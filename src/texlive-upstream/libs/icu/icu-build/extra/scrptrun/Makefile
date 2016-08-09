## Makefile.in for ICU - extra/scrptrun
## Copyright (c) 2001-2011, International Business Machines Corporation and
## others. All Rights Reserved.

## Source directory information
srcdir = /home/maqiyuan/Desktop/texlive-upstream/libs/icu/icu-src/source/extra/scrptrun
top_srcdir = /home/maqiyuan/Desktop/texlive-upstream/libs/icu/icu-src/source

top_builddir = ../..

include $(top_builddir)/icudefs.mk

## Platform-specific setup
include $(top_srcdir)/config/mh-linux

## Build directory information
subdir = extra/scrptrun

## Extra files to remove for 'make clean'
CLEANFILES = *~ $(DEPS)

## Target information
TARGET = srtest

DEFS = -DPACKAGE_NAME=\"ICU\" -DPACKAGE_TARNAME=\"International\ Components\ for\ Unicode\" -DPACKAGE_VERSION=\"57.1\" -DPACKAGE_STRING=\"ICU\ 57.1\" -DPACKAGE_BUGREPORT=\"http://icu-project.org/bugs\" -DPACKAGE_URL=\"http://icu-project.org\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DSIZEOF_VOID_P=8 -DHAVE_LIBM=1 -DHAVE_ELF_H=1 -DHAVE_GETTIMEOFDAY=1 -DHAVE_LIBPTHREAD=1 -DHAVE_INTTYPES_H=1 -DHAVE_DIRENT_H=1 -DHAVE_WCHAR_H=1 -DSIZEOF_WCHAR_T=4
CPPFLAGS =  -ffunction-sections -fdata-sections $(THREADSCPPFLAGS)  -DU_HAVE_ELF_H=1 -DU_ENABLE_DYLOAD=0 -DU_HAVE_ATOMIC=1  -I$(top_srcdir)/common -I$(top_srcdir) 
CFLAGS =  -O2 $(THREADSCFLAGS) 
CXXFLAGS =  -O2 --std=c++0x $(THREADSCXXFLAGS) 
ENABLE_RPATH = NO
ifeq ($(ENABLE_RPATH),YES)
RPATHLDFLAGS = $(LD_RPATH)$(LD_RPATH_PRE)$(libdir)
endif
LDFLAGS =  -Wl,--gc-sections $(RPATHLDFLAGS)
LIBS = $(LIBICUUC) -lpthread -lm  

OBJECTS = scrptrun.o srtest.o

DEPS = $(OBJECTS:.o=.d)

## List of phony targets
.PHONY : all all-local install install-local clean clean-local	\
distclean distclean-local dist dist-local check check-local

## Clear suffix list
.SUFFIXES :

## List of standard targets
all: all-local
install: install-local
clean: clean-local
distclean : distclean-local
dist: dist-local
check: all check-local

all-local: $(TARGET)

install-local:

dist-local:

clean-local:
	test -z "$(CLEANFILES)" || $(RMV) $(CLEANFILES)
	$(RMV) $(OBJECTS) $(TARGET)

distclean-local: clean-local
	$(RMV) Makefile

check-local: all-local

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	 && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status

$(TARGET) : $(OBJECTS)
	$(LINK.cc) -o $@ $^ $(LIBS)
	$(POST_BUILD_STEP)

invoke:
	ICU_DATA=$${ICU_DATA:-$(top_builddir)/data/} TZ=PST8PDT $(INVOKE) $(INVOCATION)

ifeq (,$(MAKECMDGOALS))
-include $(DEPS)
else
ifneq ($(patsubst %clean,,$(MAKECMDGOALS)),)
-include $(DEPS)
endif
endif
