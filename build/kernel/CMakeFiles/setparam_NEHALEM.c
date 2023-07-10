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
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_NEHALEM;  OR    */
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
#include "kernel_NEHALEM.h"
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

  sbstobf16_k_NEHALEM, sbdtobf16_k_NEHALEM, sbf16tos_k_NEHALEM, dbf16tod_k_NEHALEM,

  samax_k_NEHALEM,  samin_k_NEHALEM,  smax_k_NEHALEM,  smin_k_NEHALEM,
  isamax_k_NEHALEM, isamin_k_NEHALEM, ismax_k_NEHALEM, ismin_k_NEHALEM,
  snrm2_k_NEHALEM,  sasum_k_NEHALEM, ssum_k_NEHALEM, scopy_k_NEHALEM, sbdot_k_NEHALEM,
  dsdot_k_NEHALEM,
  srot_k_NEHALEM,   saxpy_k_NEHALEM,  sscal_k_NEHALEM, sswap_k_NEHALEM,
  sbgemv_n_NEHALEM, sbgemv_t_NEHALEM, sger_k_NEHALEM,
  ssymv_L_NEHALEM, ssymv_U_NEHALEM,

  sbgemm_kernel_NEHALEM, sbgemm_beta_NEHALEM,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_NEHALEM, sbgemm_itcopy_NEHALEM,
#else
  sbgemm_oncopy_NEHALEM, sbgemm_otcopy_NEHALEM,
#endif
  sbgemm_oncopy_NEHALEM, sbgemm_otcopy_NEHALEM,

  strsm_kernel_LN_NEHALEM, strsm_kernel_LT_NEHALEM, strsm_kernel_RN_NEHALEM, strsm_kernel_RT_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_NEHALEM, strsm_iunncopy_NEHALEM, strsm_iutucopy_NEHALEM, strsm_iutncopy_NEHALEM,
  strsm_ilnucopy_NEHALEM, strsm_ilnncopy_NEHALEM, strsm_iltucopy_NEHALEM, strsm_iltncopy_NEHALEM,
#else
  strsm_ounucopy_NEHALEM, strsm_ounncopy_NEHALEM, strsm_outucopy_NEHALEM, strsm_outncopy_NEHALEM,
  strsm_olnucopy_NEHALEM, strsm_olnncopy_NEHALEM, strsm_oltucopy_NEHALEM, strsm_oltncopy_NEHALEM,
#endif
  strsm_ounucopy_NEHALEM, strsm_ounncopy_NEHALEM, strsm_outucopy_NEHALEM, strsm_outncopy_NEHALEM,
  strsm_olnucopy_NEHALEM, strsm_olnncopy_NEHALEM, strsm_oltucopy_NEHALEM, strsm_oltncopy_NEHALEM,
  strmm_kernel_RN_NEHALEM, strmm_kernel_RT_NEHALEM, strmm_kernel_LN_NEHALEM, strmm_kernel_LT_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_NEHALEM, strmm_iunncopy_NEHALEM, strmm_iutucopy_NEHALEM, strmm_iutncopy_NEHALEM,
  strmm_ilnucopy_NEHALEM, strmm_ilnncopy_NEHALEM, strmm_iltucopy_NEHALEM, strmm_iltncopy_NEHALEM,
#else
  strmm_ounucopy_NEHALEM, strmm_ounncopy_NEHALEM, strmm_outucopy_NEHALEM, strmm_outncopy_NEHALEM,
  strmm_olnucopy_NEHALEM, strmm_olnncopy_NEHALEM, strmm_oltucopy_NEHALEM, strmm_oltncopy_NEHALEM,
#endif
  strmm_ounucopy_NEHALEM, strmm_ounncopy_NEHALEM, strmm_outucopy_NEHALEM, strmm_outncopy_NEHALEM,
  strmm_olnucopy_NEHALEM, strmm_olnncopy_NEHALEM, strmm_oltucopy_NEHALEM, strmm_oltncopy_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_NEHALEM, ssymm_iltcopy_NEHALEM,
#else
  ssymm_outcopy_NEHALEM, ssymm_oltcopy_NEHALEM,
#endif
  ssymm_outcopy_NEHALEM, ssymm_oltcopy_NEHALEM,

#ifndef NO_LAPACK
  sneg_tcopy_NEHALEM, slaswp_ncopy_NEHALEM,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_NEHALEM,
  sbgemm_small_kernel_nn_NEHALEM, sbgemm_small_kernel_nt_NEHALEM, sbgemm_small_kernel_tn_NEHALEM, sbgemm_small_kernel_tt_NEHALEM,
  sbgemm_small_kernel_b0_nn_NEHALEM, sbgemm_small_kernel_b0_nt_NEHALEM, sbgemm_small_kernel_b0_tn_NEHALEM, sbgemm_small_kernel_b0_tt_NEHALEM,
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
  samax_k_NEHALEM,  samin_k_NEHALEM,  smax_k_NEHALEM,  smin_k_NEHALEM,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_NEHALEM,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_NEHALEM, ismax_k_NEHALEM, ismin_k_NEHALEM,
  snrm2_k_NEHALEM,  sasum_k_NEHALEM,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_NEHALEM,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_NEHALEM, sdot_k_NEHALEM,
//  dsdot_k_NEHALEM,
  srot_k_NEHALEM,   saxpy_k_NEHALEM,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_NEHALEM,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_NEHALEM,
  sgemv_n_NEHALEM,  sgemv_t_NEHALEM,
#endif
#if BUILD_SINGLE == 1
  sger_k_NEHALEM,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_NEHALEM, ssymv_U_NEHALEM,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_NEHALEM,
  sgemm_direct_performant_NEHALEM,	
#endif

  sgemm_kernel_NEHALEM, sgemm_beta_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_NEHALEM, sgemm_itcopy_NEHALEM,
