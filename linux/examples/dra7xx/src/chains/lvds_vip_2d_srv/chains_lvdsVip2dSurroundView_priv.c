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
#include "chains_lvdsVip2dSurroundView_priv.h"
Void chains_lvdsVip2dSurroundView_SetLinkId(chains_lvdsVip2dSurroundViewObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE;
       pObj->Sync_svLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->Dup_svLinkID                   = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_0);
       pObj->IPCOut_IPU1_0_A15_0_2LinkID    = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_2);
       pObj->IPCIn_A15_0_IPU1_0_1LinkID     = A15_0_LINK (SYSTEM_LINK_ID_IPC_IN_1);
       pObj->epSink_2LinkID                 = SYSTEM_LINK_ID_EP_1;
       pObj->IPCOut_IPU1_0_DSP2_1LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_1);
       pObj->IPCIn_DSP2_IPU1_0_1LinkID      = DSP2_LINK (SYSTEM_LINK_ID_IPC_IN_1);
       pObj->IPCOut_IPU1_0_DSP2_0LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_DSP2_IPU1_0_0LinkID      = DSP2_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_GeoAlignLinkID             = DSP2_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->Alg_SynthesisLinkID            = DSP2_LINK (SYSTEM_LINK_ID_ALG_1);
       pObj->IPCOut_DSP2_A15_0_0LinkID      = DSP2_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_A15_0_DSP2_0LinkID       = A15_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->epSink_1LinkID                 = SYSTEM_LINK_ID_EP_0;
       pObj->Alg_PhotoAlignLinkID           = DSP2_LINK (SYSTEM_LINK_ID_ALG_2);
}

Void chains_lvdsVip2dSurroundView_ResetLinkPrms(chains_lvdsVip2dSurroundViewObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       SyncLink_CreateParams_Init(&pObj->Sync_svPrm);
       DupLink_CreateParams_Init(&pObj->Dup_svPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_A15_0_2Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_A15_0_IPU1_0_1Prm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_DSP2_1Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP2_IPU1_0_1Prm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_DSP2_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP2_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_DSP2_A15_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_A15_0_DSP2_0Prm);
}

