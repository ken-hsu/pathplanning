//
// File: floor.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "floor.h"

// Function Definitions

//
// Arguments    : emxArray_real_T *x
// Return Type  : void
//
void b_floor(emxArray_real_T *x)
{
  int nx;
  int k;
  nx = x->size[0] << 1;
  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = floor(x->data[k]);
  }
}

//
// File trailer for floor.cpp
//
// [EOF]
//
