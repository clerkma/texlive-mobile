## $Id: Makefile.am 53601 2020-01-30 19:18:37Z karl $
## Makefile.am for the TeX Live subdirectory texk/dvipsk/
##
## Copyright 2017-2020 Karl Berry <tex-live@tug.org>
## Copyright 2009-2015 Peter Breitenlohner <tex-live@tug.org>
## You may freely use, modify and/or distribute this file.
##
SUBDIRS = squeeze

AM_CPPFLAGS = $(KPATHSEA_INCLUDES) -DUNIX -DKPATHSEA -DSHIFTLOWCHARS
AM_CFLAGS = $(WARNING_CFLAGS)

bin_PROGRAMS = afm2tfm dvips

afm2tfm_SOURCES = afm2tfm.c

$(afm2tfm_OBJECTS): $(KPATHSEA_DEPEND)

dvips_SOURCES = \
	bbox.c \
	bitmapenc.c \
	color.c \
	config.h \
	debug.h \
	dopage.c \
	dosection.c \
	dospecial.c \
	download.c \
	dpicheck.c \
	drawPS.c \
	dviinput.c \
	dvips.c \
	dvips.h \
	emspecial.c \
	finclude.c \
	fontdef.c \
	header.c \
	hps.c \
	loadfont.c \
	output.c \
	papersiz.c \
	paths.h \
	pprescan.c \
	prescan.c \
	protos.h \
	protos_add.h \
	ptexmac.h \
	repack.c \
	resident.c \
	scalewidth.c \
	scanpage.c \
	search.c \
	skippage.c \
	t1part.c \
	t1part.h \
	tfmload.c \
	unpack.c \
	virtualfont.c \
	writet1.c

$(dvips_OBJECTS): $(KPATHSEA_DEPEND)

LDADD = $(KPATHSEA_LIBS)

## Rebuild libkpathsea
@KPATHSEA_RULE@

dist_man1_MANS = afm2tfm.1 dvips.1

info_TEXINFOS = dvips.texi
dvips_TEXINFOS = contrib/config.proto dvips.help

DISTCLEANFILES = $(DVIS) $(PSS)

enc_DATA = dvips-all.enc

prolog_DATA = $(prologues)

dist_prologues = \
	color.lpro \
	crop.lpro \
	finclude.lpro \
	hps.lpro \
	special.lpro \
	tex.lpro \
	texps.lpro

prologdir = $(datarootdir)/texmf-dist/dvips/base

prologues = $(dist_prologues:.lpro=.pro) texc.pro

texc.lpro: texc.script tex.lpro
	$(AM_V_GEN)$(SHELL) $(srcdir)/texc.script $(srcdir)/tex.lpro $@

SUFFIXES = .pro .lpro

# The `t[mp]-' business is so that we don't create an empty .pro file,
# if running squeeze fails for some reason.  A dependency on squeeze
# fails here, so we include it below.
.lpro.pro:
	$(AM_V_GEN)squeeze/squeeze <$< >t-$@ && mv t-$@ $@

# When cross-compiling, EXEEXT for the build and host systems may differ.
# Thus we depend on the auxiliary file squeeze/stamp-squeeze.
$(prologues): squeeze/stamp-squeeze

squeeze/stamp-squeeze:
	cd squeeze && $(MAKE) $(AM_MAKEFLAGS) stamp-squeeze

EXTRA_DIST = $(dist_prologues) texc.script

CLEANFILES = $(prologues) texc.lpro

## dvips tests
TEST_EXTENSIONS = .pl .test
TESTS = afm2tfm-test.pl
afm2tfm-test.log: afm2tfm$(EXEEXT)
TESTS += beginfontk1.test eepic-nan.test pfbincl.test \
	quotecmd-test.pl same-name.test test-dvips.test \
	test-overflow-buffers.test
beginfontk1.log eepic-nan.log pfbincl.log \
	quotecmd-test.log same-name.log test-dvips.log \
	test-overflow-buffers.log: dvips$(EXEEXT)

