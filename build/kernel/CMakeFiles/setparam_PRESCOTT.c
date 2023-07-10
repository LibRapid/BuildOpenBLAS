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
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_PRESCOTT;  OR    */
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
#include "kernel_PRESCOTT.h"
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

  sbstobf16_k_PRESCOTT, sbdtobf16_k_PRESCOTT, sbf16tos_k_PRESCOTT, dbf16tod_k_PRESCOTT,

  samax_k_PRESCOTT,  samin_k_PRESCOTT,  smax_k_PRESCOTT,  smin_k_PRESCOTT,
  isamax_k_PRESCOTT, isamin_k_PRESCOTT, ismax_k_PRESCOTT, ismin_k_PRESCOTT,
  snrm2_k_PRESCOTT,  sasum_k_PRESCOTT, ssum_k_PRESCOTT, scopy_k_PRESCOTT, sbdot_k_PRESCOTT,
  dsdot_k_PRESCOTT,
  srot_k_PRESCOTT,   saxpy_k_PRESCOTT,  sscal_k_PRESCOTT, sswap_k_PRESCOTT,
  sbgemv_n_PRESCOTT, sbgemv_t_PRESCOTT, sger_k_PRESCOTT,
  ssymv_L_PRESCOTT, ssymv_U_PRESCOTT,

  sbgemm_kernel_PRESCOTT, sbgemm_beta_PRESCOTT,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_PRESCOTT, sbgemm_itcopy_PRESCOTT,
#else
  sbgemm_oncopy_PRESCOTT, sbgemm_otcopy_PRESCOTT,
#endif
  sbgemm_oncopy_PRESCOTT, sbgemm_otcopy_PRESCOTT,

  strsm_kernel_LN_PRESCOTT, strsm_kernel_LT_PRESCOTT, strsm_kernel_RN_PRESCOTT, strsm_kernel_RT_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_PRESCOTT, strsm_iunncopy_PRESCOTT, strsm_iutucopy_PRESCOTT, strsm_iutncopy_PRESCOTT,
  strsm_ilnucopy_PRESCOTT, strsm_ilnncopy_PRESCOTT, strsm_iltucopy_PRESCOTT, strsm_iltncopy_PRESCOTT,
#else
  strsm_ounucopy_PRESCOTT, strsm_ounncopy_PRESCOTT, strsm_outucopy_PRESCOTT, strsm_outncopy_PRESCOTT,
  strsm_olnucopy_PRESCOTT, strsm_olnncopy_PRESCOTT, strsm_oltucopy_PRESCOTT, strsm_oltncopy_PRESCOTT,
#endif
  strsm_ounucopy_PRESCOTT, strsm_ounncopy_PRESCOTT, strsm_outucopy_PRESCOTT, strsm_outncopy_PRESCOTT,
  strsm_olnucopy_PRESCOTT, strsm_olnncopy_PRESCOTT, strsm_oltucopy_PRESCOTT, strsm_oltncopy_PRESCOTT,
  strmm_kernel_RN_PRESCOTT, strmm_kernel_RT_PRESCOTT, strmm_kernel_LN_PRESCOTT, strmm_kernel_LT_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_PRESCOTT, strmm_iunncopy_PRESCOTT, strmm_iutucopy_PRESCOTT, strmm_iutncopy_PRESCOTT,
  strmm_ilnucopy_PRESCOTT, strmm_ilnncopy_PRESCOTT, strmm_iltucopy_PRESCOTT, strmm_iltncopy_PRESCOTT,
#else
  strmm_ounucopy_PRESCOTT, strmm_ounncopy_PRESCOTT, strmm_outucopy_PRESCOTT, strmm_outncopy_PRESCOTT,
  strmm_olnucopy_PRESCOTT, strmm_olnncopy_PRESCOTT, strmm_oltucopy_PRESCOTT, strmm_oltncopy_PRESCOTT,
#endif
  strmm_ounucopy_PRESCOTT, strmm_ounncopy_PRESCOTT, strmm_outucopy_PRESCOTT, strmm_outncopy_PRESCOTT,
  strmm_olnucopy_PRESCOTT, strmm_olnncopy_PRESCOTT, strmm_oltucopy_PRESCOTT, strmm_oltncopy_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_PRESCOTT, ssymm_iltcopy_PRESCOTT,
#else
  ssymm_outcopy_PRESCOTT, ssymm_oltcopy_PRESCOTT,
#endif
  ssymm_outcopy_PRESCOTT, ssymm_oltcopy_PRESCOTT,

#ifndef NO_LAPACK
  sneg_tcopy_PRESCOTT, slaswp_ncopy_PRESCOTT,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_PRESCOTT,
  sbgemm_small_kernel_nn_PRESCOTT, sbgemm_small_kernel_nt_PRESCOTT, sbgemm_small_kernel_tn_PRESCOTT, sbgemm_small_kernel_tt_PRESCOTT,
  sbgemm_small_kernel_b0_nn_PRESCOTT, sbgemm_small_kernel_b0_nt_PRESCOTT, sbgemm_small_kernel_b0_tn_PRESCOTT, sbgemm_small_kernel_b0_tt_PRESCOTT,
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
  samax_k_PRESCOTT,  samin_k_PRESCOTT,  smax_k_PRESCOTT,  smin_k_PRESCOTT,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_PRESCOTT,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_PRESCOTT, ismax_k_PRESCOTT, ismin_k_PRESCOTT,
  snrm2_k_PRESCOTT,  sasum_k_PRESCOTT,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_PRESCOTT,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_PRESCOTT, sdot_k_PRESCOTT,
//  dsdot_k_PRESCOTT,
  srot_k_PRESCOTT,   saxpy_k_PRESCOTT,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_PRESCOTT,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_PRESCOTT,
  sgemv_n_PRESCOTT,  sgemv_t_PRESCOTT,
#endif
#if BUILD_SINGLE == 1
  sger_k_PRESCOTT,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_PRESCOTT, ssymv_U_PRESCOTT,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_PRESCOTT,
  sgemm_direct_performant_PRESCOTT,	
