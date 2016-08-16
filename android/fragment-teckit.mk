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

# for teckit
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

TECKIT_ROOT     := ../src/texlive-upstream/libs/teckit
TECKIT_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/teckit/\
$(LOCAL_PATH)/../src/texlive-upstream/libs/teckit/TECkit-src/source/Public-headers
TECKIT_FILES := \
$(TECKIT_ROOT)/TECkit-src/source/Compiler.cpp \
$(TECKIT_ROOT)/TECkit-src/source/UnicodeNames.cpp
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libTECkit_Compiler
LOCAL_CFLAGS     := -fexceptions -DHAVE_CONFIG_H -O2
LOCAL_C_INCLUDES := $(TECKIT_INCLUDES)
LOCAL_SRC_FILES  := $(TECKIT_FILES)

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

TECKIT_ROOT     := ../src/texlive-upstream/libs/teckit
TECKIT_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/teckit/\
$(LOCAL_PATH)/../src/texlive-upstream/libs/teckit/TECkit-src/source/Public-headers
TECKIT_FILES := \
$(TECKIT_ROOT)/TECkit-src/source/Sample-tools/TECkit_Compile.cpp
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libTECkit_Compiler libz
LOCAL_MODULE     := teckit_compile
LOCAL_CFLAGS     := -fexceptions -DHAVE_CONFIG_H -O2
LOCAL_C_INCLUDES := $(TECKIT_INCLUDES)
LOCAL_SRC_FILES  := $(TECKIT_FILES)

include $(BUILD_EXECUTABLE)
