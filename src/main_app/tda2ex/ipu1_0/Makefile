
APP_NAME = vision_sdk

SRCDIR = src
INCDIR = .

# List all the external components/interfaces, whose interface header files
#  need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = bios xdc starterware bsp ipc fc xdais edma hdvicplib jpegvdec jpegvenc vision_sdk starterware_hal

# List all the components required by the application
COMP_LIST_$(CORE) = bios xdc ipc starterware fc xdais edma hdvicplib jpegvdec jpegvenc vision_sdk

# XDC CFG File
XDC_CFG_FILE_$(CORE) = MAIN_APP_$(CORE).cfg

# Common source files and CFLAGS across all platforms and cores
SRCS_$(CORE) = main_$(CORE).c

ifeq ($(IPU1_EVELOADER_INCLUDE),yes)
INCDIR += $(vision_sdk_PATH)/src/utils_common/src/eveloader
SRCS_$(CORE) += eve_firmware.c
endif

CFLAGS_LOCAL_$(CORE) = $(vision_sdk_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
include $(ROOTDIR)/build/makerules/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
