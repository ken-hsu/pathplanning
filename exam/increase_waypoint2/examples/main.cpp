//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 10:12:04
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
#include "increase_waypoint2.h"
#include "main.h"
#include "increase_waypoint2_terminate.h"
#include "increase_waypoint2_emxAPI.h"
#include "increase_waypoint2_initialize.h"

// Function Declarations
static void argInit_2x1_real_T(double result[2]);
static double argInit_real_T();
static void main_increase_waypoint2();

// Function Definitions

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_2x1_real_T(double result[2])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
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
static void main_increase_waypoint2()
{
  emxArray_real_T *waypoint_add_lat;
  emxArray_real_T *waypoint_add_lon;
  double dv0[2];
  double dv1[2];
  double waypoint_add_amount;
  emxInitArray_real_T(&waypoint_add_lat, 1);
  emxInitArray_real_T(&waypoint_add_lon, 1);

  // Initialize function 'increase_waypoint2' input arguments.
  // Initialize function input argument 'lat'.
  // Initialize function input argument 'lon'.
  // Call the entry-point 'increase_waypoint2'.
  argInit_2x1_real_T(dv0);
  argInit_2x1_real_T(dv1);
  increase_waypoint2(dv0, dv1, waypoint_add_lat, waypoint_add_lon,
                     &waypoint_add_amount);
  emxDestroyArray_real_T(waypoint_add_lon);
  emxDestroyArray_real_T(waypoint_add_lat);
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
  increase_waypoint2_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_increase_waypoint2();

  // Terminate the application.
  // You do not need to do this more than one time.
  increase_waypoint2_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
