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
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFI_HASWELL;  OR    */
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
#include "kernel_HASWELL.h"
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

  sbstobf16_k_HASWELL, sbdtobf16_k_HASWELL, sbf16tos_k_HASWELL, dbf16tod_k_HASWELL,

  samax_k_HASWELL,  samin_k_HASWELL,  smax_k_HASWELL,  smin_k_HASWELL,
  isamax_k_HASWELL, isamin_k_HASWELL, ismax_k_HASWELL, ismin_k_HASWELL,
  snrm2_k_HASWELL,  sasum_k_HASWELL, ssum_k_HASWELL, scopy_k_HASWELL, sbdot_k_HASWELL,
  dsdot_k_HASWELL,
  srot_k_HASWELL,   saxpy_k_HASWELL,  sscal_k_HASWELL, sswap_k_HASWELL,
  sbgemv_n_HASWELL, sbgemv_t_HASWELL, sger_k_HASWELL,
  ssymv_L_HASWELL, ssymv_U_HASWELL,

  sbgemm_kernel_HASWELL, sbgemm_beta_HASWELL,
#if SBGEMM_DEFAULT_UNROLL_M != SBGEMM_DEFAULT_UNROLL_N
  sbgemm_incopy_HASWELL, sbgemm_itcopy_HASWELL,
#else
  sbgemm_oncopy_HASWELL, sbgemm_otcopy_HASWELL,
#endif
  sbgemm_oncopy_HASWELL, sbgemm_otcopy_HASWELL,

  strsm_kernel_LN_HASWELL, strsm_kernel_LT_HASWELL, strsm_kernel_RN_HASWELL, strsm_kernel_RT_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_HASWELL, strsm_iunncopy_HASWELL, strsm_iutucopy_HASWELL, strsm_iutncopy_HASWELL,
  strsm_ilnucopy_HASWELL, strsm_ilnncopy_HASWELL, strsm_iltucopy_HASWELL, strsm_iltncopy_HASWELL,
#else
  strsm_ounucopy_HASWELL, strsm_ounncopy_HASWELL, strsm_outucopy_HASWELL, strsm_outncopy_HASWELL,
  strsm_olnucopy_HASWELL, strsm_olnncopy_HASWELL, strsm_oltucopy_HASWELL, strsm_oltncopy_HASWELL,
#endif
  strsm_ounucopy_HASWELL, strsm_ounncopy_HASWELL, strsm_outucopy_HASWELL, strsm_outncopy_HASWELL,
  strsm_olnucopy_HASWELL, strsm_olnncopy_HASWELL, strsm_oltucopy_HASWELL, strsm_oltncopy_HASWELL,
  strmm_kernel_RN_HASWELL, strmm_kernel_RT_HASWELL, strmm_kernel_LN_HASWELL, strmm_kernel_LT_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_HASWELL, strmm_iunncopy_HASWELL, strmm_iutucopy_HASWELL, strmm_iutncopy_HASWELL,
  strmm_ilnucopy_HASWELL, strmm_ilnncopy_HASWELL, strmm_iltucopy_HASWELL, strmm_iltncopy_HASWELL,
#else
  strmm_ounucopy_HASWELL, strmm_ounncopy_HASWELL, strmm_outucopy_HASWELL, strmm_outncopy_HASWELL,
  strmm_olnucopy_HASWELL, strmm_olnncopy_HASWELL, strmm_oltucopy_HASWELL, strmm_oltncopy_HASWELL,
#endif
  strmm_ounucopy_HASWELL, strmm_ounncopy_HASWELL, strmm_outucopy_HASWELL, strmm_outncopy_HASWELL,
  strmm_olnucopy_HASWELL, strmm_olnncopy_HASWELL, strmm_oltucopy_HASWELL, strmm_oltncopy_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_HASWELL, ssymm_iltcopy_HASWELL,
#else
  ssymm_outcopy_HASWELL, ssymm_oltcopy_HASWELL,
#endif
  ssymm_outcopy_HASWELL, ssymm_oltcopy_HASWELL,

#ifndef NO_LAPACK
  sneg_tcopy_HASWELL, slaswp_ncopy_HASWELL,
#else
  NULL,NULL,
#endif
#ifdef SMALL_MATRIX_OPT
  sbgemm_small_matrix_permit_HASWELL,
  sbgemm_small_kernel_nn_HASWELL, sbgemm_small_kernel_nt_HASWELL, sbgemm_small_kernel_tn_HASWELL, sbgemm_small_kernel_tt_HASWELL,
  sbgemm_small_kernel_b0_nn_HASWELL, sbgemm_small_kernel_b0_nt_HASWELL, sbgemm_small_kernel_b0_tn_HASWELL, sbgemm_small_kernel_b0_tt_HASWELL,
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
  samax_k_HASWELL,  samin_k_HASWELL,  smax_k_HASWELL,  smin_k_HASWELL,
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  isamax_k_HASWELL,
#endif 
#if (BUILD_SINGLE==1 ) || (BUILD_COMPLEX==1)
  isamin_k_HASWELL, ismax_k_HASWELL, ismin_k_HASWELL,
  snrm2_k_HASWELL,  sasum_k_HASWELL,
#endif 
#if BUILD_SINGLE == 1  
  ssum_k_HASWELL,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  scopy_k_HASWELL, sdot_k_HASWELL,
//  dsdot_k_HASWELL,
  srot_k_HASWELL,   saxpy_k_HASWELL,  
#endif
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1) || (BUILD_COMPLEX16==1)
  sscal_k_HASWELL,
#endif 
#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
  sswap_k_HASWELL,
  sgemv_n_HASWELL,  sgemv_t_HASWELL,
#endif
#if BUILD_SINGLE == 1
  sger_k_HASWELL,
#endif
#if BUILD_SINGLE == 1  
  ssymv_L_HASWELL, ssymv_U_HASWELL,
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX==1)
#ifdef ARCH_X86_64
  sgemm_direct_HASWELL,
  sgemm_direct_performant_HASWELL,	
#endif

  sgemm_kernel_HASWELL, sgemm_beta_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  sgemm_incopy_HASWELL, sgemm_itcopy_HASWELL,
#else
  sgemm_oncopy_HASWELL, sgemm_otcopy_HASWELL,
#endif
  sgemm_oncopy_HASWELL, sgemm_otcopy_HASWELL,
