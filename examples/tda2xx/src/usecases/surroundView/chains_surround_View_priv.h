/*
*******************************************************************************
*
* Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
* ALL RIGHTS RESERVED
*
*******************************************************************************
*/

/*
*******************************************************************************
*
* IMPORTANT NOTE:
*  This file is AUTO-GENERATED by Vision SDK use case generation tool
*
*******************************************************************************
*/

#ifndef _chains_surround_View_H_
#define _chains_surround_View_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_surroundView.h>
#include <include/link_api/algorithmLink_dmaSwMs.h>
#include <include/link_api/mergeLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>
#include <include/link_api/ipcLink.h>

#include <include/link_api/saveLink.h> //ryuhs74@20151027 - Add Save Link

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    SyncLinkID;
       UInt32    DupLinkID;

       UInt32    IPCOut_IPU1_0_DSP_0_0LinkID;
       UInt32    IPCIn_DSP_0_IPU1_0_0LinkID;
       UInt32    Alg_SurroundViewLink_0_ID;
       UInt32    IPCOut_DSP_0_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP_0_0LinkID;

       UInt32    IPCOut_IPU1_0_DSP_1_0LinkID;
       UInt32    IPCIn_DSP_1_IPU1_0_0LinkID;
       UInt32    Alg_SurroundViewLink_1_ID;
       UInt32    IPCOut_DSP_1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP_1_0LinkID;

       UInt32    MergeLinkID;

       UInt32    SyncLinkSurroundViewID;
       UInt32    Alg_DmaSwMsLinkID;
       UInt32    Display_videoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       SyncLink_CreateParams                   SyncPrm;
       DupLink_CreateParams                    DupPrm;

       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP_0_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP_0_IPU1_0_0Prm;
       AlgorithmLink_SurroundViewCreateParams       Alg_SurroundViewPrm_0;
       IpcLink_CreateParams                    IPCOut_DSP_0_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP_0_0Prm;

       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP_1_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP_1_IPU1_0_0Prm;
       AlgorithmLink_SurroundViewCreateParams       Alg_SurroundViewPrm_1;
       IpcLink_CreateParams                    IPCOut_DSP_1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP_1_0Prm;

       MergeLink_CreateParams                  MergePrm;
       SyncLink_CreateParams                   SyncSurroundViewPrm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMsPrm;
       DisplayLink_CreateParams                Display_videoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;

       //Uint32 Save_SaveLinkID;				//ryuhs74220151027 - Add Save Link
       //SaveLink_CreateParams				Save_Prm;//ryuhs74220151027 - Add Save Link
} chains_surround_ViewObj;

Void chains_surround_View_SetLinkId(chains_surround_ViewObj *pObj);

Void chains_surround_View_ResetLinkPrms(chains_surround_ViewObj *pObj);

Void chains_surround_View_SetPrms(chains_surround_ViewObj *pObj);

Void chains_surround_View_ConnectLinks(chains_surround_ViewObj *pObj);

Int32 chains_surround_View_Create(chains_surround_ViewObj *pObj, Void *appObj);

Int32 chains_surround_View_Start(chains_surround_ViewObj *pObj);

Int32 chains_surround_View_Stop(chains_surround_ViewObj *pObj);

Int32 chains_surround_View_Delete(chains_surround_ViewObj *pObj);

Void chains_surround_View_printBufferStatistics(chains_surround_ViewObj *pObj);

Void chains_surround_View_printStatistics(chains_surround_ViewObj *pObj);

Void chains_surround_View_SetAppPrms(chains_surround_ViewObj *pObj, Void *appObj);

#endif /* _chains_surround_View_H_ */