#else
  sgemm_oncopy_NEHALEM, sgemm_otcopy_NEHALEM,
#endif
  sgemm_oncopy_NEHALEM, sgemm_otcopy_NEHALEM,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_NEHALEM,
  sgemm_small_kernel_nn_NEHALEM, sgemm_small_kernel_nt_NEHALEM, sgemm_small_kernel_tn_NEHALEM, sgemm_small_kernel_tt_NEHALEM,
  sgemm_small_kernel_b0_nn_NEHALEM, sgemm_small_kernel_b0_nt_NEHALEM, sgemm_small_kernel_b0_tn_NEHALEM, sgemm_small_kernel_b0_tt_NEHALEM,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_NEHALEM, strsm_kernel_LT_NEHALEM, strsm_kernel_RN_NEHALEM, strsm_kernel_RT_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_NEHALEM, strsm_iunncopy_NEHALEM, strsm_iutucopy_NEHALEM, strsm_iutncopy_NEHALEM,
  strsm_ilnucopy_NEHALEM, strsm_ilnncopy_NEHALEM, strsm_iltucopy_NEHALEM, strsm_iltncopy_NEHALEM,
#else
  strsm_ounucopy_NEHALEM, strsm_ounncopy_NEHALEM, strsm_outucopy_NEHALEM, strsm_outncopy_NEHALEM,
  strsm_olnucopy_NEHALEM, strsm_olnncopy_NEHALEM, strsm_oltucopy_NEHALEM, strsm_oltncopy_NEHALEM,
#endif
  strsm_ounucopy_NEHALEM, strsm_ounncopy_NEHALEM, strsm_outucopy_NEHALEM, strsm_outncopy_NEHALEM,
  strsm_olnucopy_NEHALEM, strsm_olnncopy_NEHALEM, strsm_oltucopy_NEHALEM, strsm_oltncopy_NEHALEM,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_NEHALEM, strmm_kernel_RT_NEHALEM, strmm_kernel_LN_NEHALEM, strmm_kernel_LT_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_NEHALEM, strmm_iunncopy_NEHALEM, strmm_iutucopy_NEHALEM, strmm_iutncopy_NEHALEM,
  strmm_ilnucopy_NEHALEM, strmm_ilnncopy_NEHALEM, strmm_iltucopy_NEHALEM, strmm_iltncopy_NEHALEM,
#else
  strmm_ounucopy_NEHALEM, strmm_ounncopy_NEHALEM, strmm_outucopy_NEHALEM, strmm_outncopy_NEHALEM,
  strmm_olnucopy_NEHALEM, strmm_olnncopy_NEHALEM, strmm_oltucopy_NEHALEM, strmm_oltncopy_NEHALEM,
#endif
  strmm_ounucopy_NEHALEM, strmm_ounncopy_NEHALEM, strmm_outucopy_NEHALEM, strmm_outncopy_NEHALEM,
  strmm_olnucopy_NEHALEM, strmm_olnncopy_NEHALEM, strmm_oltucopy_NEHALEM, strmm_oltncopy_NEHALEM,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_NEHALEM, ssymm_iltcopy_NEHALEM,
#else
  ssymm_outcopy_NEHALEM, ssymm_oltcopy_NEHALEM,
#endif
  ssymm_outcopy_NEHALEM, ssymm_oltcopy_NEHALEM,
#ifndef NO_LAPACK
  sneg_tcopy_NEHALEM, slaswp_ncopy_NEHALEM,
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
  damax_k_NEHALEM,  damin_k_NEHALEM,  dmax_k_NEHALEM,  dmin_k_NEHALEM,
  idamax_k_NEHALEM, idamin_k_NEHALEM, idmax_k_NEHALEM, idmin_k_NEHALEM,
  dnrm2_k_NEHALEM, dasum_k_NEHALEM,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_NEHALEM,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_NEHALEM, ddot_k_NEHALEM,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_NEHALEM,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_NEHALEM,
  daxpy_k_NEHALEM,
  dscal_k_NEHALEM, 
  dswap_k_NEHALEM,
  dgemv_n_NEHALEM,  dgemv_t_NEHALEM,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_NEHALEM,
  dsymv_L_NEHALEM,  dsymv_U_NEHALEM,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_NEHALEM, dgemm_beta_NEHALEM,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_NEHALEM, dgemm_itcopy_NEHALEM,
#else
  dgemm_oncopy_NEHALEM, dgemm_otcopy_NEHALEM,
#endif
  dgemm_oncopy_NEHALEM, dgemm_otcopy_NEHALEM,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_NEHALEM,
  dgemm_small_kernel_nn_NEHALEM, dgemm_small_kernel_nt_NEHALEM, dgemm_small_kernel_tn_NEHALEM, dgemm_small_kernel_tt_NEHALEM,
  dgemm_small_kernel_b0_nn_NEHALEM, dgemm_small_kernel_b0_nt_NEHALEM, dgemm_small_kernel_b0_tn_NEHALEM, dgemm_small_kernel_b0_tt_NEHALEM,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_NEHALEM, dtrsm_kernel_LT_NEHALEM, dtrsm_kernel_RN_NEHALEM, dtrsm_kernel_RT_NEHALEM,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_NEHALEM, dtrsm_iunncopy_NEHALEM, dtrsm_iutucopy_NEHALEM, dtrsm_iutncopy_NEHALEM,
  dtrsm_ilnucopy_NEHALEM, dtrsm_ilnncopy_NEHALEM, dtrsm_iltucopy_NEHALEM, dtrsm_iltncopy_NEHALEM,
#else
  dtrsm_ounucopy_NEHALEM, dtrsm_ounncopy_NEHALEM, dtrsm_outucopy_NEHALEM, dtrsm_outncopy_NEHALEM,
  dtrsm_olnucopy_NEHALEM, dtrsm_olnncopy_NEHALEM, dtrsm_oltucopy_NEHALEM, dtrsm_oltncopy_NEHALEM,