#endif

#if BUILD_SINGLE == 1 || BUILD_DOUBLE == 1 || BUILD_COMPLEX == 1
#ifdef SMALL_MATRIX_OPT
  sgemm_small_matrix_permit_HASWELL,
  sgemm_small_kernel_nn_HASWELL, sgemm_small_kernel_nt_HASWELL, sgemm_small_kernel_tn_HASWELL, sgemm_small_kernel_tt_HASWELL,
  sgemm_small_kernel_b0_nn_HASWELL, sgemm_small_kernel_b0_nt_HASWELL, sgemm_small_kernel_b0_tn_HASWELL, sgemm_small_kernel_b0_tt_HASWELL,
#endif
#endif

#if (BUILD_SINGLE==1) || (BUILD_DOUBLE==1) || (BUILD_COMPLEX == 1)
  strsm_kernel_LN_HASWELL, strsm_kernel_LT_HASWELL, strsm_kernel_RN_HASWELL, strsm_kernel_RT_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strsm_iunucopy_HASWELL, strsm_iunncopy_HASWELL, strsm_iutucopy_HASWELL, strsm_iutncopy_HASWELL,
  strsm_ilnucopy_HASWELL, strsm_ilnncopy_HASWELL, strsm_iltucopy_HASWELL, strsm_iltncopy_HASWELL,
#else
  strsm_ounucopy_HASWELL, strsm_ounncopy_HASWELL, strsm_outucopy_HASWELL, strsm_outncopy_HASWELL,
  strsm_olnucopy_HASWELL, strsm_olnncopy_HASWELL, strsm_oltucopy_HASWELL, strsm_oltncopy_HASWELL,
#endif
  strsm_ounucopy_HASWELL, strsm_ounncopy_HASWELL, strsm_outucopy_HASWELL, strsm_outncopy_HASWELL,
  strsm_olnucopy_HASWELL, strsm_olnncopy_HASWELL, strsm_oltucopy_HASWELL, strsm_oltncopy_HASWELL,
#endif
#if (BUILD_SINGLE==1)
  strmm_kernel_RN_HASWELL, strmm_kernel_RT_HASWELL, strmm_kernel_LN_HASWELL, strmm_kernel_LT_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  strmm_iunucopy_HASWELL, strmm_iunncopy_HASWELL, strmm_iutucopy_HASWELL, strmm_iutncopy_HASWELL,
  strmm_ilnucopy_HASWELL, strmm_ilnncopy_HASWELL, strmm_iltucopy_HASWELL, strmm_iltncopy_HASWELL,
#else
  strmm_ounucopy_HASWELL, strmm_ounncopy_HASWELL, strmm_outucopy_HASWELL, strmm_outncopy_HASWELL,
  strmm_olnucopy_HASWELL, strmm_olnncopy_HASWELL, strmm_oltucopy_HASWELL, strmm_oltncopy_HASWELL,
#endif
  strmm_ounucopy_HASWELL, strmm_ounncopy_HASWELL, strmm_outucopy_HASWELL, strmm_outncopy_HASWELL,
  strmm_olnucopy_HASWELL, strmm_olnncopy_HASWELL, strmm_oltucopy_HASWELL, strmm_oltncopy_HASWELL,
#if SGEMM_DEFAULT_UNROLL_M != SGEMM_DEFAULT_UNROLL_N
  ssymm_iutcopy_HASWELL, ssymm_iltcopy_HASWELL,
#else
  ssymm_outcopy_HASWELL, ssymm_oltcopy_HASWELL,
#endif
  ssymm_outcopy_HASWELL, ssymm_oltcopy_HASWELL,
#ifndef NO_LAPACK
  sneg_tcopy_HASWELL, slaswp_ncopy_HASWELL,
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
  damax_k_HASWELL,  damin_k_HASWELL,  dmax_k_HASWELL,  dmin_k_HASWELL,
  idamax_k_HASWELL, idamin_k_HASWELL, idmax_k_HASWELL, idmin_k_HASWELL,
  dnrm2_k_HASWELL, dasum_k_HASWELL,
#endif  
#if  (BUILD_DOUBLE==1)  
  dsum_k_HASWELL,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dcopy_k_HASWELL, ddot_k_HASWELL,
#endif
#if  (BUILD_SINGLE==1) || (BUILD_DOUBLE==1)  
  dsdot_k_HASWELL,
#endif
#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  drot_k_HASWELL,
  daxpy_k_HASWELL,
  dscal_k_HASWELL, 
  dswap_k_HASWELL,
  dgemv_n_HASWELL,  dgemv_t_HASWELL,
#endif
#if  (BUILD_DOUBLE==1)  
  dger_k_HASWELL,
  dsymv_L_HASWELL,  dsymv_U_HASWELL,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
  dgemm_kernel_HASWELL, dgemm_beta_HASWELL,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dgemm_incopy_HASWELL, dgemm_itcopy_HASWELL,
#else
  dgemm_oncopy_HASWELL, dgemm_otcopy_HASWELL,
#endif
  dgemm_oncopy_HASWELL, dgemm_otcopy_HASWELL,
#endif

#if  (BUILD_DOUBLE==1) || (BUILD_COMPLEX16==1)  
#ifdef SMALL_MATRIX_OPT
  dgemm_small_matrix_permit_HASWELL,
  dgemm_small_kernel_nn_HASWELL, dgemm_small_kernel_nt_HASWELL, dgemm_small_kernel_tn_HASWELL, dgemm_small_kernel_tt_HASWELL,
  dgemm_small_kernel_b0_nn_HASWELL, dgemm_small_kernel_b0_nt_HASWELL, dgemm_small_kernel_b0_tn_HASWELL, dgemm_small_kernel_b0_tt_HASWELL,
#endif
#endif
#if  (BUILD_DOUBLE==1)   
  dtrsm_kernel_LN_HASWELL, dtrsm_kernel_LT_HASWELL, dtrsm_kernel_RN_HASWELL, dtrsm_kernel_RT_HASWELL,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrsm_iunucopy_HASWELL, dtrsm_iunncopy_HASWELL, dtrsm_iutucopy_HASWELL, dtrsm_iutncopy_HASWELL,
  dtrsm_ilnucopy_HASWELL, dtrsm_ilnncopy_HASWELL, dtrsm_iltucopy_HASWELL, dtrsm_iltncopy_HASWELL,