#endif

  sgemm_kernel_PRESCOTT, sgemm_beta_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_PRESCOTT, sgemm_itcopy_PRESCOTT,
#else
  sgemm_oncopy_PRESCOTT, sgemm_otcopy_PRESCOTT,
#endif
  sgemm_oncopy_PRESCOTT, sgemm_otcopy_PRESCOTT,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_PRESCOTT,
  sgemm_small_kernel_nn_PRESCOTT, sgemm_small_kernel_nt_PRESCOTT, sgemm_small_kernel_tn_PRESCOTT, sgemm_small_kernel_tt_PRESCOTT,
  sgemm_small_kernel_b0_nn_PRESCOTT, sgemm_small_kernel_b0_nt_PRESCOTT, sgemm_small_kernel_b0_tn_PRESCOTT, sgemm_small_kernel_b0_tt_PRESCOTT,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_PRESCOTT, strsm_kernel_LT_PRESCOTT, strsm_kernel_RN_PRESCOTT, strsm_kernel_RT_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_PRESCOTT, strsm_iunncopy_PRESCOTT, strsm_iutucopy_PRESCOTT, strsm_iutncopy_PRESCOTT,
  strsm_ilnucopy_PRESCOTT, strsm_ilnncopy_PRESCOTT, strsm_iltucopy_PRESCOTT, strsm_iltncopy_PRESCOTT,
#else
  strsm_ounucopy_PRESCOTT, strsm_ounncopy_PRESCOTT, strsm_outucopy_PRESCOTT, strsm_outncopy_PRESCOTT,
  strsm_olnucopy_PRESCOTT, strsm_olnncopy_PRESCOTT, strsm_oltucopy_PRESCOTT, strsm_oltncopy_PRESCOTT,
#endif
  strsm_ounucopy_PRESCOTT, strsm_ounncopy_PRESCOTT, strsm_outucopy_PRESCOTT, strsm_outncopy_PRESCOTT,
  strsm_olnucopy_PRESCOTT, strsm_olnncopy_PRESCOTT, strsm_oltucopy_PRESCOTT, strsm_oltncopy_PRESCOTT,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_PRESCOTT, strmm_kernel_RT_PRESCOTT, strmm_kernel_LN_PRESCOTT, strmm_kernel_LT_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_PRESCOTT, strmm_iunncopy_PRESCOTT, strmm_iutucopy_PRESCOTT, strmm_iutncopy_PRESCOTT,
  strmm_ilnucopy_PRESCOTT, strmm_ilnncopy_PRESCOTT, strmm_iltucopy_PRESCOTT, strmm_iltncopy_PRESCOTT,
#else
  strmm_ounucopy_PRESCOTT, strmm_ounncopy_PRESCOTT, strmm_outucopy_PRESCOTT, strmm_outncopy_PRESCOTT,
  strmm_olnucopy_PRESCOTT, strmm_olnncopy_PRESCOTT, strmm_oltucopy_PRESCOTT, strmm_oltncopy_PRESCOTT,
#endif
  strmm_ounucopy_PRESCOTT, strmm_ounncopy_PRESCOTT, strmm_outucopy_PRESCOTT, strmm_outncopy_PRESCOTT,
  strmm_olnucopy_PRESCOTT, strmm_olnncopy_PRESCOTT, strmm_oltucopy_PRESCOTT, strmm_oltncopy_PRESCOTT,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_PRESCOTT, ssymm_iltcopy_PRESCOTT,
#else
  ssymm_outcopy_PRESCOTT, ssymm_oltcopy_PRESCOTT,
#endif
  ssymm_outcopy_PRESCOTT, ssymm_oltcopy_PRESCOTT,
#ifndef NO_LAPACK
  sneg_tcopy_PRESCOTT, slaswp_ncopy_PRESCOTT,
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
  damax_k_PRESCOTT,  damin_k_PRESCOTT,  dmax_k_PRESCOTT,  dmin_k_PRESCOTT,
  idamax_k_PRESCOTT, idamin_k_PRESCOTT, idmax_k_PRESCOTT, idmin_k_PRESCOTT,
  dnrm2_k_PRESCOTT, dasum_k_PRESCOTT,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_PRESCOTT,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_PRESCOTT, ddot_k_PRESCOTT,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_PRESCOTT,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_PRESCOTT,
  daxpy_k_PRESCOTT,
  dscal_k_PRESCOTT, 
  dswap_k_PRESCOTT,
  dgemv_n_PRESCOTT,  dgemv_t_PRESCOTT,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_PRESCOTT,
  dsymv_L_PRESCOTT,  dsymv_U_PRESCOTT,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_PRESCOTT, dgemm_beta_PRESCOTT,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_PRESCOTT, dgemm_itcopy_PRESCOTT,
#else
  dgemm_oncopy_PRESCOTT, dgemm_otcopy_PRESCOTT,
#endif
  dgemm_oncopy_PRESCOTT, dgemm_otcopy_PRESCOTT,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_PRESCOTT,
  dgemm_small_kernel_nn_PRESCOTT, dgemm_small_kernel_nt_PRESCOTT, dgemm_small_kernel_tn_PRESCOTT, dgemm_small_kernel_tt_PRESCOTT,
  dgemm_small_kernel_b0_nn_PRESCOTT, dgemm_small_kernel_b0_nt_PRESCOTT, dgemm_small_kernel_b0_tn_PRESCOTT, dgemm_small_kernel_b0_tt_PRESCOTT,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_PRESCOTT, dtrsm_kernel_LT_PRESCOTT, dtrsm_kernel_RN_PRESCOTT, dtrsm_kernel_RT_PRESCOTT,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_PRESCOTT, dtrsm_iunncopy_PRESCOTT, dtrsm_iutucopy_PRESCOTT, dtrsm_iutncopy_PRESCOTT,
  dtrsm_ilnucopy_PRESCOTT, dtrsm_ilnncopy_PRESCOTT, dtrsm_iltucopy_PRESCOTT, dtrsm_iltncopy_PRESCOTT,
