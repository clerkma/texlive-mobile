# for web2c
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LIB_ROOT     := ../src/texlive-upstream/texk/web2c/lib
LIB_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c

LIB_FILES := \
$(LIB_ROOT)/basechsuffix.c \
$(LIB_ROOT)/chartostring.c \
$(LIB_ROOT)/coredump.c \
$(LIB_ROOT)/eofeoln.c \
$(LIB_ROOT)/fprintreal.c \
$(LIB_ROOT)/inputint.c \
$(LIB_ROOT)/input2int.c \
$(LIB_ROOT)/main.c \
$(LIB_ROOT)/openclose.c \
$(LIB_ROOT)/printversion.c \
$(LIB_ROOT)/setupvar.c \
$(LIB_ROOT)/uexit.c \
$(LIB_ROOT)/usage.c \
$(LIB_ROOT)/version.c \
$(LIB_ROOT)/zround.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libn
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(LIB_INCLUDES)
LOCAL_SRC_FILES  := $(LIB_FILES)

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LIBP_ROOT     := ../src/texlive-upstream/texk/web2c/lib
LIBP_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc

LIBP_FILES := \
$(LIBP_ROOT)/openclose.c \
$(LIBP_ROOT)/printversion.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libp
LOCAL_CFLAGS     := -DPTEX -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(LIBP_INCLUDES)
LOCAL_SRC_FILES  := $(LIBP_FILES)

include $(BUILD_STATIC_LIBRARY)

include fragment-kpathsea.mk

#for tex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/texextra.c \
$(PROG_ROOT)/texini.c \
$(PROG_ROOT)/tex0.c \
$(PROG_ROOT)/tex-pool.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := tex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)
