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