#else
  dtrsm_ounucopy_PRESCOTT, dtrsm_ounncopy_PRESCOTT, dtrsm_outucopy_PRESCOTT, dtrsm_outncopy_PRESCOTT,
  dtrsm_olnucopy_PRESCOTT, dtrsm_olnncopy_PRESCOTT, dtrsm_oltucopy_PRESCOTT, dtrsm_oltncopy_PRESCOTT,
#endif
  dtrsm_ounucopy_PRESCOTT, dtrsm_ounncopy_PRESCOTT, dtrsm_outucopy_PRESCOTT, dtrsm_outncopy_PRESCOTT,
  dtrsm_olnucopy_PRESCOTT, dtrsm_olnncopy_PRESCOTT, dtrsm_oltucopy_PRESCOTT, dtrsm_oltncopy_PRESCOTT,
  dtrmm_kernel_RN_PRESCOTT, dtrmm_kernel_RT_PRESCOTT, dtrmm_kernel_LN_PRESCOTT, dtrmm_kernel_LT_PRESCOTT,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_PRESCOTT, dtrmm_iunncopy_PRESCOTT, dtrmm_iutucopy_PRESCOTT, dtrmm_iutncopy_PRESCOTT,
  dtrmm_ilnucopy_PRESCOTT, dtrmm_ilnncopy_PRESCOTT, dtrmm_iltucopy_PRESCOTT, dtrmm_iltncopy_PRESCOTT,
#else
  dtrmm_ounucopy_PRESCOTT, dtrmm_ounncopy_PRESCOTT, dtrmm_outucopy_PRESCOTT, dtrmm_outncopy_PRESCOTT,
  dtrmm_olnucopy_PRESCOTT, dtrmm_olnncopy_PRESCOTT, dtrmm_oltucopy_PRESCOTT, dtrmm_oltncopy_PRESCOTT,
#endif
  dtrmm_ounucopy_PRESCOTT, dtrmm_ounncopy_PRESCOTT, dtrmm_outucopy_PRESCOTT, dtrmm_outncopy_PRESCOTT,
  dtrmm_olnucopy_PRESCOTT, dtrmm_olnncopy_PRESCOTT, dtrmm_oltucopy_PRESCOTT, dtrmm_oltncopy_PRESCOTT,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_PRESCOTT, dsymm_iltcopy_PRESCOTT,
#else
  dsymm_outcopy_PRESCOTT, dsymm_oltcopy_PRESCOTT,
#endif
  dsymm_outcopy_PRESCOTT, dsymm_oltcopy_PRESCOTT,

#ifndef NO_LAPACK
  dneg_tcopy_PRESCOTT, dlaswp_ncopy_PRESCOTT,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_PRESCOTT,  qamin_k_PRESCOTT,  qmax_k_PRESCOTT,  qmin_k_PRESCOTT,
  iqamax_k_PRESCOTT, iqamin_k_PRESCOTT, iqmax_k_PRESCOTT, iqmin_k_PRESCOTT,
  qnrm2_k_PRESCOTT,  qasum_k_PRESCOTT,  qsum_k_PRESCOTT, qcopy_k_PRESCOTT, qdot_k_PRESCOTT,
  qrot_k_PRESCOTT,   qaxpy_k_PRESCOTT,  qscal_k_PRESCOTT, qswap_k_PRESCOTT,
  qgemv_n_PRESCOTT,  qgemv_t_PRESCOTT,  qger_k_PRESCOTT,
  qsymv_L_PRESCOTT,  qsymv_U_PRESCOTT,

  qgemm_kernel_PRESCOTT, qgemm_beta_PRESCOTT,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_PRESCOTT, qgemm_itcopy_PRESCOTT,
#else
  qgemm_oncopy_PRESCOTT, qgemm_otcopy_PRESCOTT,
#endif
  qgemm_oncopy_PRESCOTT, qgemm_otcopy_PRESCOTT,
  qtrsm_kernel_LN_PRESCOTT, qtrsm_kernel_LT_PRESCOTT, qtrsm_kernel_RN_PRESCOTT, qtrsm_kernel_RT_PRESCOTT,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_PRESCOTT, qtrsm_iunncopy_PRESCOTT, qtrsm_iutucopy_PRESCOTT, qtrsm_iutncopy_PRESCOTT,
  qtrsm_ilnucopy_PRESCOTT, qtrsm_ilnncopy_PRESCOTT, qtrsm_iltucopy_PRESCOTT, qtrsm_iltncopy_PRESCOTT,
#else
  qtrsm_ounucopy_PRESCOTT, qtrsm_ounncopy_PRESCOTT, qtrsm_outucopy_PRESCOTT, qtrsm_outncopy_PRESCOTT,
  qtrsm_olnucopy_PRESCOTT, qtrsm_olnncopy_PRESCOTT, qtrsm_oltucopy_PRESCOTT, qtrsm_oltncopy_PRESCOTT,
#endif
  qtrsm_ounucopy_PRESCOTT, qtrsm_ounncopy_PRESCOTT, qtrsm_outucopy_PRESCOTT, qtrsm_outncopy_PRESCOTT,
  qtrsm_olnucopy_PRESCOTT, qtrsm_olnncopy_PRESCOTT, qtrsm_oltucopy_PRESCOTT, qtrsm_oltncopy_PRESCOTT,
  qtrmm_kernel_RN_PRESCOTT, qtrmm_kernel_RT_PRESCOTT, qtrmm_kernel_LN_PRESCOTT, qtrmm_kernel_LT_PRESCOTT,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_PRESCOTT, qtrmm_iunncopy_PRESCOTT, qtrmm_iutucopy_PRESCOTT, qtrmm_iutncopy_PRESCOTT,
  qtrmm_ilnucopy_PRESCOTT, qtrmm_ilnncopy_PRESCOTT, qtrmm_iltucopy_PRESCOTT, qtrmm_iltncopy_PRESCOTT,
#else
  qtrmm_ounucopy_PRESCOTT, qtrmm_ounncopy_PRESCOTT, qtrmm_outucopy_PRESCOTT, qtrmm_outncopy_PRESCOTT,
  qtrmm_olnucopy_PRESCOTT, qtrmm_olnncopy_PRESCOTT, qtrmm_oltucopy_PRESCOTT, qtrmm_oltncopy_PRESCOTT,
