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
LOCAL_CFLAGS     := -pie -fPIE -O2
LOCAL_C_INCLUDES := $(ZLIB_INCLUDES)
LOCAL_SRC_FILES  := $(ZLIB_FILES)

include $(BUILD_STATIC_LIBRARY)
