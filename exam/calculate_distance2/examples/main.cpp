//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:19:19
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
#include "calculate_distance2.h"
#include "main.h"
#include "calculate_distance2_terminate.h"
#include "calculate_distance2_emxAPI.h"
#include "calculate_distance2_initialize.h"

// Function Declarations
static void argInit_d2000x1_real_T(double result_data[], int result_size[1]);
static double argInit_real_T();
static void main_calculate_distance2();

// Function Definitions

//
// Arguments    : double result_data[]
//                int result_size[1]
// Return Type  : void
//
static void argInit_d2000x1_real_T(double result_data[], int result_size[1])
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
static void main_calculate_distance2()
{
  emxArray_real_T *x_coordination;
  emxArray_real_T *dis_meter;
  double waypoint_lat_data[2000];
  int waypoint_lat_size[1];
  double waypoint_lon_data[2000];
  int waypoint_lon_size[1];
  emxInitArray_real_T(&x_coordination, 1);
  emxInitArray_real_T(&dis_meter, 1);

  // Initialize function 'calculate_distance2' input arguments.
  // Initialize function input argument 'waypoint_lat'.
  argInit_d2000x1_real_T(waypoint_lat_data, waypoint_lat_size);

  // Initialize function input argument 'waypoint_lon'.
  argInit_d2000x1_real_T(waypoint_lon_data, waypoint_lon_size);

  // Call the entry-point 'calculate_distance2'.
  calculate_distance2(waypoint_lat_data, waypoint_lat_size, waypoint_lon_data,
                      waypoint_lon_size, argInit_real_T(), argInit_real_T(),
                      x_coordination, dis_meter);
  emxDestroyArray_real_T(dis_meter);
  emxDestroyArray_real_T(x_coordination);
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
  calculate_distance2_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_calculate_distance2();

  // Terminate the application.
  // You do not need to do this more than one time.
  calculate_distance2_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
