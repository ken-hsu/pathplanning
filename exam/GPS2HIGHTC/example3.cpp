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


double Latitude_data[4000] = {24.1254,24.6899};
int Latitude_size[1] = {2};
double Lontitude_data[4000] = {121.4562,121.4511};
int Lontitude_size[1] = {2};
// static short iv0[12967201];
double H_data[4000];
int H_size[1];
double c_record_data[8000];
int c_record_size[2];
      GPS2HIGHTC(Latitude_data, Latitude_size, Lontitude_data, Lontitude_size, img_data_ptr,
             H_data, H_size, c_record_data, c_record_size);
             for (int i = 0; i < Latitude_size[0]; i++){
                  printf("[row %.4f ,column %.4f :Hight is %.4f ]\n",
                  c_record_data[i],c_record_data[i+Latitude_size[0]],H_data[i]);
             }
             printf("%d",img_data_ptr[69918]);

}