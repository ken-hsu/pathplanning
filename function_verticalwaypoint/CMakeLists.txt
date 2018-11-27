PROJECT(opencv_test)
cmake_minimum_required(VERSION 3.5)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${opencv_test_SOURCE_DIR}/bin)\

add_library(vwp
	function_verticalwaypoint
	function_verticalwaypoint_emxAPI.cpp
	function_verticalwaypoint_emxutil.cpp
	function_verticalwaypoint_initialize.cpp
	function_verticalwaypoint_terminate.cpp
	increase_waypoint.cpp
	rtGetInf.cpp
	rtGetNaN.cpp
	rt_nonfinite.cpp
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv_test
 generate.cpp
 )
# link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(opencv_test 
${OpenCV_LIBS}
vwp
)
