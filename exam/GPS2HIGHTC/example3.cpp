#include "rt_nonfinite.h"
#include "GPS2HIGHTC.h"
// #include "main.h"
#include "GPS2HIGHTC_terminate.h"
#include "GPS2HIGHTC_initialize.h"

#include<stdio.h>

#include <opencv2/opencv.hpp>
int main(){

cv::Mat img = cv::imread("/home/ken/src/Ken/pathplanning/ASTGTM2_N24E121_dem.tif",-1);
cv::imshow("rgb",img);
// cv::waitKey(0);
std::cout << img.type() << std::endl;

int16_t a = img.at<int16_t>(3598,4);
printf("image index value: is %d \n",a);
short int* img_data_ptr = (short int*)img.data;


double Latitude_data[4000] = {24.3300};
int Latitude_size[1] = {1};
double Lontitude_data[4000] = {121.1200};
int Lontitude_size[1] = {1};
// static short iv0[12967201];
double H_data[4000];
int H_size[1];
double c_record_data[8000];
int c_record_size[2];
      GPS2HIGHTC(Latitude_data, Latitude_size, Lontitude_data, Lontitude_size, img_data_ptr,
             H_data, H_size, c_record_data, c_record_size);
printf("[Hight is %.4f \nH size is %d \nindex row %.4f \nindex column %.4f]",H_data[0],H_size[0],c_record_data[0],c_record_data[1]);

}