Void chains_lvdsVip2dSurroundView_SetPrms(chains_lvdsVip2dSurroundViewObj *pObj){
       (pObj->Dup_svPrm).numOutQue = 3;
       (pObj->Alg_GeoAlignPrm).baseClassCreate.size  = sizeof(AlgorithmLink_GAlignCreateParams);
       (pObj->Alg_GeoAlignPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_GALIGNMENT;
       (pObj->Alg_SynthesisPrm).baseClassCreate.size  = sizeof(AlgorithmLink_SynthesisCreateParams);
       (pObj->Alg_SynthesisPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_SYNTHESIS;
       (pObj->Alg_PhotoAlignPrm).baseClassCreate.size  = sizeof(AlgorithmLink_PAlignCreateParams);
       (pObj->Alg_PhotoAlignPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_PALIGNMENT;
}

Void chains_lvdsVip2dSurroundView_ConnectLinks(chains_lvdsVip2dSurroundViewObj *pObj){

       //Capture -> Sync_sv
       pObj->CapturePrm.outQueParams.nextLink = pObj->Sync_svLinkID;
       pObj->Sync_svPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->Sync_svPrm.inQueParams.prevLinkQueId = 0;

       //Sync_sv -> Dup_sv
       pObj->Sync_svPrm.outQueParams.nextLink = pObj->Dup_svLinkID;
       pObj->Dup_svPrm.inQueParams.prevLinkId = pObj->Sync_svLinkID;
       pObj->Dup_svPrm.inQueParams.prevLinkQueId = 0;

       //Dup_sv -> IPCOut_IPU1_0_DSP2_0
       pObj->Dup_svPrm.outQueParams[0].nextLink = pObj->IPCOut_IPU1_0_DSP2_0LinkID;
       pObj->IPCOut_IPU1_0_DSP2_0Prm.inQueParams.prevLinkId = pObj->Dup_svLinkID;
       pObj->IPCOut_IPU1_0_DSP2_0Prm.inQueParams.prevLinkQueId = 0;

       //Dup_sv -> IPCOut_IPU1_0_DSP2_1
       pObj->Dup_svPrm.outQueParams[1].nextLink = pObj->IPCOut_IPU1_0_DSP2_1LinkID;
       pObj->IPCOut_IPU1_0_DSP2_1Prm.inQueParams.prevLinkId = pObj->Dup_svLinkID;
       pObj->IPCOut_IPU1_0_DSP2_1Prm.inQueParams.prevLinkQueId = 1;

       //Dup_sv -> IPCOut_IPU1_0_A15_0_2
       pObj->Dup_svPrm.outQueParams[2].nextLink = pObj->IPCOut_IPU1_0_A15_0_2LinkID;
       pObj->IPCOut_IPU1_0_A15_0_2Prm.inQueParams.prevLinkId = pObj->Dup_svLinkID;
       pObj->IPCOut_IPU1_0_A15_0_2Prm.inQueParams.prevLinkQueId = 2;

       //IPCOut_IPU1_0_A15_0_2 -> IPCIn_A15_0_IPU1_0_1
       pObj->IPCOut_IPU1_0_A15_0_2Prm.outQueParams.nextLink = pObj->IPCIn_A15_0_IPU1_0_1LinkID;
       pObj->IPCIn_A15_0_IPU1_0_1Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_A15_0_2LinkID;
       pObj->IPCIn_A15_0_IPU1_0_1Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_A15_0_IPU1_0_1 -> epSink_2
       pObj->IPCIn_A15_0_IPU1_0_1Prm.outQueParams.nextLink = pObj->epSink_2LinkID;
       pObj->epSink_2Prm.inQueParams.prevLinkId = pObj->IPCIn_A15_0_IPU1_0_1LinkID;
       pObj->epSink_2Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_IPU1_0_DSP2_1 -> IPCIn_DSP2_IPU1_0_1
       pObj->IPCOut_IPU1_0_DSP2_1Prm.outQueParams.nextLink = pObj->IPCIn_DSP2_IPU1_0_1LinkID;
       pObj->IPCIn_DSP2_IPU1_0_1Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_DSP2_1LinkID;
       pObj->IPCIn_DSP2_IPU1_0_1Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP2_IPU1_0_1 -> Alg_Synthesis
       pObj->IPCIn_DSP2_IPU1_0_1Prm.outQueParams.nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[0].prevLinkId = pObj->IPCIn_DSP2_IPU1_0_1LinkID;
       pObj->Alg_SynthesisPrm.inQueParams[0].prevLinkQueId = 0;

       //IPCOut_IPU1_0_DSP2_0 -> IPCIn_DSP2_IPU1_0_0
       pObj->IPCOut_IPU1_0_DSP2_0Prm.outQueParams.nextLink = pObj->IPCIn_DSP2_IPU1_0_0LinkID;
       pObj->IPCIn_DSP2_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_DSP2_0LinkID;
       pObj->IPCIn_DSP2_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP2_IPU1_0_0 -> Alg_GeoAlign
       pObj->IPCIn_DSP2_IPU1_0_0Prm.outQueParams.nextLink = pObj->Alg_GeoAlignLinkID;
       pObj->Alg_GeoAlignPrm.inQueParams[0].prevLinkId = pObj->IPCIn_DSP2_IPU1_0_0LinkID;
       pObj->Alg_GeoAlignPrm.inQueParams[0].prevLinkQueId = 0;

       //Alg_GeoAlign -> Alg_Synthesis
       pObj->Alg_GeoAlignPrm.outQueParams[0].nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[1].prevLinkId = pObj->Alg_GeoAlignLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[1].prevLinkQueId = 0;

       //Alg_Synthesis -> IPCOut_DSP2_A15_0_0
       pObj->Alg_SynthesisPrm.outQueParams[0].nextLink = pObj->IPCOut_DSP2_A15_0_0LinkID;
       pObj->IPCOut_DSP2_A15_0_0Prm.inQueParams.prevLinkId = pObj->Alg_SynthesisLinkID;
       pObj->IPCOut_DSP2_A15_0_0Prm.inQueParams.prevLinkQueId = 0;

       //Alg_Synthesis -> Alg_PhotoAlign
       pObj->Alg_SynthesisPrm.outQueParams[1].nextLink = pObj->Alg_PhotoAlignLinkID;
       pObj->Alg_PhotoAlignPrm.inQueParams[0].prevLinkId = pObj->Alg_SynthesisLinkID;
       pObj->Alg_PhotoAlignPrm.inQueParams[0].prevLinkQueId = 1;

       //IPCOut_DSP2_A15_0_0 -> IPCIn_A15_0_DSP2_0
       pObj->IPCOut_DSP2_A15_0_0Prm.outQueParams.nextLink = pObj->IPCIn_A15_0_DSP2_0LinkID;
       pObj->IPCIn_A15_0_DSP2_0Prm.inQueParams.prevLinkId = pObj->IPCOut_DSP2_A15_0_0LinkID;
       pObj->IPCIn_A15_0_DSP2_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_A15_0_DSP2_0 -> epSink_1
       pObj->IPCIn_A15_0_DSP2_0Prm.outQueParams.nextLink = pObj->epSink_1LinkID;
       pObj->epSink_1Prm.inQueParams.prevLinkId = pObj->IPCIn_A15_0_DSP2_0LinkID;
       pObj->epSink_1Prm.inQueParams.prevLinkQueId = 0;

       //Alg_PhotoAlign -> Alg_Synthesis
       pObj->Alg_PhotoAlignPrm.outQueParams[0].nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[2].prevLinkId = pObj->Alg_PhotoAlignLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[2].prevLinkQueId = 0;

}

Int32 chains_lvdsVip2dSurroundView_Create(chains_lvdsVip2dSurroundViewObj *pObj, Void *appObj){

       Int32 status;

       chains_lvdsVip2dSurroundView_SetLinkId(pObj);
       chains_lvdsVip2dSurroundView_ResetLinkPrms(pObj);

       chains_lvdsVip2dSurroundView_SetPrms(pObj);
       chains_lvdsVip2dSurroundView_SetAppPrms(pObj, appObj);

       chains_lvdsVip2dSurroundView_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Sync_svLinkID, &pObj->Sync_svPrm, sizeof(pObj->Sync_svPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Dup_svLinkID, &pObj->Dup_svPrm, sizeof(pObj->Dup_svPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_A15_0_2LinkID, &pObj->IPCOut_IPU1_0_A15_0_2Prm, sizeof(pObj->IPCOut_IPU1_0_A15_0_2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_A15_0_IPU1_0_1LinkID, &pObj->IPCIn_A15_0_IPU1_0_1Prm, sizeof(pObj->IPCIn_A15_0_IPU1_0_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->epSink_2LinkID, &pObj->epSink_2Prm, sizeof(pObj->epSink_2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_DSP2_1LinkID, &pObj->IPCOut_IPU1_0_DSP2_1Prm, sizeof(pObj->IPCOut_IPU1_0_DSP2_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP2_IPU1_0_1LinkID, &pObj->IPCIn_DSP2_IPU1_0_1Prm, sizeof(pObj->IPCIn_DSP2_IPU1_0_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_DSP2_0LinkID, &pObj->IPCOut_IPU1_0_DSP2_0Prm, sizeof(pObj->IPCOut_IPU1_0_DSP2_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP2_IPU1_0_0LinkID, &pObj->IPCIn_DSP2_IPU1_0_0Prm, sizeof(pObj->IPCIn_DSP2_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_GeoAlignLinkID, &pObj->Alg_GeoAlignPrm, sizeof(pObj->Alg_GeoAlignPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_SynthesisLinkID, &pObj->Alg_SynthesisPrm, sizeof(pObj->Alg_SynthesisPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_DSP2_A15_0_0LinkID, &pObj->IPCOut_DSP2_A15_0_0Prm, sizeof(pObj->IPCOut_DSP2_A15_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_A15_0_DSP2_0LinkID, &pObj->IPCIn_A15_0_DSP2_0Prm, sizeof(pObj->IPCIn_A15_0_DSP2_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->epSink_1LinkID, &pObj->epSink_1Prm, sizeof(pObj->epSink_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_PhotoAlignLinkID, &pObj->Alg_PhotoAlignPrm, sizeof(pObj->Alg_PhotoAlignPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVip2dSurroundView_Start(chains_lvdsVip2dSurroundViewObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->epSink_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_A15_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_DSP2_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP2_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP2_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_DSP2_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->epSink_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_A15_0_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_A15_0_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVip2dSurroundView_Stop(chains_lvdsVip2dSurroundViewObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->epSink_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_A15_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_DSP2_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP2_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP2_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP2_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->epSink_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_A15_0_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_A15_0_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVip2dSurroundView_Delete(chains_lvdsVip2dSurroundViewObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->epSink_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_A15_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_DSP2_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP2_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_DSP2_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP2_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_DSP2_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->epSink_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_A15_0_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_A15_0_2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_lvdsVip2dSurroundView_printBufferStatistics(chains_lvdsVip2dSurroundViewObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->Sync_svLinkID);
       System_linkPrintBufferStatistics(pObj->Dup_svLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_A15_0_2LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_A15_0_IPU1_0_1LinkID);
       System_linkPrintBufferStatistics(pObj->epSink_2LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_DSP2_1LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP2_IPU1_0_1LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_DSP2_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP2_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_GeoAlignLinkID);
       System_linkPrintBufferStatistics(pObj->Alg_SynthesisLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_DSP2_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_A15_0_DSP2_0LinkID);
       System_linkPrintBufferStatistics(pObj->epSink_1LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->Alg_PhotoAlignLinkID);
       Task_sleep(500);
}

Void chains_lvdsVip2dSurroundView_printStatistics(chains_lvdsVip2dSurroundViewObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->Sync_svLinkID);
       System_linkPrintStatistics(pObj->Dup_svLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_A15_0_2LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_A15_0_IPU1_0_1LinkID);
       System_linkPrintStatistics(pObj->epSink_2LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_DSP2_1LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP2_IPU1_0_1LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_DSP2_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP2_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->Alg_GeoAlignLinkID);
       System_linkPrintStatistics(pObj->Alg_SynthesisLinkID);
       System_linkPrintStatistics(pObj->IPCOut_DSP2_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_A15_0_DSP2_0LinkID);
       System_linkPrintStatistics(pObj->epSink_1LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->Alg_PhotoAlignLinkID);
       Task_sleep(500);
}

