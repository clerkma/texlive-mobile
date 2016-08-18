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

# libicudata
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

ICU_ROOT     := ../src/texlive-upstream/libs/icu/
ICU_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include
ICU_FILES := \
$(ICU_ROOT)/icu-src/source/stubdata/stubdata.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libicudata
LOCAL_CFLAGS     := -O2
LOCAL_C_INCLUDES := $(ICU_INCLUDES)
LOCAL_SRC_FILES  := $(ICU_FILES)

include $(BUILD_STATIC_LIBRARY)

# libicuuc
include $(CLEAR_VARS)

ICU_ROOT     := ../src/texlive-upstream/libs/icu/
ICU_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include
ICU_FILES := \
$(ICU_ROOT)/icu-src/source/common/pluralmap.cpp \
$(ICU_ROOT)/icu-src/source/common/uloc_keytype.cpp \
$(ICU_ROOT)/icu-src/source/common/unifiedcache.cpp \
$(ICU_ROOT)/icu-src/source/common/simpleformatter.cpp \
$(ICU_ROOT)/icu-src/source/common/sharedobject.cpp \
$(ICU_ROOT)/icu-src/source/common/ulistformatter.cpp \
$(ICU_ROOT)/icu-src/source/common/listformatter.cpp \
$(ICU_ROOT)/icu-src/source/common/icuplug.cpp \
$(ICU_ROOT)/icu-src/source/common/icudataver.c \
$(ICU_ROOT)/icu-src/source/common/uloc_tag.c \
$(ICU_ROOT)/icu-src/source/common/ulist.c \
$(ICU_ROOT)/icu-src/source/common/propsvec.c \
$(ICU_ROOT)/icu-src/source/common/ucnvsel.cpp \
$(ICU_ROOT)/icu-src/source/common/dtintrv.cpp \
$(ICU_ROOT)/icu-src/source/common/wintz.c \
$(ICU_ROOT)/icu-src/source/common/cwchar.c \
$(ICU_ROOT)/icu-src/source/common/locbased.cpp \
$(ICU_ROOT)/icu-src/source/common/parsepos.cpp \
$(ICU_ROOT)/icu-src/source/common/util_props.cpp \
$(ICU_ROOT)/icu-src/source/common/util.cpp \
$(ICU_ROOT)/icu-src/source/common/punycode.cpp \
$(ICU_ROOT)/icu-src/source/common/uts46.cpp \
$(ICU_ROOT)/icu-src/source/common/usprep.cpp \
$(ICU_ROOT)/icu-src/source/common/uidna.cpp \
$(ICU_ROOT)/icu-src/source/common/servslkf.cpp \
$(ICU_ROOT)/icu-src/source/common/servrbf.cpp \
$(ICU_ROOT)/icu-src/source/common/servlkf.cpp \
$(ICU_ROOT)/icu-src/source/common/servlk.cpp \
$(ICU_ROOT)/icu-src/source/common/servls.cpp \
$(ICU_ROOT)/icu-src/source/common/servnotf.cpp \
$(ICU_ROOT)/icu-src/source/common/serv.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbitblb.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbistbl.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbisetb.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbiscan.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbirb.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbinode.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbidata.cpp \
$(ICU_ROOT)/icu-src/source/common/rbbi.cpp \
$(ICU_ROOT)/icu-src/source/common/filteredbrk.cpp \
$(ICU_ROOT)/icu-src/source/common/dictbe.cpp \
$(ICU_ROOT)/icu-src/source/common/brkeng.cpp \
$(ICU_ROOT)/icu-src/source/common/ubrk.cpp \
$(ICU_ROOT)/icu-src/source/common/brkiter.cpp \
$(ICU_ROOT)/icu-src/source/common/uarrsort.c \
$(ICU_ROOT)/icu-src/source/common/unifunct.cpp \
$(ICU_ROOT)/icu-src/source/common/unifilt.cpp \
$(ICU_ROOT)/icu-src/source/common/caniter.cpp \
$(ICU_ROOT)/icu-src/source/common/ruleiter.cpp \
$(ICU_ROOT)/icu-src/source/common/usetiter.cpp \
$(ICU_ROOT)/icu-src/source/common/uniset.cpp \
$(ICU_ROOT)/icu-src/source/common/uset.cpp \
$(ICU_ROOT)/icu-src/source/common/uniset_closure.cpp \
$(ICU_ROOT)/icu-src/source/common/uniset_props.cpp \
$(ICU_ROOT)/icu-src/source/common/uset_props.cpp \
$(ICU_ROOT)/icu-src/source/common/unisetspan.cpp \
$(ICU_ROOT)/icu-src/source/common/bmpset.cpp \
$(ICU_ROOT)/icu-src/source/common/utrie2_builder.cpp \
$(ICU_ROOT)/icu-src/source/common/utrie2.cpp \
$(ICU_ROOT)/icu-src/source/common/utrie.cpp \
$(ICU_ROOT)/icu-src/source/common/unames.cpp \
$(ICU_ROOT)/icu-src/source/common/usc_impl.c \
$(ICU_ROOT)/icu-src/source/common/uscript_props.cpp \
$(ICU_ROOT)/icu-src/source/common/uscript.c \
$(ICU_ROOT)/icu-src/source/common/ushape.cpp \
$(ICU_ROOT)/icu-src/source/common/ubidiln.c \
$(ICU_ROOT)/icu-src/source/common/ubidiwrt.c \
$(ICU_ROOT)/icu-src/source/common/ubidi.c \
$(ICU_ROOT)/icu-src/source/common/ubidi_props.c \
$(ICU_ROOT)/icu-src/source/common/propname.cpp \
$(ICU_ROOT)/icu-src/source/common/ucase.cpp \
$(ICU_ROOT)/icu-src/source/common/uprops.cpp \
$(ICU_ROOT)/icu-src/source/common/uchar.c \
$(ICU_ROOT)/icu-src/source/common/patternprops.cpp \
$(ICU_ROOT)/icu-src/source/common/uiter.cpp \
$(ICU_ROOT)/icu-src/source/common/uchriter.cpp \
$(ICU_ROOT)/icu-src/source/common/schriter.cpp \
$(ICU_ROOT)/icu-src/source/common/chariter.cpp \
$(ICU_ROOT)/icu-src/source/common/loadednormalizer2impl.cpp \
$(ICU_ROOT)/icu-src/source/common/unormcmp.cpp \
$(ICU_ROOT)/icu-src/source/common/unorm.cpp \
$(ICU_ROOT)/icu-src/source/common/normlzr.cpp \
$(ICU_ROOT)/icu-src/source/common/filterednormalizer2.cpp \
$(ICU_ROOT)/icu-src/source/common/normalizer2.cpp \
$(ICU_ROOT)/icu-src/source/common/normalizer2impl.cpp \
$(ICU_ROOT)/icu-src/source/common/ustr_titlecase_brkiter.cpp \
$(ICU_ROOT)/icu-src/source/common/unistr_titlecase_brkiter.cpp \
$(ICU_ROOT)/icu-src/source/common/ustrcase_locale.cpp \
$(ICU_ROOT)/icu-src/source/common/unistr_case_locale.cpp \
$(ICU_ROOT)/icu-src/source/common/utext.cpp \
$(ICU_ROOT)/icu-src/source/common/ustr_wcs.cpp \
$(ICU_ROOT)/icu-src/source/common/ustrtrns.cpp \
$(ICU_ROOT)/icu-src/source/common/ustrfmt.c \
$(ICU_ROOT)/icu-src/source/common/cstring.c \
$(ICU_ROOT)/icu-src/source/common/ucasemap_titlecase_brkiter.cpp \
$(ICU_ROOT)/icu-src/source/common/ucasemap.cpp \
$(ICU_ROOT)/icu-src/source/common/ustrcase.cpp \
$(ICU_ROOT)/icu-src/source/common/ustring.cpp \
$(ICU_ROOT)/icu-src/source/common/utf_impl.c \
$(ICU_ROOT)/icu-src/source/common/unistr_props.cpp \
$(ICU_ROOT)/icu-src/source/common/unistr_case.cpp \
$(ICU_ROOT)/icu-src/source/common/unistr.cpp \
$(ICU_ROOT)/icu-src/source/common/unistr_cnv.cpp \
$(ICU_ROOT)/icu-src/source/common/ustr_cnv.cpp \
$(ICU_ROOT)/icu-src/source/common/appendable.cpp \
$(ICU_ROOT)/icu-src/source/common/dictionarydata.cpp \
$(ICU_ROOT)/icu-src/source/common/ucharstrieiterator.cpp \
$(ICU_ROOT)/icu-src/source/common/ucharstriebuilder.cpp \
$(ICU_ROOT)/icu-src/source/common/ucharstrie.cpp \
$(ICU_ROOT)/icu-src/source/common/bytestrieiterator.cpp \
$(ICU_ROOT)/icu-src/source/common/bytestrie.cpp \
$(ICU_ROOT)/icu-src/source/common/bytestriebuilder.cpp \
$(ICU_ROOT)/icu-src/source/common/stringtriebuilder.cpp \
$(ICU_ROOT)/icu-src/source/common/stringpiece.cpp \
$(ICU_ROOT)/icu-src/source/common/bytestream.cpp \
$(ICU_ROOT)/icu-src/source/common/locresdata.cpp \
$(ICU_ROOT)/icu-src/source/common/loclikely.cpp \
$(ICU_ROOT)/icu-src/source/common/locdspnm.cpp \
$(ICU_ROOT)/icu-src/source/common/locdispnames.cpp \
$(ICU_ROOT)/icu-src/source/common/locavailable.cpp \
$(ICU_ROOT)/icu-src/source/common/locutil.cpp \
$(ICU_ROOT)/icu-src/source/common/locid.cpp \
$(ICU_ROOT)/icu-src/source/common/uloc.cpp \
$(ICU_ROOT)/icu-src/source/common/locmap.c \
$(ICU_ROOT)/icu-src/source/common/ucat.c \
$(ICU_ROOT)/icu-src/source/common/messagepattern.cpp \
$(ICU_ROOT)/icu-src/source/common/ucurr.cpp \
$(ICU_ROOT)/icu-src/source/common/resbund_cnv.cpp \
$(ICU_ROOT)/icu-src/source/common/resbund.cpp \
$(ICU_ROOT)/icu-src/source/common/uresdata.cpp \
$(ICU_ROOT)/icu-src/source/common/ures_cnv.c \
$(ICU_ROOT)/icu-src/source/common/uresbund.cpp \
$(ICU_ROOT)/icu-src/source/common/resource.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnv_ct.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_set.c \
$(ICU_ROOT)/icu-src/source/common/ucnvdisp.c \
$(ICU_ROOT)/icu-src/source/common/ucnvisci.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_lmb.c \
$(ICU_ROOT)/icu-src/source/common/ucnvhz.c \
$(ICU_ROOT)/icu-src/source/common/ucnv2022.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnvmbcs.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnv_ext.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnvbocu.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnvscsu.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_u32.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_u16.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_u8.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_u7.c \
$(ICU_ROOT)/icu-src/source/common/ucnvlat1.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_err.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_cb.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_io.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnv_cnv.c \
$(ICU_ROOT)/icu-src/source/common/ucnv_bld.cpp \
$(ICU_ROOT)/icu-src/source/common/ucnv.c \
$(ICU_ROOT)/icu-src/source/common/uvectr64.cpp \
$(ICU_ROOT)/icu-src/source/common/uvectr32.cpp \
$(ICU_ROOT)/icu-src/source/common/ustack.cpp \
$(ICU_ROOT)/icu-src/source/common/uvector.cpp \
$(ICU_ROOT)/icu-src/source/common/ustrenum.cpp \
$(ICU_ROOT)/icu-src/source/common/uenum.c \
$(ICU_ROOT)/icu-src/source/common/uhash_us.cpp \
$(ICU_ROOT)/icu-src/source/common/uhash.c \
$(ICU_ROOT)/icu-src/source/common/utrace.c \
$(ICU_ROOT)/icu-src/source/common/ucol_swp.cpp \
$(ICU_ROOT)/icu-src/source/common/udataswp.c \
$(ICU_ROOT)/icu-src/source/common/umapfile.c \
$(ICU_ROOT)/icu-src/source/common/udatamem.c \
$(ICU_ROOT)/icu-src/source/common/ucmndata.c \
$(ICU_ROOT)/icu-src/source/common/udata.cpp \
$(ICU_ROOT)/icu-src/source/common/cstr.cpp \
$(ICU_ROOT)/icu-src/source/common/charstr.cpp \
$(ICU_ROOT)/icu-src/source/common/cmemory.c \
$(ICU_ROOT)/icu-src/source/common/uobject.cpp \
$(ICU_ROOT)/icu-src/source/common/uinit.cpp \
$(ICU_ROOT)/icu-src/source/common/ucln_cmn.cpp \
$(ICU_ROOT)/icu-src/source/common/umutex.cpp \
$(ICU_ROOT)/icu-src/source/common/uinvchar.c \
$(ICU_ROOT)/icu-src/source/common/utypes.c \
$(ICU_ROOT)/icu-src/source/common/umath.c \
$(ICU_ROOT)/icu-src/source/common/putil.cpp \
$(ICU_ROOT)/icu-src/source/common/errorcode.cpp
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libicuuc
LOCAL_CFLAGS     := -O2 -DU_COMMON_IMPLEMENTATION
LOCAL_C_INCLUDES := $(ICU_INCLUDES)
LOCAL_SRC_FILES  := $(ICU_FILES)

