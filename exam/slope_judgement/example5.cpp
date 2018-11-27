#include <iostream> 
#include <stdio.h>
using namespace std; 

#include "rt_nonfinite.h"
#include "slope_judgement.h"
// #include "main.h"
#include "slope_judgement_terminate.h"
#include "slope_judgement_emxAPI.h"
#include "slope_judgement_initialize.h"
int main(){
      emxArray_real_T *vertical_waypoint;
  double H_data[4000] = {100.0000,101.0000,102.0000,108.0000};
  printf("%f || %f || %f || %f \n",H_data[0],H_data[1],H_data[2],H_data[3]);
  int H_size[1] = {4};
  double slope_data[4000] = {0.1,0.1,0.2};
  int slope_size[1] = {3};
  double x_coordination_data[4000] = {0,100,200,300};
  int x_coordination_size[1];
    double unvalid;
  emxInitArray_real_T(&vertical_waypoint, 1);
    double num_point = H_size[0];
    double threshold = 0.15;


  slope_judgement(H_data, H_size, slope_data, slope_size, x_coordination_data,
                  x_coordination_size, num_point, threshold,
                  vertical_waypoint, &unvalid);
  printf("%f || %f || %f || %f \n",H_data[0],H_data[1],H_data[2],H_data[3]);

for (int i = 0; i < (int)num_point; i++){
    printf("change is %f \n",unvalid);

}
}