#else
  dtrsm_ounucopy_HASWELL, dtrsm_ounncopy_HASWELL, dtrsm_outucopy_HASWELL, dtrsm_outncopy_HASWELL,
  dtrsm_olnucopy_HASWELL, dtrsm_olnncopy_HASWELL, dtrsm_oltucopy_HASWELL, dtrsm_oltncopy_HASWELL,
#endif
  dtrsm_ounucopy_HASWELL, dtrsm_ounncopy_HASWELL, dtrsm_outucopy_HASWELL, dtrsm_outncopy_HASWELL,
  dtrsm_olnucopy_HASWELL, dtrsm_olnncopy_HASWELL, dtrsm_oltucopy_HASWELL, dtrsm_oltncopy_HASWELL,
  dtrmm_kernel_RN_HASWELL, dtrmm_kernel_RT_HASWELL, dtrmm_kernel_LN_HASWELL, dtrmm_kernel_LT_HASWELL,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dtrmm_iunucopy_HASWELL, dtrmm_iunncopy_HASWELL, dtrmm_iutucopy_HASWELL, dtrmm_iutncopy_HASWELL,
  dtrmm_ilnucopy_HASWELL, dtrmm_ilnncopy_HASWELL, dtrmm_iltucopy_HASWELL, dtrmm_iltncopy_HASWELL,
#else
  dtrmm_ounucopy_HASWELL, dtrmm_ounncopy_HASWELL, dtrmm_outucopy_HASWELL, dtrmm_outncopy_HASWELL,
  dtrmm_olnucopy_HASWELL, dtrmm_olnncopy_HASWELL, dtrmm_oltucopy_HASWELL, dtrmm_oltncopy_HASWELL,
#endif
  dtrmm_ounucopy_HASWELL, dtrmm_ounncopy_HASWELL, dtrmm_outucopy_HASWELL, dtrmm_outncopy_HASWELL,
  dtrmm_olnucopy_HASWELL, dtrmm_olnncopy_HASWELL, dtrmm_oltucopy_HASWELL, dtrmm_oltncopy_HASWELL,
#if DGEMM_DEFAULT_UNROLL_M != DGEMM_DEFAULT_UNROLL_N
  dsymm_iutcopy_HASWELL, dsymm_iltcopy_HASWELL,
#else
  dsymm_outcopy_HASWELL, dsymm_oltcopy_HASWELL,
#endif
  dsymm_outcopy_HASWELL, dsymm_oltcopy_HASWELL,

#ifndef NO_LAPACK
  dneg_tcopy_HASWELL, dlaswp_ncopy_HASWELL,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  qamax_k_HASWELL,  qamin_k_HASWELL,  qmax_k_HASWELL,  qmin_k_HASWELL,
  iqamax_k_HASWELL, iqamin_k_HASWELL, iqmax_k_HASWELL, iqmin_k_HASWELL,
  qnrm2_k_HASWELL,  qasum_k_HASWELL,  qsum_k_HASWELL, qcopy_k_HASWELL, qdot_k_HASWELL,
  qrot_k_HASWELL,   qaxpy_k_HASWELL,  qscal_k_HASWELL, qswap_k_HASWELL,
  qgemv_n_HASWELL,  qgemv_t_HASWELL,  qger_k_HASWELL,
  qsymv_L_HASWELL,  qsymv_U_HASWELL,

  qgemm_kernel_HASWELL, qgemm_beta_HASWELL,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qgemm_incopy_HASWELL, qgemm_itcopy_HASWELL,
#else
  qgemm_oncopy_HASWELL, qgemm_otcopy_HASWELL,
#endif
  qgemm_oncopy_HASWELL, qgemm_otcopy_HASWELL,
  qtrsm_kernel_LN_HASWELL, qtrsm_kernel_LT_HASWELL, qtrsm_kernel_RN_HASWELL, qtrsm_kernel_RT_HASWELL,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrsm_iunucopy_HASWELL, qtrsm_iunncopy_HASWELL, qtrsm_iutucopy_HASWELL, qtrsm_iutncopy_HASWELL,
  qtrsm_ilnucopy_HASWELL, qtrsm_ilnncopy_HASWELL, qtrsm_iltucopy_HASWELL, qtrsm_iltncopy_HASWELL,
#else
  qtrsm_ounucopy_HASWELL, qtrsm_ounncopy_HASWELL, qtrsm_outucopy_HASWELL, qtrsm_outncopy_HASWELL,
  qtrsm_olnucopy_HASWELL, qtrsm_olnncopy_HASWELL, qtrsm_oltucopy_HASWELL, qtrsm_oltncopy_HASWELL,
#endif
  qtrsm_ounucopy_HASWELL, qtrsm_ounncopy_HASWELL, qtrsm_outucopy_HASWELL, qtrsm_outncopy_HASWELL,
  qtrsm_olnucopy_HASWELL, qtrsm_olnncopy_HASWELL, qtrsm_oltucopy_HASWELL, qtrsm_oltncopy_HASWELL,
  qtrmm_kernel_RN_HASWELL, qtrmm_kernel_RT_HASWELL, qtrmm_kernel_LN_HASWELL, qtrmm_kernel_LT_HASWELL,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qtrmm_iunucopy_HASWELL, qtrmm_iunncopy_HASWELL, qtrmm_iutucopy_HASWELL, qtrmm_iutncopy_HASWELL,
  qtrmm_ilnucopy_HASWELL, qtrmm_ilnncopy_HASWELL, qtrmm_iltucopy_HASWELL, qtrmm_iltncopy_HASWELL,
#else
  qtrmm_ounucopy_HASWELL, qtrmm_ounncopy_HASWELL, qtrmm_outucopy_HASWELL, qtrmm_outncopy_HASWELL,
  qtrmm_olnucopy_HASWELL, qtrmm_olnncopy_HASWELL, qtrmm_oltucopy_HASWELL, qtrmm_oltncopy_HASWELL,
#endif
  qtrmm_ounucopy_HASWELL, qtrmm_ounncopy_HASWELL, qtrmm_outucopy_HASWELL, qtrmm_outncopy_HASWELL,
  qtrmm_olnucopy_HASWELL, qtrmm_olnncopy_HASWELL, qtrmm_oltucopy_HASWELL, qtrmm_oltncopy_HASWELL,
