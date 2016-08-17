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

# for web2c
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LIB_ROOT     := ../src/texlive-upstream/texk/web2c/lib
LIB_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c

LIB_FILES := \
$(LIB_ROOT)/basechsuffix.c \
$(LIB_ROOT)/chartostring.c \
$(LIB_ROOT)/coredump.c \
$(LIB_ROOT)/eofeoln.c \
$(LIB_ROOT)/fprintreal.c \
$(LIB_ROOT)/inputint.c \
$(LIB_ROOT)/input2int.c \
$(LIB_ROOT)/main.c \
$(LIB_ROOT)/openclose.c \
$(LIB_ROOT)/printversion.c \
$(LIB_ROOT)/setupvar.c \
$(LIB_ROOT)/uexit.c \
$(LIB_ROOT)/usage.c \
$(LIB_ROOT)/version.c \
$(LIB_ROOT)/zround.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libn
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(LIB_INCLUDES)
LOCAL_SRC_FILES  := $(LIB_FILES)

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LIBP_ROOT     := ../src/texlive-upstream/texk/web2c/lib
LIBP_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc

LIBP_FILES := \
$(LIBP_ROOT)/openclose.c \
$(LIBP_ROOT)/printversion.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libp
LOCAL_CFLAGS     := -DPTEX -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(LIBP_INCLUDES)
LOCAL_SRC_FILES  := $(LIBP_FILES)

include $(BUILD_STATIC_LIBRARY)

include fragment-kpathsea.mk
include fragment-ptexenc.mk
include fragment-libpaper.mk
include fragment-freetype2.mk
include fragment-zlib.mk
include fragment-zzip.mk
include fragment-gd.mk
include fragment-libpng.mk
include fragment-expat.mk
include fragment-xpdf.mk
include fragment-teckit.mk
include fragment-pixman.mk
include fragment-cairo.mk
include fragment-gmp.mk
include fragment-mpfr.mk
include fragment-lua52.mk
include fragment-poppler.mk

