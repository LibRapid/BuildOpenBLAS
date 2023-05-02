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
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_SANDYBRIDGE;  OR    */
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
#include "kernel_SANDYBRIDGE.h"
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

  sbstobf16_k_SANDYBRIDGE, sbdtobf16_k_SANDYBRIDGE, sbf16tos_k_SANDYBRIDGE, dbf16tod_k_SANDYBRIDGE,

  samax_k_SANDYBRIDGE,  samin_k_SANDYBRIDGE,  smax_k_SANDYBRIDGE,  smin_k_SANDYBRIDGE,
  isamax_k_SANDYBRIDGE, isamin_k_SANDYBRIDGE, ismax_k_SANDYBRIDGE, ismin_k_SANDYBRIDGE,
  snrm2_k_SANDYBRIDGE,  sasum_k_SANDYBRIDGE, ssum_k_SANDYBRIDGE, scopy_k_SANDYBRIDGE, sbdot_k_SANDYBRIDGE,
  dsdot_k_SANDYBRIDGE,
  srot_k_SANDYBRIDGE,   saxpy_k_SANDYBRIDGE,  sscal_k_SANDYBRIDGE, sswap_k_SANDYBRIDGE,
  sbgemv_n_SANDYBRIDGE, sbgemv_t_SANDYBRIDGE, sger_k_SANDYBRIDGE,
  ssymv_L_SANDYBRIDGE, ssymv_U_SANDYBRIDGE,

  sbgemm_kernel_SANDYBRIDGE, sbgemm_beta_SANDYBRIDGE,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_SANDYBRIDGE, sbgemm_itcopy_SANDYBRIDGE,
#else
  sbgemm_oncopy_SANDYBRIDGE, sbgemm_otcopy_SANDYBRIDGE,
#endif
  sbgemm_oncopy_SANDYBRIDGE, sbgemm_otcopy_SANDYBRIDGE,

  strsm_kernel_LN_SANDYBRIDGE, strsm_kernel_LT_SANDYBRIDGE, strsm_kernel_RN_SANDYBRIDGE, strsm_kernel_RT_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_SANDYBRIDGE, strsm_iunncopy_SANDYBRIDGE, strsm_iutucopy_SANDYBRIDGE, strsm_iutncopy_SANDYBRIDGE,
  strsm_ilnucopy_SANDYBRIDGE, strsm_ilnncopy_SANDYBRIDGE, strsm_iltucopy_SANDYBRIDGE, strsm_iltncopy_SANDYBRIDGE,
#else
  strsm_ounucopy_SANDYBRIDGE, strsm_ounncopy_SANDYBRIDGE, strsm_outucopy_SANDYBRIDGE, strsm_outncopy_SANDYBRIDGE,
  strsm_olnucopy_SANDYBRIDGE, strsm_olnncopy_SANDYBRIDGE, strsm_oltucopy_SANDYBRIDGE, strsm_oltncopy_SANDYBRIDGE,
#endif
  strsm_ounucopy_SANDYBRIDGE, strsm_ounncopy_SANDYBRIDGE, strsm_outucopy_SANDYBRIDGE, strsm_outncopy_SANDYBRIDGE,
  strsm_olnucopy_SANDYBRIDGE, strsm_olnncopy_SANDYBRIDGE, strsm_oltucopy_SANDYBRIDGE, strsm_oltncopy_SANDYBRIDGE,
  strmm_kernel_RN_SANDYBRIDGE, strmm_kernel_RT_SANDYBRIDGE, strmm_kernel_LN_SANDYBRIDGE, strmm_kernel_LT_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_SANDYBRIDGE, strmm_iunncopy_SANDYBRIDGE, strmm_iutucopy_SANDYBRIDGE, strmm_iutncopy_SANDYBRIDGE,
  strmm_ilnucopy_SANDYBRIDGE, strmm_ilnncopy_SANDYBRIDGE, strmm_iltucopy_SANDYBRIDGE, strmm_iltncopy_SANDYBRIDGE,
#else
  strmm_ounucopy_SANDYBRIDGE, strmm_ounncopy_SANDYBRIDGE, strmm_outucopy_SANDYBRIDGE, strmm_outncopy_SANDYBRIDGE,
  strmm_olnucopy_SANDYBRIDGE, strmm_olnncopy_SANDYBRIDGE, strmm_oltucopy_SANDYBRIDGE, strmm_oltncopy_SANDYBRIDGE,
#endif
  strmm_ounucopy_SANDYBRIDGE, strmm_ounncopy_SANDYBRIDGE, strmm_outucopy_SANDYBRIDGE, strmm_outncopy_SANDYBRIDGE,
  strmm_olnucopy_SANDYBRIDGE, strmm_olnncopy_SANDYBRIDGE, strmm_oltucopy_SANDYBRIDGE, strmm_oltncopy_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_SANDYBRIDGE, ssymm_iltcopy_SANDYBRIDGE,
#else
  ssymm_outcopy_SANDYBRIDGE, ssymm_oltcopy_SANDYBRIDGE,
#endif
  ssymm_outcopy_SANDYBRIDGE, ssymm_oltcopy_SANDYBRIDGE,

#ifndef NO_LAPACK
  sneg_tcopy_SANDYBRIDGE, slaswp_ncopy_SANDYBRIDGE,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_SANDYBRIDGE,
  sbgemm_small_kernel_nn_SANDYBRIDGE, sbgemm_small_kernel_nt_SANDYBRIDGE, sbgemm_small_kernel_tn_SANDYBRIDGE, sbgemm_small_kernel_tt_SANDYBRIDGE,
  sbgemm_small_kernel_b0_nn_SANDYBRIDGE, sbgemm_small_kernel_b0_nt_SANDYBRIDGE, sbgemm_small_kernel_b0_tn_SANDYBRIDGE, sbgemm_small_kernel_b0_tt_SANDYBRIDGE,
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
  samax_k_SANDYBRIDGE,  samin_k_SANDYBRIDGE,  smax_k_SANDYBRIDGE,  smin_k_SANDYBRIDGE,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_SANDYBRIDGE,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_SANDYBRIDGE, ismax_k_SANDYBRIDGE, ismin_k_SANDYBRIDGE,
  snrm2_k_SANDYBRIDGE,  sasum_k_SANDYBRIDGE,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_SANDYBRIDGE,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_SANDYBRIDGE, sdot_k_SANDYBRIDGE,
//  dsdot_k_SANDYBRIDGE,
  srot_k_SANDYBRIDGE,   saxpy_k_SANDYBRIDGE,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_SANDYBRIDGE,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_SANDYBRIDGE,
  sgemv_n_SANDYBRIDGE,  sgemv_t_SANDYBRIDGE,
#endif
#if BUILD_SINGLE == 1
  sger_k_SANDYBRIDGE,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_SANDYBRIDGE, ssymv_U_SANDYBRIDGE,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_SANDYBRIDGE,
  sgemm_direct_performant_SANDYBRIDGE,	
