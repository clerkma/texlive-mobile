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

# for libpng
include $(CLEAR_VARS)

LIBPNG_ROOT     := ../src/texlive-upstream/libs/libpng/libpng-src
LIBPNG_INCLUDES := $(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
LIBPNG_FILES := \
$(LIBPNG_ROOT)/pngerror.c \
$(LIBPNG_ROOT)/png.c \
$(LIBPNG_ROOT)/pngrio.c \
$(LIBPNG_ROOT)/pngset.c \
$(LIBPNG_ROOT)/pngwrite.c \
$(LIBPNG_ROOT)/pngget.c \
$(LIBPNG_ROOT)/pngpread.c \
$(LIBPNG_ROOT)/pngrtran.c \
$(LIBPNG_ROOT)/pngtrans.c \
$(LIBPNG_ROOT)/pngwtran.c \
$(LIBPNG_ROOT)/pngmem.c \
$(LIBPNG_ROOT)/pngread.c \
$(LIBPNG_ROOT)/pngrutil.c \
$(LIBPNG_ROOT)/pngwio.c \
$(LIBPNG_ROOT)/pngwutil.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpng
LOCAL_CFLAGS     := -pie -fPIE -DPNG_ARM_NEON_OPT=0 -O2
LOCAL_C_INCLUDES := $(LIBPNG_INCLUDES)
LOCAL_SRC_FILES  := $(LIBPNG_FILES)

include $(BUILD_STATIC_LIBRARY)