#for tangle
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/tangle.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := tangle
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ctangle
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/cweb.c\
$(PROG_ROOT)/ctangle.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := ctangle
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for bibtex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/bibtex.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := bibtex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvicopy
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/dvicopy.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := dvicopy
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvitype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/dvitype.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := dvitype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for gftodvi
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/gftodvi.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := gftodvi
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for gftopk
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/gftopk.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := gftopk
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for gftype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/gftype.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := gftype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for mft
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/mft.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := mft
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for patgen
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/patgen.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := patgen
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pktogf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pktogf.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := pktogf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pktype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pktype.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := pktype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pltotf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pltotf.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := pltotf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pooltype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pooltype.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := pooltype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tftopl
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/tftopl.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := tftopl
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for vftovp
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/vftovp.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := vftovp
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for vptovf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/vptovf.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := vptovf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for weave
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/weave.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := weave
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ctie
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ctie.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := ctie
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for cweave
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/cweb.c\
$(PROG_ROOT)/cweave.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := cweave
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tie
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/tie.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := tie
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/texextra.c \
$(PROG_ROOT)/texini.c \
$(PROG_ROOT)/tex0.c \
$(PROG_ROOT)/tex-pool.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := tex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ptex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ptexdir/ptexextra.c\
$(PROG_ROOT)/synctexdir/synctex.c\
$(PROG_ROOT)/ptexini.c\
$(PROG_ROOT)/ptex0.c\
$(PROG_ROOT)/ptex-pool.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := ptex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-D__SyncTeX__ -DSYNCTEX_ENGINE_H=\"synctex-ptex.h\"\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pbibtex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pbibtex.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea
LOCAL_MODULE     := pbibtex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pdvitype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/pdvitype.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea
LOCAL_MODULE     := pdvitype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ppltotf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ppltotf.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea
LOCAL_MODULE     := ppltotf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ptftopl
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ptftopl.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea
LOCAL_MODULE     := ptftopl
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for eptex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5
PROG_FILES :=\
$(PROG_ROOT)/eptexdir/eptexextra.c\
$(PROG_ROOT)/synctexdir/synctex.c\
$(PROG_ROOT)/eptexini.c\
$(PROG_ROOT)/eptex0.c\
$(PROG_ROOT)/eptex-pool.c\
$(PROG_ROOT)/libmd5/md5.c\
$(PROG_ROOT)/ptexdir/kanji.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := eptex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-D__SyncTeX__ -DSYNCTEX_ENGINE_H=\"synctex-eptex.h\"\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for uptex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/uptexdir/uptexextra.c\
$(PROG_ROOT)/synctexdir/synctex.c\
$(PROG_ROOT)/uptexini.c\
$(PROG_ROOT)/uptex0.c\
$(PROG_ROOT)/uptex-pool.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := uptex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-D__SyncTeX__ -DSYNCTEX_ENGINE_H=\"synctex-uptex.h\"\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for upbibtex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/upbibtex.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := upbibtex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for updvitype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/updvitype.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := updvitype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for uppltotf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/uppltotf.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := uppltotf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for uptftopl
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/uptftopl.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := uptftopl
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for euptex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5
PROG_FILES :=\
$(PROG_ROOT)/euptexdir/euptexextra.c\
$(PROG_ROOT)/synctexdir/synctex.c\
$(PROG_ROOT)/euptexini.c\
$(PROG_ROOT)/euptex0.c\
$(PROG_ROOT)/euptex-pool.c\
$(PROG_ROOT)/libmd5/md5.c\
$(PROG_ROOT)/uptexdir/kanji.c\
$(PROG_ROOT)/uptexdir/kanji_dump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libp libptexenc libn libkpathsea libz
LOCAL_MODULE     := euptex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-D__SyncTeX__ -DSYNCTEX_ENGINE_H=\"synctex-euptex.h\"\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pdftex/core
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/pdftexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/goo\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf
PROG_FILES :=\
$(PROG_ROOT)/pdftexdir/avl.c \
$(PROG_ROOT)/pdftexdir/avlstuff.c \
$(PROG_ROOT)/pdftexdir/epdf.c \
$(PROG_ROOT)/pdftexdir/mapfile.c \
$(PROG_ROOT)/pdftexdir/pdftoepdf.cc \
$(PROG_ROOT)/pdftexdir/pkin.c \
$(PROG_ROOT)/pdftexdir/subfont.c \
$(PROG_ROOT)/pdftexdir/tounicode.c \
$(PROG_ROOT)/pdftexdir/utils.c \
$(PROG_ROOT)/pdftexdir/vfpacket.c \
$(PROG_ROOT)/pdftexdir/writeenc.c \
$(PROG_ROOT)/pdftexdir/writefont.c \
$(PROG_ROOT)/pdftexdir/writeimg.c \
$(PROG_ROOT)/pdftexdir/writejbig2.c \
$(PROG_ROOT)/pdftexdir/writejpg.c \
$(PROG_ROOT)/pdftexdir/writepng.c \
$(PROG_ROOT)/pdftexdir/writet1.c \
$(PROG_ROOT)/pdftexdir/writet3.c \
$(PROG_ROOT)/pdftexdir/writettf.c \
$(PROG_ROOT)/pdftexdir/writezip.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libcorepdftex
LOCAL_CFLAGS     :=\
-DPDF_PARSER_ONLY \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for pdftex/pdftex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/pdftexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/synctexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf
PROG_FILES :=\
$(PROG_ROOT)/pdftexdir/pdftexextra.c\
$(PROG_ROOT)/synctexdir/synctex.c\
$(PROG_ROOT)/pdftexini.c\
$(PROG_ROOT)/pdftex0.c\
$(PROG_ROOT)/pdftex-pool.c\
$(PROG_ROOT)/libmd5/md5.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libcorepdftex libpng libxpdf libn libkpathsea libz
LOCAL_MODULE     := pdftex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DPDF_PARSER_ONLY -D__SyncTeX__ -DSYNCTEX_ENGINE_H=\"synctex-pdftex.h\"\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pdftex/ttf2afm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/pdftexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/synctexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf
PROG_FILES :=\
$(PROG_ROOT)/pdftexdir/ttf2afm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libcorepdftex libn libkpathsea libz
LOCAL_MODULE     := ttf2afm
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pdftex/pdftosrc
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/pdftexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/synctexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf
PROG_FILES :=\
$(PROG_ROOT)/pdftexdir/pdftosrc.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libcorepdftex libxpdf libn libkpathsea libz
LOCAL_MODULE     := pdftosrc
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for luatex/unilib
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/unilib
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/unilib/ArabicForms.c \
$(PROG_ROOT)/luatexdir/unilib/alphabet.c \
$(PROG_ROOT)/luatexdir/unilib/char.c \
$(PROG_ROOT)/luatexdir/unilib/cjk.c \
$(PROG_ROOT)/luatexdir/unilib/gwwiconv.c \
$(PROG_ROOT)/luatexdir/unilib/ucharmap.c \
$(PROG_ROOT)/luatexdir/unilib/unialt.c \
$(PROG_ROOT)/luatexdir/unilib/usprintf.c \
$(PROG_ROOT)/luatexdir/unilib/ustring.c \
$(PROG_ROOT)/luatexdir/unilib/utype.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libluatexuni
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H  \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for luatex/fontforge
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/unilib\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge/inc
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/autohint.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/clipnoui.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/cvundoes.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/dumppfa.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/encoding.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/featurefile.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/fontviewbase.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/fvcomposit.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/fvfonts.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/lookups.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/macbinary.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/macenc.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/mathconstants.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/memory.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/mm.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/namelist.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/noprefs.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/nouiutil.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/parsepfa.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/parsettf.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/parsettfatt.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/psread.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/pua.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/python.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/sfd1.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinechar.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinefill.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinefont.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splineorder2.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splineoverlap.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinerefigure.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinesave.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinesaveafm.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splinestroke.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splineutil.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/splineutil2.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/start.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/stemdb.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/tottf.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/tottfgpos.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/fontforge/ttfspecial.c \
$(PROG_ROOT)/luatexdir/luafontloader/fontforge/gutils/fsys.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libluatexff
LOCAL_CFLAGS     :=\
-DLUA_FF_LIB=1 -D_NO_PYTHON=1 -DX_DISPLAY_MISSING=1 -DUSE_OUR_MEMORY=1 \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for luatex/socket
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luasocket\
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52/include
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/luasocket/src/auxiliar.c \
$(PROG_ROOT)/luatexdir/luasocket/src/buffer.c \
$(PROG_ROOT)/luatexdir/luasocket/src/except.c \
$(PROG_ROOT)/luatexdir/luasocket/src/inet.c \
$(PROG_ROOT)/luatexdir/luasocket/src/io.c \
$(PROG_ROOT)/luatexdir/luasocket/src/lua_preload.c \
$(PROG_ROOT)/luatexdir/luasocket/src/luasocket.c \
$(PROG_ROOT)/luatexdir/luasocket/src/mime.c \
$(PROG_ROOT)/luatexdir/luasocket/src/options.c \
$(PROG_ROOT)/luatexdir/luasocket/src/select.c \
$(PROG_ROOT)/luatexdir/luasocket/src/serial.c \
$(PROG_ROOT)/luatexdir/luasocket/src/socket.c \
$(PROG_ROOT)/luatexdir/luasocket/src/tcp.c \
$(PROG_ROOT)/luatexdir/luasocket/src/timeout.c \
$(PROG_ROOT)/luatexdir/luasocket/src/udp.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libluatexsocket
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H -DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 \
-DLUA_USE_POSIX -DLUA_USE_DLOPEN\
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for libmplib
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/mplibdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/mpfr/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/cairo/cairo\
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/tfmin.c \
$(PROG_ROOT)/mp.c \
$(PROG_ROOT)/mpmath.c \
$(PROG_ROOT)/mpmathbinary.c \
$(PROG_ROOT)/mpmathdecimal.c \
$(PROG_ROOT)/mpmathdouble.c \
$(PROG_ROOT)/mpstrings.c \
$(PROG_ROOT)/pngout.c \
$(PROG_ROOT)/psout.c \
$(PROG_ROOT)/svgout.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libmplib
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H -DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 \
-DLUA_USE_POSIX -DLUA_USE_DLOPEN\
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for libmputil
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/mplibdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/mpfr/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/cairo/cairo\
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/mplibdir/avl.c \
$(PROG_ROOT)/mplibdir/decNumber.c \
$(PROG_ROOT)/mplibdir/decContext.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libmputil
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H -DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 \
-DLUA_USE_POSIX -DLUA_USE_DLOPEN\
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for mpost
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/mplibdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/mpfr/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/cairo/cairo\
$(LOCAL_PATH)/../src/texlive-upstream/libs/pixman/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/mpost.c \
$(PROG_ROOT)/mpxout.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := \
libmplib libmputil libmpfr libgmp libcairo libpixman\
libpng libz libkpathsea
LOCAL_MODULE     := mpost
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for luatex/misc
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luasocket\
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/luafilesystem/src/lfs.c \
$(PROG_ROOT)/luatexdir/luamd5/md5.c \
$(PROG_ROOT)/luatexdir/luamd5/md5lib.c \
$(PROG_ROOT)/luatexdir/luamd5/md5_lua.c \
$(PROG_ROOT)/luatexdir/luapeg/lpeg.c \
$(PROG_ROOT)/luatexdir/luaprofiler/clocks.c \
$(PROG_ROOT)/luatexdir/luaprofiler/core_profiler.c \
$(PROG_ROOT)/luatexdir/luaprofiler/function_meter.c \
$(PROG_ROOT)/luatexdir/luaprofiler/stack.c \
$(PROG_ROOT)/luatexdir/luaprofiler/lua50_profiler.c \
$(PROG_ROOT)/luatexdir/luazip/src/luazip.c \
$(PROG_ROOT)/luatexdir/luazlib/lgzip.c \
$(PROG_ROOT)/luatexdir/luazlib/lzlib.c \
$(PROG_ROOT)/luatexdir/slnunicode/slnunico.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libluatexmisc
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H -DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 \
-DLUA_USE_POSIX -DLUA_USE_DLOPEN\
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for luatex/luatex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/unilib\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge/inc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge/fontforge\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luasocket\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/mplibdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/synctexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/lua/lstrlibext.c \
$(PROG_ROOT)/luastuff.c \
$(PROG_ROOT)/texluac.c \
$(PROG_ROOT)/luatexdir/luafontloader/src/ffdummies.c\
$(PROG_ROOT)/luatexdir/luafontloader/src/luafflib.c \
$(PROG_ROOT)/luatexdir/lua/lcallbacklib.c \
$(PROG_ROOT)/luatexdir/lua/lfontlib.c \
$(PROG_ROOT)/luatexdir/lua/limglib.c \
$(PROG_ROOT)/luatexdir/lua/lpdfscannerlib.cc \
$(PROG_ROOT)/luatexdir/lua/lepdflib.cc \
$(PROG_ROOT)/luatexdir/lua/lkpselib.c \
$(PROG_ROOT)/luatexdir/lua/llanglib.c \
$(PROG_ROOT)/luatexdir/lua/llualib.c \
$(PROG_ROOT)/luatexdir/lua/llfslibext.c \
$(PROG_ROOT)/luatexdir/lua/lnodelib.c \
$(PROG_ROOT)/luatexdir/lua/liolibext.c \
$(PROG_ROOT)/luatexdir/lua/loslibext.c \
$(PROG_ROOT)/luatexdir/lua/lpdflib.c \
$(PROG_ROOT)/luatexdir/lua/lstatslib.c \
$(PROG_ROOT)/luatexdir/lua/ltexiolib.c \
$(PROG_ROOT)/luatexdir/lua/ltexlib.c \
$(PROG_ROOT)/luatexdir/lua/lnewtokenlib.c \
$(PROG_ROOT)/luatexdir/utils/avl.c \
$(PROG_ROOT)/synctexdir/synctex.c \
$(PROG_ROOT)/dvigen.c \
$(PROG_ROOT)/dofont.c \
$(PROG_ROOT)/luafont.c \
$(PROG_ROOT)/mapfile.c \
$(PROG_ROOT)/pkin.c \
$(PROG_ROOT)/sfnt.c \
$(PROG_ROOT)/subfont.c \
$(PROG_ROOT)/texfont.c \
$(PROG_ROOT)/tfmofm.c \
$(PROG_ROOT)/tounicode.c \
$(PROG_ROOT)/tt_glyf.c \
$(PROG_ROOT)/tt_table.c \
$(PROG_ROOT)/vfovf.c \
$(PROG_ROOT)/vfpacket.c \
$(PROG_ROOT)/writecff.c \
$(PROG_ROOT)/writeenc.c \
$(PROG_ROOT)/writefont.c \
$(PROG_ROOT)/writet1.c \
$(PROG_ROOT)/writet3.c \
$(PROG_ROOT)/writettf.c \
$(PROG_ROOT)/writetype0.c \
$(PROG_ROOT)/writetype2.c \
$(PROG_ROOT)/writeimg.c \
$(PROG_ROOT)/writejbig2.c \
$(PROG_ROOT)/writejpg.c \
$(PROG_ROOT)/writejp2.c \
$(PROG_ROOT)/writepng.c \
$(PROG_ROOT)/pdftoepdf.cc \
$(PROG_ROOT)/texlang.c \
$(PROG_ROOT)/hyphen.c \
$(PROG_ROOT)/hnjalloc.c \
$(PROG_ROOT)/luainit.c \
$(PROG_ROOT)/luanode.c \
$(PROG_ROOT)/luatoken.c \
$(PROG_ROOT)/pdfpagetree.c \
$(PROG_ROOT)/pdfaction.c \
$(PROG_ROOT)/pdfannot.c \
$(PROG_ROOT)/pdfcolorstack.c \
$(PROG_ROOT)/pdfdest.c \
$(PROG_ROOT)/pdffont.c \
$(PROG_ROOT)/pdfgen.c \
$(PROG_ROOT)/pdfglyph.c \
$(PROG_ROOT)/pdfimage.c \
$(PROG_ROOT)/pdflink.c \
$(PROG_ROOT)/pdflistout.c \
$(PROG_ROOT)/pdfliteral.c \
$(PROG_ROOT)/pdfobj.c \
$(PROG_ROOT)/pdfoutline.c \
$(PROG_ROOT)/pdfpage.c \
$(PROG_ROOT)/pdfrule.c \
$(PROG_ROOT)/pdfsaverestore.c \
$(PROG_ROOT)/pdfsetmatrix.c \
$(PROG_ROOT)/pdfshipout.c \
$(PROG_ROOT)/pdftables.c \
$(PROG_ROOT)/pdfthread.c \
$(PROG_ROOT)/pdfxform.c \
$(PROG_ROOT)/align.c \
$(PROG_ROOT)/arithmetic.c \
$(PROG_ROOT)/buildpage.c \
$(PROG_ROOT)/commands.c \
$(PROG_ROOT)/conditional.c \
$(PROG_ROOT)/directions.c \
$(PROG_ROOT)/dumpdata.c \
$(PROG_ROOT)/equivalents.c \
$(PROG_ROOT)/errors.c \
$(PROG_ROOT)/expand.c \
$(PROG_ROOT)/extensions.c \
$(PROG_ROOT)/filename.c \
$(PROG_ROOT)/inputstack.c \
$(PROG_ROOT)/linebreak.c \
$(PROG_ROOT)/mainbody.c \
$(PROG_ROOT)/maincontrol.c \
$(PROG_ROOT)/mathcodes.c \
$(PROG_ROOT)/memoryword.c \
$(PROG_ROOT)/mlist.c \
$(PROG_ROOT)/nesting.c \
$(PROG_ROOT)/packaging.c \
$(PROG_ROOT)/postlinebreak.c \
$(PROG_ROOT)/primitive.c \
$(PROG_ROOT)/printing.c \
$(PROG_ROOT)/scanning.c \
$(PROG_ROOT)/stringpool.c \
$(PROG_ROOT)/texdeffont.c \
$(PROG_ROOT)/texfileio.c \
$(PROG_ROOT)/texmath.c \
$(PROG_ROOT)/texnodes.c \
$(PROG_ROOT)/textcodes.c \
$(PROG_ROOT)/textoken.c \
$(PROG_ROOT)/avlstuff.c \
$(PROG_ROOT)/managed-sa.c \
$(PROG_ROOT)/utils.c \
$(PROG_ROOT)/unistring.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libcoreluatex
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-DpdfTeX\
-DPDF_PARSER_ONLY -D__SyncTeX__ -DSYNCTEX_ENGINE_H='<synctex-luatex.h>'\
-DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 -DLUA_USE_POSIX -DLUA_USE_DLOPEN\
-DLUA_FF_LIB=1 \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#libpixman libcairo libgmp libmpfr libpoppler libzzip
#for luatex/unilib
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/unilib\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge/inc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luafontloader/fontforge/fontforge\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/luatexdir/luasocket\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/mplibdir\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/synctexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/lua52/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zziplib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/luatexdir/luatex.c \
$(PROG_ROOT)/mplibdir/lmplib.c \
$(PROG_ROOT)/libmd5/md5.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := \
libmplib libmputil libcoreluatex libluatexff \
libluatexmisc libluatexsocket libmpfr libgmp\
liblua52 libcairo libpixman libzzip libpng\
libz libpoppler libn libkpathsea libluatexuni
LOCAL_MODULE     := luatex
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H \
-DLUA_COMPAT_MODULE -DLUAI_HASHLIMIT=6 \
-DLUA_USE_POSIX -DLUA_USE_DLOPEN \
-DpdfTeX -Dextra_version_info=`date +-%Y%m%d%H` \
-DSYNCTEX_ENGINE_H='<synctex-luatex.h>' \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for xetex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES :=\
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/w2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/libmd5\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/xetexdir\
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2 \
$(LOCAL_PATH)/../src/texlive-upstream/libs/teckit/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/harfbuzz/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/graphite2/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include
PROG_FILES :=\
$(PROG_ROOT)/xetexdir/XeTeXFontInst.cpp \
$(PROG_ROOT)/xetexdir/XeTeXFontMgr.cpp \
$(PROG_ROOT)/xetexdir/XeTeXLayoutInterface.cpp \
$(PROG_ROOT)/xetexdir/XeTeXOTMath.cpp \
$(PROG_ROOT)/xetexdir/XeTeX_ext.c \
$(PROG_ROOT)/xetexdir/XeTeX_pic.c \
$(PROG_ROOT)/xetexdir/trans.c \
$(PROG_ROOT)/xetexdir/hz.cpp \
$(PROG_ROOT)/xetexdir/pdfimage.cpp \
$(PROG_ROOT)/xetexdir/image/bmpimage.c \
$(PROG_ROOT)/xetexdir/image/jpegimage.c \
$(PROG_ROOT)/xetexdir/image/mfileio.c \
$(PROG_ROOT)/xetexdir/image/numbers.c \
$(PROG_ROOT)/xetexdir/image/pngimage.c \
$(PROG_ROOT)/xetexdir/XeTeXFontMgr_FC.cpp \
$(PROG_ROOT)/xetexdir/xetexextra.c \
$(PROG_ROOT)/synctexdir/synctex.c \
$(PROG_ROOT)/xetexini.c \
$(PROG_ROOT)/xete0.c \
$(PROG_ROOT)/xetex-pool.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := xetex
LOCAL_CFLAGS     :=\
-DHAVE_CONFIG_H -DGRAPHITE2_STATIC \
-Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for odvitype
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/odvitype.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := odvitype
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ofm2opl
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ofm2opl.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := wofm2opl
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for opl2ofm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/opl2ofm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := wopl2ofm
LOCAL_LDLIBS     := -s -lm
LOCAL_DISABLE_FATAL_LINKER_WARNINGS := true
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ovf2ovp
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ovf2ovp.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := wovf2ovp
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ovp2ovf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c
PROG_FILES :=\
$(PROG_ROOT)/ovp2ovf.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := wovp2ovf
LOCAL_LDLIBS     := -s -lm
LOCAL_DISABLE_FATAL_LINKER_WARNINGS := true
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for aleph
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/web2c
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c\
$(LOCAL_PATH)/../src/texlive-upstream/texk/web2c/alephdir
PROG_FILES :=\
$(PROG_ROOT)/alephdir/aleph.c\
$(PROG_ROOT)/alephdir/alephbis.c\
$(PROG_ROOT)/alephdir/alephextra.c\
$(PROG_ROOT)/alephini.c\
$(PROG_ROOT)/aleph0.c\
$(PROG_ROOT)/aleph-pool.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libn libkpathsea
LOCAL_MODULE     := aleph
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for afm2pl
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/afm2pl
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/afm2pl.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := afm2pl
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := -Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for bibtex8
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/bibtex-x
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/bibtex-1.c \
$(PROG_ROOT)/bibtex-2.c \
$(PROG_ROOT)/bibtex-3.c \
$(PROG_ROOT)/bibtex-4.c \
$(PROG_ROOT)/bibtex.c \
$(PROG_ROOT)/utils.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := bibtex8
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DUNIX -DKPATHSEA -DSUPPORT_8BIT\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for chktex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/chktex/
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/chktex
PROG_FILES :=\
$(PROG_ROOT)/chktex-src/ChkTeX.c \
$(PROG_ROOT)/chktex-src/FindErrs.c \
$(PROG_ROOT)/chktex-src/OpSys.c \
$(PROG_ROOT)/chktex-src/Resource.c \
$(PROG_ROOT)/chktex-src/Utility.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := chktex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for detex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/detex
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/detex
PROG_FILES :=\
$(PROG_ROOT)/detex-src/detex.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := detex
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DNO_MALLOC_DECL -DKPATHSEA -Dlint\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dtl/dt2dv
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dtl
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/dt2dv.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := dt2dv
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dtl/dv2dt
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dtl
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/dv2dt.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := dv2dt
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvi2tty/disdvi
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvi2tty
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvi2tty
PROG_FILES :=\
$(PROG_ROOT)/dvi2tty-src/disdvi.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := disdvi
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvi2tty/dvi2tty
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvi2tty
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvi2tty
PROG_FILES :=\
$(PROG_ROOT)/dvi2tty-src/dvi2tty.c \
$(PROG_ROOT)/dvi2tty-src/dvistuff.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libptexenc
LOCAL_MODULE     := dvi2tty
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvidvi
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvidvi
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvidvi
PROG_FILES :=\
$(PROG_ROOT)/dvidvi.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := dvidvi
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DNO_DEBUG -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dviljk/libdviljk
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dviljk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dviljk
PROG_FILES :=\
$(PROG_ROOT)/tfm.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libdviljk
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for dvilj/dvilj
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dviljk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dviljk
PROG_FILES :=\
$(PROG_ROOT)/dvi2xx.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libdviljk
LOCAL_MODULE     := dvilj
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DLJ -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvilj/dvilj2p
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dviljk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dviljk
PROG_FILES :=\
$(PROG_ROOT)/dvi2xx.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libdviljk
LOCAL_MODULE     := dvilj2p
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DLJ2P -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvilj/dvilj4
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dviljk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dviljk
PROG_FILES :=\
$(PROG_ROOT)/dvi2xx.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libdviljk
LOCAL_MODULE     := dvilj4
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DLJ4 -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvilj/dvilj4l
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dviljk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dviljk
PROG_FILES :=\
$(PROG_ROOT)/dvi2xx.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libdviljk
LOCAL_MODULE     := dvilj4l
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DLJ4 -DLJ4L -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvipng
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvipng
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipng\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipng/dvipng-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gd/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include
PROG_FILES :=\
$(PROG_ROOT)/dvipng-src/color.c \
$(PROG_ROOT)/dvipng-src/draw.c \
$(PROG_ROOT)/dvipng-src/dvi.c \
$(PROG_ROOT)/dvipng-src/dvipng.c \
$(PROG_ROOT)/dvipng-src/font.c \
$(PROG_ROOT)/dvipng-src/ft.c \
$(PROG_ROOT)/dvipng-src/misc.c \
$(PROG_ROOT)/dvipng-src/papersiz.c \
$(PROG_ROOT)/dvipng-src/pk.c \
$(PROG_ROOT)/dvipng-src/ppagelist.c \
$(PROG_ROOT)/dvipng-src/set.c \
$(PROG_ROOT)/dvipng-src/special.c \
$(PROG_ROOT)/dvipng-src/vf.c \
$(PROG_ROOT)/dvipng-src/enc.c \
$(PROG_ROOT)/dvipng-src/fontmap.c \
$(PROG_ROOT)/dvipng-src/sfd.c \
$(PROG_ROOT)/dvipng-src/tfm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libgd libfreetype libpng libz
LOCAL_MODULE     := dvipng
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DTEXLIVE\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvipos
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvipos
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipos
PROG_FILES :=\
$(PROG_ROOT)/dvicore.c \
$(PROG_ROOT)/dvipos.c \
$(PROG_ROOT)/tfm.c \
$(PROG_ROOT)/utils.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := dvipos
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DSHIFTLOWCHARS -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

