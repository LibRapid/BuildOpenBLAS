/*********************************************************************/
/* Copyright 2009, 2010 The University of Texas at Austin.           */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/*   1. Redistributions of source code must retain the above         */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer.                                                  */
/*                                                                   */
/*   2. Redistributions in binary form must reproduce the above      */
/*      copyright notice, this list of conditions and the following  */
/*      disclaimer in the documentation and/or other materials       */
/*      provided with the distribution.                              */
/*                                                                   */
/*    THIS  SOFTWARE IS PROVIDED  BY THE  UNIVERSITY OF  TEXAS AT    */
/*    AUSTIN  ``AS IS''  AND ANY  EXPRESS OR  IMPLIED WARRANTIES,    */
/*    INCLUDING, BUT  NOT LIMITED  TO, THE IMPLIED  WARRANTIES OF    */
/*    MERCHANTABILITY  AND FITNESS FOR  A PARTICULAR  PURPOSE ARE    */
/*    DISCLAIMED.  IN  NO EVENT SHALL THE UNIVERSITY  OF TEXAS AT    */
/*    AUSTIN OR CONTRIBUTORS BE  LIABLE FOR ANY DIRECT, INDIRECT,    */
/*    INCIDENTAL,  SPECIAL, EXEMPLARY,  OR  CONSEQUENTIAL DAMAGES    */
/*    (INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_CORE2;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*    (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#include <stdio.h>
#include <string.h>
#include "common.h"

#ifdef BUILD_KERNEL
#include "kernel_CORE2.h"
#endif

#undef DEBUG

static void init_parameter(void);

gotoblas_t TABLE_NAME = {
  DTB_DEFAULT_ENTRIES ,

  GEMM_DEFAULT_OFFSET_A, GEMM_DEFAULT_OFFSET_B, GEMM_DEFAULT_ALIGN,

#ifdef BUILD_BFLOAT16
  0, 0, 0,
  SBGEMM_DEFAULT_UNROLL_M, SBGEMM_DEFAULT_UNROLL_N,
#ifdef SBGEMM_DEFAULT_UNROLL_MN
 SBGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(SBGEMM_DEFAULT_UNROLL_M, SBGEMM_DEFAULT_UNROLL_N),
#endif

  SBGEMM_ALIGN_K,

  sbstobf16_k_CORE2, sbdtobf16_k_CORE2, sbf16tos_k_CORE2, dbf16tod_k_CORE2,

  samax_k_CORE2,  samin_k_CORE2,  smax_k_CORE2,  smin_k_CORE2,
  isamax_k_CORE2, isamin_k_CORE2, ismax_k_CORE2, ismin_k_CORE2,
  snrm2_k_CORE2,  sasum_k_CORE2, ssum_k_CORE2, scopy_k_CORE2, sbdot_k_CORE2,
  dsdot_k_CORE2,
  srot_k_CORE2,   saxpy_k_CORE2,  sscal_k_CORE2, sswap_k_CORE2,
  sbgemv_n_CORE2, sbgemv_t_CORE2, sger_k_CORE2,
  ssymv_L_CORE2, ssymv_U_CORE2,

  sbgemm_kernel_CORE2, sbgemm_beta_CORE2,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_CORE2, sbgemm_itcopy_CORE2,
#else
  sbgemm_oncopy_CORE2, sbgemm_otcopy_CORE2,
#endif
  sbgemm_oncopy_CORE2, sbgemm_otcopy_CORE2,

  strsm_kernel_LN_CORE2, strsm_kernel_LT_CORE2, strsm_kernel_RN_CORE2, strsm_kernel_RT_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_CORE2, strsm_iunncopy_CORE2, strsm_iutucopy_CORE2, strsm_iutncopy_CORE2,
  strsm_ilnucopy_CORE2, strsm_ilnncopy_CORE2, strsm_iltucopy_CORE2, strsm_iltncopy_CORE2,
#else
  strsm_ounucopy_CORE2, strsm_ounncopy_CORE2, strsm_outucopy_CORE2, strsm_outncopy_CORE2,
  strsm_olnucopy_CORE2, strsm_olnncopy_CORE2, strsm_oltucopy_CORE2, strsm_oltncopy_CORE2,
#endif
  strsm_ounucopy_CORE2, strsm_ounncopy_CORE2, strsm_outucopy_CORE2, strsm_outncopy_CORE2,
  strsm_olnucopy_CORE2, strsm_olnncopy_CORE2, strsm_oltucopy_CORE2, strsm_oltncopy_CORE2,
  strmm_kernel_RN_CORE2, strmm_kernel_RT_CORE2, strmm_kernel_LN_CORE2, strmm_kernel_LT_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_CORE2, strmm_iunncopy_CORE2, strmm_iutucopy_CORE2, strmm_iutncopy_CORE2,
  strmm_ilnucopy_CORE2, strmm_ilnncopy_CORE2, strmm_iltucopy_CORE2, strmm_iltncopy_CORE2,
#else
  strmm_ounucopy_CORE2, strmm_ounncopy_CORE2, strmm_outucopy_CORE2, strmm_outncopy_CORE2,
  strmm_olnucopy_CORE2, strmm_olnncopy_CORE2, strmm_oltucopy_CORE2, strmm_oltncopy_CORE2,
#endif
  strmm_ounucopy_CORE2, strmm_ounncopy_CORE2, strmm_outucopy_CORE2, strmm_outncopy_CORE2,
  strmm_olnucopy_CORE2, strmm_olnncopy_CORE2, strmm_oltucopy_CORE2, strmm_oltncopy_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_CORE2, ssymm_iltcopy_CORE2,
#else
  ssymm_outcopy_CORE2, ssymm_oltcopy_CORE2,
#endif
  ssymm_outcopy_CORE2, ssymm_oltcopy_CORE2,

#ifndef NO_LAPACK
  sneg_tcopy_CORE2, slaswp_ncopy_CORE2,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_CORE2,
  sbgemm_small_kernel_nn_CORE2, sbgemm_small_kernel_nt_CORE2, sbgemm_small_kernel_tn_CORE2, sbgemm_small_kernel_tt_CORE2,
  sbgemm_small_kernel_b0_nn_CORE2, sbgemm_small_kernel_b0_nt_CORE2, sbgemm_small_kernel_b0_tn_CORE2, sbgemm_small_kernel_b0_tt_CORE2,
#endif
#endif

#if ( BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  0, 0, 0,
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N,
#ifdef SGEMM_DEFAULT_UNROLL_MN
 SGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif
#endif

#ifdef HAVE_EXCLUSIVE_CACHE
  1,
#else
  0,
#endif

#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  samax_k_CORE2,  samin_k_CORE2,  smax_k_CORE2,  smin_k_CORE2,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_CORE2,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_CORE2, ismax_k_CORE2, ismin_k_CORE2,
  snrm2_k_CORE2,  sasum_k_CORE2,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_CORE2,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_CORE2, sdot_k_CORE2,
//  dsdot_k_CORE2,
  srot_k_CORE2,   saxpy_k_CORE2,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_CORE2,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_CORE2,
  sgemv_n_CORE2,  sgemv_t_CORE2,
#endif
#if BUILD_SINGLE == 1
  sger_k_CORE2,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_CORE2, ssymv_U_CORE2,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_CORE2,
  sgemm_direct_performant_CORE2,	
#endif

  sgemm_kernel_CORE2, sgemm_beta_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_CORE2, sgemm_itcopy_CORE2,
#else
  sgemm_oncopy_CORE2, sgemm_otcopy_CORE2,
#endif
  sgemm_oncopy_CORE2, sgemm_otcopy_CORE2,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_CORE2,
  sgemm_small_kernel_nn_CORE2, sgemm_small_kernel_nt_CORE2, sgemm_small_kernel_tn_CORE2, sgemm_small_kernel_tt_CORE2,
  sgemm_small_kernel_b0_nn_CORE2, sgemm_small_kernel_b0_nt_CORE2, sgemm_small_kernel_b0_tn_CORE2, sgemm_small_kernel_b0_tt_CORE2,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_CORE2, strsm_kernel_LT_CORE2, strsm_kernel_RN_CORE2, strsm_kernel_RT_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_CORE2, strsm_iunncopy_CORE2, strsm_iutucopy_CORE2, strsm_iutncopy_CORE2,
  strsm_ilnucopy_CORE2, strsm_ilnncopy_CORE2, strsm_iltucopy_CORE2, strsm_iltncopy_CORE2,
#else
  strsm_ounucopy_CORE2, strsm_ounncopy_CORE2, strsm_outucopy_CORE2, strsm_outncopy_CORE2,
  strsm_olnucopy_CORE2, strsm_olnncopy_CORE2, strsm_oltucopy_CORE2, strsm_oltncopy_CORE2,
#endif
  strsm_ounucopy_CORE2, strsm_ounncopy_CORE2, strsm_outucopy_CORE2, strsm_outncopy_CORE2,
  strsm_olnucopy_CORE2, strsm_olnncopy_CORE2, strsm_oltucopy_CORE2, strsm_oltncopy_CORE2,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_CORE2, strmm_kernel_RT_CORE2, strmm_kernel_LN_CORE2, strmm_kernel_LT_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_CORE2, strmm_iunncopy_CORE2, strmm_iutucopy_CORE2, strmm_iutncopy_CORE2,
  strmm_ilnucopy_CORE2, strmm_ilnncopy_CORE2, strmm_iltucopy_CORE2, strmm_iltncopy_CORE2,
#else
  strmm_ounucopy_CORE2, strmm_ounncopy_CORE2, strmm_outucopy_CORE2, strmm_outncopy_CORE2,
  strmm_olnucopy_CORE2, strmm_olnncopy_CORE2, strmm_oltucopy_CORE2, strmm_oltncopy_CORE2,
#endif
  strmm_ounucopy_CORE2, strmm_ounncopy_CORE2, strmm_outucopy_CORE2, strmm_outncopy_CORE2,
  strmm_olnucopy_CORE2, strmm_olnncopy_CORE2, strmm_oltucopy_CORE2, strmm_oltncopy_CORE2,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_CORE2, ssymm_iltcopy_CORE2,
#else
  ssymm_outcopy_CORE2, ssymm_oltcopy_CORE2,
#endif
  ssymm_outcopy_CORE2, ssymm_oltcopy_CORE2,
#ifndef NO_LAPACK
  sneg_tcopy_CORE2, slaswp_ncopy_CORE2,
#else
  NULL,NULL,
#endif
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  0, 0, 0,
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N,
#ifdef DGEMM_DEFAULT_UNROLL_MN
 DGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif
#endif


#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  damax_k_CORE2,  damin_k_CORE2,  dmax_k_CORE2,  dmin_k_CORE2,
  idamax_k_CORE2, idamin_k_CORE2, idmax_k_CORE2, idmin_k_CORE2,
  dnrm2_k_CORE2, dasum_k_CORE2,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_CORE2,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_CORE2, ddot_k_CORE2,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_CORE2,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_CORE2,
  daxpy_k_CORE2,
  dscal_k_CORE2, 
  dswap_k_CORE2,
  dgemv_n_CORE2,  dgemv_t_CORE2,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_CORE2,
  dsymv_L_CORE2,  dsymv_U_CORE2,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_CORE2, dgemm_beta_CORE2,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_CORE2, dgemm_itcopy_CORE2,
#else
  dgemm_oncopy_CORE2, dgemm_otcopy_CORE2,
#endif
  dgemm_oncopy_CORE2, dgemm_otcopy_CORE2,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_CORE2,
  dgemm_small_kernel_nn_CORE2, dgemm_small_kernel_nt_CORE2, dgemm_small_kernel_tn_CORE2, dgemm_small_kernel_tt_CORE2,
  dgemm_small_kernel_b0_nn_CORE2, dgemm_small_kernel_b0_nt_CORE2, dgemm_small_kernel_b0_tn_CORE2, dgemm_small_kernel_b0_tt_CORE2,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_CORE2, dtrsm_kernel_LT_CORE2, dtrsm_kernel_RN_CORE2, dtrsm_kernel_RT_CORE2,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_CORE2, dtrsm_iunncopy_CORE2, dtrsm_iutucopy_CORE2, dtrsm_iutncopy_CORE2,
  dtrsm_ilnucopy_CORE2, dtrsm_ilnncopy_CORE2, dtrsm_iltucopy_CORE2, dtrsm_iltncopy_CORE2,
#else
  dtrsm_ounucopy_CORE2, dtrsm_ounncopy_CORE2, dtrsm_outucopy_CORE2, dtrsm_outncopy_CORE2,
  dtrsm_olnucopy_CORE2, dtrsm_olnncopy_CORE2, dtrsm_oltucopy_CORE2, dtrsm_oltncopy_CORE2,
#endif
  dtrsm_ounucopy_CORE2, dtrsm_ounncopy_CORE2, dtrsm_outucopy_CORE2, dtrsm_outncopy_CORE2,
  dtrsm_olnucopy_CORE2, dtrsm_olnncopy_CORE2, dtrsm_oltucopy_CORE2, dtrsm_oltncopy_CORE2,
  dtrmm_kernel_RN_CORE2, dtrmm_kernel_RT_CORE2, dtrmm_kernel_LN_CORE2, dtrmm_kernel_LT_CORE2,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_CORE2, dtrmm_iunncopy_CORE2, dtrmm_iutucopy_CORE2, dtrmm_iutncopy_CORE2,
  dtrmm_ilnucopy_CORE2, dtrmm_ilnncopy_CORE2, dtrmm_iltucopy_CORE2, dtrmm_iltncopy_CORE2,
#else
  dtrmm_ounucopy_CORE2, dtrmm_ounncopy_CORE2, dtrmm_outucopy_CORE2, dtrmm_outncopy_CORE2,
  dtrmm_olnucopy_CORE2, dtrmm_olnncopy_CORE2, dtrmm_oltucopy_CORE2, dtrmm_oltncopy_CORE2,
#endif
  dtrmm_ounucopy_CORE2, dtrmm_ounncopy_CORE2, dtrmm_outucopy_CORE2, dtrmm_outncopy_CORE2,
  dtrmm_olnucopy_CORE2, dtrmm_olnncopy_CORE2, dtrmm_oltucopy_CORE2, dtrmm_oltncopy_CORE2,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_CORE2, dsymm_iltcopy_CORE2,
#else
  dsymm_outcopy_CORE2, dsymm_oltcopy_CORE2,
#endif
  dsymm_outcopy_CORE2, dsymm_oltcopy_CORE2,

#ifndef NO_LAPACK
  dneg_tcopy_CORE2, dlaswp_ncopy_CORE2,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_CORE2,  qamin_k_CORE2,  qmax_k_CORE2,  qmin_k_CORE2,
  iqamax_k_CORE2, iqamin_k_CORE2, iqmax_k_CORE2, iqmin_k_CORE2,
  qnrm2_k_CORE2,  qasum_k_CORE2,  qsum_k_CORE2, qcopy_k_CORE2, qdot_k_CORE2,
  qrot_k_CORE2,   qaxpy_k_CORE2,  qscal_k_CORE2, qswap_k_CORE2,
  qgemv_n_CORE2,  qgemv_t_CORE2,  qger_k_CORE2,
  qsymv_L_CORE2,  qsymv_U_CORE2,

  qgemm_kernel_CORE2, qgemm_beta_CORE2,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_CORE2, qgemm_itcopy_CORE2,
#else
  qgemm_oncopy_CORE2, qgemm_otcopy_CORE2,
#endif
  qgemm_oncopy_CORE2, qgemm_otcopy_CORE2,
  qtrsm_kernel_LN_CORE2, qtrsm_kernel_LT_CORE2, qtrsm_kernel_RN_CORE2, qtrsm_kernel_RT_CORE2,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_CORE2, qtrsm_iunncopy_CORE2, qtrsm_iutucopy_CORE2, qtrsm_iutncopy_CORE2,
  qtrsm_ilnucopy_CORE2, qtrsm_ilnncopy_CORE2, qtrsm_iltucopy_CORE2, qtrsm_iltncopy_CORE2,
#else
  qtrsm_ounucopy_CORE2, qtrsm_ounncopy_CORE2, qtrsm_outucopy_CORE2, qtrsm_outncopy_CORE2,
  qtrsm_olnucopy_CORE2, qtrsm_olnncopy_CORE2, qtrsm_oltucopy_CORE2, qtrsm_oltncopy_CORE2,
#endif
  qtrsm_ounucopy_CORE2, qtrsm_ounncopy_CORE2, qtrsm_outucopy_CORE2, qtrsm_outncopy_CORE2,
  qtrsm_olnucopy_CORE2, qtrsm_olnncopy_CORE2, qtrsm_oltucopy_CORE2, qtrsm_oltncopy_CORE2,
  qtrmm_kernel_RN_CORE2, qtrmm_kernel_RT_CORE2, qtrmm_kernel_LN_CORE2, qtrmm_kernel_LT_CORE2,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_CORE2, qtrmm_iunncopy_CORE2, qtrmm_iutucopy_CORE2, qtrmm_iutncopy_CORE2,
  qtrmm_ilnucopy_CORE2, qtrmm_ilnncopy_CORE2, qtrmm_iltucopy_CORE2, qtrmm_iltncopy_CORE2,
#else
  qtrmm_ounucopy_CORE2, qtrmm_ounncopy_CORE2, qtrmm_outucopy_CORE2, qtrmm_outncopy_CORE2,
  qtrmm_olnucopy_CORE2, qtrmm_olnncopy_CORE2, qtrmm_oltucopy_CORE2, qtrmm_oltncopy_CORE2,
#endif
  qtrmm_ounucopy_CORE2, qtrmm_ounncopy_CORE2, qtrmm_outucopy_CORE2, qtrmm_outncopy_CORE2,
  qtrmm_olnucopy_CORE2, qtrmm_olnncopy_CORE2, qtrmm_oltucopy_CORE2, qtrmm_oltncopy_CORE2,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_CORE2, qsymm_iltcopy_CORE2,
#else
  qsymm_outcopy_CORE2, qsymm_oltcopy_CORE2,
#endif
  qsymm_outcopy_CORE2, qsymm_oltcopy_CORE2,

#ifndef NO_LAPACK
  qneg_tcopy_CORE2, qlaswp_ncopy_CORE2,
#else
  NULL, NULL,
#endif

#endif

#if (BUILD_COMPLEX)
  0, 0, 0,
  CGEMM_DEFAULT_UNROLL_M, CGEMM_DEFAULT_UNROLL_N,
#ifdef CGEMM_DEFAULT_UNROLL_MN
 CGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(CGEMM_DEFAULT_UNROLL_M, CGEMM_DEFAULT_UNROLL_N),
#endif
#if (BUILD_COMPLEX)
  camax_k_CORE2, camin_k_CORE2,
#endif
#if (BUILD_COMPLEX)
  icamax_k_CORE2, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_CORE2,
  cnrm2_k_CORE2, casum_k_CORE2, csum_k_CORE2,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_CORE2, cdotu_k_CORE2, cdotc_k_CORE2,
#endif
#if (BUILD_COMPLEX)
 csrot_k_CORE2,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_CORE2,
  caxpyc_k_CORE2, 
  cscal_k_CORE2, 
  cswap_k_CORE2,

  cgemv_n_CORE2, cgemv_t_CORE2, cgemv_r_CORE2, cgemv_c_CORE2,
  cgemv_o_CORE2, cgemv_u_CORE2, cgemv_s_CORE2, cgemv_d_CORE2,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_CORE2, cgerc_k_CORE2, cgerv_k_CORE2, cgerd_k_CORE2,
  csymv_L_CORE2, csymv_U_CORE2,
  chemv_L_CORE2, chemv_U_CORE2, chemv_M_CORE2, chemv_V_CORE2,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_CORE2, cgemm_kernel_l_CORE2, cgemm_kernel_r_CORE2, cgemm_kernel_b_CORE2,
  cgemm_beta_CORE2,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_CORE2, cgemm_itcopy_CORE2,
#else
  cgemm_oncopy_CORE2, cgemm_otcopy_CORE2,
#endif
  cgemm_oncopy_CORE2, cgemm_otcopy_CORE2,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_CORE2,
  cgemm_small_kernel_nn_CORE2, cgemm_small_kernel_nt_CORE2, cgemm_small_kernel_nr_CORE2, cgemm_small_kernel_nc_CORE2,
  cgemm_small_kernel_tn_CORE2, cgemm_small_kernel_tt_CORE2, cgemm_small_kernel_tr_CORE2, cgemm_small_kernel_tc_CORE2,
  cgemm_small_kernel_rn_CORE2, cgemm_small_kernel_rt_CORE2, cgemm_small_kernel_rr_CORE2, cgemm_small_kernel_rc_CORE2,
  cgemm_small_kernel_cn_CORE2, cgemm_small_kernel_ct_CORE2, cgemm_small_kernel_cr_CORE2, cgemm_small_kernel_cc_CORE2,
  cgemm_small_kernel_b0_nn_CORE2, cgemm_small_kernel_b0_nt_CORE2, cgemm_small_kernel_b0_nr_CORE2, cgemm_small_kernel_b0_nc_CORE2,
  cgemm_small_kernel_b0_tn_CORE2, cgemm_small_kernel_b0_tt_CORE2, cgemm_small_kernel_b0_tr_CORE2, cgemm_small_kernel_b0_tc_CORE2,
  cgemm_small_kernel_b0_rn_CORE2, cgemm_small_kernel_b0_rt_CORE2, cgemm_small_kernel_b0_rr_CORE2, cgemm_small_kernel_b0_rc_CORE2,
  cgemm_small_kernel_b0_cn_CORE2, cgemm_small_kernel_b0_ct_CORE2, cgemm_small_kernel_b0_cr_CORE2, cgemm_small_kernel_b0_cc_CORE2,
#endif

  ctrsm_kernel_LN_CORE2, ctrsm_kernel_LT_CORE2, ctrsm_kernel_LR_CORE2, ctrsm_kernel_LC_CORE2,
  ctrsm_kernel_RN_CORE2, ctrsm_kernel_RT_CORE2, ctrsm_kernel_RR_CORE2, ctrsm_kernel_RC_CORE2,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_CORE2,  ctrsm_iunncopy_CORE2,  ctrsm_iutucopy_CORE2,  ctrsm_iutncopy_CORE2,
  ctrsm_ilnucopy_CORE2,  ctrsm_ilnncopy_CORE2,  ctrsm_iltucopy_CORE2,  ctrsm_iltncopy_CORE2,
#else
  ctrsm_ounucopy_CORE2,  ctrsm_ounncopy_CORE2,  ctrsm_outucopy_CORE2,  ctrsm_outncopy_CORE2,
  ctrsm_olnucopy_CORE2,  ctrsm_olnncopy_CORE2,  ctrsm_oltucopy_CORE2,  ctrsm_oltncopy_CORE2,
#endif
  ctrsm_ounucopy_CORE2,  ctrsm_ounncopy_CORE2,  ctrsm_outucopy_CORE2,  ctrsm_outncopy_CORE2,
  ctrsm_olnucopy_CORE2,  ctrsm_olnncopy_CORE2,  ctrsm_oltucopy_CORE2,  ctrsm_oltncopy_CORE2,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_CORE2,  ctrmm_kernel_RT_CORE2,  ctrmm_kernel_RR_CORE2,  ctrmm_kernel_RC_CORE2,
  ctrmm_kernel_LN_CORE2,  ctrmm_kernel_LT_CORE2,  ctrmm_kernel_LR_CORE2,  ctrmm_kernel_LC_CORE2,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_CORE2,  ctrmm_iunncopy_CORE2,  ctrmm_iutucopy_CORE2,  ctrmm_iutncopy_CORE2,
  ctrmm_ilnucopy_CORE2,  ctrmm_ilnncopy_CORE2,  ctrmm_iltucopy_CORE2,  ctrmm_iltncopy_CORE2,
#else
  ctrmm_ounucopy_CORE2,  ctrmm_ounncopy_CORE2,  ctrmm_outucopy_CORE2,  ctrmm_outncopy_CORE2,
  ctrmm_olnucopy_CORE2,  ctrmm_olnncopy_CORE2,  ctrmm_oltucopy_CORE2,  ctrmm_oltncopy_CORE2,
#endif
  ctrmm_ounucopy_CORE2,  ctrmm_ounncopy_CORE2,  ctrmm_outucopy_CORE2,  ctrmm_outncopy_CORE2,
  ctrmm_olnucopy_CORE2,  ctrmm_olnncopy_CORE2,  ctrmm_oltucopy_CORE2,  ctrmm_oltncopy_CORE2,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_CORE2,  csymm_iltcopy_CORE2,
#else
  csymm_outcopy_CORE2,  csymm_oltcopy_CORE2,
#endif
  csymm_outcopy_CORE2,  csymm_oltcopy_CORE2,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_CORE2,  chemm_iltcopy_CORE2,
#else
  chemm_outcopy_CORE2,  chemm_oltcopy_CORE2,
#endif
  chemm_outcopy_CORE2,  chemm_oltcopy_CORE2,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_CORE2,

  cgemm3m_incopyb_CORE2,  cgemm3m_incopyr_CORE2,
  cgemm3m_incopyi_CORE2,  cgemm3m_itcopyb_CORE2,
  cgemm3m_itcopyr_CORE2,  cgemm3m_itcopyi_CORE2,
  cgemm3m_oncopyb_CORE2,  cgemm3m_oncopyr_CORE2,
  cgemm3m_oncopyi_CORE2,  cgemm3m_otcopyb_CORE2,
  cgemm3m_otcopyr_CORE2,  cgemm3m_otcopyi_CORE2,

  csymm3m_iucopyb_CORE2,  csymm3m_ilcopyb_CORE2,
  csymm3m_iucopyr_CORE2,  csymm3m_ilcopyr_CORE2,
  csymm3m_iucopyi_CORE2,  csymm3m_ilcopyi_CORE2,
  csymm3m_oucopyb_CORE2,  csymm3m_olcopyb_CORE2,
  csymm3m_oucopyr_CORE2,  csymm3m_olcopyr_CORE2,
  csymm3m_oucopyi_CORE2,  csymm3m_olcopyi_CORE2,

  chemm3m_iucopyb_CORE2,  chemm3m_ilcopyb_CORE2,
  chemm3m_iucopyr_CORE2,  chemm3m_ilcopyr_CORE2,
  chemm3m_iucopyi_CORE2,  chemm3m_ilcopyi_CORE2,

  chemm3m_oucopyb_CORE2,  chemm3m_olcopyb_CORE2,
  chemm3m_oucopyr_CORE2,  chemm3m_olcopyr_CORE2,
  chemm3m_oucopyi_CORE2,  chemm3m_olcopyi_CORE2,
#else
  0, 0, 0,

  NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
#endif
#endif

#if (BUILD_COMPLEX)
#ifndef NO_LAPACK
  cneg_tcopy_CORE2,
  
   claswp_ncopy_CORE2,
#else
  NULL, NULL,
#endif

#endif

#if BUILD_COMPLEX16 == 1
  0, 0, 0,
  ZGEMM_DEFAULT_UNROLL_M, ZGEMM_DEFAULT_UNROLL_N,
#ifdef ZGEMM_DEFAULT_UNROLL_MN
 ZGEMM_DEFAULT_UNROLL_MN,
#else
 MAX(ZGEMM_DEFAULT_UNROLL_M, ZGEMM_DEFAULT_UNROLL_N),
#endif

  zamax_k_CORE2, zamin_k_CORE2, izamax_k_CORE2, izamin_k_CORE2,
  znrm2_k_CORE2, zasum_k_CORE2, zsum_k_CORE2, zcopy_k_CORE2,
  zdotu_k_CORE2, zdotc_k_CORE2, zdrot_k_CORE2,
  zaxpy_k_CORE2, zaxpyc_k_CORE2, zscal_k_CORE2, zswap_k_CORE2,

  zgemv_n_CORE2, zgemv_t_CORE2, zgemv_r_CORE2, zgemv_c_CORE2,
  zgemv_o_CORE2, zgemv_u_CORE2, zgemv_s_CORE2, zgemv_d_CORE2,
  zgeru_k_CORE2, zgerc_k_CORE2, zgerv_k_CORE2, zgerd_k_CORE2,
  zsymv_L_CORE2, zsymv_U_CORE2,
  zhemv_L_CORE2, zhemv_U_CORE2, zhemv_M_CORE2, zhemv_V_CORE2,

  zgemm_kernel_n_CORE2, zgemm_kernel_l_CORE2, zgemm_kernel_r_CORE2, zgemm_kernel_b_CORE2,
  zgemm_beta_CORE2,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_CORE2, zgemm_itcopy_CORE2,
#else
  zgemm_oncopy_CORE2, zgemm_otcopy_CORE2,
#endif
  zgemm_oncopy_CORE2, zgemm_otcopy_CORE2,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_CORE2,
  zgemm_small_kernel_nn_CORE2, zgemm_small_kernel_nt_CORE2, zgemm_small_kernel_nr_CORE2, zgemm_small_kernel_nc_CORE2,
  zgemm_small_kernel_tn_CORE2, zgemm_small_kernel_tt_CORE2, zgemm_small_kernel_tr_CORE2, zgemm_small_kernel_tc_CORE2,
  zgemm_small_kernel_rn_CORE2, zgemm_small_kernel_rt_CORE2, zgemm_small_kernel_rr_CORE2, zgemm_small_kernel_rc_CORE2,
  zgemm_small_kernel_cn_CORE2, zgemm_small_kernel_ct_CORE2, zgemm_small_kernel_cr_CORE2, zgemm_small_kernel_cc_CORE2,
  zgemm_small_kernel_b0_nn_CORE2, zgemm_small_kernel_b0_nt_CORE2, zgemm_small_kernel_b0_nr_CORE2, zgemm_small_kernel_b0_nc_CORE2,
  zgemm_small_kernel_b0_tn_CORE2, zgemm_small_kernel_b0_tt_CORE2, zgemm_small_kernel_b0_tr_CORE2, zgemm_small_kernel_b0_tc_CORE2,
  zgemm_small_kernel_b0_rn_CORE2, zgemm_small_kernel_b0_rt_CORE2, zgemm_small_kernel_b0_rr_CORE2, zgemm_small_kernel_b0_rc_CORE2,
  zgemm_small_kernel_b0_cn_CORE2, zgemm_small_kernel_b0_ct_CORE2, zgemm_small_kernel_b0_cr_CORE2, zgemm_small_kernel_b0_cc_CORE2,
#endif

  ztrsm_kernel_LN_CORE2, ztrsm_kernel_LT_CORE2, ztrsm_kernel_LR_CORE2, ztrsm_kernel_LC_CORE2,
  ztrsm_kernel_RN_CORE2, ztrsm_kernel_RT_CORE2, ztrsm_kernel_RR_CORE2, ztrsm_kernel_RC_CORE2,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_CORE2,  ztrsm_iunncopy_CORE2,  ztrsm_iutucopy_CORE2,  ztrsm_iutncopy_CORE2,
  ztrsm_ilnucopy_CORE2,  ztrsm_ilnncopy_CORE2,  ztrsm_iltucopy_CORE2,  ztrsm_iltncopy_CORE2,
#else
  ztrsm_ounucopy_CORE2,  ztrsm_ounncopy_CORE2,  ztrsm_outucopy_CORE2,  ztrsm_outncopy_CORE2,
  ztrsm_olnucopy_CORE2,  ztrsm_olnncopy_CORE2,  ztrsm_oltucopy_CORE2,  ztrsm_oltncopy_CORE2,
#endif
  ztrsm_ounucopy_CORE2,  ztrsm_ounncopy_CORE2,  ztrsm_outucopy_CORE2,  ztrsm_outncopy_CORE2,
  ztrsm_olnucopy_CORE2,  ztrsm_olnncopy_CORE2,  ztrsm_oltucopy_CORE2,  ztrsm_oltncopy_CORE2,

  ztrmm_kernel_RN_CORE2,  ztrmm_kernel_RT_CORE2,  ztrmm_kernel_RR_CORE2,  ztrmm_kernel_RC_CORE2,
  ztrmm_kernel_LN_CORE2,  ztrmm_kernel_LT_CORE2,  ztrmm_kernel_LR_CORE2,  ztrmm_kernel_LC_CORE2,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_CORE2,  ztrmm_iunncopy_CORE2,  ztrmm_iutucopy_CORE2,  ztrmm_iutncopy_CORE2,
  ztrmm_ilnucopy_CORE2,  ztrmm_ilnncopy_CORE2,  ztrmm_iltucopy_CORE2,  ztrmm_iltncopy_CORE2,
#else
  ztrmm_ounucopy_CORE2,  ztrmm_ounncopy_CORE2,  ztrmm_outucopy_CORE2,  ztrmm_outncopy_CORE2,
  ztrmm_olnucopy_CORE2,  ztrmm_olnncopy_CORE2,  ztrmm_oltucopy_CORE2,  ztrmm_oltncopy_CORE2,
#endif
  ztrmm_ounucopy_CORE2,  ztrmm_ounncopy_CORE2,  ztrmm_outucopy_CORE2,  ztrmm_outncopy_CORE2,
  ztrmm_olnucopy_CORE2,  ztrmm_olnncopy_CORE2,  ztrmm_oltucopy_CORE2,  ztrmm_oltncopy_CORE2,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_CORE2,  zsymm_iltcopy_CORE2,
#else
  zsymm_outcopy_CORE2,  zsymm_oltcopy_CORE2,
#endif
  zsymm_outcopy_CORE2,  zsymm_oltcopy_CORE2,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_CORE2,  zhemm_iltcopy_CORE2,
#else
  zhemm_outcopy_CORE2,  zhemm_oltcopy_CORE2,
#endif
  zhemm_outcopy_CORE2,  zhemm_oltcopy_CORE2,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_CORE2,

  zgemm3m_incopyb_CORE2,  zgemm3m_incopyr_CORE2,
  zgemm3m_incopyi_CORE2,  zgemm3m_itcopyb_CORE2,
  zgemm3m_itcopyr_CORE2,  zgemm3m_itcopyi_CORE2,
  zgemm3m_oncopyb_CORE2,  zgemm3m_oncopyr_CORE2,
  zgemm3m_oncopyi_CORE2,  zgemm3m_otcopyb_CORE2,
  zgemm3m_otcopyr_CORE2,  zgemm3m_otcopyi_CORE2,

  zsymm3m_iucopyb_CORE2,  zsymm3m_ilcopyb_CORE2,
  zsymm3m_iucopyr_CORE2,  zsymm3m_ilcopyr_CORE2,
  zsymm3m_iucopyi_CORE2,  zsymm3m_ilcopyi_CORE2,
  zsymm3m_oucopyb_CORE2,  zsymm3m_olcopyb_CORE2,
  zsymm3m_oucopyr_CORE2,  zsymm3m_olcopyr_CORE2,
  zsymm3m_oucopyi_CORE2,  zsymm3m_olcopyi_CORE2,

  zhemm3m_iucopyb_CORE2,  zhemm3m_ilcopyb_CORE2,
  zhemm3m_iucopyr_CORE2,  zhemm3m_ilcopyr_CORE2,
  zhemm3m_iucopyi_CORE2,  zhemm3m_ilcopyi_CORE2,

  zhemm3m_oucopyb_CORE2,  zhemm3m_olcopyb_CORE2,
  zhemm3m_oucopyr_CORE2,  zhemm3m_olcopyr_CORE2,
  zhemm3m_oucopyi_CORE2,  zhemm3m_olcopyi_CORE2,
#else
  0, 0, 0,

  NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
#endif

#ifndef NO_LAPACK
  zneg_tcopy_CORE2, zlaswp_ncopy_CORE2,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_CORE2, xamin_k_CORE2, ixamax_k_CORE2, ixamin_k_CORE2,
  xnrm2_k_CORE2, xasum_k_CORE2, xsum_k_CORE2, xcopy_k_CORE2,
  xdotu_k_CORE2, xdotc_k_CORE2, xqrot_k_CORE2,
  xaxpy_k_CORE2, xaxpyc_k_CORE2, xscal_k_CORE2, xswap_k_CORE2,

  xgemv_n_CORE2, xgemv_t_CORE2, xgemv_r_CORE2, xgemv_c_CORE2,
  xgemv_o_CORE2, xgemv_u_CORE2, xgemv_s_CORE2, xgemv_d_CORE2,
  xgeru_k_CORE2, xgerc_k_CORE2, xgerv_k_CORE2, xgerd_k_CORE2,
  xsymv_L_CORE2, xsymv_U_CORE2,
  xhemv_L_CORE2, xhemv_U_CORE2, xhemv_M_CORE2, xhemv_V_CORE2,

  xgemm_kernel_n_CORE2, xgemm_kernel_l_CORE2, xgemm_kernel_r_CORE2, xgemm_kernel_b_CORE2,
  xgemm_beta_CORE2,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_CORE2, xgemm_itcopy_CORE2,
#else
  xgemm_oncopy_CORE2, xgemm_otcopy_CORE2,
#endif
  xgemm_oncopy_CORE2, xgemm_otcopy_CORE2,

  xtrsm_kernel_LN_CORE2, xtrsm_kernel_LT_CORE2, xtrsm_kernel_LR_CORE2, xtrsm_kernel_LC_CORE2,
  xtrsm_kernel_RN_CORE2, xtrsm_kernel_RT_CORE2, xtrsm_kernel_RR_CORE2, xtrsm_kernel_RC_CORE2,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_CORE2,  xtrsm_iunncopy_CORE2,  xtrsm_iutucopy_CORE2,  xtrsm_iutncopy_CORE2,
  xtrsm_ilnucopy_CORE2,  xtrsm_ilnncopy_CORE2,  xtrsm_iltucopy_CORE2,  xtrsm_iltncopy_CORE2,
#else
  xtrsm_ounucopy_CORE2,  xtrsm_ounncopy_CORE2,  xtrsm_outucopy_CORE2,  xtrsm_outncopy_CORE2,
  xtrsm_olnucopy_CORE2,  xtrsm_olnncopy_CORE2,  xtrsm_oltucopy_CORE2,  xtrsm_oltncopy_CORE2,
#endif
  xtrsm_ounucopy_CORE2,  xtrsm_ounncopy_CORE2,  xtrsm_outucopy_CORE2,  xtrsm_outncopy_CORE2,
  xtrsm_olnucopy_CORE2,  xtrsm_olnncopy_CORE2,  xtrsm_oltucopy_CORE2,  xtrsm_oltncopy_CORE2,

  xtrmm_kernel_RN_CORE2,  xtrmm_kernel_RT_CORE2,  xtrmm_kernel_RR_CORE2,  xtrmm_kernel_RC_CORE2,
  xtrmm_kernel_LN_CORE2,  xtrmm_kernel_LT_CORE2,  xtrmm_kernel_LR_CORE2,  xtrmm_kernel_LC_CORE2,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_CORE2,  xtrmm_iunncopy_CORE2,  xtrmm_iutucopy_CORE2,  xtrmm_iutncopy_CORE2,
  xtrmm_ilnucopy_CORE2,  xtrmm_ilnncopy_CORE2,  xtrmm_iltucopy_CORE2,  xtrmm_iltncopy_CORE2,
#else
  xtrmm_ounucopy_CORE2,  xtrmm_ounncopy_CORE2,  xtrmm_outucopy_CORE2,  xtrmm_outncopy_CORE2,
  xtrmm_olnucopy_CORE2,  xtrmm_olnncopy_CORE2,  xtrmm_oltucopy_CORE2,  xtrmm_oltncopy_CORE2,
#endif
  xtrmm_ounucopy_CORE2,  xtrmm_ounncopy_CORE2,  xtrmm_outucopy_CORE2,  xtrmm_outncopy_CORE2,
  xtrmm_olnucopy_CORE2,  xtrmm_olnncopy_CORE2,  xtrmm_oltucopy_CORE2,  xtrmm_oltncopy_CORE2,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_CORE2,  xsymm_iltcopy_CORE2,
#else
  xsymm_outcopy_CORE2,  xsymm_oltcopy_CORE2,
#endif
  xsymm_outcopy_CORE2,  xsymm_oltcopy_CORE2,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_CORE2,  xhemm_iltcopy_CORE2,
#else
  xhemm_outcopy_CORE2,  xhemm_oltcopy_CORE2,
#endif
  xhemm_outcopy_CORE2,  xhemm_oltcopy_CORE2,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_CORE2,

  xgemm3m_incopyb_CORE2,  xgemm3m_incopyr_CORE2,
  xgemm3m_incopyi_CORE2,  xgemm3m_itcopyb_CORE2,
  xgemm3m_itcopyr_CORE2,  xgemm3m_itcopyi_CORE2,
  xgemm3m_oncopyb_CORE2,  xgemm3m_oncopyr_CORE2,
  xgemm3m_oncopyi_CORE2,  xgemm3m_otcopyb_CORE2,
  xgemm3m_otcopyr_CORE2,  xgemm3m_otcopyi_CORE2,

  xsymm3m_iucopyb_CORE2,  xsymm3m_ilcopyb_CORE2,
  xsymm3m_iucopyr_CORE2,  xsymm3m_ilcopyr_CORE2,
  xsymm3m_iucopyi_CORE2,  xsymm3m_ilcopyi_CORE2,
  xsymm3m_oucopyb_CORE2,  xsymm3m_olcopyb_CORE2,
  xsymm3m_oucopyr_CORE2,  xsymm3m_olcopyr_CORE2,
  xsymm3m_oucopyi_CORE2,  xsymm3m_olcopyi_CORE2,

  xhemm3m_iucopyb_CORE2,  xhemm3m_ilcopyb_CORE2,
  xhemm3m_iucopyr_CORE2,  xhemm3m_ilcopyr_CORE2,
  xhemm3m_iucopyi_CORE2,  xhemm3m_ilcopyi_CORE2,

  xhemm3m_oucopyb_CORE2,  xhemm3m_olcopyb_CORE2,
  xhemm3m_oucopyr_CORE2,  xhemm3m_olcopyr_CORE2,
  xhemm3m_oucopyi_CORE2,  xhemm3m_olcopyi_CORE2,
#else
  0, 0, 0,

  NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,

  NULL, NULL,
  NULL, NULL,
  NULL, NULL,
#endif

#ifndef NO_LAPACK
  xneg_tcopy_CORE2, xlaswp_ncopy_CORE2,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_CORE2,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_CORE2,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_CORE2,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_CORE2,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_CORE2, somatcopy_k_ct_CORE2, somatcopy_k_rn_CORE2, somatcopy_k_rt_CORE2,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_CORE2, domatcopy_k_ct_CORE2, domatcopy_k_rn_CORE2, domatcopy_k_rt_CORE2,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_CORE2, comatcopy_k_ct_CORE2, comatcopy_k_rn_CORE2, comatcopy_k_rt_CORE2,
  comatcopy_k_cnc_CORE2, comatcopy_k_ctc_CORE2, comatcopy_k_rnc_CORE2, comatcopy_k_rtc_CORE2,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_CORE2, zomatcopy_k_ct_CORE2, zomatcopy_k_rn_CORE2, zomatcopy_k_rt_CORE2,
  zomatcopy_k_cnc_CORE2, zomatcopy_k_ctc_CORE2, zomatcopy_k_rnc_CORE2, zomatcopy_k_rtc_CORE2,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_CORE2, simatcopy_k_ct_CORE2, simatcopy_k_rn_CORE2, simatcopy_k_rt_CORE2,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_CORE2, dimatcopy_k_ct_CORE2, dimatcopy_k_rn_CORE2, dimatcopy_k_rt_CORE2,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_CORE2, cimatcopy_k_ct_CORE2, cimatcopy_k_rn_CORE2, cimatcopy_k_rt_CORE2,
  cimatcopy_k_cnc_CORE2, cimatcopy_k_ctc_CORE2, cimatcopy_k_rnc_CORE2, cimatcopy_k_rtc_CORE2,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_CORE2, zimatcopy_k_ct_CORE2, zimatcopy_k_rn_CORE2, zimatcopy_k_rt_CORE2,
  zimatcopy_k_cnc_CORE2, zimatcopy_k_ctc_CORE2, zimatcopy_k_rnc_CORE2, zimatcopy_k_rtc_CORE2,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_CORE2,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_CORE2,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_CORE2,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_CORE2,
#endif
};

#if (ARCH_ARM64)
static void init_parameter(void) {
#if (BUILD_BFLOAT16)
  TABLE_NAME.sbgemm_p = SBGEMM_DEFAULT_P;
#endif
#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif

#if (BUILD_BFLOAT16)
  TABLE_NAME.sbgemm_q = SBGEMM_DEFAULT_Q;
#endif
#if BUILD_SINGLE == 1 || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
#endif
#if BUILD_DOUBLE== 1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX== 1
  TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;
#endif

#if (BUILD_BFLOAT16)
  TABLE_NAME.sbgemm_r = SBGEMM_DEFAULT_R;
#endif
#if BUILD_SINGLE == 1 || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_r = SGEMM_DEFAULT_R;
#endif
#if BUILD_DOUBLE==1  || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_r = DGEMM_DEFAULT_R;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_r = CGEMM_DEFAULT_R;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_r = ZGEMM_DEFAULT_R;
#endif

#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
  TABLE_NAME.qgemm_q = QGEMM_DEFAULT_Q;
  TABLE_NAME.xgemm_q = XGEMM_DEFAULT_Q;
  TABLE_NAME.qgemm_r = QGEMM_DEFAULT_R;
  TABLE_NAME.xgemm_r = XGEMM_DEFAULT_R;
#endif

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_P
  TABLE_NAME.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.cgemm3m_p = TABLE_NAME.sgemm_p;
#endif

#ifdef ZGEMM3M_DEFAULT_P
  TABLE_NAME.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.zgemm3m_p = TABLE_NAME.dgemm_p;
#endif

#ifdef CGEMM3M_DEFAULT_Q
  TABLE_NAME.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.cgemm3m_q = TABLE_NAME.sgemm_q;
#endif

#ifdef ZGEMM3M_DEFAULT_Q
  TABLE_NAME.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.zgemm3m_q = TABLE_NAME.dgemm_q;
#endif

#ifdef CGEMM3M_DEFAULT_R
  TABLE_NAME.cgemm3m_r = CGEMM3M_DEFAULT_R;
#else
  TABLE_NAME.cgemm3m_r = TABLE_NAME.sgemm_r;
#endif

#ifdef ZGEMM3M_DEFAULT_R
  TABLE_NAME.zgemm3m_r = ZGEMM3M_DEFAULT_R;
#else
  TABLE_NAME.zgemm3m_r = TABLE_NAME.dgemm_r;
#endif

#ifdef EXPRECISION
  TABLE_NAME.xgemm3m_p = TABLE_NAME.qgemm_p;
  TABLE_NAME.xgemm3m_q = TABLE_NAME.qgemm_q;
  TABLE_NAME.xgemm3m_r = TABLE_NAME.qgemm_r;
#endif
#endif

}
#else // (ARCH_ARM64)
#if defined(ARCH_MIPS64)
static void init_parameter(void) {
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;

  TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
  TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
  TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
  TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;

  TABLE_NAME.sgemm_r = SGEMM_DEFAULT_R;
  TABLE_NAME.dgemm_r = 640;
  TABLE_NAME.cgemm_r = CGEMM_DEFAULT_R;
  TABLE_NAME.zgemm_r = ZGEMM_DEFAULT_R;

#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
  TABLE_NAME.qgemm_q = QGEMM_DEFAULT_Q;
  TABLE_NAME.xgemm_q = XGEMM_DEFAULT_Q;
  TABLE_NAME.qgemm_r = QGEMM_DEFAULT_R;
  TABLE_NAME.xgemm_r = XGEMM_DEFAULT_R;
#endif

#if defined(USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_P
  TABLE_NAME.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.cgemm3m_p = TABLE_NAME.sgemm_p;
#endif

#ifdef ZGEMM3M_DEFAULT_P
  TABLE_NAME.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.zgemm3m_p = TABLE_NAME.dgemm_p;
#endif

#ifdef CGEMM3M_DEFAULT_Q
  TABLE_NAME.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.cgemm3m_q = TABLE_NAME.sgemm_q;
#endif

#ifdef ZGEMM3M_DEFAULT_Q
  TABLE_NAME.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.zgemm3m_q = TABLE_NAME.dgemm_q;
#endif

#ifdef CGEMM3M_DEFAULT_R
  TABLE_NAME.cgemm3m_r = CGEMM3M_DEFAULT_R;
#else
  TABLE_NAME.cgemm3m_r = TABLE_NAME.sgemm_r;
#endif

#ifdef ZGEMM3M_DEFAULT_R
  TABLE_NAME.zgemm3m_r = ZGEMM3M_DEFAULT_R;
#else
  TABLE_NAME.zgemm3m_r = TABLE_NAME.dgemm_r;
#endif

#ifdef EXPRECISION
  TABLE_NAME.xgemm3m_p = TABLE_NAME.qgemm_p;
  TABLE_NAME.xgemm3m_q = TABLE_NAME.qgemm_q;
  TABLE_NAME.xgemm3m_r = TABLE_NAME.qgemm_r;
#endif
#endif
}
#else // (ARCH_MIPS64)
#if (ARCH_LOONGARCH64)
static void init_parameter(void) {

#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_p = SBGEMM_DEFAULT_P;
#endif
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_r = SBGEMM_DEFAULT_R;
#endif
  TABLE_NAME.sgemm_r = SGEMM_DEFAULT_R;
  TABLE_NAME.dgemm_r = DGEMM_DEFAULT_R;
  TABLE_NAME.cgemm_r = CGEMM_DEFAULT_R;
  TABLE_NAME.zgemm_r = ZGEMM_DEFAULT_R;

#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_q = SBGEMM_DEFAULT_Q;
#endif
  TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
  TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
  TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
  TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else // (ARCH_LOONGARCH64)
#if (ARCH_POWER)
static void init_parameter(void) {

#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_p = SBGEMM_DEFAULT_P;
#endif
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_r = SBGEMM_DEFAULT_R;
#endif
  TABLE_NAME.sgemm_r = SGEMM_DEFAULT_R;
  TABLE_NAME.dgemm_r = DGEMM_DEFAULT_R;
  TABLE_NAME.cgemm_r = CGEMM_DEFAULT_R;
  TABLE_NAME.zgemm_r = ZGEMM_DEFAULT_R;


#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_q = SBGEMM_DEFAULT_Q;
#endif
  TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
  TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
  TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
  TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else //POWER

#if (ARCH_ZARCH)
static void init_parameter(void) {
#ifdef BUILD_BFLOAT16
	TABLE_NAME.sbgemm_p = SBGEMM_DEFAULT_P;
#endif
	TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
	TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
	TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
	TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;

#ifdef BUILD_BFLOAT16
	TABLE_NAME.sbgemm_r = SBGEMM_DEFAULT_R;
#endif
	TABLE_NAME.sgemm_r = SGEMM_DEFAULT_R;
	TABLE_NAME.dgemm_r = DGEMM_DEFAULT_R;
	TABLE_NAME.cgemm_r = CGEMM_DEFAULT_R;
	TABLE_NAME.zgemm_r = ZGEMM_DEFAULT_R;


#ifdef BUILD_BFLOAT16
	TABLE_NAME.sbgemm_q = SBGEMM_DEFAULT_Q;
#endif
	TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
	TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
	TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
	TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;
}
#else //ZARCH

#ifdef ARCH_X86
static int get_l2_size_old(void){
  int i, eax, ebx, ecx, edx, cpuid_level;
  int info[15];

  cpuid(2, &eax, &ebx, &ecx, &edx);

  info[ 0] = BITMASK(eax,  8, 0xff);
  info[ 1] = BITMASK(eax, 16, 0xff);
  info[ 2] = BITMASK(eax, 24, 0xff);

  info[ 3] = BITMASK(ebx,  0, 0xff);
  info[ 4] = BITMASK(ebx,  8, 0xff);
  info[ 5] = BITMASK(ebx, 16, 0xff);
  info[ 6] = BITMASK(ebx, 24, 0xff);

  info[ 7] = BITMASK(ecx,  0, 0xff);
  info[ 8] = BITMASK(ecx,  8, 0xff);
  info[ 9] = BITMASK(ecx, 16, 0xff);
  info[10] = BITMASK(ecx, 24, 0xff);

  info[11] = BITMASK(edx,  0, 0xff);
  info[12] = BITMASK(edx,  8, 0xff);
  info[13] = BITMASK(edx, 16, 0xff);
  info[14] = BITMASK(edx, 24, 0xff);

  for (i = 0; i < 15; i++){

    switch (info[i]){

      /* This table is from http://www.sandpile.org/ia32/cpuid.htm */

    case 0x1a :
      return 96;

    case 0x39 :
    case 0x3b :
    case 0x41 :
    case 0x79 :
    case 0x81 :
      return 128;

    case 0x3a :
      return 192;

    case 0x21 :
    case 0x3c :
    case 0x42 :
    case 0x7a :
    case 0x7e :
    case 0x82 :
      return 256;

    case 0x3d :
      return 384;

    case 0x3e :
    case 0x43 :
    case 0x7b :
    case 0x7f :
    case 0x83 :
    case 0x86 :
      return 512;

    case 0x44 :
    case 0x78 :
    case 0x7c :
    case 0x84 :
    case 0x87 :
      return 1024;

    case 0x45 :
    case 0x7d :
    case 0x85 :
      return 2048;

    case 0x48 :
      return 3184;

    case 0x49 :
      return 4096;

    case 0x4e :
      return 6144;
    }
  }
