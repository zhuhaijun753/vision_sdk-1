/*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

/*
 *  ======== mem_segment_definition.xs ========
 *  ======== Single file for the memory map configuration of all cores =========
 */

KB=1024;
MB=KB*KB;

/* Allocation of cores' internal memory resources */
DSP1_L2_SRAM_ADDR           = 0x40800000;
DSP1_L2_SRAM_SIZE           = 288*KB;

DSP2_L2_SRAM_ADDR           = 0x41000000;
DSP2_L2_SRAM_SIZE           = 288*KB;

EVE1_SRAM_ADDR              = 0x42000000;
EVE1_SRAM_SIZE              = 1*MB;

EVE2_SRAM_ADDR              = 0x42100000;
EVE2_SRAM_SIZE              = 1*MB;

EVE3_SRAM_ADDR              = 0x42200000;
EVE3_SRAM_SIZE              = 1*MB;

EVE4_SRAM_ADDR              = 0x42300000;
EVE4_SRAM_SIZE              = 1*MB;

/* DDR3 Memory map 1.5GB */
/*************************
Required-by          Size    Address     Used-for                  Cacheable
A15-Linux            88MB    0x80000000      
A15, IPU1/2, DSP1/2 256MB    0x85800000  SR1+NDK                   Yes to All cores
IPU2-Bios            56MB    0x95800000  IPUMM               
DSP1-Bios            64MB    0x99000000  RADIO (+ Analytic algos)  16MB non-cacheable - required by RADIO
IPU1-Bios            32MB    0x9D000000  Vision-SDK FWK            Yes to IPU1 
DSP2-Bios            32MB    0x9F000000  SRV Algos                 Yes to DSP2         
A15, IPU1/2, DSP1/2  32MB    0xA1000000  SR0                       No to All cores 
EVE                  64MB    0xA3800000                      
A15-Linux           392MB    0xA7800000      
A15-Linux           512MB    0xC0000000(End of Interleaving) 
*************************/
DDR3_ADDR                   = 0x80000000;
DDR3_SIZE                   = 1024*MB;
DDR3_LINUX_MEM_OFFSET       = 88*MB;

/* First 512 MB - cached */
DDR3_BASE_ADDR_0            = 0x80000000;
DDR3_BASE_SIZE_0            = 424*MB + DDR3_LINUX_MEM_OFFSET;


/* The start address of the second mem section should be 16MB aligned.
 * This alignment is a must as a single 16MB mapping is used for EVE
 * to map SR0, REMOTE_LOG_MEM sections.
 * tlb_config_eveX.c need to be modified otherwise
 */
DDR3_BASE_ADDR_1            = 0xA0000000;
DDR3_BASE_SIZE_1            = 512*MB;

/* Address and Size definitions of different components running on different cores */
NDK_START_ADDR              = 0x85800000;
NDK_MEM_SIZE                =   2*MB
SR1_FRAME_BUFFER_SIZE       = 250*MB;

DSP1_START_ADDR             = 0x99000000;
DSP1_CODE_SIZE              =   2*MB;
DSP1_DATA_SIZE              =  24*MB;

IPU1_START_ADDR             = 0x9D000000;
IPU1_1_CODE_SIZE            =   2*MB;
IPU1_1_BSS_SIZE             =   2*MB;
IPU1_1_DATA_SIZE            =   2*MB;
IPU1_0_CODE_SIZE            =   5*MB;
IPU1_0_DATA_SIZE            =   4*MB;
IPU1_0_BSS_SIZE             =  17*MB - IPU1_0_DATA_SIZE;

DSP2_START_ADDR             = 0x9F000000;
DSP2_CODE_SIZE              =   2*MB;
DSP2_DATA_SIZE              =  10*MB;

