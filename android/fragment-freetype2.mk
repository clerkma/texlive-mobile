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

#for freetype2
include $(CLEAR_VARS)

LIBFREETYPE_ROOT    := ../src/texlive-upstream/libs/freetype2/freetype-src
LIBFREETYPE_INCLUDES:= \
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype-src/include
LIBFREETYPE_FILES   := \
$(LIBFREETYPE_ROOT)/src/base/ftbase.c \
$(LIBFREETYPE_ROOT)/src/base/ftbbox.c \
$(LIBFREETYPE_ROOT)/src/base/ftbdf.c \
$(LIBFREETYPE_ROOT)/src/base/ftcid.c \
$(LIBFREETYPE_ROOT)/src/base/ftmm.c \
$(LIBFREETYPE_ROOT)/src/base/ftbitmap.c \
$(LIBFREETYPE_ROOT)/src/base/ftfntfmt.c \
$(LIBFREETYPE_ROOT)/src/base/ftgasp.c \
$(LIBFREETYPE_ROOT)/src/base/ftglyph.c \
$(LIBFREETYPE_ROOT)/src/base/ftinit.c \
$(LIBFREETYPE_ROOT)/src/base/ftstroke.c \
$(LIBFREETYPE_ROOT)/src/base/ftsynth.c \
$(LIBFREETYPE_ROOT)/src/base/ftsystem.c \
$(LIBFREETYPE_ROOT)/src/base/fttype1.c \
$(LIBFREETYPE_ROOT)/src/cff/cff.c \
$(LIBFREETYPE_ROOT)/src/cid/type1cid.c \
$(LIBFREETYPE_ROOT)/src/psaux/psaux.c \
$(LIBFREETYPE_ROOT)/src/pshinter/pshinter.c \
$(LIBFREETYPE_ROOT)/src/psnames/psnames.c \
$(LIBFREETYPE_ROOT)/src/raster/raster.c \
$(LIBFREETYPE_ROOT)/src/smooth/smooth.c \
$(LIBFREETYPE_ROOT)/src/autofit/autofit.c \
$(LIBFREETYPE_ROOT)/src/sfnt/sfnt.c \
$(LIBFREETYPE_ROOT)/src/gzip/ftgzip.c \
$(LIBFREETYPE_ROOT)/src/bdf/bdf.c \
$(LIBFREETYPE_ROOT)/src/pfr/pfr.c \
$(LIBFREETYPE_ROOT)/src/pcf/pcf.c \
$(LIBFREETYPE_ROOT)/src/lzw/ftlzw.c \
$(LIBFREETYPE_ROOT)/src/winfonts/winfnt.c \
$(LIBFREETYPE_ROOT)/src/type42/type42.c \
$(LIBFREETYPE_ROOT)/src/truetype/truetype.c \
$(LIBFREETYPE_ROOT)/src/type1/type1.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libfreetype
LOCAL_CFLAGS     := \
-pie -fPIE \
-DHAVE_CONFIG_H  \
-DFT2_BUILD_LIBRARY -O2
LOCAL_C_INCLUDES := $(LIBFREETYPE_INCLUDES)
LOCAL_SRC_FILES  := $(LIBFREETYPE_FILES)

include $(BUILD_STATIC_LIBRARY)
