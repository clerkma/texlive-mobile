# for libz
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

ZLIB_ROOT     := ../src/texlive-upstream/libs/zlib/zlib-src
ZLIB_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include
ZLIB_FILES := \
$(ZLIB_ROOT)/adler32.c \
$(ZLIB_ROOT)/compress.c \
$(ZLIB_ROOT)/crc32.c \
$(ZLIB_ROOT)/deflate.c \
$(ZLIB_ROOT)/infback.c \
$(ZLIB_ROOT)/gzclose.c \
$(ZLIB_ROOT)/gzlib.c \
$(ZLIB_ROOT)/gzread.c \
$(ZLIB_ROOT)/gzwrite.c \
$(ZLIB_ROOT)/inffast.c \
$(ZLIB_ROOT)/inflate.c \
$(ZLIB_ROOT)/inftrees.c \
$(ZLIB_ROOT)/trees.c \
$(ZLIB_ROOT)/uncompr.c \
$(ZLIB_ROOT)/zutil.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libz
LOCAL_CFLAGS     := -O2
LOCAL_C_INCLUDES := $(ZLIB_INCLUDES)
LOCAL_SRC_FILES  := $(ZLIB_FILES)

include $(BUILD_STATIC_LIBRARY)
