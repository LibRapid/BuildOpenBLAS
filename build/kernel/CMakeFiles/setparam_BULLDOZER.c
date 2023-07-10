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
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_BULLDOZER;  OR    */
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
#include "kernel_BULLDOZER.h"
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

  sbstobf16_k_BULLDOZER, sbdtobf16_k_BULLDOZER, sbf16tos_k_BULLDOZER, dbf16tod_k_BULLDOZER,

  samax_k_BULLDOZER,  samin_k_BULLDOZER,  smax_k_BULLDOZER,  smin_k_BULLDOZER,
  isamax_k_BULLDOZER, isamin_k_BULLDOZER, ismax_k_BULLDOZER, ismin_k_BULLDOZER,
  snrm2_k_BULLDOZER,  sasum_k_BULLDOZER, ssum_k_BULLDOZER, scopy_k_BULLDOZER, sbdot_k_BULLDOZER,
  dsdot_k_BULLDOZER,
  srot_k_BULLDOZER,   saxpy_k_BULLDOZER,  sscal_k_BULLDOZER, sswap_k_BULLDOZER,
  sbgemv_n_BULLDOZER, sbgemv_t_BULLDOZER, sger_k_BULLDOZER,
  ssymv_L_BULLDOZER, ssymv_U_BULLDOZER,

  sbgemm_kernel_BULLDOZER, sbgemm_beta_BULLDOZER,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_BULLDOZER, sbgemm_itcopy_BULLDOZER,
#else
  sbgemm_oncopy_BULLDOZER, sbgemm_otcopy_BULLDOZER,
#endif
  sbgemm_oncopy_BULLDOZER, sbgemm_otcopy_BULLDOZER,

  strsm_kernel_LN_BULLDOZER, strsm_kernel_LT_BULLDOZER, strsm_kernel_RN_BULLDOZER, strsm_kernel_RT_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_BULLDOZER, strsm_iunncopy_BULLDOZER, strsm_iutucopy_BULLDOZER, strsm_iutncopy_BULLDOZER,
  strsm_ilnucopy_BULLDOZER, strsm_ilnncopy_BULLDOZER, strsm_iltucopy_BULLDOZER, strsm_iltncopy_BULLDOZER,
#else
  strsm_ounucopy_BULLDOZER, strsm_ounncopy_BULLDOZER, strsm_outucopy_BULLDOZER, strsm_outncopy_BULLDOZER,
  strsm_olnucopy_BULLDOZER, strsm_olnncopy_BULLDOZER, strsm_oltucopy_BULLDOZER, strsm_oltncopy_BULLDOZER,
#endif
  strsm_ounucopy_BULLDOZER, strsm_ounncopy_BULLDOZER, strsm_outucopy_BULLDOZER, strsm_outncopy_BULLDOZER,
  strsm_olnucopy_BULLDOZER, strsm_olnncopy_BULLDOZER, strsm_oltucopy_BULLDOZER, strsm_oltncopy_BULLDOZER,
  strmm_kernel_RN_BULLDOZER, strmm_kernel_RT_BULLDOZER, strmm_kernel_LN_BULLDOZER, strmm_kernel_LT_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_BULLDOZER, strmm_iunncopy_BULLDOZER, strmm_iutucopy_BULLDOZER, strmm_iutncopy_BULLDOZER,
  strmm_ilnucopy_BULLDOZER, strmm_ilnncopy_BULLDOZER, strmm_iltucopy_BULLDOZER, strmm_iltncopy_BULLDOZER,
#else
  strmm_ounucopy_BULLDOZER, strmm_ounncopy_BULLDOZER, strmm_outucopy_BULLDOZER, strmm_outncopy_BULLDOZER,
  strmm_olnucopy_BULLDOZER, strmm_olnncopy_BULLDOZER, strmm_oltucopy_BULLDOZER, strmm_oltncopy_BULLDOZER,
#endif
  strmm_ounucopy_BULLDOZER, strmm_ounncopy_BULLDOZER, strmm_outucopy_BULLDOZER, strmm_outncopy_BULLDOZER,
  strmm_olnucopy_BULLDOZER, strmm_olnncopy_BULLDOZER, strmm_oltucopy_BULLDOZER, strmm_oltncopy_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_BULLDOZER, ssymm_iltcopy_BULLDOZER,
#else
  ssymm_outcopy_BULLDOZER, ssymm_oltcopy_BULLDOZER,
#endif
  ssymm_outcopy_BULLDOZER, ssymm_oltcopy_BULLDOZER,

#ifndef NO_LAPACK
  sneg_tcopy_BULLDOZER, slaswp_ncopy_BULLDOZER,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_BULLDOZER,
  sbgemm_small_kernel_nn_BULLDOZER, sbgemm_small_kernel_nt_BULLDOZER, sbgemm_small_kernel_tn_BULLDOZER, sbgemm_small_kernel_tt_BULLDOZER,
  sbgemm_small_kernel_b0_nn_BULLDOZER, sbgemm_small_kernel_b0_nt_BULLDOZER, sbgemm_small_kernel_b0_tn_BULLDOZER, sbgemm_small_kernel_b0_tt_BULLDOZER,
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
  samax_k_BULLDOZER,  samin_k_BULLDOZER,  smax_k_BULLDOZER,  smin_k_BULLDOZER,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_BULLDOZER,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_BULLDOZER, ismax_k_BULLDOZER, ismin_k_BULLDOZER,
  snrm2_k_BULLDOZER,  sasum_k_BULLDOZER,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_BULLDOZER,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_BULLDOZER, sdot_k_BULLDOZER,
//  dsdot_k_BULLDOZER,
  srot_k_BULLDOZER,   saxpy_k_BULLDOZER,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_BULLDOZER,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_BULLDOZER,
  sgemv_n_BULLDOZER,  sgemv_t_BULLDOZER,
#endif
#if BUILD_SINGLE == 1
  sger_k_BULLDOZER,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_BULLDOZER, ssymv_U_BULLDOZER,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_BULLDOZER,
  sgemm_direct_performant_BULLDOZER,	