#if QGEMM_DEFAULT_UNROLL_M != QGEMM_DEFAULT_UNROLL_N
  qsymm_iutcopy_HASWELL, qsymm_iltcopy_HASWELL,
#else
  qsymm_outcopy_HASWELL, qsymm_oltcopy_HASWELL,
#endif
  qsymm_outcopy_HASWELL, qsymm_oltcopy_HASWELL,

#ifndef NO_LAPACK
  qneg_tcopy_HASWELL, qlaswp_ncopy_HASWELL,
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
  camax_k_HASWELL, camin_k_HASWELL,
#endif
#if (BUILD_COMPLEX)
  icamax_k_HASWELL, 
#endif
#if (BUILD_COMPLEX)
  icamin_k_HASWELL,
  cnrm2_k_HASWELL, casum_k_HASWELL, csum_k_HASWELL,
#endif
#if (BUILD_COMPLEX)
  ccopy_k_HASWELL, cdotu_k_HASWELL, cdotc_k_HASWELL,
#endif
#if (BUILD_COMPLEX)
 csrot_k_HASWELL,
#endif
#if (BUILD_COMPLEX)
  caxpy_k_HASWELL,
  caxpyc_k_HASWELL, 
  cscal_k_HASWELL, 
  cswap_k_HASWELL,

  cgemv_n_HASWELL, cgemv_t_HASWELL, cgemv_r_HASWELL, cgemv_c_HASWELL,
  cgemv_o_HASWELL, cgemv_u_HASWELL, cgemv_s_HASWELL, cgemv_d_HASWELL,
#endif
#if (BUILD_COMPLEX)
  cgeru_k_HASWELL, cgerc_k_HASWELL, cgerv_k_HASWELL, cgerd_k_HASWELL,
  csymv_L_HASWELL, csymv_U_HASWELL,
  chemv_L_HASWELL, chemv_U_HASWELL, chemv_M_HASWELL, chemv_V_HASWELL,
#endif
#if (BUILD_COMPLEX)
  cgemm_kernel_n_HASWELL, cgemm_kernel_l_HASWELL, cgemm_kernel_r_HASWELL, cgemm_kernel_b_HASWELL,
  cgemm_beta_HASWELL,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  cgemm_incopy_HASWELL, cgemm_itcopy_HASWELL,
#else
  cgemm_oncopy_HASWELL, cgemm_otcopy_HASWELL,
#endif
  cgemm_oncopy_HASWELL, cgemm_otcopy_HASWELL,

#ifdef SMALL_MATRIX_OPT
  cgemm_small_matrix_permit_HASWELL,
  cgemm_small_kernel_nn_HASWELL, cgemm_small_kernel_nt_HASWELL, cgemm_small_kernel_nr_HASWELL, cgemm_small_kernel_nc_HASWELL,
  cgemm_small_kernel_tn_HASWELL, cgemm_small_kernel_tt_HASWELL, cgemm_small_kernel_tr_HASWELL, cgemm_small_kernel_tc_HASWELL,
  cgemm_small_kernel_rn_HASWELL, cgemm_small_kernel_rt_HASWELL, cgemm_small_kernel_rr_HASWELL, cgemm_small_kernel_rc_HASWELL,
  cgemm_small_kernel_cn_HASWELL, cgemm_small_kernel_ct_HASWELL, cgemm_small_kernel_cr_HASWELL, cgemm_small_kernel_cc_HASWELL,
  cgemm_small_kernel_b0_nn_HASWELL, cgemm_small_kernel_b0_nt_HASWELL, cgemm_small_kernel_b0_nr_HASWELL, cgemm_small_kernel_b0_nc_HASWELL,
  cgemm_small_kernel_b0_tn_HASWELL, cgemm_small_kernel_b0_tt_HASWELL, cgemm_small_kernel_b0_tr_HASWELL, cgemm_small_kernel_b0_tc_HASWELL,
  cgemm_small_kernel_b0_rn_HASWELL, cgemm_small_kernel_b0_rt_HASWELL, cgemm_small_kernel_b0_rr_HASWELL, cgemm_small_kernel_b0_rc_HASWELL,
  cgemm_small_kernel_b0_cn_HASWELL, cgemm_small_kernel_b0_ct_HASWELL, cgemm_small_kernel_b0_cr_HASWELL, cgemm_small_kernel_b0_cc_HASWELL,
#endif

  ctrsm_kernel_LN_HASWELL, ctrsm_kernel_LT_HASWELL, ctrsm_kernel_LR_HASWELL, ctrsm_kernel_LC_HASWELL,
  ctrsm_kernel_RN_HASWELL, ctrsm_kernel_RT_HASWELL, ctrsm_kernel_RR_HASWELL, ctrsm_kernel_RC_HASWELL,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrsm_iunucopy_HASWELL,  ctrsm_iunncopy_HASWELL,  ctrsm_iutucopy_HASWELL,  ctrsm_iutncopy_HASWELL,
  ctrsm_ilnucopy_HASWELL,  ctrsm_ilnncopy_HASWELL,  ctrsm_iltucopy_HASWELL,  ctrsm_iltncopy_HASWELL,
#else
  ctrsm_ounucopy_HASWELL,  ctrsm_ounncopy_HASWELL,  ctrsm_outucopy_HASWELL,  ctrsm_outncopy_HASWELL,
  ctrsm_olnucopy_HASWELL,  ctrsm_olnncopy_HASWELL,  ctrsm_oltucopy_HASWELL,  ctrsm_oltncopy_HASWELL,
#endif
  ctrsm_ounucopy_HASWELL,  ctrsm_ounncopy_HASWELL,  ctrsm_outucopy_HASWELL,  ctrsm_outncopy_HASWELL,
  ctrsm_olnucopy_HASWELL,  ctrsm_olnncopy_HASWELL,  ctrsm_oltucopy_HASWELL,  ctrsm_oltncopy_HASWELL,
