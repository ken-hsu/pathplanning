//
// File: GPS2HIGHTC.h
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:19:06
//
#ifndef GPS2HIGHTC_H
#define GPS2HIGHTC_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "GPS2HIGHTC_types.h"

// Function Declarations
extern void GPS2HIGHTC(const double Latitude_data[], const int Latitude_size[1],
  const double Lontitude_data[], const int Lontitude_size[1], const short map
  [12967201], double H_data[], int H_size[1], double c_record_data[], int
  c_record_size[2]);

#endif

//
// File trailer for GPS2HIGHTC.h
//
// [EOF]
//
