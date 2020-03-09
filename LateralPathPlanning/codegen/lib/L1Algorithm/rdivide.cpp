//
// File: rdivide.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
//

// Include Files
#include "rt_nonfinite.h"
#include "L1Algorithm.h"
#include "rdivide.h"
#include "L1Algorithm_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *z
// Return Type  : void
//
void rdivide(const emxArray_real_T *x, emxArray_real_T *z)
{
  int i2;
  int loop_ub;
  i2 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  emxEnsureCapacity_real_T(z, i2);
  loop_ub = x->size[0] * x->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    z->data[i2] = x->data[i2] / 6.371E+6;
  }
}

//
// File trailer for rdivide.cpp
//
// [EOF]
//
