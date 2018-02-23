## $Id: Makefile.am 44086 2017-04-27 21:38:29Z karl $
## Makefile.am for the TeX Live subdirectory texk/upmendex/
##
## Copyright 2017 Karl Berry <tex-live@tug.org>
## Copyright 2010-2014 Peter Breitenlohner <tex-live@tug.org>
## You may freely use, modify and/or distribute this file.
##
AM_CPPFLAGS = $(KPATHSEA_INCLUDES) $(ICU_INCLUDES)
AM_CFLAGS = $(WARNING_CFLAGS)

bin_PROGRAMS = upmendex

upmendex_SOURCES = \
	convert.c \
	exkana.h \
	exvar.h \
	fread.c \
	fwrite.c \
	kana.h \
	kp.c \
	kp.h \
	ktable.h \
	main.c \
	mendex.h \
	pageread.c \
	qsort.c \
	qsort.h \
	sort.c \
	styfile.c \
	var.h



# Force Automake to use CXXLD for linking
nodist_EXTRA_upmendex_SOURCES = dummy.cxx


$(upmendex_OBJECTS): $(KPATHSEA_DEPEND) $(ICU_DEPEND)

LDADD = $(KPATHSEA_LIBS) $(ICU_LIBS) $(ICU_LIBS_EXTRA)

## Rebuild libkpathsea
@KPATHSEA_RULE@
## Rebuild libsicuxxx
@ICU_RULE@

EXTRA_DIST = \
	COPYRIGHT

## Eventually delete these files
##
EXTRA_DIST += \
	indexsty \
	upmendex.doc

## Tests
##
TESTS = tests/upmendex.test
EXTRA_DIST += $(TESTS)

## tests/upmendex.test
EXTRA_DIST += tests/foo.idx tests/foo.ind \
	tests/uni.idx tests/uni.dict tests/uni.ist tests/uni.ind
DISTCLEANFILES = foo.* uni.*