#endif

  sgemm_kernel_BULLDOZER, sgemm_beta_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_BULLDOZER, sgemm_itcopy_BULLDOZER,
#else
  sgemm_oncopy_BULLDOZER, sgemm_otcopy_BULLDOZER,
#endif
  sgemm_oncopy_BULLDOZER, sgemm_otcopy_BULLDOZER,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_BULLDOZER,
  sgemm_small_kernel_nn_BULLDOZER, sgemm_small_kernel_nt_BULLDOZER, sgemm_small_kernel_tn_BULLDOZER, sgemm_small_kernel_tt_BULLDOZER,
  sgemm_small_kernel_b0_nn_BULLDOZER, sgemm_small_kernel_b0_nt_BULLDOZER, sgemm_small_kernel_b0_tn_BULLDOZER, sgemm_small_kernel_b0_tt_BULLDOZER,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_BULLDOZER, strsm_kernel_LT_BULLDOZER, strsm_kernel_RN_BULLDOZER, strsm_kernel_RT_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_BULLDOZER, strsm_iunncopy_BULLDOZER, strsm_iutucopy_BULLDOZER, strsm_iutncopy_BULLDOZER,
  strsm_ilnucopy_BULLDOZER, strsm_ilnncopy_BULLDOZER, strsm_iltucopy_BULLDOZER, strsm_iltncopy_BULLDOZER,
#else
  strsm_ounucopy_BULLDOZER, strsm_ounncopy_BULLDOZER, strsm_outucopy_BULLDOZER, strsm_outncopy_BULLDOZER,
  strsm_olnucopy_BULLDOZER, strsm_olnncopy_BULLDOZER, strsm_oltucopy_BULLDOZER, strsm_oltncopy_BULLDOZER,
#endif
  strsm_ounucopy_BULLDOZER, strsm_ounncopy_BULLDOZER, strsm_outucopy_BULLDOZER, strsm_outncopy_BULLDOZER,
  strsm_olnucopy_BULLDOZER, strsm_olnncopy_BULLDOZER, strsm_oltucopy_BULLDOZER, strsm_oltncopy_BULLDOZER,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_BULLDOZER, strmm_kernel_RT_BULLDOZER, strmm_kernel_LN_BULLDOZER, strmm_kernel_LT_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_BULLDOZER, strmm_iunncopy_BULLDOZER, strmm_iutucopy_BULLDOZER, strmm_iutncopy_BULLDOZER,
  strmm_ilnucopy_BULLDOZER, strmm_ilnncopy_BULLDOZER, strmm_iltucopy_BULLDOZER, strmm_iltncopy_BULLDOZER,
#else
  strmm_ounucopy_BULLDOZER, strmm_ounncopy_BULLDOZER, strmm_outucopy_BULLDOZER, strmm_outncopy_BULLDOZER,
  strmm_olnucopy_BULLDOZER, strmm_olnncopy_BULLDOZER, strmm_oltucopy_BULLDOZER, strmm_oltncopy_BULLDOZER,
#endif
  strmm_ounucopy_BULLDOZER, strmm_ounncopy_BULLDOZER, strmm_outucopy_BULLDOZER, strmm_outncopy_BULLDOZER,
  strmm_olnucopy_BULLDOZER, strmm_olnncopy_BULLDOZER, strmm_oltucopy_BULLDOZER, strmm_oltncopy_BULLDOZER,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_BULLDOZER, ssymm_iltcopy_BULLDOZER,
#else
  ssymm_outcopy_BULLDOZER, ssymm_oltcopy_BULLDOZER,
#endif
  ssymm_outcopy_BULLDOZER, ssymm_oltcopy_BULLDOZER,
#ifndef NO_LAPACK
  sneg_tcopy_BULLDOZER, slaswp_ncopy_BULLDOZER,
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
  damax_k_BULLDOZER,  damin_k_BULLDOZER,  dmax_k_BULLDOZER,  dmin_k_BULLDOZER,
  idamax_k_BULLDOZER, idamin_k_BULLDOZER, idmax_k_BULLDOZER, idmin_k_BULLDOZER,
  dnrm2_k_BULLDOZER, dasum_k_BULLDOZER,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_BULLDOZER,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_BULLDOZER, ddot_k_BULLDOZER,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_BULLDOZER,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_BULLDOZER,
  daxpy_k_BULLDOZER,
  dscal_k_BULLDOZER, 
  dswap_k_BULLDOZER,
  dgemv_n_BULLDOZER,  dgemv_t_BULLDOZER,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_BULLDOZER,
  dsymv_L_BULLDOZER,  dsymv_U_BULLDOZER,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_BULLDOZER, dgemm_beta_BULLDOZER,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_BULLDOZER, dgemm_itcopy_BULLDOZER,
#else
  dgemm_oncopy_BULLDOZER, dgemm_otcopy_BULLDOZER,
#endif
  dgemm_oncopy_BULLDOZER, dgemm_otcopy_BULLDOZER,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_BULLDOZER,
  dgemm_small_kernel_nn_BULLDOZER, dgemm_small_kernel_nt_BULLDOZER, dgemm_small_kernel_tn_BULLDOZER, dgemm_small_kernel_tt_BULLDOZER,
  dgemm_small_kernel_b0_nn_BULLDOZER, dgemm_small_kernel_b0_nt_BULLDOZER, dgemm_small_kernel_b0_tn_BULLDOZER, dgemm_small_kernel_b0_tt_BULLDOZER,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_BULLDOZER, dtrsm_kernel_LT_BULLDOZER, dtrsm_kernel_RN_BULLDOZER, dtrsm_kernel_RT_BULLDOZER,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_BULLDOZER, dtrsm_iunncopy_BULLDOZER, dtrsm_iutucopy_BULLDOZER, dtrsm_iutncopy_BULLDOZER,
  dtrsm_ilnucopy_BULLDOZER, dtrsm_ilnncopy_BULLDOZER, dtrsm_iltucopy_BULLDOZER, dtrsm_iltncopy_BULLDOZER,
