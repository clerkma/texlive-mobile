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
$(POPPLER_PATH)/poppler-src/goo/gfile.cc \
$(POPPLER_PATH)/poppler-src/goo/glibc.cc \
$(POPPLER_PATH)/poppler-src/goo/gmem.cc \
$(POPPLER_PATH)/poppler-src/goo/gmempp.cc \
$(POPPLER_PATH)/poppler-src/goo/grandom.cc \
$(POPPLER_PATH)/poppler-src/goo/gstrtod.cc \
$(POPPLER_PATH)/poppler-src/goo/FixedPoint.cc \
$(POPPLER_PATH)/poppler-src/goo/GooHash.cc \
$(POPPLER_PATH)/poppler-src/goo/GooList.cc \
$(POPPLER_PATH)/poppler-src/goo/GooString.cc \
$(POPPLER_PATH)/poppler-src/goo/GooTimer.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiBase.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiEncodings.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiIdentifier.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiTrueType.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiType1.cc \
$(POPPLER_PATH)/poppler-src/fofi/FoFiType1C.cc \
$(POPPLER_PATH)/poppler-src/poppler/Annot.cc \
$(POPPLER_PATH)/poppler-src/poppler/Array.cc \
$(POPPLER_PATH)/poppler-src/poppler/BuiltinFont.cc \
$(POPPLER_PATH)/poppler-src/poppler/BuiltinFontTables.cc \
$(POPPLER_PATH)/poppler-src/poppler/CMap.cc \
$(POPPLER_PATH)/poppler-src/poppler/CachedFile.cc \
$(POPPLER_PATH)/poppler-src/poppler/Catalog.cc \
$(POPPLER_PATH)/poppler-src/poppler/CharCodeToUnicode.cc \
$(POPPLER_PATH)/poppler-src/poppler/DateInfo.cc \
$(POPPLER_PATH)/poppler-src/poppler/Decrypt.cc \
$(POPPLER_PATH)/poppler-src/poppler/Dict.cc \
$(POPPLER_PATH)/poppler-src/poppler/Error.cc \
$(POPPLER_PATH)/poppler-src/poppler/FileSpec.cc \
$(POPPLER_PATH)/poppler-src/poppler/FlateStream.cc \
$(POPPLER_PATH)/poppler-src/poppler/FontEncodingTables.cc \
$(POPPLER_PATH)/poppler-src/poppler/FontInfo.cc \
$(POPPLER_PATH)/poppler-src/poppler/Form.cc \
$(POPPLER_PATH)/poppler-src/poppler/Function.cc \
$(POPPLER_PATH)/poppler-src/poppler/Gfx.cc \
$(POPPLER_PATH)/poppler-src/poppler/GfxFont.cc \
$(POPPLER_PATH)/poppler-src/poppler/GfxState.cc \
$(POPPLER_PATH)/poppler-src/poppler/GlobalParams.cc \
$(POPPLER_PATH)/poppler-src/poppler/Hints.cc \
$(POPPLER_PATH)/poppler-src/poppler/JArithmeticDecoder.cc \
$(POPPLER_PATH)/poppler-src/poppler/JBIG2Stream.cc \
$(POPPLER_PATH)/poppler-src/poppler/JPXStream.cc \
$(POPPLER_PATH)/poppler-src/poppler/Lexer.cc \
$(POPPLER_PATH)/poppler-src/poppler/Linearization.cc \
$(POPPLER_PATH)/poppler-src/poppler/Link.cc \
$(POPPLER_PATH)/poppler-src/poppler/MarkedContentOutputDev.cc \
$(POPPLER_PATH)/poppler-src/poppler/Movie.cc \
$(POPPLER_PATH)/poppler-src/poppler/NameToCharCode.cc \
$(POPPLER_PATH)/poppler-src/poppler/Object.cc \
$(POPPLER_PATH)/poppler-src/poppler/OptionalContent.cc \
$(POPPLER_PATH)/poppler-src/poppler/Outline.cc \
$(POPPLER_PATH)/poppler-src/poppler/OutputDev.cc \
$(POPPLER_PATH)/poppler-src/poppler/PDFDoc.cc \
$(POPPLER_PATH)/poppler-src/poppler/PDFDocEncoding.cc \
$(POPPLER_PATH)/poppler-src/poppler/PDFDocFactory.cc \
$(POPPLER_PATH)/poppler-src/poppler/PSTokenizer.cc \
$(POPPLER_PATH)/poppler-src/poppler/Page.cc \
$(POPPLER_PATH)/poppler-src/poppler/PageLabelInfo.cc \
$(POPPLER_PATH)/poppler-src/poppler/PageTransition.cc \
$(POPPLER_PATH)/poppler-src/poppler/Parser.cc \
$(POPPLER_PATH)/poppler-src/poppler/PopplerCache.cc \
$(POPPLER_PATH)/poppler-src/poppler/PreScanOutputDev.cc \
$(POPPLER_PATH)/poppler-src/poppler/ProfileData.cc \
$(POPPLER_PATH)/poppler-src/poppler/Rendition.cc \
$(POPPLER_PATH)/poppler-src/poppler/SecurityHandler.cc \
$(POPPLER_PATH)/poppler-src/poppler/SignatureInfo.cc \
$(POPPLER_PATH)/poppler-src/poppler/Sound.cc \
$(POPPLER_PATH)/poppler-src/poppler/StdinCachedFile.cc \
$(POPPLER_PATH)/poppler-src/poppler/StdinPDFDocBuilder.cc \
$(POPPLER_PATH)/poppler-src/poppler/Stream.cc \
$(POPPLER_PATH)/poppler-src/poppler/StructElement.cc \
$(POPPLER_PATH)/poppler-src/poppler/StructTreeRoot.cc \
$(POPPLER_PATH)/poppler-src/poppler/UTF.cc \
$(POPPLER_PATH)/poppler-src/poppler/UnicodeMap.cc \
$(POPPLER_PATH)/poppler-src/poppler/UnicodeTypeTable.cc \
$(POPPLER_PATH)/poppler-src/poppler/ViewerPreferences.cc \
$(POPPLER_PATH)/poppler-src/poppler/XRef.cc \
$(POPPLER_PATH)/poppler-src/poppler/XpdfPluginAPI.cc \
$(POPPLER_PATH)/poppler-src/poppler/strtok_r.cc 

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libpoppler
LOCAL_CFLAGS     := -O2 -DHAVE_CONFIG_H -DPOPPLER_DATADIR='"."'
LOCAL_C_INCLUDES := $(POPPLER_INCLUDES)
LOCAL_SRC_FILES  := $(POPPLER_FILES)

include $(BUILD_STATIC_LIBRARY)