#endif

  sgemm_kernel_SANDYBRIDGE, sgemm_beta_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_SANDYBRIDGE, sgemm_itcopy_SANDYBRIDGE,
#else
  sgemm_oncopy_SANDYBRIDGE, sgemm_otcopy_SANDYBRIDGE,
#endif
  sgemm_oncopy_SANDYBRIDGE, sgemm_otcopy_SANDYBRIDGE,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_SANDYBRIDGE,
  sgemm_small_kernel_nn_SANDYBRIDGE, sgemm_small_kernel_nt_SANDYBRIDGE, sgemm_small_kernel_tn_SANDYBRIDGE, sgemm_small_kernel_tt_SANDYBRIDGE,
  sgemm_small_kernel_b0_nn_SANDYBRIDGE, sgemm_small_kernel_b0_nt_SANDYBRIDGE, sgemm_small_kernel_b0_tn_SANDYBRIDGE, sgemm_small_kernel_b0_tt_SANDYBRIDGE,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_SANDYBRIDGE, strsm_kernel_LT_SANDYBRIDGE, strsm_kernel_RN_SANDYBRIDGE, strsm_kernel_RT_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_SANDYBRIDGE, strsm_iunncopy_SANDYBRIDGE, strsm_iutucopy_SANDYBRIDGE, strsm_iutncopy_SANDYBRIDGE,
  strsm_ilnucopy_SANDYBRIDGE, strsm_ilnncopy_SANDYBRIDGE, strsm_iltucopy_SANDYBRIDGE, strsm_iltncopy_SANDYBRIDGE,
#else
  strsm_ounucopy_SANDYBRIDGE, strsm_ounncopy_SANDYBRIDGE, strsm_outucopy_SANDYBRIDGE, strsm_outncopy_SANDYBRIDGE,
  strsm_olnucopy_SANDYBRIDGE, strsm_olnncopy_SANDYBRIDGE, strsm_oltucopy_SANDYBRIDGE, strsm_oltncopy_SANDYBRIDGE,
#endif
  strsm_ounucopy_SANDYBRIDGE, strsm_ounncopy_SANDYBRIDGE, strsm_outucopy_SANDYBRIDGE, strsm_outncopy_SANDYBRIDGE,
  strsm_olnucopy_SANDYBRIDGE, strsm_olnncopy_SANDYBRIDGE, strsm_oltucopy_SANDYBRIDGE, strsm_oltncopy_SANDYBRIDGE,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_SANDYBRIDGE, strmm_kernel_RT_SANDYBRIDGE, strmm_kernel_LN_SANDYBRIDGE, strmm_kernel_LT_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_SANDYBRIDGE, strmm_iunncopy_SANDYBRIDGE, strmm_iutucopy_SANDYBRIDGE, strmm_iutncopy_SANDYBRIDGE,
  strmm_ilnucopy_SANDYBRIDGE, strmm_ilnncopy_SANDYBRIDGE, strmm_iltucopy_SANDYBRIDGE, strmm_iltncopy_SANDYBRIDGE,
#else
  strmm_ounucopy_SANDYBRIDGE, strmm_ounncopy_SANDYBRIDGE, strmm_outucopy_SANDYBRIDGE, strmm_outncopy_SANDYBRIDGE,
  strmm_olnucopy_SANDYBRIDGE, strmm_olnncopy_SANDYBRIDGE, strmm_oltucopy_SANDYBRIDGE, strmm_oltncopy_SANDYBRIDGE,
#endif
  strmm_ounucopy_SANDYBRIDGE, strmm_ounncopy_SANDYBRIDGE, strmm_outucopy_SANDYBRIDGE, strmm_outncopy_SANDYBRIDGE,
  strmm_olnucopy_SANDYBRIDGE, strmm_olnncopy_SANDYBRIDGE, strmm_oltucopy_SANDYBRIDGE, strmm_oltncopy_SANDYBRIDGE,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_SANDYBRIDGE, ssymm_iltcopy_SANDYBRIDGE,
#else
  ssymm_outcopy_SANDYBRIDGE, ssymm_oltcopy_SANDYBRIDGE,
#endif
  ssymm_outcopy_SANDYBRIDGE, ssymm_oltcopy_SANDYBRIDGE,
#ifndef NO_LAPACK
  sneg_tcopy_SANDYBRIDGE, slaswp_ncopy_SANDYBRIDGE,
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
  damax_k_SANDYBRIDGE,  damin_k_SANDYBRIDGE,  dmax_k_SANDYBRIDGE,  dmin_k_SANDYBRIDGE,
  idamax_k_SANDYBRIDGE, idamin_k_SANDYBRIDGE, idmax_k_SANDYBRIDGE, idmin_k_SANDYBRIDGE,
  dnrm2_k_SANDYBRIDGE, dasum_k_SANDYBRIDGE,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_SANDYBRIDGE,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_SANDYBRIDGE, ddot_k_SANDYBRIDGE,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_SANDYBRIDGE,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_SANDYBRIDGE,
  daxpy_k_SANDYBRIDGE,
  dscal_k_SANDYBRIDGE, 
  dswap_k_SANDYBRIDGE,
  dgemv_n_SANDYBRIDGE,  dgemv_t_SANDYBRIDGE,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_SANDYBRIDGE,
  dsymv_L_SANDYBRIDGE,  dsymv_U_SANDYBRIDGE,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_SANDYBRIDGE, dgemm_beta_SANDYBRIDGE,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_SANDYBRIDGE, dgemm_itcopy_SANDYBRIDGE,
#else
  dgemm_oncopy_SANDYBRIDGE, dgemm_otcopy_SANDYBRIDGE,
#endif
  dgemm_oncopy_SANDYBRIDGE, dgemm_otcopy_SANDYBRIDGE,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_SANDYBRIDGE,
  dgemm_small_kernel_nn_SANDYBRIDGE, dgemm_small_kernel_nt_SANDYBRIDGE, dgemm_small_kernel_tn_SANDYBRIDGE, dgemm_small_kernel_tt_SANDYBRIDGE,
  dgemm_small_kernel_b0_nn_SANDYBRIDGE, dgemm_small_kernel_b0_nt_SANDYBRIDGE, dgemm_small_kernel_b0_tn_SANDYBRIDGE, dgemm_small_kernel_b0_tt_SANDYBRIDGE,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_SANDYBRIDGE, dtrsm_kernel_LT_SANDYBRIDGE, dtrsm_kernel_RN_SANDYBRIDGE, dtrsm_kernel_RT_SANDYBRIDGE,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_SANDYBRIDGE, dtrsm_iunncopy_SANDYBRIDGE, dtrsm_iutucopy_SANDYBRIDGE, dtrsm_iutncopy_SANDYBRIDGE,
  dtrsm_ilnucopy_SANDYBRIDGE, dtrsm_ilnncopy_SANDYBRIDGE, dtrsm_iltucopy_SANDYBRIDGE, dtrsm_iltncopy_SANDYBRIDGE,
