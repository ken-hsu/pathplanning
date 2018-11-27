//
// File: slope_judgement.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 15:57:31
//

// Include Files
#include "rt_nonfinite.h"
#include "slope_judgement.h"
#include "slope_judgement_emxutil.h"

// Function Definitions

//
// Arguments    : double H_data[]
//                int H_size[1]
//                const double slope_data[]
//                const int slope_size[1]
//                const double x_coordination_data[]
//                const int x_coordination_size[1]
//                double num_point
//                double slope_threshold
//                emxArray_real_T *vertical_waypoint
//                double *unvalid
// Return Type  : void
//
void slope_judgement(double H_data[], int [1], const double slope_data[], const
                     int slope_size[1], const double x_coordination_data[],
                     const int [1], double num_point, double slope_threshold,
                     emxArray_real_T *vertical_waypoint, double *unvalid)
{
  int i0;
  int nx;
  int b_unvalid;
  boolean_T x_data[4000];
  int idx;
  int ii_size_idx_0;
  int ii;
  boolean_T exitg1;
  int ii_data[4000];
  int point_need_change_data[4000];
  double ps;
  double pf;
  emxArray_int32_T *r0;
  double point_advance;
  double param;
  int i1;
  int i2;
  int i3;
  short tmp_data[4000];

  //  slope judgement
  i0 = vertical_waypoint->size[0];
  vertical_waypoint->size[0] = (int)num_point;
  emxEnsureCapacity_real_T(vertical_waypoint, i0);
  nx = (int)num_point;
  for (i0 = 0; i0 < nx; i0++) {
    vertical_waypoint->data[i0] = 0.0;
  }

  b_unvalid = 0;
  nx = slope_size[0];
  for (i0 = 0; i0 < nx; i0++) {
    x_data[i0] = (slope_data[i0] > slope_threshold);
  }

  nx = slope_size[0];
  idx = 0;
  ii_size_idx_0 = slope_size[0];
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (slope_size[0] == 1) {
    if (idx == 0) {
      ii_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  if (0 <= ii_size_idx_0 - 1) {
    memcpy(&point_need_change_data[0], &ii_data[0], (unsigned int)(ii_size_idx_0
            * (int)sizeof(int)));
  }

  ps = 0.0;
  pf = 0.0;
  for (idx = 0; idx < ii_size_idx_0; idx++) {
    point_advance = 0.0;
    param = slope_data[point_need_change_data[idx] - 1];
    exitg1 = false;
    while ((!exitg1) && (param > slope_threshold)) {
      point_advance++;
      ps = (double)point_need_change_data[idx] - point_advance;
      pf = (double)point_need_change_data[idx] + 1.0;
      if (ps <= 0.0) {
        b_unvalid = 1;
        ps = 1.0;
        exitg1 = true;
      } else {
        param = (H_data[point_need_change_data[idx]] - H_data[(int)ps - 1]) /
          (x_coordination_data[point_need_change_data[idx]] -
           x_coordination_data[(int)ps - 1]);
      }
    }

    if (ps + 1.0 > pf - 1.0) {
      i0 = 1;
      ii = 0;
      i1 = 1;
      i2 = 0;
    } else {
      i0 = (int)ps + 1;
      ii = (int)(pf - 1.0);
      i1 = (int)ps + 1;
      i2 = (int)(pf - 1.0);
    }

    nx = (short)((short)i2 - (short)i1);
    for (i3 = 0; i3 <= nx; i3++) {
      tmp_data[i3] = (short)((short)((short)i1 + i3) - 1);
    }

    point_advance = H_data[(int)ps - 1];
    nx = ii - i0;
    for (ii = 0; ii <= nx; ii++) {
      ii_data[ii] = i0 + ii;
    }

    nx = (short)((short)i2 - (short)i1) + 1;
    for (i0 = 0; i0 < nx; i0++) {
      H_data[tmp_data[i0]] = point_advance + param *
        (x_coordination_data[ii_data[i0] - 1] - x_coordination_data[(int)ps - 1]);
    }

    // record_same_slope(i,1:point_advance) = ps+1:pf-1;
  }

  emxInit_int32_T(&r0, 1);
  i0 = r0->size[0];
  r0->size[0] = (int)num_point;
  emxEnsureCapacity_int32_T(r0, i0);
  nx = (int)num_point;
  for (i0 = 0; i0 < nx; i0++) {
    r0->data[i0] = i0;
  }

  nx = r0->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    vertical_waypoint->data[r0->data[i0]] = H_data[i0];
  }

  emxFree_int32_T(&r0);
  *unvalid = b_unvalid;
}

//
// File trailer for slope_judgement.cpp
//
// [EOF]
//
