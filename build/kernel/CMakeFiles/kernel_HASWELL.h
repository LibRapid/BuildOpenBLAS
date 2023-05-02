
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
/*_HASWELL(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_HASWELL(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#ifndef ASSEMBLER

#ifdef __CUDACC__
extern "C" {
#endif

float   sdot_k_HASWELL(BLASLONG, float   *, BLASLONG, float   *, BLASLONG);
double dsdot_k_HASWELL(BLASLONG, float   *, BLASLONG, float *, BLASLONG);
double  ddot_k_HASWELL(BLASLONG, double  *, BLASLONG, double  *, BLASLONG);
xdouble qdot_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
float  sbdot_k_HASWELL(BLASLONG, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG);

void   sbstobf16_k_HASWELL(BLASLONG, float    *, BLASLONG, bfloat16 *, BLASLONG);
void   sbdtobf16_k_HASWELL(BLASLONG, double   *, BLASLONG, bfloat16 *, BLASLONG);
void   sbf16tos_k_HASWELL(BLASLONG, bfloat16 *, BLASLONG, float    *, BLASLONG);
void   dbf16tod_k_HASWELL(BLASLONG, bfloat16 *, BLASLONG, double   *, BLASLONG);

openblas_complex_float cdotc_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
openblas_complex_float cdotu_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
openblas_complex_double zdotc_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG);
openblas_complex_double zdotu_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG);
openblas_complex_xdouble xdotc_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
openblas_complex_xdouble xdotu_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    saxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    daxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    qaxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    caxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zaxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xaxpy_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    caxpyc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zaxpyc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xaxpyc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    scopy_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    dcopy_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    qcopy_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    ccopy_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zcopy_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xcopy_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    sswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float  *, BLASLONG, float *, BLASLONG);
int    dswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double *, BLASLONG, double*, BLASLONG);
int    qswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble*, BLASLONG);
int    cswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float *, BLASLONG);
int    zswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double*, BLASLONG);
int    xswap_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble*, BLASLONG);

float   sasum_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  dasum_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qasum_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   casum_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zasum_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xasum_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

float   ssum_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  dsum_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qsum_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   csum_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zsum_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xsum_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

float   samax_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  damax_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qamax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   camax_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zamax_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xamax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

float   samin_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  damin_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qamin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   camin_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zamin_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xamin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

BLASLONG   isamax_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   idamax_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   iqamax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icamax_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   izamax_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   ixamax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

BLASLONG   isamin_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   idamin_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   iqamin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icamin_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   izamin_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   ixamin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

float   smax_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  dmax_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qmax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   cmax_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zmax_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xmax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

float   smin_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  dmin_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble qmin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   cmin_k_HASWELL(BLASLONG, float  *, BLASLONG);
double  zmin_k_HASWELL(BLASLONG, double *, BLASLONG);
xdouble xmin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

BLASLONG   ismax_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   idmax_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   iqmax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icmax_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   izmax_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   ixmax_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

BLASLONG   ismin_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   idmin_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   iqmin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icmin_k_HASWELL(BLASLONG, float  *, BLASLONG);
BLASLONG   izmin_k_HASWELL(BLASLONG, double *, BLASLONG);
BLASLONG   ixmin_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

int    sscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,
	      float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    dscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,
	      double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    qscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble,
	      xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);
int    cscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float,
	      float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    zscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	      double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    xscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	      xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);
int    csscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float,
	       float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    zdscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    xqscal_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);

float   snrm2_k_HASWELL(BLASLONG, float   *, BLASLONG);
double  dnrm2_k_HASWELL(BLASLONG, double  *, BLASLONG);
xdouble qnrm2_k_HASWELL(BLASLONG, xdouble *, BLASLONG);
float   cnrm2_k_HASWELL(BLASLONG, float   *, BLASLONG);
double  znrm2_k_HASWELL(BLASLONG, double  *, BLASLONG);
xdouble xnrm2_k_HASWELL(BLASLONG, xdouble *, BLASLONG);

int    srot_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG, float , float );
int    drot_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double, double);
int    qrot_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble, xdouble);
int    csrot_k_HASWELL(BLASLONG, float  *, BLASLONG, float  *, BLASLONG, float , float );
int    zdrot_k_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double, double);
int    xqrot_k_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble, xdouble);

int    srotg_k_HASWELL(float  *, float  *, float  *, float  *);
int    drotg_k_HASWELL(double *, double *, double *, double *);
int    qrotg_k_HASWELL(xdouble *, xdouble *, xdouble *, xdouble *);
int    csrotg_k_HASWELL(float  *, float  *, float  *, float  *);
int    zdrotg_k_HASWELL(double *, double *, double *, double *);
int    xqrotg_k_HASWELL(xdouble *, xdouble *, xdouble *, xdouble *);

int    srotmg_k_HASWELL(float  *, float  *, float  *, float  *, float  *);
int    drotmg_k_HASWELL(double *, double *, double *, double *, double *);
int    qrotmg_k_HASWELL(xdouble *, xdouble *, xdouble *, xdouble *, xdouble *);

int    srotm_k_HASWELL(BLASLONG, float,  BLASLONG, float,  BLASLONG, float);
int    drotm_k_HASWELL(BLASLONG, double, BLASLONG, double, BLASLONG, double);
int    qrotm_k_HASWELL(BLASLONG, xdouble, BLASLONG, xdouble, BLASLONG, xdouble);


int    saxpby_k_HASWELL(BLASLONG, float,  float  *, BLASLONG, float,  float  *, BLASLONG);
int    daxpby_k_HASWELL(BLASLONG, double, double *, BLASLONG, double, double *, BLASLONG);
int    caxpby_k_HASWELL(BLASLONG, float,  float,  float  *, BLASLONG, float,  float,  float  *, BLASLONG);
int    zaxpby_k_HASWELL(BLASLONG, double, double, double *, BLASLONG, double, double, double *, BLASLONG);


#ifdef __CUDACC__
}
#endif

#endif


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
/*_HASWELL(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_HASWELL(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#ifndef ASSEMBLER

/* Level 2 Blas routines */