AM_TESTS_ENVIRONMENT  = TEXMFCNF=$(srcdir)/../kpathsea; export TEXMFCNF;
AM_TESTS_ENVIRONMENT += TEXCONFIG=$(srcdir)/testdata; export TEXCONFIG;
AM_TESTS_ENVIRONMENT += TEXFONTS=$(srcdir)/testdata; export TEXFONTS;
AM_TESTS_ENVIRONMENT += TEXFONTMAPS=$(srcdir)/testdata; export TEXFONTMAPS;
AM_TESTS_ENVIRONMENT += TEXPSHEADERS=$(srcdir)/testdata; export TEXPSHEADERS;

EXTRA_DIST += \
	$(TESTS) \
	testdata/8r.enc \
	testdata/ad.enc \
	testdata/alt-rule.pro \
	testdata/cmex10.pfb \
	testdata/cmex10.tfm \
	testdata/cmmi10.pfb \
	testdata/cmmi10.tfm \
	testdata/cmr10.pfb \
	testdata/cmr10.tfm \
	testdata/cmsy10.pfb \
	testdata/cmsy10.tfm \
	testdata/cmtt10.pfb \
	testdata/cmtt10.tfm \
	testdata/color.pro \
	testdata/config.pdf \
	testdata/config.ps \
	testdata/psfonts.map \
	testdata/ptmbi.vf \
	testdata/ptmbi8r.tfm \
	testdata/ptmr.vf \
	testdata/ptmr8r.tfm \
	testdata/ptmri.vf \
	testdata/ptmri8r.tfm \
	testdata/special.pro \
	testdata/tex.pro \
	testdata/texc.pro \
	testdata/texps.pro

## afm2tfm-test.pl
DISTCLEANFILES += afmtest.tfm
## beginfontk1.test
EXTRA_DIST += testdata/beginfontk1.dvi testdata/beginfontk1.eps testdata/beginfontk1.tex
DISTCLEANFILES += beginfontk1.ps
## eepic-nan.test
EXTRA_DIST += testdata/eepic-nan.dvi testdata/eepic-nan.tex
DISTCLEANFILES += eepic-nan.ps
## pfbincl.test
EXTRA_DIST += testdata/pfbincl.eps testdata/pfbincl.tex testdata/pfbincl.xdv testdata/pfbincl.xps 
DISTCLEANFILES += pfbincl.ps
## quotecmd-test.pl
EXTRA_DIST += testdata/quotecmd.dvi testdata/quotecmd.tex 
DISTCLEANFILES += *badnews*
## same-name.test
DISTCLEANFILES += same-name.out
## test-dvips
EXTRA_DIST += testdata/dvipstst.tex testdata/dvipstst.xdv testdata/dvipstst.xps
DISTCLEANFILES += dvipstst.ps missfont.log mtest.ps
## test-overflow-buffers
EXTRA_DIST += overflow-color-push.dvi overflow-color-push.tex \
              overflow-epsfile.dvi overflow-epsfile.tex \
              overflow-psbox.dvi overflow-psbox.tex
DISTCLEANFILES += overflow-color-push.ps overflow-epsfile.ps overflow-psbox.ps

EXTRA_DIST += \
	NEWS \
	TODO \
	testdata/intoverflow.dvi \
	testdata/vfnameoverflow.dvi

## Not used
##
EXTRA_DIST += \
	atari \
	cmfonts.map \
	config.ps \
	contrib/afm-extra \
	contrib/colorsep.lpro \
	contrib/configs \
	contrib/crop.lpr \
	contrib/latex209 \
	contrib/treen.sh \
	contrib/treen2.sh \
	contrib/volker \
	contrib/whichinpath \
	cyrfonts.map \
	eufonts.map \
	flib.c \
	hps/CHANGES_HPS.txt \
	hps/README_HPS.txt \
	lafonts.map \
	makefont.c \
	mvs \
	psfonts.map \
	tex \
	vmcms \
	vms

# Files not to be distributed
include $(srcdir)/../../am/dist_hook.am
