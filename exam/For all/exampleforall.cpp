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

/**
 * HIGHT2SLOPE
 */
#include "HIGHT2SLOPE.h"
#include "HIGHT2SLOPE_terminate.h"
#include "HIGHT2SLOPE_initialize.h"

/**
 * slope_judgement
 */
#include "slope_judgement.h"
#include "slope_judgement_terminate.h"
#include "slope_judgement_emxAPI.h"
#include "slope_judgement_initialize.h"

#include <iostream> 
#include <stdio.h>
using namespace std; 

#include <opencv2/opencv.hpp>

int main(){
    /**
     * increase_waypoint2
     */
    double lat[2] = {24.1254,24.6899};
    double lon[2] = {121.4562,121.4511};
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
    double waypoint_lat_data[4000];
    double waypoint_lon_data[4000];
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
    // for (int i = 0; i <(int)num_point; i++ ){
    //     printf("[Hight is %.4f || H size is %d || index row %.4f || index column %.4f ]\n",
    //         H_data[i],H_size[0],c_record_data[i],c_record_data[i+11]);
    // }

    /**
     * HIGHT2SLOPE
     */
    int hight_size[1] = {waypoint_add_amount};
    int dis_size[1] = {waypoint_add_amount};
    double dis_data[4000];
    double slope_data[3999];
    int slope_size[1];
    for (int i = 0; i <(int)num_point; i++ ){
        dis_data[i] = dis_meter->data[i];
    }   
    HIGHT2SLOPE(H_data, hight_size, dis_data, dis_size, slope_data, slope_size);
    // for (int i = 0; i < hight_size[0]; i++){
    //     printf("%f \n",slope_data[i]);
    // }

    /**
     * slope_judgement
     */
    emxArray_real_T *vertical_waypoint;
    double x_coordination_data[4000];
    int x_coordination_size[1];
    double threshold = 0.15;
    emxInitArray_real_T(&vertical_waypoint, 1);
    double unvalid;

    for (int i = 0; i <(int)num_point; i++ ){
        x_coordination_data[i] = x_coordination->data[i];
    }   
    slope_judgement(H_data, hight_size, slope_data, slope_size, x_coordination_data,
                    x_coordination_size, num_point, threshold,
                    vertical_waypoint, &unvalid);

    printf("unvalid is %f \n",unvalid); 
    for (int i = 0; i < (int)num_point; i++){
        printf("Lat %f, Lon %f : Hight is %f \n",
        waypoint_add_lat_ptr->data[i],waypoint_add_lon_ptr->data[i],vertical_waypoint->data[i]);
    }               
}  
