//
// File: GPS2HIGHTC.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "GPS2HIGHTC.h"
#include "function_verticalwaypoint_emxutil.h"

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
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// map = imread('ASTGTM2_N24E121_dem.tif');
//      Latitude = 24.0001;
//      Lontitude = 120.0001;
// Arguments    : const emxArray_real_T *Latitude
//                const emxArray_real_T *Lontitude
//                const short map[12967201]
//                emxArray_real_T *H
//                emxArray_real_T *c_record
// Return Type  : void
//
void GPS2HIGHTC(const emxArray_real_T *Latitude, const emxArray_real_T
                *Lontitude, const short map[12967201], emxArray_real_T *H,
                emxArray_real_T *c_record)
{
  int i1;
  int loop_ub;
  int i;
  double LonDec4;
  double LonDec4p1;
  double LatDec4p1;
  double c[2];
  short varargin_1[3];
  int b_LonDec4;
  short mtmp;

  //  GPS to HIGHT
  //  A function with a given DEM, input a GPS location, output a terrian
  //  Input double(Longitude,Altitude)
  //  Output int16(Hight)
  i1 = H->size[0];
  H->size[0] = Latitude->size[0];
  emxEnsureCapacity_real_T1(H, i1);
  loop_ub = Latitude->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    H->data[i1] = 0.0;
  }

  i1 = c_record->size[0] * c_record->size[1];
  c_record->size[0] = Latitude->size[0];
  c_record->size[1] = 2;
  emxEnsureCapacity_real_T(c_record, i1);
  for (i = 0; i < Latitude->size[0]; i++) {
    //  take the number after the decimal point
    LonDec4 = floor((Lontitude->data[i] - floor(Lontitude->data[i])) * 10000.0);

    //  the number of 4 variable after the decimal point
    LonDec4p1 = rt_roundd_snf(LonDec4 * 0.36);
    LatDec4p1 = rt_roundd_snf(floor((Latitude->data[i] - floor(Latitude->data[i]))
      * 10000.0) * 0.36);

    //  Index of latitude accounted from lower row to higher
    c[0] = 3602.0 - (LatDec4p1 + 1.0);
    c[1] = LonDec4p1 + 1.0;

    //      if c1(1) > 3601 || c1(1) < 1
    //          c1(1) = c(1);
    //      end
    //      if c2(2) > 3601 || c2(2) < 1
    //          c2(2) = c(2);
    //      end
    //      H = map(c(1),c(2));
    //      H = (map(c(1),c(2))+map(c1(1),c1(2))+map(c2(1),c2(2)))/3;
    for (i1 = 0; i1 < 2; i1++) {
      c_record->data[i + c_record->size[0] * i1] = c[i1];
    }

    varargin_1[0] = map[((int)(3602.0 - (LatDec4p1 + 1.0)) + 3601 * ((int)
      (LonDec4p1 + 1.0) - 1)) - 1];
    varargin_1[1] = map[((int)(3602.0 - (LatDec4p1 + 1.0)) + 3601 * ((int)
      (LonDec4p1 + 1.0) - 1)) - 1];
    if (LonDec4 * 0.36 - LonDec4p1 > 0.0) {
      b_LonDec4 = 1;
    } else {
      b_LonDec4 = -1;
    }

    varargin_1[2] = map[((int)(3602.0 - (LatDec4p1 + 1.0)) + 3601 * ((int)
      ((LonDec4p1 + 1.0) + (double)b_LonDec4) - 1)) - 1];
    mtmp = map[((int)(3602.0 - (LatDec4p1 + 1.0)) + 3601 * ((int)(LonDec4p1 +
      1.0) - 1)) - 1];
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      if (varargin_1[loop_ub + 1] > mtmp) {
        mtmp = varargin_1[loop_ub + 1];
      }
    }

    H->data[i] = mtmp;
  }
}

//
// File trailer for GPS2HIGHTC.cpp
//
// [EOF]
//
