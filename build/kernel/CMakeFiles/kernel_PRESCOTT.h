
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
/*_PRESCOTT(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_PRESCOTT(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
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

float   sdot_k_PRESCOTT(BLASLONG, float   *, BLASLONG, float   *, BLASLONG);
double dsdot_k_PRESCOTT(BLASLONG, float   *, BLASLONG, float *, BLASLONG);
double  ddot_k_PRESCOTT(BLASLONG, double  *, BLASLONG, double  *, BLASLONG);
xdouble qdot_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
float  sbdot_k_PRESCOTT(BLASLONG, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG);

void   sbstobf16_k_PRESCOTT(BLASLONG, float    *, BLASLONG, bfloat16 *, BLASLONG);
void   sbdtobf16_k_PRESCOTT(BLASLONG, double   *, BLASLONG, bfloat16 *, BLASLONG);
void   sbf16tos_k_PRESCOTT(BLASLONG, bfloat16 *, BLASLONG, float    *, BLASLONG);
void   dbf16tod_k_PRESCOTT(BLASLONG, bfloat16 *, BLASLONG, double   *, BLASLONG);

openblas_complex_float cdotc_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
openblas_complex_float cdotu_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
openblas_complex_double zdotc_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG);
openblas_complex_double zdotu_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG);
openblas_complex_xdouble xdotc_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
openblas_complex_xdouble xdotu_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    saxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    daxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    qaxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    caxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zaxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xaxpy_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    caxpyc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zaxpyc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xaxpyc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    scopy_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    dcopy_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    qcopy_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);
int    ccopy_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG);
int    zcopy_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG);
int    xcopy_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG);

int    sswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float  *, BLASLONG, float *, BLASLONG);
int    dswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double *, BLASLONG, double*, BLASLONG);
int    qswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble*, BLASLONG);
int    cswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float  *, BLASLONG, float *, BLASLONG);
int    zswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG, double*, BLASLONG);
int    xswap_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble*, BLASLONG);

float   sasum_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  dasum_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qasum_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   casum_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zasum_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xasum_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

float   ssum_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  dsum_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qsum_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   csum_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zsum_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xsum_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

float   samax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  damax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qamax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   camax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zamax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xamax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

float   samin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  damin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qamin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   camin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zamin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xamin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

BLASLONG   isamax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   idamax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   iqamax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icamax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   izamax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   ixamax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

BLASLONG   isamin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   idamin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   iqamin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icamin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   izamin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   ixamin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

float   smax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  dmax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qmax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   cmax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zmax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xmax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

float   smin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  dmin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble qmin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   cmin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
double  zmin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
xdouble xmin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

BLASLONG   ismax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   idmax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   iqmax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icmax_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   izmax_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   ixmax_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

BLASLONG   ismin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   idmin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   iqmin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
BLASLONG   icmin_k_PRESCOTT(BLASLONG, float  *, BLASLONG);
BLASLONG   izmin_k_PRESCOTT(BLASLONG, double *, BLASLONG);
BLASLONG   ixmin_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

int    sscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,
	      float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    dscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,
	      double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    qscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble,
	      xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);
int    cscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float,
	      float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    zscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	      double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    xscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	      xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);
int    csscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float,
	       float *, BLASLONG, float *, BLASLONG,  float  *, BLASLONG);
int    zdscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double *, BLASLONG,  double  *, BLASLONG);
int    xqscal_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble *, BLASLONG,  xdouble  *, BLASLONG);

float   snrm2_k_PRESCOTT(BLASLONG, float   *, BLASLONG);
double  dnrm2_k_PRESCOTT(BLASLONG, double  *, BLASLONG);
xdouble qnrm2_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);
float   cnrm2_k_PRESCOTT(BLASLONG, float   *, BLASLONG);
double  znrm2_k_PRESCOTT(BLASLONG, double  *, BLASLONG);
xdouble xnrm2_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG);

int    srot_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG, float , float );
int    drot_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double, double);
int    qrot_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble, xdouble);
int    csrot_k_PRESCOTT(BLASLONG, float  *, BLASLONG, float  *, BLASLONG, float , float );
int    zdrot_k_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double, double);
int    xqrot_k_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble, xdouble);

int    srotg_k_PRESCOTT(float  *, float  *, float  *, float  *);
int    drotg_k_PRESCOTT(double *, double *, double *, double *);
int    qrotg_k_PRESCOTT(xdouble *, xdouble *, xdouble *, xdouble *);
int    csrotg_k_PRESCOTT(float  *, float  *, float  *, float  *);
int    zdrotg_k_PRESCOTT(double *, double *, double *, double *);
int    xqrotg_k_PRESCOTT(xdouble *, xdouble *, xdouble *, xdouble *);

int    srotmg_k_PRESCOTT(float  *, float  *, float  *, float  *, float  *);
int    drotmg_k_PRESCOTT(double *, double *, double *, double *, double *);
int    qrotmg_k_PRESCOTT(xdouble *, xdouble *, xdouble *, xdouble *, xdouble *);

int    srotm_k_PRESCOTT(BLASLONG, float,  BLASLONG, float,  BLASLONG, float);
int    drotm_k_PRESCOTT(BLASLONG, double, BLASLONG, double, BLASLONG, double);
int    qrotm_k_PRESCOTT(BLASLONG, xdouble, BLASLONG, xdouble, BLASLONG, xdouble);


int    saxpby_k_PRESCOTT(BLASLONG, float,  float  *, BLASLONG, float,  float  *, BLASLONG);
int    daxpby_k_PRESCOTT(BLASLONG, double, double *, BLASLONG, double, double *, BLASLONG);
int    caxpby_k_PRESCOTT(BLASLONG, float,  float,  float  *, BLASLONG, float,  float,  float  *, BLASLONG);
int    zaxpby_k_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double, double, double *, BLASLONG);


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
/*_PRESCOTT(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_PRESCOTT(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
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

int sbgemv_n_PRESCOTT(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG);
int sbgemv_t_PRESCOTT(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG);
int sbgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG, int);
int sbgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, float, bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float, float *, BLASLONG, int);
int sger_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dger_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qger_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int cgeru_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerv_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cgerd_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zgeru_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerv_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zgerd_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xgeru_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerc_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerv_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xgerd_k_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int sger_thread_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dger_thread_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qger_thread_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int cger_thread_U_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_C_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_V_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cger_thread_D_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zger_thread_U_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_C_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_V_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zger_thread_D_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xger_thread_U_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_C_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_V_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xger_thread_D_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int sgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int dgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int dgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int qgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int qgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);

int cgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);
int cgemv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer);

int zgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);
int zgemv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer);

int xgemv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);
int xgemv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer);

int sgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int sgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int dgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int dgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int qgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int qgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int cgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_r_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_c_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_o_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_u_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_s_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgemv_thread_d_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int zgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_r_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_c_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_o_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_u_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_s_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgemv_thread_d_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int xgemv_thread_n_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_t_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_r_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_c_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_o_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_u_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_s_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgemv_thread_d_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int strsv_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int strsv_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtrsv_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtrsv_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtrsv_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtrsv_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctrsv_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_RLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctrsv_CLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztrsv_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_RLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztrsv_CLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtrsv_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_RLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtrsv_CLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int strmv_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int strmv_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);

int dtrmv_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dtrmv_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);

int qtrmv_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qtrmv_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ctrmv_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_RLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ctrmv_CLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);

int ztrmv_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_RLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int ztrmv_CLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);

int xtrmv_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_RLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xtrmv_CLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int strmv_thread_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int strmv_thread_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int dtrmv_thread_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtrmv_thread_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int qtrmv_thread_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtrmv_thread_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ctrmv_thread_NUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_NLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_TLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_RLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CUU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CUN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CLU_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctrmv_thread_CLN_PRESCOTT(BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int ztrmv_thread_NUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_NLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_TLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_RLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CUU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CUN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CLU_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztrmv_thread_CLN_PRESCOTT(BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int xtrmv_thread_NUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_NLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_TLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_RLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CUU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CUN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CLU_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtrmv_thread_CLN_PRESCOTT(BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int stpsv_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpsv_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);

int dtpsv_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpsv_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);

int qtpsv_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpsv_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int ctpsv_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_RLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpsv_CLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);

int ztpsv_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_RLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpsv_CLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);

int xtpsv_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_RLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpsv_CLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int stpmv_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int stpmv_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);

int dtpmv_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int dtpmv_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);

int qtpmv_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int qtpmv_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int ctpmv_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_RLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);
int ctpmv_CLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, void *);

int ztpmv_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_RLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);
int ztpmv_CLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, void *);

int xtpmv_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_RLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);
int xtpmv_CLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, void *);

int stpmv_thread_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int stpmv_thread_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);

int dtpmv_thread_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int dtpmv_thread_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);

int qtpmv_thread_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int qtpmv_thread_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);

int ctpmv_thread_NUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_NLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_TLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_RLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CUU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CUN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CLU_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);
int ctpmv_thread_CLN_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, int);

int ztpmv_thread_NUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_NLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_TLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_RLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CUU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CUN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CLU_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);
int ztpmv_thread_CLN_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, int);

int xtpmv_thread_NUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_NLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_TLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_RLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CUU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CUN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CLU_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);
int xtpmv_thread_CLN_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, int);

int ssymv_L_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ssymv_U_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dsymv_L_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dsymv_U_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qsymv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsymv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csymv_L_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int csymv_U_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zsymv_L_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zsymv_U_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xsymv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsymv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssymv_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssymv_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsymv_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsymv_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsymv_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsymv_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csymv_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csymv_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsymv_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsymv_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsymv_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsymv_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chemv_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_M_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chemv_thread_V_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhemv_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_M_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhemv_thread_V_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhemv_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_M_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhemv_thread_V_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sspmv_L_PRESCOTT(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int sspmv_U_PRESCOTT(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int dspmv_L_PRESCOTT(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int dspmv_U_PRESCOTT(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int qspmv_L_PRESCOTT(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qspmv_U_PRESCOTT(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int cspmv_L_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int cspmv_U_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int zspmv_L_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zspmv_U_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int xspmv_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xspmv_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int sspmv_thread_L_PRESCOTT(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int sspmv_thread_U_PRESCOTT(BLASLONG, float, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int dspmv_thread_L_PRESCOTT(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int dspmv_thread_U_PRESCOTT(BLASLONG, double, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int qspmv_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qspmv_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int cspmv_thread_L_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int cspmv_thread_U_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zspmv_thread_L_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zspmv_thread_U_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xspmv_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xspmv_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssyr_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int ssyr_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int dsyr_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int dsyr_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int qsyr_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsyr_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csyr_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *);
int csyr_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *);
int zsyr_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *);
int zsyr_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *);
int xsyr_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsyr_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssyr_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssyr_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsyr_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsyr_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsyr_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsyr_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csyr_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int csyr_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsyr_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsyr_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsyr_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsyr_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssyr2_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int ssyr2_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int dsyr2_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int dsyr2_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int qsyr2_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int qsyr2_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int csyr2_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int csyr2_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zsyr2_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zsyr2_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xsyr2_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xsyr2_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int ssyr2_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssyr2_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsyr2_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsyr2_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsyr2_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsyr2_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csyr2_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csyr2_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsyr2_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsyr2_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsyr2_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsyr2_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int sspr_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int sspr_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int dspr_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int dspr_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int qspr_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int qspr_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int cspr_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, float *);
int cspr_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, float *);
int zspr_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, double *);
int zspr_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, double *);
int xspr_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xspr_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);

int sspr_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int sspr_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int dspr_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int dspr_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int qspr_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int qspr_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int cspr_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, float *, int);
int cspr_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, float *, int);
int zspr_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, double *, int);
int zspr_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, double *, int);
int xspr_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xspr_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int sspr2_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int sspr2_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int dspr2_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int dspr2_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int qspr2_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int qspr2_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int cspr2_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int cspr2_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int zspr2_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zspr2_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int xspr2_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xspr2_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);

int sspr2_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int sspr2_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int dspr2_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int dspr2_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int qspr2_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int qspr2_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int cspr2_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int cspr2_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int zspr2_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zspr2_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int xspr2_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xspr2_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int cher_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_V_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int cher_M_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *);
int zher_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_V_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int zher_M_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *);
int xher_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_V_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher_M_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int cher_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_V_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher_thread_M_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, int);
int zher_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_V_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher_thread_M_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, int);
int xher_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_V_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher_thread_M_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int cher2_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_M_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int cher2_V_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zher2_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_M_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zher2_V_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xher2_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_M_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xher2_V_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int cher2_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_M_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int cher2_thread_V_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zher2_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_M_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zher2_thread_V_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xher2_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_M_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xher2_thread_V_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chpr_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_M_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int chpr_V_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *);
int zhpr_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_M_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int zhpr_V_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *);
int xhpr_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_M_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr_V_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *);

int chpr_thread_L_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_U_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_M_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int chpr_thread_V_PRESCOTT(BLASLONG, float, float *, BLASLONG, float *, float *, int);
int zhpr_thread_L_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_U_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_M_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int zhpr_thread_V_PRESCOTT(BLASLONG, double, double *, BLASLONG, double *, double *, int);
int xhpr_thread_L_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_U_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_M_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr_thread_V_PRESCOTT(BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int chpr2_L_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_U_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_M_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int chpr2_V_PRESCOTT(BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, float *);
int zhpr2_L_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_U_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_M_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int zhpr2_V_PRESCOTT(BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, double *);
int xhpr2_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_M_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);
int xhpr2_V_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *);

int chpr2_thread_L_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_U_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_M_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int chpr2_thread_V_PRESCOTT(BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, float *, int);
int zhpr2_thread_L_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_U_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_M_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int zhpr2_thread_V_PRESCOTT(BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, double *, int);
int xhpr2_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_M_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);
int xhpr2_thread_V_PRESCOTT(BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, xdouble *, int);

int chemv_L_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_U_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_M_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int chemv_V_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *);
int zhemv_L_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_U_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_M_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int zhemv_V_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *);
int xhemv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_M_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);
int xhemv_V_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *);

int chpmv_L_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_U_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_M_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int chpmv_V_PRESCOTT(BLASLONG, float, float, float *, float *, BLASLONG, float *, BLASLONG, void *);
int zhpmv_L_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_U_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_M_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int zhpmv_V_PRESCOTT(BLASLONG, double, double, double *, double *, BLASLONG, double *, BLASLONG, void *);
int xhpmv_L_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_U_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_M_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhpmv_V_PRESCOTT(BLASLONG, xdouble, xdouble, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int chpmv_thread_L_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_U_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_M_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int chpmv_thread_V_PRESCOTT(BLASLONG, float *, float *, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhpmv_thread_L_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_U_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_M_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhpmv_thread_V_PRESCOTT(BLASLONG, double *, double *, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhpmv_thread_L_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_U_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_M_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhpmv_thread_V_PRESCOTT(BLASLONG, xdouble *, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ssbmv_L_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ssbmv_U_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int dsbmv_L_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dsbmv_U_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int qsbmv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qsbmv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int csbmv_L_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int csbmv_U_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int zsbmv_L_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zsbmv_U_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int xsbmv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xsbmv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int chbmv_L_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_U_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_M_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int chbmv_V_PRESCOTT(BLASLONG, BLASLONG, float, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int zhbmv_L_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_U_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_M_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int zhbmv_V_PRESCOTT(BLASLONG, BLASLONG, double, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int xhbmv_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_M_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xhbmv_V_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);


int ssbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ssbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, float, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int dsbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dsbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, double, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int qsbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qsbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int csbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int csbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zsbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zsbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xsbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xsbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int chbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_M_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int chbmv_thread_V_PRESCOTT(BLASLONG, BLASLONG, float *, float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int zhbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_M_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int zhbmv_thread_V_PRESCOTT(BLASLONG, BLASLONG, double *, double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int xhbmv_thread_L_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_U_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_M_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xhbmv_thread_V_PRESCOTT(BLASLONG, BLASLONG, xdouble *, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int snorm_n_PRESCOTT(BLASLONG, BLASLONG, float *a, BLASLONG);
int snorm_t_PRESCOTT(BLASLONG, BLASLONG, float *a, BLASLONG);
int dnorm_n_PRESCOTT(BLASLONG, BLASLONG, double *a, BLASLONG);
int dnorm_t_PRESCOTT(BLASLONG, BLASLONG, double *a, BLASLONG);
int cnorm_n_PRESCOTT(BLASLONG, BLASLONG, float *a, BLASLONG);
int cnorm_t_PRESCOTT(BLASLONG, BLASLONG, float *a, BLASLONG);
int znorm_n_PRESCOTT(BLASLONG, BLASLONG, double *a, BLASLONG);
int znorm_t_PRESCOTT(BLASLONG, BLASLONG, double *a, BLASLONG);

void sgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void sgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);

void dgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void dgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);

void qgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void qgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);

void cgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);
void cgbmv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *buffer);

void zgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);
void zgbmv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *buffer);

void xgbmv_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);
void xgbmv_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *buffer);

int sgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int sgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int dgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int dgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int qgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int qgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int cgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);
int cgbmv_thread_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, float *,
		 float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *buffer, int);

int zgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);
int zgbmv_thread_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, double *,
		 double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *buffer, int);

int xgbmv_thread_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_t_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_c_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_o_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_u_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_s_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);
int xgbmv_thread_d_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, BLASLONG, xdouble *,
		 xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *buffer, int);

int stbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_RLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbmv_CLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_RLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbmv_CLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtbmv_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_RLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbmv_CLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int stbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int stbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int dtbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int dtbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int qtbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int qtbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int ctbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_RLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);
int ctbmv_thread_CLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, float *, int);

int ztbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_RLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);
int ztbmv_thread_CLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, double *, int);

int xtbmv_thread_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_RLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);
int xtbmv_thread_CLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, xdouble *, int);

int stbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int stbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int dtbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int dtbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int qtbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int qtbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

int ctbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_RLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CUU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CUN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CLU_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);
int ctbsv_CLN_PRESCOTT(BLASLONG, BLASLONG, float *, BLASLONG, float *, BLASLONG, void *);

int ztbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_RLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CUU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CUN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CLU_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);
int ztbsv_CLN_PRESCOTT(BLASLONG, BLASLONG, double *, BLASLONG, double *, BLASLONG, void *);

int xtbsv_NUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_NLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_TLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_RLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CUU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CUN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CLU_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);
int xtbsv_CLN_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *, BLASLONG, void *);

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
/*_PRESCOTT(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_PRESCOTT(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
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
__global__ void cuda_sgemm_kernel_PRESCOTT(int, int, int, float *, float *, float *);
__global__ void cuda_dgemm_kernel_PRESCOTT(int, int, int, double *, double *, double *);
#endif

#ifdef __CUDACC__
extern "C" {
#endif

void sgemm_direct_PRESCOTT(BLASLONG M, BLASLONG N, BLASLONG K,
	float * A, BLASLONG strideA,
	float * B, BLASLONG strideB,
	float * R, BLASLONG strideR);

int sgemm_direct_performant_PRESCOTT(BLASLONG M, BLASLONG N, BLASLONG K);


int sbgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,
	       bfloat16 *, BLASLONG, bfloat16 *, BLASLONG, float *, BLASLONG);
int sgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,
	       float  *, BLASLONG, float   *, BLASLONG, float  *, BLASLONG);
int dgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,
	       double *, BLASLONG, double  *, BLASLONG, double *, BLASLONG);
int cgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,
	       float  *, BLASLONG, float   *, BLASLONG, float  *, BLASLONG);
int zgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double,
	       double *, BLASLONG, double  *, BLASLONG, double *, BLASLONG);

#ifdef EXPRECISION
int qgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
int xgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
#else
int qgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble *,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
int xgemm_beta_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble *,
	       xdouble *, BLASLONG, xdouble  *, BLASLONG, xdouble *, BLASLONG);
#endif

int sbgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sbgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, bfloat16 *a, BLASLONG lda, bfloat16 *b);
int sgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int sgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int dgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int dgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int cgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int zgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);

#ifdef QUAD_PRECISION
int qgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int qgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
int xgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xidouble *b);
#else
int qgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int qgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_incopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_itcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
#endif


int strsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int dtrsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);

int qtrsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int ctrsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrsm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);

int ztrsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrsm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);

int xtrsm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrsm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int strmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);
int strmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float *, float *, float *, BLASLONG, BLASLONG);

int dtrmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);
int dtrmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG, BLASLONG);

int qtrmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int qtrmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int ctrmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);
int ctrmm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, float *, float *, BLASLONG, BLASLONG);

int ztrmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);
int ztrmm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG, BLASLONG);

int xtrmm_kernel_RN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_RC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);
int xtrmm_kernel_LC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG, BLASLONG);

int strmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int strmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);

int dtrmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dtrmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);

int qtrmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qtrmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int ctrmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ctrmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);

int ztrmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int ztrmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);

int xtrmm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xtrmm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int strsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int strsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);

int dtrsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int dtrsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);

int qtrsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int qtrsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);

int ctrsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);
int ctrsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG offset, float *b);

int ztrsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);
int ztrsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG offset, double *b);

int xtrsm_iunucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iunncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iutucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iutncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ounucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ounncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_outucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_outncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ilnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_ilnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_iltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_olnucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_olnncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_oltucopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);
int xtrsm_oltncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG offset, xdouble *b);

int ssymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int ssymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int dsymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int dsymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int qsymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int qsymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int csymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int csymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int zsymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zsymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int xsymm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xsymm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int chemm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int chemm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, float *b);
int zhemm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int zhemm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, double *b);
int xhemm_iutcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_outcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_iltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);
int xhemm_oltcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG posX, BLASLONG posY, xdouble *b);

int ssyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int ssyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);

int dsyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int dsyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);

int qsyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int qsyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int csyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int csyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int zsyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zsyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int xsyrk_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xsyrk_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int ssyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int ssyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int dsyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int dsyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int qsyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int qsyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int csyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int csyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int zsyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zsyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int xsyr2k_kernel_U_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xsyr2k_kernel_L_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int cherk_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);
int cherk_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset);

int zherk_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);
int zherk_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset);

int xherk_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);
int xherk_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset);

int cher2k_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);
int cher2k_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float alpha_r, float alpha_i, float *a, float *b, float *c, BLASLONG ldc, BLASLONG offset, int flag);

int zher2k_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);
int zher2k_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double alpha_r, double alpha_i, double *a, double *b, double *c, BLASLONG ldc, BLASLONG offset, int flag);

int xher2k_kernel_UN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_UC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_LN_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);
int xher2k_kernel_LC_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, xdouble alpha_r, xdouble alpha_i, xdouble *a, xdouble *b, xdouble *c, BLASLONG ldc, BLASLONG offset, int flag);

int sbgemm_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  bfloat16 *, bfloat16 *, float *, BLASLONG);
int sgemm_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float  *, float  *, float  *, BLASLONG);
int dgemm_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xidouble *, xidouble *, xidouble *, xdouble *, BLASLONG);
#else
int qgemm_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
#endif

#ifdef SMALL_MATRIX_OPT
int sbgemm_small_matrix_permit_PRESCOTT(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float beta);

int sbgemm_small_kernel_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sbgemm_small_kernel_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);

int sgemm_small_matrix_permit_PRESCOTT(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha, float beta);

int sgemm_small_kernel_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);
int sgemm_small_kernel_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float beta, float * C, BLASLONG ldc);

int dgemm_small_matrix_permit_PRESCOTT(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, double alpha, double beta);

int dgemm_small_kernel_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);
int dgemm_small_kernel_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double beta, double * C, BLASLONG ldc);

int sbgemm_small_kernel_b0_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sbgemm_small_kernel_b0_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, bfloat16 * A, BLASLONG lda, float alpha, bfloat16 * B, BLASLONG ldb, float * C, BLASLONG ldc);

int sgemm_small_kernel_b0_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);
int sgemm_small_kernel_b0_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha, float * B, BLASLONG ldb, float * C, BLASLONG ldc);

int dgemm_small_kernel_b0_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);
int dgemm_small_kernel_b0_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha, double * B, BLASLONG ldb, double * C, BLASLONG ldc);

int cgemm_small_matrix_permit_PRESCOTT(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, float alpha0, float alpha1, float beta0, float beta1);

int cgemm_small_kernel_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_nc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
	
int cgemm_small_kernel_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_tc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int cgemm_small_kernel_rn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_rc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int cgemm_small_kernel_cn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_ct_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_cr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);
int cgemm_small_kernel_cc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb, float beta0, float beta1, float * C, BLASLONG ldc);

int zgemm_small_matrix_permit_PRESCOTT(int transa, int transb, BLASLONG m, BLASLONG n, BLASLONG k, double alpha0, double alpha1, double beta0, double beta1);

int zgemm_small_kernel_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_nc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
	
int zgemm_small_kernel_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_tc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int zgemm_small_kernel_rn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_rc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int zgemm_small_kernel_cn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_ct_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_cr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);
int zgemm_small_kernel_cc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb, double beta0, double beta1, double * C, BLASLONG ldc);

int cgemm_small_kernel_b0_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);	
int cgemm_small_kernel_b0_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_nr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_nc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
	
int cgemm_small_kernel_b0_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_tc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int cgemm_small_kernel_b0_rn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_rc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int cgemm_small_kernel_b0_cn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_ct_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_cr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);
int cgemm_small_kernel_b0_cc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, float * A, BLASLONG lda, float alpha0, float alpha1, float * B, BLASLONG ldb,  float * C, BLASLONG ldc);

int zgemm_small_kernel_b0_nn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);	
int zgemm_small_kernel_b0_nt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_nr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_nc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
	
int zgemm_small_kernel_b0_tn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_tc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

int zgemm_small_kernel_b0_rn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rt_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_rc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

int zgemm_small_kernel_b0_cn_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_ct_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_cr_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);
int zgemm_small_kernel_b0_cc_PRESCOTT(BLASLONG m, BLASLONG n, BLASLONG k, double * A, BLASLONG lda, double alpha0, double alpha1, double * B, BLASLONG ldb,  double * C, BLASLONG ldc);

#endif

int cgemm_kernel_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_l_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int cgemm_kernel_b_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);

int zgemm_kernel_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_l_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int zgemm_kernel_b_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);

int xgemm_kernel_n_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_l_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_r_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);
int xgemm_kernel_b_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,  float,  float  *, float  *, float  *, BLASLONG);
int zgemm3m_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, double *, double *, BLASLONG);
int xgemm3m_kernel_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, xdouble *, xdouble *, BLASLONG);

int sbgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);

int sgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int qgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int cgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int xgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int xgemm_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int xgemm_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int sbgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);
int sbgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, bfloat16 *, bfloat16 *, BLASLONG);

int sgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

#ifdef QUAD_PRECISION
int qgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
int qgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xidouble *, xidouble *, BLASLONG);
#else
int qgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
#endif

int cgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemm_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int zgemm3m_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int xgemm3m_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemm3m_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemm3m_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemm3m_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemm3m_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemm3m_thread_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemm3m_thread_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cher2m_LNN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LNC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LTC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LRC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_LCC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UNC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UTC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_URC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);
int cher2m_UCC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float, float, float *, BLASLONG,
	       float *, BLASLONG, float *, BLASLONG, float *, BLASLONG, BLASLONG);

int zher2m_LNN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LNC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LTC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LRC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_LCC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UNC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UTC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_URC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCN_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCT_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCR_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);
int zher2m_UCC_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double, double, double *, BLASLONG,
	       double *, BLASLONG, double *, BLASLONG, double *, BLASLONG, BLASLONG);

int strsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dtrsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qtrsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ctrsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrsm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int ztrsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrsm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xtrsm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrsm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int strmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int strmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dtrmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dtrmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qtrmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qtrmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ctrmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ctrmm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int ztrmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int ztrmm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xtrmm_LNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_LCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RNLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RTLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RRLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCUU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCUN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCLU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xtrmm_RCLN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm3m_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm3m_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm3m_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsymm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsymm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int chemm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int chemm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zhemm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zhemm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xhemm_thread_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_LL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_RU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xhemm_thread_RL_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyrk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyrk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyrk_thread_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int ssyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int ssyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dsyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dsyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qsyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qsyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int csyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int csyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zsyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zsyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xsyr2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_UT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xsyr2k_LT_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cherk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zherk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xherk_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cherk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cherk_thread_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zherk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zherk_thread_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xherk_thread_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xherk_thread_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cher2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cher2k_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zher2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zher2k_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xher2k_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_UC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xher2k_LC_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sgemt_n_PRESCOTT(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, int);
int sgemt_t_PRESCOTT(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, int);
int dgemt_n_PRESCOTT(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, int);
int dgemt_t_PRESCOTT(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, int);

int cgemt_n_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_t_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_r_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int cgemt_c_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, int);
int zgemt_n_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_t_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_r_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);
int zgemt_c_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, int);

int sgema_n_PRESCOTT(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, BLASLONG);
int sgema_t_PRESCOTT(BLASLONG, BLASLONG, float,  float   *, BLASLONG, float    *, BLASLONG);
int dgema_n_PRESCOTT(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, BLASLONG);
int dgema_t_PRESCOTT(BLASLONG, BLASLONG, double, double  *, BLASLONG, double   *, BLASLONG);

int cgema_n_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_t_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_r_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int cgema_c_PRESCOTT(BLASLONG, BLASLONG, float,  float,  float   *, BLASLONG, float    *, BLASLONG);
int zgema_n_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_t_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_r_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);
int zgema_c_PRESCOTT(BLASLONG, BLASLONG, double, double, double  *, BLASLONG, double   *, BLASLONG);

int cgemm3m_incopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_incopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_incopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);
int cgemm3m_itcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b);

int cgemm3m_oncopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_oncopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_oncopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);
int cgemm3m_otcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float alpha_r, float alpha_i, float *b);

int zgemm3m_incopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_incopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_incopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);
int zgemm3m_itcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b);

int zgemm3m_oncopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_oncopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_oncopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);
int zgemm3m_otcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double alpha_r, double alpha_i, double *b);

int xgemm3m_incopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_incopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_incopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);
int xgemm3m_itcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b);

int xgemm3m_oncopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_oncopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_oncopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xgemm3m_otcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int csymm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int csymm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);

int csymm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int csymm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);

int zsymm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zsymm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);

int zsymm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zsymm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);

int xsymm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xsymm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);

int xsymm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xsymm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int chemm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);
int chemm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float *b);

int chemm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);
int chemm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, BLASLONG x, BLASLONG y, float alpha_r, float alpha_i, float *b);

int zhemm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);
int zhemm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double *b);

int zhemm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);
int zhemm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, BLASLONG x, BLASLONG y, double alpha_r, double alpha_i, double *b);

int xhemm3m_iucopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_iucopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_iucopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);
int xhemm3m_ilcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble *b);

int xhemm3m_oucopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyb_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_oucopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyr_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_oucopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);
int xhemm3m_olcopyi_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, BLASLONG x, BLASLONG y, xdouble alpha_r, xdouble alpha_i, xdouble *b);

int sgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int sgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int dgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int dgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int qgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int qgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int cgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
int cgemc_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);

int zgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
int zgemc_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);

int xgemc_nn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_nc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_tc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rt_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_rc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cn_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_ct_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cr_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
int xgemc_cc_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int sgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int dgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int dgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int qgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int qgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int cgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int cgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, float *a, BLASLONG lda, float *b, BLASLONG ldb, float *c);
int zgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int zgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, double *a, BLASLONG lda, double *b, BLASLONG ldb, double *c);
int xgemc_oncopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);
int xgemc_otcopy_PRESCOTT(BLASLONG m, BLASLONG n, xdouble *a, BLASLONG lda, xdouble *b, BLASLONG ldb, xdouble *c);

int somatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int somatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG, float  *, BLASLONG);
int simatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG);
int simatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  float, float *, BLASLONG);

int domatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int domatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG, double  *, BLASLONG);
int dimatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG);
int dimatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  double, double *, BLASLONG);

int comatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int cimatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);

int comatcopy_k_cnc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rnc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_ctc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int comatcopy_k_rtc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG, float  *, BLASLONG);
int cimatcopy_k_cnc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rnc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_ctc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);
int cimatcopy_k_rtc_PRESCOTT(BLASLONG, BLASLONG,  float, float, float *, BLASLONG);

int zomatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zimatcopy_k_cn_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rn_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_ct_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rt_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);

int zomatcopy_k_cnc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rnc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_ctc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zomatcopy_k_rtc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG, double  *, BLASLONG);
int zimatcopy_k_cnc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rnc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_ctc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);
int zimatcopy_k_rtc_PRESCOTT(BLASLONG, BLASLONG,  double, double, double *, BLASLONG);

int sgeadd_k_PRESCOTT(BLASLONG, BLASLONG, float, float*, BLASLONG, float, float *, BLASLONG); 
int dgeadd_k_PRESCOTT(BLASLONG, BLASLONG, double, double*, BLASLONG, double, double *, BLASLONG); 
int cgeadd_k_PRESCOTT(BLASLONG, BLASLONG, float, float, float*, BLASLONG, float, float, float *, BLASLONG); 
int zgeadd_k_PRESCOTT(BLASLONG, BLASLONG, double,double, double*, BLASLONG, double, double, double *, BLASLONG); 


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
/*_PRESCOTT(INCLUDING, BUT  NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE    */
/*    GOODS  OR  SERVICES; LOSS  OF  USE,  DATA,  OR PROFITS;  OR    */
/*    BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF    */
/*    LIABILITY, WHETHER  IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*_PRESCOTT(INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY WAY OUT    */
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

