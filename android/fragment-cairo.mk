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

# for cairo
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

CAIRO_ROOT     := ../src/texlive-upstream/libs/cairo
CAIRO_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/cairo\
$(LOCAL_PATH)/../src/texlive-upstream/libs/cairo/cairo-src/src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman/include
CAIRO_FILES    :=\
$(CAIRO_ROOT)/cairo-src/src/cairo-analysis-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-arc.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-array.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-atomic.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-base64-stream.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-base85-stream.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-bentley-ottmann.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-bentley-ottmann-rectangular.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-bentley-ottmann-rectilinear.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-botor-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-boxes.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-boxes-intersect.c \
$(CAIRO_ROOT)/cairo-src/src/cairo.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-cache.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip-boxes.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip-polygon.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip-region.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-color.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-composite-rectangles.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-contour.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-damage.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-debug.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-default-context.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-device.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-error.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-fallback-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-fixed.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-font-face.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-font-face-twin.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-font-face-twin-data.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-font-options.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-freelist.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-freed-pool.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-gstate.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-hash.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-hull.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-image-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-image-info.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-image-source.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-image-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-line.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-lzw.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-matrix.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-mask-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-mesh-pattern-rasterizer.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-mempool.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-misc.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-mono-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-mutex.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-no-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-observer.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-output-stream.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-paginated-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-bounds.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-fill.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-fixed.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-in-fill.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-stroke.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-stroke-boxes.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-stroke-polygon.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-stroke-traps.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-path-stroke-tristrip.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-pattern.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-pen.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-polygon.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-polygon-intersect.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-polygon-reduce.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-raster-source-pattern.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-recording-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-rectangle.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-rectangular-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-region.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-rtree.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-scaled-font.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-shape-mask-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-slope.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-spans.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-spans-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-spline.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-stroke-dash.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-stroke-style.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-clipper.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-fallback.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-observer.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-offset.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-snapshot.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-subsurface.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-surface-wrapper.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-time.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-tor-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-tor22-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-clip-tor-scan-converter.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-toy-font-face.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-traps.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-tristrip.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-traps-compositor.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-unicode.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-user-font.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-version.c \
$(CAIRO_ROOT)/cairo-src/src/cairo-wideint.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libcairo
LOCAL_CFLAGS     := \
-pie -fPIE \
-Wno-attributes -fvisibility=hidden \
-DHAVE_CONFIG_H -DCAIRO_NO_MUTEX -O2
LOCAL_C_INCLUDES := $(CAIRO_INCLUDES)
LOCAL_SRC_FILES  := $(CAIRO_FILES)

include $(BUILD_STATIC_LIBRARY)
