# Copyright 2013, 2014, 2015, 2016 Clerk Ma
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301 USA.

# for xz
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

XZ_ROOT     := ../src/xz-5.2.2
XZ_INCLUDES := \
$(LOCAL_PATH)/../src/xz-5.2.2 \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/api \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/common \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/check \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/lz \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/rangecoder \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/lzma \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/delta \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/simple \
$(LOCAL_PATH)/../src/xz-5.2.2/src/common
XZ_FILES := \
$(XZ_ROOT)/src/common/tuklib_physmem.c \
$(XZ_ROOT)/src/common/tuklib_cpucores.c \
$(XZ_ROOT)/src/liblzma/common/common.c \
$(XZ_ROOT)/src/liblzma/common/block_util.c \
$(XZ_ROOT)/src/liblzma/common/easy_preset.c \
$(XZ_ROOT)/src/liblzma/common/filter_common.c \
$(XZ_ROOT)/src/liblzma/common/hardware_physmem.c \
$(XZ_ROOT)/src/liblzma/common/index.c \
$(XZ_ROOT)/src/liblzma/common/stream_flags_common.c \
$(XZ_ROOT)/src/liblzma/common/vli_size.c \
$(XZ_ROOT)/src/liblzma/common/alone_encoder.c \
$(XZ_ROOT)/src/liblzma/common/block_buffer_encoder.c \
$(XZ_ROOT)/src/liblzma/common/block_encoder.c \
$(XZ_ROOT)/src/liblzma/common/block_header_encoder.c \
$(XZ_ROOT)/src/liblzma/common/easy_buffer_encoder.c \
$(XZ_ROOT)/src/liblzma/common/easy_encoder.c \
$(XZ_ROOT)/src/liblzma/common/easy_encoder_memusage.c \
$(XZ_ROOT)/src/liblzma/common/filter_buffer_encoder.c \
$(XZ_ROOT)/src/liblzma/common/filter_encoder.c \
$(XZ_ROOT)/src/liblzma/common/filter_flags_encoder.c \
$(XZ_ROOT)/src/liblzma/common/index_encoder.c \
$(XZ_ROOT)/src/liblzma/common/stream_buffer_encoder.c \
$(XZ_ROOT)/src/liblzma/common/stream_encoder.c \
$(XZ_ROOT)/src/liblzma/common/stream_flags_encoder.c \
$(XZ_ROOT)/src/liblzma/common/vli_encoder.c \
$(XZ_ROOT)/src/liblzma/common/hardware_cputhreads.c \
$(XZ_ROOT)/src/liblzma/common/outqueue.c \
$(XZ_ROOT)/src/liblzma/common/stream_encoder_mt.c \
$(XZ_ROOT)/src/liblzma/common/alone_decoder.c \
$(XZ_ROOT)/src/liblzma/common/auto_decoder.c \
$(XZ_ROOT)/src/liblzma/common/block_buffer_decoder.c \
$(XZ_ROOT)/src/liblzma/common/block_decoder.c \
$(XZ_ROOT)/src/liblzma/common/block_header_decoder.c \
$(XZ_ROOT)/src/liblzma/common/easy_decoder_memusage.c \
$(XZ_ROOT)/src/liblzma/common/filter_buffer_decoder.c \
$(XZ_ROOT)/src/liblzma/common/filter_decoder.c \
$(XZ_ROOT)/src/liblzma/common/filter_flags_decoder.c \
$(XZ_ROOT)/src/liblzma/common/index_decoder.c \
$(XZ_ROOT)/src/liblzma/common/index_hash.c \
$(XZ_ROOT)/src/liblzma/common/stream_buffer_decoder.c \
$(XZ_ROOT)/src/liblzma/common/stream_decoder.c \
$(XZ_ROOT)/src/liblzma/common/stream_flags_decoder.c \
$(XZ_ROOT)/src/liblzma/common/vli_decoder.c \
$(XZ_ROOT)/src/liblzma/check/check.c \
$(XZ_ROOT)/src/liblzma/check/crc32_table.c \
$(XZ_ROOT)/src/liblzma/check/crc32_fast.c \
$(XZ_ROOT)/src/liblzma/check/crc64_table.c \
$(XZ_ROOT)/src/liblzma/check/crc64_fast.c \
$(XZ_ROOT)/src/liblzma/check/sha256.c \
$(XZ_ROOT)/src/liblzma/lz/lz_encoder.c \
$(XZ_ROOT)/src/liblzma/lz/lz_encoder_mf.c \
$(XZ_ROOT)/src/liblzma/lz/lz_decoder.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma_encoder.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma_encoder_presets.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma_encoder_optimum_fast.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma_encoder_optimum_normal.c \
$(XZ_ROOT)/src/liblzma/lzma/fastpos_table.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma_decoder.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma2_encoder.c \
$(XZ_ROOT)/src/liblzma/lzma/lzma2_decoder.c \
$(XZ_ROOT)/src/liblzma/rangecoder/price_table.c \
$(XZ_ROOT)/src/liblzma/delta/delta_common.c \
$(XZ_ROOT)/src/liblzma/delta/delta_encoder.c \
$(XZ_ROOT)/src/liblzma/delta/delta_decoder.c \
$(XZ_ROOT)/src/liblzma/simple/simple_coder.c \
$(XZ_ROOT)/src/liblzma/simple/simple_encoder.c \
$(XZ_ROOT)/src/liblzma/simple/simple_decoder.c \
$(XZ_ROOT)/src/liblzma/simple/x86.c \
$(XZ_ROOT)/src/liblzma/simple/powerpc.c \
$(XZ_ROOT)/src/liblzma/simple/ia64.c \
$(XZ_ROOT)/src/liblzma/simple/arm.c \
$(XZ_ROOT)/src/liblzma/simple/armthumb.c \
$(XZ_ROOT)/src/liblzma/simple/sparc.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := liblzma
LOCAL_CFLAGS     := -pie -fPIE -O2 \
-DHAVE_CONFIG_H \
-fvisibility=hidden -std=gnu99
LOCAL_C_INCLUDES := $(XZ_INCLUDES)
LOCAL_SRC_FILES  := $(XZ_FILES)