include $(BUILD_STATIC_LIBRARY)

# libicui18n
include $(CLEAR_VARS)

ICU_ROOT     := ../src/texlive-upstream/libs/icu/
ICU_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/icu-src/source/common
ICU_FILES := \
$(ICU_ROOT)/icu-src/source/i18n/dayperiodrules.cpp \
$(ICU_ROOT)/icu-src/source/i18n/visibledigits.cpp \
$(ICU_ROOT)/icu-src/source/i18n/decimfmtimpl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/smallintformatter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/affixpatternparser.cpp \
$(ICU_ROOT)/icu-src/source/i18n/precision.cpp \
$(ICU_ROOT)/icu-src/source/i18n/pluralaffix.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitaffixesandpadding.cpp \
$(ICU_ROOT)/icu-src/source/i18n/valueformatter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitaffix.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitformatter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitinterval.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitgrouping.cpp \
$(ICU_ROOT)/icu-src/source/i18n/scientificnumberformatter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/sharedbreakiterator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/measunit.cpp \
$(ICU_ROOT)/icu-src/source/i18n/quantityformatter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/reldatefmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uregion.cpp \
$(ICU_ROOT)/icu-src/source/i18n/identifier_info.cpp \
$(ICU_ROOT)/icu-src/source/i18n/scriptset.cpp \
$(ICU_ROOT)/icu-src/source/i18n/region.cpp \
$(ICU_ROOT)/icu-src/source/i18n/gender.cpp \
$(ICU_ROOT)/icu-src/source/i18n/compactdecimalformat.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tzfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tzgnames.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tznames_impl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tznames.cpp \
$(ICU_ROOT)/icu-src/source/i18n/alphaindex.cpp \
$(ICU_ROOT)/icu-src/source/i18n/decContext.c \
$(ICU_ROOT)/icu-src/source/i18n/decNumber.c \
$(ICU_ROOT)/icu-src/source/i18n/ufieldpositer.cpp \
$(ICU_ROOT)/icu-src/source/i18n/fpositer.cpp \
$(ICU_ROOT)/icu-src/source/i18n/fphdlimp.cpp \
$(ICU_ROOT)/icu-src/source/i18n/vzone.cpp \
$(ICU_ROOT)/icu-src/source/i18n/zrule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ztrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/smpdtfst.cpp \
$(ICU_ROOT)/icu-src/source/i18n/decfmtst.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uspoof_wsconf.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uspoof_conf.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uspoof_build.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uspoof_impl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uspoof.cpp \
$(ICU_ROOT)/icu-src/source/i18n/currpinf.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tmutfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tmutamt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tmunit.cpp \
$(ICU_ROOT)/icu-src/source/i18n/udateintervalformat.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dtitvinf.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dtitvfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/selfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/plurfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/plurrule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/upluralrules.cpp \
$(ICU_ROOT)/icu-src/source/i18n/standardplural.cpp \
$(ICU_ROOT)/icu-src/source/i18n/zonemeta.cpp \
$(ICU_ROOT)/icu-src/source/i18n/vtzone.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tztrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tzrule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbtz.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dtrule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/basictz.cpp \
$(ICU_ROOT)/icu-src/source/i18n/winnmfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/windtfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/wintzimpl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/inputext.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csrutf8.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csrucode.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csrsbcs.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csrmbcs.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csrecog.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csr2022.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csmatch.cpp \
$(ICU_ROOT)/icu-src/source/i18n/csdetect.cpp \
$(ICU_ROOT)/icu-src/source/i18n/utmscale.c \
$(ICU_ROOT)/icu-src/source/i18n/measure.cpp \
$(ICU_ROOT)/icu-src/source/i18n/currunit.cpp \
$(ICU_ROOT)/icu-src/source/i18n/curramt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/currfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/measfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ulocdata.c \
$(ICU_ROOT)/icu-src/source/i18n/uregexc.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uregex.cpp \
$(ICU_ROOT)/icu-src/source/i18n/regeximp.cpp \
$(ICU_ROOT)/icu-src/source/i18n/regextxt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/regexst.cpp \
$(ICU_ROOT)/icu-src/source/i18n/repattrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rematch.cpp \
$(ICU_ROOT)/icu-src/source/i18n/regexcmp.cpp \
$(ICU_ROOT)/icu-src/source/i18n/brktrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/transreg.cpp \
$(ICU_ROOT)/icu-src/source/i18n/quant.cpp \
$(ICU_ROOT)/icu-src/source/i18n/nortrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uni2name.cpp \
$(ICU_ROOT)/icu-src/source/i18n/name2uni.cpp \
$(ICU_ROOT)/icu-src/source/i18n/anytrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/toupptrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tolowtrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/titletrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/casetrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/remtrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/nultrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbt_set.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbt_rule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbt_pars.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbt_data.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/cpdtrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/tridpars.cpp \
$(ICU_ROOT)/icu-src/source/i18n/strrepl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/funcrepl.cpp \
$(ICU_ROOT)/icu-src/source/i18n/unesctrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/esctrn.cpp \
$(ICU_ROOT)/icu-src/source/i18n/utrans.cpp \
$(ICU_ROOT)/icu-src/source/i18n/translit.cpp \
$(ICU_ROOT)/icu-src/source/i18n/stsearch.cpp \
$(ICU_ROOT)/icu-src/source/i18n/search.cpp \
$(ICU_ROOT)/icu-src/source/i18n/usearch.cpp \
$(ICU_ROOT)/icu-src/source/i18n/strmatch.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationfastlatinbuilder.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationbuilder.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationruleparser.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationweights.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationdatabuilder.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationrootelements.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationroot.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rulebasedcollator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationkeys.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationfastlatin.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationcompare.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationsets.cpp \
$(ICU_ROOT)/icu-src/source/i18n/uitercollationiterator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/utf8collationiterator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/utf16collationiterator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationiterator.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationfcd.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationdatawriter.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationdatareader.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationtailoring.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationdata.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collationsettings.cpp \
$(ICU_ROOT)/icu-src/source/i18n/collation.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucol_sit.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucol_res.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucol.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucoleitr.cpp \
$(ICU_ROOT)/icu-src/source/i18n/bocsu.cpp \
$(ICU_ROOT)/icu-src/source/i18n/sortkey.cpp \
$(ICU_ROOT)/icu-src/source/i18n/coll.cpp \
$(ICU_ROOT)/icu-src/source/i18n/coleitr.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ethpccal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dangical.cpp \
$(ICU_ROOT)/icu-src/source/i18n/coptccal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/cecal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/chnsecal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/indiancal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/hebrwcal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/gregoimp.cpp \
$(ICU_ROOT)/icu-src/source/i18n/japancal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/islamcal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/persncal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/buddhcal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/taiwncal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/astro.cpp \
$(ICU_ROOT)/icu-src/source/i18n/olsontz.cpp \
$(ICU_ROOT)/icu-src/source/i18n/simpletz.cpp \
$(ICU_ROOT)/icu-src/source/i18n/timezone.cpp \
$(ICU_ROOT)/icu-src/source/i18n/gregocal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/calendar.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucal.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucsdet.cpp \
$(ICU_ROOT)/icu-src/source/i18n/unumsys.cpp \
$(ICU_ROOT)/icu-src/source/i18n/numsys.cpp \
$(ICU_ROOT)/icu-src/source/i18n/rbnf.cpp \
$(ICU_ROOT)/icu-src/source/i18n/nfsubs.cpp \
$(ICU_ROOT)/icu-src/source/i18n/nfrule.cpp \
$(ICU_ROOT)/icu-src/source/i18n/nfrs.cpp \
$(ICU_ROOT)/icu-src/source/i18n/udatpg.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dtptngen.cpp \
$(ICU_ROOT)/icu-src/source/i18n/udat.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dtfmtsym.cpp \
$(ICU_ROOT)/icu-src/source/i18n/reldtfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/smpdtfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/datefmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/choicfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/fmtable_cnv.cpp \
$(ICU_ROOT)/icu-src/source/i18n/digitlst.cpp \
$(ICU_ROOT)/icu-src/source/i18n/dcfmtsym.cpp \
$(ICU_ROOT)/icu-src/source/i18n/decimalformatpattern.cpp \
$(ICU_ROOT)/icu-src/source/i18n/decimfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/unum.cpp \
$(ICU_ROOT)/icu-src/source/i18n/numfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/umsg.cpp \
$(ICU_ROOT)/icu-src/source/i18n/msgfmt.cpp \
$(ICU_ROOT)/icu-src/source/i18n/format.cpp \
$(ICU_ROOT)/icu-src/source/i18n/fmtable.cpp \
$(ICU_ROOT)/icu-src/source/i18n/ucln_in.cpp
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libicui18n
LOCAL_CFLAGS     := -O2 -DU_I18N_IMPLEMENTATION 
LOCAL_C_INCLUDES := $(ICU_INCLUDES)
LOCAL_SRC_FILES  := $(ICU_FILES)

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