#endif
  dtrsm_ounucopy_NEHALEM, dtrsm_ounncopy_NEHALEM, dtrsm_outucopy_NEHALEM, dtrsm_outncopy_NEHALEM,
  dtrsm_olnucopy_NEHALEM, dtrsm_olnncopy_NEHALEM, dtrsm_oltucopy_NEHALEM, dtrsm_oltncopy_NEHALEM,
  dtrmm_kernel_RN_NEHALEM, dtrmm_kernel_RT_NEHALEM, dtrmm_kernel_LN_NEHALEM, dtrmm_kernel_LT_NEHALEM,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_NEHALEM, dtrmm_iunncopy_NEHALEM, dtrmm_iutucopy_NEHALEM, dtrmm_iutncopy_NEHALEM,
  dtrmm_ilnucopy_NEHALEM, dtrmm_ilnncopy_NEHALEM, dtrmm_iltucopy_NEHALEM, dtrmm_iltncopy_NEHALEM,
#else
  dtrmm_ounucopy_NEHALEM, dtrmm_ounncopy_NEHALEM, dtrmm_outucopy_NEHALEM, dtrmm_outncopy_NEHALEM,
  dtrmm_olnucopy_NEHALEM, dtrmm_olnncopy_NEHALEM, dtrmm_oltucopy_NEHALEM, dtrmm_oltncopy_NEHALEM,
#endif
  dtrmm_ounucopy_NEHALEM, dtrmm_ounncopy_NEHALEM, dtrmm_outucopy_NEHALEM, dtrmm_outncopy_NEHALEM,
  dtrmm_olnucopy_NEHALEM, dtrmm_olnncopy_NEHALEM, dtrmm_oltucopy_NEHALEM, dtrmm_oltncopy_NEHALEM,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_NEHALEM, dsymm_iltcopy_NEHALEM,
#else
  dsymm_outcopy_NEHALEM, dsymm_oltcopy_NEHALEM,
#endif
  dsymm_outcopy_NEHALEM, dsymm_oltcopy_NEHALEM,

#ifndef NO_LAPACK
  dneg_tcopy_NEHALEM, dlaswp_ncopy_NEHALEM,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_NEHALEM,  qamin_k_NEHALEM,  qmax_k_NEHALEM,  qmin_k_NEHALEM,
  iqamax_k_NEHALEM, iqamin_k_NEHALEM, iqmax_k_NEHALEM, iqmin_k_NEHALEM,
  qnrm2_k_NEHALEM,  qasum_k_NEHALEM,  qsum_k_NEHALEM, qcopy_k_NEHALEM, qdot_k_NEHALEM,
  qrot_k_NEHALEM,   qaxpy_k_NEHALEM,  qscal_k_NEHALEM, qswap_k_NEHALEM,
  qgemv_n_NEHALEM,  qgemv_t_NEHALEM,  qger_k_NEHALEM,
  qsymv_L_NEHALEM,  qsymv_U_NEHALEM,

  qgemm_kernel_NEHALEM, qgemm_beta_NEHALEM,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_NEHALEM, qgemm_itcopy_NEHALEM,
#else
  qgemm_oncopy_NEHALEM, qgemm_otcopy_NEHALEM,
#endif
  qgemm_oncopy_NEHALEM, qgemm_otcopy_NEHALEM,
  qtrsm_kernel_LN_NEHALEM, qtrsm_kernel_LT_NEHALEM, qtrsm_kernel_RN_NEHALEM, qtrsm_kernel_RT_NEHALEM,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_NEHALEM, qtrsm_iunncopy_NEHALEM, qtrsm_iutucopy_NEHALEM, qtrsm_iutncopy_NEHALEM,
  qtrsm_ilnucopy_NEHALEM, qtrsm_ilnncopy_NEHALEM, qtrsm_iltucopy_NEHALEM, qtrsm_iltncopy_NEHALEM,
#else
  qtrsm_ounucopy_NEHALEM, qtrsm_ounncopy_NEHALEM, qtrsm_outucopy_NEHALEM, qtrsm_outncopy_NEHALEM,
  qtrsm_olnucopy_NEHALEM, qtrsm_olnncopy_NEHALEM, qtrsm_oltucopy_NEHALEM, qtrsm_oltncopy_NEHALEM,
#endif
  qtrsm_ounucopy_NEHALEM, qtrsm_ounncopy_NEHALEM, qtrsm_outucopy_NEHALEM, qtrsm_outncopy_NEHALEM,
  qtrsm_olnucopy_NEHALEM, qtrsm_olnncopy_NEHALEM, qtrsm_oltucopy_NEHALEM, qtrsm_oltncopy_NEHALEM,
  qtrmm_kernel_RN_NEHALEM, qtrmm_kernel_RT_NEHALEM, qtrmm_kernel_LN_NEHALEM, qtrmm_kernel_LT_NEHALEM,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_NEHALEM, qtrmm_iunncopy_NEHALEM, qtrmm_iutucopy_NEHALEM, qtrmm_iutncopy_NEHALEM,
  qtrmm_ilnucopy_NEHALEM, qtrmm_ilnncopy_NEHALEM, qtrmm_iltucopy_NEHALEM, qtrmm_iltncopy_NEHALEM,
#else
  qtrmm_ounucopy_NEHALEM, qtrmm_ounncopy_NEHALEM, qtrmm_outucopy_NEHALEM, qtrmm_outncopy_NEHALEM,
  qtrmm_olnucopy_NEHALEM, qtrmm_olnncopy_NEHALEM, qtrmm_oltucopy_NEHALEM, qtrmm_oltncopy_NEHALEM,
