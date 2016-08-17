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

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

POPPLER_ROOT     := ../src/texlive-upstream/libs/poppler
POPPLER_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/ \
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/poppler-src \
$(LOCAL_PATH)/../src/texlive-upstream/libs/poppler/poppler-src/goo \
$(LOCAL_PATH)/../src/texlive-upstream/libs/zlib/include
POPPLER_FILES := \
$(POPPLER_ROOT)/poppler-src/goo/gfile.cc \
$(POPPLER_ROOT)/poppler-src/goo/glibc.cc \
$(POPPLER_ROOT)/poppler-src/goo/gmem.cc \
$(POPPLER_ROOT)/poppler-src/goo/gmempp.cc \
$(POPPLER_ROOT)/poppler-src/goo/grandom.cc \
$(POPPLER_ROOT)/poppler-src/goo/gstrtod.cc \
$(POPPLER_ROOT)/poppler-src/goo/FixedPoint.cc \
$(POPPLER_ROOT)/poppler-src/goo/GooHash.cc \
$(POPPLER_ROOT)/poppler-src/goo/GooList.cc \
$(POPPLER_ROOT)/poppler-src/goo/GooString.cc \
$(POPPLER_ROOT)/poppler-src/goo/GooTimer.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiBase.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiEncodings.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiIdentifier.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiTrueType.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiType1.cc \
$(POPPLER_ROOT)/poppler-src/fofi/FoFiType1C.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Annot.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Array.cc \
$(POPPLER_ROOT)/poppler-src/poppler/BuiltinFont.cc \
$(POPPLER_ROOT)/poppler-src/poppler/BuiltinFontTables.cc \
$(POPPLER_ROOT)/poppler-src/poppler/CMap.cc \
$(POPPLER_ROOT)/poppler-src/poppler/CachedFile.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Catalog.cc \
$(POPPLER_ROOT)/poppler-src/poppler/CharCodeToUnicode.cc \
$(POPPLER_ROOT)/poppler-src/poppler/DateInfo.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Decrypt.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Dict.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Error.cc \
$(POPPLER_ROOT)/poppler-src/poppler/FileSpec.cc \
$(POPPLER_ROOT)/poppler-src/poppler/FlateStream.cc \
$(POPPLER_ROOT)/poppler-src/poppler/FontEncodingTables.cc \
$(POPPLER_ROOT)/poppler-src/poppler/FontInfo.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Form.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Function.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Gfx.cc \
$(POPPLER_ROOT)/poppler-src/poppler/GfxFont.cc \
$(POPPLER_ROOT)/poppler-src/poppler/GfxState.cc \
$(POPPLER_ROOT)/poppler-src/poppler/GlobalParams.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Hints.cc \
$(POPPLER_ROOT)/poppler-src/poppler/JArithmeticDecoder.cc \
$(POPPLER_ROOT)/poppler-src/poppler/JBIG2Stream.cc \
$(POPPLER_ROOT)/poppler-src/poppler/JPXStream.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Lexer.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Linearization.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Link.cc \
$(POPPLER_ROOT)/poppler-src/poppler/MarkedContentOutputDev.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Movie.cc \
$(POPPLER_ROOT)/poppler-src/poppler/NameToCharCode.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Object.cc \
$(POPPLER_ROOT)/poppler-src/poppler/OptionalContent.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Outline.cc \
$(POPPLER_ROOT)/poppler-src/poppler/OutputDev.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PDFDoc.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PDFDocEncoding.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PDFDocFactory.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PSTokenizer.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Page.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PageLabelInfo.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PageTransition.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Parser.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PopplerCache.cc \
$(POPPLER_ROOT)/poppler-src/poppler/PreScanOutputDev.cc \
$(POPPLER_ROOT)/poppler-src/poppler/ProfileData.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Rendition.cc \
$(POPPLER_ROOT)/poppler-src/poppler/SecurityHandler.cc \
$(POPPLER_ROOT)/poppler-src/poppler/SignatureInfo.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Sound.cc \
$(POPPLER_ROOT)/poppler-src/poppler/StdinCachedFile.cc \
$(POPPLER_ROOT)/poppler-src/poppler/StdinPDFDocBuilder.cc \
$(POPPLER_ROOT)/poppler-src/poppler/Stream.cc \
$(POPPLER_ROOT)/poppler-src/poppler/StructElement.cc \
$(POPPLER_ROOT)/poppler-src/poppler/StructTreeRoot.cc \
$(POPPLER_ROOT)/poppler-src/poppler/UTF.cc \
$(POPPLER_ROOT)/poppler-src/poppler/UnicodeMap.cc \
$(POPPLER_ROOT)/poppler-src/poppler/UnicodeTypeTable.cc \
$(POPPLER_ROOT)/poppler-src/poppler/ViewerPreferences.cc \
$(POPPLER_ROOT)/poppler-src/poppler/XRef.cc \
$(POPPLER_ROOT)/poppler-src/poppler/XpdfPluginAPI.cc \
$(POPPLER_ROOT)/poppler-src/poppler/strtok_r.cpp

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpoppler
LOCAL_CFLAGS     := -O2 -DHAVE_CONFIG_H -DPOPPLER_DATADIR='"."'
LOCAL_C_INCLUDES := $(POPPLER_INCLUDES)
LOCAL_SRC_FILES  := $(POPPLER_FILES)

include $(BUILD_STATIC_LIBRARY)
