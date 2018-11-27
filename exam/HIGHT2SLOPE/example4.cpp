#include <iostream> 
#include <stdio.h>
using namespace std; 

#include "rt_nonfinite.h"
#include "HIGHT2SLOPE.h"
// #include "main.h"
#include "HIGHT2SLOPE_terminate.h"
#include "HIGHT2SLOPE_initialize.h"
int main(){
    double hight_data[4000]={110,120,140,100};
    int hight_size[1] = {4};
    double dis_data[4000] = {2,4,5};
    int dis_size[1] = {4};
    double slope_data[3999];
    int slope_size[1];

    // Call the entry-point 'HIGHT2SLOPE'.
    HIGHT2SLOPE(hight_data, hight_size, dis_data, dis_size, slope_data, slope_size);
    for (int i = 0; i < hight_size[0]; i++){
        printf("%.4f \n",slope_data[i]);
    }
}