#endif
#endif
#if (BUILD_COMPLEX)

  ctrmm_kernel_RN_HASWELL,  ctrmm_kernel_RT_HASWELL,  ctrmm_kernel_RR_HASWELL,  ctrmm_kernel_RC_HASWELL,
  ctrmm_kernel_LN_HASWELL,  ctrmm_kernel_LT_HASWELL,  ctrmm_kernel_LR_HASWELL,  ctrmm_kernel_LC_HASWELL,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  ctrmm_iunucopy_HASWELL,  ctrmm_iunncopy_HASWELL,  ctrmm_iutucopy_HASWELL,  ctrmm_iutncopy_HASWELL,
  ctrmm_ilnucopy_HASWELL,  ctrmm_ilnncopy_HASWELL,  ctrmm_iltucopy_HASWELL,  ctrmm_iltncopy_HASWELL,
#else
  ctrmm_ounucopy_HASWELL,  ctrmm_ounncopy_HASWELL,  ctrmm_outucopy_HASWELL,  ctrmm_outncopy_HASWELL,
  ctrmm_olnucopy_HASWELL,  ctrmm_olnncopy_HASWELL,  ctrmm_oltucopy_HASWELL,  ctrmm_oltncopy_HASWELL,
#endif
  ctrmm_ounucopy_HASWELL,  ctrmm_ounncopy_HASWELL,  ctrmm_outucopy_HASWELL,  ctrmm_outncopy_HASWELL,
  ctrmm_olnucopy_HASWELL,  ctrmm_olnncopy_HASWELL,  ctrmm_oltucopy_HASWELL,  ctrmm_oltncopy_HASWELL,

#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  csymm_iutcopy_HASWELL,  csymm_iltcopy_HASWELL,
#else
  csymm_outcopy_HASWELL,  csymm_oltcopy_HASWELL,
#endif
  csymm_outcopy_HASWELL,  csymm_oltcopy_HASWELL,
#if CGEMM_DEFAULT_UNROLL_M != CGEMM_DEFAULT_UNROLL_N
  chemm_iutcopy_HASWELL,  chemm_iltcopy_HASWELL,
#else
  chemm_outcopy_HASWELL,  chemm_oltcopy_HASWELL,
#endif
  chemm_outcopy_HASWELL,  chemm_oltcopy_HASWELL,

  0, 0, 0,

#if (USE_GEMM3M)
#ifdef CGEMM3M_DEFAULT_UNROLL_M
  CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N, MAX(CGEMM3M_DEFAULT_UNROLL_M, CGEMM3M_DEFAULT_UNROLL_N),
#else
  SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N, MAX(SGEMM_DEFAULT_UNROLL_M, SGEMM_DEFAULT_UNROLL_N),
#endif


  cgemm3m_kernel_HASWELL,

  cgemm3m_incopyb_HASWELL,  cgemm3m_incopyr_HASWELL,
  cgemm3m_incopyi_HASWELL,  cgemm3m_itcopyb_HASWELL,
  cgemm3m_itcopyr_HASWELL,  cgemm3m_itcopyi_HASWELL,
  cgemm3m_oncopyb_HASWELL,  cgemm3m_oncopyr_HASWELL,
  cgemm3m_oncopyi_HASWELL,  cgemm3m_otcopyb_HASWELL,
  cgemm3m_otcopyr_HASWELL,  cgemm3m_otcopyi_HASWELL,

  csymm3m_iucopyb_HASWELL,  csymm3m_ilcopyb_HASWELL,
  csymm3m_iucopyr_HASWELL,  csymm3m_ilcopyr_HASWELL,
  csymm3m_iucopyi_HASWELL,  csymm3m_ilcopyi_HASWELL,
  csymm3m_oucopyb_HASWELL,  csymm3m_olcopyb_HASWELL,
  csymm3m_oucopyr_HASWELL,  csymm3m_olcopyr_HASWELL,
  csymm3m_oucopyi_HASWELL,  csymm3m_olcopyi_HASWELL,

  chemm3m_iucopyb_HASWELL,  chemm3m_ilcopyb_HASWELL,
  chemm3m_iucopyr_HASWELL,  chemm3m_ilcopyr_HASWELL,
  chemm3m_iucopyi_HASWELL,  chemm3m_ilcopyi_HASWELL,

  chemm3m_oucopyb_HASWELL,  chemm3m_olcopyb_HASWELL,
  chemm3m_oucopyr_HASWELL,  chemm3m_olcopyr_HASWELL,
  chemm3m_oucopyi_HASWELL,  chemm3m_olcopyi_HASWELL,
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
  cneg_tcopy_HASWELL,
  
   claswp_ncopy_HASWELL,
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

  zamax_k_HASWELL, zamin_k_HASWELL, izamax_k_HASWELL, izamin_k_HASWELL,
  znrm2_k_HASWELL, zasum_k_HASWELL, zsum_k_HASWELL, zcopy_k_HASWELL,
  zdotu_k_HASWELL, zdotc_k_HASWELL, zdrot_k_HASWELL,
  zaxpy_k_HASWELL, zaxpyc_k_HASWELL, zscal_k_HASWELL, zswap_k_HASWELL,

  zgemv_n_HASWELL, zgemv_t_HASWELL, zgemv_r_HASWELL, zgemv_c_HASWELL,
  zgemv_o_HASWELL, zgemv_u_HASWELL, zgemv_s_HASWELL, zgemv_d_HASWELL,
  zgeru_k_HASWELL, zgerc_k_HASWELL, zgerv_k_HASWELL, zgerd_k_HASWELL,
  zsymv_L_HASWELL, zsymv_U_HASWELL,
  zhemv_L_HASWELL, zhemv_U_HASWELL, zhemv_M_HASWELL, zhemv_V_HASWELL,

  zgemm_kernel_n_HASWELL, zgemm_kernel_l_HASWELL, zgemm_kernel_r_HASWELL, zgemm_kernel_b_HASWELL,
  zgemm_beta_HASWELL,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zgemm_incopy_HASWELL, zgemm_itcopy_HASWELL,
#else
  zgemm_oncopy_HASWELL, zgemm_otcopy_HASWELL,
#endif
  zgemm_oncopy_HASWELL, zgemm_otcopy_HASWELL,