#else
  dtrsm_ounucopy_SANDYBRIDGE, dtrsm_ounncopy_SANDYBRIDGE, dtrsm_outucopy_SANDYBRIDGE, dtrsm_outncopy_SANDYBRIDGE,
  dtrsm_olnucopy_SANDYBRIDGE, dtrsm_olnncopy_SANDYBRIDGE, dtrsm_oltucopy_SANDYBRIDGE, dtrsm_oltncopy_SANDYBRIDGE,
#endif
  dtrsm_ounucopy_SANDYBRIDGE, dtrsm_ounncopy_SANDYBRIDGE, dtrsm_outucopy_SANDYBRIDGE, dtrsm_outncopy_SANDYBRIDGE,
  dtrsm_olnucopy_SANDYBRIDGE, dtrsm_olnncopy_SANDYBRIDGE, dtrsm_oltucopy_SANDYBRIDGE, dtrsm_oltncopy_SANDYBRIDGE,
  dtrmm_kernel_RN_SANDYBRIDGE, dtrmm_kernel_RT_SANDYBRIDGE, dtrmm_kernel_LN_SANDYBRIDGE, dtrmm_kernel_LT_SANDYBRIDGE,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_SANDYBRIDGE, dtrmm_iunncopy_SANDYBRIDGE, dtrmm_iutucopy_SANDYBRIDGE, dtrmm_iutncopy_SANDYBRIDGE,
  dtrmm_ilnucopy_SANDYBRIDGE, dtrmm_ilnncopy_SANDYBRIDGE, dtrmm_iltucopy_SANDYBRIDGE, dtrmm_iltncopy_SANDYBRIDGE,
#else
  dtrmm_ounucopy_SANDYBRIDGE, dtrmm_ounncopy_SANDYBRIDGE, dtrmm_outucopy_SANDYBRIDGE, dtrmm_outncopy_SANDYBRIDGE,
  dtrmm_olnucopy_SANDYBRIDGE, dtrmm_olnncopy_SANDYBRIDGE, dtrmm_oltucopy_SANDYBRIDGE, dtrmm_oltncopy_SANDYBRIDGE,
#endif
  dtrmm_ounucopy_SANDYBRIDGE, dtrmm_ounncopy_SANDYBRIDGE, dtrmm_outucopy_SANDYBRIDGE, dtrmm_outncopy_SANDYBRIDGE,
  dtrmm_olnucopy_SANDYBRIDGE, dtrmm_olnncopy_SANDYBRIDGE, dtrmm_oltucopy_SANDYBRIDGE, dtrmm_oltncopy_SANDYBRIDGE,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_SANDYBRIDGE, dsymm_iltcopy_SANDYBRIDGE,
#else
  dsymm_outcopy_SANDYBRIDGE, dsymm_oltcopy_SANDYBRIDGE,
#endif
  dsymm_outcopy_SANDYBRIDGE, dsymm_oltcopy_SANDYBRIDGE,

#ifndef NO_LAPACK
  dneg_tcopy_SANDYBRIDGE, dlaswp_ncopy_SANDYBRIDGE,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_SANDYBRIDGE,  qamin_k_SANDYBRIDGE,  qmax_k_SANDYBRIDGE,  qmin_k_SANDYBRIDGE,
  iqamax_k_SANDYBRIDGE, iqamin_k_SANDYBRIDGE, iqmax_k_SANDYBRIDGE, iqmin_k_SANDYBRIDGE,
  qnrm2_k_SANDYBRIDGE,  qasum_k_SANDYBRIDGE,  qsum_k_SANDYBRIDGE, qcopy_k_SANDYBRIDGE, qdot_k_SANDYBRIDGE,
  qrot_k_SANDYBRIDGE,   qaxpy_k_SANDYBRIDGE,  qscal_k_SANDYBRIDGE, qswap_k_SANDYBRIDGE,
  qgemv_n_SANDYBRIDGE,  qgemv_t_SANDYBRIDGE,  qger_k_SANDYBRIDGE,
  qsymv_L_SANDYBRIDGE,  qsymv_U_SANDYBRIDGE,

  qgemm_kernel_SANDYBRIDGE, qgemm_beta_SANDYBRIDGE,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_SANDYBRIDGE, qgemm_itcopy_SANDYBRIDGE,
#else
  qgemm_oncopy_SANDYBRIDGE, qgemm_otcopy_SANDYBRIDGE,
#endif
  qgemm_oncopy_SANDYBRIDGE, qgemm_otcopy_SANDYBRIDGE,
  qtrsm_kernel_LN_SANDYBRIDGE, qtrsm_kernel_LT_SANDYBRIDGE, qtrsm_kernel_RN_SANDYBRIDGE, qtrsm_kernel_RT_SANDYBRIDGE,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_SANDYBRIDGE, qtrsm_iunncopy_SANDYBRIDGE, qtrsm_iutucopy_SANDYBRIDGE, qtrsm_iutncopy_SANDYBRIDGE,
  qtrsm_ilnucopy_SANDYBRIDGE, qtrsm_ilnncopy_SANDYBRIDGE, qtrsm_iltucopy_SANDYBRIDGE, qtrsm_iltncopy_SANDYBRIDGE,
#else
  qtrsm_ounucopy_SANDYBRIDGE, qtrsm_ounncopy_SANDYBRIDGE, qtrsm_outucopy_SANDYBRIDGE, qtrsm_outncopy_SANDYBRIDGE,
  qtrsm_olnucopy_SANDYBRIDGE, qtrsm_olnncopy_SANDYBRIDGE, qtrsm_oltucopy_SANDYBRIDGE, qtrsm_oltncopy_SANDYBRIDGE,
#endif
  qtrsm_ounucopy_SANDYBRIDGE, qtrsm_ounncopy_SANDYBRIDGE, qtrsm_outucopy_SANDYBRIDGE, qtrsm_outncopy_SANDYBRIDGE,
  qtrsm_olnucopy_SANDYBRIDGE, qtrsm_olnncopy_SANDYBRIDGE, qtrsm_oltucopy_SANDYBRIDGE, qtrsm_oltncopy_SANDYBRIDGE,
  qtrmm_kernel_RN_SANDYBRIDGE, qtrmm_kernel_RT_SANDYBRIDGE, qtrmm_kernel_LN_SANDYBRIDGE, qtrmm_kernel_LT_SANDYBRIDGE,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_SANDYBRIDGE, qtrmm_iunncopy_SANDYBRIDGE, qtrmm_iutucopy_SANDYBRIDGE, qtrmm_iutncopy_SANDYBRIDGE,
  qtrmm_ilnucopy_SANDYBRIDGE, qtrmm_ilnncopy_SANDYBRIDGE, qtrmm_iltucopy_SANDYBRIDGE, qtrmm_iltncopy_SANDYBRIDGE,
#else
  qtrmm_ounucopy_SANDYBRIDGE, qtrmm_ounncopy_SANDYBRIDGE, qtrmm_outucopy_SANDYBRIDGE, qtrmm_outncopy_SANDYBRIDGE,
  qtrmm_olnucopy_SANDYBRIDGE, qtrmm_olnncopy_SANDYBRIDGE, qtrmm_oltucopy_SANDYBRIDGE, qtrmm_oltncopy_SANDYBRIDGE,
