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

# for pixman
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

PIXMAN_ROOT     := ../src/texlive-upstream/libs/pixman
PIXMAN_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman\
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman-src/pixman
PIXMAN_FILES := \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-access.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-access-accessors.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-bits-image.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-combine32.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-combine-float.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-conical-gradient.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-x86.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-mips.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-arm.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-ppc.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-edge.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-edge-accessors.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-fast-path.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-filter.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-glyph.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-general.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-gradient-walker.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-image.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-implementation.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-linear-gradient.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-matrix.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-noop.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-radial-gradient.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-region16.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-region32.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-solid-fill.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-timer.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-trap.c \
$(PIXMAN_ROOT)/pixman-src/pixman/pixman-utils.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpixman
LOCAL_CFLAGS     := -pie -fPIE -O2 -DHAVE_CONFIG_H
LOCAL_C_INCLUDES := $(PIXMAN_INCLUDES)
LOCAL_SRC_FILES  := $(PIXMAN_FILES)

include $(BUILD_STATIC_LIBRARY)
