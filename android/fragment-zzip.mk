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

# for zziplib
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

ZZIPLIB_ROOT     := ../src/texlive-upstream/libs/zziplib
ZZIPLIB_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/ \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/zziplib-src \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include
ZZIPLIB_FILES := \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/dir.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/err.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/fetch.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/file.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/info.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/plugin.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/stat.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/write.c \
$(ZZIPLIB_ROOT)/zziplib-src/zzip/zip.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libzzip
LOCAL_CFLAGS     := -pie -fPIE -O2 -DHAVE_CONFIG_H -D_USE_MMAP
LOCAL_C_INCLUDES := $(ZZIPLIB_INCLUDES)
LOCAL_SRC_FILES  := $(ZZIPLIB_FILES)

include $(BUILD_STATIC_LIBRARY)