#endif
  qtrmm_ounucopy_PRESCOTT, qtrmm_ounncopy_PRESCOTT, qtrmm_outucopy_PRESCOTT, qtrmm_outncopy_PRESCOTT,
  qtrmm_olnucopy_PRESCOTT, qtrmm_olnncopy_PRESCOTT, qtrmm_oltucopy_PRESCOTT, qtrmm_oltncopy_PRESCOTT,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_PRESCOTT, qsymm_iltcopy_PRESCOTT,
#else
  qsymm_outcopy_PRESCOTT, qsymm_oltcopy_PRESCOTT,
#endif
  qsymm_outcopy_PRESCOTT, qsymm_oltcopy_PRESCOTT,

#ifndef NO_LAPACK
  qneg_tcopy_PRESCOTT, qlaswp_ncopy_PRESCOTT,
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
  camax_k_PRESCOTT, camin_k_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
  icamax_k_PRESCOTT, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_PRESCOTT,
  cnrm2_k_PRESCOTT, casum_k_PRESCOTT, csum_k_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_PRESCOTT, cdotu_k_PRESCOTT, cdotc_k_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
 csrot_k_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_PRESCOTT,
  caxpyc_k_PRESCOTT, 
  cscal_k_PRESCOTT, 
  cswap_k_PRESCOTT,

  cgemv_n_PRESCOTT, cgemv_t_PRESCOTT, cgemv_r_PRESCOTT, cgemv_c_PRESCOTT,
  cgemv_o_PRESCOTT, cgemv_u_PRESCOTT, cgemv_s_PRESCOTT, cgemv_d_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_PRESCOTT, cgerc_k_PRESCOTT, cgerv_k_PRESCOTT, cgerd_k_PRESCOTT,
  csymv_L_PRESCOTT, csymv_U_PRESCOTT,
  chemv_L_PRESCOTT, chemv_U_PRESCOTT, chemv_M_PRESCOTT, chemv_V_PRESCOTT,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_PRESCOTT, cgemm_kernel_l_PRESCOTT, cgemm_kernel_r_PRESCOTT, cgemm_kernel_b_PRESCOTT,
  cgemm_beta_PRESCOTT,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_PRESCOTT, cgemm_itcopy_PRESCOTT,
#else
  cgemm_oncopy_PRESCOTT, cgemm_otcopy_PRESCOTT,
#endif
  cgemm_oncopy_PRESCOTT, cgemm_otcopy_PRESCOTT,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_PRESCOTT,
  cgemm_small_kernel_nn_PRESCOTT, cgemm_small_kernel_nt_PRESCOTT, cgemm_small_kernel_nr_PRESCOTT, cgemm_small_kernel_nc_PRESCOTT,
  cgemm_small_kernel_tn_PRESCOTT, cgemm_small_kernel_tt_PRESCOTT, cgemm_small_kernel_tr_PRESCOTT, cgemm_small_kernel_tc_PRESCOTT,
  cgemm_small_kernel_rn_PRESCOTT, cgemm_small_kernel_rt_PRESCOTT, cgemm_small_kernel_rr_PRESCOTT, cgemm_small_kernel_rc_PRESCOTT,
  cgemm_small_kernel_cn_PRESCOTT, cgemm_small_kernel_ct_PRESCOTT, cgemm_small_kernel_cr_PRESCOTT, cgemm_small_kernel_cc_PRESCOTT,
  cgemm_small_kernel_b0_nn_PRESCOTT, cgemm_small_kernel_b0_nt_PRESCOTT, cgemm_small_kernel_b0_nr_PRESCOTT, cgemm_small_kernel_b0_nc_PRESCOTT,
  cgemm_small_kernel_b0_tn_PRESCOTT, cgemm_small_kernel_b0_tt_PRESCOTT, cgemm_small_kernel_b0_tr_PRESCOTT, cgemm_small_kernel_b0_tc_PRESCOTT,
  cgemm_small_kernel_b0_rn_PRESCOTT, cgemm_small_kernel_b0_rt_PRESCOTT, cgemm_small_kernel_b0_rr_PRESCOTT, cgemm_small_kernel_b0_rc_PRESCOTT,
  cgemm_small_kernel_b0_cn_PRESCOTT, cgemm_small_kernel_b0_ct_PRESCOTT, cgemm_small_kernel_b0_cr_PRESCOTT, cgemm_small_kernel_b0_cc_PRESCOTT,
#endif

  ctrsm_kernel_LN_PRESCOTT, ctrsm_kernel_LT_PRESCOTT, ctrsm_kernel_LR_PRESCOTT, ctrsm_kernel_LC_PRESCOTT,
  ctrsm_kernel_RN_PRESCOTT, ctrsm_kernel_RT_PRESCOTT, ctrsm_kernel_RR_PRESCOTT, ctrsm_kernel_RC_PRESCOTT,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_PRESCOTT,  ctrsm_iunncopy_PRESCOTT,  ctrsm_iutucopy_PRESCOTT,  ctrsm_iutncopy_PRESCOTT,
  ctrsm_ilnucopy_PRESCOTT,  ctrsm_ilnncopy_PRESCOTT,  ctrsm_iltucopy_PRESCOTT,  ctrsm_iltncopy_PRESCOTT,
#else
  ctrsm_ounucopy_PRESCOTT,  ctrsm_ounncopy_PRESCOTT,  ctrsm_outucopy_PRESCOTT,  ctrsm_outncopy_PRESCOTT,
  ctrsm_olnucopy_PRESCOTT,  ctrsm_olnncopy_PRESCOTT,  ctrsm_oltucopy_PRESCOTT,  ctrsm_oltncopy_PRESCOTT,