#ifdef SMALL_MATRIX_OPT
  zgemm_small_matrix_permit_HASWELL,
  zgemm_small_kernel_nn_HASWELL, zgemm_small_kernel_nt_HASWELL, zgemm_small_kernel_nr_HASWELL, zgemm_small_kernel_nc_HASWELL,
  zgemm_small_kernel_tn_HASWELL, zgemm_small_kernel_tt_HASWELL, zgemm_small_kernel_tr_HASWELL, zgemm_small_kernel_tc_HASWELL,
  zgemm_small_kernel_rn_HASWELL, zgemm_small_kernel_rt_HASWELL, zgemm_small_kernel_rr_HASWELL, zgemm_small_kernel_rc_HASWELL,
  zgemm_small_kernel_cn_HASWELL, zgemm_small_kernel_ct_HASWELL, zgemm_small_kernel_cr_HASWELL, zgemm_small_kernel_cc_HASWELL,
  zgemm_small_kernel_b0_nn_HASWELL, zgemm_small_kernel_b0_nt_HASWELL, zgemm_small_kernel_b0_nr_HASWELL, zgemm_small_kernel_b0_nc_HASWELL,
  zgemm_small_kernel_b0_tn_HASWELL, zgemm_small_kernel_b0_tt_HASWELL, zgemm_small_kernel_b0_tr_HASWELL, zgemm_small_kernel_b0_tc_HASWELL,
  zgemm_small_kernel_b0_rn_HASWELL, zgemm_small_kernel_b0_rt_HASWELL, zgemm_small_kernel_b0_rr_HASWELL, zgemm_small_kernel_b0_rc_HASWELL,
  zgemm_small_kernel_b0_cn_HASWELL, zgemm_small_kernel_b0_ct_HASWELL, zgemm_small_kernel_b0_cr_HASWELL, zgemm_small_kernel_b0_cc_HASWELL,
#endif

  ztrsm_kernel_LN_HASWELL, ztrsm_kernel_LT_HASWELL, ztrsm_kernel_LR_HASWELL, ztrsm_kernel_LC_HASWELL,
  ztrsm_kernel_RN_HASWELL, ztrsm_kernel_RT_HASWELL, ztrsm_kernel_RR_HASWELL, ztrsm_kernel_RC_HASWELL,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrsm_iunucopy_HASWELL,  ztrsm_iunncopy_HASWELL,  ztrsm_iutucopy_HASWELL,  ztrsm_iutncopy_HASWELL,
  ztrsm_ilnucopy_HASWELL,  ztrsm_ilnncopy_HASWELL,  ztrsm_iltucopy_HASWELL,  ztrsm_iltncopy_HASWELL,
#else
  ztrsm_ounucopy_HASWELL,  ztrsm_ounncopy_HASWELL,  ztrsm_outucopy_HASWELL,  ztrsm_outncopy_HASWELL,
  ztrsm_olnucopy_HASWELL,  ztrsm_olnncopy_HASWELL,  ztrsm_oltucopy_HASWELL,  ztrsm_oltncopy_HASWELL,
#endif
  ztrsm_ounucopy_HASWELL,  ztrsm_ounncopy_HASWELL,  ztrsm_outucopy_HASWELL,  ztrsm_outncopy_HASWELL,
  ztrsm_olnucopy_HASWELL,  ztrsm_olnncopy_HASWELL,  ztrsm_oltucopy_HASWELL,  ztrsm_oltncopy_HASWELL,

  ztrmm_kernel_RN_HASWELL,  ztrmm_kernel_RT_HASWELL,  ztrmm_kernel_RR_HASWELL,  ztrmm_kernel_RC_HASWELL,
  ztrmm_kernel_LN_HASWELL,  ztrmm_kernel_LT_HASWELL,  ztrmm_kernel_LR_HASWELL,  ztrmm_kernel_LC_HASWELL,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  ztrmm_iunucopy_HASWELL,  ztrmm_iunncopy_HASWELL,  ztrmm_iutucopy_HASWELL,  ztrmm_iutncopy_HASWELL,
  ztrmm_ilnucopy_HASWELL,  ztrmm_ilnncopy_HASWELL,  ztrmm_iltucopy_HASWELL,  ztrmm_iltncopy_HASWELL,
#else
  ztrmm_ounucopy_HASWELL,  ztrmm_ounncopy_HASWELL,  ztrmm_outucopy_HASWELL,  ztrmm_outncopy_HASWELL,
  ztrmm_olnucopy_HASWELL,  ztrmm_olnncopy_HASWELL,  ztrmm_oltucopy_HASWELL,  ztrmm_oltncopy_HASWELL,
#endif
  ztrmm_ounucopy_HASWELL,  ztrmm_ounncopy_HASWELL,  ztrmm_outucopy_HASWELL,  ztrmm_outncopy_HASWELL,
  ztrmm_olnucopy_HASWELL,  ztrmm_olnncopy_HASWELL,  ztrmm_oltucopy_HASWELL,  ztrmm_oltncopy_HASWELL,

#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zsymm_iutcopy_HASWELL,  zsymm_iltcopy_HASWELL,
#else
  zsymm_outcopy_HASWELL,  zsymm_oltcopy_HASWELL,
#endif
  zsymm_outcopy_HASWELL,  zsymm_oltcopy_HASWELL,
#if ZGEMM_DEFAULT_UNROLL_M != ZGEMM_DEFAULT_UNROLL_N
  zhemm_iutcopy_HASWELL,  zhemm_iltcopy_HASWELL,
#else
  zhemm_outcopy_HASWELL,  zhemm_oltcopy_HASWELL,
#endif
  zhemm_outcopy_HASWELL,  zhemm_oltcopy_HASWELL,

  0, 0, 0,
#if (USE_GEMM3M)
#ifdef ZGEMM3M_DEFAULT_UNROLL_M
  ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N, MAX(ZGEMM3M_DEFAULT_UNROLL_M, ZGEMM3M_DEFAULT_UNROLL_N),
#else
  DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N, MAX(DGEMM_DEFAULT_UNROLL_M, DGEMM_DEFAULT_UNROLL_N),
