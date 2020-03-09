//
// File: norm.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
//

// Include Files
#include "rt_nonfinite.h"
#include "L1Algorithm.h"
#include "norm.h"

// Function Definitions

//
// Arguments    : const double x[2]
// Return Type  : double
//
double norm(const double x[2])
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 2; k++) {
    absxk = std::abs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

//
// File trailer for norm.cpp
//
// [EOF]
//