#ifdef __CUDACC__
extern "C" {
#endif

int sbgemv_n_HASWELL(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG);
int sbgemv_t_HASWELL(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG);
int sbgemv_thread_n_HASWELL(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG, int);
int sbgemv_thread_t_HASWELL(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG, int);
int sger_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dger_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qger_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int cgeru_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerv_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerd_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zgeru_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerv_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerd_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xgeru_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerc_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerv_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerd_k_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int sger_thread_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dger_thread_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qger_thread_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int cger_thread_U_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_C_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_V_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_D_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zger_thread_U_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_C_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_V_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_D_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xger_thread_U_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_C_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_V_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_D_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int sgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int dgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int dgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int qgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int qgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);

int cgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);

int zgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);

int xgemv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);

int sgemv_thread_n_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int sgemv_thread_t_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int dgemv_thread_n_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int dgemv_thread_t_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int qgemv_thread_n_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int qgemv_thread_t_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int cgemv_thread_n_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_t_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_r_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_c_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_o_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_u_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_s_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_d_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int zgemv_thread_n_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_t_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_r_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_c_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_o_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_u_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_s_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_d_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int xgemv_thread_n_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_t_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_r_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_c_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_o_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_u_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_s_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_d_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int strsv_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtrsv_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtrsv_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctrsv_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztrsv_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtrsv_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int strmv_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);

int dtrmv_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);

int qtrmv_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ctrmv_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);

int ztrmv_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);

int xtrmv_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int strmv_thread_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int dtrmv_thread_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int qtrmv_thread_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ctrmv_thread_NUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CUU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CUN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CLU_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CLN_HASWELL(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int ztrmv_thread_NUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CUU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CUN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CLU_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CLN_HASWELL(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int xtrmv_thread_NUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CUU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CUN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CLU_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CLN_HASWELL(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int stpsv_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);

int dtpsv_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);

int qtpsv_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int ctpsv_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);