include $(BUILD_STATIC_LIBRARY)

# xzdec
include $(CLEAR_VARS)

XZ_ROOT     := ../src/xz-5.2.2
XZ_INCLUDES := \
$(LOCAL_PATH)/../src/xz-5.2.2 \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/api \
$(LOCAL_PATH)/../src/xz-5.2.2/src/common \
$(LOCAL_PATH)/../src/xz-5.2.2/src/lib
XZ_FILES := \
$(XZ_ROOT)/src/xzdec/xzdec.c \
$(XZ_ROOT)/src/common/tuklib_progname.c \
$(XZ_ROOT)/src/common/tuklib_exit.c

LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := liblzma
LOCAL_MODULE     := xzdec
LOCAL_CFLAGS     := -pie -fPIE -O2 \
-DHAVE_CONFIG_H -DTUKLIB_GETTEXT=0 \
-fvisibility=hidden -std=gnu99
LOCAL_C_INCLUDES := $(XZ_INCLUDES)
LOCAL_SRC_FILES  := $(XZ_FILES)

include $(BUILD_EXECUTABLE)

# xz
include $(CLEAR_VARS)

XZ_ROOT     := ../src/xz-5.2.2
XZ_INCLUDES := \
$(LOCAL_PATH)/../src/xz-5.2.2 \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma \
$(LOCAL_PATH)/../src/xz-5.2.2/src/liblzma/api \
$(LOCAL_PATH)/../src/xz-5.2.2/src/common \
$(LOCAL_PATH)/../src/xz-5.2.2/src/lib
XZ_FILES := \
$(XZ_ROOT)/src/xz/args.c \
$(XZ_ROOT)/src/xz/coder.c \
$(XZ_ROOT)/src/xz/file_io.c \
$(XZ_ROOT)/src/xz/hardware.c \
$(XZ_ROOT)/src/xz/list.c \
$(XZ_ROOT)/src/xz/main.c \
$(XZ_ROOT)/src/xz/message.c \
$(XZ_ROOT)/src/xz/mytime.c \
$(XZ_ROOT)/src/xz/options.c \
$(XZ_ROOT)/src/xz/signals.c \
$(XZ_ROOT)/src/xz/suffix.c \
$(XZ_ROOT)/src/xz/util.c \
$(XZ_ROOT)/src/common/tuklib_open_stdxxx.c \
$(XZ_ROOT)/src/common/tuklib_progname.c \
$(XZ_ROOT)/src/common/tuklib_exit.c \
$(XZ_ROOT)/src/common/tuklib_mbstr_width.c \
$(XZ_ROOT)/src/common/tuklib_mbstr_fw.c

LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := liblzma
LOCAL_MODULE     := xz
LOCAL_CFLAGS     := -pie -fPIE -O2 \
-DHAVE_CONFIG_H -DLOCALEDIR=\"/usr/local/share/locale\" \
-fvisibility=hidden -std=gnu99
LOCAL_C_INCLUDES := $(XZ_INCLUDES)
LOCAL_SRC_FILES  := $(XZ_FILES)

include $(BUILD_EXECUTABLE)
