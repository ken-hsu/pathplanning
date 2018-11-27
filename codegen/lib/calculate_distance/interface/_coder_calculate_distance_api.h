/*
 * File: _coder_calculate_distance_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:17:27
 */

#ifndef _CODER_CALCULATE_DISTANCE_API_H
#define _CODER_CALCULATE_DISTANCE_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calculate_distance_api.h"

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
extern void calculate_distance(real_T waypoint_add_data[], int32_T
  waypoint_add_size[2], real_T num_point, real_T InitLat, emxArray_real_T
  *x_coordination, emxArray_real_T *dis_meter);
extern void calculate_distance_api(const mxArray * const prhs[3], const mxArray *
  plhs[2]);
extern void calculate_distance_atexit(void);
extern void calculate_distance_initialize(void);
extern void calculate_distance_terminate(void);
extern void calculate_distance_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calculate_distance_api.h
 *
 * [EOF]
 */
