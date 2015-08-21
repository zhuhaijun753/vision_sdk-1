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
#include "chains_ov490VipSurroundViewStandalone_priv.h"
Void chains_ov490VipSurroundViewStandalone_SetLinkId(chains_ov490VipSurroundViewStandaloneObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE_0;
       pObj->SplitLinkID                    = IPU1_0_LINK (SYSTEM_LINK_ID_SPLIT_0);
       pObj->Dup_sv_orgLinkID               = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_0);
       pObj->Sync_svLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_2);
       pObj->Dup_svLinkID                   = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_1);
       pObj->IPCOut_IPU1_0_DSP1_1LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_1);
       pObj->IPCIn_DSP1_IPU1_0_1LinkID      = DSP1_LINK (SYSTEM_LINK_ID_IPC_IN_1);
       pObj->IPCOut_IPU1_0_DSP1_0LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_DSP1_IPU1_0_0LinkID      = DSP1_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_GeoAlignLinkID             = DSP1_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->Alg_SynthesisLinkID            = DSP1_LINK (SYSTEM_LINK_ID_ALG_1);
       pObj->IPCOut_DSP1_IPU1_0_0LinkID     = DSP1_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_IPU1_0_DSP1_0LinkID      = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Display_svLinkID               = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->Alg_PhotoAlignLinkID           = DSP1_LINK (SYSTEM_LINK_ID_ALG_2);
       pObj->SelectLinkID                   = IPU1_0_LINK (SYSTEM_LINK_ID_SELECT_0);
       pObj->VPE_sv_org2LinkID              = SYSTEM_LINK_ID_VPE_0;
       pObj->Sync_sv_org2LinkID             = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_1);
       pObj->Alg_DmaSwMs_sv_org2LinkID      = IPU1_0_LINK (SYSTEM_LINK_ID_ALG_1);
       pObj->Display_sv_org2LinkID          = SYSTEM_LINK_ID_DISPLAY_1;
       pObj->VPE_sv_org1LinkID              = SYSTEM_LINK_ID_VPE_1;
       pObj->Sync_sv_org1LinkID             = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->Alg_DmaSwMs_sv_org1LinkID      = IPU1_0_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->Display_sv_org1LinkID          = SYSTEM_LINK_ID_DISPLAY_2;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_3;
}

