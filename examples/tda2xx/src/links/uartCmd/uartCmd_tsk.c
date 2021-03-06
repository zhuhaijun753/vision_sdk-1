/**
 *                                                                            
 * Copyright (c) 2015 CAMMSYS - http://www.cammsys.net/                       
 *                                                                            
 * All rights reserved.                                                       
 *                                                                            
 * @file	uartInput_tsk.c
 * @author  Raven
 * @date	Sep 21, 2015
 * @brief	                                                                     
 */

#include <examples/tda2xx/include/chains.h>
#include <examples/tda2xx/include/chains_common.h>
#include <src/utils_common/include/utils_prcm_stats.h>
#include <src/utils_common/include/utils_uart.h>
#include "uartCmd_priv.h"
#include <include/link_api/algorithmLink.h>
#include <include/link_api/displayLink.h> //ryuhs74@20151209 - For CES

#pragma DATA_ALIGN(UartCmd_tskStack, 32)
#pragma DATA_SECTION(UartCmd_tskStack, ".bss:taskStackSection")
UInt8 UartCmd_tskStack[1024*4];


static BspOsal_TaskHandle tsk;
static uint8_t RxBuf[DATA_MAX_LEN];
static uint8_t TxBuf[DATA_MAX_LEN];
static uint32_t RxBufPos = 0;
#pragma DATA_ALIGN(RxBuf, 128);
#pragma DATA_ALIGN(TxBuf, 128);

//ryuhs74@20151104 - Add Put CMD To GrpxSrcLink
//void GrpxSrcLink_putCmd( uint8_t _cmd );
//void E500ViewMode_putCmd( uint8_t _cmd );


static int LOCAL_UART_isReceivedAll(uint8_t *buf, uint16_t len)
{
	uint16_t dataLen;

	if ( len < MIN_MSG_SIZE )
	{
		Vps_printf("len < MIN_MSG_SIZEr\n");
		return -1;
	}
	dataLen = GET_LENGTH(buf);
	if ( len < dataLen + MSG_HEADER_LEN )
	{
		Vps_printf("len < dataLen + MSG_HEADER_LEN\n");
		return -1;
	}
	return 0;
}


static uint8_t Make_BCC(uint8_t *pData, uint16_t len)
{
	uint8_t chksum = 0;
	int i;

    for(i = 0; i< (len+4); i++)
    	chksum ^= (*pData++);
    chksum |= 0x20; 			//in order not to same as 0x02,0x03, 0x0X
    return chksum;
}

static int UART_SendCmd(uint8_t targetId, uint8_t srcId, uint8_t *data, uint16_t dataLen)
{
	uint8_t bcc;
	size_t len;

	SET_START_TAG(TxBuf);
	SET_TARGET_ID(TxBuf, targetId);
	SET_SOURCE_ID(TxBuf, srcId);
	SET_LENGTH(TxBuf, dataLen);
	SET_DATA(TxBuf, data, dataLen);
	bcc = Make_BCC(&TxBuf[1], dataLen);
	SET_BCC(TxBuf, bcc);
	SET_END_TAG(TxBuf);

	len = MSG_HEADER_LEN+dataLen;
	UtillUartWrite(UART_CH_MICOM,TxBuf,&len);

	return 0;
}


//extern int gisCapture;
//extern UInt32 gdone;
extern UInt32 gGrpxSrcLinkID;
UInt32 gFullFront = 0;
extern UInt32 gE500AlgLinkID_0;
extern UInt32 gE500AlgLinkID_1;