//  return 0;
fprintf (stderr,"OpenBLAS WARNING - could not determine the L2 cache size on this system, assuming 256k\n");
return 256;
}
#endif

static __inline__ int get_l2_size(void){

  int eax, ebx, ecx, edx, l2;

  cpuid(0x80000006, &eax, &ebx, &ecx, &edx);

  l2 = BITMASK(ecx, 16, 0xffff);

#ifndef ARCH_X86
  if (l2 <= 0) {
     fprintf (stderr,"OpenBLAS WARNING - could not determine the L2 cache size on this system, assuming 256k\n");
     return 256;
  }
  return l2;

#else

  if (l2 > 0) return l2;

  return get_l2_size_old();
#endif
}

static __inline__ int get_l3_size(void){

  int eax, ebx, ecx, edx;

  cpuid(0x80000006, &eax, &ebx, &ecx, &edx);

  return BITMASK(edx, 18, 0x3fff) * 512;
}


static void init_parameter(void) {

  int l2 = get_l2_size();

  (void) l2; /* dirty trick to suppress unused variable warning for targets */
             /* where the GEMM unrolling parameters do not depend on l2 */
  
#ifdef BUILD_BFLOAT16
  TABLE_NAME.sbgemm_p = SBGEMM_DEFAULT_P;
  TABLE_NAME.sbgemm_q = SBGEMM_DEFAULT_Q;
#endif
#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_q = SGEMM_DEFAULT_Q;
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16)
  TABLE_NAME.dgemm_q = DGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX == 1
  TABLE_NAME.cgemm_q = CGEMM_DEFAULT_Q;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_q = ZGEMM_DEFAULT_Q;