Void chains_ov490VipSurroundViewStandalone_ResetLinkPrms(chains_ov490VipSurroundViewStandaloneObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       SplitLink_CreateParams_Init(&pObj->SplitPrm);
       DupLink_CreateParams_Init(&pObj->Dup_sv_orgPrm);
       SyncLink_CreateParams_Init(&pObj->Sync_svPrm);
       DupLink_CreateParams_Init(&pObj->Dup_svPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_DSP1_1Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP1_IPU1_0_1Prm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_DSP1_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP1_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_DSP1_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_IPU1_0_DSP1_0Prm);
       DisplayLink_CreateParams_Init(&pObj->Display_svPrm);
       SelectLink_CreateParams_Init(&pObj->SelectPrm);
       VpeLink_CreateParams_Init(&pObj->VPE_sv_org2Prm);
       SyncLink_CreateParams_Init(&pObj->Sync_sv_org2Prm);
       AlgorithmLink_DmaSwMsCreateParams_Init(&pObj->Alg_DmaSwMs_sv_org2Prm);
       DisplayLink_CreateParams_Init(&pObj->Display_sv_org2Prm);
       VpeLink_CreateParams_Init(&pObj->VPE_sv_org1Prm);
       SyncLink_CreateParams_Init(&pObj->Sync_sv_org1Prm);
       AlgorithmLink_DmaSwMsCreateParams_Init(&pObj->Alg_DmaSwMs_sv_org1Prm);
       DisplayLink_CreateParams_Init(&pObj->Display_sv_org1Prm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
}

Void chains_ov490VipSurroundViewStandalone_SetPrms(chains_ov490VipSurroundViewStandaloneObj *pObj){
       (pObj->Dup_sv_orgPrm).numOutQue = 2;
       (pObj->Dup_svPrm).numOutQue = 2;
       (pObj->Alg_GeoAlignPrm).baseClassCreate.size  = sizeof(AlgorithmLink_GAlignCreateParams);
       (pObj->Alg_GeoAlignPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_GALIGNMENT;
       (pObj->Alg_SynthesisPrm).baseClassCreate.size  = sizeof(AlgorithmLink_SynthesisCreateParams);
       (pObj->Alg_SynthesisPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_SYNTHESIS;
       (pObj->Alg_PhotoAlignPrm).baseClassCreate.size  = sizeof(AlgorithmLink_PAlignCreateParams);
       (pObj->Alg_PhotoAlignPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_PALIGNMENT;
       (pObj->SelectPrm).numOutQue = 2;
       (pObj->Alg_DmaSwMs_sv_org2Prm).baseClassCreate.size  = sizeof(AlgorithmLink_DmaSwMsCreateParams);
       (pObj->Alg_DmaSwMs_sv_org2Prm).baseClassCreate.algId  = ALGORITHM_LINK_IPU_ALG_DMA_SWMS;
       (pObj->Alg_DmaSwMs_sv_org1Prm).baseClassCreate.size  = sizeof(AlgorithmLink_DmaSwMsCreateParams);
       (pObj->Alg_DmaSwMs_sv_org1Prm).baseClassCreate.algId  = ALGORITHM_LINK_IPU_ALG_DMA_SWMS;
}

Void chains_ov490VipSurroundViewStandalone_ConnectLinks(chains_ov490VipSurroundViewStandaloneObj *pObj){

       //Capture -> Split
       pObj->CapturePrm.outQueParams.nextLink = pObj->SplitLinkID;
       pObj->SplitPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->SplitPrm.inQueParams.prevLinkQueId = 0;

       //Split -> Dup_sv_org
       pObj->SplitPrm.outQueParams.nextLink = pObj->Dup_sv_orgLinkID;
       pObj->Dup_sv_orgPrm.inQueParams.prevLinkId = pObj->SplitLinkID;
       pObj->Dup_sv_orgPrm.inQueParams.prevLinkQueId = 0;

       //Dup_sv_org -> Select
       pObj->Dup_sv_orgPrm.outQueParams[0].nextLink = pObj->SelectLinkID;
       pObj->SelectPrm.inQueParams.prevLinkId = pObj->Dup_sv_orgLinkID;
       pObj->SelectPrm.inQueParams.prevLinkQueId = 0;

       //Dup_sv_org -> Sync_sv
       pObj->Dup_sv_orgPrm.outQueParams[1].nextLink = pObj->Sync_svLinkID;
       pObj->Sync_svPrm.inQueParams.prevLinkId = pObj->Dup_sv_orgLinkID;
       pObj->Sync_svPrm.inQueParams.prevLinkQueId = 1;

       //Sync_sv -> Dup_sv
       pObj->Sync_svPrm.outQueParams.nextLink = pObj->Dup_svLinkID;
       pObj->Dup_svPrm.inQueParams.prevLinkId = pObj->Sync_svLinkID;
       pObj->Dup_svPrm.inQueParams.prevLinkQueId = 0;

       //Dup_sv -> IPCOut_IPU1_0_DSP1_0
       pObj->Dup_svPrm.outQueParams[0].nextLink = pObj->IPCOut_IPU1_0_DSP1_0LinkID;
       pObj->IPCOut_IPU1_0_DSP1_0Prm.inQueParams.prevLinkId = pObj->Dup_svLinkID;
       pObj->IPCOut_IPU1_0_DSP1_0Prm.inQueParams.prevLinkQueId = 0;

       //Dup_sv -> IPCOut_IPU1_0_DSP1_1
       pObj->Dup_svPrm.outQueParams[1].nextLink = pObj->IPCOut_IPU1_0_DSP1_1LinkID;
       pObj->IPCOut_IPU1_0_DSP1_1Prm.inQueParams.prevLinkId = pObj->Dup_svLinkID;
       pObj->IPCOut_IPU1_0_DSP1_1Prm.inQueParams.prevLinkQueId = 1;

       //IPCOut_IPU1_0_DSP1_1 -> IPCIn_DSP1_IPU1_0_1
       pObj->IPCOut_IPU1_0_DSP1_1Prm.outQueParams.nextLink = pObj->IPCIn_DSP1_IPU1_0_1LinkID;
       pObj->IPCIn_DSP1_IPU1_0_1Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_DSP1_1LinkID;
       pObj->IPCIn_DSP1_IPU1_0_1Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP1_IPU1_0_1 -> Alg_Synthesis
       pObj->IPCIn_DSP1_IPU1_0_1Prm.outQueParams.nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[0].prevLinkId = pObj->IPCIn_DSP1_IPU1_0_1LinkID;
       pObj->Alg_SynthesisPrm.inQueParams[0].prevLinkQueId = 0;

       //IPCOut_IPU1_0_DSP1_0 -> IPCIn_DSP1_IPU1_0_0
       pObj->IPCOut_IPU1_0_DSP1_0Prm.outQueParams.nextLink = pObj->IPCIn_DSP1_IPU1_0_0LinkID;
       pObj->IPCIn_DSP1_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_DSP1_0LinkID;
       pObj->IPCIn_DSP1_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP1_IPU1_0_0 -> Alg_GeoAlign
       pObj->IPCIn_DSP1_IPU1_0_0Prm.outQueParams.nextLink = pObj->Alg_GeoAlignLinkID;
       pObj->Alg_GeoAlignPrm.inQueParams[0].prevLinkId = pObj->IPCIn_DSP1_IPU1_0_0LinkID;
       pObj->Alg_GeoAlignPrm.inQueParams[0].prevLinkQueId = 0;

       //Alg_GeoAlign -> Alg_Synthesis
       pObj->Alg_GeoAlignPrm.outQueParams[0].nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[1].prevLinkId = pObj->Alg_GeoAlignLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[1].prevLinkQueId = 0;

       //Alg_Synthesis -> IPCOut_DSP1_IPU1_0_0
       pObj->Alg_SynthesisPrm.outQueParams[0].nextLink = pObj->IPCOut_DSP1_IPU1_0_0LinkID;
       pObj->IPCOut_DSP1_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->Alg_SynthesisLinkID;
       pObj->IPCOut_DSP1_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //Alg_Synthesis -> Alg_PhotoAlign
       pObj->Alg_SynthesisPrm.outQueParams[1].nextLink = pObj->Alg_PhotoAlignLinkID;
       pObj->Alg_PhotoAlignPrm.inQueParams[0].prevLinkId = pObj->Alg_SynthesisLinkID;
       pObj->Alg_PhotoAlignPrm.inQueParams[0].prevLinkQueId = 1;

       //IPCOut_DSP1_IPU1_0_0 -> IPCIn_IPU1_0_DSP1_0
       pObj->IPCOut_DSP1_IPU1_0_0Prm.outQueParams.nextLink = pObj->IPCIn_IPU1_0_DSP1_0LinkID;
       pObj->IPCIn_IPU1_0_DSP1_0Prm.inQueParams.prevLinkId = pObj->IPCOut_DSP1_IPU1_0_0LinkID;
       pObj->IPCIn_IPU1_0_DSP1_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_IPU1_0_DSP1_0 -> Display_sv
       pObj->IPCIn_IPU1_0_DSP1_0Prm.outQueParams.nextLink = pObj->Display_svLinkID;
       pObj->Display_svPrm.inQueParams.prevLinkId = pObj->IPCIn_IPU1_0_DSP1_0LinkID;
       pObj->Display_svPrm.inQueParams.prevLinkQueId = 0;

       //Alg_PhotoAlign -> Alg_Synthesis
       pObj->Alg_PhotoAlignPrm.outQueParams[0].nextLink = pObj->Alg_SynthesisLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[2].prevLinkId = pObj->Alg_PhotoAlignLinkID;
       pObj->Alg_SynthesisPrm.inQueParams[2].prevLinkQueId = 0;

       //Select -> VPE_sv_org1
       pObj->SelectPrm.outQueParams[0].nextLink = pObj->VPE_sv_org1LinkID;
       pObj->VPE_sv_org1Prm.inQueParams.prevLinkId = pObj->SelectLinkID;
       pObj->VPE_sv_org1Prm.inQueParams.prevLinkQueId = 0;

       //Select -> VPE_sv_org2
       pObj->SelectPrm.outQueParams[1].nextLink = pObj->VPE_sv_org2LinkID;
       pObj->VPE_sv_org2Prm.inQueParams.prevLinkId = pObj->SelectLinkID;
       pObj->VPE_sv_org2Prm.inQueParams.prevLinkQueId = 1;

       //VPE_sv_org2 -> Sync_sv_org2
       pObj->VPE_sv_org2Prm.outQueParams[0].nextLink = pObj->Sync_sv_org2LinkID;
       pObj->Sync_sv_org2Prm.inQueParams.prevLinkId = pObj->VPE_sv_org2LinkID;
       pObj->Sync_sv_org2Prm.inQueParams.prevLinkQueId = 0;

       //Sync_sv_org2 -> Alg_DmaSwMs_sv_org2
       pObj->Sync_sv_org2Prm.outQueParams.nextLink = pObj->Alg_DmaSwMs_sv_org2LinkID;
       pObj->Alg_DmaSwMs_sv_org2Prm.inQueParams.prevLinkId = pObj->Sync_sv_org2LinkID;
       pObj->Alg_DmaSwMs_sv_org2Prm.inQueParams.prevLinkQueId = 0;

       //Alg_DmaSwMs_sv_org2 -> Display_sv_org2
       pObj->Alg_DmaSwMs_sv_org2Prm.outQueParams.nextLink = pObj->Display_sv_org2LinkID;
       pObj->Display_sv_org2Prm.inQueParams.prevLinkId = pObj->Alg_DmaSwMs_sv_org2LinkID;
       pObj->Display_sv_org2Prm.inQueParams.prevLinkQueId = 0;

       //VPE_sv_org1 -> Sync_sv_org1
       pObj->VPE_sv_org1Prm.outQueParams[0].nextLink = pObj->Sync_sv_org1LinkID;
       pObj->Sync_sv_org1Prm.inQueParams.prevLinkId = pObj->VPE_sv_org1LinkID;
       pObj->Sync_sv_org1Prm.inQueParams.prevLinkQueId = 0;

       //Sync_sv_org1 -> Alg_DmaSwMs_sv_org1
       pObj->Sync_sv_org1Prm.outQueParams.nextLink = pObj->Alg_DmaSwMs_sv_org1LinkID;
       pObj->Alg_DmaSwMs_sv_org1Prm.inQueParams.prevLinkId = pObj->Sync_sv_org1LinkID;
       pObj->Alg_DmaSwMs_sv_org1Prm.inQueParams.prevLinkQueId = 0;

       //Alg_DmaSwMs_sv_org1 -> Display_sv_org1
       pObj->Alg_DmaSwMs_sv_org1Prm.outQueParams.nextLink = pObj->Display_sv_org1LinkID;
       pObj->Display_sv_org1Prm.inQueParams.prevLinkId = pObj->Alg_DmaSwMs_sv_org1LinkID;
       pObj->Display_sv_org1Prm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_ov490VipSurroundViewStandalone_Create(chains_ov490VipSurroundViewStandaloneObj *pObj, Void *appObj){

       Int32 status;

       chains_ov490VipSurroundViewStandalone_SetLinkId(pObj);
       chains_ov490VipSurroundViewStandalone_ResetLinkPrms(pObj);

       chains_ov490VipSurroundViewStandalone_SetPrms(pObj);
       chains_ov490VipSurroundViewStandalone_SetAppPrms(pObj, appObj);

       chains_ov490VipSurroundViewStandalone_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SplitLinkID, &pObj->SplitPrm, sizeof(pObj->SplitPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Dup_sv_orgLinkID, &pObj->Dup_sv_orgPrm, sizeof(pObj->Dup_sv_orgPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Sync_svLinkID, &pObj->Sync_svPrm, sizeof(pObj->Sync_svPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Dup_svLinkID, &pObj->Dup_svPrm, sizeof(pObj->Dup_svPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_DSP1_1LinkID, &pObj->IPCOut_IPU1_0_DSP1_1Prm, sizeof(pObj->IPCOut_IPU1_0_DSP1_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP1_IPU1_0_1LinkID, &pObj->IPCIn_DSP1_IPU1_0_1Prm, sizeof(pObj->IPCIn_DSP1_IPU1_0_1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_DSP1_0LinkID, &pObj->IPCOut_IPU1_0_DSP1_0Prm, sizeof(pObj->IPCOut_IPU1_0_DSP1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP1_IPU1_0_0LinkID, &pObj->IPCIn_DSP1_IPU1_0_0Prm, sizeof(pObj->IPCIn_DSP1_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_GeoAlignLinkID, &pObj->Alg_GeoAlignPrm, sizeof(pObj->Alg_GeoAlignPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_SynthesisLinkID, &pObj->Alg_SynthesisPrm, sizeof(pObj->Alg_SynthesisPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_DSP1_IPU1_0_0LinkID, &pObj->IPCOut_DSP1_IPU1_0_0Prm, sizeof(pObj->IPCOut_DSP1_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_IPU1_0_DSP1_0LinkID, &pObj->IPCIn_IPU1_0_DSP1_0Prm, sizeof(pObj->IPCIn_IPU1_0_DSP1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_svLinkID, &pObj->Display_svPrm, sizeof(pObj->Display_svPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_PhotoAlignLinkID, &pObj->Alg_PhotoAlignPrm, sizeof(pObj->Alg_PhotoAlignPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SelectLinkID, &pObj->SelectPrm, sizeof(pObj->SelectPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->VPE_sv_org2LinkID, &pObj->VPE_sv_org2Prm, sizeof(pObj->VPE_sv_org2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Sync_sv_org2LinkID, &pObj->Sync_sv_org2Prm, sizeof(pObj->Sync_sv_org2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_DmaSwMs_sv_org2LinkID, &pObj->Alg_DmaSwMs_sv_org2Prm, sizeof(pObj->Alg_DmaSwMs_sv_org2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_sv_org2LinkID, &pObj->Display_sv_org2Prm, sizeof(pObj->Display_sv_org2Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->VPE_sv_org1LinkID, &pObj->VPE_sv_org1Prm, sizeof(pObj->VPE_sv_org1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Sync_sv_org1LinkID, &pObj->Sync_sv_org1Prm, sizeof(pObj->Sync_sv_org1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_DmaSwMs_sv_org1LinkID, &pObj->Alg_DmaSwMs_sv_org1Prm, sizeof(pObj->Alg_DmaSwMs_sv_org1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_sv_org1LinkID, &pObj->Display_sv_org1Prm, sizeof(pObj->Display_sv_org1Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_ov490VipSurroundViewStandalone_Start(chains_ov490VipSurroundViewStandaloneObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_DmaSwMs_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Sync_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->VPE_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_DmaSwMs_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Sync_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->VPE_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SelectLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP1_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_DSP1_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Dup_sv_orgLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SplitLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_ov490VipSurroundViewStandalone_Stop(chains_ov490VipSurroundViewStandaloneObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_DmaSwMs_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Sync_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->VPE_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_DmaSwMs_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Sync_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->VPE_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SelectLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP1_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP1_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Dup_sv_orgLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SplitLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_ov490VipSurroundViewStandalone_Delete(chains_ov490VipSurroundViewStandaloneObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_DmaSwMs_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Sync_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->VPE_sv_org1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_DmaSwMs_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Sync_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->VPE_sv_org2LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SelectLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_PhotoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_SynthesisLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_GeoAlignLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP1_IPU1_0_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_DSP1_1LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Dup_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Sync_svLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Dup_sv_orgLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SplitLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_ov490VipSurroundViewStandalone_printBufferStatistics(chains_ov490VipSurroundViewStandaloneObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->SplitLinkID);
       System_linkPrintBufferStatistics(pObj->Dup_sv_orgLinkID);
       System_linkPrintBufferStatistics(pObj->Sync_svLinkID);
       System_linkPrintBufferStatistics(pObj->Dup_svLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_DSP1_1LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP1_IPU1_0_1LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_DSP1_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP1_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_GeoAlignLinkID);
       System_linkPrintBufferStatistics(pObj->Alg_SynthesisLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       System_linkPrintBufferStatistics(pObj->Display_svLinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->Alg_PhotoAlignLinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->SelectLinkID);
       System_linkPrintBufferStatistics(pObj->VPE_sv_org2LinkID);
       System_linkPrintBufferStatistics(pObj->Sync_sv_org2LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_DmaSwMs_sv_org2LinkID);
       System_linkPrintBufferStatistics(pObj->Display_sv_org2LinkID);
       System_linkPrintBufferStatistics(pObj->VPE_sv_org1LinkID);
       System_linkPrintBufferStatistics(pObj->Sync_sv_org1LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_DmaSwMs_sv_org1LinkID);
       System_linkPrintBufferStatistics(pObj->Display_sv_org1LinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_ov490VipSurroundViewStandalone_printStatistics(chains_ov490VipSurroundViewStandaloneObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->SplitLinkID);
       System_linkPrintStatistics(pObj->Dup_sv_orgLinkID);
       System_linkPrintStatistics(pObj->Sync_svLinkID);
       System_linkPrintStatistics(pObj->Dup_svLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_DSP1_1LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP1_IPU1_0_1LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_DSP1_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP1_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->Alg_GeoAlignLinkID);
       System_linkPrintStatistics(pObj->Alg_SynthesisLinkID);
       System_linkPrintStatistics(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       System_linkPrintStatistics(pObj->Display_svLinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->Alg_PhotoAlignLinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->SelectLinkID);
       System_linkPrintStatistics(pObj->VPE_sv_org2LinkID);
       System_linkPrintStatistics(pObj->Sync_sv_org2LinkID);
       System_linkPrintStatistics(pObj->Alg_DmaSwMs_sv_org2LinkID);
       System_linkPrintStatistics(pObj->Display_sv_org2LinkID);
       System_linkPrintStatistics(pObj->VPE_sv_org1LinkID);
       System_linkPrintStatistics(pObj->Sync_sv_org1LinkID);
       System_linkPrintStatistics(pObj->Alg_DmaSwMs_sv_org1LinkID);
       System_linkPrintStatistics(pObj->Display_sv_org1LinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

