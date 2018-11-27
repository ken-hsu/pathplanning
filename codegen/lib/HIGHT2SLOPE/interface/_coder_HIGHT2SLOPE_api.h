/*
 * File: _coder_HIGHT2SLOPE_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:23:41
 */

#ifndef _CODER_HIGHT2SLOPE_API_H
#define _CODER_HIGHT2SLOPE_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_HIGHT2SLOPE_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void HIGHT2SLOPE(real_T hight_data[], int32_T hight_size[1], real_T
  dis_data[], int32_T dis_size[1], real_T slope_data[], int32_T slope_size[1]);
extern void HIGHT2SLOPE_api(const mxArray * const prhs[2], const mxArray *plhs[1]);
extern void HIGHT2SLOPE_atexit(void);
extern void HIGHT2SLOPE_initialize(void);
extern void HIGHT2SLOPE_terminate(void);
extern void HIGHT2SLOPE_xil_terminate(void);

#endif

/*
 * File trailer for _coder_HIGHT2SLOPE_api.h
 *
 * [EOF]
 */
