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

# for libgd
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LIBGD_ROOT     := ../src/texlive-upstream/libs/gd/libgd-src
LIBGD_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gd\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gd/libgd-src/src
LIBGD_FILES := \
$(LIBGD_ROOT)/src/gd.c \
$(LIBGD_ROOT)/src/gd_bmp.c \
$(LIBGD_ROOT)/src/gd_color.c \
$(LIBGD_ROOT)/src/gd_color_map.c \
$(LIBGD_ROOT)/src/gd_color_match.c \
$(LIBGD_ROOT)/src/gd_crop.c \
$(LIBGD_ROOT)/src/gd_filename.c \
$(LIBGD_ROOT)/src/gd_filter.c \
$(LIBGD_ROOT)/src/gd_gd.c \
$(LIBGD_ROOT)/src/gd_gd2.c \
$(LIBGD_ROOT)/src/gd_gif_in.c \
$(LIBGD_ROOT)/src/gd_gif_out.c \
$(LIBGD_ROOT)/src/gd_interpolation.c \
$(LIBGD_ROOT)/src/gd_io.c \
$(LIBGD_ROOT)/src/gd_io_dp.c \
$(LIBGD_ROOT)/src/gd_io_file.c \
$(LIBGD_ROOT)/src/gd_io_ss.c \
$(LIBGD_ROOT)/src/gd_jpeg.c \
$(LIBGD_ROOT)/src/gd_matrix.c \
$(LIBGD_ROOT)/src/gd_nnquant.c \
$(LIBGD_ROOT)/src/gd_png.c \
$(LIBGD_ROOT)/src/gd_rotate.c \
$(LIBGD_ROOT)/src/gd_security.c \
$(LIBGD_ROOT)/src/gd_ss.c \
$(LIBGD_ROOT)/src/gd_tga.c \
$(LIBGD_ROOT)/src/gd_tiff.c \
$(LIBGD_ROOT)/src/gd_topal.c \
$(LIBGD_ROOT)/src/gd_transform.c \
$(LIBGD_ROOT)/src/gd_version.c \
$(LIBGD_ROOT)/src/gd_wbmp.c \
$(LIBGD_ROOT)/src/gd_webp.c \
$(LIBGD_ROOT)/src/gd_xbm.c \
$(LIBGD_ROOT)/src/gdcache.c \
$(LIBGD_ROOT)/src/gdfontg.c \
$(LIBGD_ROOT)/src/gdfontl.c \
$(LIBGD_ROOT)/src/gdfontmb.c \
$(LIBGD_ROOT)/src/gdfonts.c \
$(LIBGD_ROOT)/src/gdfontt.c \
$(LIBGD_ROOT)/src/gdft.c \
$(LIBGD_ROOT)/src/gdfx.c \
$(LIBGD_ROOT)/src/gdhelpers.c \
$(LIBGD_ROOT)/src/gdkanji.c \
$(LIBGD_ROOT)/src/gdtables.c \
$(LIBGD_ROOT)/src/gdxpm.c \
$(LIBGD_ROOT)/src/wbmp.c \
$(LIBGD_ROOT)/src/webpimg.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libgd
LOCAL_CFLAGS     := -DHAVE_CONFIG_H -O2
LOCAL_C_INCLUDES := $(LIBGD_INCLUDES)
LOCAL_SRC_FILES  := $(LIBGD_FILES)

include $(BUILD_STATIC_LIBRARY)