#endif
  ctrsm_ounucopy_PRESCOTT,  ctrsm_ounncopy_PRESCOTT,  ctrsm_outucopy_PRESCOTT,  ctrsm_outncopy_PRESCOTT,
  ctrsm_olnucopy_PRESCOTT,  ctrsm_olnncopy_PRESCOTT,  ctrsm_oltucopy_PRESCOTT,  ctrsm_oltncopy_PRESCOTT,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_PRESCOTT,  ctrmm_kernel_RT_PRESCOTT,  ctrmm_kernel_RR_PRESCOTT,  ctrmm_kernel_RC_PRESCOTT,
  ctrmm_kernel_LN_PRESCOTT,  ctrmm_kernel_LT_PRESCOTT,  ctrmm_kernel_LR_PRESCOTT,  ctrmm_kernel_LC_PRESCOTT,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_PRESCOTT,  ctrmm_iunncopy_PRESCOTT,  ctrmm_iutucopy_PRESCOTT,  ctrmm_iutncopy_PRESCOTT,
  ctrmm_ilnucopy_PRESCOTT,  ctrmm_ilnncopy_PRESCOTT,  ctrmm_iltucopy_PRESCOTT,  ctrmm_iltncopy_PRESCOTT,
#else
  ctrmm_ounucopy_PRESCOTT,  ctrmm_ounncopy_PRESCOTT,  ctrmm_outucopy_PRESCOTT,  ctrmm_outncopy_PRESCOTT,
  ctrmm_olnucopy_PRESCOTT,  ctrmm_olnncopy_PRESCOTT,  ctrmm_oltucopy_PRESCOTT,  ctrmm_oltncopy_PRESCOTT,
#endif
  ctrmm_ounucopy_PRESCOTT,  ctrmm_ounncopy_PRESCOTT,  ctrmm_outucopy_PRESCOTT,  ctrmm_outncopy_PRESCOTT,
  ctrmm_olnucopy_PRESCOTT,  ctrmm_olnncopy_PRESCOTT,  ctrmm_oltucopy_PRESCOTT,  ctrmm_oltncopy_PRESCOTT,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_PRESCOTT,  csymm_iltcopy_PRESCOTT,
#else
  csymm_outcopy_PRESCOTT,  csymm_oltcopy_PRESCOTT,
#endif
  csymm_outcopy_PRESCOTT,  csymm_oltcopy_PRESCOTT,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_PRESCOTT,  chemm_iltcopy_PRESCOTT,
#else
  chemm_outcopy_PRESCOTT,  chemm_oltcopy_PRESCOTT,
#endif
  chemm_outcopy_PRESCOTT,  chemm_oltcopy_PRESCOTT,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_PRESCOTT,

  cgemm3m_incopyb_PRESCOTT,  cgemm3m_incopyr_PRESCOTT,
  cgemm3m_incopyi_PRESCOTT,  cgemm3m_itcopyb_PRESCOTT,
  cgemm3m_itcopyr_PRESCOTT,  cgemm3m_itcopyi_PRESCOTT,
  cgemm3m_oncopyb_PRESCOTT,  cgemm3m_oncopyr_PRESCOTT,
  cgemm3m_oncopyi_PRESCOTT,  cgemm3m_otcopyb_PRESCOTT,
  cgemm3m_otcopyr_PRESCOTT,  cgemm3m_otcopyi_PRESCOTT,

  csymm3m_iucopyb_PRESCOTT,  csymm3m_ilcopyb_PRESCOTT,
  csymm3m_iucopyr_PRESCOTT,  csymm3m_ilcopyr_PRESCOTT,
  csymm3m_iucopyi_PRESCOTT,  csymm3m_ilcopyi_PRESCOTT,
  csymm3m_oucopyb_PRESCOTT,  csymm3m_olcopyb_PRESCOTT,
  csymm3m_oucopyr_PRESCOTT,  csymm3m_olcopyr_PRESCOTT,
  csymm3m_oucopyi_PRESCOTT,  csymm3m_olcopyi_PRESCOTT,

  chemm3m_iucopyb_PRESCOTT,  chemm3m_ilcopyb_PRESCOTT,
  chemm3m_iucopyr_PRESCOTT,  chemm3m_ilcopyr_PRESCOTT,
  chemm3m_iucopyi_PRESCOTT,  chemm3m_ilcopyi_PRESCOTT,

  chemm3m_oucopyb_PRESCOTT,  chemm3m_olcopyb_PRESCOTT,
  chemm3m_oucopyr_PRESCOTT,  chemm3m_olcopyr_PRESCOTT,
  chemm3m_oucopyi_PRESCOTT,  chemm3m_olcopyi_PRESCOTT,
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
  cneg_tcopy_PRESCOTT,
  
   claswp_ncopy_PRESCOTT,
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

  zamax_k_PRESCOTT, zamin_k_PRESCOTT, izamax_k_PRESCOTT, izamin_k_PRESCOTT,
  znrm2_k_PRESCOTT, zasum_k_PRESCOTT, zsum_k_PRESCOTT, zcopy_k_PRESCOTT,
  zdotu_k_PRESCOTT, zdotc_k_PRESCOTT, zdrot_k_PRESCOTT,
  zaxpy_k_PRESCOTT, zaxpyc_k_PRESCOTT, zscal_k_PRESCOTT, zswap_k_PRESCOTT,

  zgemv_n_PRESCOTT, zgemv_t_PRESCOTT, zgemv_r_PRESCOTT, zgemv_c_PRESCOTT,
  zgemv_o_PRESCOTT, zgemv_u_PRESCOTT, zgemv_s_PRESCOTT, zgemv_d_PRESCOTT,
  zgeru_k_PRESCOTT, zgerc_k_PRESCOTT, zgerv_k_PRESCOTT, zgerd_k_PRESCOTT,
  zsymv_L_PRESCOTT, zsymv_U_PRESCOTT,
  zhemv_L_PRESCOTT, zhemv_U_PRESCOTT, zhemv_M_PRESCOTT, zhemv_V_PRESCOTT,

  zgemm_kernel_n_PRESCOTT, zgemm_kernel_l_PRESCOTT, zgemm_kernel_r_PRESCOTT, zgemm_kernel_b_PRESCOTT,
  zgemm_beta_PRESCOTT,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_PRESCOTT, zgemm_itcopy_PRESCOTT,
#else
  zgemm_oncopy_PRESCOTT, zgemm_otcopy_PRESCOTT,
