// basic file operations
#include <iostream>
#include <fstream>
using namespace std;
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "sign.h"
#include "sqrt.h"
#include "function_verticalwaypoint_emxutil.h"
#include "nullAssignment.h"
#include "HIGHT2SLOPE.h"
#include "GPS2HIGHTC.h"
#include "floor.h"
// #include "function_verticalwaypoint_rtwutil.h"
#include <opencv2\highgui\highgui.hpp>

int main () {
    double lat = 47.39772048440407;
    double lon = 8.54824584249181;
    double H = 50;
    int ID = 0;
    // emxArray_real_T waypoint;
    // emxArray_real_T vertical_waypoint;
    // emxArray_real_T index_of_waypoint;
    // const short map[12967201];


    // cv::Mat img = cv::imread("earth.jpg");

    // cv::imshow("rgb",img);
    // cv::waitKey(0);

    // function_verticalwaypoint(&waypoint, map, &vertical_waypoint, &index_of_waypoint);
  ofstream myfile;
  myfile.open ("plan001.plan");
  myfile << "{\"fileType\": \"Plan\",\"geoFence\": {\"circles\": [],\"polygons\": [],\"version\": 2},\"groundStation\": \"QGroundControl\",\"mission\": {\"cruiseSpeed\": 15,\"firmwareType\": 12,\"hoverSpeed\": 5,\"items\": [";
  for (int i = 1; i < 8; i++){
    ID = ID + 1;
    myfile <<" {\"AMSLAltAboveTerrain\": null,\"Altitude\": 50,\"AltitudeMode\": 0,\"autoContinue\": true,\"command\": 84,\"doJumpId\": "<<ID<<",\"frame\": 3,\"params\": [0,0,0,null,";
    lat = lat + 0.1;
    lon = lon + 0.9;
    H = 50;
    myfile << lat <<","<< lon <<"," << H;
    myfile << "],\"type\": \"SimpleItem\"},";
}

myfile <<" {\"AMSLAltAboveTerrain\": null,\"Altitude\": 50,\"AltitudeMode\": 0,\"autoContinue\": true,\"command\": 84,\"doJumpId\": "<<ID+1<<",\"frame\": 3,\"params\": [0,0,0,null,";
lat = lat + 0.1;
lon = lon + 0.3;
H = 50;
myfile << lat <<","<< lon <<"," << H;
myfile << "],\"type\": \"SimpleItem\"}";
myfile << "],\"plannedHomePosition\": [";
myfile << lat <<","<< lon <<"," << H;
myfile << "],\"vehicleType\": 20,\"version\": 2},\"rallyPoints\": {\"points\": [],\"version\": 2},\"version\": 1}";
  myfile.close();
  return 0;
}