#endif
  qtrmm_ounucopy_NEHALEM, qtrmm_ounncopy_NEHALEM, qtrmm_outucopy_NEHALEM, qtrmm_outncopy_NEHALEM,
  qtrmm_olnucopy_NEHALEM, qtrmm_olnncopy_NEHALEM, qtrmm_oltucopy_NEHALEM, qtrmm_oltncopy_NEHALEM,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_NEHALEM, qsymm_iltcopy_NEHALEM,
#else
  qsymm_outcopy_NEHALEM, qsymm_oltcopy_NEHALEM,
#endif
  qsymm_outcopy_NEHALEM, qsymm_oltcopy_NEHALEM,

#ifndef NO_LAPACK
  qneg_tcopy_NEHALEM, qlaswp_ncopy_NEHALEM,
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
  camax_k_NEHALEM, camin_k_NEHALEM,
#endif
#if (BUILD_COMPLEX)
  icamax_k_NEHALEM, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_NEHALEM,
  cnrm2_k_NEHALEM, casum_k_NEHALEM, csum_k_NEHALEM,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_NEHALEM, cdotu_k_NEHALEM, cdotc_k_NEHALEM,
#endif
#if (BUILD_COMPLEX)
 csrot_k_NEHALEM,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_NEHALEM,
  caxpyc_k_NEHALEM, 
  cscal_k_NEHALEM, 
  cswap_k_NEHALEM,

  cgemv_n_NEHALEM, cgemv_t_NEHALEM, cgemv_r_NEHALEM, cgemv_c_NEHALEM,
  cgemv_o_NEHALEM, cgemv_u_NEHALEM, cgemv_s_NEHALEM, cgemv_d_NEHALEM,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_NEHALEM, cgerc_k_NEHALEM, cgerv_k_NEHALEM, cgerd_k_NEHALEM,
  csymv_L_NEHALEM, csymv_U_NEHALEM,
  chemv_L_NEHALEM, chemv_U_NEHALEM, chemv_M_NEHALEM, chemv_V_NEHALEM,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_NEHALEM, cgemm_kernel_l_NEHALEM, cgemm_kernel_r_NEHALEM, cgemm_kernel_b_NEHALEM,
  cgemm_beta_NEHALEM,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_NEHALEM, cgemm_itcopy_NEHALEM,
#else
  cgemm_oncopy_NEHALEM, cgemm_otcopy_NEHALEM,
#endif
  cgemm_oncopy_NEHALEM, cgemm_otcopy_NEHALEM,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_NEHALEM,
  cgemm_small_kernel_nn_NEHALEM, cgemm_small_kernel_nt_NEHALEM, cgemm_small_kernel_nr_NEHALEM, cgemm_small_kernel_nc_NEHALEM,
  cgemm_small_kernel_tn_NEHALEM, cgemm_small_kernel_tt_NEHALEM, cgemm_small_kernel_tr_NEHALEM, cgemm_small_kernel_tc_NEHALEM,
  cgemm_small_kernel_rn_NEHALEM, cgemm_small_kernel_rt_NEHALEM, cgemm_small_kernel_rr_NEHALEM, cgemm_small_kernel_rc_NEHALEM,
  cgemm_small_kernel_cn_NEHALEM, cgemm_small_kernel_ct_NEHALEM, cgemm_small_kernel_cr_NEHALEM, cgemm_small_kernel_cc_NEHALEM,
  cgemm_small_kernel_b0_nn_NEHALEM, cgemm_small_kernel_b0_nt_NEHALEM, cgemm_small_kernel_b0_nr_NEHALEM, cgemm_small_kernel_b0_nc_NEHALEM,
  cgemm_small_kernel_b0_tn_NEHALEM, cgemm_small_kernel_b0_tt_NEHALEM, cgemm_small_kernel_b0_tr_NEHALEM, cgemm_small_kernel_b0_tc_NEHALEM,
  cgemm_small_kernel_b0_rn_NEHALEM, cgemm_small_kernel_b0_rt_NEHALEM, cgemm_small_kernel_b0_rr_NEHALEM, cgemm_small_kernel_b0_rc_NEHALEM,
  cgemm_small_kernel_b0_cn_NEHALEM, cgemm_small_kernel_b0_ct_NEHALEM, cgemm_small_kernel_b0_cr_NEHALEM, cgemm_small_kernel_b0_cc_NEHALEM,
#endif

  ctrsm_kernel_LN_NEHALEM, ctrsm_kernel_LT_NEHALEM, ctrsm_kernel_LR_NEHALEM, ctrsm_kernel_LC_NEHALEM,
  ctrsm_kernel_RN_NEHALEM, ctrsm_kernel_RT_NEHALEM, ctrsm_kernel_RR_NEHALEM, ctrsm_kernel_RC_NEHALEM,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_NEHALEM,  ctrsm_iunncopy_NEHALEM,  ctrsm_iutucopy_NEHALEM,  ctrsm_iutncopy_NEHALEM,
  ctrsm_ilnucopy_NEHALEM,  ctrsm_ilnncopy_NEHALEM,  ctrsm_iltucopy_NEHALEM,  ctrsm_iltncopy_NEHALEM,
#else
  ctrsm_ounucopy_NEHALEM,  ctrsm_ounncopy_NEHALEM,  ctrsm_outucopy_NEHALEM,  ctrsm_outncopy_NEHALEM,
  ctrsm_olnucopy_NEHALEM,  ctrsm_olnncopy_NEHALEM,  ctrsm_oltucopy_NEHALEM,  ctrsm_oltncopy_NEHALEM,