#endif
  zgemm_oncopy_PRESCOTT, zgemm_otcopy_PRESCOTT,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_PRESCOTT,
  zgemm_small_kernel_nn_PRESCOTT, zgemm_small_kernel_nt_PRESCOTT, zgemm_small_kernel_nr_PRESCOTT, zgemm_small_kernel_nc_PRESCOTT,
  zgemm_small_kernel_tn_PRESCOTT, zgemm_small_kernel_tt_PRESCOTT, zgemm_small_kernel_tr_PRESCOTT, zgemm_small_kernel_tc_PRESCOTT,
  zgemm_small_kernel_rn_PRESCOTT, zgemm_small_kernel_rt_PRESCOTT, zgemm_small_kernel_rr_PRESCOTT, zgemm_small_kernel_rc_PRESCOTT,
  zgemm_small_kernel_cn_PRESCOTT, zgemm_small_kernel_ct_PRESCOTT, zgemm_small_kernel_cr_PRESCOTT, zgemm_small_kernel_cc_PRESCOTT,
  zgemm_small_kernel_b0_nn_PRESCOTT, zgemm_small_kernel_b0_nt_PRESCOTT, zgemm_small_kernel_b0_nr_PRESCOTT, zgemm_small_kernel_b0_nc_PRESCOTT,
  zgemm_small_kernel_b0_tn_PRESCOTT, zgemm_small_kernel_b0_tt_PRESCOTT, zgemm_small_kernel_b0_tr_PRESCOTT, zgemm_small_kernel_b0_tc_PRESCOTT,
  zgemm_small_kernel_b0_rn_PRESCOTT, zgemm_small_kernel_b0_rt_PRESCOTT, zgemm_small_kernel_b0_rr_PRESCOTT, zgemm_small_kernel_b0_rc_PRESCOTT,
  zgemm_small_kernel_b0_cn_PRESCOTT, zgemm_small_kernel_b0_ct_PRESCOTT, zgemm_small_kernel_b0_cr_PRESCOTT, zgemm_small_kernel_b0_cc_PRESCOTT,
#endif

  ztrsm_kernel_LN_PRESCOTT, ztrsm_kernel_LT_PRESCOTT, ztrsm_kernel_LR_PRESCOTT, ztrsm_kernel_LC_PRESCOTT,
  ztrsm_kernel_RN_PRESCOTT, ztrsm_kernel_RT_PRESCOTT, ztrsm_kernel_RR_PRESCOTT, ztrsm_kernel_RC_PRESCOTT,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_PRESCOTT,  ztrsm_iunncopy_PRESCOTT,  ztrsm_iutucopy_PRESCOTT,  ztrsm_iutncopy_PRESCOTT,
  ztrsm_ilnucopy_PRESCOTT,  ztrsm_ilnncopy_PRESCOTT,  ztrsm_iltucopy_PRESCOTT,  ztrsm_iltncopy_PRESCOTT,
#else
  ztrsm_ounucopy_PRESCOTT,  ztrsm_ounncopy_PRESCOTT,  ztrsm_outucopy_PRESCOTT,  ztrsm_outncopy_PRESCOTT,
  ztrsm_olnucopy_PRESCOTT,  ztrsm_olnncopy_PRESCOTT,  ztrsm_oltucopy_PRESCOTT,  ztrsm_oltncopy_PRESCOTT,
#endif
  ztrsm_ounucopy_PRESCOTT,  ztrsm_ounncopy_PRESCOTT,  ztrsm_outucopy_PRESCOTT,  ztrsm_outncopy_PRESCOTT,
  ztrsm_olnucopy_PRESCOTT,  ztrsm_olnncopy_PRESCOTT,  ztrsm_oltucopy_PRESCOTT,  ztrsm_oltncopy_PRESCOTT,

  ztrmm_kernel_RN_PRESCOTT,  ztrmm_kernel_RT_PRESCOTT,  ztrmm_kernel_RR_PRESCOTT,  ztrmm_kernel_RC_PRESCOTT,
  ztrmm_kernel_LN_PRESCOTT,  ztrmm_kernel_LT_PRESCOTT,  ztrmm_kernel_LR_PRESCOTT,  ztrmm_kernel_LC_PRESCOTT,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_PRESCOTT,  ztrmm_iunncopy_PRESCOTT,  ztrmm_iutucopy_PRESCOTT,  ztrmm_iutncopy_PRESCOTT,
  ztrmm_ilnucopy_PRESCOTT,  ztrmm_ilnncopy_PRESCOTT,  ztrmm_iltucopy_PRESCOTT,  ztrmm_iltncopy_PRESCOTT,
#else
  ztrmm_ounucopy_PRESCOTT,  ztrmm_ounncopy_PRESCOTT,  ztrmm_outucopy_PRESCOTT,  ztrmm_outncopy_PRESCOTT,
  ztrmm_olnucopy_PRESCOTT,  ztrmm_olnncopy_PRESCOTT,  ztrmm_oltucopy_PRESCOTT,  ztrmm_oltncopy_PRESCOTT,
#endif
  ztrmm_ounucopy_PRESCOTT,  ztrmm_ounncopy_PRESCOTT,  ztrmm_outucopy_PRESCOTT,  ztrmm_outncopy_PRESCOTT,
  ztrmm_olnucopy_PRESCOTT,  ztrmm_olnncopy_PRESCOTT,  ztrmm_oltucopy_PRESCOTT,  ztrmm_oltncopy_PRESCOTT,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_PRESCOTT,  zsymm_iltcopy_PRESCOTT,
#else
  zsymm_outcopy_PRESCOTT,  zsymm_oltcopy_PRESCOTT,
#endif
  zsymm_outcopy_PRESCOTT,  zsymm_oltcopy_PRESCOTT,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_PRESCOTT,  zhemm_iltcopy_PRESCOTT,
#else
  zhemm_outcopy_PRESCOTT,  zhemm_oltcopy_PRESCOTT,
