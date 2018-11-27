//
// File: calculate_distance2.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:19:19
//
#ifndef CALCULATE_DISTANCE2_H
#define CALCULATE_DISTANCE2_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "calculate_distance2_types.h"

// Function Declarations
extern void calculate_distance2(const double waypoint_lat_data[], const int
  waypoint_lat_size[1], const double waypoint_lon_data[], const int
  waypoint_lon_size[1], double num_point, double InitLat, emxArray_real_T
  *x_coordination, emxArray_real_T *dis_meter);

#endif

//
// File trailer for calculate_distance2.h
//
// [EOF]
//
