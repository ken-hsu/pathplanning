//
// File: slope_judgement_emxutil.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 15:57:31
//
#ifndef SLOPE_JUDGEMENT_EMXUTIL_H
#define SLOPE_JUDGEMENT_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "slope_judgement_types.h"

// Function Declarations
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for slope_judgement_emxutil.h
//
// [EOF]
//
