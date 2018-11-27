/*
 * File: _coder_increase_waypoint2_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 27-Nov-2018 10:12:04
 */

#ifndef _CODER_INCREASE_WAYPOINT2_API_H
#define _CODER_INCREASE_WAYPOINT2_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_increase_waypoint2_api.h"

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
extern void increase_waypoint2(real_T lat[2], real_T lon[2], emxArray_real_T
  *waypoint_add_lat, emxArray_real_T *waypoint_add_lon, real_T
  *waypoint_add_amount);
extern void increase_waypoint2_api(const mxArray * const prhs[2], const mxArray *
  plhs[3]);
extern void increase_waypoint2_atexit(void);
extern void increase_waypoint2_initialize(void);
extern void increase_waypoint2_terminate(void);
extern void increase_waypoint2_xil_terminate(void);

#endif

/*
 * File trailer for _coder_increase_waypoint2_api.h
 *
 * [EOF]
 */