blasint sgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetf2_k_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrf_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrf_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int slaswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,   float   *, BLASLONG, float  *, BLASLONG, blasint *, BLASLONG);
int slaswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,   float   *, BLASLONG, float  *, BLASLONG, blasint *, BLASLONG);
int dlaswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,  double  *, BLASLONG, double *, BLASLONG, blasint *, BLASLONG);
int dlaswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,  double  *, BLASLONG, double *, BLASLONG, blasint *, BLASLONG);
int qlaswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);
int qlaswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);

int claswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,   float,   float   *, BLASLONG, float   *, BLASLONG, blasint *, BLASLONG);
int claswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float,   float,   float   *, BLASLONG, float   *, BLASLONG, blasint *, BLASLONG);
int zlaswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,  double,  double  *, BLASLONG, double  *, BLASLONG, blasint *, BLASLONG);
int zlaswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double,  double,  double  *, BLASLONG, double  *, BLASLONG, blasint *, BLASLONG);
int xlaswp_plus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);
int xlaswp_minus_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble, xdouble, xdouble *, BLASLONG, xdouble *, BLASLONG, blasint *, BLASLONG);

int slaswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float   *, BLASLONG, blasint *, float   *);
int dlaswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double  *, BLASLONG, blasint *, double  *);
int qlaswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble *, BLASLONG, blasint *, xdouble *);
int claswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, float   *, BLASLONG, blasint *, float   *);
int zlaswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, double  *, BLASLONG, blasint *, double  *);
int xlaswp_ncopy_PRESCOTT(BLASLONG, BLASLONG, BLASLONG, xdouble *, BLASLONG, blasint *, xdouble *);