#endif
  zhemm_outcopy_PRESCOTT,  zhemm_oltcopy_PRESCOTT,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_PRESCOTT,

  zgemm3m_incopyb_PRESCOTT,  zgemm3m_incopyr_PRESCOTT,
  zgemm3m_incopyi_PRESCOTT,  zgemm3m_itcopyb_PRESCOTT,
  zgemm3m_itcopyr_PRESCOTT,  zgemm3m_itcopyi_PRESCOTT,
  zgemm3m_oncopyb_PRESCOTT,  zgemm3m_oncopyr_PRESCOTT,
  zgemm3m_oncopyi_PRESCOTT,  zgemm3m_otcopyb_PRESCOTT,
  zgemm3m_otcopyr_PRESCOTT,  zgemm3m_otcopyi_PRESCOTT,

  zsymm3m_iucopyb_PRESCOTT,  zsymm3m_ilcopyb_PRESCOTT,
  zsymm3m_iucopyr_PRESCOTT,  zsymm3m_ilcopyr_PRESCOTT,
  zsymm3m_iucopyi_PRESCOTT,  zsymm3m_ilcopyi_PRESCOTT,
  zsymm3m_oucopyb_PRESCOTT,  zsymm3m_olcopyb_PRESCOTT,
  zsymm3m_oucopyr_PRESCOTT,  zsymm3m_olcopyr_PRESCOTT,
  zsymm3m_oucopyi_PRESCOTT,  zsymm3m_olcopyi_PRESCOTT,

  zhemm3m_iucopyb_PRESCOTT,  zhemm3m_ilcopyb_PRESCOTT,
  zhemm3m_iucopyr_PRESCOTT,  zhemm3m_ilcopyr_PRESCOTT,
  zhemm3m_iucopyi_PRESCOTT,  zhemm3m_ilcopyi_PRESCOTT,

  zhemm3m_oucopyb_PRESCOTT,  zhemm3m_olcopyb_PRESCOTT,
  zhemm3m_oucopyr_PRESCOTT,  zhemm3m_olcopyr_PRESCOTT,
  zhemm3m_oucopyi_PRESCOTT,  zhemm3m_olcopyi_PRESCOTT,
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
  zneg_tcopy_PRESCOTT, zlaswp_ncopy_PRESCOTT,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_PRESCOTT, xamin_k_PRESCOTT, ixamax_k_PRESCOTT, ixamin_k_PRESCOTT,
  xnrm2_k_PRESCOTT, xasum_k_PRESCOTT, xsum_k_PRESCOTT, xcopy_k_PRESCOTT,
  xdotu_k_PRESCOTT, xdotc_k_PRESCOTT, xqrot_k_PRESCOTT,
  xaxpy_k_PRESCOTT, xaxpyc_k_PRESCOTT, xscal_k_PRESCOTT, xswap_k_PRESCOTT,

  xgemv_n_PRESCOTT, xgemv_t_PRESCOTT, xgemv_r_PRESCOTT, xgemv_c_PRESCOTT,
  xgemv_o_PRESCOTT, xgemv_u_PRESCOTT, xgemv_s_PRESCOTT, xgemv_d_PRESCOTT,
  xgeru_k_PRESCOTT, xgerc_k_PRESCOTT, xgerv_k_PRESCOTT, xgerd_k_PRESCOTT,
  xsymv_L_PRESCOTT, xsymv_U_PRESCOTT,
  xhemv_L_PRESCOTT, xhemv_U_PRESCOTT, xhemv_M_PRESCOTT, xhemv_V_PRESCOTT,

  xgemm_kernel_n_PRESCOTT, xgemm_kernel_l_PRESCOTT, xgemm_kernel_r_PRESCOTT, xgemm_kernel_b_PRESCOTT,
  xgemm_beta_PRESCOTT,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_PRESCOTT, xgemm_itcopy_PRESCOTT,
#else
  xgemm_oncopy_PRESCOTT, xgemm_otcopy_PRESCOTT,
#endif
  xgemm_oncopy_PRESCOTT, xgemm_otcopy_PRESCOTT,

  xtrsm_kernel_LN_PRESCOTT, xtrsm_kernel_LT_PRESCOTT, xtrsm_kernel_LR_PRESCOTT, xtrsm_kernel_LC_PRESCOTT,
  xtrsm_kernel_RN_PRESCOTT, xtrsm_kernel_RT_PRESCOTT, xtrsm_kernel_RR_PRESCOTT, xtrsm_kernel_RC_PRESCOTT,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_PRESCOTT,  xtrsm_iunncopy_PRESCOTT,  xtrsm_iutucopy_PRESCOTT,  xtrsm_iutncopy_PRESCOTT,
  xtrsm_ilnucopy_PRESCOTT,  xtrsm_ilnncopy_PRESCOTT,  xtrsm_iltucopy_PRESCOTT,  xtrsm_iltncopy_PRESCOTT,
#else
  xtrsm_ounucopy_PRESCOTT,  xtrsm_ounncopy_PRESCOTT,  xtrsm_outucopy_PRESCOTT,  xtrsm_outncopy_PRESCOTT,
  xtrsm_olnucopy_PRESCOTT,  xtrsm_olnncopy_PRESCOTT,  xtrsm_oltucopy_PRESCOTT,  xtrsm_oltncopy_PRESCOTT,
#endif
  xtrsm_ounucopy_PRESCOTT,  xtrsm_ounncopy_PRESCOTT,  xtrsm_outucopy_PRESCOTT,  xtrsm_outncopy_PRESCOTT,
  xtrsm_olnucopy_PRESCOTT,  xtrsm_olnncopy_PRESCOTT,  xtrsm_oltucopy_PRESCOTT,  xtrsm_oltncopy_PRESCOTT,

  xtrmm_kernel_RN_PRESCOTT,  xtrmm_kernel_RT_PRESCOTT,  xtrmm_kernel_RR_PRESCOTT,  xtrmm_kernel_RC_PRESCOTT,
  xtrmm_kernel_LN_PRESCOTT,  xtrmm_kernel_LT_PRESCOTT,  xtrmm_kernel_LR_PRESCOTT,  xtrmm_kernel_LC_PRESCOTT,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_PRESCOTT,  xtrmm_iunncopy_PRESCOTT,  xtrmm_iutucopy_PRESCOTT,  xtrmm_iutncopy_PRESCOTT,
  xtrmm_ilnucopy_PRESCOTT,  xtrmm_ilnncopy_PRESCOTT,  xtrmm_iltucopy_PRESCOTT,  xtrmm_iltncopy_PRESCOTT,