#endif
  qtrmm_ounucopy_SANDYBRIDGE, qtrmm_ounncopy_SANDYBRIDGE, qtrmm_outucopy_SANDYBRIDGE, qtrmm_outncopy_SANDYBRIDGE,
  qtrmm_olnucopy_SANDYBRIDGE, qtrmm_olnncopy_SANDYBRIDGE, qtrmm_oltucopy_SANDYBRIDGE, qtrmm_oltncopy_SANDYBRIDGE,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_SANDYBRIDGE, qsymm_iltcopy_SANDYBRIDGE,
#else
  qsymm_outcopy_SANDYBRIDGE, qsymm_oltcopy_SANDYBRIDGE,
#endif
  qsymm_outcopy_SANDYBRIDGE, qsymm_oltcopy_SANDYBRIDGE,

#ifndef NO_LAPACK
  qneg_tcopy_SANDYBRIDGE, qlaswp_ncopy_SANDYBRIDGE,
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
  camax_k_SANDYBRIDGE, camin_k_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
  icamax_k_SANDYBRIDGE, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_SANDYBRIDGE,
  cnrm2_k_SANDYBRIDGE, casum_k_SANDYBRIDGE, csum_k_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_SANDYBRIDGE, cdotu_k_SANDYBRIDGE, cdotc_k_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
 csrot_k_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_SANDYBRIDGE,
  caxpyc_k_SANDYBRIDGE, 
  cscal_k_SANDYBRIDGE, 
  cswap_k_SANDYBRIDGE,

  cgemv_n_SANDYBRIDGE, cgemv_t_SANDYBRIDGE, cgemv_r_SANDYBRIDGE, cgemv_c_SANDYBRIDGE,
  cgemv_o_SANDYBRIDGE, cgemv_u_SANDYBRIDGE, cgemv_s_SANDYBRIDGE, cgemv_d_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_SANDYBRIDGE, cgerc_k_SANDYBRIDGE, cgerv_k_SANDYBRIDGE, cgerd_k_SANDYBRIDGE,
  csymv_L_SANDYBRIDGE, csymv_U_SANDYBRIDGE,
  chemv_L_SANDYBRIDGE, chemv_U_SANDYBRIDGE, chemv_M_SANDYBRIDGE, chemv_V_SANDYBRIDGE,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_SANDYBRIDGE, cgemm_kernel_l_SANDYBRIDGE, cgemm_kernel_r_SANDYBRIDGE, cgemm_kernel_b_SANDYBRIDGE,
  cgemm_beta_SANDYBRIDGE,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_SANDYBRIDGE, cgemm_itcopy_SANDYBRIDGE,
#else
  cgemm_oncopy_SANDYBRIDGE, cgemm_otcopy_SANDYBRIDGE,
#endif
  cgemm_oncopy_SANDYBRIDGE, cgemm_otcopy_SANDYBRIDGE,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_SANDYBRIDGE,
  cgemm_small_kernel_nn_SANDYBRIDGE, cgemm_small_kernel_nt_SANDYBRIDGE, cgemm_small_kernel_nr_SANDYBRIDGE, cgemm_small_kernel_nc_SANDYBRIDGE,
  cgemm_small_kernel_tn_SANDYBRIDGE, cgemm_small_kernel_tt_SANDYBRIDGE, cgemm_small_kernel_tr_SANDYBRIDGE, cgemm_small_kernel_tc_SANDYBRIDGE,
  cgemm_small_kernel_rn_SANDYBRIDGE, cgemm_small_kernel_rt_SANDYBRIDGE, cgemm_small_kernel_rr_SANDYBRIDGE, cgemm_small_kernel_rc_SANDYBRIDGE,
  cgemm_small_kernel_cn_SANDYBRIDGE, cgemm_small_kernel_ct_SANDYBRIDGE, cgemm_small_kernel_cr_SANDYBRIDGE, cgemm_small_kernel_cc_SANDYBRIDGE,
  cgemm_small_kernel_b0_nn_SANDYBRIDGE, cgemm_small_kernel_b0_nt_SANDYBRIDGE, cgemm_small_kernel_b0_nr_SANDYBRIDGE, cgemm_small_kernel_b0_nc_SANDYBRIDGE,
  cgemm_small_kernel_b0_tn_SANDYBRIDGE, cgemm_small_kernel_b0_tt_SANDYBRIDGE, cgemm_small_kernel_b0_tr_SANDYBRIDGE, cgemm_small_kernel_b0_tc_SANDYBRIDGE,
  cgemm_small_kernel_b0_rn_SANDYBRIDGE, cgemm_small_kernel_b0_rt_SANDYBRIDGE, cgemm_small_kernel_b0_rr_SANDYBRIDGE, cgemm_small_kernel_b0_rc_SANDYBRIDGE,
  cgemm_small_kernel_b0_cn_SANDYBRIDGE, cgemm_small_kernel_b0_ct_SANDYBRIDGE, cgemm_small_kernel_b0_cr_SANDYBRIDGE, cgemm_small_kernel_b0_cc_SANDYBRIDGE,
#endif

  ctrsm_kernel_LN_SANDYBRIDGE, ctrsm_kernel_LT_SANDYBRIDGE, ctrsm_kernel_LR_SANDYBRIDGE, ctrsm_kernel_LC_SANDYBRIDGE,
  ctrsm_kernel_RN_SANDYBRIDGE, ctrsm_kernel_RT_SANDYBRIDGE, ctrsm_kernel_RR_SANDYBRIDGE, ctrsm_kernel_RC_SANDYBRIDGE,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_SANDYBRIDGE,  ctrsm_iunncopy_SANDYBRIDGE,  ctrsm_iutucopy_SANDYBRIDGE,  ctrsm_iutncopy_SANDYBRIDGE,
  ctrsm_ilnucopy_SANDYBRIDGE,  ctrsm_ilnncopy_SANDYBRIDGE,  ctrsm_iltucopy_SANDYBRIDGE,  ctrsm_iltncopy_SANDYBRIDGE,
#else
  ctrsm_ounucopy_SANDYBRIDGE,  ctrsm_ounncopy_SANDYBRIDGE,  ctrsm_outucopy_SANDYBRIDGE,  ctrsm_outncopy_SANDYBRIDGE,
  ctrsm_olnucopy_SANDYBRIDGE,  ctrsm_olnncopy_SANDYBRIDGE,  ctrsm_oltucopy_SANDYBRIDGE,  ctrsm_oltncopy_SANDYBRIDGE,