//UInt32 TestFileSave = 0;
UInt32 gDisplay_videoLinkID = 0; //ryuhs74@20151209 - For CES
Void chains_surround_View_SwitchDisplayCh( uint8_t _cmd ) //ryuhs74@20151209 - For CES
{
	//TOP : 0 Rear = 1, LEFT = 2, RIGHT = 3, FRONT = 4
    DisplayLink_SwitchChannelParams displayPrm;

    if( _cmd == IRDA_KEY_UP ){ //FRONT : 4
    	displayPrm.activeChId = 4;
    	System_linkControl(gDisplay_videoLinkID, DISPLAY_LINK_CMD_SWITCH_CH, &displayPrm, sizeof(displayPrm), TRUE);
    	System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_CLEAR_E500_UI, NULL, 0, TRUE);
    } else if( _cmd == IRDA_KEY_DOWN ){ //Rear : 1
    	displayPrm.activeChId = 1;
    	System_linkControl(gDisplay_videoLinkID, DISPLAY_LINK_CMD_SWITCH_CH, &displayPrm, sizeof(displayPrm), TRUE);
    	System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_CLEAR_E500_UI, NULL, 0, TRUE);
    } else if( _cmd == IRDA_KEY_RIGHT ){ //RIGHT : 3
    	displayPrm.activeChId = 3;
    	System_linkControl(gDisplay_videoLinkID, DISPLAY_LINK_CMD_SWITCH_CH, &displayPrm, sizeof(displayPrm), TRUE);
    	System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_CLEAR_E500_UI, NULL, 0, TRUE);
    } else if( _cmd == IRDA_KEY_LEFT ){ //LEFT : 2
    	displayPrm.activeChId = 2;
    	System_linkControl(gDisplay_videoLinkID, DISPLAY_LINK_CMD_SWITCH_CH, &displayPrm, sizeof(displayPrm), TRUE);
    	System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_CLEAR_E500_UI, NULL, 0, TRUE);
    }else if( _cmd == IRDA_KEY_FULL ){
    	displayPrm.activeChId = 0;
    	System_linkControl(gDisplay_videoLinkID, DISPLAY_LINK_CMD_SWITCH_CH, &displayPrm, sizeof(displayPrm), TRUE);
    	System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_REDRAW_E500_UI, NULL, 0, TRUE);
    }
}