# for DVIPDFMX
include $(CLEAR_VARS)

DVIPDFMX_ROOT     := ../src/texlive-upstream/texk/dvipdfm-x
DVIPDFMX_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk/ \
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipdfm-x \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpng/include \
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include

DVIPDFMX_FILES := \
$(DVIPDFMX_ROOT)/agl.c \
$(DVIPDFMX_ROOT)/bmpimage.c \
$(DVIPDFMX_ROOT)/cff.c \
$(DVIPDFMX_ROOT)/cff_dict.c \
$(DVIPDFMX_ROOT)/cid.c \
$(DVIPDFMX_ROOT)/cidtype0.c \
$(DVIPDFMX_ROOT)/cidtype2.c \
$(DVIPDFMX_ROOT)/cmap.c \
$(DVIPDFMX_ROOT)/cmap_read.c \
$(DVIPDFMX_ROOT)/cmap_write.c \
$(DVIPDFMX_ROOT)/cs_type2.c \
$(DVIPDFMX_ROOT)/dpxconf.c \
$(DVIPDFMX_ROOT)/dpxcrypt.c \
$(DVIPDFMX_ROOT)/dpxfile.c \
$(DVIPDFMX_ROOT)/dpxutil.c \
$(DVIPDFMX_ROOT)/dvi.c \
$(DVIPDFMX_ROOT)/dvipdfmx.c \
$(DVIPDFMX_ROOT)/epdf.c \
$(DVIPDFMX_ROOT)/error.c \
$(DVIPDFMX_ROOT)/fontmap.c \
$(DVIPDFMX_ROOT)/jp2image.c \
$(DVIPDFMX_ROOT)/jpegimage.c \
$(DVIPDFMX_ROOT)/mem.c \
$(DVIPDFMX_ROOT)/mfileio.c \
$(DVIPDFMX_ROOT)/mpost.c \
$(DVIPDFMX_ROOT)/numbers.c \
$(DVIPDFMX_ROOT)/otl_conf.c \
$(DVIPDFMX_ROOT)/otl_opt.c \
$(DVIPDFMX_ROOT)/pdfcolor.c \
$(DVIPDFMX_ROOT)/pdfdev.c \
$(DVIPDFMX_ROOT)/pdfdoc.c \
$(DVIPDFMX_ROOT)/pdfdraw.c \
$(DVIPDFMX_ROOT)/pdfencrypt.c \
$(DVIPDFMX_ROOT)/pdfencoding.c \
$(DVIPDFMX_ROOT)/pdffont.c \
$(DVIPDFMX_ROOT)/pdfnames.c \
$(DVIPDFMX_ROOT)/pdfobj.c \
$(DVIPDFMX_ROOT)/pdfparse.c \
$(DVIPDFMX_ROOT)/pdfresource.c \
$(DVIPDFMX_ROOT)/pdfximage.c \
$(DVIPDFMX_ROOT)/pkfont.c \
$(DVIPDFMX_ROOT)/pngimage.c \
$(DVIPDFMX_ROOT)/pst.c \
$(DVIPDFMX_ROOT)/pst_obj.c \
$(DVIPDFMX_ROOT)/sfnt.c \
$(DVIPDFMX_ROOT)/spc_color.c \
$(DVIPDFMX_ROOT)/spc_dvipdfmx.c \
$(DVIPDFMX_ROOT)/spc_dvips.c \
$(DVIPDFMX_ROOT)/spc_html.c \
$(DVIPDFMX_ROOT)/spc_misc.c \
$(DVIPDFMX_ROOT)/spc_pdfm.c \
$(DVIPDFMX_ROOT)/spc_tpic.c \
$(DVIPDFMX_ROOT)/spc_util.c \
$(DVIPDFMX_ROOT)/spc_xtx.c \
$(DVIPDFMX_ROOT)/specials.c \
$(DVIPDFMX_ROOT)/subfont.c \
$(DVIPDFMX_ROOT)/t1_char.c \
$(DVIPDFMX_ROOT)/t1_load.c \
$(DVIPDFMX_ROOT)/tfm.c \
$(DVIPDFMX_ROOT)/truetype.c \
$(DVIPDFMX_ROOT)/tt_aux.c \
$(DVIPDFMX_ROOT)/tt_cmap.c \
$(DVIPDFMX_ROOT)/tt_glyf.c \
$(DVIPDFMX_ROOT)/tt_gsub.c \
$(DVIPDFMX_ROOT)/tt_post.c \
$(DVIPDFMX_ROOT)/tt_table.c \
$(DVIPDFMX_ROOT)/type0.c \
$(DVIPDFMX_ROOT)/type1.c \
$(DVIPDFMX_ROOT)/type1c.c \
$(DVIPDFMX_ROOT)/unicode.c \
$(DVIPDFMX_ROOT)/vf.c \
$(DVIPDFMX_ROOT)/xbb.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libpaper libpng libz
LOCAL_MODULE     := xdvipdfmx
LOCAL_CFLAGS     :=\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement\
-Wno-unknown-pragmas -DHAVE_CONFIG_H -DMAKE_KPSE_DLL -O2
LOCAL_C_INCLUDES := $(DVIPDFMX_INCLUDES)
LOCAL_SRC_FILES  := $(DVIPDFMX_FILES)