ICU_ROOT     := ../src/texlive-upstream/libs/icu/
ICU_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/include\
$(LOCAL_PATH)/../src/texlive-upstream/libs/icu/icu-src/source/common
ICU_FILES := \
$(ICU_ROOT)/icu-src/source/io/ucln_io.cpp \
$(ICU_ROOT)/icu-src/source/io/ustream.cpp \
$(ICU_ROOT)/icu-src/source/io/sscanf.c \
$(ICU_ROOT)/icu-src/source/io/sprintf.c \
$(ICU_ROOT)/icu-src/source/io/ustdio.c \
$(ICU_ROOT)/icu-src/source/io/uscanf_p.c \
$(ICU_ROOT)/icu-src/source/io/uscanf.c \
$(ICU_ROOT)/icu-src/source/io/uprntf_p.c \
$(ICU_ROOT)/icu-src/source/io/uprintf.cpp \
$(ICU_ROOT)/icu-src/source/io/ufmt_cmn.c \
$(ICU_ROOT)/icu-src/source/io/ufile.c \
$(ICU_ROOT)/icu-src/source/io/locbund.cpp
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libicuio
LOCAL_CFLAGS     := -O2 -DU_IO_IMPLEMENTATION
LOCAL_C_INCLUDES := $(ICU_INCLUDES)
LOCAL_SRC_FILES  := $(ICU_FILES)

include $(BUILD_STATIC_LIBRARY)
