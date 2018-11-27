//
// File: calculate_distance.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:17:27
//

// Include Files
#include "rt_nonfinite.h"
#include "calculate_distance.h"
#include "calculate_distance_emxutil.h"

// Function Definitions

//
// InitLat = waypoint(1,1);
// Arguments    : const double waypoint_add_data[]
//                const int waypoint_add_size[2]
//                double num_point
//                double InitLat
//                emxArray_real_T *x_coordination
//                emxArray_real_T *dis_meter
// Return Type  : void
//
void calculate_distance(const double waypoint_add_data[], const int
  waypoint_add_size[2], double num_point, double InitLat, emxArray_real_T
  *x_coordination, emxArray_real_T *dis_meter)
{
  int i0;
  int loop_ub;
  double MetperLon;
  double a;
  double dis_latlon[2];
  double b_a;

  //  Calculate distance
  i0 = x_coordination->size[0];
  x_coordination->size[0] = (int)num_point;
  emxEnsureCapacity_real_T(x_coordination, i0);
  loop_ub = (int)num_point;
  for (i0 = 0; i0 < loop_ub; i0++) {
    x_coordination->data[i0] = 0.0;
  }

  i0 = dis_meter->size[0];
  dis_meter->size[0] = (int)(num_point - 1.0);
  emxEnsureCapacity_real_T(dis_meter, i0);
  loop_ub = (int)(num_point - 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    dis_meter->data[i0] = 0.0;
  }

  MetperLon = 111320.0 * std::cos(InitLat * 3.1415926535897931 / 180.0);

  //  meter per degree
  for (loop_ub = 0; loop_ub < (int)(num_point - 1.0); loop_ub++) {
    for (i0 = 0; i0 < 2; i0++) {
      dis_latlon[i0] = waypoint_add_data[((int)((1.0 + (double)loop_ub) + 1.0) +
        waypoint_add_size[0] * i0) - 1] - waypoint_add_data[loop_ub +
        waypoint_add_size[0] * i0];
    }

    a = dis_latlon[0] * 110574.0;
    b_a = dis_latlon[1] * MetperLon;
    dis_meter->data[loop_ub] = std::sqrt(a * a + b_a * b_a);
    x_coordination->data[(int)((1.0 + (double)loop_ub) + 1.0) - 1] =
      x_coordination->data[loop_ub] + dis_meter->data[loop_ub];
  }
}

//
// File trailer for calculate_distance.cpp
//
// [EOF]
//
