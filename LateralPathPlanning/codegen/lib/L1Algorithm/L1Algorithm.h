//
// File: L1Algorithm.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
//
#ifndef L1ALGORITHM_H
#define L1ALGORITHM_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "L1Algorithm_types.h"

// Function Declarations
extern void L1Algorithm(emxArray_real_T *waypoint_latlon, double L1_distance,
  const double uavHome_latlon[2], double Yaw, emxArray_real_T *point_latlon);

#endif

//
// File trailer for L1Algorithm.h
//
// [EOF]
//