#else
  dtrsm_ounucopy_BULLDOZER, dtrsm_ounncopy_BULLDOZER, dtrsm_outucopy_BULLDOZER, dtrsm_outncopy_BULLDOZER,
  dtrsm_olnucopy_BULLDOZER, dtrsm_olnncopy_BULLDOZER, dtrsm_oltucopy_BULLDOZER, dtrsm_oltncopy_BULLDOZER,
#endif
  dtrsm_ounucopy_BULLDOZER, dtrsm_ounncopy_BULLDOZER, dtrsm_outucopy_BULLDOZER, dtrsm_outncopy_BULLDOZER,
  dtrsm_olnucopy_BULLDOZER, dtrsm_olnncopy_BULLDOZER, dtrsm_oltucopy_BULLDOZER, dtrsm_oltncopy_BULLDOZER,
  dtrmm_kernel_RN_BULLDOZER, dtrmm_kernel_RT_BULLDOZER, dtrmm_kernel_LN_BULLDOZER, dtrmm_kernel_LT_BULLDOZER,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_BULLDOZER, dtrmm_iunncopy_BULLDOZER, dtrmm_iutucopy_BULLDOZER, dtrmm_iutncopy_BULLDOZER,
  dtrmm_ilnucopy_BULLDOZER, dtrmm_ilnncopy_BULLDOZER, dtrmm_iltucopy_BULLDOZER, dtrmm_iltncopy_BULLDOZER,
#else
  dtrmm_ounucopy_BULLDOZER, dtrmm_ounncopy_BULLDOZER, dtrmm_outucopy_BULLDOZER, dtrmm_outncopy_BULLDOZER,
  dtrmm_olnucopy_BULLDOZER, dtrmm_olnncopy_BULLDOZER, dtrmm_oltucopy_BULLDOZER, dtrmm_oltncopy_BULLDOZER,
#endif
  dtrmm_ounucopy_BULLDOZER, dtrmm_ounncopy_BULLDOZER, dtrmm_outucopy_BULLDOZER, dtrmm_outncopy_BULLDOZER,
  dtrmm_olnucopy_BULLDOZER, dtrmm_olnncopy_BULLDOZER, dtrmm_oltucopy_BULLDOZER, dtrmm_oltncopy_BULLDOZER,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_BULLDOZER, dsymm_iltcopy_BULLDOZER,
#else
  dsymm_outcopy_BULLDOZER, dsymm_oltcopy_BULLDOZER,
#endif
  dsymm_outcopy_BULLDOZER, dsymm_oltcopy_BULLDOZER,

#ifndef NO_LAPACK
  dneg_tcopy_BULLDOZER, dlaswp_ncopy_BULLDOZER,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_BULLDOZER,  qamin_k_BULLDOZER,  qmax_k_BULLDOZER,  qmin_k_BULLDOZER,
  iqamax_k_BULLDOZER, iqamin_k_BULLDOZER, iqmax_k_BULLDOZER, iqmin_k_BULLDOZER,
  qnrm2_k_BULLDOZER,  qasum_k_BULLDOZER,  qsum_k_BULLDOZER, qcopy_k_BULLDOZER, qdot_k_BULLDOZER,
  qrot_k_BULLDOZER,   qaxpy_k_BULLDOZER,  qscal_k_BULLDOZER, qswap_k_BULLDOZER,
  qgemv_n_BULLDOZER,  qgemv_t_BULLDOZER,  qger_k_BULLDOZER,
  qsymv_L_BULLDOZER,  qsymv_U_BULLDOZER,

  qgemm_kernel_BULLDOZER, qgemm_beta_BULLDOZER,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_BULLDOZER, qgemm_itcopy_BULLDOZER,
#else
  qgemm_oncopy_BULLDOZER, qgemm_otcopy_BULLDOZER,
#endif
  qgemm_oncopy_BULLDOZER, qgemm_otcopy_BULLDOZER,
  qtrsm_kernel_LN_BULLDOZER, qtrsm_kernel_LT_BULLDOZER, qtrsm_kernel_RN_BULLDOZER, qtrsm_kernel_RT_BULLDOZER,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_BULLDOZER, qtrsm_iunncopy_BULLDOZER, qtrsm_iutucopy_BULLDOZER, qtrsm_iutncopy_BULLDOZER,
  qtrsm_ilnucopy_BULLDOZER, qtrsm_ilnncopy_BULLDOZER, qtrsm_iltucopy_BULLDOZER, qtrsm_iltncopy_BULLDOZER,
#else
  qtrsm_ounucopy_BULLDOZER, qtrsm_ounncopy_BULLDOZER, qtrsm_outucopy_BULLDOZER, qtrsm_outncopy_BULLDOZER,
  qtrsm_olnucopy_BULLDOZER, qtrsm_olnncopy_BULLDOZER, qtrsm_oltucopy_BULLDOZER, qtrsm_oltncopy_BULLDOZER,
#endif
  qtrsm_ounucopy_BULLDOZER, qtrsm_ounncopy_BULLDOZER, qtrsm_outucopy_BULLDOZER, qtrsm_outncopy_BULLDOZER,
  qtrsm_olnucopy_BULLDOZER, qtrsm_olnncopy_BULLDOZER, qtrsm_oltucopy_BULLDOZER, qtrsm_oltncopy_BULLDOZER,
  qtrmm_kernel_RN_BULLDOZER, qtrmm_kernel_RT_BULLDOZER, qtrmm_kernel_LN_BULLDOZER, qtrmm_kernel_LT_BULLDOZER,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_BULLDOZER, qtrmm_iunncopy_BULLDOZER, qtrmm_iutucopy_BULLDOZER, qtrmm_iutncopy_BULLDOZER,
  qtrmm_ilnucopy_BULLDOZER, qtrmm_ilnncopy_BULLDOZER, qtrmm_iltucopy_BULLDOZER, qtrmm_iltncopy_BULLDOZER,
#else
  qtrmm_ounucopy_BULLDOZER, qtrmm_ounncopy_BULLDOZER, qtrmm_outucopy_BULLDOZER, qtrmm_outncopy_BULLDOZER,
  qtrmm_olnucopy_BULLDOZER, qtrmm_olnncopy_BULLDOZER, qtrmm_oltucopy_BULLDOZER, qtrmm_oltncopy_BULLDOZER,