#endif

#if BUILD_COMPLEX == 1
#ifdef CGEMM3M_DEFAULT_Q
  TABLE_NAME.cgemm3m_q = CGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.cgemm3m_q = SGEMM_DEFAULT_Q;
#endif
#endif

#if BUILD_COMPLEX16 == 1
#ifdef ZGEMM3M_DEFAULT_Q
  TABLE_NAME.zgemm3m_q = ZGEMM3M_DEFAULT_Q;
#else
  TABLE_NAME.zgemm3m_q = DGEMM_DEFAULT_Q;
#endif
#endif

#ifdef EXPRECISION
  TABLE_NAME.qgemm_q = QGEMM_DEFAULT_Q;
  TABLE_NAME.xgemm_q = XGEMM_DEFAULT_Q;
  TABLE_NAME.xgemm3m_q = QGEMM_DEFAULT_Q;
#endif

#if defined(CORE_KATMAI)  || defined(CORE_COPPERMINE) || defined(CORE_BANIAS) || defined(CORE_YONAH) || defined(CORE_ATHLON)

#ifdef DEBUG
  fprintf(stderr, "Katmai, Coppermine, Banias, Athlon\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  64 * (l2 >> 7);
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  32 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1 
  TABLE_NAME.cgemm_p =  32 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  16 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  16 * (l2 >> 7);
  TABLE_NAME.xgemm_p =   8 * (l2 >> 7);
#endif
#endif

#ifdef CORE_NORTHWOOD

#ifdef DEBUG
  fprintf(stderr, "Northwood\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  96 * (l2 >> 7);
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  48 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1 
  TABLE_NAME.cgemm_p =  48 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  24 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  24 * (l2 >> 7);
  TABLE_NAME.xgemm_p =  12 * (l2 >> 7);
#endif
#endif

#ifdef ATOM

#ifdef DEBUG
  fprintf(stderr, "Atom\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = 256;
#endif
#if BUILD_DOUBLE ==1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = 128;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p = 128;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  64;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  64;
  TABLE_NAME.xgemm_p =  32;
#endif
#endif

#ifdef CORE_PRESCOTT

#ifdef DEBUG
  fprintf(stderr, "Prescott\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  56 * (l2 >> 7);
#endif
#if BUILD_DOUBLE ==1  || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p =  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16 == 1
  TABLE_NAME.zgemm_p =  14 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  14 * (l2 >> 7);
  TABLE_NAME.xgemm_p =   7 * (l2 >> 7);
#endif
#endif

#ifdef CORE2

#ifdef DEBUG
  fprintf(stderr, "Core2\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  92 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE==1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  46 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p =  46 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  23 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  92 * (l2 >> 9) + 8;
  TABLE_NAME.xgemm_p =  46 * (l2 >> 9) + 4;
#endif
#endif

#ifdef PENRYN

#ifdef DEBUG
  fprintf(stderr, "Penryn\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE == 1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p =  21 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  21 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  42 * (l2 >> 9) + 8;
  TABLE_NAME.xgemm_p =  21 * (l2 >> 9) + 4;
#endif
#endif

#ifdef DUNNINGTON

#ifdef DEBUG
  fprintf(stderr, "Dunnington\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_DOUBLE ==1 || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p =  42 * (l2 >> 9) + 8;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p =  21 * (l2 >> 9) + 4;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p =  21 * (l2 >> 9) + 4;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  42 * (l2 >> 9) + 8;
  TABLE_NAME.xgemm_p =  21 * (l2 >> 9) + 4;
#endif
#endif


#ifdef NEHALEM

#ifdef DEBUG
  fprintf(stderr, "Nehalem\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef SANDYBRIDGE

#ifdef DEBUG
  fprintf(stderr, "Sandybridge\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef HASWELL

#ifdef DEBUG
  fprintf(stderr, "Haswell\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#if defined(SKYLAKEX) || defined(COOPERLAKE) || defined(SAPPHIRERAPIDS)

#ifdef DEBUG
  fprintf(stderr, "SkylakeX\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef OPTERON

#ifdef DEBUG
  fprintf(stderr, "Opteron\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = 224 +  56 * (l2 >> 7);
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = 112 +  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = 112 +  28 * (l2 >> 7);
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p =  56 +  14 * (l2 >> 7);
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p =  56 +  14 * (l2 >> 7);
  TABLE_NAME.xgemm_p =  28 +   7 * (l2 >> 7);
#endif
#endif

#ifdef BARCELONA

#ifdef DEBUG
  fprintf(stderr, "Barcelona\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef BOBCAT

#ifdef DEBUG
  fprintf(stderr, "Bobcate\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef BULLDOZER

#ifdef DEBUG
  fprintf(stderr, "Bulldozer\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef EXCAVATOR

#ifdef DEBUG
  fprintf(stderr, "Excavator\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef PILEDRIVER

#ifdef DEBUG
  fprintf(stderr, "Piledriver\n");
#endif

#if (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef STEAMROLLER

#ifdef DEBUG
  fprintf(stderr, "Steamroller\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if BUILD_DOUBLE || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif

#ifdef ZEN

#ifdef DEBUG
  fprintf(stderr, "Zen\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if BUILD_COMPLEX16
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif
#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif
#endif


#ifdef NANO

#ifdef DEBUG
  fprintf(stderr, "NANO\n");
#endif

#if  (BUILD_SINGLE==1) || (BUILD_COMPLEX==1)
  TABLE_NAME.sgemm_p = SGEMM_DEFAULT_P;
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)
  TABLE_NAME.dgemm_p = DGEMM_DEFAULT_P;
#endif
#if (BUILD_COMPLEX==1)
  TABLE_NAME.cgemm_p = CGEMM_DEFAULT_P;
#endif
#if (BUILD_COMPLEX16==1)
  TABLE_NAME.zgemm_p = ZGEMM_DEFAULT_P;
#endif


#ifdef EXPRECISION
  TABLE_NAME.qgemm_p = QGEMM_DEFAULT_P;
  TABLE_NAME.xgemm_p = XGEMM_DEFAULT_P;
#endif

#endif

#if BUILD_COMPLEX==1
#ifdef CGEMM3M_DEFAULT_P
  TABLE_NAME.cgemm3m_p = CGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.cgemm3m_p = TABLE_NAME.sgemm_p;
#endif
#endif

#if BUILD_COMPLEX16==1
#ifdef ZGEMM3M_DEFAULT_P
  TABLE_NAME.zgemm3m_p = ZGEMM3M_DEFAULT_P;
#else
  TABLE_NAME.zgemm3m_p = TABLE_NAME.dgemm_p;
#endif
#endif

#ifdef EXPRECISION
  TABLE_NAME.xgemm3m_p = TABLE_NAME.qgemm_p;
#endif


#if BUILD_SINGLE == 1
  TABLE_NAME.sgemm_p = ((TABLE_NAME.sgemm_p + SGEMM_DEFAULT_UNROLL_M - 1)/SGEMM_DEFAULT_UNROLL_M) * SGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_DOUBLE== 1
  TABLE_NAME.dgemm_p = ((TABLE_NAME.dgemm_p + DGEMM_DEFAULT_UNROLL_M - 1)/DGEMM_DEFAULT_UNROLL_M) * DGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_COMPLEX==1
  TABLE_NAME.cgemm_p = ((TABLE_NAME.cgemm_p + CGEMM_DEFAULT_UNROLL_M - 1)/CGEMM_DEFAULT_UNROLL_M) * CGEMM_DEFAULT_UNROLL_M;
#endif
#if BUILD_COMPLEX16==1
  TABLE_NAME.zgemm_p = ((TABLE_NAME.zgemm_p + ZGEMM_DEFAULT_UNROLL_M - 1)/ZGEMM_DEFAULT_UNROLL_M) * ZGEMM_DEFAULT_UNROLL_M;
#endif

#if BUILD_COMPLEX==1
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  TABLE_NAME.cgemm3m_p = ((TABLE_NAME.cgemm3m_p + CGEMM3M_DEFAULT_UNROLL_M - 1)/CGEMM3M_DEFAULT_UNROLL_M) * CGEMM3M_DEFAULT_UNROLL_M;
#else
  TABLE_NAME.cgemm3m_p = ((TABLE_NAME.cgemm3m_p + SGEMM_DEFAULT_UNROLL_M - 1)/SGEMM_DEFAULT_UNROLL_M) * SGEMM_DEFAULT_UNROLL_M;
#endif
#endif

#if BUILD_COMPLEX16==1
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  TABLE_NAME.zgemm3m_p = ((TABLE_NAME.zgemm3m_p + ZGEMM3M_DEFAULT_UNROLL_M - 1)/ZGEMM3M_DEFAULT_UNROLL_M) * ZGEMM3M_DEFAULT_UNROLL_M;
#else
  TABLE_NAME.zgemm3m_p = ((TABLE_NAME.zgemm3m_p + DGEMM_DEFAULT_UNROLL_M - 1)/DGEMM_DEFAULT_UNROLL_M) * DGEMM_DEFAULT_UNROLL_M;
#endif
#endif

#ifdef QUAD_PRECISION
  TABLE_NAME.qgemm_p = ((TABLE_NAME.qgemm_p + QGEMM_DEFAULT_UNROLL_M - 1)/QGEMM_DEFAULT_UNROLL_M) * QGEMM_DEFAULT_UNROLL_M;
  TABLE_NAME.xgemm_p = ((TABLE_NAME.xgemm_p + XGEMM_DEFAULT_UNROLL_M - 1)/XGEMM_DEFAULT_UNROLL_M) * XGEMM_DEFAULT_UNROLL_M;
  TABLE_NAME.xgemm3m_p = ((TABLE_NAME.xgemm3m_p + QGEMM_DEFAULT_UNROLL_M - 1)/QGEMM_DEFAULT_UNROLL_M) * QGEMM_DEFAULT_UNROLL_M;
#endif

#ifdef DEBUG
  fprintf(stderr, "L2 = %8d DGEMM_P  .. %d\n", l2, TABLE_NAME.dgemm_p);
#endif

#if BUILD_BFLOAT16==1
  TABLE_NAME.sbgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.sbgemm_p * TABLE_NAME.sbgemm_q *  4 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.sbgemm_q *  4) - 15) & ~15);
#endif

#if BUILD_SINGLE==1
  TABLE_NAME.sgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.sgemm_p * TABLE_NAME.sgemm_q *  4 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.sgemm_q *  4) - 15) & ~15);
#endif

#if BUILD_DOUBLE==1
  TABLE_NAME.dgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.dgemm_p * TABLE_NAME.dgemm_q *  8 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.dgemm_q *  8) - 15) & ~15);
#endif

#ifdef EXPRECISION
  TABLE_NAME.qgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.qgemm_p * TABLE_NAME.qgemm_q * 16 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.qgemm_q * 16) - 15) & ~15);
#endif

#if BUILD_COMPLEX ==1 
  TABLE_NAME.cgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.cgemm_p * TABLE_NAME.cgemm_q *  8 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.cgemm_q *  8) - 15) & ~15);
#endif

#if BUILD_COMPLEX16 ==1
  TABLE_NAME.zgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.zgemm_p * TABLE_NAME.zgemm_q * 16 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.zgemm_q * 16) - 15) & ~15);
