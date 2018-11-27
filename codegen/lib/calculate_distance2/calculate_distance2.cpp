//
// File: calculate_distance2.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:19:19
//

// Include Files
#include "rt_nonfinite.h"
#include "calculate_distance2.h"
#include "calculate_distance2_emxutil.h"

// Function Definitions

//
// InitLat = waypoint(1,1);
// Arguments    : const double waypoint_lat_data[]
//                const int waypoint_lat_size[1]
//                const double waypoint_lon_data[]
//                const int waypoint_lon_size[1]
//                double num_point
//                double InitLat
//                emxArray_real_T *x_coordination
//                emxArray_real_T *dis_meter
// Return Type  : void
//
void calculate_distance2(const double waypoint_lat_data[], const int [1], const
  double waypoint_lon_data[], const int [1], double num_point, double InitLat,
  emxArray_real_T *x_coordination, emxArray_real_T *dis_meter)
{
  int i;
  int loop_ub;
  double MetperLon;
  double a;
  double b_a;

  //  Calculate distance2
  i = x_coordination->size[0];
  x_coordination->size[0] = (int)num_point;
  emxEnsureCapacity_real_T(x_coordination, i);
  loop_ub = (int)num_point;
  for (i = 0; i < loop_ub; i++) {
    x_coordination->data[i] = 0.0;
  }

  i = dis_meter->size[0];
  dis_meter->size[0] = (int)(num_point - 1.0);
  emxEnsureCapacity_real_T(dis_meter, i);
  loop_ub = (int)(num_point - 1.0);
  for (i = 0; i < loop_ub; i++) {
    dis_meter->data[i] = 0.0;
  }

  MetperLon = 111320.0 * std::cos(InitLat * 3.1415926535897931 / 180.0);

  //  meter per degree
  for (i = 0; i < (int)(num_point - 1.0); i++) {
    a = (waypoint_lat_data[(int)((1.0 + (double)i) + 1.0) - 1] -
         waypoint_lat_data[i]) * 110574.0;
    b_a = (waypoint_lon_data[(int)((1.0 + (double)i) + 1.0) - 1] -
           waypoint_lon_data[i]) * MetperLon;
    dis_meter->data[i] = std::sqrt(a * a + b_a * b_a);
    x_coordination->data[(int)((1.0 + (double)i) + 1.0) - 1] =
      x_coordination->data[i] + dis_meter->data[i];
  }
}

//
// File trailer for calculate_distance2.cpp
//
// [EOF]
//
