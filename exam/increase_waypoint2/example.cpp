#include "rt_nonfinite.h"
#include "increase_waypoint2.h"
// #include "main.h"
#include "increase_waypoint2_terminate.h"
#include "increase_waypoint2_emxAPI.h"
#include "increase_waypoint2_initialize.h"

#include <iostream> 
#include <stdio.h>
using namespace std; 

int main(){
    double lat[2] = {22.0001,22.0005};
    double lon[2] = {121.1002,121.1012};
    emxArray_real_T *waypoint_add_lat;
    emxArray_real_T *waypoint_add_lon;
    double waypoint_add_amount;
    emxInitArray_real_T(&waypoint_add_lat, 1);
    emxInitArray_real_T(&waypoint_add_lon, 1);
    increase_waypoint2(lat, lon, waypoint_add_lat, waypoint_add_lon,
                     &waypoint_add_amount);
                    //    int step = (int)waypoint_add_amount;
                     for (int i = 0 ;i < (int)waypoint_add_amount; i++){
                        // std::cout<<i<<" = "<<waypoint_add_lon->data[i]<<endl;
                        printf("%.4f \n",waypoint_add_lon->data[i]);
                     }
                     
}  
