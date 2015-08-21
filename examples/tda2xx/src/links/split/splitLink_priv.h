 /*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \ingroup SPLIT_LINK_API
 * \defgroup SPLIT_LINK_IMPL Split Link Implementation
 *
 * @{
 */

/**
 *******************************************************************************
 *
 * \file splitLink_priv.h Split Link private API/Data structures
 *
 * \brief  This file is a private header file for split link implementation
 *         This file lists the data structures, function prototypes which are
 *         implemented and used as a part of split link.
 *         Split Link is used in cases where the output buffers from one link is
 *         to be sent to multiple links. Split link simply duplicates the buffers
 *         without actually duplicating the video frame and send these buffers
 *         across all output queues. Split link implements the logic to release
 *         buffers to it's previous link only when every link connected to it's
 *         output queue release the buffers.
 *
 * \version 0.0 (Jul 2013) : [NN] First version
 *
 *******************************************************************************
 */

#ifndef _SPLIT_LINK_PRIV_H_
#define _SPLIT_LINK_PRIV_H_

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */
#include <src/links_ipu/system/system_priv_ipu1_0.h>
#include <include/link_api/splitLink.h>

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */

#define SPLIT_LINK_TSK_STACK_SIZE        (SYSTEM_DEFAULT_TSK_STACK_SIZE)
#define SPLIT_LINK_TSK_PRI               (12)

 /**
 *******************************************************************************
 *
 * \brief Maximum number of split link objects
 *
 * SUPPORTED in ALL platforms
 *
 *******************************************************************************
 */
#define SPLIT_LINK_OBJ_MAX    (1)

 /**
 *******************************************************************************
 *
 * \brief Maximum value of split factor
 *
 * SUPPORTED in ALL platforms
 *
 *******************************************************************************
 */
#define SPLIT_LINK_MAX_NUM_SPLITS    (3)

/**
 *******************************************************************************
 *
 * \brief Maximum frmaes an output queue can support
 *
 * SUPPORTED in ALL platforms
 *
 *******************************************************************************
 */
#define SPLIT_LINK_MAX_FRAMES_PER_OUT_QUE    \
                           (SYSTEM_LINK_FRAMES_PER_CH*SYSTEM_MAX_CH_PER_OUT_QUE)

/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */


/**
 *******************************************************************************
 *
 * \brief Stat structure that stores information about the number of
 *  - Recevied buffers
 *  - Forwarded buffers ( Sent to next link )
 *  - Released buffers ( Sent back to the previous link )
 *
 *******************************************************************************
 */
typedef struct {
    UInt32 recvCount;
    UInt32 forwardCount;
    UInt32 releaseCount;
} SplitLink_StatsObj;

/**
 *******************************************************************************
 *
 * \brief Structure to hold all Split link related information
 *
 *******************************************************************************
 */
typedef struct {
    UInt32 tskId;
    /**< Placeholder to store split link task id */

    UInt32 state;
    /**< Link state, one of SYSTEM_LINK_STATE_xxx */

    Utils_TskHndl tsk;
    /**< Handle to capture link task */

    SplitLink_CreateParams createArgs;
    /**< Create params for split link */

    UInt32 getFrameCount;
    /**< Count of incoming frames */

    UInt32 putFrameCount;
    /**< Count of outgoing frames */

    System_LinkInfo inTskInfo;
    /**< Output queue information of previous link */

    System_LinkInfo info;
    /**< Output queue information of this link */

    Utils_BufHndl outFrameQue;
    /**< Handles to each of the output queues */

    System_Buffer
        sysBufs[SPLIT_LINK_MAX_FRAMES_PER_OUT_QUE *
                SPLIT_LINK_MAX_NUM_SPLITS];
    /**< Placeholder to store the incoming buffers */

    System_VideoFrameBuffer
        sysVidFrmBufs[SPLIT_LINK_MAX_FRAMES_PER_OUT_QUE *
                      SPLIT_LINK_MAX_NUM_SPLITS];
    /**< Placeholder to store payload in the incoming buffers */

    System_BufferList inBufList;

    System_BufferList outBufList;

    BspOsal_SemHandle lock;
    /**< Link level lock, used while updating the link params */

    SplitLink_StatsObj stats;
    /**< To store statistics of the buffers */
} SplitLink_Obj;

extern SplitLink_Obj gSplitLink_obj[];

Void SplitLink_tskMain(struct Utils_TskHndl * pTsk, Utils_MsgHndl * pMsg);

Int32 SplitLink_tskCreate(UInt32 instId);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/* @} */