#endif
  qtrmm_ounucopy_BULLDOZER, qtrmm_ounncopy_BULLDOZER, qtrmm_outucopy_BULLDOZER, qtrmm_outncopy_BULLDOZER,
  qtrmm_olnucopy_BULLDOZER, qtrmm_olnncopy_BULLDOZER, qtrmm_oltucopy_BULLDOZER, qtrmm_oltncopy_BULLDOZER,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_BULLDOZER, qsymm_iltcopy_BULLDOZER,
#else
  qsymm_outcopy_BULLDOZER, qsymm_oltcopy_BULLDOZER,
#endif
  qsymm_outcopy_BULLDOZER, qsymm_oltcopy_BULLDOZER,

#ifndef NO_LAPACK
  qneg_tcopy_BULLDOZER, qlaswp_ncopy_BULLDOZER,
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
  camax_k_BULLDOZER, camin_k_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
  icamax_k_BULLDOZER, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_BULLDOZER,
  cnrm2_k_BULLDOZER, casum_k_BULLDOZER, csum_k_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_BULLDOZER, cdotu_k_BULLDOZER, cdotc_k_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
 csrot_k_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_BULLDOZER,
  caxpyc_k_BULLDOZER, 
  cscal_k_BULLDOZER, 
  cswap_k_BULLDOZER,

  cgemv_n_BULLDOZER, cgemv_t_BULLDOZER, cgemv_r_BULLDOZER, cgemv_c_BULLDOZER,
  cgemv_o_BULLDOZER, cgemv_u_BULLDOZER, cgemv_s_BULLDOZER, cgemv_d_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_BULLDOZER, cgerc_k_BULLDOZER, cgerv_k_BULLDOZER, cgerd_k_BULLDOZER,
  csymv_L_BULLDOZER, csymv_U_BULLDOZER,
  chemv_L_BULLDOZER, chemv_U_BULLDOZER, chemv_M_BULLDOZER, chemv_V_BULLDOZER,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_BULLDOZER, cgemm_kernel_l_BULLDOZER, cgemm_kernel_r_BULLDOZER, cgemm_kernel_b_BULLDOZER,
  cgemm_beta_BULLDOZER,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_BULLDOZER, cgemm_itcopy_BULLDOZER,
#else
  cgemm_oncopy_BULLDOZER, cgemm_otcopy_BULLDOZER,
#endif
  cgemm_oncopy_BULLDOZER, cgemm_otcopy_BULLDOZER,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_BULLDOZER,
  cgemm_small_kernel_nn_BULLDOZER, cgemm_small_kernel_nt_BULLDOZER, cgemm_small_kernel_nr_BULLDOZER, cgemm_small_kernel_nc_BULLDOZER,
  cgemm_small_kernel_tn_BULLDOZER, cgemm_small_kernel_tt_BULLDOZER, cgemm_small_kernel_tr_BULLDOZER, cgemm_small_kernel_tc_BULLDOZER,
  cgemm_small_kernel_rn_BULLDOZER, cgemm_small_kernel_rt_BULLDOZER, cgemm_small_kernel_rr_BULLDOZER, cgemm_small_kernel_rc_BULLDOZER,
  cgemm_small_kernel_cn_BULLDOZER, cgemm_small_kernel_ct_BULLDOZER, cgemm_small_kernel_cr_BULLDOZER, cgemm_small_kernel_cc_BULLDOZER,
  cgemm_small_kernel_b0_nn_BULLDOZER, cgemm_small_kernel_b0_nt_BULLDOZER, cgemm_small_kernel_b0_nr_BULLDOZER, cgemm_small_kernel_b0_nc_BULLDOZER,
  cgemm_small_kernel_b0_tn_BULLDOZER, cgemm_small_kernel_b0_tt_BULLDOZER, cgemm_small_kernel_b0_tr_BULLDOZER, cgemm_small_kernel_b0_tc_BULLDOZER,
  cgemm_small_kernel_b0_rn_BULLDOZER, cgemm_small_kernel_b0_rt_BULLDOZER, cgemm_small_kernel_b0_rr_BULLDOZER, cgemm_small_kernel_b0_rc_BULLDOZER,
  cgemm_small_kernel_b0_cn_BULLDOZER, cgemm_small_kernel_b0_ct_BULLDOZER, cgemm_small_kernel_b0_cr_BULLDOZER, cgemm_small_kernel_b0_cc_BULLDOZER,
#endif

  ctrsm_kernel_LN_BULLDOZER, ctrsm_kernel_LT_BULLDOZER, ctrsm_kernel_LR_BULLDOZER, ctrsm_kernel_LC_BULLDOZER,
  ctrsm_kernel_RN_BULLDOZER, ctrsm_kernel_RT_BULLDOZER, ctrsm_kernel_RR_BULLDOZER, ctrsm_kernel_RC_BULLDOZER,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_BULLDOZER,  ctrsm_iunncopy_BULLDOZER,  ctrsm_iutucopy_BULLDOZER,  ctrsm_iutncopy_BULLDOZER,
  ctrsm_ilnucopy_BULLDOZER,  ctrsm_ilnncopy_BULLDOZER,  ctrsm_iltucopy_BULLDOZER,  ctrsm_iltncopy_BULLDOZER,
#else
  ctrsm_ounucopy_BULLDOZER,  ctrsm_ounncopy_BULLDOZER,  ctrsm_outucopy_BULLDOZER,  ctrsm_outncopy_BULLDOZER,
  ctrsm_olnucopy_BULLDOZER,  ctrsm_olnncopy_BULLDOZER,  ctrsm_oltucopy_BULLDOZER,  ctrsm_oltncopy_BULLDOZER,
