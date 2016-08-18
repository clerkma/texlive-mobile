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

# for libpotrace
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

POTRACE_ROOT     := ../src/texlive-upstream/libs/potrace
POTRACE_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/potrace\
$(LOCAL_PATH)/../src/texlive-upstream/libs/potrace/potrace-src/src
POTRACE_FILES := \
$(POTRACE_ROOT)/potrace-src/src/curve.c \
$(POTRACE_ROOT)/potrace-src/src/decompose.c \
$(POTRACE_ROOT)/potrace-src/src/potracelib.c \
$(POTRACE_ROOT)/potrace-src/src/trace.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpotrace
LOCAL_CFLAGS     := -O2 -DHAVE_CONFIG_H
LOCAL_C_INCLUDES := $(POTRACE_INCLUDES)
LOCAL_SRC_FILES  := $(POTRACE_FILES)

include $(BUILD_STATIC_LIBRARY)
