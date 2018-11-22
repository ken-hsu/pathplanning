#include <opencv2\opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("");
    cv::imshow("/home/ken/src/Ken/pathplanning/ASTGTM2_N25E055_dem.tif",img);
    cv::waitKey(0);
    return 0;
}