/* The start address of the second mem section should be 16MB aligned.
 * This alignment is a must as a single 16MB mapping is used for EVE
 * to map SR0, EMOTE_LOG_MEM sections.
 * tlb_config_eveX.c need to be modified otherwise
 *
 * size of REMOTE_LOG_SIZE+SYSTEM_IPC_SHM_SIZE+LINK_STATS_SIZE+
 *         HDVPSS_DESC_SIZE+SR0_SIZE
 * MUST be a multiple of MB
 */
REMOTE_LOG_SIZE             =  256*KB;
SYSTEM_IPC_SHM_SIZE         =  256*KB;
LINK_STATS_SIZE             =  512*KB;
HDVPSS_DESC_SIZE            = 1024*KB;
SR0_SIZE                    = 1024*KB;
TRACE_BUF_LEN               =  384*KB;
EXC_DATA_LEN                =   64*KB;
PM_DATA_LEN                 =  512*KB;

/* The start address of EVE memory must be 16MB aligned. */
EVE_START_ADDR              = 0xA2000000;
/* EVE vecs space should be align with 16MB boundary, and if possible try to fit
 * the entire vecs+code+data in 16MB section. In this case a single TLB map would
 * be enough to map vecs+code+data of an EVE.
 * tlb_config_eveX.c need to be modified if any of these EVE memory sections or
 * SR1_FRAME_BUFFER_MEM section is modified.
 */
EVE1_VECS_SIZE              = 0.5*MB;
EVE1_CODE_SIZE              =   2*MB;
EVE1_DATA_SIZE              =13.5*MB;
EVE2_VECS_SIZE              = 0.5*MB;
EVE2_CODE_SIZE              =   2*MB;
EVE2_DATA_SIZE              =13.5*MB;
EVE3_VECS_SIZE              = 0.5*MB;
EVE3_CODE_SIZE              =   2*MB;
EVE3_DATA_SIZE              =13.5*MB;
EVE4_VECS_SIZE              = 0.5*MB;
EVE4_CODE_SIZE              =   2*MB;
EVE4_DATA_SIZE              =13.5*MB;

TOTAL_MEM_SIZE              = (DDR3_SIZE);


/* A single Linux mem hole is used for both NDK MEM and SR1_FRAME MEM
 * So both of these sections should be one after another without any gap
 */
NDK_MEM_ADDR                = NDK_START_ADDR
SR1_FRAME_BUFFER_ADDR       = NDK_MEM_ADDR          + NDK_MEM_SIZE;

DSP1_CODE_ADDR              = DSP1_START_ADDR;
DSP1_DATA_ADDR              = DSP1_CODE_ADDR        + DSP1_CODE_SIZE;

IPU1_1_CODE_ADDR            = IPU1_START_ADDR;
IPU1_1_DATA_ADDR            = IPU1_1_CODE_ADDR      + IPU1_1_CODE_SIZE;
IPU1_1_BSS_ADDR             = IPU1_1_DATA_ADDR      + IPU1_1_DATA_SIZE;
IPU1_0_CODE_ADDR            = IPU1_1_BSS_ADDR       + IPU1_1_BSS_SIZE;
IPU1_0_DATA_ADDR            = IPU1_0_CODE_ADDR      + IPU1_0_CODE_SIZE;
IPU1_0_BSS_ADDR             = IPU1_0_DATA_ADDR      + IPU1_0_DATA_SIZE;

DSP2_CODE_ADDR              = DSP2_START_ADDR;
DSP2_DATA_ADDR              = DSP2_CODE_ADDR        + DSP2_CODE_SIZE;

/* Non Cached Section for IPU1 */
/* The start address of the second mem section should be 16MB aligned.
 * This alignment is a must as a single 16MB mapping is used for EVE
 * to map SR0, EMOTE_LOG_MEM sections.
 * tlb_config_eveX.c need to be modified otherwise
 */
