//
// File: HIGHT2SLOPE.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:23:41
//

// Include Files
#include "rt_nonfinite.h"
#include "HIGHT2SLOPE.h"

// Function Definitions

//
// Arguments    : const double hight_data[]
//                const int hight_size[1]
//                const double dis_data[]
//                const int dis_size[1]
//                double slope_data[]
//                int slope_size[1]
// Return Type  : void
//
void HIGHT2SLOPE(const double hight_data[], const int hight_size[1], const
                 double dis_data[], const int [1], double slope_data[], int
                 slope_size[1])
{
  int loop_ub;
  slope_size[0] = hight_size[0] - 1;
  loop_ub = hight_size[0];
  if (0 <= loop_ub - 2) {
    memset(&slope_data[0], 0, (unsigned int)((loop_ub + -1) * (int)sizeof(double)));
  }

  for (loop_ub = 0; loop_ub <= hight_size[0] - 2; loop_ub++) {
    slope_data[loop_ub] = (hight_data[loop_ub + 1] - hight_data[loop_ub]) /
      dis_data[loop_ub];
  }
}

//
// File trailer for HIGHT2SLOPE.cpp
//
// [EOF]
//