#endif
  ctrsm_ounucopy_NEHALEM,  ctrsm_ounncopy_NEHALEM,  ctrsm_outucopy_NEHALEM,  ctrsm_outncopy_NEHALEM,
  ctrsm_olnucopy_NEHALEM,  ctrsm_olnncopy_NEHALEM,  ctrsm_oltucopy_NEHALEM,  ctrsm_oltncopy_NEHALEM,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_NEHALEM,  ctrmm_kernel_RT_NEHALEM,  ctrmm_kernel_RR_NEHALEM,  ctrmm_kernel_RC_NEHALEM,
  ctrmm_kernel_LN_NEHALEM,  ctrmm_kernel_LT_NEHALEM,  ctrmm_kernel_LR_NEHALEM,  ctrmm_kernel_LC_NEHALEM,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_NEHALEM,  ctrmm_iunncopy_NEHALEM,  ctrmm_iutucopy_NEHALEM,  ctrmm_iutncopy_NEHALEM,
  ctrmm_ilnucopy_NEHALEM,  ctrmm_ilnncopy_NEHALEM,  ctrmm_iltucopy_NEHALEM,  ctrmm_iltncopy_NEHALEM,
#else
  ctrmm_ounucopy_NEHALEM,  ctrmm_ounncopy_NEHALEM,  ctrmm_outucopy_NEHALEM,  ctrmm_outncopy_NEHALEM,
  ctrmm_olnucopy_NEHALEM,  ctrmm_olnncopy_NEHALEM,  ctrmm_oltucopy_NEHALEM,  ctrmm_oltncopy_NEHALEM,
#endif
  ctrmm_ounucopy_NEHALEM,  ctrmm_ounncopy_NEHALEM,  ctrmm_outucopy_NEHALEM,  ctrmm_outncopy_NEHALEM,
  ctrmm_olnucopy_NEHALEM,  ctrmm_olnncopy_NEHALEM,  ctrmm_oltucopy_NEHALEM,  ctrmm_oltncopy_NEHALEM,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_NEHALEM,  csymm_iltcopy_NEHALEM,
#else
  csymm_outcopy_NEHALEM,  csymm_oltcopy_NEHALEM,
#endif
  csymm_outcopy_NEHALEM,  csymm_oltcopy_NEHALEM,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_NEHALEM,  chemm_iltcopy_NEHALEM,
#else
  chemm_outcopy_NEHALEM,  chemm_oltcopy_NEHALEM,
#endif
  chemm_outcopy_NEHALEM,  chemm_oltcopy_NEHALEM,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_NEHALEM,

  cgemm3m_incopyb_NEHALEM,  cgemm3m_incopyr_NEHALEM,
  cgemm3m_incopyi_NEHALEM,  cgemm3m_itcopyb_NEHALEM,
  cgemm3m_itcopyr_NEHALEM,  cgemm3m_itcopyi_NEHALEM,
  cgemm3m_oncopyb_NEHALEM,  cgemm3m_oncopyr_NEHALEM,
  cgemm3m_oncopyi_NEHALEM,  cgemm3m_otcopyb_NEHALEM,
  cgemm3m_otcopyr_NEHALEM,  cgemm3m_otcopyi_NEHALEM,

  csymm3m_iucopyb_NEHALEM,  csymm3m_ilcopyb_NEHALEM,
  csymm3m_iucopyr_NEHALEM,  csymm3m_ilcopyr_NEHALEM,
  csymm3m_iucopyi_NEHALEM,  csymm3m_ilcopyi_NEHALEM,
  csymm3m_oucopyb_NEHALEM,  csymm3m_olcopyb_NEHALEM,
  csymm3m_oucopyr_NEHALEM,  csymm3m_olcopyr_NEHALEM,
  csymm3m_oucopyi_NEHALEM,  csymm3m_olcopyi_NEHALEM,

  chemm3m_iucopyb_NEHALEM,  chemm3m_ilcopyb_NEHALEM,
  chemm3m_iucopyr_NEHALEM,  chemm3m_ilcopyr_NEHALEM,
  chemm3m_iucopyi_NEHALEM,  chemm3m_ilcopyi_NEHALEM,

  chemm3m_oucopyb_NEHALEM,  chemm3m_olcopyb_NEHALEM,
  chemm3m_oucopyr_NEHALEM,  chemm3m_olcopyr_NEHALEM,
  chemm3m_oucopyi_NEHALEM,  chemm3m_olcopyi_NEHALEM,
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
  cneg_tcopy_NEHALEM,
  
   claswp_ncopy_NEHALEM,
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

  zamax_k_NEHALEM, zamin_k_NEHALEM, izamax_k_NEHALEM, izamin_k_NEHALEM,
  znrm2_k_NEHALEM, zasum_k_NEHALEM, zsum_k_NEHALEM, zcopy_k_NEHALEM,
  zdotu_k_NEHALEM, zdotc_k_NEHALEM, zdrot_k_NEHALEM,
  zaxpy_k_NEHALEM, zaxpyc_k_NEHALEM, zscal_k_NEHALEM, zswap_k_NEHALEM,

  zgemv_n_NEHALEM, zgemv_t_NEHALEM, zgemv_r_NEHALEM, zgemv_c_NEHALEM,
  zgemv_o_NEHALEM, zgemv_u_NEHALEM, zgemv_s_NEHALEM, zgemv_d_NEHALEM,
  zgeru_k_NEHALEM, zgerc_k_NEHALEM, zgerv_k_NEHALEM, zgerd_k_NEHALEM,
  zsymv_L_NEHALEM, zsymv_U_NEHALEM,
  zhemv_L_NEHALEM, zhemv_U_NEHALEM, zhemv_M_NEHALEM, zhemv_V_NEHALEM,

  zgemm_kernel_n_NEHALEM, zgemm_kernel_l_NEHALEM, zgemm_kernel_r_NEHALEM, zgemm_kernel_b_NEHALEM,
  zgemm_beta_NEHALEM,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_NEHALEM, zgemm_itcopy_NEHALEM,
#else
  zgemm_oncopy_NEHALEM, zgemm_otcopy_NEHALEM,
