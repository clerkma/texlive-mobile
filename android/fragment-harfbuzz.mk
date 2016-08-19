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

# for libharfbuzz
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

HARFBUZZ_ROOT     := ../src/texlive-upstream/libs/harfbuzz
HARFBUZZ_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/harfbuzz\
$(LOCAL_PATH)/../src/texlive-upstream/libs/harfbuzz/harfbuzz-src/src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/graphite2/include
HARFBUZZ_FILES := \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-blob.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-buffer-serialize.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-buffer.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-common.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-face.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-fallback-shape.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-font.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-tag.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-set.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-shape.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-shape-plan.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-shaper.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-unicode.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-warning.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-font.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-layout.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-map.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-arabic.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-default.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-hangul.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-hebrew.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-indic.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-indic-table.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-myanmar.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-thai.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-tibetan.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-use.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-complex-use-table.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-fallback.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-ot-shape-normalize.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-icu.cc \
$(HARFBUZZ_ROOT)/harfbuzz-src/src/hb-graphite2.cc
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libharfbuzz
LOCAL_CFLAGS     := \
-pie -fPIE \
-O2 -DHAVE_CONFIG_H -DHB_NO_MT -DHB_NO_UNICODE_FUNCS \
-DU_STATIC_IMPLEMENTATION -DGRAPHITE2_STATIC
LOCAL_C_INCLUDES := $(HARFBUZZ_INCLUDES)
LOCAL_SRC_FILES  := $(HARFBUZZ_FILES)

include $(BUILD_STATIC_LIBRARY)