blasint sgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint sgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_R_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_C_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_R_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_C_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrs_N_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_T_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_R_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_C_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint sgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint sgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_R_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cgetrs_C_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_R_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zgetrs_C_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xgetrs_N_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_T_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_R_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xgetrs_C_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotf2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotf2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotrf_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotrf_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint spotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint spotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dpotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dpotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qpotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qpotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint cpotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint cpotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zpotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zpotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xpotrf_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xpotrf_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauu2_U_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauu2_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauum_U_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauum_L_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint slauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlauum_U_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlauum_L_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrti2_UU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_UN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_LU_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrti2_LN_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtri_UU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_UN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtri_UU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_UN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtri_LN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

int sneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, float   *, BLASLONG, float   *);
int dneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, double  *, BLASLONG, double  *);
int qneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *);
int cneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, float   *, BLASLONG, float   *);
int zneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, double  *, BLASLONG, double  *);
int xneg_tcopy_PRESCOTT(BLASLONG, BLASLONG, xdouble *, BLASLONG, xdouble *);

blasint slarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint slarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dlarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dlarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qlarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qlarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint clarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint clarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint zlarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint zlarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xlarf_L_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xlarf_R_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtrs_UNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCU_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCN_single_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

blasint strtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint strtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint dtrtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint dtrtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint qtrtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint qtrtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint ctrtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_URN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_UCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LRN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ctrtrs_LCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, float *, float *, BLASLONG);
blasint ztrtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_URN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_UCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LRN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint ztrtrs_LCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, double *, double *, BLASLONG);
blasint xtrtrs_UNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_URN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_UCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LNN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LTN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LRN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCU_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);
blasint xtrtrs_LCN_parallel_PRESCOTT(blas_arg_t *, BLASLONG *, BLASLONG *, xdouble *, xdouble *, BLASLONG);

#endif