#endif
  zgemm_oncopy_NEHALEM, zgemm_otcopy_NEHALEM,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_NEHALEM,
  zgemm_small_kernel_nn_NEHALEM, zgemm_small_kernel_nt_NEHALEM, zgemm_small_kernel_nr_NEHALEM, zgemm_small_kernel_nc_NEHALEM,
  zgemm_small_kernel_tn_NEHALEM, zgemm_small_kernel_tt_NEHALEM, zgemm_small_kernel_tr_NEHALEM, zgemm_small_kernel_tc_NEHALEM,
  zgemm_small_kernel_rn_NEHALEM, zgemm_small_kernel_rt_NEHALEM, zgemm_small_kernel_rr_NEHALEM, zgemm_small_kernel_rc_NEHALEM,
  zgemm_small_kernel_cn_NEHALEM, zgemm_small_kernel_ct_NEHALEM, zgemm_small_kernel_cr_NEHALEM, zgemm_small_kernel_cc_NEHALEM,
  zgemm_small_kernel_b0_nn_NEHALEM, zgemm_small_kernel_b0_nt_NEHALEM, zgemm_small_kernel_b0_nr_NEHALEM, zgemm_small_kernel_b0_nc_NEHALEM,
  zgemm_small_kernel_b0_tn_NEHALEM, zgemm_small_kernel_b0_tt_NEHALEM, zgemm_small_kernel_b0_tr_NEHALEM, zgemm_small_kernel_b0_tc_NEHALEM,
  zgemm_small_kernel_b0_rn_NEHALEM, zgemm_small_kernel_b0_rt_NEHALEM, zgemm_small_kernel_b0_rr_NEHALEM, zgemm_small_kernel_b0_rc_NEHALEM,
  zgemm_small_kernel_b0_cn_NEHALEM, zgemm_small_kernel_b0_ct_NEHALEM, zgemm_small_kernel_b0_cr_NEHALEM, zgemm_small_kernel_b0_cc_NEHALEM,
#endif

  ztrsm_kernel_LN_NEHALEM, ztrsm_kernel_LT_NEHALEM, ztrsm_kernel_LR_NEHALEM, ztrsm_kernel_LC_NEHALEM,
  ztrsm_kernel_RN_NEHALEM, ztrsm_kernel_RT_NEHALEM, ztrsm_kernel_RR_NEHALEM, ztrsm_kernel_RC_NEHALEM,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_NEHALEM,  ztrsm_iunncopy_NEHALEM,  ztrsm_iutucopy_NEHALEM,  ztrsm_iutncopy_NEHALEM,
  ztrsm_ilnucopy_NEHALEM,  ztrsm_ilnncopy_NEHALEM,  ztrsm_iltucopy_NEHALEM,  ztrsm_iltncopy_NEHALEM,
#else
  ztrsm_ounucopy_NEHALEM,  ztrsm_ounncopy_NEHALEM,  ztrsm_outucopy_NEHALEM,  ztrsm_outncopy_NEHALEM,
  ztrsm_olnucopy_NEHALEM,  ztrsm_olnncopy_NEHALEM,  ztrsm_oltucopy_NEHALEM,  ztrsm_oltncopy_NEHALEM,
#endif
  ztrsm_ounucopy_NEHALEM,  ztrsm_ounncopy_NEHALEM,  ztrsm_outucopy_NEHALEM,  ztrsm_outncopy_NEHALEM,
  ztrsm_olnucopy_NEHALEM,  ztrsm_olnncopy_NEHALEM,  ztrsm_oltucopy_NEHALEM,  ztrsm_oltncopy_NEHALEM,

  ztrmm_kernel_RN_NEHALEM,  ztrmm_kernel_RT_NEHALEM,  ztrmm_kernel_RR_NEHALEM,  ztrmm_kernel_RC_NEHALEM,
  ztrmm_kernel_LN_NEHALEM,  ztrmm_kernel_LT_NEHALEM,  ztrmm_kernel_LR_NEHALEM,  ztrmm_kernel_LC_NEHALEM,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_NEHALEM,  ztrmm_iunncopy_NEHALEM,  ztrmm_iutucopy_NEHALEM,  ztrmm_iutncopy_NEHALEM,
  ztrmm_ilnucopy_NEHALEM,  ztrmm_ilnncopy_NEHALEM,  ztrmm_iltucopy_NEHALEM,  ztrmm_iltncopy_NEHALEM,
#else
  ztrmm_ounucopy_NEHALEM,  ztrmm_ounncopy_NEHALEM,  ztrmm_outucopy_NEHALEM,  ztrmm_outncopy_NEHALEM,
  ztrmm_olnucopy_NEHALEM,  ztrmm_olnncopy_NEHALEM,  ztrmm_oltucopy_NEHALEM,  ztrmm_oltncopy_NEHALEM,
#endif
  ztrmm_ounucopy_NEHALEM,  ztrmm_ounncopy_NEHALEM,  ztrmm_outucopy_NEHALEM,  ztrmm_outncopy_NEHALEM,
  ztrmm_olnucopy_NEHALEM,  ztrmm_olnncopy_NEHALEM,  ztrmm_oltucopy_NEHALEM,  ztrmm_oltncopy_NEHALEM,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_NEHALEM,  zsymm_iltcopy_NEHALEM,
#else
  zsymm_outcopy_NEHALEM,  zsymm_oltcopy_NEHALEM,
#endif
  zsymm_outcopy_NEHALEM,  zsymm_oltcopy_NEHALEM,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_NEHALEM,  zhemm_iltcopy_NEHALEM,
#else
  zhemm_outcopy_NEHALEM,  zhemm_oltcopy_NEHALEM,
