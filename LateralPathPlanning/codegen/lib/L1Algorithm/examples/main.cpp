//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
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
#include "L1Algorithm.h"
#include "main.h"
#include "L1Algorithm_terminate.h"
#include "L1Algorithm_emxAPI.h"
#include "L1Algorithm_initialize.h"

// Function Declarations
static void argInit_2x1_real_T(double result[2]);
static emxArray_real_T *argInit_2xUnbounded_real_T();
static double argInit_real_T();
static void main_L1Algorithm();

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
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_2xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv0[2] = { 2, 2 };

  int idx0;
  int idx1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv0[0]);

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
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
static void main_L1Algorithm()
{
  emxArray_real_T *point_latlon;
  emxArray_real_T *waypoint_latlon;
  double dv1[2];
  emxInitArray_real_T(&point_latlon, 2);

  // Initialize function 'L1Algorithm' input arguments.
  // Initialize function input argument 'waypoint_latlon'.
  waypoint_latlon = argInit_2xUnbounded_real_T();

  // Initialize function input argument 'uavHome_latlon'.
  // Call the entry-point 'L1Algorithm'.
  argInit_2x1_real_T(dv1);
  L1Algorithm(waypoint_latlon, argInit_real_T(), dv1, argInit_real_T(),
              point_latlon);
  emxDestroyArray_real_T(point_latlon);
  emxDestroyArray_real_T(waypoint_latlon);
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
  L1Algorithm_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_L1Algorithm();

  // Terminate the application.
  // You do not need to do this more than one time.
  L1Algorithm_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
