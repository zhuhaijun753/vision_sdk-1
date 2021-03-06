

SRCDIR += surroundview

SRCS_SURROUND_VIEW_SYTH = synthesisLink_algPlugin.c  \

SRCS_SURROUND_VIEW_PALIGN = pAlignLink_algPlugin.c \

SRCS_SURROUND_VIEW_ULTRASONICFUSION = uFusionLink_algPlugin.c UFusionExt.c UFusion_bufferZonesLUT.c \

SRCS_SURROUND_VIEW_GALIGN = gAlignLink_algPlugin.c \

ifeq ($(SOC), tda2xx)
SRCS_SURROUND_VIEW_GALIGN += GAlignLUT_tda2xx.c GAlignExt_tda2xx.c
endif

ifeq ($(SOC), tda2ex)
SRCS_SURROUND_VIEW_GALIGN += GAlignLUT_tda2xx.c GAlignExt_tda2xx.c
endif

ifeq ($(SOC), tda3xx)
SRCS_SURROUND_VIEW_GALIGN += GAlignLUT_tda3xx.c GAlignExt_tda3xx.c
endif

SRCS_c66xdsp_1 += $(SRCS_SURROUND_VIEW_SYTH) $(SRCS_SURROUND_VIEW_PALIGN) $(SRCS_SURROUND_VIEW_ULTRASONICFUSION) $(SRCS_SURROUND_VIEW_GALIGN)