#endif
  zhemm_outcopy_NEHALEM,  zhemm_oltcopy_NEHALEM,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_NEHALEM,

  zgemm3m_incopyb_NEHALEM,  zgemm3m_incopyr_NEHALEM,
  zgemm3m_incopyi_NEHALEM,  zgemm3m_itcopyb_NEHALEM,
  zgemm3m_itcopyr_NEHALEM,  zgemm3m_itcopyi_NEHALEM,
  zgemm3m_oncopyb_NEHALEM,  zgemm3m_oncopyr_NEHALEM,
  zgemm3m_oncopyi_NEHALEM,  zgemm3m_otcopyb_NEHALEM,
  zgemm3m_otcopyr_NEHALEM,  zgemm3m_otcopyi_NEHALEM,

  zsymm3m_iucopyb_NEHALEM,  zsymm3m_ilcopyb_NEHALEM,
  zsymm3m_iucopyr_NEHALEM,  zsymm3m_ilcopyr_NEHALEM,
  zsymm3m_iucopyi_NEHALEM,  zsymm3m_ilcopyi_NEHALEM,
  zsymm3m_oucopyb_NEHALEM,  zsymm3m_olcopyb_NEHALEM,
  zsymm3m_oucopyr_NEHALEM,  zsymm3m_olcopyr_NEHALEM,
  zsymm3m_oucopyi_NEHALEM,  zsymm3m_olcopyi_NEHALEM,

  zhemm3m_iucopyb_NEHALEM,  zhemm3m_ilcopyb_NEHALEM,
  zhemm3m_iucopyr_NEHALEM,  zhemm3m_ilcopyr_NEHALEM,
  zhemm3m_iucopyi_NEHALEM,  zhemm3m_ilcopyi_NEHALEM,

  zhemm3m_oucopyb_NEHALEM,  zhemm3m_olcopyb_NEHALEM,
  zhemm3m_oucopyr_NEHALEM,  zhemm3m_olcopyr_NEHALEM,
  zhemm3m_oucopyi_NEHALEM,  zhemm3m_olcopyi_NEHALEM,
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
  zneg_tcopy_NEHALEM, zlaswp_ncopy_NEHALEM,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_NEHALEM, xamin_k_NEHALEM, ixamax_k_NEHALEM, ixamin_k_NEHALEM,
  xnrm2_k_NEHALEM, xasum_k_NEHALEM, xsum_k_NEHALEM, xcopy_k_NEHALEM,
  xdotu_k_NEHALEM, xdotc_k_NEHALEM, xqrot_k_NEHALEM,
  xaxpy_k_NEHALEM, xaxpyc_k_NEHALEM, xscal_k_NEHALEM, xswap_k_NEHALEM,

  xgemv_n_NEHALEM, xgemv_t_NEHALEM, xgemv_r_NEHALEM, xgemv_c_NEHALEM,
  xgemv_o_NEHALEM, xgemv_u_NEHALEM, xgemv_s_NEHALEM, xgemv_d_NEHALEM,
  xgeru_k_NEHALEM, xgerc_k_NEHALEM, xgerv_k_NEHALEM, xgerd_k_NEHALEM,
  xsymv_L_NEHALEM, xsymv_U_NEHALEM,
  xhemv_L_NEHALEM, xhemv_U_NEHALEM, xhemv_M_NEHALEM, xhemv_V_NEHALEM,

  xgemm_kernel_n_NEHALEM, xgemm_kernel_l_NEHALEM, xgemm_kernel_r_NEHALEM, xgemm_kernel_b_NEHALEM,
  xgemm_beta_NEHALEM,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_NEHALEM, xgemm_itcopy_NEHALEM,
#else
  xgemm_oncopy_NEHALEM, xgemm_otcopy_NEHALEM,
#endif
  xgemm_oncopy_NEHALEM, xgemm_otcopy_NEHALEM,

  xtrsm_kernel_LN_NEHALEM, xtrsm_kernel_LT_NEHALEM, xtrsm_kernel_LR_NEHALEM, xtrsm_kernel_LC_NEHALEM,
  xtrsm_kernel_RN_NEHALEM, xtrsm_kernel_RT_NEHALEM, xtrsm_kernel_RR_NEHALEM, xtrsm_kernel_RC_NEHALEM,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_NEHALEM,  xtrsm_iunncopy_NEHALEM,  xtrsm_iutucopy_NEHALEM,  xtrsm_iutncopy_NEHALEM,
  xtrsm_ilnucopy_NEHALEM,  xtrsm_ilnncopy_NEHALEM,  xtrsm_iltucopy_NEHALEM,  xtrsm_iltncopy_NEHALEM,
#else
  xtrsm_ounucopy_NEHALEM,  xtrsm_ounncopy_NEHALEM,  xtrsm_outucopy_NEHALEM,  xtrsm_outncopy_NEHALEM,
  xtrsm_olnucopy_NEHALEM,  xtrsm_olnncopy_NEHALEM,  xtrsm_oltucopy_NEHALEM,  xtrsm_oltncopy_NEHALEM,
#endif
  xtrsm_ounucopy_NEHALEM,  xtrsm_ounncopy_NEHALEM,  xtrsm_outucopy_NEHALEM,  xtrsm_outncopy_NEHALEM,
  xtrsm_olnucopy_NEHALEM,  xtrsm_olnncopy_NEHALEM,  xtrsm_oltucopy_NEHALEM,  xtrsm_oltncopy_NEHALEM,

  xtrmm_kernel_RN_NEHALEM,  xtrmm_kernel_RT_NEHALEM,  xtrmm_kernel_RR_NEHALEM,  xtrmm_kernel_RC_NEHALEM,
  xtrmm_kernel_LN_NEHALEM,  xtrmm_kernel_LT_NEHALEM,  xtrmm_kernel_LR_NEHALEM,  xtrmm_kernel_LC_NEHALEM,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_NEHALEM,  xtrmm_iunncopy_NEHALEM,  xtrmm_iutucopy_NEHALEM,  xtrmm_iutncopy_NEHALEM,
  xtrmm_ilnucopy_NEHALEM,  xtrmm_ilnncopy_NEHALEM,  xtrmm_iltucopy_NEHALEM,  xtrmm_iltncopy_NEHALEM,