SR0_ADDR                    = DDR3_BASE_ADDR_1 + 1*MB; /* Leaving 1MB for virtqueue of DSP - this is hardcoded in ipc virqueue */
REMOTE_LOG_ADDR             = SR0_ADDR              + SR0_SIZE;
LINK_STATS_ADDR             = REMOTE_LOG_ADDR       + REMOTE_LOG_SIZE;
SYSTEM_IPC_SHM_ADDR         = LINK_STATS_ADDR       + LINK_STATS_SIZE;
HDVPSS_DESC_ADDR            = SYSTEM_IPC_SHM_ADDR   + SYSTEM_IPC_SHM_SIZE;
TRACE_BUF_BASE              = HDVPSS_DESC_ADDR      + HDVPSS_DESC_SIZE;
EXC_DATA_BASE               = TRACE_BUF_BASE        + TRACE_BUF_LEN;
PM_DATA_BASE                = EXC_DATA_BASE         + EXC_DATA_LEN;

/* EVE vecs space should be align with 16MB boundary, and if possible try to fit
 * the entire vecs+code+data in 16MB section. In this case a single TLB map would
 * be enough to map vecs+code+data of an EVE.
 * tlb_config_eveX.c need to be modified if any of these EVE memory sections or
 * SR1_FRAME_BUFFER_MEM section is modified.
 */

EVE1_VECS_ADDR              = EVE_START_ADDR
EVE1_CODE_ADDR              = EVE1_VECS_ADDR        + EVE1_VECS_SIZE;
EVE1_DATA_ADDR              = EVE1_CODE_ADDR        + EVE1_CODE_SIZE;
EVE2_VECS_ADDR              = EVE1_DATA_ADDR        + EVE1_DATA_SIZE;
EVE2_CODE_ADDR              = EVE2_VECS_ADDR        + EVE2_VECS_SIZE;
EVE2_DATA_ADDR              = EVE2_CODE_ADDR        + EVE2_CODE_SIZE;
EVE3_VECS_ADDR              = EVE2_DATA_ADDR        + EVE2_DATA_SIZE;
EVE3_CODE_ADDR              = EVE3_VECS_ADDR        + EVE3_VECS_SIZE;
EVE3_DATA_ADDR              = EVE3_CODE_ADDR        + EVE3_CODE_SIZE;
EVE4_VECS_ADDR              = EVE3_DATA_ADDR        + EVE3_DATA_SIZE;
EVE4_CODE_ADDR              = EVE4_VECS_ADDR        + EVE4_VECS_SIZE;
EVE4_DATA_ADDR              = EVE4_CODE_ADDR        + EVE4_CODE_SIZE;

