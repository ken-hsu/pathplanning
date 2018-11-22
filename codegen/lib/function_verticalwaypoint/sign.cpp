//
// File: sign.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "sign.h"

// Function Definitions

//
// Arguments    : double *x
// Return Type  : void
//
void b_sign(double *x)
{
  if (*x < 0.0) {
    *x = -1.0;
  } else if (*x > 0.0) {
    *x = 1.0;
  } else {
    if (*x == 0.0) {
      *x = 0.0;
    }
  }
}

//
// File trailer for sign.cpp
//
// [EOF]
//