#else
  xtrmm_ounucopy_NEHALEM,  xtrmm_ounncopy_NEHALEM,  xtrmm_outucopy_NEHALEM,  xtrmm_outncopy_NEHALEM,
  xtrmm_olnucopy_NEHALEM,  xtrmm_olnncopy_NEHALEM,  xtrmm_oltucopy_NEHALEM,  xtrmm_oltncopy_NEHALEM,
#endif
  xtrmm_ounucopy_NEHALEM,  xtrmm_ounncopy_NEHALEM,  xtrmm_outucopy_NEHALEM,  xtrmm_outncopy_NEHALEM,
  xtrmm_olnucopy_NEHALEM,  xtrmm_olnncopy_NEHALEM,  xtrmm_oltucopy_NEHALEM,  xtrmm_oltncopy_NEHALEM,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_NEHALEM,  xsymm_iltcopy_NEHALEM,
#else
  xsymm_outcopy_NEHALEM,  xsymm_oltcopy_NEHALEM,
#endif
  xsymm_outcopy_NEHALEM,  xsymm_oltcopy_NEHALEM,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_NEHALEM,  xhemm_iltcopy_NEHALEM,
#else
  xhemm_outcopy_NEHALEM,  xhemm_oltcopy_NEHALEM,
#endif
  xhemm_outcopy_NEHALEM,  xhemm_oltcopy_NEHALEM,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_NEHALEM,

  xgemm3m_incopyb_NEHALEM,  xgemm3m_incopyr_NEHALEM,
  xgemm3m_incopyi_NEHALEM,  xgemm3m_itcopyb_NEHALEM,
  xgemm3m_itcopyr_NEHALEM,  xgemm3m_itcopyi_NEHALEM,
  xgemm3m_oncopyb_NEHALEM,  xgemm3m_oncopyr_NEHALEM,
  xgemm3m_oncopyi_NEHALEM,  xgemm3m_otcopyb_NEHALEM,
  xgemm3m_otcopyr_NEHALEM,  xgemm3m_otcopyi_NEHALEM,

  xsymm3m_iucopyb_NEHALEM,  xsymm3m_ilcopyb_NEHALEM,
  xsymm3m_iucopyr_NEHALEM,  xsymm3m_ilcopyr_NEHALEM,
  xsymm3m_iucopyi_NEHALEM,  xsymm3m_ilcopyi_NEHALEM,
  xsymm3m_oucopyb_NEHALEM,  xsymm3m_olcopyb_NEHALEM,
  xsymm3m_oucopyr_NEHALEM,  xsymm3m_olcopyr_NEHALEM,
  xsymm3m_oucopyi_NEHALEM,  xsymm3m_olcopyi_NEHALEM,

  xhemm3m_iucopyb_NEHALEM,  xhemm3m_ilcopyb_NEHALEM,
  xhemm3m_iucopyr_NEHALEM,  xhemm3m_ilcopyr_NEHALEM,
  xhemm3m_iucopyi_NEHALEM,  xhemm3m_ilcopyi_NEHALEM,

  xhemm3m_oucopyb_NEHALEM,  xhemm3m_olcopyb_NEHALEM,
  xhemm3m_oucopyr_NEHALEM,  xhemm3m_olcopyr_NEHALEM,
  xhemm3m_oucopyi_NEHALEM,  xhemm3m_olcopyi_NEHALEM,
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
  xneg_tcopy_NEHALEM, xlaswp_ncopy_NEHALEM,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_NEHALEM,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_NEHALEM,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_NEHALEM,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_NEHALEM,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_NEHALEM, somatcopy_k_ct_NEHALEM, somatcopy_k_rn_NEHALEM, somatcopy_k_rt_NEHALEM,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_NEHALEM, domatcopy_k_ct_NEHALEM, domatcopy_k_rn_NEHALEM, domatcopy_k_rt_NEHALEM,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_NEHALEM, comatcopy_k_ct_NEHALEM, comatcopy_k_rn_NEHALEM, comatcopy_k_rt_NEHALEM,
  comatcopy_k_cnc_NEHALEM, comatcopy_k_ctc_NEHALEM, comatcopy_k_rnc_NEHALEM, comatcopy_k_rtc_NEHALEM,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_NEHALEM, zomatcopy_k_ct_NEHALEM, zomatcopy_k_rn_NEHALEM, zomatcopy_k_rt_NEHALEM,
  zomatcopy_k_cnc_NEHALEM, zomatcopy_k_ctc_NEHALEM, zomatcopy_k_rnc_NEHALEM, zomatcopy_k_rtc_NEHALEM,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_NEHALEM, simatcopy_k_ct_NEHALEM, simatcopy_k_rn_NEHALEM, simatcopy_k_rt_NEHALEM,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_NEHALEM, dimatcopy_k_ct_NEHALEM, dimatcopy_k_rn_NEHALEM, dimatcopy_k_rt_NEHALEM,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_NEHALEM, cimatcopy_k_ct_NEHALEM, cimatcopy_k_rn_NEHALEM, cimatcopy_k_rt_NEHALEM,
  cimatcopy_k_cnc_NEHALEM, cimatcopy_k_ctc_NEHALEM, cimatcopy_k_rnc_NEHALEM, cimatcopy_k_rtc_NEHALEM,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_NEHALEM, zimatcopy_k_ct_NEHALEM, zimatcopy_k_rn_NEHALEM, zimatcopy_k_rt_NEHALEM,
  zimatcopy_k_cnc_NEHALEM, zimatcopy_k_ctc_NEHALEM, zimatcopy_k_rnc_NEHALEM, zimatcopy_k_rtc_NEHALEM,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_NEHALEM,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_NEHALEM,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_NEHALEM,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_NEHALEM,
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
