//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:19:06
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "GPS2HIGHTC.h"
#include "main.h"
#include "GPS2HIGHTC_terminate.h"
#include "GPS2HIGHTC_initialize.h"

// Function Declarations
static void argInit_3601x3601_int16_T(short result[12967201]);
static void argInit_d4000x1_real_T(double result_data[], int result_size[1]);
static short argInit_int16_T();
static double argInit_real_T();
static void main_GPS2HIGHTC();

// Function Definitions

//
// Arguments    : short result[12967201]
// Return Type  : void
//
static void argInit_3601x3601_int16_T(short result[12967201])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 3601; idx0++) {
    for (idx1 = 0; idx1 < 3601; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + 3601 * idx1] = argInit_int16_T();
    }
  }
}

//
// Arguments    : double result_data[]
//                int result_size[1]
// Return Type  : void
//
static void argInit_d4000x1_real_T(double result_data[], int result_size[1])
{
  int idx0;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : short
//
static short argInit_int16_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_GPS2HIGHTC()
{
  double Latitude_data[4000];
  int Latitude_size[1];
  double Lontitude_data[4000];
  int Lontitude_size[1];
  static short iv0[12967201];
  double H_data[4000];
  int H_size[1];
  double c_record_data[8000];
  int c_record_size[2];

  // Initialize function 'GPS2HIGHTC' input arguments.
  // Initialize function input argument 'Latitude'.
  argInit_d4000x1_real_T(Latitude_data, Latitude_size);

  // Initialize function input argument 'Lontitude'.
  argInit_d4000x1_real_T(Lontitude_data, Lontitude_size);

  // Initialize function input argument 'map'.
  // Call the entry-point 'GPS2HIGHTC'.
  argInit_3601x3601_int16_T(iv0);
  GPS2HIGHTC(Latitude_data, Latitude_size, Lontitude_data, Lontitude_size, iv0,
             H_data, H_size, c_record_data, c_record_size);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  GPS2HIGHTC_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_GPS2HIGHTC();

  // Terminate the application.
  // You do not need to do this more than one time.
  GPS2HIGHTC_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
