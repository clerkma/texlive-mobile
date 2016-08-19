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
# for libz
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

GMP_ROOT     := ../src/texlive-upstream/libs/gmp
GMP_INCLUDES := \
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/gmp-src\
$(LOCAL_PATH)/../src/texlive-upstream/libs/gmp/gmp-src/mpn/generic
GMP_FILES := \
$(GMP_ROOT)/gmp-src/assert.c \
$(GMP_ROOT)/gmp-src/compat.c \
$(GMP_ROOT)/gmp-src/errno.c \
$(GMP_ROOT)/gmp-src/extract-dbl.c \
$(GMP_ROOT)/gmp-src/invalid.c \
$(GMP_ROOT)/gmp-src/memory.c \
$(GMP_ROOT)/gmp-src/mp_bpl.c \
$(GMP_ROOT)/gmp-src/mp_clz_tab.c \
$(GMP_ROOT)/gmp-src/mp_dv_tab.c \
$(GMP_ROOT)/gmp-src/mp_get_fns.c \
$(GMP_ROOT)/gmp-src/mp_minv_tab.c \
$(GMP_ROOT)/gmp-src/mp_set_fns.c \
$(GMP_ROOT)/gmp-src/nextprime.c \
$(GMP_ROOT)/gmp-src/primesieve.c \
$(GMP_ROOT)/gmp-src/tal-reent.c \
$(GMP_ROOT)/gmp-src/version.c \
$(GMP_ROOT)/mp_bases.c \
$(GMP_ROOT)/popcount.c \
$(GMP_ROOT)/gmp-src/mpn/generic/add.c \
$(GMP_ROOT)/gmp-src/mpn/generic/add_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/add_n.c \
$(GMP_ROOT)/gmp-src/mpn/generic/addmul_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/bdiv_dbm1c.c \
$(GMP_ROOT)/gmp-src/mpn/generic/bdiv_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/binvert.c \
$(GMP_ROOT)/gmp-src/mpn/generic/cmp.c \
$(GMP_ROOT)/gmp-src/mpn/generic/com.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dcpi1_bdiv_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dcpi1_bdiv_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dcpi1_div_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dcpi1_div_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dcpi1_divappr_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/div_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/div_qr_2n_pi1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/dive_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/divexact.c \
$(GMP_ROOT)/gmp-src/mpn/generic/divrem.c \
$(GMP_ROOT)/gmp-src/mpn/generic/divrem_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/divrem_2.c \
$(GMP_ROOT)/gmp-src/mpn/generic/gcd_subdiv_step.c \
$(GMP_ROOT)/gmp-src/mpn/generic/gcdext.c \
$(GMP_ROOT)/gmp-src/mpn/generic/gcdext_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/gcdext_lehmer.c \
$(GMP_ROOT)/gmp-src/mpn/generic/get_str.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd2.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd_appr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd_matrix.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd_reduce.c \
$(GMP_ROOT)/gmp-src/mpn/generic/hgcd_step.c \
$(GMP_ROOT)/gmp-src/mpn/generic/invertappr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/lshift.c \
$(GMP_ROOT)/gmp-src/mpn/generic/lshiftc.c \
$(GMP_ROOT)/gmp-src/mpn/generic/matrix22_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/matrix22_mul1_inverse_vector.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mu_bdiv_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mu_div_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mu_div_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mu_divappr_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mul_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mul_basecase.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mul_fft.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mul_n.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mullo_basecase.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mullo_n.c \
$(GMP_ROOT)/gmp-src/mpn/generic/mulmod_bnm1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/neg.c \
$(GMP_ROOT)/gmp-src/mpn/generic/nussbaumer_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/powlo.c \
$(GMP_ROOT)/gmp-src/mpn/generic/powm.c \
$(GMP_ROOT)/gmp-src/mpn/generic/pre_divrem_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/redc_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/redc_n.c \
$(GMP_ROOT)/gmp-src/mpn/generic/rshift.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sbpi1_bdiv_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sbpi1_bdiv_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sbpi1_div_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sbpi1_div_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sbpi1_divappr_q.c \
$(GMP_ROOT)/gmp-src/mpn/generic/scan1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/set_str.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqr_basecase.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqrlo.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqrlo_basecase.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqrmod_bnm1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sqrtrem.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sub.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sub_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/sub_n.c \
$(GMP_ROOT)/gmp-src/mpn/generic/submul_1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/tdiv_qr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom22_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom2_sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom32_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom33_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom3_sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom42_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom42_mulmid.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom43_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom44_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom4_sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom53_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom63_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom6_sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom6h_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom8_sqr.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom8h_mul.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_couple_handling.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_dgr3_pm1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_dgr3_pm2.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_pm1.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_pm2.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_pm2exp.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_eval_pm2rexp.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_12pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_16pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_5pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_6pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_7pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/toom_interpolate_8pts.c \
$(GMP_ROOT)/gmp-src/mpn/generic/zero_p.c \
$(GMP_ROOT)/gmp-src/mpz/abs.c \
$(GMP_ROOT)/gmp-src/mpz/add.c \
$(GMP_ROOT)/gmp-src/mpz/add_ui.c \
$(GMP_ROOT)/gmp-src/mpz/aorsmul.c \
$(GMP_ROOT)/gmp-src/mpz/aorsmul_i.c \
$(GMP_ROOT)/gmp-src/mpz/cfdiv_q_2exp.c \
$(GMP_ROOT)/gmp-src/mpz/clear.c \
$(GMP_ROOT)/gmp-src/mpz/cmp_ui.c \
$(GMP_ROOT)/gmp-src/mpz/cmpabs.c \
$(GMP_ROOT)/gmp-src/mpz/divexact.c \
$(GMP_ROOT)/gmp-src/mpz/fdiv_q.c \
$(GMP_ROOT)/gmp-src/mpz/fdiv_q_ui.c \
$(GMP_ROOT)/gmp-src/mpz/fdiv_qr.c \
$(GMP_ROOT)/gmp-src/mpz/gcdext.c \
$(GMP_ROOT)/gmp-src/mpz/get_si.c \
$(GMP_ROOT)/gmp-src/mpz/init.c \
$(GMP_ROOT)/gmp-src/mpz/invert.c \
$(GMP_ROOT)/gmp-src/mpz/iset.c \
$(GMP_ROOT)/gmp-src/mpz/iset_ui.c \
$(GMP_ROOT)/gmp-src/mpz/mod.c \
$(GMP_ROOT)/gmp-src/mpz/mul.c \
$(GMP_ROOT)/gmp-src/mpz/mul_2exp.c \
$(GMP_ROOT)/gmp-src/mpz/mul_si.c \
$(GMP_ROOT)/gmp-src/mpz/mul_ui.c \
$(GMP_ROOT)/gmp-src/mpz/n_pow_ui.c \
$(GMP_ROOT)/gmp-src/mpz/neg.c \
$(GMP_ROOT)/gmp-src/mpz/powm.c \
$(GMP_ROOT)/gmp-src/mpz/powm_ui.c \
$(GMP_ROOT)/gmp-src/mpz/realloc.c \
$(GMP_ROOT)/gmp-src/mpz/scan1.c \
$(GMP_ROOT)/gmp-src/mpz/set.c \
$(GMP_ROOT)/gmp-src/mpz/size.c \
$(GMP_ROOT)/gmp-src/mpz/set_ui.c \
$(GMP_ROOT)/gmp-src/mpz/sizeinbase.c \
$(GMP_ROOT)/gmp-src/mpz/sqrt.c \
$(GMP_ROOT)/gmp-src/mpz/sub.c \
$(GMP_ROOT)/gmp-src/mpz/sub_ui.c \
$(GMP_ROOT)/gmp-src/mpz/swap.c \
$(GMP_ROOT)/gmp-src/mpz/tdiv_q.c \
$(GMP_ROOT)/gmp-src/mpz/tdiv_q_2exp.c \
$(GMP_ROOT)/gmp-src/mpz/tdiv_qr.c \
$(GMP_ROOT)/gmp-src/mpz/tdiv_r.c \
$(GMP_ROOT)/gmp-src/mpz/tdiv_r_2exp.c \
$(GMP_ROOT)/gmp-src/mpz/tstbit.c \
$(GMP_ROOT)/gmp-src/mpz/ui_pow_ui.c
LOCAL_ARM_NEON   := false
LOCAL_MODULE     := libgmp
LOCAL_CFLAGS     := \
-pie -fPIE \
-DHAVE_CONFIG_H -DNO_ASM -fvisibility=hidden -O2
LOCAL_C_INCLUDES := $(GMP_INCLUDES)
LOCAL_SRC_FILES  := $(GMP_FILES)

include $(BUILD_STATIC_LIBRARY)