#endif


  zgemm3m_kernel_HASWELL,

  zgemm3m_incopyb_HASWELL,  zgemm3m_incopyr_HASWELL,
  zgemm3m_incopyi_HASWELL,  zgemm3m_itcopyb_HASWELL,
  zgemm3m_itcopyr_HASWELL,  zgemm3m_itcopyi_HASWELL,
  zgemm3m_oncopyb_HASWELL,  zgemm3m_oncopyr_HASWELL,
  zgemm3m_oncopyi_HASWELL,  zgemm3m_otcopyb_HASWELL,
  zgemm3m_otcopyr_HASWELL,  zgemm3m_otcopyi_HASWELL,

  zsymm3m_iucopyb_HASWELL,  zsymm3m_ilcopyb_HASWELL,
  zsymm3m_iucopyr_HASWELL,  zsymm3m_ilcopyr_HASWELL,
  zsymm3m_iucopyi_HASWELL,  zsymm3m_ilcopyi_HASWELL,
  zsymm3m_oucopyb_HASWELL,  zsymm3m_olcopyb_HASWELL,
  zsymm3m_oucopyr_HASWELL,  zsymm3m_olcopyr_HASWELL,
  zsymm3m_oucopyi_HASWELL,  zsymm3m_olcopyi_HASWELL,

  zhemm3m_iucopyb_HASWELL,  zhemm3m_ilcopyb_HASWELL,
  zhemm3m_iucopyr_HASWELL,  zhemm3m_ilcopyr_HASWELL,
  zhemm3m_iucopyi_HASWELL,  zhemm3m_ilcopyi_HASWELL,

  zhemm3m_oucopyb_HASWELL,  zhemm3m_olcopyb_HASWELL,
  zhemm3m_oucopyr_HASWELL,  zhemm3m_olcopyr_HASWELL,
  zhemm3m_oucopyi_HASWELL,  zhemm3m_olcopyi_HASWELL,
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
  zneg_tcopy_HASWELL, zlaswp_ncopy_HASWELL,
#else
  NULL, NULL,
#endif

#endif

#ifdef EXPRECISION

  0, 0, 0,
  XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N, MAX(XGEMM_DEFAULT_UNROLL_M, XGEMM_DEFAULT_UNROLL_N),

  xamax_k_HASWELL, xamin_k_HASWELL, ixamax_k_HASWELL, ixamin_k_HASWELL,
  xnrm2_k_HASWELL, xasum_k_HASWELL, xsum_k_HASWELL, xcopy_k_HASWELL,
  xdotu_k_HASWELL, xdotc_k_HASWELL, xqrot_k_HASWELL,
  xaxpy_k_HASWELL, xaxpyc_k_HASWELL, xscal_k_HASWELL, xswap_k_HASWELL,

  xgemv_n_HASWELL, xgemv_t_HASWELL, xgemv_r_HASWELL, xgemv_c_HASWELL,
  xgemv_o_HASWELL, xgemv_u_HASWELL, xgemv_s_HASWELL, xgemv_d_HASWELL,
  xgeru_k_HASWELL, xgerc_k_HASWELL, xgerv_k_HASWELL, xgerd_k_HASWELL,
  xsymv_L_HASWELL, xsymv_U_HASWELL,
  xhemv_L_HASWELL, xhemv_U_HASWELL, xhemv_M_HASWELL, xhemv_V_HASWELL,

  xgemm_kernel_n_HASWELL, xgemm_kernel_l_HASWELL, xgemm_kernel_r_HASWELL, xgemm_kernel_b_HASWELL,
  xgemm_beta_HASWELL,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xgemm_incopy_HASWELL, xgemm_itcopy_HASWELL,
#else
  xgemm_oncopy_HASWELL, xgemm_otcopy_HASWELL,
#endif
  xgemm_oncopy_HASWELL, xgemm_otcopy_HASWELL,

  xtrsm_kernel_LN_HASWELL, xtrsm_kernel_LT_HASWELL, xtrsm_kernel_LR_HASWELL, xtrsm_kernel_LC_HASWELL,
  xtrsm_kernel_RN_HASWELL, xtrsm_kernel_RT_HASWELL, xtrsm_kernel_RR_HASWELL, xtrsm_kernel_RC_HASWELL,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrsm_iunucopy_HASWELL,  xtrsm_iunncopy_HASWELL,  xtrsm_iutucopy_HASWELL,  xtrsm_iutncopy_HASWELL,
  xtrsm_ilnucopy_HASWELL,  xtrsm_ilnncopy_HASWELL,  xtrsm_iltucopy_HASWELL,  xtrsm_iltncopy_HASWELL,
#else
  xtrsm_ounucopy_HASWELL,  xtrsm_ounncopy_HASWELL,  xtrsm_outucopy_HASWELL,  xtrsm_outncopy_HASWELL,
  xtrsm_olnucopy_HASWELL,  xtrsm_olnncopy_HASWELL,  xtrsm_oltucopy_HASWELL,  xtrsm_oltncopy_HASWELL,
#endif
  xtrsm_ounucopy_HASWELL,  xtrsm_ounncopy_HASWELL,  xtrsm_outucopy_HASWELL,  xtrsm_outncopy_HASWELL,
  xtrsm_olnucopy_HASWELL,  xtrsm_olnncopy_HASWELL,  xtrsm_oltucopy_HASWELL,  xtrsm_oltncopy_HASWELL,

  xtrmm_kernel_RN_HASWELL,  xtrmm_kernel_RT_HASWELL,  xtrmm_kernel_RR_HASWELL,  xtrmm_kernel_RC_HASWELL,
  xtrmm_kernel_LN_HASWELL,  xtrmm_kernel_LT_HASWELL,  xtrmm_kernel_LR_HASWELL,  xtrmm_kernel_LC_HASWELL,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xtrmm_iunucopy_HASWELL,  xtrmm_iunncopy_HASWELL,  xtrmm_iutucopy_HASWELL,  xtrmm_iutncopy_HASWELL,
  xtrmm_ilnucopy_HASWELL,  xtrmm_ilnncopy_HASWELL,  xtrmm_iltucopy_HASWELL,  xtrmm_iltncopy_HASWELL,
#else
  xtrmm_ounucopy_HASWELL,  xtrmm_ounncopy_HASWELL,  xtrmm_outucopy_HASWELL,  xtrmm_outncopy_HASWELL,
  xtrmm_olnucopy_HASWELL,  xtrmm_olnncopy_HASWELL,  xtrmm_oltucopy_HASWELL,  xtrmm_oltncopy_HASWELL,
#endif
  xtrmm_ounucopy_HASWELL,  xtrmm_ounncopy_HASWELL,  xtrmm_outucopy_HASWELL,  xtrmm_outncopy_HASWELL,
  xtrmm_olnucopy_HASWELL,  xtrmm_olnncopy_HASWELL,  xtrmm_oltucopy_HASWELL,  xtrmm_oltncopy_HASWELL,