#endif
  ctrsm_ounucopy_BULLDOZER,  ctrsm_ounncopy_BULLDOZER,  ctrsm_outucopy_BULLDOZER,  ctrsm_outncopy_BULLDOZER,
  ctrsm_olnucopy_BULLDOZER,  ctrsm_olnncopy_BULLDOZER,  ctrsm_oltucopy_BULLDOZER,  ctrsm_oltncopy_BULLDOZER,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_BULLDOZER,  ctrmm_kernel_RT_BULLDOZER,  ctrmm_kernel_RR_BULLDOZER,  ctrmm_kernel_RC_BULLDOZER,
  ctrmm_kernel_LN_BULLDOZER,  ctrmm_kernel_LT_BULLDOZER,  ctrmm_kernel_LR_BULLDOZER,  ctrmm_kernel_LC_BULLDOZER,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_BULLDOZER,  ctrmm_iunncopy_BULLDOZER,  ctrmm_iutucopy_BULLDOZER,  ctrmm_iutncopy_BULLDOZER,
  ctrmm_ilnucopy_BULLDOZER,  ctrmm_ilnncopy_BULLDOZER,  ctrmm_iltucopy_BULLDOZER,  ctrmm_iltncopy_BULLDOZER,
#else
  ctrmm_ounucopy_BULLDOZER,  ctrmm_ounncopy_BULLDOZER,  ctrmm_outucopy_BULLDOZER,  ctrmm_outncopy_BULLDOZER,
  ctrmm_olnucopy_BULLDOZER,  ctrmm_olnncopy_BULLDOZER,  ctrmm_oltucopy_BULLDOZER,  ctrmm_oltncopy_BULLDOZER,
#endif
  ctrmm_ounucopy_BULLDOZER,  ctrmm_ounncopy_BULLDOZER,  ctrmm_outucopy_BULLDOZER,  ctrmm_outncopy_BULLDOZER,
  ctrmm_olnucopy_BULLDOZER,  ctrmm_olnncopy_BULLDOZER,  ctrmm_oltucopy_BULLDOZER,  ctrmm_oltncopy_BULLDOZER,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_BULLDOZER,  csymm_iltcopy_BULLDOZER,
#else
  csymm_outcopy_BULLDOZER,  csymm_oltcopy_BULLDOZER,
#endif
  csymm_outcopy_BULLDOZER,  csymm_oltcopy_BULLDOZER,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_BULLDOZER,  chemm_iltcopy_BULLDOZER,
#else
  chemm_outcopy_BULLDOZER,  chemm_oltcopy_BULLDOZER,
#endif
  chemm_outcopy_BULLDOZER,  chemm_oltcopy_BULLDOZER,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_BULLDOZER,

  cgemm3m_incopyb_BULLDOZER,  cgemm3m_incopyr_BULLDOZER,
  cgemm3m_incopyi_BULLDOZER,  cgemm3m_itcopyb_BULLDOZER,
  cgemm3m_itcopyr_BULLDOZER,  cgemm3m_itcopyi_BULLDOZER,
  cgemm3m_oncopyb_BULLDOZER,  cgemm3m_oncopyr_BULLDOZER,
  cgemm3m_oncopyi_BULLDOZER,  cgemm3m_otcopyb_BULLDOZER,
  cgemm3m_otcopyr_BULLDOZER,  cgemm3m_otcopyi_BULLDOZER,

  csymm3m_iucopyb_BULLDOZER,  csymm3m_ilcopyb_BULLDOZER,
  csymm3m_iucopyr_BULLDOZER,  csymm3m_ilcopyr_BULLDOZER,
  csymm3m_iucopyi_BULLDOZER,  csymm3m_ilcopyi_BULLDOZER,
  csymm3m_oucopyb_BULLDOZER,  csymm3m_olcopyb_BULLDOZER,
  csymm3m_oucopyr_BULLDOZER,  csymm3m_olcopyr_BULLDOZER,
  csymm3m_oucopyi_BULLDOZER,  csymm3m_olcopyi_BULLDOZER,

  chemm3m_iucopyb_BULLDOZER,  chemm3m_ilcopyb_BULLDOZER,
  chemm3m_iucopyr_BULLDOZER,  chemm3m_ilcopyr_BULLDOZER,
  chemm3m_iucopyi_BULLDOZER,  chemm3m_ilcopyi_BULLDOZER,

  chemm3m_oucopyb_BULLDOZER,  chemm3m_olcopyb_BULLDOZER,
  chemm3m_oucopyr_BULLDOZER,  chemm3m_olcopyr_BULLDOZER,
  chemm3m_oucopyi_BULLDOZER,  chemm3m_olcopyi_BULLDOZER,
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
  cneg_tcopy_BULLDOZER,
  
   claswp_ncopy_BULLDOZER,
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

  zamax_k_BULLDOZER, zamin_k_BULLDOZER, izamax_k_BULLDOZER, izamin_k_BULLDOZER,
  znrm2_k_BULLDOZER, zasum_k_BULLDOZER, zsum_k_BULLDOZER, zcopy_k_BULLDOZER,
  zdotu_k_BULLDOZER, zdotc_k_BULLDOZER, zdrot_k_BULLDOZER,
  zaxpy_k_BULLDOZER, zaxpyc_k_BULLDOZER, zscal_k_BULLDOZER, zswap_k_BULLDOZER,

  zgemv_n_BULLDOZER, zgemv_t_BULLDOZER, zgemv_r_BULLDOZER, zgemv_c_BULLDOZER,
  zgemv_o_BULLDOZER, zgemv_u_BULLDOZER, zgemv_s_BULLDOZER, zgemv_d_BULLDOZER,
  zgeru_k_BULLDOZER, zgerc_k_BULLDOZER, zgerv_k_BULLDOZER, zgerd_k_BULLDOZER,
  zsymv_L_BULLDOZER, zsymv_U_BULLDOZER,
  zhemv_L_BULLDOZER, zhemv_U_BULLDOZER, zhemv_M_BULLDOZER, zhemv_V_BULLDOZER,

  zgemm_kernel_n_BULLDOZER, zgemm_kernel_l_BULLDOZER, zgemm_kernel_r_BULLDOZER, zgemm_kernel_b_BULLDOZER,
  zgemm_beta_BULLDOZER,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_BULLDOZER, zgemm_itcopy_BULLDOZER,
#else
  zgemm_oncopy_BULLDOZER, zgemm_otcopy_BULLDOZER,
