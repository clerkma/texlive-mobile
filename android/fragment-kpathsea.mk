# for kpathsea
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

KPATHSEA_ROOT     := ../src/texlive-upstream/texk/kpathsea
KPATHSEA_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/texk/\
$(LOCAL_PATH)/../src/texlive-upstream/texk/kpathsea
KPATHSEA_FILES    := \
$(KPATHSEA_ROOT)/progname.c \
$(KPATHSEA_ROOT)/readable.c \
$(KPATHSEA_ROOT)/rm-suffix.c \
$(KPATHSEA_ROOT)/absolute.c \
$(KPATHSEA_ROOT)/str-list.c \
$(KPATHSEA_ROOT)/atou.c \
$(KPATHSEA_ROOT)/str-llist.c \
$(KPATHSEA_ROOT)/cnf.c \
$(KPATHSEA_ROOT)/tex-file.c \
$(KPATHSEA_ROOT)/concat3.c \
$(KPATHSEA_ROOT)/tex-glyph.c \
$(KPATHSEA_ROOT)/concatn.c \
$(KPATHSEA_ROOT)/tex-hush.c \
$(KPATHSEA_ROOT)/concat.c \
$(KPATHSEA_ROOT)/tex-make.c \
$(KPATHSEA_ROOT)/db.c \
$(KPATHSEA_ROOT)/tilde.c \
$(KPATHSEA_ROOT)/debug.c \
$(KPATHSEA_ROOT)/uppercasify.c \
$(KPATHSEA_ROOT)/dir.c \
$(KPATHSEA_ROOT)/variable.c \
$(KPATHSEA_ROOT)/elt-dirs.c \
$(KPATHSEA_ROOT)/version.c \
$(KPATHSEA_ROOT)/expand.c \
$(KPATHSEA_ROOT)/xbasename.c \
$(KPATHSEA_ROOT)/extend-fname.c \
$(KPATHSEA_ROOT)/xcalloc.c \
$(KPATHSEA_ROOT)/file-p.c \
$(KPATHSEA_ROOT)/xdirname.c \
$(KPATHSEA_ROOT)/find-suffix.c \
$(KPATHSEA_ROOT)/xfopen.c \
$(KPATHSEA_ROOT)/fn.c \
$(KPATHSEA_ROOT)/xfseek.c \
$(KPATHSEA_ROOT)/fontmap.c \
$(KPATHSEA_ROOT)/xfseeko.c \
$(KPATHSEA_ROOT)/getopt1.c \
$(KPATHSEA_ROOT)/xftell.c \
$(KPATHSEA_ROOT)/getopt.c \
$(KPATHSEA_ROOT)/xftello.c \
$(KPATHSEA_ROOT)/hash.c \
$(KPATHSEA_ROOT)/xgetcwd.c \
$(KPATHSEA_ROOT)/kdefault.c \
$(KPATHSEA_ROOT)/xmalloc.c \
$(KPATHSEA_ROOT)/kpathsea.c \
$(KPATHSEA_ROOT)/xopendir.c \
$(KPATHSEA_ROOT)/line.c \
$(KPATHSEA_ROOT)/xputenv.c \
$(KPATHSEA_ROOT)/magstep.c \
$(KPATHSEA_ROOT)/xrealloc.c \
$(KPATHSEA_ROOT)/make-suffix.c \
$(KPATHSEA_ROOT)/xstat.c \
$(KPATHSEA_ROOT)/path-elt.c \
$(KPATHSEA_ROOT)/xstrdup.c \
$(KPATHSEA_ROOT)/pathsearch.c \
$(KPATHSEA_ROOT)/proginit.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libkpathsea
LOCAL_CFLAGS     := \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas\
-DHAVE_CONFIG_H -DHAVE_STRING_H -DMAKE_KPSE_DLL -O2
LOCAL_C_INCLUDES := $(KPATHSEA_INCLUDES)
LOCAL_SRC_FILES  := $(KPATHSEA_FILES)

include $(BUILD_STATIC_LIBRARY)
