//
// File: increase_waypoint2.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:12:04
//

// Include Files
#include "rt_nonfinite.h"
#include "increase_waypoint2.h"
#include "increase_waypoint2_emxutil.h"

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// lat = [22.0001;22.0004];
//  lon = [120.0001;120.0004];
// Arguments    : const double lat[2]
//                const double lon[2]
//                emxArray_real_T *waypoint_add_lat
//                emxArray_real_T *waypoint_add_lon
//                double *waypoint_add_amount
// Return Type  : void
//
void increase_waypoint2(const double lat[2], const double lon[2],
  emxArray_real_T *waypoint_add_lat, emxArray_real_T *waypoint_add_lon, double
  *waypoint_add_amount)
{
  double step;
  int j;
  int loop_ub;
  double slope;
  double x;

  //  Increase waypoint2
  //  waypoint = [22.0000,120.0009;22.0001,120.0007];
  step = rt_roundd_snf(std::abs(lon[1] - lon[0]) * 10000.0);
  j = waypoint_add_lat->size[0];
  waypoint_add_lat->size[0] = (int)(step + 1.0);
  emxEnsureCapacity_real_T(waypoint_add_lat, j);
  loop_ub = (int)(step + 1.0);
  for (j = 0; j < loop_ub; j++) {
    waypoint_add_lat->data[j] = 0.0;
  }

  j = waypoint_add_lon->size[0];
  waypoint_add_lon->size[0] = (int)(step + 1.0);
  emxEnsureCapacity_real_T(waypoint_add_lon, j);
  loop_ub = (int)(step + 1.0);
  for (j = 0; j < loop_ub; j++) {
    waypoint_add_lon->data[j] = 0.0;
  }

  slope = std::abs((lat[1] - lat[0]) / (lon[1] - lon[0]));
  for (j = 0; j < (int)((step - 1.0) + 1.0); j++) {
    x = lon[1] - lon[0];
    if (x < 0.0) {
      x = -1.0;
    } else if (x > 0.0) {
      x = 1.0;
    } else {
      if (x == 0.0) {
        x = 0.0;
      }
    }

    waypoint_add_lon->data[j] = lon[0] + 0.0001 * (double)j * x;
    x = lat[1] - lat[0];
    if (x < 0.0) {
      x = -1.0;
    } else if (x > 0.0) {
      x = 1.0;
    } else {
      if (x == 0.0) {
        x = 0.0;
      }
    }

    waypoint_add_lat->data[j] = lat[0] + slope * 0.0001 * (double)j * x;
  }

  waypoint_add_lat->data[(int)(step + 1.0) - 1] = lat[1];
  waypoint_add_lon->data[(int)(step + 1.0) - 1] = lon[1];
  *waypoint_add_amount = step + 1.0;
}

//
// File trailer for increase_waypoint2.cpp
//
// [EOF]
//
