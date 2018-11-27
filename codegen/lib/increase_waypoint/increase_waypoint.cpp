//
// File: increase_waypoint.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 16:14:28
//

// Include Files
#include "rt_nonfinite.h"
#include "increase_waypoint.h"
#include "increase_waypoint_emxutil.h"

// Function Definitions

//
// waypoint = [22.0001,120.0001;22.0004,120.0006];
// Arguments    : const double waypoint[4]
//                emxArray_real_T *waypoint_add
//                double *waypoint_add_amount
// Return Type  : void
//
void increase_waypoint(const double waypoint[4], emxArray_real_T *waypoint_add,
  double *waypoint_add_amount)
{
  double step_temp;
  int j;
  int loop_ub;
  double slope;
  double minus_latlon[2];
  double steps;
  double x;

  //  Increase waypoint
  //  waypoint = [22.0000,120.0009;22.0001,120.0007];
  //  step accumulation
  step_temp = std::floor(std::abs(waypoint[3] - waypoint[2]) * 10000.0);
  j = waypoint_add->size[0] * waypoint_add->size[1];
  waypoint_add->size[0] = (int)(2.0 + step_temp);
  waypoint_add->size[1] = 2;
  emxEnsureCapacity_real_T(waypoint_add, j);
  loop_ub = (int)(2.0 + step_temp) << 1;
  for (j = 0; j < loop_ub; j++) {
    waypoint_add->data[j] = 0.0;
  }

  for (j = 0; j < 2; j++) {
    minus_latlon[j] = waypoint[1 + (j << 1)] - waypoint[j << 1];
  }

  slope = std::abs(minus_latlon[0] / minus_latlon[1]);
  steps = std::abs(std::floor(minus_latlon[1] * 10000.0));
  for (j = 0; j < (int)((steps - 1.0) + 1.0); j++) {
    x = minus_latlon[1];
    if (minus_latlon[1] < 0.0) {
      x = -1.0;
    } else if (minus_latlon[1] > 0.0) {
      x = 1.0;
    } else {
      if (minus_latlon[1] == 0.0) {
        x = 0.0;
      }
    }

    waypoint_add->data[j + waypoint_add->size[0]] = waypoint[2] + 0.0001 *
      (double)j * x;
    x = minus_latlon[0];
    if (minus_latlon[0] < 0.0) {
      x = -1.0;
    } else if (minus_latlon[0] > 0.0) {
      x = 1.0;
    } else {
      if (minus_latlon[0] == 0.0) {
        x = 0.0;
      }
    }

    waypoint_add->data[j] = waypoint[0] + slope * 0.0001 * (double)j * x;
  }

  for (j = 0; j < 2; j++) {
    waypoint_add->data[((int)(1.0 + steps) + waypoint_add->size[0] * j) - 1] =
      waypoint[1 + (j << 1)];
  }

  *waypoint_add_amount = 2.0 + step_temp;
}

//
// File trailer for increase_waypoint.cpp
//
// [EOF]
//
