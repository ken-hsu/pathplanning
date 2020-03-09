//
// File: L1Algorithm.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 03-Jan-2020 15:06:08
//

// Include Files
#include "rt_nonfinite.h"
#include "L1Algorithm.h"
#include "norm.h"
#include "L1Algorithm_emxutil.h"
#include "rdivide.h"

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2((double)b_u0, (double)b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// for simulation
//      clear all;
//      % parameter setting
//      L1_distance = 110;
//      % read plan from file
//      fileID = fopen('/home/ken/Documents/xxxx.plan');
//      C = textscan(fileID, '%s','Delimiter',',');
//      co = 0;
//      for i = 1:size(C{1},1)
//      if (C{1}{i} == num2str(0))
//      co = co +1;
//      end
//      end
//      numOfWaypoint = co/3 +1;
//      waypoint_latlon = zeros(2,numOfWaypoint);
//      for i = 1:numOfWaypoint-1
//      waypoint_latlon(1,i+1) = str2double(C{1}{29+(i-1)*19})*pi/180;
//      waypoint_latlon(2,i+1) = str2double(C{1}{30+(i-1)*19})*pi/180;
//      end
//
//      % uav condition
//      Yaw = 0;
//      uavHome_latlon = [47.397742 8.545594]'*pi/180;
// Arguments    : emxArray_real_T *waypoint_latlon
//                double L1_distance
//                const double uavHome_latlon[2]
//                double Yaw
//                emxArray_real_T *point_latlon
// Return Type  : void
//
void L1Algorithm(emxArray_real_T *waypoint_latlon, double L1_distance, const
                 double uavHome_latlon[2], double Yaw, emxArray_real_T
                 *point_latlon)
{
  int numOfWaypoint;
  int i0;
  emxArray_real_T *waypoint_cartesianNE;
  double totalDistance;
  int i;
  int b_i;
  double uavLocation[2];
  int i1;
  emxArray_real_T *vector;
  unsigned int numOfPoint;
  double BP_distance;
  double vectorBP[2];
  double vectorAB[2];
  boolean_T exitg1;
  double vectorAB_unit[2];
  double theta;
  emxArray_real_T *b_vector;
  double AP_distance;
  double vectorAP[2];
  emxArray_real_T *r0;
  double vectorAP_unit[2];
  double vectorV[2];
  boolean_T guard1 = false;
  double vectorBP_unit[2];
  boolean_T guard2 = false;
  double dv0[4];

  //  for code generation
  //  number of waypoint
  numOfWaypoint = waypoint_latlon->size[1] - 2;

  //  Constant
  //  first waypoint is home position
  for (i0 = 0; i0 < 2; i0++) {
    waypoint_latlon->data[i0] = uavHome_latlon[i0];
  }

  emxInit_real_T(&waypoint_cartesianNE, 2);

  //  transfer latlon to meter
  totalDistance = std::cos(uavHome_latlon[0]);
  i = waypoint_latlon->size[1];
  b_i = waypoint_latlon->size[1] - 1;
  i0 = waypoint_cartesianNE->size[0] * waypoint_cartesianNE->size[1];
  waypoint_cartesianNE->size[0] = 2;
  waypoint_cartesianNE->size[1] = i;
  emxEnsureCapacity_real_T(waypoint_cartesianNE, i0);
  for (i0 = 0; i0 < i; i0++) {
    waypoint_cartesianNE->data[waypoint_cartesianNE->size[0] * i0] =
      (waypoint_latlon->data[waypoint_latlon->size[0] * i0] - uavHome_latlon[0])
      * 6.371E+6;
  }

  for (i0 = 0; i0 <= b_i; i0++) {
    waypoint_cartesianNE->data[1 + waypoint_cartesianNE->size[0] * i0] =
      (waypoint_latlon->data[1 + waypoint_latlon->size[0] * i0] -
       uavHome_latlon[1]) * totalDistance * 6.371E+6;
  }

  for (i = 0; i < 2; i++) {
    uavLocation[i] = 0.0;
  }

  //  calculate total distance for the parameter declaration
  if (2 > waypoint_cartesianNE->size[1]) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = 1;
    i1 = waypoint_cartesianNE->size[1];
  }

  emxInit_real_T(&vector, 2);
  b_i = vector->size[0] * vector->size[1];
  vector->size[0] = 2;
  vector->size[1] = i1 - i0;
  emxEnsureCapacity_real_T(vector, b_i);
  i = i1 - i0;
  for (i1 = 0; i1 < i; i1++) {
    for (b_i = 0; b_i < 2; b_i++) {
      vector->data[b_i + vector->size[0] * i1] = waypoint_cartesianNE->data[b_i
        + waypoint_cartesianNE->size[0] * (i0 + i1)] -
        waypoint_cartesianNE->data[b_i + waypoint_cartesianNE->size[0] * i1];
    }
  }

  totalDistance = 0.0;
  for (i = 0; i <= numOfWaypoint; i++) {
    totalDistance += norm(*(double (*)[2])&vector->data[vector->size[0] * i]);
  }

  totalDistance = std::floor(totalDistance * 1.2);
  i0 = vector->size[0] * vector->size[1];
  vector->size[0] = 2;
  vector->size[1] = (int)totalDistance;
  emxEnsureCapacity_real_T(vector, i0);
  i = (int)totalDistance << 1;
  for (i0 = 0; i0 < i; i0++) {
    vector->data[i0] = 0.0;
  }

  //  L1 algorithm
  numOfPoint = 0U;
  for (i = 0; i <= numOfWaypoint; i++) {
    for (i0 = 0; i0 < 2; i0++) {
      vectorBP[i0] = uavLocation[i0] - waypoint_cartesianNE->data[i0 +
        waypoint_cartesianNE->size[0] * (i + 1)];
    }

    BP_distance = norm(vectorBP);
    for (i0 = 0; i0 < 2; i0++) {
      vectorAB[i0] = waypoint_cartesianNE->data[i0 + waypoint_cartesianNE->size
        [0] * (i + 1)] - waypoint_cartesianNE->data[i0 +
        waypoint_cartesianNE->size[0] * i];
    }

    totalDistance = norm(vectorAB);
    for (b_i = 0; b_i < 2; b_i++) {
      vectorAB_unit[b_i] = vectorAB[b_i] / totalDistance;
    }

    exitg1 = false;
    while ((!exitg1) && (BP_distance > 30.0)) {
      theta = 0.0;
      for (i0 = 0; i0 < 2; i0++) {
        theta += vectorBP[i0] * -vectorAB[i0];
      }

      if (theta > 0.0) {
        //  arrived determination
        for (i0 = 0; i0 < 2; i0++) {
          vectorAP[i0] = uavLocation[i0] - waypoint_cartesianNE->data[i0 +
            waypoint_cartesianNE->size[0] * i];
        }

        AP_distance = norm(vectorAP);
        if (AP_distance == 0.0) {
          for (b_i = 0; b_i < 2; b_i++) {
            vectorAP_unit[b_i] = 0.0;
          }
        } else {
          for (b_i = 0; b_i < 2; b_i++) {
            vectorAP_unit[b_i] = vectorAP[b_i] / AP_distance;
          }
        }

        for (i0 = 0; i0 < 2; i0++) {
          vectorBP[i0] = uavLocation[i0] - waypoint_cartesianNE->data[i0 +
            waypoint_cartesianNE->size[0] * (i + 1)];
        }

        BP_distance = norm(vectorBP);
        vectorV[0] = std::sin(Yaw);
        vectorV[1] = std::cos(Yaw);
        totalDistance = norm(vectorV);
        for (b_i = 0; b_i < 2; b_i++) {
          vectorBP_unit[b_i] = vectorBP[b_i] / BP_distance;
          vectorV[b_i] /= totalDistance;
        }

        guard1 = false;
        guard2 = false;
        if (AP_distance > L1_distance) {
          theta = 0.0;
          for (i0 = 0; i0 < 2; i0++) {
            theta += vectorAP[i0] * vectorAB_unit[i0];
          }

          if (theta / AP_distance < -0.7071) {
            //  if ... go to waypoint A
            theta = 0.0;
            for (i0 = 0; i0 < 2; i0++) {
              theta += -vectorAP_unit[i0] * vectorV[i0];
            }

            totalDistance = rt_atan2d_snf(vectorV[0] * -vectorAP_unit[1] -
              vectorV[1] * -vectorAP_unit[0], theta);
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          theta = 0.0;
          for (i0 = 0; i0 < 2; i0++) {
            theta += vectorAB_unit[i0] * vectorBP_unit[i0];
          }

          if (std::abs(std::acos(theta)) < 1.7453292519943295) {
            guard1 = true;
          } else {
            theta = 0.0;
            for (i0 = 0; i0 < 2; i0++) {
              theta += vectorV[i0] * vectorAB_unit[i0];
            }

            if (std::abs(std::acos(theta)) >= 1.5707963267948966) {
              guard1 = true;
            } else {
              //  fly along the line AB
              totalDistance = std::sin((vectorAP[0] * vectorAB_unit[1] -
                vectorAP[1] * vectorAB_unit[0]) / L1_distance);
              if (totalDistance > 0.78539816339744828) {
                totalDistance = 0.78539816339744828;
              } else {
                if (totalDistance < -0.78539816339744828) {
                  totalDistance = -0.78539816339744828;
                }
              }

              theta = 0.0;
              for (i0 = 0; i0 < 2; i0++) {
                theta += vectorAB_unit[i0] * vectorV[i0];
              }

              totalDistance = std::asin(totalDistance) + rt_atan2d_snf(vectorV[0]
                * vectorAB_unit[1] - vectorV[1] * vectorAB_unit[0], theta);
            }
          }
        }

        if (guard1) {
          //  if miss waypoint B, go to waypoint B
          theta = 0.0;
          for (i0 = 0; i0 < 2; i0++) {
            theta += -vectorBP_unit[i0] * vectorV[i0];
          }

          totalDistance = rt_atan2d_snf(vectorV[0] * -vectorBP_unit[1] -
            vectorV[1] * -vectorBP_unit[0], theta);
        }

        //  The angle of eta large than 0 means require a negative roll (going to left) 
        //  transform from body to NED
        //  change sign of the eta for calculate correct lateral acceleration
        totalDistance = -totalDistance;
        totalDistance = 2.0 * std::sin(totalDistance) / L1_distance;

        //  airplane lateral dynamics
        if (totalDistance > 0.01) {
          totalDistance = 0.01;
        }

        totalDistance = 1.0 / totalDistance;

        //  arc length unit:m/s (this value determine the iteration precision)
        theta = 1.0 / totalDistance;

        //  a vector in body coordination, represent uav location in this time stamp to the next time stamp 
        //  tramsform vector to NED frame
        vectorAP[0] = totalDistance - totalDistance * std::cos(theta);
        vectorAP[1] = totalDistance * std::sin(theta);
        dv0[0] = std::cos(Yaw);
        dv0[2] = std::sin(Yaw);
        dv0[1] = -std::sin(Yaw);
        dv0[3] = std::cos(Yaw);
        Yaw += theta;
        numOfPoint++;
        for (i0 = 0; i0 < 2; i0++) {
          theta = 0.0;
          for (i1 = 0; i1 < 2; i1++) {
            theta += dv0[i0 + (i1 << 1)] * vectorAP[i1];
          }

          totalDistance = uavLocation[i0] + theta;
          vector->data[i0 + vector->size[0] * ((int)numOfPoint - 1)] =
            totalDistance;
          uavLocation[i0] = totalDistance;
        }
      } else {
        exitg1 = true;
      }
    }
  }

  emxFree_real_T(&waypoint_cartesianNE);
  i0 = point_latlon->size[0] * point_latlon->size[1];
  point_latlon->size[0] = 2;
  point_latlon->size[1] = (int)numOfPoint;
  emxEnsureCapacity_real_T(point_latlon, i0);
  i = (int)numOfPoint << 1;
  for (i0 = 0; i0 < i; i0++) {
    point_latlon->data[i0] = 0.0;
  }

  //  cartesian to polar
  if (1 > (int)numOfPoint) {
    i = 0;
  } else {
    i = (int)numOfPoint;
  }

  emxInit_real_T(&b_vector, 2);
  i0 = b_vector->size[0] * b_vector->size[1];
  b_vector->size[0] = 1;
  b_vector->size[1] = i;
  emxEnsureCapacity_real_T(b_vector, i0);
  for (i0 = 0; i0 < i; i0++) {
    b_vector->data[b_vector->size[0] * i0] = vector->data[vector->size[0] * i0];
  }

  emxInit_real_T(&r0, 2);
  rdivide(b_vector, r0);
  i = r0->size[1];
  for (i0 = 0; i0 < i; i0++) {
    point_latlon->data[point_latlon->size[0] * i0] = uavHome_latlon[0] +
      r0->data[r0->size[0] * i0];
  }

  if (1 > (int)numOfPoint) {
    i = 0;
  } else {
    i = (int)numOfPoint;
  }

  totalDistance = std::cos(uavHome_latlon[0]);
  i0 = b_vector->size[0] * b_vector->size[1];
  b_vector->size[0] = 1;
  b_vector->size[1] = i;
  emxEnsureCapacity_real_T(b_vector, i0);
  for (i0 = 0; i0 < i; i0++) {
    b_vector->data[b_vector->size[0] * i0] = vector->data[1 + vector->size[0] *
      i0];
  }

  emxFree_real_T(&vector);
  rdivide(b_vector, r0);
  i = r0->size[1];
  emxFree_real_T(&b_vector);
  for (i0 = 0; i0 < i; i0++) {
    point_latlon->data[1 + point_latlon->size[0] * i0] = uavHome_latlon[1] +
      r0->data[r0->size[0] * i0] / totalDistance;
  }

  emxFree_real_T(&r0);

  //  for simulation
  //  plot(point_cartesianNE(2,1:numOfPoint),point_cartesianNE(1,1:numOfPoint)); axis equal 
  //  hold on;
  //  plot(waypoint_cartesianNE(2,:),waypoint_cartesianNE(1,:)); % plot waypoint line 
  //  hold on;
  //  plot(waypoint_cartesianNE(2,:),waypoint_cartesianNE(1,:),'*'); % plot waypoint 
  //  for i = 1:numOfWaypoint
  //      text(waypoint_cartesianNE(2,i),waypoint_cartesianNE(1,i),num2str(i-1)); 
  //  end
  //  text(uavHome_cartesian(2),uavHome_cartesian(1),'uav home');
  //  title('uav trajectory simulation');
  //  xlabel('east meter');
  //  ylabel('north meter');
}

//
// File trailer for L1Algorithm.cpp
//
// [EOF]
//