int ztpsv_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);

int xtpsv_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int stpmv_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);

int dtpmv_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);

int qtpmv_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int ctpmv_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CUU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CUN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CLU_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CLN_HASWELL(BLASLONG, float *, float *, BLASLONG, void *);

int ztpmv_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CUU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CUN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CLU_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CLN_HASWELL(BLASLONG, double *, double *, BLASLONG, void *);

int xtpmv_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int stpmv_thread_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);

int dtpmv_thread_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);

int qtpmv_thread_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);

int ctpmv_thread_NUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CUU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CUN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CLU_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CLN_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, int);

int ztpmv_thread_NUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CUU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CUN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CLU_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CLN_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, int);

int xtpmv_thread_NUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CUU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CUN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CLU_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CLN_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);

int ssymv_L_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ssymv_U_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dsymv_L_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dsymv_U_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qsymv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsymv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csymv_L_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int csymv_U_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zsymv_L_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zsymv_U_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xsymv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsymv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssymv_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssymv_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsymv_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsymv_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsymv_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsymv_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csymv_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csymv_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsymv_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsymv_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsymv_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsymv_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chemv_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_M_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_V_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhemv_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_M_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_V_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhemv_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_M_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_V_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sspmv_L_HASWELL(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int sspmv_U_HASWELL(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int dspmv_L_HASWELL(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int dspmv_U_HASWELL(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int qspmv_L_HASWELL(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qspmv_U_HASWELL(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int cspmv_L_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int cspmv_U_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int zspmv_L_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zspmv_U_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int xspmv_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xspmv_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int sspmv_thread_L_HASWELL(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int sspmv_thread_U_HASWELL(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int dspmv_thread_L_HASWELL(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int dspmv_thread_U_HASWELL(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int qspmv_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qspmv_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int cspmv_thread_L_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int cspmv_thread_U_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zspmv_thread_L_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zspmv_thread_U_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xspmv_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xspmv_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssyr_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int ssyr_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int dsyr_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int dsyr_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int qsyr_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsyr_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csyr_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *);
int csyr_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *);
int zsyr_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *);
int zsyr_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *);
int xsyr_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsyr_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssyr_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssyr_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsyr_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsyr_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsyr_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsyr_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csyr_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int csyr_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsyr_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsyr_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsyr_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsyr_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssyr2_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ssyr2_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dsyr2_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dsyr2_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qsyr2_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsyr2_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csyr2_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int csyr2_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zsyr2_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zsyr2_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xsyr2_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsyr2_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssyr2_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssyr2_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsyr2_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsyr2_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsyr2_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsyr2_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csyr2_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csyr2_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsyr2_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsyr2_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsyr2_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsyr2_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sspr_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int sspr_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int dspr_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int dspr_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int qspr_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int qspr_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int cspr_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, float *);
int cspr_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, float *);
int zspr_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, double *);
int zspr_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, double *);
int xspr_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xspr_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);

int sspr_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int sspr_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int dspr_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int dspr_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int qspr_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int qspr_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int cspr_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, float *, int);
int cspr_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, float *, int);
int zspr_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, double *, int);
int zspr_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, double *, int);
int xspr_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xspr_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int sspr2_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int sspr2_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int dspr2_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int dspr2_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int qspr2_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int qspr2_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int cspr2_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int cspr2_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int zspr2_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zspr2_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int xspr2_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xspr2_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);

int sspr2_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int sspr2_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int dspr2_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int dspr2_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int qspr2_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int qspr2_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int cspr2_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int cspr2_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int zspr2_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zspr2_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int xspr2_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xspr2_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int cher_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_V_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_M_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int zher_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_V_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_M_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int xher_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_V_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_M_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int cher_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_V_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_M_HASWELL(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int zher_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_V_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_M_HASWELL(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int xher_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_V_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_M_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int cher2_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_M_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_V_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zher2_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_M_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_V_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xher2_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_M_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_V_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int cher2_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_M_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_V_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zher2_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_M_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_V_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xher2_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_M_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_V_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chpr_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_M_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_V_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *);
int zhpr_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_M_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_V_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *);
int xhpr_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_M_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_V_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);

