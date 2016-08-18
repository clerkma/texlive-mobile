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

# for libgraphite2
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

GRAPHITE2_ROOT     := ../src/texlive-upstream/libs/graphite2
GRAPHITE2_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/graphite2\
$(LOCAL_PATH)/../src/texlive-upstream/libs/graphite2/graphite2-src/src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/graphite2/graphite2-src/include
GRAPHITE2_FILES := \
$(GRAPHITE2_ROOT)/graphite2-src/src/CachedFace.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/CmapCache.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Code.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Collider.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Decompressor.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Face.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/FeatureMap.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Font.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/GlyphCache.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/GlyphFace.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Intervals.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/json.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Justifier.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/NameTable.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Pass.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Position.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Segment.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Silf.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Slot.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/Sparse.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/TtfUtil.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/UtfCodec.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_char_info.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_face.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_features.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_font.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_logging.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_segment.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/gr_slot.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/direct_machine.cpp \
$(GRAPHITE2_ROOT)/graphite2-src/src/FileFace.cpp
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libgraphite2
LOCAL_CFLAGS     := \
-O2 -DHAVE_CONFIG_H -DGRAPHITE2_STATIC\
-DGRAPHITE2_CUSTOM_HEADER='<config.h>'
LOCAL_C_INCLUDES := $(GRAPHITE2_INCLUDES)
LOCAL_SRC_FILES  := $(GRAPHITE2_FILES)

include $(BUILD_STATIC_LIBRARY)
