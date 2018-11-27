//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 27-Nov-2018 15:57:31
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
#include "slope_judgement.h"
#include "main.h"
#include "slope_judgement_terminate.h"
#include "slope_judgement_emxAPI.h"
#include "slope_judgement_initialize.h"

// Function Declarations
static void argInit_d4000x1_real_T(double result_data[], int result_size[1]);
static double argInit_real_T();
static void main_slope_judgement();

// Function Definitions

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
static void main_slope_judgement()
{
  emxArray_real_T *vertical_waypoint;
  double H_data[4000];
  int H_size[1];
  double slope_data[4000];
  int slope_size[1];
  double x_coordination_data[4000];
  int x_coordination_size[1];
  double unvalid;
  emxInitArray_real_T(&vertical_waypoint, 1);

  // Initialize function 'slope_judgement' input arguments.
  // Initialize function input argument 'H'.
  argInit_d4000x1_real_T(H_data, H_size);

  // Initialize function input argument 'slope'.
  argInit_d4000x1_real_T(slope_data, slope_size);

  // Initialize function input argument 'x_coordination'.
  argInit_d4000x1_real_T(x_coordination_data, x_coordination_size);

  // Call the entry-point 'slope_judgement'.
  slope_judgement(H_data, H_size, slope_data, slope_size, x_coordination_data,
                  x_coordination_size, argInit_real_T(), argInit_real_T(),
                  vertical_waypoint, &unvalid);
  emxDestroyArray_real_T(vertical_waypoint);
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
  slope_judgement_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_slope_judgement();

  // Terminate the application.
  // You do not need to do this more than one time.
  slope_judgement_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
