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

# for libpaper
include $(CLEAR_VARS)
LIBPAPER_ROOT    := ../src/texlive-upstream/libs/libpaper/libpaper-src
LIBPAPER_INCLUDES:= \
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper

LIBPAPER_FILES   := \
$(LIBPAPER_ROOT)/lib/dimen.c \
$(LIBPAPER_ROOT)/lib/paper.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpaper
LOCAL_CFLAGS     := -pie -fPIE -DHAVE_CONFIG_H -O2
LOCAL_C_INCLUDES := $(LIBPAPER_INCLUDES)
LOCAL_SRC_FILES  := $(LIBPAPER_FILES)

include $(BUILD_STATIC_LIBRARY)
