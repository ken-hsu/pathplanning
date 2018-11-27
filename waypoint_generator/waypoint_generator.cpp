#include <iostream> 
#include <vector>
#include <math.h>
using namespace std; 
// Function Declarations
void increase_waypoint(vector<double> waypoint, double &step);
// Function Definition
void increase_waypoint(vector<double> waypoint, double &step){
    vector<double> ::iterator it = waypoint.begin();
    step = floor(fabsf(*(it+1) - *it)*10000)/10000;
}
int main(){
    double step;
    std::vector<double> waypoint {1.0002,2.0009,3.0003};
    increase_waypoint(waypoint,step);
    std::cout<<step;
}
// Function Definitions
