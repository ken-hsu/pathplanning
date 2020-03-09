//
// File: L1Algorithm_emxutil.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
//
#ifndef L1ALGORITHM_EMXUTIL_H
#define L1ALGORITHM_EMXUTIL_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "L1Algorithm_types.h"

// Function Declarations
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for L1Algorithm_emxutil.h
//
// [EOF]
//