#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xsymm_iutcopy_HASWELL,  xsymm_iltcopy_HASWELL,
#else
  xsymm_outcopy_HASWELL,  xsymm_oltcopy_HASWELL,
#endif
  xsymm_outcopy_HASWELL,  xsymm_oltcopy_HASWELL,
#if XGEMM_DEFAULT_UNROLL_M != XGEMM_DEFAULT_UNROLL_N
  xhemm_iutcopy_HASWELL,  xhemm_iltcopy_HASWELL,
#else
  xhemm_outcopy_HASWELL,  xhemm_oltcopy_HASWELL,
#endif
  xhemm_outcopy_HASWELL,  xhemm_oltcopy_HASWELL,

  0, 0, 0,
#if (USE_GEMM3M)
  QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N, MAX(QGEMM_DEFAULT_UNROLL_M, QGEMM_DEFAULT_UNROLL_N),

  xgemm3m_kernel_HASWELL,

  xgemm3m_incopyb_HASWELL,  xgemm3m_incopyr_HASWELL,
  xgemm3m_incopyi_HASWELL,  xgemm3m_itcopyb_HASWELL,
  xgemm3m_itcopyr_HASWELL,  xgemm3m_itcopyi_HASWELL,
  xgemm3m_oncopyb_HASWELL,  xgemm3m_oncopyr_HASWELL,
  xgemm3m_oncopyi_HASWELL,  xgemm3m_otcopyb_HASWELL,
  xgemm3m_otcopyr_HASWELL,  xgemm3m_otcopyi_HASWELL,

  xsymm3m_iucopyb_HASWELL,  xsymm3m_ilcopyb_HASWELL,
  xsymm3m_iucopyr_HASWELL,  xsymm3m_ilcopyr_HASWELL,
  xsymm3m_iucopyi_HASWELL,  xsymm3m_ilcopyi_HASWELL,
  xsymm3m_oucopyb_HASWELL,  xsymm3m_olcopyb_HASWELL,
  xsymm3m_oucopyr_HASWELL,  xsymm3m_olcopyr_HASWELL,
  xsymm3m_oucopyi_HASWELL,  xsymm3m_olcopyi_HASWELL,

  xhemm3m_iucopyb_HASWELL,  xhemm3m_ilcopyb_HASWELL,
  xhemm3m_iucopyr_HASWELL,  xhemm3m_ilcopyr_HASWELL,
  xhemm3m_iucopyi_HASWELL,  xhemm3m_ilcopyi_HASWELL,

  xhemm3m_oucopyb_HASWELL,  xhemm3m_olcopyb_HASWELL,
  xhemm3m_oucopyr_HASWELL,  xhemm3m_olcopyr_HASWELL,
  xhemm3m_oucopyi_HASWELL,  xhemm3m_olcopyi_HASWELL,
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
  xneg_tcopy_HASWELL, xlaswp_ncopy_HASWELL,
#else
  NULL, NULL,
#endif

#endif

  init_parameter,

  SNUMOPT, DNUMOPT, QNUMOPT,
#if BUILD_SINGLE == 1
  saxpby_k_HASWELL,
#endif
#if BUILD_DOUBLE  == 1
  daxpby_k_HASWELL,
#endif
#if BUILD_COMPLEX == 1
  caxpby_k_HASWELL,
#endif
#if BUILD_COMPLEX16== 1
  zaxpby_k_HASWELL,
#endif

#if BUILD_SINGLE == 1
  somatcopy_k_cn_HASWELL, somatcopy_k_ct_HASWELL, somatcopy_k_rn_HASWELL, somatcopy_k_rt_HASWELL,
#endif
#if BUILD_DOUBLE== 1
  domatcopy_k_cn_HASWELL, domatcopy_k_ct_HASWELL, domatcopy_k_rn_HASWELL, domatcopy_k_rt_HASWELL,
#endif
#if BUILD_COMPLEX == 1
  comatcopy_k_cn_HASWELL, comatcopy_k_ct_HASWELL, comatcopy_k_rn_HASWELL, comatcopy_k_rt_HASWELL,
  comatcopy_k_cnc_HASWELL, comatcopy_k_ctc_HASWELL, comatcopy_k_rnc_HASWELL, comatcopy_k_rtc_HASWELL,
#endif
#if BUILD_COMPLEX16 == 1
  zomatcopy_k_cn_HASWELL, zomatcopy_k_ct_HASWELL, zomatcopy_k_rn_HASWELL, zomatcopy_k_rt_HASWELL,
  zomatcopy_k_cnc_HASWELL, zomatcopy_k_ctc_HASWELL, zomatcopy_k_rnc_HASWELL, zomatcopy_k_rtc_HASWELL,
#endif

#if BUILD_SINGLE == 1
  simatcopy_k_cn_HASWELL, simatcopy_k_ct_HASWELL, simatcopy_k_rn_HASWELL, simatcopy_k_rt_HASWELL,
#endif
#if BUILD_DOUBLE== 1
  dimatcopy_k_cn_HASWELL, dimatcopy_k_ct_HASWELL, dimatcopy_k_rn_HASWELL, dimatcopy_k_rt_HASWELL,
#endif
#if BUILD_COMPLEX== 1
  cimatcopy_k_cn_HASWELL, cimatcopy_k_ct_HASWELL, cimatcopy_k_rn_HASWELL, cimatcopy_k_rt_HASWELL,
  cimatcopy_k_cnc_HASWELL, cimatcopy_k_ctc_HASWELL, cimatcopy_k_rnc_HASWELL, cimatcopy_k_rtc_HASWELL,
#endif
#if BUILD_COMPLEX16==1
  zimatcopy_k_cn_HASWELL, zimatcopy_k_ct_HASWELL, zimatcopy_k_rn_HASWELL, zimatcopy_k_rt_HASWELL,
  zimatcopy_k_cnc_HASWELL, zimatcopy_k_ctc_HASWELL, zimatcopy_k_rnc_HASWELL, zimatcopy_k_rtc_HASWELL,
#endif

#if BUILD_SINGLE == 1
  sgeadd_k_HASWELL,
#endif
#if BUILD_DOUBLE==1
  dgeadd_k_HASWELL,
#endif
#if BUILD_COMPLEX==1
  cgeadd_k_HASWELL,
#endif
#if BUILD_COMPLEX16==1
  zgeadd_k_HASWELL,
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
