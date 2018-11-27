/*
 * File: _coder_calculate_distance2_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 27-Nov-2018 10:19:19
 */

#ifndef _CODER_CALCULATE_DISTANCE2_API_H
#define _CODER_CALCULATE_DISTANCE2_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calculate_distance2_api.h"

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
extern void calculate_distance2(real_T waypoint_lat_data[], int32_T
  waypoint_lat_size[1], real_T waypoint_lon_data[], int32_T waypoint_lon_size[1],
  real_T num_point, real_T InitLat, emxArray_real_T *x_coordination,
  emxArray_real_T *dis_meter);
extern void calculate_distance2_api(const mxArray * const prhs[4], const mxArray
  *plhs[2]);
extern void calculate_distance2_atexit(void);
extern void calculate_distance2_initialize(void);
extern void calculate_distance2_terminate(void);
extern void calculate_distance2_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calculate_distance2_api.h
 *
 * [EOF]
 */
