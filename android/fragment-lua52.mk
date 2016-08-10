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

LUA52_ROOT     := ../src/texlive-upstream/libs/lua52/lua52-src/src
LUA52_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52 \
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52/lua52-src/src
LUA52_FILES := \
$(LUA52_ROOT)/lapi.c \
$(LUA52_ROOT)/lauxlib.c \
$(LUA52_ROOT)/lbaselib.c \
$(LUA52_ROOT)/lbitlib.c \
$(LUA52_ROOT)/lcode.c \
$(LUA52_ROOT)/lcorolib.c \
$(LUA52_ROOT)/lctype.c \
$(LUA52_ROOT)/ldblib.c \
$(LUA52_ROOT)/ldebug.c \
$(LUA52_ROOT)/ldo.c \
$(LUA52_ROOT)/ldump.c \
$(LUA52_ROOT)/lfunc.c \
$(LUA52_ROOT)/lgc.c \
$(LUA52_ROOT)/linit.c \
$(LUA52_ROOT)/liolib.c \
$(LUA52_ROOT)/llex.c \
$(LUA52_ROOT)/lmathlib.c \
$(LUA52_ROOT)/lmem.c \
$(LUA52_ROOT)/loadlib.c \
$(LUA52_ROOT)/lobject.c \
$(LUA52_ROOT)/lopcodes.c \
$(LUA52_ROOT)/loslib.c \
$(LUA52_ROOT)/lparser.c \
$(LUA52_ROOT)/lstate.c \
$(LUA52_ROOT)/lstring.c \
$(LUA52_ROOT)/lstrlib.c \
$(LUA52_ROOT)/ltable.c \
$(LUA52_ROOT)/ltablib.c \
$(LUA52_ROOT)/ltm.c \
$(LUA52_ROOT)/lundump.c \
$(LUA52_ROOT)/lvm.c \
$(LUA52_ROOT)/lzio.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := liblua52
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6\
-DLUA_USE_POSIX -DLUA_USE_DLOPEN -DHAVE_UNISTD_H -O2
LOCAL_C_INCLUDES := $(LUA52_INCLUDES)
LOCAL_SRC_FILES  := $(LUA52_FILES)

include $(BUILD_STATIC_LIBRARY)