#endif
  ctrsm_ounucopy_SANDYBRIDGE,  ctrsm_ounncopy_SANDYBRIDGE,  ctrsm_outucopy_SANDYBRIDGE,  ctrsm_outncopy_SANDYBRIDGE,
  ctrsm_olnucopy_SANDYBRIDGE,  ctrsm_olnncopy_SANDYBRIDGE,  ctrsm_oltucopy_SANDYBRIDGE,  ctrsm_oltncopy_SANDYBRIDGE,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_SANDYBRIDGE,  ctrmm_kernel_RT_SANDYBRIDGE,  ctrmm_kernel_RR_SANDYBRIDGE,  ctrmm_kernel_RC_SANDYBRIDGE,
  ctrmm_kernel_LN_SANDYBRIDGE,  ctrmm_kernel_LT_SANDYBRIDGE,  ctrmm_kernel_LR_SANDYBRIDGE,  ctrmm_kernel_LC_SANDYBRIDGE,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_SANDYBRIDGE,  ctrmm_iunncopy_SANDYBRIDGE,  ctrmm_iutucopy_SANDYBRIDGE,  ctrmm_iutncopy_SANDYBRIDGE,
  ctrmm_ilnucopy_SANDYBRIDGE,  ctrmm_ilnncopy_SANDYBRIDGE,  ctrmm_iltucopy_SANDYBRIDGE,  ctrmm_iltncopy_SANDYBRIDGE,
#else
  ctrmm_ounucopy_SANDYBRIDGE,  ctrmm_ounncopy_SANDYBRIDGE,  ctrmm_outucopy_SANDYBRIDGE,  ctrmm_outncopy_SANDYBRIDGE,
  ctrmm_olnucopy_SANDYBRIDGE,  ctrmm_olnncopy_SANDYBRIDGE,  ctrmm_oltucopy_SANDYBRIDGE,  ctrmm_oltncopy_SANDYBRIDGE,
#endif
  ctrmm_ounucopy_SANDYBRIDGE,  ctrmm_ounncopy_SANDYBRIDGE,  ctrmm_outucopy_SANDYBRIDGE,  ctrmm_outncopy_SANDYBRIDGE,
  ctrmm_olnucopy_SANDYBRIDGE,  ctrmm_olnncopy_SANDYBRIDGE,  ctrmm_oltucopy_SANDYBRIDGE,  ctrmm_oltncopy_SANDYBRIDGE,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_SANDYBRIDGE,  csymm_iltcopy_SANDYBRIDGE,
#else
  csymm_outcopy_SANDYBRIDGE,  csymm_oltcopy_SANDYBRIDGE,
#endif
  csymm_outcopy_SANDYBRIDGE,  csymm_oltcopy_SANDYBRIDGE,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_SANDYBRIDGE,  chemm_iltcopy_SANDYBRIDGE,
#else
  chemm_outcopy_SANDYBRIDGE,  chemm_oltcopy_SANDYBRIDGE,
#endif
  chemm_outcopy_SANDYBRIDGE,  chemm_oltcopy_SANDYBRIDGE,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_SANDYBRIDGE,

  cgemm3m_incopyb_SANDYBRIDGE,  cgemm3m_incopyr_SANDYBRIDGE,
  cgemm3m_incopyi_SANDYBRIDGE,  cgemm3m_itcopyb_SANDYBRIDGE,
  cgemm3m_itcopyr_SANDYBRIDGE,  cgemm3m_itcopyi_SANDYBRIDGE,
  cgemm3m_oncopyb_SANDYBRIDGE,  cgemm3m_oncopyr_SANDYBRIDGE,
  cgemm3m_oncopyi_SANDYBRIDGE,  cgemm3m_otcopyb_SANDYBRIDGE,
  cgemm3m_otcopyr_SANDYBRIDGE,  cgemm3m_otcopyi_SANDYBRIDGE,

  csymm3m_iucopyb_SANDYBRIDGE,  csymm3m_ilcopyb_SANDYBRIDGE,
  csymm3m_iucopyr_SANDYBRIDGE,  csymm3m_ilcopyr_SANDYBRIDGE,
  csymm3m_iucopyi_SANDYBRIDGE,  csymm3m_ilcopyi_SANDYBRIDGE,
  csymm3m_oucopyb_SANDYBRIDGE,  csymm3m_olcopyb_SANDYBRIDGE,
  csymm3m_oucopyr_SANDYBRIDGE,  csymm3m_olcopyr_SANDYBRIDGE,
  csymm3m_oucopyi_SANDYBRIDGE,  csymm3m_olcopyi_SANDYBRIDGE,

  chemm3m_iucopyb_SANDYBRIDGE,  chemm3m_ilcopyb_SANDYBRIDGE,
  chemm3m_iucopyr_SANDYBRIDGE,  chemm3m_ilcopyr_SANDYBRIDGE,
  chemm3m_iucopyi_SANDYBRIDGE,  chemm3m_ilcopyi_SANDYBRIDGE,

  chemm3m_oucopyb_SANDYBRIDGE,  chemm3m_olcopyb_SANDYBRIDGE,
  chemm3m_oucopyr_SANDYBRIDGE,  chemm3m_olcopyr_SANDYBRIDGE,
  chemm3m_oucopyi_SANDYBRIDGE,  chemm3m_olcopyi_SANDYBRIDGE,
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
  cneg_tcopy_SANDYBRIDGE,
  
   claswp_ncopy_SANDYBRIDGE,
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

  zamax_k_SANDYBRIDGE, zamin_k_SANDYBRIDGE, izamax_k_SANDYBRIDGE, izamin_k_SANDYBRIDGE,
  znrm2_k_SANDYBRIDGE, zasum_k_SANDYBRIDGE, zsum_k_SANDYBRIDGE, zcopy_k_SANDYBRIDGE,
  zdotu_k_SANDYBRIDGE, zdotc_k_SANDYBRIDGE, zdrot_k_SANDYBRIDGE,
  zaxpy_k_SANDYBRIDGE, zaxpyc_k_SANDYBRIDGE, zscal_k_SANDYBRIDGE, zswap_k_SANDYBRIDGE,

  zgemv_n_SANDYBRIDGE, zgemv_t_SANDYBRIDGE, zgemv_r_SANDYBRIDGE, zgemv_c_SANDYBRIDGE,
  zgemv_o_SANDYBRIDGE, zgemv_u_SANDYBRIDGE, zgemv_s_SANDYBRIDGE, zgemv_d_SANDYBRIDGE,
  zgeru_k_SANDYBRIDGE, zgerc_k_SANDYBRIDGE, zgerv_k_SANDYBRIDGE, zgerd_k_SANDYBRIDGE,
  zsymv_L_SANDYBRIDGE, zsymv_U_SANDYBRIDGE,
  zhemv_L_SANDYBRIDGE, zhemv_U_SANDYBRIDGE, zhemv_M_SANDYBRIDGE, zhemv_V_SANDYBRIDGE,

  zgemm_kernel_n_SANDYBRIDGE, zgemm_kernel_l_SANDYBRIDGE, zgemm_kernel_r_SANDYBRIDGE, zgemm_kernel_b_SANDYBRIDGE,
  zgemm_beta_SANDYBRIDGE,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_SANDYBRIDGE, zgemm_itcopy_SANDYBRIDGE,
#else
  zgemm_oncopy_SANDYBRIDGE, zgemm_otcopy_SANDYBRIDGE,
