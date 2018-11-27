#include "rt_nonfinite.h"
#include "calculate_distance2.h"
// #include "main.h"
#include "calculate_distance2_terminate.h"
#include "calculate_distance2_emxAPI.h"
#include "calculate_distance2_initialize.h"

#include <iostream> 
#include <stdio.h>
using namespace std; 

int main(){
  emxArray_real_T *x_coordination;
  emxArray_real_T *dis_meter;
  double waypoint_lat_data[2000] = {22.0001,22.0004,22.0005,22.0006};
  int waypoint_lat_size[1];
  double waypoint_lon_data[2000] = {120.0001,120.0002,120.0004,120.0006};
  int waypoint_lon_size[1];
  emxInitArray_real_T(&x_coordination, 1);
  emxInitArray_real_T(&dis_meter, 1);
  double num_point = 4.0;
  double init_lat = 28.0;
  calculate_distance2(waypoint_lat_data, waypoint_lat_size, waypoint_lon_data,
                      waypoint_lon_size,num_point ,init_lat,
                      x_coordination, dis_meter);
for (int i = 0 ;i < (int)num_point; i++){
// std::cout<<i<<" = "<<waypoint_add_lon->data[i]<<endl;
printf("%.4f \n",x_coordination->data[i]);
}
                     
}  
