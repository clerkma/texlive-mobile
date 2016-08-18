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

# for libfontconfig
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

FONTCONFIG_ROOT     := ../src/fontconfig-2.12.1
FONTCONFIG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2 \
$(LOCAL_PATH)/../src/fontconfig-2.12.1\
$(LOCAL_PATH)/../src/expat-2.2.0/lib
FONTCONFIG_FILES := \
$(FONTCONFIG_ROOT)/src/fcatomic.c \
$(FONTCONFIG_ROOT)/src/fcblanks.c \
$(FONTCONFIG_ROOT)/src/fccache.c \
$(FONTCONFIG_ROOT)/src/fccfg.c \
$(FONTCONFIG_ROOT)/src/fccharset.c \
$(FONTCONFIG_ROOT)/src/fccompat.c \
$(FONTCONFIG_ROOT)/src/fcdbg.c \
$(FONTCONFIG_ROOT)/src/fcdefault.c \
$(FONTCONFIG_ROOT)/src/fcdir.c \
$(FONTCONFIG_ROOT)/src/fcformat.c \
$(FONTCONFIG_ROOT)/src/fcfreetype.c \
$(FONTCONFIG_ROOT)/src/fcfs.c \
$(FONTCONFIG_ROOT)/src/fcinit.c \
$(FONTCONFIG_ROOT)/src/fclang.c \
$(FONTCONFIG_ROOT)/src/fclist.c \
$(FONTCONFIG_ROOT)/src/fcmatch.c \
$(FONTCONFIG_ROOT)/src/fcmatrix.c \
$(FONTCONFIG_ROOT)/src/fcname.c \
$(FONTCONFIG_ROOT)/src/fcobjs.c \
$(FONTCONFIG_ROOT)/src/fcpat.c \
$(FONTCONFIG_ROOT)/src/fcrange.c \
$(FONTCONFIG_ROOT)/src/fcserialize.c \
$(FONTCONFIG_ROOT)/src/fcstat.c \
$(FONTCONFIG_ROOT)/src/fcstr.c \
$(FONTCONFIG_ROOT)/src/fcweight.c \
$(FONTCONFIG_ROOT)/src/fcxml.c \
$(FONTCONFIG_ROOT)/src/ftglue.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libfontconfig
LOCAL_CFLAGS     := -O2 \
-DHAVE_CONFIG_H -DFC_CACHEDIR=\"/sdcard/texlive-portable/cache\"\
-DFONTCONFIG_PATH=\"/sdcard/texlive-portable/fontconfig\"
LOCAL_C_INCLUDES := $(FONTCONFIG_INCLUDES)
LOCAL_SRC_FILES  := $(FONTCONFIG_FILES)

include $(BUILD_STATIC_LIBRARY)