void GrpxLink_putCmd( uint8_t _cmd )
{
	Int32 status;

	if( _cmd == IRDA_KEY_UP ){
		_cmd = SYSTEM_CMD_FRONT_SIDE_VIEW;
		Vps_printf("In GrpxSrcLink_putCmd, CMD_REQ_FRONT_VIEW, CMD : %d", _cmd);
		status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
		Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_DOWN ){
		_cmd = SYSTEM_CMD_REAR_SIDE_VIEW;
		Vps_printf("In GrpxSrcLink_putCmd, CMD_REQ_REAR_VIEW, CMD : %d", _cmd);
		status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
		Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_RIGHT ){
		_cmd = SYSTEM_CMD_RIGH_SIDE_VIEW;
		Vps_printf("In GrpxSrcLink_putCmd, CMD_REQ_RIGHT_VIEW, CMD : %d", _cmd);
		status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
		Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_LEFT ){
		_cmd = SYSTEM_CMD_LEFT_SIDE_VIEW;
		Vps_printf("In GrpxSrcLink_putCmd, CMD_REQ_LEFT_VIEW, CMD : %d", _cmd);
		status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
		Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	}else if( _cmd == IRDA_KEY_FULL ){
		if( gFullFront == 0 )//Front Full View
		{

			_cmd = SYSTEM_CMD_FULL_FRONT_VIEW;
			Vps_printf("In GrpxSrcLink_putCmd, IRDA_KEY_FULL, Front, CMD : %d", _cmd);
			gFullFront = 1;
			status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
			Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		} else {

			_cmd = SYSTEM_CMD_FULL_REAR_VIEW;
			Vps_printf("In GrpxSrcLink_putCmd, IRDA_KEY_FULL, Rear, CMD : %d", _cmd);
			gFullFront = 0;
			status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
			Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		}
	} else if( _cmd == IRDA_KEY_PWR ){
#if 1
		_cmd = SYSTEM_CMD_FILE_SAVE_START;
		Vps_printf("In GrpxSrcLink_putCmd, IRDA_KEY_PWR, File Save, CMD : %d", _cmd);
		status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
		Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
#else
		if( TestFileSave == 0){
			TestFileSave = 1;
			_cmd = SYSTEM_CMD_FILE_SAVE_START;
			Vps_printf("In GrpxSrcLink_putCmd, IRDA_KEY_PWR, File Save, CMD : %d", _cmd);
			status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
			Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		} else {
			TestFileSave = 0;
			_cmd = SYSTEM_CMD_FILE_SAVE_DONE;
			Vps_printf("In GrpxSrcLink_putCmd, IRDA_KEY_PWR, File Save Done, CMD : %d", _cmd);
			status = System_linkControl(gGrpxSrcLinkID, _cmd, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
			Vps_printf("   CMD Send %s gGrpxSrcLinkID\n", ( status == 0x0)?"Success":"Fail");
		}
#endif
	}
}

void AlgLink_putCmd( uint8_t _cmd )
{
#if 1

	Int32 status;
	AlgorithmLink_ControlParams AlgLinkControlPrm;

	if( _cmd == IRDA_KEY_UP ){
		Vps_printf("In AlgLink_putCmd, IRDA_KEY_UP");
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FRONT_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		Vps_printf("   CMD Send %s AlgLink_putCmd\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_DOWN ){
		Vps_printf("In AlgLink_putCmd, IRDA_KEY_DOWN");
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_REAR_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		Vps_printf("   CMD Send %s AlgLink_putCmd\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_RIGHT ){
		Vps_printf("In AlgLink_putCmd, IRDA_KEY_RIGHT");
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_RIGH_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		Vps_printf("   CMD Send %s AlgLink_putCmd\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	} else if( _cmd == IRDA_KEY_LEFT ){
		Vps_printf("In AlgLink_putCmd, IRDA_KEY_LEFT");
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_LEFT_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		Vps_printf("   CMD Send %s AlgLink_putCmd\n", ( status == 0x0)?"Success":"Fail");
		gFullFront = 0;
	}else if( _cmd == IRDA_KEY_FULL ){
		if( gFullFront == 0 )//Front Full View
		{
			Vps_printf("In AlgLink_putCmd, IRDA_KEY_FULL");
			AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FULL_FRONT_VIEW;
		} else {
			Vps_printf("In AlgLink_putCmd, IRDA_KEY_FULL");
			AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FULL_REAR_VIEW;
		}
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		Vps_printf("   CMD Send %s AlgLink_putCmd\n", ( status == 0x0)?"Success":"Fail");
	}
#endif
}

static UInt32 nState = 0;

void PutCmd_Button(UInt32 nState )
{
	Int32 status;
	AlgorithmLink_ControlParams AlgLinkControlPrm;

	Vps_printf("AVM-E500 : In PutCmd_Button, nState: %d", nState);

	if( nState == 0 ){ //IRDA_KEY_UP
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FRONT_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_FRONT_SIDE_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	} else if( nState == 1 ){ //IRDA_KEY_DOWN
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_REAR_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_REAR_SIDE_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	} else if( nState == 2 ){ //IRDA_KEY_LEFT
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_LEFT_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_LEFT_SIDE_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	} else if( nState == 3 ){ //IRDA_KEY_RIGHT
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_RIGH_SIDE_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_RIGH_SIDE_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	}else if( nState == 4 ){ //IRDA_KEY_FULL - Front
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FULL_FRONT_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_FULL_FRONT_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	} else if( nState == 5 ){ //IRDA_KEY_FULL - Rear
		AlgLinkControlPrm.controlCmd = SYSTEM_CMD_FULL_REAR_VIEW;
		status = System_linkControl( gE500AlgLinkID_0, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl( gE500AlgLinkID_1, ALGORITHM_LINK_CMD_CONFIG, &AlgLinkControlPrm, sizeof(AlgLinkControlPrm), TRUE);
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_FULL_REAR_VIEW, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	} else if( nState == 6 ){
		status = System_linkControl(gGrpxSrcLinkID, SYSTEM_CMD_COLORBARTEST_UI, NULL, 0, TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	}
	Vps_printf("AVM-E500 : CMD Send %s PutCmd_Button\n", ( status == 0x0)?"Success":"Fail");
}

static int UART_ParseCmd(uint8_t *rxBuf)
{
	uint8_t calcBcc;
	uint16_t dataLen;
	uint8_t buf[64];

	//
	/////////////////////////////////////////
	///   Error Check
	if ( GET_START_TAG(rxBuf) != START_TAG)
	{
		Vps_printf("START TAG Error");
		return MSG_ERROR_BAD_PARAMETER;
	}
	if ( GET_END_TAG(rxBuf) != END_TAG)
	{
		Vps_printf("END TAG Error");
		return MSG_ERROR_BAD_PARAMETER;
	}

	dataLen = GET_LENGTH(rxBuf);
	calcBcc = Make_BCC(&rxBuf[1], dataLen);
	if (calcBcc != GET_BCC(rxBuf))
	{
		Vps_printf(	"BCC error, calcBcc(%d), bcc(%d)\n",
					calcBcc,
					GET_BCC(rxBuf));
		return MSG_ERROR_BCC;
	}

	////////////////////////////////////////
	/// Parse message
	Vps_printf(	"ParserCMD [0x%02X] len[%d] data[0x%02X 0x%02X 0x%02X 0x%02X]",
				GET_COMMAND(rxBuf),
				dataLen,
				GET_ARG1(rxBuf),
				GET_ARG2(rxBuf),
				GET_ARG3(rxBuf),
				GET_ARG4(rxBuf));

	switch (GET_COMMAND(rxBuf))
	{
	case CMD_REQ_DSP_STANDBY:
	{

		break;
	}

	case CMD_REQ_DSP_STATUS:
	{
		Vps_printf("STATUS REQ");
		buf[0] = CMD_REQ_DSP_STATUS;
		buf[1] = ACK;
		buf[2] = DSP_STATUS_AVM_MODE;
		UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 3);
		break;
	}

	case CMD_REQ_MICOM_VER:		// Recv version of AVM MICOM
		break;
	case CMD_SEND_IRDA_KEY:		// Recv IrDA command with Key value
		switch (GET_ARG1(rxBuf))
		//ryuhs74@20151020 - Add HDMI On/Off Test Start
		{
		case IRDA_KEY_PWR: //File Save - IRDA_KEY_PWR = (0x09)
			//gisCapture = 1;
			//Vps_printf(	"**********************************gisCapture : %d\n",
			//			gisCapture);
			GrpxLink_putCmd(GET_ARG1(rxBuf));
			break;
		case IRDA_KEY_UP : //Front - IRDA_KEY_UP = (0x0F)
		case IRDA_KEY_DOWN : //Rear - IRDA_KEY_DOWN = (0x0E)
		case IRDA_KEY_LEFT : //LFET - IRDA_KEY_LEFT = (0x0B)
		case IRDA_KEY_RIGHT : //RIGHT - IRDA_KEY_RIGHT = (0x0A)
		case IRDA_KEY_FULL : //Full - IRDA_KEY_FULL = (0x05),

			AlgLink_putCmd( GET_ARG1(rxBuf) );
			GrpxLink_putCmd( GET_ARG1(rxBuf) );
			//chains_surround_View_SwitchDisplayCh( GET_ARG1(rxBuf));
			break;
		} //ryuhs74@20151020 - Add HDMI On/Off Test End
		break;
	case CMD_SEND_RGEAR:		// Recv Rear Gear On/Off
		break;
	case CMD_CONTROL_VIDEO_OUT:	// ???
		break;
	case CMD_SDCARD_HPD:		// ???
		break;
	case CMD_REQ_VBAT_ADC:		// ???
		break;
	case CMD_DSP_REQ_TEST:
		break;

	case CMD_SEND_TURN_SIGNAL:

		break;
	case CMD_SEND_BUTTON_PRESSED:	///Recv Button Event
		Vps_printf("In CMD_SEND_BUTTON_PRESSED ");
		switch (GET_ARG1(rxBuf))
		{
		case BUTTON_1_SHORT_PRESSED:
			Vps_printf("In BUTTON_1_SHORT_PRESSED\n");
			if( nState >= 5)
				nState = 0;
			else
				nState++;

			PutCmd_Button(nState);
			break;
		case BUTTON_1_LONG_PRESSED :
			Vps_printf("In BUTTON_1_LONG_PRESSED\n");
			break;
		case BUTTON_2_SHORT_PRESSED :
			Vps_printf("In BUTTON_2_SHORT_PRESSED\n");
			if( nState <= 0)
				nState = 5;
			else
				nState--;
			PutCmd_Button(nState);
			break;
		case BUTTON_2_LONG_PRESSED : //LFET - IRDA_KEY_LEFT = (0x0B)
			Vps_printf("In BUTTON_2_LONG_PRESSED\n");
			break;
		}
		buf[0] = CMD_SEND_BUTTON_PRESSED;
		buf[1] = ACK;
		UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 2);
		break;
	case CMD_REQ_LVDS_STATUS:
		break;
	case CMD_REQ_AUDIO_OUT:
		break;

	case CMD_REQ_HDMI_ONOFF:
	{
		extern void vpshal_HdmiWpVideoStart(UInt32 start)	;

		buf[0] = CMD_REQ_HDMI_ONOFF;
		buf[1] = ACK;
		Vps_printf(	"CMD_REQ_HDMI_ONOFF : %x %s",
					GET_ARG1(rxBuf),
					GET_ARG1(rxBuf) ? "ON" : "OFF");

		if ( GET_ARG1(rxBuf) == 0x00)
		{
			vpshal_HdmiWpVideoStart(0);
		}
		else
		{
			vpshal_HdmiWpVideoStart(1);
		}
		UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 2);
        BspOsal_sleep(200);
		buf[0] = CMD_SEND_HDMI_ON_OFF;
		buf[1] = GET_ARG1(rxBuf);
		UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 2);
		break;
	}
	case CMD_REQ_ETHERNET_ONOFF:
	{
		extern void PlatformRGMII1SetPinDeMux(void);
		extern void PlatformRGMII1SetPinMux(void);

		buf[0] = CMD_REQ_ETHERNET_ONOFF;
		buf[1] = ACK;
		Vps_printf("CMD_REQ_ETHERNET_ONOFF : %x %s",
				   GET_ARG1(rxBuf),
				   GET_ARG1(rxBuf) ? "ON" : "OFF");

		if ( GET_ARG1(rxBuf) == 0x00)
		{
			PlatformRGMII1SetPinDeMux();
		}
		else
		{
			PlatformRGMII1SetPinMux();
		}
		UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 2);
		break;
	}
	default:
	{
		Vps_printf("UNKNOWN CMD\n");

	}
		break;
	}
	///
	////////////////////////////////////////
	return MSG_NO_ERROR;
}


static void SendDSPStatus(void)
{
	uint8_t buf[3];

	buf[0] = CMD_REQ_DSP_STATUS;
	buf[1] = ACK;
	buf[2] = DSP_STATUS_AVM_MODE;

	UART_SendCmd(DEV_ID_AVM_MICOM, DEV_ID_AVM_DSP, buf, 3);
}

Void UartCmd_tsk_main(UArg arg0, UArg arg1)
{
	SendDSPStatus();

	for(;;)
	{
		int parseResult = MSG_NO_ERROR;
		size_t len;
		UtillUartRead(UART_CH_MICOM,RxBuf+RxBufPos,&len);
		RxBufPos += len;
		if ( GET_START_TAG(RxBuf) != START_TAG)
		{
			//Vps_printf("[UART8] 0x%02x\n", rxBuf8[0]);
			RxBufPos = 0;
			continue;
		}
		if(RxBufPos >= DATA_MAX_LEN)
			RxBufPos = 0;
		if ( LOCAL_UART_isReceivedAll(RxBuf, RxBufPos) != 0 )
		{
			Vps_printf("UART continue\n");
			continue;
		}

		parseResult = UART_ParseCmd(RxBuf);
		RxBufPos = 0;

		if( parseResult != MSG_NO_ERROR)
		{
			///Error
			;
		}
	}
}


Int32 UartCmd_tsk_init()
{
	tsk = BspOsal_taskCreate(
			(BspOsal_TaskFuncPtr)UartCmd_tsk_main,
			1,
			UartCmd_tskStack,
			sizeof(UartCmd_tskStack),
			NULL);

    return 0;
}


Int32 UartCmd_tsk_deInit()
 {

	BspOsal_taskDelete(tsk);
    return 0;
 }
