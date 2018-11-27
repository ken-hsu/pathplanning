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
 * GPS2HIGHTC
 */
#include "GPS2HIGHTC.h"
#include "GPS2HIGHTC_terminate.h"
#include "GPS2HIGHTC_initialize.h"

#include <iostream> 
#include <stdio.h>
using namespace std; 

#include <opencv2/opencv.hpp>

int main(){
    /**
     * increase_waypoint2
     */
    double lat[2] = {22.0008,22.0001};
    double lon[2] = {121.1002,121.1012};
    emxArray_real_T *waypoint_add_lat_ptr;
    emxArray_real_T *waypoint_add_lon_ptr;
    double waypoint_add_amount;
    emxInitArray_real_T(&waypoint_add_lat_ptr, 1);
    emxInitArray_real_T(&waypoint_add_lon_ptr, 1);
    increase_waypoint2(lat, lon, waypoint_add_lat_ptr, waypoint_add_lon_ptr,
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
        waypoint_lat_data[i] = waypoint_add_lat_ptr->data[i];
        waypoint_lon_data[i] = waypoint_add_lon_ptr->data[i];
    }
    calculate_distance2(waypoint_lat_data, waypoint_lat_size, waypoint_lon_data,
                        waypoint_lon_size,num_point ,init_lat,
                        x_coordination, dis_meter);
// for (int i = 0 ;i < (int)num_point; i++){
// printf("%.4f \n",x_coordination->data[i]);
// }

 /**
 * GPS2HIGHTC
 */   
cv::Mat img = cv::imread("/home/ken/src/Ken/pathplanning/ASTGTM2_N24E121_dem.tif",-1);
cv::imshow("rgb",img);
short int* img_data_ptr = (short int*)img.data;

int Latitude_size[1] = {waypoint_add_amount};
int Lontitude_size[1] = {waypoint_add_amount};
double H_data[4000];
int H_size[1];
double c_record_data[8000];
int c_record_size[2];
      GPS2HIGHTC(waypoint_lat_data, Latitude_size, waypoint_lon_data, Lontitude_size, img_data_ptr,
             H_data, H_size, c_record_data, c_record_size);

printf("[Hight is %.4f \nH size is %d \nindex row %.4f \nindex column %.4f]",
        H_data[0],H_size[0],c_record_data[0],c_record_data[1]);
                   
}  