#endif
  zgemm_oncopy_SANDYBRIDGE, zgemm_otcopy_SANDYBRIDGE,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_SANDYBRIDGE,
  zgemm_small_kernel_nn_SANDYBRIDGE, zgemm_small_kernel_nt_SANDYBRIDGE, zgemm_small_kernel_nr_SANDYBRIDGE, zgemm_small_kernel_nc_SANDYBRIDGE,
  zgemm_small_kernel_tn_SANDYBRIDGE, zgemm_small_kernel_tt_SANDYBRIDGE, zgemm_small_kernel_tr_SANDYBRIDGE, zgemm_small_kernel_tc_SANDYBRIDGE,
  zgemm_small_kernel_rn_SANDYBRIDGE, zgemm_small_kernel_rt_SANDYBRIDGE, zgemm_small_kernel_rr_SANDYBRIDGE, zgemm_small_kernel_rc_SANDYBRIDGE,
  zgemm_small_kernel_cn_SANDYBRIDGE, zgemm_small_kernel_ct_SANDYBRIDGE, zgemm_small_kernel_cr_SANDYBRIDGE, zgemm_small_kernel_cc_SANDYBRIDGE,
  zgemm_small_kernel_b0_nn_SANDYBRIDGE, zgemm_small_kernel_b0_nt_SANDYBRIDGE, zgemm_small_kernel_b0_nr_SANDYBRIDGE, zgemm_small_kernel_b0_nc_SANDYBRIDGE,
  zgemm_small_kernel_b0_tn_SANDYBRIDGE, zgemm_small_kernel_b0_tt_SANDYBRIDGE, zgemm_small_kernel_b0_tr_SANDYBRIDGE, zgemm_small_kernel_b0_tc_SANDYBRIDGE,
  zgemm_small_kernel_b0_rn_SANDYBRIDGE, zgemm_small_kernel_b0_rt_SANDYBRIDGE, zgemm_small_kernel_b0_rr_SANDYBRIDGE, zgemm_small_kernel_b0_rc_SANDYBRIDGE,
  zgemm_small_kernel_b0_cn_SANDYBRIDGE, zgemm_small_kernel_b0_ct_SANDYBRIDGE, zgemm_small_kernel_b0_cr_SANDYBRIDGE, zgemm_small_kernel_b0_cc_SANDYBRIDGE,
#endif

  ztrsm_kernel_LN_SANDYBRIDGE, ztrsm_kernel_LT_SANDYBRIDGE, ztrsm_kernel_LR_SANDYBRIDGE, ztrsm_kernel_LC_SANDYBRIDGE,
  ztrsm_kernel_RN_SANDYBRIDGE, ztrsm_kernel_RT_SANDYBRIDGE, ztrsm_kernel_RR_SANDYBRIDGE, ztrsm_kernel_RC_SANDYBRIDGE,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_SANDYBRIDGE,  ztrsm_iunncopy_SANDYBRIDGE,  ztrsm_iutucopy_SANDYBRIDGE,  ztrsm_iutncopy_SANDYBRIDGE,
  ztrsm_ilnucopy_SANDYBRIDGE,  ztrsm_ilnncopy_SANDYBRIDGE,  ztrsm_iltucopy_SANDYBRIDGE,  ztrsm_iltncopy_SANDYBRIDGE,
#else
  ztrsm_ounucopy_SANDYBRIDGE,  ztrsm_ounncopy_SANDYBRIDGE,  ztrsm_outucopy_SANDYBRIDGE,  ztrsm_outncopy_SANDYBRIDGE,
  ztrsm_olnucopy_SANDYBRIDGE,  ztrsm_olnncopy_SANDYBRIDGE,  ztrsm_oltucopy_SANDYBRIDGE,  ztrsm_oltncopy_SANDYBRIDGE,
#endif
  ztrsm_ounucopy_SANDYBRIDGE,  ztrsm_ounncopy_SANDYBRIDGE,  ztrsm_outucopy_SANDYBRIDGE,  ztrsm_outncopy_SANDYBRIDGE,
  ztrsm_olnucopy_SANDYBRIDGE,  ztrsm_olnncopy_SANDYBRIDGE,  ztrsm_oltucopy_SANDYBRIDGE,  ztrsm_oltncopy_SANDYBRIDGE,

  ztrmm_kernel_RN_SANDYBRIDGE,  ztrmm_kernel_RT_SANDYBRIDGE,  ztrmm_kernel_RR_SANDYBRIDGE,  ztrmm_kernel_RC_SANDYBRIDGE,
  ztrmm_kernel_LN_SANDYBRIDGE,  ztrmm_kernel_LT_SANDYBRIDGE,  ztrmm_kernel_LR_SANDYBRIDGE,  ztrmm_kernel_LC_SANDYBRIDGE,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_SANDYBRIDGE,  ztrmm_iunncopy_SANDYBRIDGE,  ztrmm_iutucopy_SANDYBRIDGE,  ztrmm_iutncopy_SANDYBRIDGE,
  ztrmm_ilnucopy_SANDYBRIDGE,  ztrmm_ilnncopy_SANDYBRIDGE,  ztrmm_iltucopy_SANDYBRIDGE,  ztrmm_iltncopy_SANDYBRIDGE,
#else
  ztrmm_ounucopy_SANDYBRIDGE,  ztrmm_ounncopy_SANDYBRIDGE,  ztrmm_outucopy_SANDYBRIDGE,  ztrmm_outncopy_SANDYBRIDGE,
  ztrmm_olnucopy_SANDYBRIDGE,  ztrmm_olnncopy_SANDYBRIDGE,  ztrmm_oltucopy_SANDYBRIDGE,  ztrmm_oltncopy_SANDYBRIDGE,
#endif
  ztrmm_ounucopy_SANDYBRIDGE,  ztrmm_ounncopy_SANDYBRIDGE,  ztrmm_outucopy_SANDYBRIDGE,  ztrmm_outncopy_SANDYBRIDGE,
  ztrmm_olnucopy_SANDYBRIDGE,  ztrmm_olnncopy_SANDYBRIDGE,  ztrmm_oltucopy_SANDYBRIDGE,  ztrmm_oltncopy_SANDYBRIDGE,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_SANDYBRIDGE,  zsymm_iltcopy_SANDYBRIDGE,
#else
  zsymm_outcopy_SANDYBRIDGE,  zsymm_oltcopy_SANDYBRIDGE,
#endif
  zsymm_outcopy_SANDYBRIDGE,  zsymm_oltcopy_SANDYBRIDGE,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_SANDYBRIDGE,  zhemm_iltcopy_SANDYBRIDGE,
#else
  zhemm_outcopy_SANDYBRIDGE,  zhemm_oltcopy_SANDYBRIDGE,