int chpr_thread_L_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_U_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_M_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_V_HASWELL(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int zhpr_thread_L_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_U_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_M_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_V_HASWELL(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int xhpr_thread_L_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_U_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_M_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_V_HASWELL(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int chpr2_L_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_U_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_M_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_V_HASWELL(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int zhpr2_L_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_U_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_M_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_V_HASWELL(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int xhpr2_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_M_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_V_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);

int chpr2_thread_L_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_U_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_M_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_V_HASWELL(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int zhpr2_thread_L_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_U_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_M_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_V_HASWELL(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int xhpr2_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_M_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_V_HASWELL(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int chemv_L_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_U_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_M_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_V_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zhemv_L_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_U_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_M_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_V_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xhemv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_M_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_V_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int chpmv_L_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_U_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_M_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_V_HASWELL(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int zhpmv_L_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_U_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_M_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_V_HASWELL(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int xhpmv_L_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_U_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_M_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_V_HASWELL(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int chpmv_thread_L_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_U_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_M_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_V_HASWELL(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhpmv_thread_L_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_U_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_M_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_V_HASWELL(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhpmv_thread_L_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_U_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_M_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_V_HASWELL(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssbmv_L_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ssbmv_U_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int dsbmv_L_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dsbmv_U_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int qsbmv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qsbmv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int csbmv_L_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int csbmv_U_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int zsbmv_L_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zsbmv_U_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int xsbmv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xsbmv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int chbmv_L_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_U_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_M_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_V_HASWELL(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int zhbmv_L_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_U_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_M_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_V_HASWELL(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int xhbmv_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_M_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_V_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);


int ssbmv_thread_L_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssbmv_thread_U_HASWELL(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsbmv_thread_L_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsbmv_thread_U_HASWELL(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsbmv_thread_L_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsbmv_thread_U_HASWELL(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csbmv_thread_L_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csbmv_thread_U_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsbmv_thread_L_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsbmv_thread_U_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsbmv_thread_L_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsbmv_thread_U_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chbmv_thread_L_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_U_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_M_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_V_HASWELL(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhbmv_thread_L_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_U_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_M_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_V_HASWELL(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhbmv_thread_L_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_U_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_M_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_V_HASWELL(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int snorm_n_HASWELL(BLASLONG, BLASLONG, float *a, BLASLONG);
int snorm_t_HASWELL(BLASLONG, BLASLONG, float *a, BLASLONG);
int dnorm_n_HASWELL(BLASLONG, BLASLONG, double *a, BLASLONG);
int dnorm_t_HASWELL(BLASLONG, BLASLONG, double *a, BLASLONG);
int cnorm_n_HASWELL(BLASLONG, BLASLONG, float *a, BLASLONG);
int cnorm_t_HASWELL(BLASLONG, BLASLONG, float *a, BLASLONG);
int znorm_n_HASWELL(BLASLONG, BLASLONG, double *a, BLASLONG);
int znorm_t_HASWELL(BLASLONG, BLASLONG, double *a, BLASLONG);

void sgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void sgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);

void dgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void dgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);

void qgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void qgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);

void cgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);

void zgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);

void xgbmv_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);

int sgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int sgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int dgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int dgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int qgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int qgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int cgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int zgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int xgbmv_thread_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_t_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_c_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_o_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_u_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_s_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_d_HASWELL(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int stbmv_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtbmv_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtbmv_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctbmv_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztbmv_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtbmv_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int stbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int dtbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int qtbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ctbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int ztbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int xtbmv_thread_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int stbsv_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtbsv_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtbsv_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctbsv_NUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CUU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CUN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CLU_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CLN_HASWELL(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztbsv_NUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CUU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CUN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CLU_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CLN_HASWELL(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtbsv_NUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CUU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CUN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CLU_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CLN_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

#ifdef __CUDACC__
}
#endif

#endif

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
/*_HASWELL(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_HASWELL(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#ifndef ASSEMBLER

#ifdef __CUDACC__
__global__ void cuda_sgemm_kernel_HASWELL(int, int, int, float *, float *, float *);
__global__ void cuda_dgemm_kernel_HASWELL(int, int, int, double *, double *, double *);
#endif

#ifdef __CUDACC__
extern "C" {
#endif

void sgemm_direct_HASWELL(BLASLONG M, BLASLONG N, BLASLONG K,
	float * A, BLASLONG strideA,
	float * B, BLASLONG strideB,
	float * R, BLASLONG strideR);

int sgemm_direct_performant_HASWELL(BLASLONG M, BLASLONG N, BLASLONG K);


int sbgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,
	       bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float *, BLASLONG);
int sgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float   *, BLASLONG, float  *, BLASLONG);
int dgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double  *, BLASLONG, double *, BLASLONG);
int cgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float   *, BLASLONG, float  *, BLASLONG);
int zgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double  *, BLASLONG, double *, BLASLONG);

#ifdef EXPRECISION
int qgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
int xgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
#else
int qgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble *,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
int xgemm_beta_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble *,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
#endif

int sbgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int dgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int cgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int zgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);

#ifdef QUAD_PRECISION
int qgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
#else
int qgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_incopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_itcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
#endif


int strsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int dtrsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);

int qtrsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int ctrsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);

int ztrsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);

int xtrsm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int strmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);

int dtrmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);

int qtrmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int ctrmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);

int ztrmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);

int xtrmm_kernel_RN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RR_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RC_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LN_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LT_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LR_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LC_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int strmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);

int dtrmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);

int qtrmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int ctrmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);

int ztrmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);

int xtrmm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_outucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_outncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int strsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);

int dtrsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);

int qtrsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);

int ctrsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);

int ztrsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);

int xtrsm_iunucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iunncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iutucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iutncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ounucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ounncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_outucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_outncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ilnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ilnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_olnucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_olnncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_oltucopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_oltncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);

int ssymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int dsymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int qsymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int csymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int zsymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int xsymm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_outcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int chemm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_outcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int zhemm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_outcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int xhemm_iutcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_outcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_iltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_oltcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int ssyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int ssyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);

int dsyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int dsyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);

int qsyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int qsyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int csyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int csyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int zsyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zsyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int xsyrk_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xsyrk_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int ssyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int ssyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int dsyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int dsyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int qsyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int qsyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int csyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int csyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int zsyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zsyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int xsyr2k_kernel_U_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xsyr2k_kernel_L_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int cherk_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);

int zherk_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);

int xherk_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int cher2k_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);

int zher2k_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);

int xher2k_kernel_UN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_UC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_LN_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_LC_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int sbgemm_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  bfloat16 *, bfloat16 *, float *, BLASLONG);
int sgemm_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float  *, float  *, float  *, BLASLONG);
int dgemm_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, xidouble *, xidouble *, xidouble *, xdouble *, BLASLONG);
#else
int qgemm_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
#endif

#ifdef SMALL_MATRIX_OPT
int sbgemm_small_matrix_permit_HASWELL(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float beta);

int sbgemm_small_kernel_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);

int sgemm_small_matrix_permit_HASWELL(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float beta);

int sgemm_small_kernel_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);

int dgemm_small_matrix_permit_HASWELL(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double beta);

int dgemm_small_kernel_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);

int sbgemm_small_kernel_b0_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);

int sgemm_small_kernel_b0_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);

int dgemm_small_kernel_b0_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);

int cgemm_small_matrix_permit_HASWELL(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha0, float alpha1, float beta0, float beta1);

int cgemm_small_kernel_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
	
int cgemm_small_kernel_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int cgemm_small_kernel_rn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int cgemm_small_kernel_cn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_ct_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_cr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_cc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int zgemm_small_matrix_permit_HASWELL(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, double alpha0, double alpha1, double beta0, double beta1);

int zgemm_small_kernel_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
	
int zgemm_small_kernel_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int zgemm_small_kernel_rn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int zgemm_small_kernel_cn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_ct_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_cr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_cc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int cgemm_small_kernel_b0_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);	
int cgemm_small_kernel_b0_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_nr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_nc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
	
int cgemm_small_kernel_b0_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int cgemm_small_kernel_b0_rn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int cgemm_small_kernel_b0_cn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_ct_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_cr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_cc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int zgemm_small_kernel_b0_nn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);	
int zgemm_small_kernel_b0_nt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_nr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_nc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
	
int zgemm_small_kernel_b0_tn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

int zgemm_small_kernel_b0_rn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rt_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

int zgemm_small_kernel_b0_cn_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_ct_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_cr_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_cc_HASWELL(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

#endif

int cgemm_kernel_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_l_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_b_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);

int zgemm_kernel_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_l_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_b_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);

int xgemm_kernel_n_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_l_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_r_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_b_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int zgemm3m_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int xgemm3m_kernel_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);

int sbgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);

int sgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int qgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int cgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int xgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int xgemm_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int sbgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);

int sgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int qgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int cgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemm_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int zgemm3m_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int xgemm3m_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm3m_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemm3m_thread_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cher2m_LNN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCN_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCT_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCR_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCC_HASWELL(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);

int zher2m_LNN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCN_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCT_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCR_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCC_HASWELL(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);

int strsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dtrsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qtrsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ctrsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int ztrsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xtrsm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int strmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dtrmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qtrmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ctrmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int ztrmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xtrmm_LNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCUU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCUN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCLU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCLN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm3m_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm3m_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm_thread_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_LL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_RU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_RL_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyrk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyrk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyr2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_UT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_LT_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cherk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zherk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xherk_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cherk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zherk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xherk_thread_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cher2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zher2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xher2k_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_UC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_LC_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sgemt_n_HASWELL(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, int);
int sgemt_t_HASWELL(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, int);
int dgemt_n_HASWELL(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, int);
int dgemt_t_HASWELL(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, int);

int cgemt_n_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_t_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_r_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_c_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int zgemt_n_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_t_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_r_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_c_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);

int sgema_n_HASWELL(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, BLASLONG);
int sgema_t_HASWELL(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, BLASLONG);
int dgema_n_HASWELL(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, BLASLONG);
int dgema_t_HASWELL(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, BLASLONG);

int cgema_n_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_t_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_r_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_c_HASWELL(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int zgema_n_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_t_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_r_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_c_HASWELL(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);

int cgemm3m_incopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_incopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_incopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);

int cgemm3m_oncopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_oncopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_oncopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);

int zgemm3m_incopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_incopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_incopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);

int zgemm3m_oncopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_oncopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_oncopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);

int xgemm3m_incopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_incopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_incopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);

int xgemm3m_oncopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_oncopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_oncopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int csymm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);

int csymm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);

int zsymm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);

int zsymm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);

int xsymm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);

int xsymm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int chemm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);

int chemm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);

int zhemm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);

int zhemm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);

int xhemm3m_iucopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_iucopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_iucopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);

int xhemm3m_oucopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyb_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_oucopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyr_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_oucopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyi_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int sgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemc_nn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rt_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cn_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_ct_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cr_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cc_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int sgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int dgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int dgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int qgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int qgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int cgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int cgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int zgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int zgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int xgemc_oncopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int xgemc_otcopy_HASWELL(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);

int somatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int simatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  float, float *, BLASLONG);

int domatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int dimatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  double, double *, BLASLONG);

int comatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int cimatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);

int comatcopy_k_cnc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rnc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_ctc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rtc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int cimatcopy_k_cnc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rnc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_ctc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rtc_HASWELL(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);

int zomatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zimatcopy_k_cn_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rn_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_ct_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rt_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);

int zomatcopy_k_cnc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rnc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_ctc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rtc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zimatcopy_k_cnc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rnc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_ctc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rtc_HASWELL(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);

int sgeadd_k_HASWELL(BLASLONG, BLASLONG, float, float*, BLASLONG, float, float *, BLASLONG); 
int dgeadd_k_HASWELL(BLASLONG, BLASLONG, double, double*, BLASLONG, double, double *, BLASLONG); 
int cgeadd_k_HASWELL(BLASLONG, BLASLONG, float, float, float*, BLASLONG, float, float, float *, BLASLONG); 
int zgeadd_k_HASWELL(BLASLONG, BLASLONG, double,double, double*, BLASLONG, double, double, double *, BLASLONG); 


#ifdef __CUDACC__
}
#endif

#endif

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
/*_HASWELL(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_HASWELL(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
/*    OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF ADVISED  OF  THE    */
/*    POSSIBILITY OF SUCH DAMAGE.                                    */
/*                                                                   */
/* The views and conclusions contained in the software and           */
/* documentation are those of the authors and should not be          */
/* interpreted as representing official policies, either expressed   */
/* or implied, of The University of Texas at Austin.                 */
/*********************************************************************/

#ifndef ASSEMBLER

/* Lapack Library */

blasint sgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetf2_k_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrf_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrf_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int slaswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,   float   *, BLASLONG, float  *, BLASLONG, blasint *, BLASLONG);
int slaswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,   float   *, BLASLONG, float  *, BLASLONG, blasint *, BLASLONG);
int dlaswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,  double  *, BLASLONG, double *, BLASLONG, blasint *, BLASLONG);
int dlaswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,  double  *, BLASLONG, double *, BLASLONG, blasint *, BLASLONG);
int qlaswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);
int qlaswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);

int claswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,   float,   float   *, BLASLONG, float   *, BLASLONG, blasint *, BLASLONG);
int claswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, float,   float,   float   *, BLASLONG, float   *, BLASLONG, blasint *, BLASLONG);
int zlaswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,  double,  double  *, BLASLONG, double  *, BLASLONG, blasint *, BLASLONG);
int zlaswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, double,  double,  double  *, BLASLONG, double  *, BLASLONG, blasint *, BLASLONG);
int xlaswp_plus_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);
int xlaswp_minus_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);

int slaswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, float   *, BLASLONG, blasint *, float   *);
int dlaswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, double  *, BLASLONG, blasint *, double  *);
int qlaswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble *, BLASLONG, blasint *, xdouble *);
int claswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, float   *, BLASLONG, blasint *, float   *);
int zlaswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, double  *, BLASLONG, blasint *, double  *);
int xlaswp_ncopy_HASWELL(BLASLONG, BLASLONG, BLASLONG, xdouble *, BLASLONG, blasint *, xdouble *);

blasint sgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint sgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_R_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_C_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_R_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_C_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrs_N_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_T_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_R_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_C_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint sgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_R_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_C_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_R_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_C_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrs_N_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_T_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_R_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_C_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotf2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotf2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotrf_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotrf_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotrf_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotrf_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauu2_U_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauu2_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauum_U_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauum_L_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauum_U_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauum_L_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrti2_UU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_UN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_LU_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_LN_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtri_UU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_UN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtri_UU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_UN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sneg_tcopy_HASWELL(BLASLONG, BLASLONG, float   *, BLASLONG, float   *);
int dneg_tcopy_HASWELL(BLASLONG, BLASLONG, double  *, BLASLONG, double  *);
int qneg_tcopy_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *);
int cneg_tcopy_HASWELL(BLASLONG, BLASLONG, float   *, BLASLONG, float   *);
int zneg_tcopy_HASWELL(BLASLONG, BLASLONG, double  *, BLASLONG, double  *);
int xneg_tcopy_HASWELL(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *);

blasint slarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlarf_L_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlarf_R_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtrs_UNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCU_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCN_single_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtrs_UNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCU_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCN_parallel_HASWELL(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

#endif
