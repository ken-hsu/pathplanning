//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:17:27
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
#include "calculate_distance.h"
#include "main.h"
#include "calculate_distance_terminate.h"
#include "calculate_distance_emxAPI.h"
#include "calculate_distance_initialize.h"

// Function Declarations
static void argInit_d4000x2_real_T(double result_data[], int result_size[2]);
static double argInit_real_T();
static void main_calculate_distance();

// Function Definitions

//
// Arguments    : double result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_d4000x2_real_T(double result_data[], int result_size[2])
{
  int idx0;
  int idx1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 2;
  result_size[1] = 2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result_data[idx0 + 2 * idx1] = argInit_real_T();
    }
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
static void main_calculate_distance()
{
  emxArray_real_T *x_coordination;
  emxArray_real_T *dis_meter;
  double waypoint_add_data[8000];
  int waypoint_add_size[2];
  emxInitArray_real_T(&x_coordination, 1);
  emxInitArray_real_T(&dis_meter, 1);

  // Initialize function 'calculate_distance' input arguments.
  // Initialize function input argument 'waypoint_add'.
  argInit_d4000x2_real_T(waypoint_add_data, waypoint_add_size);

  // Call the entry-point 'calculate_distance'.
  calculate_distance(waypoint_add_data, waypoint_add_size, argInit_real_T(),
                     argInit_real_T(), x_coordination, dis_meter);
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
  calculate_distance_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_calculate_distance();

  // Terminate the application.
  // You do not need to do this more than one time.
  calculate_distance_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