#endif
  zhemm_outcopy_SANDYBRIDGE,  zhemm_oltcopy_SANDYBRIDGE,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_SANDYBRIDGE,

  zgemm3m_incopyb_SANDYBRIDGE,  zgemm3m_incopyr_SANDYBRIDGE,
  zgemm3m_incopyi_SANDYBRIDGE,  zgemm3m_itcopyb_SANDYBRIDGE,
  zgemm3m_itcopyr_SANDYBRIDGE,  zgemm3m_itcopyi_SANDYBRIDGE,
  zgemm3m_oncopyb_SANDYBRIDGE,  zgemm3m_oncopyr_SANDYBRIDGE,
  zgemm3m_oncopyi_SANDYBRIDGE,  zgemm3m_otcopyb_SANDYBRIDGE,
  zgemm3m_otcopyr_SANDYBRIDGE,  zgemm3m_otcopyi_SANDYBRIDGE,

  zsymm3m_iucopyb_SANDYBRIDGE,  zsymm3m_ilcopyb_SANDYBRIDGE,
  zsymm3m_iucopyr_SANDYBRIDGE,  zsymm3m_ilcopyr_SANDYBRIDGE,
  zsymm3m_iucopyi_SANDYBRIDGE,  zsymm3m_ilcopyi_SANDYBRIDGE,
  zsymm3m_oucopyb_SANDYBRIDGE,  zsymm3m_olcopyb_SANDYBRIDGE,
  zsymm3m_oucopyr_SANDYBRIDGE,  zsymm3m_olcopyr_SANDYBRIDGE,
  zsymm3m_oucopyi_SANDYBRIDGE,  zsymm3m_olcopyi_SANDYBRIDGE,

  zhemm3m_iucopyb_SANDYBRIDGE,  zhemm3m_ilcopyb_SANDYBRIDGE,
  zhemm3m_iucopyr_SANDYBRIDGE,  zhemm3m_ilcopyr_SANDYBRIDGE,
  zhemm3m_iucopyi_SANDYBRIDGE,  zhemm3m_ilcopyi_SANDYBRIDGE,

  zhemm3m_oucopyb_SANDYBRIDGE,  zhemm3m_olcopyb_SANDYBRIDGE,
  zhemm3m_oucopyr_SANDYBRIDGE,  zhemm3m_olcopyr_SANDYBRIDGE,
  zhemm3m_oucopyi_SANDYBRIDGE,  zhemm3m_olcopyi_SANDYBRIDGE,
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
  zneg_tcopy_SANDYBRIDGE, zlaswp_ncopy_SANDYBRIDGE,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_SANDYBRIDGE, xamin_k_SANDYBRIDGE, ixamax_k_SANDYBRIDGE, ixamin_k_SANDYBRIDGE,
  xnrm2_k_SANDYBRIDGE, xasum_k_SANDYBRIDGE, xsum_k_SANDYBRIDGE, xcopy_k_SANDYBRIDGE,
  xdotu_k_SANDYBRIDGE, xdotc_k_SANDYBRIDGE, xqrot_k_SANDYBRIDGE,
  xaxpy_k_SANDYBRIDGE, xaxpyc_k_SANDYBRIDGE, xscal_k_SANDYBRIDGE, xswap_k_SANDYBRIDGE,

  xgemv_n_SANDYBRIDGE, xgemv_t_SANDYBRIDGE, xgemv_r_SANDYBRIDGE, xgemv_c_SANDYBRIDGE,
  xgemv_o_SANDYBRIDGE, xgemv_u_SANDYBRIDGE, xgemv_s_SANDYBRIDGE, xgemv_d_SANDYBRIDGE,
  xgeru_k_SANDYBRIDGE, xgerc_k_SANDYBRIDGE, xgerv_k_SANDYBRIDGE, xgerd_k_SANDYBRIDGE,
  xsymv_L_SANDYBRIDGE, xsymv_U_SANDYBRIDGE,
  xhemv_L_SANDYBRIDGE, xhemv_U_SANDYBRIDGE, xhemv_M_SANDYBRIDGE, xhemv_V_SANDYBRIDGE,

  xgemm_kernel_n_SANDYBRIDGE, xgemm_kernel_l_SANDYBRIDGE, xgemm_kernel_r_SANDYBRIDGE, xgemm_kernel_b_SANDYBRIDGE,
  xgemm_beta_SANDYBRIDGE,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_SANDYBRIDGE, xgemm_itcopy_SANDYBRIDGE,
#else
  xgemm_oncopy_SANDYBRIDGE, xgemm_otcopy_SANDYBRIDGE,
#endif
  xgemm_oncopy_SANDYBRIDGE, xgemm_otcopy_SANDYBRIDGE,

  xtrsm_kernel_LN_SANDYBRIDGE, xtrsm_kernel_LT_SANDYBRIDGE, xtrsm_kernel_LR_SANDYBRIDGE, xtrsm_kernel_LC_SANDYBRIDGE,
  xtrsm_kernel_RN_SANDYBRIDGE, xtrsm_kernel_RT_SANDYBRIDGE, xtrsm_kernel_RR_SANDYBRIDGE, xtrsm_kernel_RC_SANDYBRIDGE,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_SANDYBRIDGE,  xtrsm_iunncopy_SANDYBRIDGE,  xtrsm_iutucopy_SANDYBRIDGE,  xtrsm_iutncopy_SANDYBRIDGE,
  xtrsm_ilnucopy_SANDYBRIDGE,  xtrsm_ilnncopy_SANDYBRIDGE,  xtrsm_iltucopy_SANDYBRIDGE,  xtrsm_iltncopy_SANDYBRIDGE,
#else
  xtrsm_ounucopy_SANDYBRIDGE,  xtrsm_ounncopy_SANDYBRIDGE,  xtrsm_outucopy_SANDYBRIDGE,  xtrsm_outncopy_SANDYBRIDGE,
  xtrsm_olnucopy_SANDYBRIDGE,  xtrsm_olnncopy_SANDYBRIDGE,  xtrsm_oltucopy_SANDYBRIDGE,  xtrsm_oltncopy_SANDYBRIDGE,
#endif
  xtrsm_ounucopy_SANDYBRIDGE,  xtrsm_ounncopy_SANDYBRIDGE,  xtrsm_outucopy_SANDYBRIDGE,  xtrsm_outncopy_SANDYBRIDGE,
  xtrsm_olnucopy_SANDYBRIDGE,  xtrsm_olnncopy_SANDYBRIDGE,  xtrsm_oltucopy_SANDYBRIDGE,  xtrsm_oltncopy_SANDYBRIDGE,

  xtrmm_kernel_RN_SANDYBRIDGE,  xtrmm_kernel_RT_SANDYBRIDGE,  xtrmm_kernel_RR_SANDYBRIDGE,  xtrmm_kernel_RC_SANDYBRIDGE,
  xtrmm_kernel_LN_SANDYBRIDGE,  xtrmm_kernel_LT_SANDYBRIDGE,  xtrmm_kernel_LR_SANDYBRIDGE,  xtrmm_kernel_LC_SANDYBRIDGE,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_SANDYBRIDGE,  xtrmm_iunncopy_SANDYBRIDGE,  xtrmm_iutucopy_SANDYBRIDGE,  xtrmm_iutncopy_SANDYBRIDGE,
  xtrmm_ilnucopy_SANDYBRIDGE,  xtrmm_ilnncopy_SANDYBRIDGE,  xtrmm_iltucopy_SANDYBRIDGE,  xtrmm_iltncopy_SANDYBRIDGE,
