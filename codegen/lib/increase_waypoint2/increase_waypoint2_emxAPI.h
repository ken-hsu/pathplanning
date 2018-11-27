//
// File: increase_waypoint2_emxAPI.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:12:04
//
#ifndef INCREASE_WAYPOINT2_EMXAPI_H
#define INCREASE_WAYPOINT2_EMXAPI_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "increase_waypoint2_types.h"

// Function Declarations
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for increase_waypoint2_emxAPI.h
//
// [EOF]
//