function getMemSegmentDefinition_external(core)
{
    var memory = new Array();
    var index = 0;

    memory[index++] = ["IPU1_1_CODE_MEM", {
            comment : "IPU1_1_CODE_MEM",
            name    : "IPU1_1_CODE_MEM",
            base    : IPU1_1_CODE_ADDR,
            len     : IPU1_1_CODE_SIZE
        }];
    memory[index++] = ["IPU1_1_DATA_MEM", {
            comment : "IPU1_1_DATA_MEM",
            name    : "IPU1_1_DATA_MEM",
            base    : IPU1_1_DATA_ADDR,
            len     : IPU1_1_DATA_SIZE
        }];
    memory[index++] = ["IPU1_1_BSS_MEM", {
            comment : "IPU1_1_BSS_MEM",
            name    : "IPU1_1_BSS_MEM",
            base    : IPU1_1_BSS_ADDR,
            len     : IPU1_1_BSS_SIZE
        }];
    memory[index++] = ["IPU1_0_CODE_MEM", {
            comment : "IPU1_0_CODE_MEM",
            name    : "IPU1_0_CODE_MEM",
            base    : IPU1_0_CODE_ADDR,
            len     : IPU1_0_CODE_SIZE
        }];
    memory[index++] = ["IPU1_0_DATA_MEM", {
            comment : "IPU1_0_DATA_MEM",
            name    : "IPU1_0_DATA_MEM",
            base    : IPU1_0_DATA_ADDR,
            len     : IPU1_0_DATA_SIZE
        }];
    memory[index++] = ["IPU1_0_BSS_MEM", {
            comment : "IPU1_0_BSS_MEM",
            name    : "IPU1_0_BSS_MEM",
            base    : IPU1_0_BSS_ADDR,
            len     : IPU1_0_BSS_SIZE
        }];
    memory[index++] = ["NDK_MEM", {
            comment : "NDK_MEM",
            name    : "NDK_MEM",
            base    : NDK_MEM_ADDR,
            len     : NDK_MEM_SIZE
        }];
    memory[index++] = ["DSP1_CODE_MEM", {
            comment : "DSP1_CODE_MEM",
            name    : "DSP1_CODE_MEM",
            base    : DSP1_CODE_ADDR,
            len     : DSP1_CODE_SIZE
        }];
    memory[index++] = ["DSP1_DATA_MEM", {
            comment : "DSP1_DATA_MEM",
            name    : "DSP1_DATA_MEM",
            base    : DSP1_DATA_ADDR,
            len     : DSP1_DATA_SIZE
        }];

    memory[index++] = ["DSP2_CODE_MEM", {
            comment : "DSP2_CODE_MEM",
            name    : "DSP2_CODE_MEM",
            base    : DSP2_CODE_ADDR,
            len     : DSP2_CODE_SIZE
        }];
    memory[index++] = ["DSP2_DATA_MEM", {
            comment : "DSP2_DATA_MEM",
            name    : "DSP2_DATA_MEM",
            base    : DSP2_DATA_ADDR,
            len     : DSP2_DATA_SIZE
        }];

    memory[index++] = ["EVE1_VECS_MEM", {
            comment : "EVE1_VECS_MEM",
            name    : "EVE1_VECS_MEM",
            base    : EVE1_VECS_ADDR,
            len     : EVE1_VECS_SIZE
        }];
    memory[index++] = ["EVE1_CODE_MEM", {
            comment : "EVE1_CODE_MEM",
            name    : "EVE1_CODE_MEM",
            base    : EVE1_CODE_ADDR,
            len     : EVE1_CODE_SIZE
        }];
    memory[index++] = ["EVE1_DATA_MEM", {
            comment : "EVE1_DATA_MEM",
            name    : "EVE1_DATA_MEM",
            base    : EVE1_DATA_ADDR,
            len     : EVE1_DATA_SIZE
        }];
    memory[index++] = ["EVE2_VECS_MEM", {
            comment : "EVE2_VECS_MEM",
            name    : "EVE2_VECS_MEM",
            base    : EVE2_VECS_ADDR,
            len     : EVE2_VECS_SIZE
        }];
    memory[index++] = ["EVE2_CODE_MEM", {
            comment : "EVE2_CODE_MEM",
            name    : "EVE2_CODE_MEM",
            base    : EVE2_CODE_ADDR,
            len     : EVE2_CODE_SIZE
        }];
    memory[index++] = ["EVE2_DATA_MEM", {
            comment : "EVE2_DATA_MEM",
            name    : "EVE2_DATA_MEM",
            base    : EVE2_DATA_ADDR,
            len     : EVE2_DATA_SIZE
        }];
    memory[index++] = ["EVE3_VECS_MEM", {
            comment : "EVE3_VECS_MEM",
            name    : "EVE3_VECS_MEM",
            base    : EVE3_VECS_ADDR,
            len     : EVE3_VECS_SIZE
        }];
    memory[index++] = ["EVE3_CODE_MEM", {
            comment : "EVE3_CODE_MEM",
            name    : "EVE3_CODE_MEM",
            base    : EVE3_CODE_ADDR,
            len     : EVE3_CODE_SIZE
        }];
    memory[index++] = ["EVE3_DATA_MEM", {
            comment : "EVE3_DATA_MEM",
            name    : "EVE3_DATA_MEM",
            base    : EVE3_DATA_ADDR,
            len     : EVE3_DATA_SIZE
        }];
    memory[index++] = ["EVE4_VECS_MEM", {
            comment : "EVE4_VECS_MEM",
            name    : "EVE4_VECS_MEM",
            base    : EVE4_VECS_ADDR,
            len     : EVE4_VECS_SIZE
        }];
    memory[index++] = ["EVE4_CODE_MEM", {
            comment : "EVE4_CODE_MEM",
            name    : "EVE4_CODE_MEM",
            base    : EVE4_CODE_ADDR,
            len     : EVE4_CODE_SIZE
        }];
    memory[index++] = ["EVE4_DATA_MEM", {
            comment : "EVE4_DATA_MEM",
            name    : "EVE4_DATA_MEM",
            base    : EVE4_DATA_ADDR,
            len     : EVE4_DATA_SIZE
        }];
    memory[index++] = ["SR1_FRAME_BUFFER_MEM", {
            comment : "SR1_FRAME_BUFFER_MEM",
            name    : "SR1_FRAME_BUFFER_MEM",
            base    : SR1_FRAME_BUFFER_ADDR,
            len     : SR1_FRAME_BUFFER_SIZE
        }];
    memory[index++] = ["SR0", {
            comment : "SR0",
            name    : "SR0",
            base    : SR0_ADDR,
            len     : SR0_SIZE
        }];
    memory[index++] = ["HDVPSS_DESC_MEM", {
            comment : "HDVPSS_DESC_MEM",
            name    : "HDVPSS_DESC_MEM",
            base    : HDVPSS_DESC_ADDR,
            len     : HDVPSS_DESC_SIZE
        }];
    memory[index++] = ["REMOTE_LOG_MEM", {
            comment : "REMOTE_LOG_MEM",
            name    : "REMOTE_LOG_MEM",
            base    : REMOTE_LOG_ADDR,
            len     : REMOTE_LOG_SIZE
        }];
    memory[index++] = ["LINK_STATS_MEM", {
            comment : "LINK_STATS_MEM",
            name    : "LINK_STATS_MEM",
            base    : LINK_STATS_ADDR,
            len     : LINK_STATS_SIZE
        }];
    memory[index++] = ["SYSTEM_IPC_SHM_MEM", {
            comment : "SYSTEM_IPC_SHM_MEM",
            name    : "SYSTEM_IPC_SHM_MEM",
            base    : SYSTEM_IPC_SHM_ADDR,
            len     : SYSTEM_IPC_SHM_SIZE
        }];

    xdc.print("# !!! Core is [" + core + "] !!!" );

    memory[index++] = ["DSP1_L2_SRAM", {
            comment: "DSP1_L2_SRAM",
            name: "DSP1_L2_SRAM",
            base: DSP1_L2_SRAM_ADDR,
            len:  DSP1_L2_SRAM_SIZE
        }];
    memory[index++] = ["DSP2_L2_SRAM", {
            comment: "DSP2_L2_SRAM",
            name: "DSP2_L2_SRAM",
            base: DSP2_L2_SRAM_ADDR,
            len:  DSP2_L2_SRAM_SIZE
        }];
    memory[index++] = ["TRACE_BUF", {
            comment: "TRACE_BUF",
            name: "TRACE_BUF",
            base: TRACE_BUF_BASE,
            len:  TRACE_BUF_LEN,
        }];
    memory[index++] = ["EXC_DATA", {
            comment: "EXC_DATA",
            name: "EXC_DATA",
            base: EXC_DATA_BASE,
            len:  EXC_DATA_LEN,
        }];
    memory[index++] = ["PM_DATA", {
            comment: "PM_DATA",
            name: "PM_DATA",
            base: PM_DATA_BASE,
            len:  PM_DATA_LEN,
        }];

    return (memory);
}