include $(BUILD_EXECUTABLE)

#for dvipsk/afm2tfm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvipsk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipsk
PROG_FILES :=\
$(PROG_ROOT)/afm2tfm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := afm2tfm
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DSHIFTLOWCHARS -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for dvipsk/dvips
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/dvipsk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/dvipsk
PROG_FILES :=\
$(PROG_ROOT)/bbox.c \
$(PROG_ROOT)/color.c \
$(PROG_ROOT)/dopage.c \
$(PROG_ROOT)/dosection.c \
$(PROG_ROOT)/dospecial.c \
$(PROG_ROOT)/download.c \
$(PROG_ROOT)/dpicheck.c \
$(PROG_ROOT)/drawPS.c \
$(PROG_ROOT)/dviinput.c \
$(PROG_ROOT)/dvips.c \
$(PROG_ROOT)/emspecial.c \
$(PROG_ROOT)/finclude.c \
$(PROG_ROOT)/fontdef.c \
$(PROG_ROOT)/header.c \
$(PROG_ROOT)/hps.c \
$(PROG_ROOT)/loadfont.c \
$(PROG_ROOT)/output.c \
$(PROG_ROOT)/papersiz.c \
$(PROG_ROOT)/pprescan.c \
$(PROG_ROOT)/prescan.c \
$(PROG_ROOT)/repack.c \
$(PROG_ROOT)/resident.c \
$(PROG_ROOT)/scalewidth.c \
$(PROG_ROOT)/scanpage.c \
$(PROG_ROOT)/search.c \
$(PROG_ROOT)/skippage.c \
$(PROG_ROOT)/t1part.c \
$(PROG_ROOT)/tfmload.c \
$(PROG_ROOT)/unpack.c \
$(PROG_ROOT)/virtualfont.c \
$(PROG_ROOT)/writet1.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := dvips
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DSHIFTLOWCHARS -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for gregorio
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/gregorio
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk \
$(LOCAL_PATH)/../src/texlive-upstream/texk/gregorio \
$(LOCAL_PATH)/../src/texlive-upstream/texk/gregorio/gregorio-src/src \
$(LOCAL_PATH)/../src/texlive-upstream/texk/gregorio/gregorio-src/src/gabc \
$(LOCAL_PATH)/../src/texlive-upstream/texk/gregorio/gregorio-src/src/dump \
$(LOCAL_PATH)/../src/texlive-upstream/texk/gregorio/gregorio-src/src/gregoriotex
PROG_FILES :=\
$(PROG_ROOT)/gregorio-src/src/characters.c \
$(PROG_ROOT)/gregorio-src/src/gregorio-utils.c \
$(PROG_ROOT)/gregorio-src/src/messages.c \
$(PROG_ROOT)/gregorio-src/src/sha1.c \
$(PROG_ROOT)/gregorio-src/src/struct.c \
$(PROG_ROOT)/gregorio-src/src/support.c \
$(PROG_ROOT)/gregorio-src/src/unicode.c \
$(PROG_ROOT)/gregorio-src/src/dump/dump.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-elements-determination.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-glyphs-determination.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-notes-determination-l.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-score-determination-l.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-score-determination-y.c \
$(PROG_ROOT)/gregorio-src/src/gabc/gabc-write.c \
$(PROG_ROOT)/gregorio-src/src/gregoriotex/gregoriotex-position.c \
$(PROG_ROOT)/gregorio-src/src/gregoriotex/gregoriotex-write.c \
$(PROG_ROOT)/gregorio-src/src/vowel/vowel.c \
$(PROG_ROOT)/gregorio-src/src/vowel/vowel-rules-l.c \
$(PROG_ROOT)/gregorio-src/src/vowel/vowel-rules-y.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := gregorio
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -D_GNU_SOURCE -DUSE_KPSE\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for gsftopk
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/gsftopk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/gsftopk
PROG_FILES :=\
$(PROG_ROOT)/gsftopk.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := gsftopk
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -Dlint -DKPATHSEA\
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/liblcdf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/bezier.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/clp.c\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/error.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/filename.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/globmatch.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/landmark.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/md5.c\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/permstr.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/point.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/slurper.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/straccum.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/string.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/strtonum.c\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/transform.cc\
$(PROG_ROOT)/lcdf-typetools-src/liblcdf/vectorv.cc
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := liblcdf
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for lcd-typetools/liblcdf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/libefont/afm.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/afmparse.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/amfm.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/afmw.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/cff.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/encoding.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/findmet.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/metrics.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otf.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfcmap.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfdata.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfdescrip.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfgpos.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfgsub.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfname.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfos2.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/otfpost.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/pairop.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/psres.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1bounds.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1cs.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1csgen.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1interp.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1item.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1font.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1fontskel.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1mm.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1rw.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/t1unparser.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/ttfcs.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/ttfhead.cc\
$(PROG_ROOT)/lcdf-typetools-src/libefont/ttfkern.cc
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libefont
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for lcd-typetools/cfftot1
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/cfftot1/cfftot1.cc\
$(PROG_ROOT)/lcdf-typetools-src/cfftot1/maket1font.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := cfftot1
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/mmafm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/mmafm/main.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := mmafm
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/mmpfb
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/mmpfb/myfont.cc\
$(PROG_ROOT)/lcdf-typetools-src/mmpfb/t1minimize.cc\
$(PROG_ROOT)/lcdf-typetools-src/mmpfb/t1rewrit.cc\
$(PROG_ROOT)/lcdf-typetools-src/mmpfb/main.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := mmpfb
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/otfinfo
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/otfinfo/otfinfo.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := otfinfo
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/otftotfm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/automatic.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/dvipsencoding.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/glyphfilter.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/kpseinterface.c\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/metrics.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/otftotfm.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/secondary.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/uniprop.cc\
$(PROG_ROOT)/lcdf-typetools-src/otftotfm/util.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := otftotfm
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/t1dotlessj
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/t1dotlessj/t1dotlessj.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := t1dotlessj
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/t1lint
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/t1lint/cscheck.cc\
$(PROG_ROOT)/lcdf-typetools-src/t1lint/t1lint.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := t1lint
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/t1rawafm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/t1rawafm/t1rawafm.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := t1rawafm
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/t1testpage
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/t1testpage/t1testpage.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := t1testpage
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for lcd-typetools/ttftotype42
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/lcdf-typetools
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src\
$(LOCAL_PATH)/../src/texlive-upstream/texk/lcdf-typetools/lcdf-typetools-src/include
PROG_FILES :=\
$(PROG_ROOT)/lcdf-typetools-src/ttftotype42/ttftotype42.cc
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libefont liblcdf
LOCAL_MODULE     := ttftotype42
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-fexceptions -frtti -Wreturn-type -Wno-unknown-pragmas -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for makeindex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/makeindexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/makeindexk
PROG_FILES :=\
$(PROG_ROOT)/genind.c\
$(PROG_ROOT)/mkind.c\
$(PROG_ROOT)/qsort.c\
$(PROG_ROOT)/scanid.c\
$(PROG_ROOT)/scanst.c\
$(PROG_ROOT)/sortid.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := makeindex
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for makejvf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/makejvf
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc
PROG_FILES :=\
$(PROG_ROOT)/main.c\
$(PROG_ROOT)/tfmread.c\
$(PROG_ROOT)/tool.c\
$(PROG_ROOT)/uniblock.c\
$(PROG_ROOT)/write.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libptexenc
LOCAL_MODULE     := makejvf
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for memdex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/mendexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/mendexk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ptexenc
PROG_FILES :=\
$(PROG_ROOT)/convert.c\
$(PROG_ROOT)/fread.c\
$(PROG_ROOT)/fwrite.c\
$(PROG_ROOT)/kp.c\
$(PROG_ROOT)/main.c\
$(PROG_ROOT)/pageread.c\
$(PROG_ROOT)/qsort.c\
$(PROG_ROOT)/sort.c\
$(PROG_ROOT)/styfile.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea libptexenc
LOCAL_MODULE     := mendex
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for msxlint
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/musixtnt
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/musixtnt
PROG_FILES :=\
$(PROG_ROOT)/musixtnt-src/msxlint.c\
$(PROG_ROOT)/musixtnt-src/utils.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := msxlint
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ps2pk/mag
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ps2pk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/basics.c\
$(PROG_ROOT)/mag.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := mag
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ps2pk/pfb2pfa
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ps2pk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/basics.c\
$(PROG_ROOT)/filenames.c\
$(PROG_ROOT)/pfb2pfa.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := pfb2pfa
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ps2pk/pk2bm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ps2pk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/basics.c\
$(PROG_ROOT)/pkin.c\
$(PROG_ROOT)/pk2bm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := pk2bm
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ps2pk/ps2pk
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ps2pk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/arith.c\
$(PROG_ROOT)/basics.c\
$(PROG_ROOT)/bstring.c\
$(PROG_ROOT)/curves.c\
$(PROG_ROOT)/encoding.c\
$(PROG_ROOT)/filenames.c\
$(PROG_ROOT)/fontfcn.c\
$(PROG_ROOT)/hints.c\
$(PROG_ROOT)/lines.c\
$(PROG_ROOT)/objects.c\
$(PROG_ROOT)/paths.c\
$(PROG_ROOT)/pkout.c\
$(PROG_ROOT)/ps2pk.c\
$(PROG_ROOT)/regions.c\
$(PROG_ROOT)/scanfont.c\
$(PROG_ROOT)/spaces.c\
$(PROG_ROOT)/t1funcs.c\
$(PROG_ROOT)/t1info.c\
$(PROG_ROOT)/t1io.c\
$(PROG_ROOT)/t1snap.c\
$(PROG_ROOT)/token.c\
$(PROG_ROOT)/type1.c\
$(PROG_ROOT)/util.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := ps2pk
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/libpsutils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/paper-size.c\
$(PROG_ROOT)/progname.c\
$(PROG_ROOT)/verror.c\
$(PROG_ROOT)/psutils-src/psutil.c\
$(PROG_ROOT)/psutils-src/psspec.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpsutils
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)


