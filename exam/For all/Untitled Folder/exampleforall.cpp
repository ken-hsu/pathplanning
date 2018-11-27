/**
 * increase_waypoint2
 */
#include "rt_nonfinite.h"
#include "increase_waypoint2.h"
#include "increase_waypoint2_terminate.h"
#include "increase_waypoint2_emxAPI.h"
#include "increase_waypoint2_initialize.h"

/**
 * calcualte_distance2
 */
#include "calculate_distance2.h"
#include "calculate_distance2_terminate.h"
#include "calculate_distance2_emxAPI.h"
#include "calculate_distance2_initialize.h"

/**
 * calcualte_distance2
 */

#include <iostream> 
#include <stdio.h>
using namespace std; 

int main(){
    /**
     * increase_waypoint2
     */
    double lat[2] = {22.0008,22.0001};
    double lon[2] = {121.1002,121.1012};
    emxArray_real_T *waypoint_add_lat;
    emxArray_real_T *waypoint_add_lon;
    double waypoint_add_amount;
    emxInitArray_real_T(&waypoint_add_lat, 1);
    emxInitArray_real_T(&waypoint_add_lon, 1);
    increase_waypoint2(lat, lon, waypoint_add_lat, waypoint_add_lon,
                     &waypoint_add_amount);

// for (int i = 0 ;i < (int)waypoint_add_amount; i++){
// printf("%.4f \n",waypoint_add_lon->data[i]);
// }
                     
    /**
     * calcualte_distance2
     */
    emxArray_real_T *x_coordination;
    emxArray_real_T *dis_meter;
    int waypoint_lat_size[1];
    int waypoint_lon_size[1];
    double waypoint_lat_data[2000];
    double waypoint_lon_data[2000];
    emxInitArray_real_T(&x_coordination, 1);
    emxInitArray_real_T(&dis_meter, 1);
    double num_point = waypoint_add_amount;
    double init_lat = lat[0];

    for (int i = 0; i<(int)waypoint_add_amount; i++){
        waypoint_lat_data[i] = waypoint_add_lat->data[i];
        waypoint_lon_data[i] = waypoint_add_lon->data[i];
    }
    calculate_distance2(waypoint_lat_data, waypoint_lat_size, waypoint_lon_data,
                        waypoint_lon_size,num_point ,init_lat,
                        x_coordination, dis_meter);


for (int i = 0 ;i < (int)num_point; i++){
printf("%.4f \n",x_coordination->data[i]);
}
                     
}  
