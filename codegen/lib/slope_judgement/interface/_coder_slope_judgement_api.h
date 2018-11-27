/*
 * File: _coder_slope_judgement_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 27-Nov-2018 15:57:31
 */

#ifndef _CODER_SLOPE_JUDGEMENT_API_H
#define _CODER_SLOPE_JUDGEMENT_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_slope_judgement_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void slope_judgement(real_T H_data[], int32_T H_size[1], real_T
  slope_data[], int32_T slope_size[1], real_T x_coordination_data[], int32_T
  x_coordination_size[1], real_T num_point, real_T slope_threshold,
  emxArray_real_T *vertical_waypoint, real_T *unvalid);
extern void slope_judgement_api(const mxArray *prhs[5], const mxArray *plhs[2]);
extern void slope_judgement_atexit(void);
extern void slope_judgement_initialize(void);
extern void slope_judgement_terminate(void);
extern void slope_judgement_xil_terminate(void);

#endif

/*
 * File trailer for _coder_slope_judgement_api.h
 *
 * [EOF]
 */