#for psutils/epsffit
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/epsffit.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := epsffit
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/psbook
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/psbook.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := psbook
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/psnup
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/psnup.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := psnup
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/psresize
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/psresize.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := psresize
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/psselect
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/psselect.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := psselct
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for psutils/pstops
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/psutils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils\
$(LOCAL_PATH)/../src/texlive-upstream/texk/psutils/psutils-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/libpaper/include
PROG_FILES :=\
$(PROG_ROOT)/psutils-src/pstops.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpsutils libpaper libkpathsea
LOCAL_MODULE     := pstops
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

# gripes0.c
# #ifndef WIN32
# #include <errno.h>
# #endif
#for seetex/libtex
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/seetexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/seetexk
PROG_FILES :=\
$(PROG_ROOT)/dviclass.c\
$(PROG_ROOT)/error.c\
$(PROG_ROOT)/fio.c\
$(PROG_ROOT)/gripes0.c\
$(PROG_ROOT)/gripes1.c\
$(PROG_ROOT)/search.c\
$(PROG_ROOT)/seek.c\
$(PROG_ROOT)/tempfile.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libseetex
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for seetex/dvibook
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/seetexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/seetexk
PROG_FILES :=\
$(PROG_ROOT)/dvibook.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := dvibook
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for seetex/dviconcat
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/seetexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/seetexk
PROG_FILES :=\
$(PROG_ROOT)/dviconcat.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := dviconcat
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for seetex/dviselect
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/seetexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/seetexk
PROG_FILES :=\
$(PROG_ROOT)/dviselect.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := dviselect
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for seetex/dvitodvi
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/seetexk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/seetexk
PROG_FILES :=\
$(PROG_ROOT)/dvitodvi.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := dvitodvi
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tex4htk/t4ht
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/tex4htk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/t4ht.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := t4ht
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DANSI -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tex2ht/tex4ht
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/tex4htk
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk
PROG_FILES :=\
$(PROG_ROOT)/tex4ht.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libseetex libkpathsea
LOCAL_MODULE     := tex4ht
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DANSI -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tff2pk2/ttf2pk
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ttf2pk2
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttf2pk2\
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2
PROG_FILES :=\
$(PROG_ROOT)/errormsg.c\
$(PROG_ROOT)/filesrch.c\
$(PROG_ROOT)/ftlib.c\
$(PROG_ROOT)/ligkern.c\
$(PROG_ROOT)/newobj.c\
$(PROG_ROOT)/parse.c\
$(PROG_ROOT)/subfont.c\
$(PROG_ROOT)/texenc.c\
$(PROG_ROOT)/ttfenc.c\
$(PROG_ROOT)/pklib.c\
$(PROG_ROOT)/ttf2pk.c\
$(PROG_ROOT)/ttflib.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libz libfreetype libkpathsea
LOCAL_MODULE     := ttf2pk
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DANSI -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for tff2pk2/ttf2tfm
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ttf2pk2
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttf2pk2\
$(LOCAL_PATH)/../src/texlive-upstream/libs/freetype2/freetype2
PROG_FILES :=\
$(PROG_ROOT)/errormsg.c\
$(PROG_ROOT)/filesrch.c\
$(PROG_ROOT)/ftlib.c\
$(PROG_ROOT)/ligkern.c\
$(PROG_ROOT)/newobj.c\
$(PROG_ROOT)/parse.c\
$(PROG_ROOT)/subfont.c\
$(PROG_ROOT)/texenc.c\
$(PROG_ROOT)/ttfenc.c\
$(PROG_ROOT)/case.c\
$(PROG_ROOT)/tfmaux.c\
$(PROG_ROOT)/ttf2tfm.c\
$(PROG_ROOT)/ttfaux.c\
$(PROG_ROOT)/vplaux.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libz libfreetype libkpathsea
LOCAL_MODULE     := ttf2tfm
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DANSI -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for ttfdump/libttf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ttfdump
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttfdump\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttfdump/include
PROG_FILES :=\
$(PROG_ROOT)/libttf/cmap.c\
$(PROG_ROOT)/libttf/cvt.c\
$(PROG_ROOT)/libttf/disasm.c\
$(PROG_ROOT)/libttf/font.c\
$(PROG_ROOT)/libttf/fpgm.c\
$(PROG_ROOT)/libttf/gasp.c\
$(PROG_ROOT)/libttf/gcache.c\
$(PROG_ROOT)/libttf/glyf.c\
$(PROG_ROOT)/libttf/gpos.c\
$(PROG_ROOT)/libttf/gsub.c\
$(PROG_ROOT)/libttf/gstate.c\
$(PROG_ROOT)/libttf/hdmx.c\
$(PROG_ROOT)/libttf/head.c\
$(PROG_ROOT)/libttf/hhea.c\
$(PROG_ROOT)/libttf/hmtx.c\
$(PROG_ROOT)/libttf/kern.c\
$(PROG_ROOT)/libttf/loca.c\
$(PROG_ROOT)/libttf/ltsh.c\
$(PROG_ROOT)/libttf/maxp.c\
$(PROG_ROOT)/libttf/name.c\
$(PROG_ROOT)/libttf/os2.c\
$(PROG_ROOT)/libttf/otfcommon.c\
$(PROG_ROOT)/libttf/pclt.c\
$(PROG_ROOT)/libttf/post.c\
$(PROG_ROOT)/libttf/prep.c\
$(PROG_ROOT)/libttf/tabledir.c\
$(PROG_ROOT)/libttf/ttc.c\
$(PROG_ROOT)/libttf/ttfread.c\
$(PROG_ROOT)/libttf/ttfutil.c\
$(PROG_ROOT)/libttf/vdmx.c\
$(PROG_ROOT)/libttf/vhea.c\
$(PROG_ROOT)/libttf/vmtx.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libttf
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DUNIX -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for ttfdump
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/texk/ttfdump
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttfdump\
$(LOCAL_PATH)/../src/texlive-upstream/texk/ttfdump/include
PROG_FILES :=\
$(PROG_ROOT)/src/ttfdump.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libttf libkpathsea
LOCAL_MODULE     := ttfdump
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DANSI -DKPATHSEA\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/autosp
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/autosp
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/autosp
PROG_FILES :=\
$(PROG_ROOT)/autosp-src/autosp.c\
$(PROG_ROOT)/autosp-src/utils.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := autosp
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"autosp\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"autosp--tex-live-\" \
-DPACKAGE_VERSION=\"2016-01-30\" \
-DPACKAGE_STRING=\"autosp\ \(TeX\ Live\)\ 2016-01-30\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"autosp--tex-live-\" \
-DVERSION=\"2016-01-30\" \
-DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 \
-DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 \
-DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 \
-DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 \
-DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 \
-DHAVE_STDIO_H=1 -DHAVE_TIME_H=1 \
-DHAVE_GETOPT_H=1 -DHAVE_CTYPE_H=1 \
-DHAVE_LIMITS_H=1 -DHAVE__BOOL=1 \
-DHAVE_STDBOOL_H=1 -DHAVE_STRSTR=1\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/devnag
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/devnag
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/devnag
PROG_FILES :=\
$(PROG_ROOT)/src/devnag.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := debnag
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H -DTEXLIVE\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/lacheck
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/lacheck
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/lacheck
PROG_FILES :=\
$(PROG_ROOT)/lacheck.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := lacheck
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/m-tx
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/m-tx
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/m-tx\
$(LOCAL_PATH)/../src/texlive-upstream/utils/m-tx/mtx-src/libp2c
PROG_FILES :=\
$(PROG_ROOT)/mtx-src/analyze.c \
$(PROG_ROOT)/mtx-src/cfuncs.c \
$(PROG_ROOT)/mtx-src/control.c \
$(PROG_ROOT)/mtx-src/files.c \
$(PROG_ROOT)/mtx-src/globals.c \
$(PROG_ROOT)/mtx-src/lyrics.c \
$(PROG_ROOT)/mtx-src/mtx.c \
$(PROG_ROOT)/mtx-src/mtxline.c \
$(PROG_ROOT)/mtx-src/multfile.c \
$(PROG_ROOT)/mtx-src/notes.c \
$(PROG_ROOT)/mtx-src/preamble.c \
$(PROG_ROOT)/mtx-src/prepmx.c \
$(PROG_ROOT)/mtx-src/status.c \
$(PROG_ROOT)/mtx-src/uptext.c \
$(PROG_ROOT)/mtx-src/utility.c 
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := prepmx
LOCAL_LDLIBS     := -s
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"m-tx\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"m-tx--tex-live-\" \
-DPACKAGE_VERSION=\"0.62\" \
-DPACKAGE_STRING=\"m-tx\ \(TeX\ Live\)\ 0.62\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"m-tx--tex-live-\" \
-DVERSION=\"0.62\" \
-DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 \
-DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 \
-DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 \
-DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 \
-DHAVE_MEMORY_H=1 -DHAVE_STDDEF_H=1 \
-DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_MEMCHR=1 \
-DHAVE_MEMMOVE=1 -DHAVE_MEMSET=1 \
-DHAVE_STRCHR=1 -DHAVE_STRRCHR=1 \
-DHAVE_STRTOL=1 -DNO_DECLARE_MALLOC \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pmx/libf2c
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/pmx
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx\
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx/pmx-src/libf2c
PROG_FILES :=\
$(PROG_ROOT)/pmx-src/libf2c/abort_.c \
$(PROG_ROOT)/pmx-src/libf2c/cabs.c \
$(PROG_ROOT)/pmx-src/libf2c/derf_.c \
$(PROG_ROOT)/pmx-src/libf2c/derfc_.c \
$(PROG_ROOT)/pmx-src/libf2c/erf_.c \
$(PROG_ROOT)/pmx-src/libf2c/erfc_.c \
$(PROG_ROOT)/pmx-src/libf2c/exit_.c \
$(PROG_ROOT)/pmx-src/libf2c/f77vers.c \
$(PROG_ROOT)/pmx-src/libf2c/getarg_.c \
$(PROG_ROOT)/pmx-src/libf2c/getenv_.c \
$(PROG_ROOT)/pmx-src/libf2c/i77vers.c \
$(PROG_ROOT)/pmx-src/libf2c/iargc_.c \
$(PROG_ROOT)/pmx-src/libf2c/main.c \
$(PROG_ROOT)/pmx-src/libf2c/s_paus.c \
$(PROG_ROOT)/pmx-src/libf2c/s_rnge.c \
$(PROG_ROOT)/pmx-src/libf2c/s_stop.c \
$(PROG_ROOT)/pmx-src/libf2c/sig_die.c \
$(PROG_ROOT)/pmx-src/libf2c/signal_.c \
$(PROG_ROOT)/pmx-src/libf2c/system_.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_ci.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_dd.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_di.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_hh.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_ii.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_ri.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_zi.c \
$(PROG_ROOT)/pmx-src/libf2c/pow_zz.c \
$(PROG_ROOT)/pmx-src/libf2c/c_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/c_cos.c \
$(PROG_ROOT)/pmx-src/libf2c/c_div.c \
$(PROG_ROOT)/pmx-src/libf2c/c_exp.c \
$(PROG_ROOT)/pmx-src/libf2c/c_log.c \
$(PROG_ROOT)/pmx-src/libf2c/c_sin.c \
$(PROG_ROOT)/pmx-src/libf2c/c_sqrt.c \
$(PROG_ROOT)/pmx-src/libf2c/z_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/z_cos.c \
$(PROG_ROOT)/pmx-src/libf2c/z_div.c \
$(PROG_ROOT)/pmx-src/libf2c/z_exp.c \
$(PROG_ROOT)/pmx-src/libf2c/z_log.c \
$(PROG_ROOT)/pmx-src/libf2c/z_sin.c \
$(PROG_ROOT)/pmx-src/libf2c/z_sqrt.c \
$(PROG_ROOT)/pmx-src/libf2c/r_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/r_acos.c \
$(PROG_ROOT)/pmx-src/libf2c/r_asin.c \
$(PROG_ROOT)/pmx-src/libf2c/r_atan.c \
$(PROG_ROOT)/pmx-src/libf2c/r_atn2.c \
$(PROG_ROOT)/pmx-src/libf2c/r_cnjg.c \
$(PROG_ROOT)/pmx-src/libf2c/r_cos.c \
$(PROG_ROOT)/pmx-src/libf2c/r_cosh.c \
$(PROG_ROOT)/pmx-src/libf2c/r_dim.c \
$(PROG_ROOT)/pmx-src/libf2c/r_exp.c \
$(PROG_ROOT)/pmx-src/libf2c/r_imag.c \
$(PROG_ROOT)/pmx-src/libf2c/r_int.c \
$(PROG_ROOT)/pmx-src/libf2c/r_lg10.c \
$(PROG_ROOT)/pmx-src/libf2c/r_log.c \
$(PROG_ROOT)/pmx-src/libf2c/r_mod.c \
$(PROG_ROOT)/pmx-src/libf2c/r_nint.c \
$(PROG_ROOT)/pmx-src/libf2c/r_sign.c \
$(PROG_ROOT)/pmx-src/libf2c/r_sin.c \
$(PROG_ROOT)/pmx-src/libf2c/r_sinh.c \
$(PROG_ROOT)/pmx-src/libf2c/r_sqrt.c \
$(PROG_ROOT)/pmx-src/libf2c/r_tan.c \
$(PROG_ROOT)/pmx-src/libf2c/r_tanh.c \
$(PROG_ROOT)/pmx-src/libf2c/d_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/d_acos.c \
$(PROG_ROOT)/pmx-src/libf2c/d_asin.c \
$(PROG_ROOT)/pmx-src/libf2c/d_atan.c \
$(PROG_ROOT)/pmx-src/libf2c/d_atn2.c \
$(PROG_ROOT)/pmx-src/libf2c/d_cnjg.c \
$(PROG_ROOT)/pmx-src/libf2c/d_cos.c \
$(PROG_ROOT)/pmx-src/libf2c/d_cosh.c \
$(PROG_ROOT)/pmx-src/libf2c/d_dim.c \
$(PROG_ROOT)/pmx-src/libf2c/d_exp.c \
$(PROG_ROOT)/pmx-src/libf2c/d_imag.c \
$(PROG_ROOT)/pmx-src/libf2c/d_int.c \
$(PROG_ROOT)/pmx-src/libf2c/d_lg10.c \
$(PROG_ROOT)/pmx-src/libf2c/d_log.c \
$(PROG_ROOT)/pmx-src/libf2c/d_mod.c \
$(PROG_ROOT)/pmx-src/libf2c/d_nint.c \
$(PROG_ROOT)/pmx-src/libf2c/d_prod.c \
$(PROG_ROOT)/pmx-src/libf2c/d_sign.c \
$(PROG_ROOT)/pmx-src/libf2c/d_sin.c \
$(PROG_ROOT)/pmx-src/libf2c/d_sinh.c \
$(PROG_ROOT)/pmx-src/libf2c/d_sqrt.c \
$(PROG_ROOT)/pmx-src/libf2c/d_tan.c \
$(PROG_ROOT)/pmx-src/libf2c/d_tanh.c \
$(PROG_ROOT)/pmx-src/libf2c/i_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/i_dim.c \
$(PROG_ROOT)/pmx-src/libf2c/i_dnnt.c \
$(PROG_ROOT)/pmx-src/libf2c/i_indx.c \
$(PROG_ROOT)/pmx-src/libf2c/i_len.c \
$(PROG_ROOT)/pmx-src/libf2c/i_mod.c \
$(PROG_ROOT)/pmx-src/libf2c/i_nint.c \
$(PROG_ROOT)/pmx-src/libf2c/i_sign.c \
$(PROG_ROOT)/pmx-src/libf2c/lbitbits.c \
$(PROG_ROOT)/pmx-src/libf2c/lbitshft.c \
$(PROG_ROOT)/pmx-src/libf2c/h_abs.c \
$(PROG_ROOT)/pmx-src/libf2c/h_dim.c \
$(PROG_ROOT)/pmx-src/libf2c/h_dnnt.c \
$(PROG_ROOT)/pmx-src/libf2c/h_indx.c \
$(PROG_ROOT)/pmx-src/libf2c/h_len.c \
$(PROG_ROOT)/pmx-src/libf2c/h_mod.c \
$(PROG_ROOT)/pmx-src/libf2c/h_nint.c \
$(PROG_ROOT)/pmx-src/libf2c/h_sign.c \
$(PROG_ROOT)/pmx-src/libf2c/hl_ge.c \
$(PROG_ROOT)/pmx-src/libf2c/hl_gt.c \
$(PROG_ROOT)/pmx-src/libf2c/hl_le.c \
$(PROG_ROOT)/pmx-src/libf2c/hl_lt.c \
$(PROG_ROOT)/pmx-src/libf2c/l_ge.c \
$(PROG_ROOT)/pmx-src/libf2c/l_gt.c \
$(PROG_ROOT)/pmx-src/libf2c/l_le.c \
$(PROG_ROOT)/pmx-src/libf2c/l_lt.c \
$(PROG_ROOT)/pmx-src/libf2c/ef1asc_.c \
$(PROG_ROOT)/pmx-src/libf2c/ef1cmc_.c \
$(PROG_ROOT)/pmx-src/libf2c/f77_aloc.c \
$(PROG_ROOT)/pmx-src/libf2c/s_cat.c \
$(PROG_ROOT)/pmx-src/libf2c/s_cmp.c \
$(PROG_ROOT)/pmx-src/libf2c/s_copy.c \
$(PROG_ROOT)/pmx-src/libf2c/backspac.c \
$(PROG_ROOT)/pmx-src/libf2c/close.c \
$(PROG_ROOT)/pmx-src/libf2c/dfe.c \
$(PROG_ROOT)/pmx-src/libf2c/dolio.c \
$(PROG_ROOT)/pmx-src/libf2c/due.c \
$(PROG_ROOT)/pmx-src/libf2c/endfile.c \
$(PROG_ROOT)/pmx-src/libf2c/err.c \
$(PROG_ROOT)/pmx-src/libf2c/fmt.c \
$(PROG_ROOT)/pmx-src/libf2c/fmtlib.c \
$(PROG_ROOT)/pmx-src/libf2c/ftell_.c \
$(PROG_ROOT)/pmx-src/libf2c/iio.c \
$(PROG_ROOT)/pmx-src/libf2c/ilnw.c \
$(PROG_ROOT)/pmx-src/libf2c/inquire.c \
$(PROG_ROOT)/pmx-src/libf2c/lread.c \
$(PROG_ROOT)/pmx-src/libf2c/lwrite.c \
$(PROG_ROOT)/pmx-src/libf2c/open.c \
$(PROG_ROOT)/pmx-src/libf2c/rdfmt.c \
$(PROG_ROOT)/pmx-src/libf2c/rewind.c \
$(PROG_ROOT)/pmx-src/libf2c/rsfe.c \
$(PROG_ROOT)/pmx-src/libf2c/rsli.c \
$(PROG_ROOT)/pmx-src/libf2c/rsne.c \
$(PROG_ROOT)/pmx-src/libf2c/sfe.c \
$(PROG_ROOT)/pmx-src/libf2c/sue.c \
$(PROG_ROOT)/pmx-src/libf2c/typesize.c \
$(PROG_ROOT)/pmx-src/libf2c/uio.c \
$(PROG_ROOT)/pmx-src/libf2c/util.c \
$(PROG_ROOT)/pmx-src/libf2c/wref.c \
$(PROG_ROOT)/pmx-src/libf2c/wrtfmt.c \
$(PROG_ROOT)/pmx-src/libf2c/wsfe.c \
$(PROG_ROOT)/pmx-src/libf2c/wsle.c \
$(PROG_ROOT)/pmx-src/libf2c/wsne.c \
$(PROG_ROOT)/pmx-src/libf2c/xwsne.c \
$(PROG_ROOT)/pmx-src/libf2c/dtime_.c \
$(PROG_ROOT)/pmx-src/libf2c/etime_.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpmxf2c
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"pmx\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"pmx--tex-live-\" \
-DPACKAGE_VERSION=\"2.7.3\" \
-DPACKAGE_STRING=\"pmx\ \(TeX\ Live\)\ 2.7.3\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"pmx--tex-live-\" -DVERSION=\"2.7.3\" \
-DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 \
-DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 \
-DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 \
-DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 \
-DSIZEOF_LONG_LONG=8 -DNON_UNIX_STDIO\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_STATIC_LIBRARY)