#else
  xtrmm_ounucopy_PRESCOTT,  xtrmm_ounncopy_PRESCOTT,  xtrmm_outucopy_PRESCOTT,  xtrmm_outncopy_PRESCOTT,
  xtrmm_olnucopy_PRESCOTT,  xtrmm_olnncopy_PRESCOTT,  xtrmm_oltucopy_PRESCOTT,  xtrmm_oltncopy_PRESCOTT,
#endif
  xtrmm_ounucopy_PRESCOTT,  xtrmm_ounncopy_PRESCOTT,  xtrmm_outucopy_PRESCOTT,  xtrmm_outncopy_PRESCOTT,
  xtrmm_olnucopy_PRESCOTT,  xtrmm_olnncopy_PRESCOTT,  xtrmm_oltucopy_PRESCOTT,  xtrmm_oltncopy_PRESCOTT,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_PRESCOTT,  xsymm_iltcopy_PRESCOTT,
#else
  xsymm_outcopy_PRESCOTT,  xsymm_oltcopy_PRESCOTT,
#endif
  xsymm_outcopy_PRESCOTT,  xsymm_oltcopy_PRESCOTT,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_PRESCOTT,  xhemm_iltcopy_PRESCOTT,
#else
  xhemm_outcopy_PRESCOTT,  xhemm_oltcopy_PRESCOTT,
#endif
  xhemm_outcopy_PRESCOTT,  xhemm_oltcopy_PRESCOTT,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_PRESCOTT,

  xgemm3m_incopyb_PRESCOTT,  xgemm3m_incopyr_PRESCOTT,
  xgemm3m_incopyi_PRESCOTT,  xgemm3m_itcopyb_PRESCOTT,
  xgemm3m_itcopyr_PRESCOTT,  xgemm3m_itcopyi_PRESCOTT,
  xgemm3m_oncopyb_PRESCOTT,  xgemm3m_oncopyr_PRESCOTT,
  xgemm3m_oncopyi_PRESCOTT,  xgemm3m_otcopyb_PRESCOTT,
  xgemm3m_otcopyr_PRESCOTT,  xgemm3m_otcopyi_PRESCOTT,

  xsymm3m_iucopyb_PRESCOTT,  xsymm3m_ilcopyb_PRESCOTT,
  xsymm3m_iucopyr_PRESCOTT,  xsymm3m_ilcopyr_PRESCOTT,
  xsymm3m_iucopyi_PRESCOTT,  xsymm3m_ilcopyi_PRESCOTT,
  xsymm3m_oucopyb_PRESCOTT,  xsymm3m_olcopyb_PRESCOTT,
  xsymm3m_oucopyr_PRESCOTT,  xsymm3m_olcopyr_PRESCOTT,
  xsymm3m_oucopyi_PRESCOTT,  xsymm3m_olcopyi_PRESCOTT,

  xhemm3m_iucopyb_PRESCOTT,  xhemm3m_ilcopyb_PRESCOTT,
  xhemm3m_iucopyr_PRESCOTT,  xhemm3m_ilcopyr_PRESCOTT,
  xhemm3m_iucopyi_PRESCOTT,  xhemm3m_ilcopyi_PRESCOTT,

  xhemm3m_oucopyb_PRESCOTT,  xhemm3m_olcopyb_PRESCOTT,
  xhemm3m_oucopyr_PRESCOTT,  xhemm3m_olcopyr_PRESCOTT,
  xhemm3m_oucopyi_PRESCOTT,  xhemm3m_olcopyi_PRESCOTT,
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
  xneg_tcopy_PRESCOTT, xlaswp_ncopy_PRESCOTT,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_PRESCOTT,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_PRESCOTT,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_PRESCOTT,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_PRESCOTT,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_PRESCOTT, somatcopy_k_ct_PRESCOTT, somatcopy_k_rn_PRESCOTT, somatcopy_k_rt_PRESCOTT,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_PRESCOTT, domatcopy_k_ct_PRESCOTT, domatcopy_k_rn_PRESCOTT, domatcopy_k_rt_PRESCOTT,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_PRESCOTT, comatcopy_k_ct_PRESCOTT, comatcopy_k_rn_PRESCOTT, comatcopy_k_rt_PRESCOTT,
  comatcopy_k_cnc_PRESCOTT, comatcopy_k_ctc_PRESCOTT, comatcopy_k_rnc_PRESCOTT, comatcopy_k_rtc_PRESCOTT,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_PRESCOTT, zomatcopy_k_ct_PRESCOTT, zomatcopy_k_rn_PRESCOTT, zomatcopy_k_rt_PRESCOTT,
  zomatcopy_k_cnc_PRESCOTT, zomatcopy_k_ctc_PRESCOTT, zomatcopy_k_rnc_PRESCOTT, zomatcopy_k_rtc_PRESCOTT,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_PRESCOTT, simatcopy_k_ct_PRESCOTT, simatcopy_k_rn_PRESCOTT, simatcopy_k_rt_PRESCOTT,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_PRESCOTT, dimatcopy_k_ct_PRESCOTT, dimatcopy_k_rn_PRESCOTT, dimatcopy_k_rt_PRESCOTT,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_PRESCOTT, cimatcopy_k_ct_PRESCOTT, cimatcopy_k_rn_PRESCOTT, cimatcopy_k_rt_PRESCOTT,
  cimatcopy_k_cnc_PRESCOTT, cimatcopy_k_ctc_PRESCOTT, cimatcopy_k_rnc_PRESCOTT, cimatcopy_k_rtc_PRESCOTT,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_PRESCOTT, zimatcopy_k_ct_PRESCOTT, zimatcopy_k_rn_PRESCOTT, zimatcopy_k_rt_PRESCOTT,
  zimatcopy_k_cnc_PRESCOTT, zimatcopy_k_ctc_PRESCOTT, zimatcopy_k_rnc_PRESCOTT, zimatcopy_k_rtc_PRESCOTT,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_PRESCOTT,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_PRESCOTT,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_PRESCOTT,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_PRESCOTT,
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
