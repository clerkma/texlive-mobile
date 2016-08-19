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

# for libexpat
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

EXPAT_ROOT     := ../src/expat-2.2.0/
EXPAT_INCLUDES := \
$(LOCAL_PATH)/../src/expat-2.2.0/\
$(LOCAL_PATH)/../src/expat-2.2.0/lib
EXPAT_FILES := \
$(EXPAT_ROOT)/lib/xmlparse.c \
$(EXPAT_ROOT)/lib/xmltok.c \
$(EXPAT_ROOT)/lib/xmlrole.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libexpat
LOCAL_CFLAGS     := -DHAVE_EXPAT_CONFIG_H -O2
LOCAL_C_INCLUDES := $(EXPAT_INCLUDES)
LOCAL_SRC_FILES  := $(EXPAT_FILES)

include $(BUILD_STATIC_LIBRARY)

#for libexpat/xmlwf
include $(CLEAR_VARS)

PROG_ROOT     := ../src/expat-2.2.0/
PROG_INCLUDES := \
$(LOCAL_PATH)/../src/expat-2.2.0/\
$(LOCAL_PATH)/../src/expat-2.2.0/lib
PROG_FILES :=\
$(PROG_ROOT)/xmlwf/xmlwf.c \
$(PROG_ROOT)/xmlwf/xmlfile.c \
$(PROG_ROOT)/xmlwf/codepage.c \
$(PROG_ROOT)/xmlwf/unixfilemap.c
LOCAL_ARM_NEON   := false
LOCAL_STATIC_LIBRARIES  := libexpat
LOCAL_MODULE     := xmlwf
LOCAL_LDLIBS     := -s -lm
LOCAL_CFLAGS     := \
-pie -fPIE \
-DHAVE_EXPAT_CONFIG_H \
-Wimplicit -Wreturn-type -Wdeclaration-after-statement -Wno-unknown-pragmas -O2
LOCAL_C_INCLUDES := $(PROG_INCLUDES)
LOCAL_SRC_FILES  := $(PROG_FILES)

include $(BUILD_EXECUTABLE)
