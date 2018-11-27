/*
 * File: _coder_increase_waypoint_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 16:14:28
 */

#ifndef _CODER_INCREASE_WAYPOINT_API_H
#define _CODER_INCREASE_WAYPOINT_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_increase_waypoint_api.h"

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
extern void increase_waypoint(real_T waypoint[4], emxArray_real_T *waypoint_add,
  real_T *waypoint_add_amount);
extern void increase_waypoint_api(const mxArray * const prhs[1], const mxArray
  *plhs[2]);
extern void increase_waypoint_atexit(void);
extern void increase_waypoint_initialize(void);
extern void increase_waypoint_terminate(void);
extern void increase_waypoint_xil_terminate(void);

#endif

/*
 * File trailer for _coder_increase_waypoint_api.h
 *
 * [EOF]
 */