#endif
  zgemm_oncopy_BULLDOZER, zgemm_otcopy_BULLDOZER,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_BULLDOZER,
  zgemm_small_kernel_nn_BULLDOZER, zgemm_small_kernel_nt_BULLDOZER, zgemm_small_kernel_nr_BULLDOZER, zgemm_small_kernel_nc_BULLDOZER,
  zgemm_small_kernel_tn_BULLDOZER, zgemm_small_kernel_tt_BULLDOZER, zgemm_small_kernel_tr_BULLDOZER, zgemm_small_kernel_tc_BULLDOZER,
  zgemm_small_kernel_rn_BULLDOZER, zgemm_small_kernel_rt_BULLDOZER, zgemm_small_kernel_rr_BULLDOZER, zgemm_small_kernel_rc_BULLDOZER,
  zgemm_small_kernel_cn_BULLDOZER, zgemm_small_kernel_ct_BULLDOZER, zgemm_small_kernel_cr_BULLDOZER, zgemm_small_kernel_cc_BULLDOZER,
  zgemm_small_kernel_b0_nn_BULLDOZER, zgemm_small_kernel_b0_nt_BULLDOZER, zgemm_small_kernel_b0_nr_BULLDOZER, zgemm_small_kernel_b0_nc_BULLDOZER,
  zgemm_small_kernel_b0_tn_BULLDOZER, zgemm_small_kernel_b0_tt_BULLDOZER, zgemm_small_kernel_b0_tr_BULLDOZER, zgemm_small_kernel_b0_tc_BULLDOZER,
  zgemm_small_kernel_b0_rn_BULLDOZER, zgemm_small_kernel_b0_rt_BULLDOZER, zgemm_small_kernel_b0_rr_BULLDOZER, zgemm_small_kernel_b0_rc_BULLDOZER,
  zgemm_small_kernel_b0_cn_BULLDOZER, zgemm_small_kernel_b0_ct_BULLDOZER, zgemm_small_kernel_b0_cr_BULLDOZER, zgemm_small_kernel_b0_cc_BULLDOZER,
#endif

  ztrsm_kernel_LN_BULLDOZER, ztrsm_kernel_LT_BULLDOZER, ztrsm_kernel_LR_BULLDOZER, ztrsm_kernel_LC_BULLDOZER,
  ztrsm_kernel_RN_BULLDOZER, ztrsm_kernel_RT_BULLDOZER, ztrsm_kernel_RR_BULLDOZER, ztrsm_kernel_RC_BULLDOZER,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_BULLDOZER,  ztrsm_iunncopy_BULLDOZER,  ztrsm_iutucopy_BULLDOZER,  ztrsm_iutncopy_BULLDOZER,
  ztrsm_ilnucopy_BULLDOZER,  ztrsm_ilnncopy_BULLDOZER,  ztrsm_iltucopy_BULLDOZER,  ztrsm_iltncopy_BULLDOZER,
#else
  ztrsm_ounucopy_BULLDOZER,  ztrsm_ounncopy_BULLDOZER,  ztrsm_outucopy_BULLDOZER,  ztrsm_outncopy_BULLDOZER,
  ztrsm_olnucopy_BULLDOZER,  ztrsm_olnncopy_BULLDOZER,  ztrsm_oltucopy_BULLDOZER,  ztrsm_oltncopy_BULLDOZER,
#endif
  ztrsm_ounucopy_BULLDOZER,  ztrsm_ounncopy_BULLDOZER,  ztrsm_outucopy_BULLDOZER,  ztrsm_outncopy_BULLDOZER,
  ztrsm_olnucopy_BULLDOZER,  ztrsm_olnncopy_BULLDOZER,  ztrsm_oltucopy_BULLDOZER,  ztrsm_oltncopy_BULLDOZER,

  ztrmm_kernel_RN_BULLDOZER,  ztrmm_kernel_RT_BULLDOZER,  ztrmm_kernel_RR_BULLDOZER,  ztrmm_kernel_RC_BULLDOZER,
  ztrmm_kernel_LN_BULLDOZER,  ztrmm_kernel_LT_BULLDOZER,  ztrmm_kernel_LR_BULLDOZER,  ztrmm_kernel_LC_BULLDOZER,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_BULLDOZER,  ztrmm_iunncopy_BULLDOZER,  ztrmm_iutucopy_BULLDOZER,  ztrmm_iutncopy_BULLDOZER,
  ztrmm_ilnucopy_BULLDOZER,  ztrmm_ilnncopy_BULLDOZER,  ztrmm_iltucopy_BULLDOZER,  ztrmm_iltncopy_BULLDOZER,
#else
  ztrmm_ounucopy_BULLDOZER,  ztrmm_ounncopy_BULLDOZER,  ztrmm_outucopy_BULLDOZER,  ztrmm_outncopy_BULLDOZER,
  ztrmm_olnucopy_BULLDOZER,  ztrmm_olnncopy_BULLDOZER,  ztrmm_oltucopy_BULLDOZER,  ztrmm_oltncopy_BULLDOZER,
#endif
  ztrmm_ounucopy_BULLDOZER,  ztrmm_ounncopy_BULLDOZER,  ztrmm_outucopy_BULLDOZER,  ztrmm_outncopy_BULLDOZER,
  ztrmm_olnucopy_BULLDOZER,  ztrmm_olnncopy_BULLDOZER,  ztrmm_oltucopy_BULLDOZER,  ztrmm_oltncopy_BULLDOZER,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_BULLDOZER,  zsymm_iltcopy_BULLDOZER,
#else
  zsymm_outcopy_BULLDOZER,  zsymm_oltcopy_BULLDOZER,
#endif
  zsymm_outcopy_BULLDOZER,  zsymm_oltcopy_BULLDOZER,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_BULLDOZER,  zhemm_iltcopy_BULLDOZER,
#else
  zhemm_outcopy_BULLDOZER,  zhemm_oltcopy_BULLDOZER,
