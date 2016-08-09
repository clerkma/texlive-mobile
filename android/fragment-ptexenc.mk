# for ptexenc
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

PTEXENC_ROOT     := ../src/texlive-upstream/texk/ptexenc
PTEXENC_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk/\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc
PTEXENC_FILES    := \
$(PTEXENC_ROOT)/kanjicnv.c \
$(PTEXENC_ROOT)/ptexenc.c \
$(PTEXENC_ROOT)/unicode.c \
$(PTEXENC_ROOT)/unicode-jp.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libptexenc
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas\
-DHAVE_CONFIG_H -DMAKE_KPSE_DLL -DMAKE_PTENC_DLL -O2
LOCAL_C_INCLUDES := $(PTEXENC_INCLUDES)
LOCAL_SRC_FILES  := $(PTEXENC_FILES)

include $(BUILD_STATIC_LIBRARY)
