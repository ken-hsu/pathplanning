//
// File: function_verticalwaypoint.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "sign.h"
#include "sqrt.h"
#include "function_verticalwaypoint_emxutil.h"
#include "nullAssignment.h"
#include "HIGHT2SLOPE.h"
#include "GPS2HIGHTC.h"
#include "floor.h"

// Function Definitions

//
// map = imread('ASTGTM2_N24E121_dem.tif');
//  waypoint = [24.92021,121.70231;
//              24.70202,121.90121;
//              24.90202,121.70122];
//  map = imread('ASTGTM2_N25E055_dem.tif');
//  waypoint = [25.0783,55.4982;
//              25.0883,55.5082;
//              25.0983,55.5182;
//              25.4983,55.7182];
// Arguments    : emxArray_real_T *waypoint
//                const short map[12967201]
//                emxArray_real_T *vertical_waypoint
//                emxArray_real_T *index_of_waypoint
// Return Type  : void
//
void function_verticalwaypoint(emxArray_real_T *waypoint, const short map
  [12967201], emxArray_real_T *vertical_waypoint, emxArray_real_T
  *index_of_waypoint)
{
  int i0;
  int nx;
  int nrows;
  double step_accu;
  double accu;
  int i;
  emxArray_real_T *waypoint_add;
  double MetperLon;
  double dis_latlon[2];
  emxArray_real_T *dis_accu;
  double ps;
  double pf;
  emxArray_real_T *dis_meter;
  emxArray_real_T *slope;
  emxArray_real_T *b_waypoint_add;
  emxArray_real_T *hight2;
  emxArray_real_T *delete_matrix;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int idx;
  boolean_T exitg1;
  emxArray_int32_T *point_need_change;
  emxArray_int32_T *r0;
  emxArray_int32_T *b_delete_matrix;
  double param;
  int nrowx;
  emxArray_real_T *b_dis_accu;
  emxArray_boolean_T *b;
  i0 = waypoint->size[0] * waypoint->size[1];
  waypoint->size[1] = 2;
  emxEnsureCapacity_real_T(waypoint, i0);
  nx = waypoint->size[0];
  nrows = waypoint->size[1];
  nx *= nrows;
  for (i0 = 0; i0 < nx; i0++) {
    waypoint->data[i0] *= 10000.0;
  }

  b_floor(waypoint);
  i0 = waypoint->size[0] * waypoint->size[1];
  waypoint->size[1] = 2;
  emxEnsureCapacity_real_T(waypoint, i0);
  nx = waypoint->size[0];
  nrows = waypoint->size[1];
  nx *= nrows;
  for (i0 = 0; i0 < nx; i0++) {
    waypoint->data[i0] /= 10000.0;
  }

  //  Increase waypoint
  step_accu = 0.0;
  accu = 0.0;
  for (i = 0; i < (int)((double)waypoint->size[0] - 1.0); i++) {
    accu += floor(fabs(waypoint->data[((int)((1.0 + (double)i) + 1.0) +
      waypoint->size[0]) - 1] - waypoint->data[i + waypoint->size[0]]) * 10000.0);
  }

  emxInit_real_T(&waypoint_add, 2);
  i0 = waypoint_add->size[0] * waypoint_add->size[1];
  waypoint_add->size[0] = (int)(accu + 1.0);
  waypoint_add->size[1] = 2;
  emxEnsureCapacity_real_T(waypoint_add, i0);
  nx = (int)(accu + 1.0) << 1;
  for (i0 = 0; i0 < nx; i0++) {
    waypoint_add->data[i0] = 0.0;
  }

  for (i = 0; i < (int)((double)waypoint->size[0] - 1.0); i++) {
    for (i0 = 0; i0 < 2; i0++) {
      dis_latlon[i0] = waypoint->data[((int)((1.0 + (double)i) + 1.0) +
        waypoint->size[0] * i0) - 1] - waypoint->data[i + waypoint->size[0] * i0];
    }

    MetperLon = fabs(dis_latlon[0] / dis_latlon[1]);
    ps = fabs(floor(dis_latlon[1] * 10000.0));
    for (nx = 0; nx < (int)((ps - 1.0) + 1.0); nx++) {
      pf = dis_latlon[1];
      b_sign(&pf);
      waypoint_add->data[((int)(((double)nx + 1.0) + step_accu) +
                          waypoint_add->size[0]) - 1] = waypoint->data[i +
        waypoint->size[0]] + 0.0001 * (double)nx * pf;
      pf = dis_latlon[0];
      b_sign(&pf);
      waypoint_add->data[(int)(((double)nx + 1.0) + step_accu) - 1] =
        waypoint->data[i] + MetperLon * 0.0001 * (double)nx * pf;
    }

    step_accu += ps;
  }

  nx = waypoint->size[0];
  for (i0 = 0; i0 < 2; i0++) {
    waypoint_add->data[((int)(1.0 + step_accu) + waypoint_add->size[0] * i0) - 1]
      = waypoint->data[(nx + waypoint->size[0] * i0) - 1];
  }

  emxInit_real_T1(&dis_accu, 1);

  //  Calculate distance
  i0 = dis_accu->size[0];
  dis_accu->size[0] = (int)(accu + 1.0);
  emxEnsureCapacity_real_T1(dis_accu, i0);
  nx = (int)(accu + 1.0);
  for (i0 = 0; i0 < nx; i0++) {
    dis_accu->data[i0] = 0.0;
  }

  emxInit_real_T1(&dis_meter, 1);
  i0 = dis_meter->size[0];
  dis_meter->size[0] = (int)accu;
  emxEnsureCapacity_real_T1(dis_meter, i0);
  nx = (int)accu;
  for (i0 = 0; i0 < nx; i0++) {
    dis_meter->data[i0] = 0.0;
  }

  MetperLon = 111320.0 * cos(waypoint->data[0] * 3.1415926535897931 / 180.0);

  //  meter per degree
  for (i = 0; i <= waypoint_add->size[0] - 2; i++) {
    for (i0 = 0; i0 < 2; i0++) {
      dis_latlon[i0] = waypoint_add->data[(i + waypoint_add->size[0] * i0) + 1]
        - waypoint_add->data[i + waypoint_add->size[0] * i0];
    }

    step_accu = dis_latlon[0] * 110574.0;
    ps = dis_latlon[1] * MetperLon;
    dis_meter->data[i] = step_accu * step_accu + ps * ps;
    b_sqrt(&dis_meter->data[i]);
    dis_accu->data[i + 1] = dis_accu->data[i] + dis_meter->data[i];
  }

  emxInit_real_T1(&slope, 1);

  //  Calculate slope
  nx = waypoint_add->size[0];
  i0 = slope->size[0];
  slope->size[0] = nx;
  emxEnsureCapacity_real_T1(slope, i0);
  for (i0 = 0; i0 < nx; i0++) {
    slope->data[i0] = waypoint_add->data[i0];
  }

  emxInit_real_T1(&b_waypoint_add, 1);
  nx = waypoint_add->size[0];
  i0 = b_waypoint_add->size[0];
  b_waypoint_add->size[0] = nx;
  emxEnsureCapacity_real_T1(b_waypoint_add, i0);
  for (i0 = 0; i0 < nx; i0++) {
    b_waypoint_add->data[i0] = waypoint_add->data[i0 + waypoint_add->size[0]];
  }

  emxInit_real_T1(&hight2, 1);
  emxInit_real_T1(&delete_matrix, 1);
  GPS2HIGHTC(slope, b_waypoint_add, map, delete_matrix, index_of_waypoint);
  HIGHT2SLOPE(delete_matrix, dis_meter, slope);

  //  slope judgement
  i0 = hight2->size[0];
  hight2->size[0] = delete_matrix->size[0];
  emxEnsureCapacity_real_T1(hight2, i0);
  nx = delete_matrix->size[0];
  emxFree_real_T(&b_waypoint_add);
  for (i0 = 0; i0 < nx; i0++) {
    hight2->data[i0] = delete_matrix->data[i0];
  }

  emxInit_boolean_T(&x, 1);
  i0 = x->size[0];
  x->size[0] = slope->size[0];
  emxEnsureCapacity_boolean_T(x, i0);
  nx = slope->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    x->data[i0] = (slope->data[i0] > 0.15);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(ii, i0);
  nrows = 1;
  exitg1 = false;
  while ((!exitg1) && (nrows <= nx)) {
    if (x->data[nrows - 1]) {
      idx++;
      ii->data[idx - 1] = nrows;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        nrows++;
      }
    } else {
      nrows++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity_int32_T(ii, i0);
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i0);
  }

  emxInit_int32_T(&point_need_change, 1);
  i0 = point_need_change->size[0];
  point_need_change->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T(point_need_change, i0);
  nx = ii->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    point_need_change->data[i0] = ii->data[i0];
  }

  ps = 0.0;
  pf = 0.0;
  i = 0;
  emxInit_int32_T1(&r0, 2);
  emxInit_int32_T(&b_delete_matrix, 1);
  while (i <= point_need_change->size[0] - 1) {
    MetperLon = 0.0;
    param = slope->data[point_need_change->data[i] - 1];
    while (param > 0.15) {
      MetperLon++;
      ps = (double)point_need_change->data[i] - MetperLon;
      pf = (double)point_need_change->data[i] + 1.0;

      //          if ps == 0
      //              error;
      //          end
      dis_latlon[0] = hight2->data[(int)ps - 1];
      dis_latlon[1] = hight2->data[point_need_change->data[i]];
      param = (dis_latlon[1] - dis_latlon[0]) / (dis_accu->
        data[point_need_change->data[i]] - dis_accu->data[(int)ps - 1]);
    }

    if (ps + 1.0 > pf - 1.0) {
      i0 = 1;
      idx = 0;
      nrows = 1;
      nrowx = 0;
    } else {
      i0 = (int)ps + 1;
      idx = (int)(pf - 1.0);
      nrows = (int)ps + 1;
      nrowx = (int)(pf - 1.0);
    }

    nx = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = (nrowx - nrows) + 1;
    emxEnsureCapacity_int32_T1(r0, nx);
    nx = (nrowx - nrows) + 1;
    for (nrowx = 0; nrowx < nx; nrowx++) {
      r0->data[r0->size[0] * nrowx] = (nrows + nrowx) - 1;
    }

    MetperLon = hight2->data[(int)ps - 1];
    nrows = b_delete_matrix->size[0];
    b_delete_matrix->size[0] = (idx - i0) + 1;
    emxEnsureCapacity_int32_T(b_delete_matrix, nrows);
    nx = idx - i0;
    for (idx = 0; idx <= nx; idx++) {
      b_delete_matrix->data[idx] = i0 + idx;
    }

    step_accu = dis_accu->data[(int)ps - 1];
    nx = r0->size[0] * r0->size[1];
    for (i0 = 0; i0 < nx; i0++) {
      hight2->data[r0->data[i0]] = MetperLon + param * (dis_accu->
        data[b_delete_matrix->data[i0] - 1] - step_accu);
    }

    // record_same_slope(i,1:point_advance) = ps+1:pf-1;
    i++;
  }

  emxFree_int32_T(&point_need_change);
  i0 = vertical_waypoint->size[0] * vertical_waypoint->size[1];
  vertical_waypoint->size[0] = (int)(accu + 1.0);
  vertical_waypoint->size[1] = 3;
  emxEnsureCapacity_real_T(vertical_waypoint, i0);
  nx = (int)(accu + 1.0) * 3;
  for (i0 = 0; i0 < nx; i0++) {
    vertical_waypoint->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 2; i0++) {
    nx = waypoint_add->size[0];
    for (idx = 0; idx < nx; idx++) {
      vertical_waypoint->data[idx + vertical_waypoint->size[0] * i0] =
        waypoint_add->data[idx + waypoint_add->size[0] * i0];
    }
  }

  nx = hight2->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    vertical_waypoint->data[i0 + (vertical_waypoint->size[0] << 1)] =
      hight2->data[i0];
  }

  //  delete redundant point
  nrows = delete_matrix->size[0];
  i0 = delete_matrix->size[0];
  delete_matrix->size[0] = nrows;
  emxEnsureCapacity_real_T1(delete_matrix, i0);
  for (i0 = 0; i0 < nrows; i0++) {
    delete_matrix->data[i0] = 1.0;
  }

  HIGHT2SLOPE(hight2, dis_meter, slope);
  i = 0;
  emxFree_real_T(&hight2);
  emxFree_real_T(&dis_meter);
  while (i <= slope->size[0] - 2) {
    for (MetperLon = 1.0; slope->data[i] == slope->data[(int)((1.0 + (double)i)
          + MetperLon) - 1]; MetperLon++) {
    }

    step_accu = (1.0 + (double)i) + MetperLon;
    if (MetperLon > 1.0) {
      if ((1.0 + (double)i) + 1.0 > step_accu - 1.0) {
        i0 = 1;
        idx = 0;
      } else {
        i0 = i + 2;
        idx = (int)(step_accu - 1.0);
      }

      nrows = r0->size[0] * r0->size[1];
      r0->size[0] = 1;
      r0->size[1] = (idx - i0) + 1;
      emxEnsureCapacity_int32_T1(r0, nrows);
      nx = (idx - i0) + 1;
      for (idx = 0; idx < nx; idx++) {
        r0->data[r0->size[0] * idx] = (i0 + idx) - 1;
      }

      nx = r0->size[0] * r0->size[1];
      for (i0 = 0; i0 < nx; i0++) {
        delete_matrix->data[r0->data[i0]] = 0.0;
      }
    }

    i++;
  }

  emxFree_int32_T(&r0);
  emxFree_real_T(&slope);
  i0 = x->size[0];
  x->size[0] = delete_matrix->size[0];
  emxEnsureCapacity_boolean_T(x, i0);
  nx = delete_matrix->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    x->data[i0] = (delete_matrix->data[i0] == 0.0);
  }

  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(ii, i0);
  nrows = 1;
  exitg1 = false;
  while ((!exitg1) && (nrows <= nx)) {
    if (x->data[nrows - 1]) {
      idx++;
      ii->data[idx - 1] = nrows;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        nrows++;
      }
    } else {
      nrows++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      i0 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity_int32_T(ii, i0);
    }
  } else {
    i0 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i0);
  }

  emxFree_boolean_T(&x);
  i0 = delete_matrix->size[0];
  delete_matrix->size[0] = ii->size[0];
  emxEnsureCapacity_real_T1(delete_matrix, i0);
  nx = ii->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    delete_matrix->data[i0] = ii->data[i0];
  }

  i0 = b_delete_matrix->size[0];
  b_delete_matrix->size[0] = delete_matrix->size[0];
  emxEnsureCapacity_int32_T(b_delete_matrix, i0);
  nx = delete_matrix->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    b_delete_matrix->data[i0] = (int)delete_matrix->data[i0];
  }

  emxInit_real_T1(&b_dis_accu, 1);
  nullAssignment(dis_accu, b_delete_matrix, b_dis_accu);
  i0 = ii->size[0];
  ii->size[0] = delete_matrix->size[0];
  emxEnsureCapacity_int32_T(ii, i0);
  nx = delete_matrix->size[0];
  emxFree_real_T(&b_dis_accu);
  emxFree_real_T(&dis_accu);
  for (i0 = 0; i0 < nx; i0++) {
    ii->data[i0] = (int)delete_matrix->data[i0];
  }

  nrowx = index_of_waypoint->size[0];
  if (ii->size[0] == 1) {
    nrows = index_of_waypoint->size[0] - 1;
    for (nx = 0; nx < 2; nx++) {
      for (i = ii->data[0]; i < nrowx; i++) {
        index_of_waypoint->data[(i + index_of_waypoint->size[0] * nx) - 1] =
          index_of_waypoint->data[i + index_of_waypoint->size[0] * nx];
      }
    }
  } else {
    emxInit_boolean_T1(&b, 2);
    i0 = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = index_of_waypoint->size[0];
    emxEnsureCapacity_boolean_T1(b, i0);
    nx = index_of_waypoint->size[0];
    for (i0 = 0; i0 < nx; i0++) {
      b->data[i0] = false;
    }

    for (idx = 1; idx <= ii->size[0]; idx++) {
      b->data[ii->data[idx - 1] - 1] = true;
    }

    nrows = 0;
    for (idx = 1; idx <= b->size[1]; idx++) {
      nrows += b->data[idx - 1];
    }

    nrows = index_of_waypoint->size[0] - nrows;
    i = 0;
    for (idx = 1; idx <= nrowx; idx++) {
      if ((idx > b->size[1]) || (!b->data[idx - 1])) {
        for (nx = 0; nx < 2; nx++) {
          index_of_waypoint->data[i + index_of_waypoint->size[0] * nx] =
            index_of_waypoint->data[(idx + index_of_waypoint->size[0] * nx) - 1];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  emxFree_int32_T(&ii);
  if (1 > nrows) {
    nx = 0;
  } else {
    nx = nrows;
  }

  i0 = waypoint_add->size[0] * waypoint_add->size[1];
  waypoint_add->size[0] = nx;
  waypoint_add->size[1] = 2;
  emxEnsureCapacity_real_T(waypoint_add, i0);
  for (i0 = 0; i0 < 2; i0++) {
    for (idx = 0; idx < nx; idx++) {
      waypoint_add->data[idx + waypoint_add->size[0] * i0] =
        index_of_waypoint->data[idx + index_of_waypoint->size[0] * i0];
    }
  }

  i0 = index_of_waypoint->size[0] * index_of_waypoint->size[1];
  index_of_waypoint->size[0] = waypoint_add->size[0];
  index_of_waypoint->size[1] = 2;
  emxEnsureCapacity_real_T(index_of_waypoint, i0);
  for (i0 = 0; i0 < 2; i0++) {
    nx = waypoint_add->size[0];
    for (idx = 0; idx < nx; idx++) {
      index_of_waypoint->data[idx + index_of_waypoint->size[0] * i0] =
        waypoint_add->data[idx + waypoint_add->size[0] * i0];
    }
  }

  emxFree_real_T(&waypoint_add);
  i0 = b_delete_matrix->size[0];
  b_delete_matrix->size[0] = delete_matrix->size[0];
  emxEnsureCapacity_int32_T(b_delete_matrix, i0);
  nx = delete_matrix->size[0];
  for (i0 = 0; i0 < nx; i0++) {
    b_delete_matrix->data[i0] = (int)delete_matrix->data[i0];
  }

  emxFree_real_T(&delete_matrix);
  c_nullAssignment(vertical_waypoint, b_delete_matrix);
  emxFree_int32_T(&b_delete_matrix);
}

//
// File trailer for function_verticalwaypoint.cpp
//
// [EOF]
//