#endif

#if BUILD_COMPLEX == 1
  TABLE_NAME.cgemm3m_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.cgemm3m_p * TABLE_NAME.cgemm3m_q *  8 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.cgemm3m_q *  8) - 15) & ~15);
#endif

#if BUILD_COMPLEX16 == 1
  TABLE_NAME.zgemm3m_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.zgemm3m_p * TABLE_NAME.zgemm3m_q * 16 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
			       ) / (TABLE_NAME.zgemm3m_q * 16) - 15) & ~15);
#endif



#ifdef EXPRECISION
  TABLE_NAME.xgemm_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.xgemm_p * TABLE_NAME.xgemm_q * 32 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
		       ) / (TABLE_NAME.xgemm_q * 32) - 15) & ~15);

  TABLE_NAME.xgemm3m_r = (((BUFFER_SIZE -
			       ((TABLE_NAME.xgemm3m_p * TABLE_NAME.xgemm3m_q * 32 + TABLE_NAME.offsetA
				 + TABLE_NAME.align) & ~TABLE_NAME.align)
		       ) / (TABLE_NAME.xgemm3m_q * 32) - 15) & ~15);

#endif



}
#endif //POWER
#endif //ZARCH
#endif //(ARCH_LOONGARCH64)
#endif //(ARCH_MIPS64)
#endif //(ARCH_ARM64)
