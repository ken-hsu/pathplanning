//
// File: main.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 26-Nov-2018 14:52:19
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
#include "function_verticalwaypoint.h"
// #include "main.h"
#include "function_verticalwaypoint_terminate.h"
#include "function_verticalwaypoint_emxAPI.h"
#include "function_verticalwaypoint_initialize.h"

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
// Function Declarations
static void argInit_3601x3601_int16_T(short result[12967201]);
static void argInit_d2000x2_real_T(double result_data[], int result_size[2]);
static short argInit_int16_T();
static double argInit_real_T();
static void main_function_verticalwaypoint();

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
//                int result_size[2]
// Return Type  : void
//
static void argInit_d2000x2_real_T(double result_data[], int result_size[2])
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


static void main_function_verticalwaypoint()
{
  emxArray_real_T *vertical_waypoint;
  emxArray_real_T *index_of_waypoint;
  double waypoint_data[4] = {24.0001,121.0002,24.0009,121.0009};
  int waypoint_size[2] = {4,2};
  double num_point;
  emxInitArray_real_T(&vertical_waypoint, 2);
  emxInitArray_real_T(&index_of_waypoint, 2);

  // Initialize function 'function_verticalwaypoint' input arguments.
  // Initialize function input argument 'waypoint'.
  argInit_d2000x2_real_T(waypoint_data, waypoint_size);

  cv::Mat img = cv::imread("/home/ken/src/Ken/pathplanning/ASTGTM2_N24E121_dem.tif");
  // img_data_ptr;
  // cv::imshow("rgb",img);
  // cv::waitKey(0);
  short int* img_data_ptr = (short int*)img.data;
  // Initialize function input argument 'map'.
  // Call the entry-point 'function_verticalwaypoint'.
  function_verticalwaypoint(waypoint_data, waypoint_size, img_data_ptr, vertical_waypoint,
    index_of_waypoint, &num_point);
  std::cout<<vertical_waypoint->data[0]<<';'<<vertical_waypoint->data[1]<<';'<<vertical_waypoint->data[2]<<"num = "<<num_point;
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
  function_verticalwaypoint_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_function_verticalwaypoint();

  // Terminate the application.
  // You do not need to do this more than one time.
  function_verticalwaypoint_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
