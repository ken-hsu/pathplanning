//
// File: increase_waypoint.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 15:36:13
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "increase_waypoint.h"
#include "function_verticalwaypoint_emxutil.h"

// Function Definitions

//
// waypoint = [22.0001,120.0001;22.0004,120.0006];
// Arguments    : const double waypoint_data[]
//                const int waypoint_size[2]
//                emxArray_real_T *waypoint_add
//                double *waypoint_add_amount
// Return Type  : void
//
void increase_waypoint(const double waypoint_data[], const int waypoint_size[2],
  emxArray_real_T *waypoint_add, double *waypoint_add_amount)
{
  double step_accu;
  double b_waypoint_add_amount;
  int i;
  int i3;
  int loop_ub;
  double slope;
  double minus_latlon[2];
  double steps;
  double x;

  //  Increase waypoint
  //  waypoint = [22.0000,120.0009;22.0001,120.0007];
  step_accu = 0.0;

  //  step accumulation
  b_waypoint_add_amount = 0.0;
  for (i = 0; i <= waypoint_size[0] - 2; i++) {
    b_waypoint_add_amount += std::floor(std::abs(waypoint_data[(i +
      waypoint_size[0]) + 1] - waypoint_data[i + waypoint_size[0]]) * 10000.0);
  }

  b_waypoint_add_amount += (double)waypoint_size[0];
  i3 = waypoint_add->size[0] * waypoint_add->size[1];
  waypoint_add->size[0] = (int)b_waypoint_add_amount;
  waypoint_add->size[1] = 2;
  emxEnsureCapacity_real_T1(waypoint_add, i3);
  loop_ub = (int)b_waypoint_add_amount << 1;
  for (i3 = 0; i3 < loop_ub; i3++) {
    waypoint_add->data[i3] = 0.0;
  }

  for (i = 0; i <= waypoint_size[0] - 2; i++) {
    for (i3 = 0; i3 < 2; i3++) {
      minus_latlon[i3] = waypoint_data[(i + waypoint_size[0] * i3) + 1] -
        waypoint_data[i + waypoint_size[0] * i3];
    }

    slope = std::abs(minus_latlon[0] / minus_latlon[1]);
    steps = std::abs(std::floor(minus_latlon[1] * 10000.0));
    for (loop_ub = 0; loop_ub < (int)((steps - 1.0) + 1.0); loop_ub++) {
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

      waypoint_add->data[((int)(((double)loop_ub + 1.0) + step_accu) +
                          waypoint_add->size[0]) - 1] = waypoint_data[i +
        waypoint_size[0]] + 0.0001 * (double)loop_ub * x;
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

      waypoint_add->data[(int)(((double)loop_ub + 1.0) + step_accu) - 1] =
        waypoint_data[i] + slope * 0.0001 * (double)loop_ub * x;
    }

    step_accu += steps;
  }

  for (i3 = 0; i3 < 2; i3++) {
    waypoint_add->data[((int)(1.0 + step_accu) + waypoint_add->size[0] * i3) - 1]
      = waypoint_data[(waypoint_size[0] + waypoint_size[0] * i3) - 1];
  }

  *waypoint_add_amount = b_waypoint_add_amount;
}

//
// File trailer for increase_waypoint.cpp
//
// [EOF]
//
