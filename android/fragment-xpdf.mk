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

# for xpdf
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

XPDF_ROOT     := ../src/texlive-upstream/libs/xpdf
XPDF_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/ \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/fofi \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/splash \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf-src/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf-src/fofi \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf-src/splash \
$(LOCAL_PATH)/../src/texlive-upstream/libs/xpdf/xpdf-src/xpdf
XPDF_FILES := \
$(XPDF_ROOT)/xpdf-src/goo/FixedPoint.cc \
$(XPDF_ROOT)/xpdf-src/goo/GHash.cc \
$(XPDF_ROOT)/xpdf-src/goo/GList.cc \
$(XPDF_ROOT)/xpdf-src/goo/GString.cc \
$(XPDF_ROOT)/xpdf-src/goo/gfile.cc \
$(XPDF_ROOT)/xpdf-src/goo/gmem.cc \
$(XPDF_ROOT)/xpdf-src/goo/gmempp.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiBase.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiEncodings.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiIdentifier.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiTrueType.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiType1.cc \
$(XPDF_ROOT)/xpdf-src/fofi/FoFiType1C.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/AcroForm.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Annot.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Array.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/BuiltinFont.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/BuiltinFontTables.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/CMap.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Catalog.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/CharCodeToUnicode.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Decrypt.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Dict.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Error.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/FontEncodingTables.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Form.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Function.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Gfx.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/GfxFont.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/GfxState.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/GlobalParams.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/JArithmeticDecoder.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/JBIG2Stream.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/JPXStream.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Lexer.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Link.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/NameToCharCode.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Object.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/OptionalContent.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Outline.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/OutputDev.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/PDFDoc.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/PDFDocEncoding.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/PSTokenizer.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Page.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Parser.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/SecurityHandler.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Stream.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/TextString.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/UnicodeMap.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/XFAForm.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/XRef.cc \
$(XPDF_ROOT)/xpdf-src/xpdf/Zoox.cc

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libxpdf
LOCAL_CFLAGS     := -pie -fPIE -O2 -DHAVE_CONFIG_H -DPDF_PARSER_ONLY
LOCAL_C_INCLUDES := $(XPDF_INCLUDES)
LOCAL_SRC_FILES  := $(XPDF_FILES)

include $(BUILD_STATIC_LIBRARY)
