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

#ifndef _chains_ov490VipSurroundViewStandalone_H_
#define _chains_ov490VipSurroundViewStandalone_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/splitLink.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/algorithmLink_geometricAlignment.h>
#include <include/link_api/algorithmLink_synthesis.h>
#include <include/link_api/ipcLink.h>
#include <include/link_api/algorithmLink_photoAlignment.h>
#include <include/link_api/selectLink.h>
#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_dmaSwMs.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    SplitLinkID;
       UInt32    Dup_sv_orgLinkID;
       UInt32    Sync_svLinkID;
       UInt32    Dup_svLinkID;
       UInt32    IPCOut_IPU1_0_DSP1_1LinkID;
       UInt32    IPCIn_DSP1_IPU1_0_1LinkID;
       UInt32    IPCOut_IPU1_0_DSP1_0LinkID;
       UInt32    IPCIn_DSP1_IPU1_0_0LinkID;
       UInt32    Alg_GeoAlignLinkID;
       UInt32    Alg_SynthesisLinkID;
       UInt32    IPCOut_DSP1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP1_0LinkID;
       UInt32    Display_svLinkID;
       UInt32    Alg_PhotoAlignLinkID;
       UInt32    SelectLinkID;
       UInt32    VPE_sv_org2LinkID;
       UInt32    Sync_sv_org2LinkID;
       UInt32    Alg_DmaSwMs_sv_org2LinkID;
       UInt32    Display_sv_org2LinkID;
       UInt32    VPE_sv_org1LinkID;
       UInt32    Sync_sv_org1LinkID;
       UInt32    Alg_DmaSwMs_sv_org1LinkID;
       UInt32    Display_sv_org1LinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       SplitLink_CreateParams                  SplitPrm;
       DupLink_CreateParams                    Dup_sv_orgPrm;
       SyncLink_CreateParams                   Sync_svPrm;
       DupLink_CreateParams                    Dup_svPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_1Prm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_0Prm;
       AlgorithmLink_GAlignCreateParams        Alg_GeoAlignPrm;
       AlgorithmLink_SynthesisCreateParams     Alg_SynthesisPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_0Prm;
       DisplayLink_CreateParams                Display_svPrm;
       AlgorithmLink_PAlignCreateParams        Alg_PhotoAlignPrm;
       SelectLink_CreateParams                 SelectPrm;
       VpeLink_CreateParams                    VPE_sv_org2Prm;
       SyncLink_CreateParams                   Sync_sv_org2Prm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org2Prm;
       DisplayLink_CreateParams                Display_sv_org2Prm;
       VpeLink_CreateParams                    VPE_sv_org1Prm;
       SyncLink_CreateParams                   Sync_sv_org1Prm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org1Prm;
       DisplayLink_CreateParams                Display_sv_org1Prm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_ov490VipSurroundViewStandaloneObj;

Void chains_ov490VipSurroundViewStandalone_SetLinkId(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_ResetLinkPrms(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_SetPrms(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_ConnectLinks(chains_ov490VipSurroundViewStandaloneObj *pObj);

Int32 chains_ov490VipSurroundViewStandalone_Create(chains_ov490VipSurroundViewStandaloneObj *pObj, Void *appObj);

Int32 chains_ov490VipSurroundViewStandalone_Start(chains_ov490VipSurroundViewStandaloneObj *pObj);

Int32 chains_ov490VipSurroundViewStandalone_Stop(chains_ov490VipSurroundViewStandaloneObj *pObj);

Int32 chains_ov490VipSurroundViewStandalone_Delete(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_printBufferStatistics(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_printStatistics(chains_ov490VipSurroundViewStandaloneObj *pObj);

Void chains_ov490VipSurroundViewStandalone_SetAppPrms(chains_ov490VipSurroundViewStandaloneObj *pObj, Void *appObj);

#endif /* _chains_ov490VipSurroundViewStandalone_H_ */