#endif
  zhemm_outcopy_BULLDOZER,  zhemm_oltcopy_BULLDOZER,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_BULLDOZER,

  zgemm3m_incopyb_BULLDOZER,  zgemm3m_incopyr_BULLDOZER,
  zgemm3m_incopyi_BULLDOZER,  zgemm3m_itcopyb_BULLDOZER,
  zgemm3m_itcopyr_BULLDOZER,  zgemm3m_itcopyi_BULLDOZER,
  zgemm3m_oncopyb_BULLDOZER,  zgemm3m_oncopyr_BULLDOZER,
  zgemm3m_oncopyi_BULLDOZER,  zgemm3m_otcopyb_BULLDOZER,
  zgemm3m_otcopyr_BULLDOZER,  zgemm3m_otcopyi_BULLDOZER,

  zsymm3m_iucopyb_BULLDOZER,  zsymm3m_ilcopyb_BULLDOZER,
  zsymm3m_iucopyr_BULLDOZER,  zsymm3m_ilcopyr_BULLDOZER,
  zsymm3m_iucopyi_BULLDOZER,  zsymm3m_ilcopyi_BULLDOZER,
  zsymm3m_oucopyb_BULLDOZER,  zsymm3m_olcopyb_BULLDOZER,
  zsymm3m_oucopyr_BULLDOZER,  zsymm3m_olcopyr_BULLDOZER,
  zsymm3m_oucopyi_BULLDOZER,  zsymm3m_olcopyi_BULLDOZER,

  zhemm3m_iucopyb_BULLDOZER,  zhemm3m_ilcopyb_BULLDOZER,
  zhemm3m_iucopyr_BULLDOZER,  zhemm3m_ilcopyr_BULLDOZER,
  zhemm3m_iucopyi_BULLDOZER,  zhemm3m_ilcopyi_BULLDOZER,

  zhemm3m_oucopyb_BULLDOZER,  zhemm3m_olcopyb_BULLDOZER,
  zhemm3m_oucopyr_BULLDOZER,  zhemm3m_olcopyr_BULLDOZER,
  zhemm3m_oucopyi_BULLDOZER,  zhemm3m_olcopyi_BULLDOZER,
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
  zneg_tcopy_BULLDOZER, zlaswp_ncopy_BULLDOZER,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_BULLDOZER, xamin_k_BULLDOZER, ixamax_k_BULLDOZER, ixamin_k_BULLDOZER,
  xnrm2_k_BULLDOZER, xasum_k_BULLDOZER, xsum_k_BULLDOZER, xcopy_k_BULLDOZER,
  xdotu_k_BULLDOZER, xdotc_k_BULLDOZER, xqrot_k_BULLDOZER,
  xaxpy_k_BULLDOZER, xaxpyc_k_BULLDOZER, xscal_k_BULLDOZER, xswap_k_BULLDOZER,

  xgemv_n_BULLDOZER, xgemv_t_BULLDOZER, xgemv_r_BULLDOZER, xgemv_c_BULLDOZER,
  xgemv_o_BULLDOZER, xgemv_u_BULLDOZER, xgemv_s_BULLDOZER, xgemv_d_BULLDOZER,
  xgeru_k_BULLDOZER, xgerc_k_BULLDOZER, xgerv_k_BULLDOZER, xgerd_k_BULLDOZER,
  xsymv_L_BULLDOZER, xsymv_U_BULLDOZER,
  xhemv_L_BULLDOZER, xhemv_U_BULLDOZER, xhemv_M_BULLDOZER, xhemv_V_BULLDOZER,

  xgemm_kernel_n_BULLDOZER, xgemm_kernel_l_BULLDOZER, xgemm_kernel_r_BULLDOZER, xgemm_kernel_b_BULLDOZER,
  xgemm_beta_BULLDOZER,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_BULLDOZER, xgemm_itcopy_BULLDOZER,
#else
  xgemm_oncopy_BULLDOZER, xgemm_otcopy_BULLDOZER,
#endif
  xgemm_oncopy_BULLDOZER, xgemm_otcopy_BULLDOZER,

  xtrsm_kernel_LN_BULLDOZER, xtrsm_kernel_LT_BULLDOZER, xtrsm_kernel_LR_BULLDOZER, xtrsm_kernel_LC_BULLDOZER,
  xtrsm_kernel_RN_BULLDOZER, xtrsm_kernel_RT_BULLDOZER, xtrsm_kernel_RR_BULLDOZER, xtrsm_kernel_RC_BULLDOZER,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_BULLDOZER,  xtrsm_iunncopy_BULLDOZER,  xtrsm_iutucopy_BULLDOZER,  xtrsm_iutncopy_BULLDOZER,
  xtrsm_ilnucopy_BULLDOZER,  xtrsm_ilnncopy_BULLDOZER,  xtrsm_iltucopy_BULLDOZER,  xtrsm_iltncopy_BULLDOZER,
#else
  xtrsm_ounucopy_BULLDOZER,  xtrsm_ounncopy_BULLDOZER,  xtrsm_outucopy_BULLDOZER,  xtrsm_outncopy_BULLDOZER,
  xtrsm_olnucopy_BULLDOZER,  xtrsm_olnncopy_BULLDOZER,  xtrsm_oltucopy_BULLDOZER,  xtrsm_oltncopy_BULLDOZER,
#endif
  xtrsm_ounucopy_BULLDOZER,  xtrsm_ounncopy_BULLDOZER,  xtrsm_outucopy_BULLDOZER,  xtrsm_outncopy_BULLDOZER,
  xtrsm_olnucopy_BULLDOZER,  xtrsm_olnncopy_BULLDOZER,  xtrsm_oltucopy_BULLDOZER,  xtrsm_oltncopy_BULLDOZER,

  xtrmm_kernel_RN_BULLDOZER,  xtrmm_kernel_RT_BULLDOZER,  xtrmm_kernel_RR_BULLDOZER,  xtrmm_kernel_RC_BULLDOZER,
  xtrmm_kernel_LN_BULLDOZER,  xtrmm_kernel_LT_BULLDOZER,  xtrmm_kernel_LR_BULLDOZER,  xtrmm_kernel_LC_BULLDOZER,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_BULLDOZER,  xtrmm_iunncopy_BULLDOZER,  xtrmm_iutucopy_BULLDOZER,  xtrmm_iutncopy_BULLDOZER,
  xtrmm_ilnucopy_BULLDOZER,  xtrmm_ilnncopy_BULLDOZER,  xtrmm_iltucopy_BULLDOZER,  xtrmm_iltncopy_BULLDOZER,