#else
  xtrmm_ounucopy_SANDYBRIDGE,  xtrmm_ounncopy_SANDYBRIDGE,  xtrmm_outucopy_SANDYBRIDGE,  xtrmm_outncopy_SANDYBRIDGE,
  xtrmm_olnucopy_SANDYBRIDGE,  xtrmm_olnncopy_SANDYBRIDGE,  xtrmm_oltucopy_SANDYBRIDGE,  xtrmm_oltncopy_SANDYBRIDGE,
#endif
  xtrmm_ounucopy_SANDYBRIDGE,  xtrmm_ounncopy_SANDYBRIDGE,  xtrmm_outucopy_SANDYBRIDGE,  xtrmm_outncopy_SANDYBRIDGE,
  xtrmm_olnucopy_SANDYBRIDGE,  xtrmm_olnncopy_SANDYBRIDGE,  xtrmm_oltucopy_SANDYBRIDGE,  xtrmm_oltncopy_SANDYBRIDGE,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_SANDYBRIDGE,  xsymm_iltcopy_SANDYBRIDGE,
#else
  xsymm_outcopy_SANDYBRIDGE,  xsymm_oltcopy_SANDYBRIDGE,
#endif
  xsymm_outcopy_SANDYBRIDGE,  xsymm_oltcopy_SANDYBRIDGE,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_SANDYBRIDGE,  xhemm_iltcopy_SANDYBRIDGE,
#else
  xhemm_outcopy_SANDYBRIDGE,  xhemm_oltcopy_SANDYBRIDGE,
#endif
  xhemm_outcopy_SANDYBRIDGE,  xhemm_oltcopy_SANDYBRIDGE,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_SANDYBRIDGE,

  xgemm3m_incopyb_SANDYBRIDGE,  xgemm3m_incopyr_SANDYBRIDGE,
  xgemm3m_incopyi_SANDYBRIDGE,  xgemm3m_itcopyb_SANDYBRIDGE,
  xgemm3m_itcopyr_SANDYBRIDGE,  xgemm3m_itcopyi_SANDYBRIDGE,
  xgemm3m_oncopyb_SANDYBRIDGE,  xgemm3m_oncopyr_SANDYBRIDGE,
  xgemm3m_oncopyi_SANDYBRIDGE,  xgemm3m_otcopyb_SANDYBRIDGE,
  xgemm3m_otcopyr_SANDYBRIDGE,  xgemm3m_otcopyi_SANDYBRIDGE,

  xsymm3m_iucopyb_SANDYBRIDGE,  xsymm3m_ilcopyb_SANDYBRIDGE,
  xsymm3m_iucopyr_SANDYBRIDGE,  xsymm3m_ilcopyr_SANDYBRIDGE,
  xsymm3m_iucopyi_SANDYBRIDGE,  xsymm3m_ilcopyi_SANDYBRIDGE,
  xsymm3m_oucopyb_SANDYBRIDGE,  xsymm3m_olcopyb_SANDYBRIDGE,
  xsymm3m_oucopyr_SANDYBRIDGE,  xsymm3m_olcopyr_SANDYBRIDGE,
  xsymm3m_oucopyi_SANDYBRIDGE,  xsymm3m_olcopyi_SANDYBRIDGE,

  xhemm3m_iucopyb_SANDYBRIDGE,  xhemm3m_ilcopyb_SANDYBRIDGE,
  xhemm3m_iucopyr_SANDYBRIDGE,  xhemm3m_ilcopyr_SANDYBRIDGE,
  xhemm3m_iucopyi_SANDYBRIDGE,  xhemm3m_ilcopyi_SANDYBRIDGE,

  xhemm3m_oucopyb_SANDYBRIDGE,  xhemm3m_olcopyb_SANDYBRIDGE,
  xhemm3m_oucopyr_SANDYBRIDGE,  xhemm3m_olcopyr_SANDYBRIDGE,
  xhemm3m_oucopyi_SANDYBRIDGE,  xhemm3m_olcopyi_SANDYBRIDGE,
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
  xneg_tcopy_SANDYBRIDGE, xlaswp_ncopy_SANDYBRIDGE,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_SANDYBRIDGE,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_SANDYBRIDGE,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_SANDYBRIDGE, somatcopy_k_ct_SANDYBRIDGE, somatcopy_k_rn_SANDYBRIDGE, somatcopy_k_rt_SANDYBRIDGE,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_SANDYBRIDGE, domatcopy_k_ct_SANDYBRIDGE, domatcopy_k_rn_SANDYBRIDGE, domatcopy_k_rt_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_SANDYBRIDGE, comatcopy_k_ct_SANDYBRIDGE, comatcopy_k_rn_SANDYBRIDGE, comatcopy_k_rt_SANDYBRIDGE,
  comatcopy_k_cnc_SANDYBRIDGE, comatcopy_k_ctc_SANDYBRIDGE, comatcopy_k_rnc_SANDYBRIDGE, comatcopy_k_rtc_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_SANDYBRIDGE, zomatcopy_k_ct_SANDYBRIDGE, zomatcopy_k_rn_SANDYBRIDGE, zomatcopy_k_rt_SANDYBRIDGE,
  zomatcopy_k_cnc_SANDYBRIDGE, zomatcopy_k_ctc_SANDYBRIDGE, zomatcopy_k_rnc_SANDYBRIDGE, zomatcopy_k_rtc_SANDYBRIDGE,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_SANDYBRIDGE, simatcopy_k_ct_SANDYBRIDGE, simatcopy_k_rn_SANDYBRIDGE, simatcopy_k_rt_SANDYBRIDGE,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_SANDYBRIDGE, dimatcopy_k_ct_SANDYBRIDGE, dimatcopy_k_rn_SANDYBRIDGE, dimatcopy_k_rt_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_SANDYBRIDGE, cimatcopy_k_ct_SANDYBRIDGE, cimatcopy_k_rn_SANDYBRIDGE, cimatcopy_k_rt_SANDYBRIDGE,
  cimatcopy_k_cnc_SANDYBRIDGE, cimatcopy_k_ctc_SANDYBRIDGE, cimatcopy_k_rnc_SANDYBRIDGE, cimatcopy_k_rtc_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_SANDYBRIDGE, zimatcopy_k_ct_SANDYBRIDGE, zimatcopy_k_rn_SANDYBRIDGE, zimatcopy_k_rt_SANDYBRIDGE,
  zimatcopy_k_cnc_SANDYBRIDGE, zimatcopy_k_ctc_SANDYBRIDGE, zimatcopy_k_rnc_SANDYBRIDGE, zimatcopy_k_rtc_SANDYBRIDGE,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_SANDYBRIDGE,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_SANDYBRIDGE,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_SANDYBRIDGE,
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
