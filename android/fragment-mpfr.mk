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

MPFR_ROOT     := ../src/texlive-upstream/libs/mpfr
MPFR_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/mpfr\
$(LOCAL_PATH)/../src/texlive-upstream/libs/mpfr/mpfr-src/src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/include
MPFR_FILES := \
$(MPFR_ROOT)/mpfr-src/src/abort_prec_max.c \
$(MPFR_ROOT)/mpfr-src/src/add.c \
$(MPFR_ROOT)/mpfr-src/src/add1.c \
$(MPFR_ROOT)/mpfr-src/src/add1sp.c \
$(MPFR_ROOT)/mpfr-src/src/add_d.c \
$(MPFR_ROOT)/mpfr-src/src/add_ui.c \
$(MPFR_ROOT)/mpfr-src/src/agm.c \
$(MPFR_ROOT)/mpfr-src/src/atan.c \
$(MPFR_ROOT)/mpfr-src/src/atan2.c \
$(MPFR_ROOT)/mpfr-src/src/cache.c \
$(MPFR_ROOT)/mpfr-src/src/clear.c \
$(MPFR_ROOT)/mpfr-src/src/clears.c \
$(MPFR_ROOT)/mpfr-src/src/cmp.c \
$(MPFR_ROOT)/mpfr-src/src/cmp2.c \
$(MPFR_ROOT)/mpfr-src/src/cmp_abs.c \
$(MPFR_ROOT)/mpfr-src/src/cmp_si.c \
$(MPFR_ROOT)/mpfr-src/src/cmp_ui.c \
$(MPFR_ROOT)/mpfr-src/src/comparisons.c \
$(MPFR_ROOT)/mpfr-src/src/const_catalan.c \
$(MPFR_ROOT)/mpfr-src/src/const_euler.c \
$(MPFR_ROOT)/mpfr-src/src/const_log2.c \
$(MPFR_ROOT)/mpfr-src/src/const_pi.c \
$(MPFR_ROOT)/mpfr-src/src/constant.c \
$(MPFR_ROOT)/mpfr-src/src/cos.c \
$(MPFR_ROOT)/mpfr-src/src/div.c \
$(MPFR_ROOT)/mpfr-src/src/div_2si.c \
$(MPFR_ROOT)/mpfr-src/src/div_2ui.c \
$(MPFR_ROOT)/mpfr-src/src/div_ui.c \
$(MPFR_ROOT)/mpfr-src/src/exceptions.c \
$(MPFR_ROOT)/mpfr-src/src/exp.c \
$(MPFR_ROOT)/mpfr-src/src/exp2.c \
$(MPFR_ROOT)/mpfr-src/src/exp3.c \
$(MPFR_ROOT)/mpfr-src/src/exp_2.c \
$(MPFR_ROOT)/mpfr-src/src/extract.c \
$(MPFR_ROOT)/mpfr-src/src/fits_sint.c \
$(MPFR_ROOT)/mpfr-src/src/fits_slong.c \
$(MPFR_ROOT)/mpfr-src/src/free_cache.c \
$(MPFR_ROOT)/mpfr-src/src/get_d.c \
$(MPFR_ROOT)/mpfr-src/src/get_si.c \
$(MPFR_ROOT)/mpfr-src/src/get_str.c \
$(MPFR_ROOT)/mpfr-src/src/get_z.c \
$(MPFR_ROOT)/mpfr-src/src/get_z_exp.c \
$(MPFR_ROOT)/mpfr-src/src/gmp_op.c \
$(MPFR_ROOT)/mpfr-src/src/init.c \
$(MPFR_ROOT)/mpfr-src/src/init2.c \
$(MPFR_ROOT)/mpfr-src/src/inits2.c \
$(MPFR_ROOT)/mpfr-src/src/isinteger.c \
$(MPFR_ROOT)/mpfr-src/src/isnum.c \
$(MPFR_ROOT)/mpfr-src/src/isqrt.c \
$(MPFR_ROOT)/mpfr-src/src/log.c \
$(MPFR_ROOT)/mpfr-src/src/mpfr-gmp.c \
$(MPFR_ROOT)/mpfr-src/src/mpn_exp.c \
$(MPFR_ROOT)/mpfr-src/src/mp_clz_tab.c \
$(MPFR_ROOT)/mpfr-src/src/mul.c \
$(MPFR_ROOT)/mpfr-src/src/mul_2si.c \
$(MPFR_ROOT)/mpfr-src/src/mul_2ui.c \
$(MPFR_ROOT)/mpfr-src/src/mul_ui.c \
$(MPFR_ROOT)/mpfr-src/src/mulders.c \
$(MPFR_ROOT)/mpfr-src/src/neg.c \
$(MPFR_ROOT)/mpfr-src/src/next.c \
$(MPFR_ROOT)/mpfr-src/src/powerof2.c \
$(MPFR_ROOT)/mpfr-src/src/rem1.c \
$(MPFR_ROOT)/mpfr-src/src/rint.c \
$(MPFR_ROOT)/mpfr-src/src/round_near_x.c \
$(MPFR_ROOT)/mpfr-src/src/round_p.c \
$(MPFR_ROOT)/mpfr-src/src/round_prec.c \
$(MPFR_ROOT)/mpfr-src/src/scale2.c \
$(MPFR_ROOT)/mpfr-src/src/set.c \
$(MPFR_ROOT)/mpfr-src/src/set_d.c \
$(MPFR_ROOT)/mpfr-src/src/set_dfl_prec.c \
$(MPFR_ROOT)/mpfr-src/src/set_f.c \
$(MPFR_ROOT)/mpfr-src/src/set_prec.c \
$(MPFR_ROOT)/mpfr-src/src/set_q.c \
$(MPFR_ROOT)/mpfr-src/src/set_rnd.c \
$(MPFR_ROOT)/mpfr-src/src/set_si_2exp.c \
$(MPFR_ROOT)/mpfr-src/src/set_str.c \
$(MPFR_ROOT)/mpfr-src/src/set_ui_2exp.c \
$(MPFR_ROOT)/mpfr-src/src/set_z.c \
$(MPFR_ROOT)/mpfr-src/src/set_z_exp.c \
$(MPFR_ROOT)/mpfr-src/src/set_zero.c \
$(MPFR_ROOT)/mpfr-src/src/setmax.c \
$(MPFR_ROOT)/mpfr-src/src/setmin.c \
$(MPFR_ROOT)/mpfr-src/src/sgn.c \
$(MPFR_ROOT)/mpfr-src/src/sin.c \
$(MPFR_ROOT)/mpfr-src/src/sin_cos.c \
$(MPFR_ROOT)/mpfr-src/src/sqr.c \
$(MPFR_ROOT)/mpfr-src/src/sqrt.c \
$(MPFR_ROOT)/mpfr-src/src/sqrt_ui.c \
$(MPFR_ROOT)/mpfr-src/src/strtofr.c \
$(MPFR_ROOT)/mpfr-src/src/sub.c \
$(MPFR_ROOT)/mpfr-src/src/sub1.c \
$(MPFR_ROOT)/mpfr-src/src/sub1sp.c \
$(MPFR_ROOT)/mpfr-src/src/sub_ui.c \
$(MPFR_ROOT)/mpfr-src/src/swap.c \
$(MPFR_ROOT)/mpfr-src/src/ui_div.c \
$(MPFR_ROOT)/mpfr-src/src/ui_sub.c \
$(MPFR_ROOT)/mpfr-src/src/version.c

LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libmpfr
LOCAL_CFLAGS     := -O2 -DHAVE_CONFIG_H -DNO_ASM
LOCAL_C_INCLUDES := $(MPFR_INCLUDES)
LOCAL_SRC_FILES  := $(MPFR_FILES)

include $(BUILD_STATIC_LIBRARY)
