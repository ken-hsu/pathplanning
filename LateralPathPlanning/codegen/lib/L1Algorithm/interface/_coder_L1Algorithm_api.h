/*
 * File: _coder_L1Algorithm_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 03-Jan-2020 15:06:08
 */

#ifndef _CODER_L1ALGORITHM_API_H
#define _CODER_L1ALGORITHM_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_L1Algorithm_api.h"

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
extern void L1Algorithm(emxArray_real_T *waypoint_latlon, real_T L1_distance,
  real_T uavHome_latlon[2], real_T Yaw, emxArray_real_T *point_latlon);
extern void L1Algorithm_api(const mxArray *prhs[4], const mxArray *plhs[1]);
extern void L1Algorithm_atexit(void);
extern void L1Algorithm_initialize(void);
extern void L1Algorithm_terminate(void);
extern void L1Algorithm_xil_terminate(void);

#endif

/*
 * File trailer for _coder_L1Algorithm_api.h
 *
 * [EOF]
 */
