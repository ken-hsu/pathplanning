//
// File: function_verticalwaypoint.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 15:36:13
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "function_verticalwaypoint_emxutil.h"
#include "increase_waypoint.h"

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
// clear all;
//  %% 1
//  map = imread('ASTGTM2_N24E121_dem.tif');
//  waypoint = [24.82021,121.20231;
//              24.70202,121.40121;
//              23.60202,121.60122];
//  map = imread('ASTGTM2_N25E055_dem.tif');
//  2
//  waypoint = _IN
//              25.0983,55.5182;
//              25.4983,55.7182];
//  3
//  map = imread('ASTGTM2_N47E008_dem.tif');
//  waypoint = [25.0783,55.4982;
//              25.0883,55.5082;
//              25.0983,55.5182;
//              25.0983,55.9182];
//  Round a number
// Arguments    : const double waypoint_data[]
//                const int waypoint_size[2]
//                const short map[12967201]
//                emxArray_real_T *vertical_waypoint
//                emxArray_real_T *index_of_waypoint
//                double *num_point
// Return Type  : void
//
void function_verticalwaypoint(const double waypoint_data[], const int
  waypoint_size[2], const short map[12967201], emxArray_real_T
  *vertical_waypoint, emxArray_real_T *index_of_waypoint, double *num_point)
{
  int temp_waypoint_size[2];
  int loop_ub;
  int i0;
  int nx;
  double temp_waypoint_data[4000];
  emxArray_real_T *waypoint_add;
  emxArray_real_T *x_coordination;
  double b_num_point;
  emxArray_real_T *point_need_change;
  double MetperLon;
  int i;
  emxArray_real_T *H;
  double LonDec4p1;
  double c[2];
  double ps;
  emxArray_real_T *slope;
  int b_MetperLon;
  short varargin_1[3];
  emxArray_boolean_T *x;
  short mtmp;
  emxArray_int32_T *ii;
  int idx;
  boolean_T exitg1;
  double pf;
  emxArray_int32_T *r0;
  double param;
  int i1;
  int i2;
  temp_waypoint_size[0] = waypoint_size[0];
  loop_ub = waypoint_size[0] * waypoint_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp_waypoint_data[i0] = waypoint_data[i0] * 10000.0;
  }

  nx = waypoint_size[0] << 1;
  for (loop_ub = 0; loop_ub + 1 <= nx; loop_ub++) {
    temp_waypoint_data[loop_ub] = std::floor(temp_waypoint_data[loop_ub]);
  }

  // Round a number to 4 decimal places
  temp_waypoint_size[1] = 2;
  loop_ub = waypoint_size[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp_waypoint_data[i0] /= 10000.0;
  }

  emxInit_real_T1(&waypoint_add, 2);
  emxInit_real_T(&x_coordination, 1);

  //  Increase waypoint
  increase_waypoint(temp_waypoint_data, temp_waypoint_size, waypoint_add,
                    &b_num_point);

  //  Calculate distance
  //  InitLat = waypoint(1,1);
  //  Calculate distance
  i0 = x_coordination->size[0];
  x_coordination->size[0] = (int)b_num_point;
  emxEnsureCapacity_real_T(x_coordination, i0);
  loop_ub = (int)b_num_point;
  for (i0 = 0; i0 < loop_ub; i0++) {
    x_coordination->data[i0] = 0.0;
  }

  emxInit_real_T(&point_need_change, 1);
  i0 = point_need_change->size[0];
  point_need_change->size[0] = (int)(b_num_point - 1.0);
  emxEnsureCapacity_real_T(point_need_change, i0);
  loop_ub = (int)(b_num_point - 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    point_need_change->data[i0] = 0.0;
  }

  MetperLon = 111320.0 * std::cos(temp_waypoint_data[0] * 3.1415926535897931 /
    180.0);

  //  meter per degree
  for (i = 0; i < (int)(b_num_point - 1.0); i++) {
    for (i0 = 0; i0 < 2; i0++) {
      c[i0] = waypoint_add->data[((int)((1.0 + (double)i) + 1.0) +
        waypoint_add->size[0] * i0) - 1] - waypoint_add->data[i +
        waypoint_add->size[0] * i0];
    }

    LonDec4p1 = c[0] * 110574.0;
    ps = c[1] * MetperLon;
    point_need_change->data[i] = std::sqrt(LonDec4p1 * LonDec4p1 + ps * ps);
    x_coordination->data[(int)((1.0 + (double)i) + 1.0) - 1] =
      x_coordination->data[i] + point_need_change->data[i];
  }

  emxInit_real_T(&H, 1);

  //  get DEM data
  //  map = imread('ASTGTM2_N24E121_dem.tif');
  //      Latitude = 24.0001;
  //      Lontitude = 120.0001;
  //  GPS to HIGHT
  //  A function with a given DEM, input a GPS location, output a terrian
  //  Input double(Longitude,Altitude)
  //  Output int16(Hight)
  i0 = waypoint_add->size[0];
  loop_ub = waypoint_add->size[0];
  nx = H->size[0];
  H->size[0] = loop_ub;
  emxEnsureCapacity_real_T(H, nx);
  for (nx = 0; nx < loop_ub; nx++) {
    H->data[nx] = 0.0;
  }

  nx = index_of_waypoint->size[0] * index_of_waypoint->size[1];
  index_of_waypoint->size[0] = i0;
  index_of_waypoint->size[1] = 2;
  emxEnsureCapacity_real_T1(index_of_waypoint, nx);
  for (i = 0; i < i0; i++) {
    //  take the number after the decimal point
    MetperLon = std::floor((waypoint_add->data[i + waypoint_add->size[0]] - std::
      floor(waypoint_add->data[i + waypoint_add->size[0]])) * 10000.0);

    //  the number of 4 variable after the decimal point
    LonDec4p1 = rt_roundd_snf(MetperLon * 0.36);
    ps = rt_roundd_snf(std::floor((waypoint_add->data[i] - std::floor
      (waypoint_add->data[i])) * 10000.0) * 0.36);

    //  Index of latitude accounted from lower row to higher
    c[0] = 3602.0 - (ps + 1.0);
    c[1] = LonDec4p1 + 1.0;
    if (MetperLon * 0.36 - LonDec4p1 > 0.0) {
      b_MetperLon = 1;
    } else {
      b_MetperLon = -1;
    }

    MetperLon = (LonDec4p1 + 1.0) + (double)b_MetperLon;
    if ((MetperLon > 3601.0) || (MetperLon < 1.0)) {
      MetperLon = LonDec4p1 + 1.0;
    }

    //          H = map(c(1),c(2));
    //      H = (map(c(1),c(2))+map(c1(1),c1(2))+map(c2(1),c2(2)))/3;
    for (nx = 0; nx < 2; nx++) {
      index_of_waypoint->data[i + index_of_waypoint->size[0] * nx] = c[nx];
    }

    varargin_1[0] = map[((int)(3602.0 - (ps + 1.0)) + 3601 * ((int)(LonDec4p1 +
      1.0) - 1)) - 1];
    varargin_1[1] = map[((int)(3602.0 - (ps + 1.0)) + 3601 * ((int)(LonDec4p1 +
      1.0) - 1)) - 1];
    varargin_1[2] = map[((int)(3602.0 - (ps + 1.0)) + 3601 * ((int)MetperLon - 1))
      - 1];
    mtmp = map[((int)(3602.0 - (ps + 1.0)) + 3601 * ((int)(LonDec4p1 + 1.0) - 1))
      - 1];
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      if (varargin_1[loop_ub + 1] > mtmp) {
        mtmp = varargin_1[loop_ub + 1];
      }
    }

    H->data[i] = mtmp;
  }

  emxInit_real_T(&slope, 1);

  //  Calculate slope
  i0 = slope->size[0];
  slope->size[0] = H->size[0] - 1;
  emxEnsureCapacity_real_T(slope, i0);
  loop_ub = H->size[0];
  for (i0 = 0; i0 <= loop_ub - 2; i0++) {
    slope->data[i0] = 0.0;
  }

  for (i = 0; i <= H->size[0] - 2; i++) {
    slope->data[i] = (H->data[i + 1] - H->data[i]) / point_need_change->data[i];
  }

  //  slope judgement
  //  slope judgement
  i0 = vertical_waypoint->size[0] * vertical_waypoint->size[1];
  vertical_waypoint->size[0] = (int)b_num_point;
  vertical_waypoint->size[1] = 3;
  emxEnsureCapacity_real_T1(vertical_waypoint, i0);
  loop_ub = (int)b_num_point * 3;
  for (i0 = 0; i0 < loop_ub; i0++) {
    vertical_waypoint->data[i0] = 0.0;
  }

  emxInit_boolean_T(&x, 1);
  i0 = x->size[0];
  x->size[0] = slope->size[0];
  emxEnsureCapacity_boolean_T(x, i0);
  loop_ub = slope->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    x->data[i0] = (slope->data[i0] > 0.15);
  }

  emxInit_int32_T1(&ii, 1);
  nx = x->size[0];
  idx = 0;
  i0 = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(ii, i0);
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= nx)) {
    if (x->data[loop_ub - 1]) {
      idx++;
      ii->data[idx - 1] = loop_ub;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
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
  i0 = point_need_change->size[0];
  point_need_change->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(point_need_change, i0);
  loop_ub = ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    point_need_change->data[i0] = ii->data[i0];
  }

  ps = 0.0;
  pf = 0.0;
  i = 0;
  emxInit_int32_T(&r0, 2);
  while (i <= point_need_change->size[0] - 1) {
    MetperLon = 0.0;
    i0 = ii->size[0];
    ii->size[0] = point_need_change->size[0];
    emxEnsureCapacity_int32_T(ii, i0);
    loop_ub = point_need_change->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      ii->data[i0] = (int)point_need_change->data[i0];
    }

    param = slope->data[ii->data[i] - 1];
    while (param > 0.15) {
      MetperLon++;
      i0 = ii->size[0];
      ii->size[0] = point_need_change->size[0];
      emxEnsureCapacity_int32_T(ii, i0);
      loop_ub = point_need_change->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        ii->data[i0] = (int)point_need_change->data[i0];
      }

      ps = (double)ii->data[i] - MetperLon;
      i0 = ii->size[0];
      ii->size[0] = point_need_change->size[0];
      emxEnsureCapacity_int32_T(ii, i0);
      loop_ub = point_need_change->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        ii->data[i0] = (int)point_need_change->data[i0];
      }

      pf = (double)ii->data[i] + 1.0;

      //          if ps == 0
      //              error;
      //          end
      i0 = ii->size[0];
      ii->size[0] = point_need_change->size[0];
      emxEnsureCapacity_int32_T(ii, i0);
      loop_ub = point_need_change->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        ii->data[i0] = (int)point_need_change->data[i0];
      }

      c[0] = H->data[(int)ps - 1];
      c[1] = H->data[ii->data[i]];
      i0 = ii->size[0];
      ii->size[0] = point_need_change->size[0];
      emxEnsureCapacity_int32_T(ii, i0);
      loop_ub = point_need_change->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        ii->data[i0] = (int)point_need_change->data[i0];
      }

      param = (c[1] - c[0]) / (x_coordination->data[ii->data[i]] -
        x_coordination->data[(int)ps - 1]);
    }

    if (ps + 1.0 > pf - 1.0) {
      i0 = 1;
      nx = 0;
      i1 = 1;
      i2 = 0;
    } else {
      i0 = (int)ps + 1;
      nx = (int)(pf - 1.0);
      i1 = (int)ps + 1;
      i2 = (int)(pf - 1.0);
    }

    idx = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = (i2 - i1) + 1;
    emxEnsureCapacity_int32_T1(r0, idx);
    loop_ub = (i2 - i1) + 1;
    for (i2 = 0; i2 < loop_ub; i2++) {
      r0->data[r0->size[0] * i2] = (i1 + i2) - 1;
    }

    MetperLon = H->data[(int)ps - 1];
    i1 = ii->size[0];
    ii->size[0] = (nx - i0) + 1;
    emxEnsureCapacity_int32_T(ii, i1);
    loop_ub = nx - i0;
    for (nx = 0; nx <= loop_ub; nx++) {
      ii->data[nx] = i0 + nx;
    }

    LonDec4p1 = x_coordination->data[(int)ps - 1];
    loop_ub = r0->size[0] * r0->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      H->data[r0->data[i0]] = MetperLon + param * (x_coordination->data[ii->
        data[i0] - 1] - LonDec4p1);
    }

    // record_same_slope(i,1:point_advance) = ps+1:pf-1;
    i++;
  }

  emxFree_int32_T(&ii);
  emxFree_int32_T(&r0);
  emxFree_real_T(&point_need_change);
  emxFree_real_T(&x_coordination);
  emxFree_real_T(&slope);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = waypoint_add->size[0];
    for (nx = 0; nx < loop_ub; nx++) {
      vertical_waypoint->data[nx + vertical_waypoint->size[0] * i0] =
        waypoint_add->data[nx + waypoint_add->size[0] * i0];
    }
  }

  emxFree_real_T(&waypoint_add);
  loop_ub = H->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    vertical_waypoint->data[i0 + (vertical_waypoint->size[0] << 1)] = H->data[i0];
  }

  emxFree_real_T(&H);

  //  delete redundant point
  //  delete_matrix = ones(size(H,1),1);
  //  slope2 = HIGHT2SLOPE(vertical_waypoint(:,3),dis_meter);
  //  for i = 1:num_point-1
  //      sp = i;
  //      repeat = 1;
  //      if sp+repeat < num_point
  //          while slope2(sp) == slope2(sp+repeat)
  //              repeat = repeat + 1;
  //              if sp+repeat >= num_point
  //                  break;
  //              end
  //          end
  //      end
  //      fp = sp + repeat;
  //      if repeat > 1
  //          delete_matrix(sp+1:fp-1) = 0;
  //      end
  //  end
  //  index = find(delete_matrix == 0);
  //  x_coordination(index) = [];
  //  index_of_waypoint(index,:) = [];
  //  vertical_waypoint(index,:) = [];
  *num_point = b_num_point;
}

//
// File trailer for function_verticalwaypoint.cpp
//
// [EOF]
//
