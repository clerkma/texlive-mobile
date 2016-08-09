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

#for bibtex
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
#include $(CLEAR_VARS)
#
#PROG_ROOT     := ../src/texlive-upstream/texk/dvidvi
#PROG_INCLUDES := \
#$(LOCAL_PATH)/../src/texlive-upstream/texk\
#$(LOCAL_PATH)/../src/texlive-upstream/texk/dvidvi
#PROG_FILES :=\
#$(PROG_ROOT)/dvidvi.c
#LOCAL_ARM_NEON   := false
#LOCAL_STATIC_LIBRARIES  := libkpathsea
#LOCAL_MODULE     := dvidvi
#LOCAL_LDLIBS     := -s -lm
#LOCAL_CFLAGS     := \
#-DHAVE_CONFIG_H -DNO_DEBUG -DUNIX -DKPATHSEA\
#-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
#LOCAL_C_INCLUDES := $(PROG_INCLUDES)
#LOCAL_SRC_FILES  := $(PROG_FILES)
#
#include $(BUILD_EXECUTABLE)

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
