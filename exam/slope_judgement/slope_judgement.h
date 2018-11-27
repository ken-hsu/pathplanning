//
// File: slope_judgement.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 15:57:31
//
#ifndef SLOPE_JUDGEMENT_H
#define SLOPE_JUDGEMENT_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "slope_judgement_types.h"

// Function Declarations
extern void slope_judgement(double H_data[], int H_size[1], const double
  slope_data[], const int slope_size[1], const double x_coordination_data[],
  const int x_coordination_size[1], double num_point, double slope_threshold,
  emxArray_real_T *vertical_waypoint, double *unvalid);

#endif

//
// File trailer for slope_judgement.h
//
// [EOF]
//