#else
  xtrmm_ounucopy_BULLDOZER,  xtrmm_ounncopy_BULLDOZER,  xtrmm_outucopy_BULLDOZER,  xtrmm_outncopy_BULLDOZER,
  xtrmm_olnucopy_BULLDOZER,  xtrmm_olnncopy_BULLDOZER,  xtrmm_oltucopy_BULLDOZER,  xtrmm_oltncopy_BULLDOZER,
#endif
  xtrmm_ounucopy_BULLDOZER,  xtrmm_ounncopy_BULLDOZER,  xtrmm_outucopy_BULLDOZER,  xtrmm_outncopy_BULLDOZER,
  xtrmm_olnucopy_BULLDOZER,  xtrmm_olnncopy_BULLDOZER,  xtrmm_oltucopy_BULLDOZER,  xtrmm_oltncopy_BULLDOZER,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_BULLDOZER,  xsymm_iltcopy_BULLDOZER,
#else
  xsymm_outcopy_BULLDOZER,  xsymm_oltcopy_BULLDOZER,
#endif
  xsymm_outcopy_BULLDOZER,  xsymm_oltcopy_BULLDOZER,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_BULLDOZER,  xhemm_iltcopy_BULLDOZER,
#else
  xhemm_outcopy_BULLDOZER,  xhemm_oltcopy_BULLDOZER,
#endif
  xhemm_outcopy_BULLDOZER,  xhemm_oltcopy_BULLDOZER,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_BULLDOZER,

  xgemm3m_incopyb_BULLDOZER,  xgemm3m_incopyr_BULLDOZER,
  xgemm3m_incopyi_BULLDOZER,  xgemm3m_itcopyb_BULLDOZER,
  xgemm3m_itcopyr_BULLDOZER,  xgemm3m_itcopyi_BULLDOZER,
  xgemm3m_oncopyb_BULLDOZER,  xgemm3m_oncopyr_BULLDOZER,
  xgemm3m_oncopyi_BULLDOZER,  xgemm3m_otcopyb_BULLDOZER,
  xgemm3m_otcopyr_BULLDOZER,  xgemm3m_otcopyi_BULLDOZER,

  xsymm3m_iucopyb_BULLDOZER,  xsymm3m_ilcopyb_BULLDOZER,
  xsymm3m_iucopyr_BULLDOZER,  xsymm3m_ilcopyr_BULLDOZER,
  xsymm3m_iucopyi_BULLDOZER,  xsymm3m_ilcopyi_BULLDOZER,
  xsymm3m_oucopyb_BULLDOZER,  xsymm3m_olcopyb_BULLDOZER,
  xsymm3m_oucopyr_BULLDOZER,  xsymm3m_olcopyr_BULLDOZER,
  xsymm3m_oucopyi_BULLDOZER,  xsymm3m_olcopyi_BULLDOZER,

  xhemm3m_iucopyb_BULLDOZER,  xhemm3m_ilcopyb_BULLDOZER,
  xhemm3m_iucopyr_BULLDOZER,  xhemm3m_ilcopyr_BULLDOZER,
  xhemm3m_iucopyi_BULLDOZER,  xhemm3m_ilcopyi_BULLDOZER,

  xhemm3m_oucopyb_BULLDOZER,  xhemm3m_olcopyb_BULLDOZER,
  xhemm3m_oucopyr_BULLDOZER,  xhemm3m_olcopyr_BULLDOZER,
  xhemm3m_oucopyi_BULLDOZER,  xhemm3m_olcopyi_BULLDOZER,
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
  xneg_tcopy_BULLDOZER, xlaswp_ncopy_BULLDOZER,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_BULLDOZER,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_BULLDOZER,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_BULLDOZER,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_BULLDOZER,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_BULLDOZER, somatcopy_k_ct_BULLDOZER, somatcopy_k_rn_BULLDOZER, somatcopy_k_rt_BULLDOZER,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_BULLDOZER, domatcopy_k_ct_BULLDOZER, domatcopy_k_rn_BULLDOZER, domatcopy_k_rt_BULLDOZER,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_BULLDOZER, comatcopy_k_ct_BULLDOZER, comatcopy_k_rn_BULLDOZER, comatcopy_k_rt_BULLDOZER,
  comatcopy_k_cnc_BULLDOZER, comatcopy_k_ctc_BULLDOZER, comatcopy_k_rnc_BULLDOZER, comatcopy_k_rtc_BULLDOZER,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_BULLDOZER, zomatcopy_k_ct_BULLDOZER, zomatcopy_k_rn_BULLDOZER, zomatcopy_k_rt_BULLDOZER,
  zomatcopy_k_cnc_BULLDOZER, zomatcopy_k_ctc_BULLDOZER, zomatcopy_k_rnc_BULLDOZER, zomatcopy_k_rtc_BULLDOZER,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_BULLDOZER, simatcopy_k_ct_BULLDOZER, simatcopy_k_rn_BULLDOZER, simatcopy_k_rt_BULLDOZER,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_BULLDOZER, dimatcopy_k_ct_BULLDOZER, dimatcopy_k_rn_BULLDOZER, dimatcopy_k_rt_BULLDOZER,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_BULLDOZER, cimatcopy_k_ct_BULLDOZER, cimatcopy_k_rn_BULLDOZER, cimatcopy_k_rt_BULLDOZER,
  cimatcopy_k_cnc_BULLDOZER, cimatcopy_k_ctc_BULLDOZER, cimatcopy_k_rnc_BULLDOZER, cimatcopy_k_rtc_BULLDOZER,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_BULLDOZER, zimatcopy_k_ct_BULLDOZER, zimatcopy_k_rn_BULLDOZER, zimatcopy_k_rt_BULLDOZER,
  zimatcopy_k_cnc_BULLDOZER, zimatcopy_k_ctc_BULLDOZER, zimatcopy_k_rnc_BULLDOZER, zimatcopy_k_rtc_BULLDOZER,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_BULLDOZER,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_BULLDOZER,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_BULLDOZER,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_BULLDOZER,
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
