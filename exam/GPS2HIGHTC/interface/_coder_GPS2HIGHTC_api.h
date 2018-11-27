/*
 * File: _coder_GPS2HIGHTC_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:19:06
 */

#ifndef _CODER_GPS2HIGHTC_API_H
#define _CODER_GPS2HIGHTC_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_GPS2HIGHTC_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void GPS2HIGHTC(real_T Latitude_data[], int32_T Latitude_size[1], real_T
  Lontitude_data[], int32_T Lontitude_size[1], int16_T map[12967201], real_T
  H_data[], int32_T H_size[1], real_T c_record_data[], int32_T c_record_size[2]);
extern void GPS2HIGHTC_api(const mxArray * const prhs[3], const mxArray *plhs[2]);
extern void GPS2HIGHTC_atexit(void);
extern void GPS2HIGHTC_initialize(void);
extern void GPS2HIGHTC_terminate(void);
extern void GPS2HIGHTC_xil_terminate(void);

#endif

/*
 * File trailer for _coder_GPS2HIGHTC_api.h
 *
 * [EOF]
 */
