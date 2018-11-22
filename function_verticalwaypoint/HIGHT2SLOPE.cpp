//
// File: HIGHT2SLOPE.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "HIGHT2SLOPE.h"
#include "function_verticalwaypoint_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *hight
//                const emxArray_real_T *dis
//                emxArray_real_T *slope
// Return Type  : void
//
void HIGHT2SLOPE(const emxArray_real_T *hight, const emxArray_real_T *dis,
                 emxArray_real_T *slope)
{
  int i;
  int loop_ub;
  i = slope->size[0];
  slope->size[0] = hight->size[0] - 1;
  emxEnsureCapacity_real_T1(slope, i);
  loop_ub = hight->size[0];
  for (i = 0; i <= loop_ub - 2; i++) {
    slope->data[i] = 0.0;
  }

  for (i = 0; i <= hight->size[0] - 2; i++) {
    slope->data[i] = (hight->data[i + 1] - hight->data[i]) / dis->data[i];
  }
}

//
// File trailer for HIGHT2SLOPE.cpp
//
// [EOF]
//