#for pmx/pmxab
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/pmx
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx\
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx/pmx-src/libf2c
PROG_FILES :=\
$(PROG_ROOT)/pmx-src/pmxab.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpmxf2c libkpathsea
LOCAL_MODULE     := pmxab
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"pmx\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"pmx--tex-live-\" \
-DPACKAGE_VERSION=\"2.7.3\" \
-DPACKAGE_STRING=\"pmx\ \(TeX\ Live\)\ 2.7.3\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"pmx--tex-live-\" -DVERSION=\"2.7.3\" \
-DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 \
-DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 \
-DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 \
-DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 \
-DSIZEOF_LONG_LONG=8 -DNON_UNIX_STDIO\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for pmx/scor2prt
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/pmx
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx\
$(LOCAL_PATH)/../src/texlive-upstream/utils/pmx/pmx-src/libf2c
PROG_FILES :=\
$(PROG_ROOT)/pmx-src/scor2prt.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libpmxf2c libkpathsea
LOCAL_MODULE     := scor2prt
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"pmx\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"pmx--tex-live-\" \
-DPACKAGE_VERSION=\"2.7.3\" \
-DPACKAGE_STRING=\"pmx\ \(TeX\ Live\)\ 2.7.3\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"pmx--tex-live-\" -DVERSION=\"2.7.3\" \
-DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 \
-DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 \
-DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 \
-DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 \
-DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 \
-DSIZEOF_LONG_LONG=8 -DNON_UNIX_STDIO\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/ps2eps
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/ps2eps
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/ps2eps
PROG_FILES :=\
$(PROG_ROOT)/ps2eps-src/src/C/bbox.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := bbox
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"ps2eps\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"ps2eps--tex-live-\" \
-DPACKAGE_VERSION=\"1.68\" \
-DPACKAGE_STRING=\"ps2eps\ \(TeX\ Live\)\ 1.68\" \
-DPACKAGE_BUGREPORT=\"tex-k@tug.org\" \
-DPACKAGE_URL=\"\" \
-DPACKAGE=\"ps2eps--tex-live-\" \
-DVERSION=\"1.68\" \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1ascii.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1ascii
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1binary.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1binary
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1asm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1asm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1disasm.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1disasm
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1unmac.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1unmac
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/t1utils
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/t1utils
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils\
$(LOCAL_PATH)/../src/texlive-upstream/utils/t1utils/t1utils-src/include
PROG_FILES :=\
$(PROG_ROOT)/t1utils-src/clp.c \
$(PROG_ROOT)/t1utils-src/t1lib.c \
$(PROG_ROOT)/t1utils-src/t1mac.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := t1mac
LOCAL_CFLAGS     := \
-DHAVE_CONFIG_H\
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)

#for utils/vlna
include $(CLEAR_VARS)

PROG_ROOT     := ../src/texlive-upstream/utils/vlna
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/utils/vlna
PROG_FILES :=\
$(PROG_ROOT)/vlna.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libkpathsea
LOCAL_MODULE     := vlna
LOCAL_CFLAGS     := \
-DPACKAGE_NAME=\"vlna\ \(TeX\ Live\)\" \
-DPACKAGE_TARNAME=\"vlna--tex-live-\" \
-DPACKAGE_VERSION=\"1.5\" \
-DPACKAGE_STRING=\"vlna\ \(TeX\ Live\)\ 1.5\" \
-DPACKAGE_BUGREPORT=\"tex-live@tug.org\" \
-DPACKAGE_URL=\"\" \
-Wimplicit -Wreturn-type -Wno-unknown-pragmas\
-Wdeclaration-after-statement -Wno-write-strings -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)
