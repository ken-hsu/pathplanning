//
// File: GPS2HIGHTC.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:19:06
//

// Include Files
#include "rt_nonfinite.h"
#include "GPS2HIGHTC.h"

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
// map = imread('ASTGTM2_N24E121_dem.tif');
//      Latitude = 24.0001;
//      Lontitude = 120.0001;
// Arguments    : const double Latitude_data[]
//                const int Latitude_size[1]
//                const double Lontitude_data[]
//                const int Lontitude_size[1]
//                const short map[12967201]
//                double H_data[]
//                int H_size[1]
//                double c_record_data[]
//                int c_record_size[2]
// Return Type  : void
//
void GPS2HIGHTC(const double Latitude_data[], const int Latitude_size[1], const
                double Lontitude_data[], const int [1], const short map[12967201],
                double H_data[], int H_size[1], double c_record_data[], int
                c_record_size[2])
{
  int loop_ub;
  double LonDec4;
  double LonDec4p1;
  double LatDec4p1;
  double c[2];
  int b_LonDec4;
  short varargin_1[3];
  short mtmp;
  int ix;

  //  GPS to HIGHT
  //  A function with a given DEM, input a GPS location, output a terrian
  //  Input double(Longitude,Altitude)
  //  Output int16(Hight)
  H_size[0] = Latitude_size[0];
  loop_ub = Latitude_size[0];
  if (0 <= loop_ub - 1) {
    memset(&H_data[0], 0, (unsigned int)(loop_ub * (int)sizeof(double)));
  }

  c_record_size[0] = Latitude_size[0];
  c_record_size[1] = 2;
  for (loop_ub = 0; loop_ub < Latitude_size[0]; loop_ub++) {
    //  take the number after the decimal point
    LonDec4 = std::floor((Lontitude_data[loop_ub] - std::floor
                          (Lontitude_data[loop_ub])) * 10000.0);

    //  the number of 4 variable after the decimal point
    LonDec4p1 = rt_roundd_snf(LonDec4 * 0.36);
    LatDec4p1 = rt_roundd_snf(std::floor((Latitude_data[loop_ub] - std::floor
      (Latitude_data[loop_ub])) * 10000.0) * 0.36);

    //  Index of latitude accounted from lower row to higher
    c[0] = 3602.0 - (LatDec4p1 + 1.0);
    c[1] = LonDec4p1 + 1.0;
    if (LonDec4 * 0.36 - LonDec4p1 > 0.0) {
      b_LonDec4 = 1;
    } else {
      b_LonDec4 = -1;
    }

    LonDec4 = (LonDec4p1 + 1.0) + (double)b_LonDec4;
    if ((LonDec4 > 3601.0) || (LonDec4 < 1.0)) {
      LonDec4 = LonDec4p1 + 1.0;
    }

    //          H = map(c(1),c(2));
    //      H = (map(c(1),c(2))+map(c1(1),c1(2))+map(c2(1),c2(2)))/3;
    varargin_1[0] = map[((int)(3602.0 - (LatDec4p1 + 1.0) - 1.0)*3601 + ((int)
      (LonDec4p1 + 1.0))) - 1];
    varargin_1[1] = map[((int)(3602.0 - (LatDec4p1 + 1.0) - 1.0)*3601 + ((int)
      (LonDec4p1 + 1.0))) - 1];
    varargin_1[2] = map[((int)(3602.0 - (LatDec4p1 + 1.0) - 1.0)*3601 + ((int)
      LonDec4)) - 1];
    mtmp = map[((int)(3602.0 - (LatDec4p1 + 1.0) - 1.0)*3601 + ((int)(LonDec4p1 +
      1.0))) - 1];
    for (ix = 0; ix < 2; ix++) {
      c_record_data[loop_ub + c_record_size[0] * ix] = c[ix];
      if (varargin_1[ix + 1] > mtmp) {
        mtmp = varargin_1[ix + 1];
      }
    }

    H_data[loop_ub] = mtmp;
  }
}

//
// File trailer for GPS2HIGHTC.cpp
//
// [EOF]
//
