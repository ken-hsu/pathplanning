/*
 * File: _coder_function_verticalwaypoint_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 15:36:13
 */

#ifndef _CODER_FUNCTION_VERTICALWAYPOINT_API_H
#define _CODER_FUNCTION_VERTICALWAYPOINT_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_function_verticalwaypoint_api.h"

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
extern void function_verticalwaypoint(real_T waypoint_data[], int32_T
  waypoint_size[2], int16_T map[12967201], emxArray_real_T *vertical_waypoint,
  emxArray_real_T *index_of_waypoint, real_T *num_point);
extern void function_verticalwaypoint_api(const mxArray * const prhs[2], const
  mxArray *plhs[3]);
extern void function_verticalwaypoint_atexit(void);
extern void function_verticalwaypoint_initialize(void);
extern void function_verticalwaypoint_terminate(void);
extern void function_verticalwaypoint_xil_terminate(void);

#endif

/*
 * File trailer for _coder_function_verticalwaypoint_api.h
 *
 * [EOF]
 */
