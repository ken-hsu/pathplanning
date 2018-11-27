PROJECT(opencv_test)
cmake_minimum_required(VERSION 3.5)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${opencv_test_SOURCE_DIR}/bin)\

add_library(vwp
calculate_distance2.cpp
calculate_distance2_emxAPI.cpp
calculate_distance2_emxutil.cpp
calculate_distance2_initialize.cpp
calculate_distance2_terminate.cpp
exampleforall.cpp
GPS2HIGHTC.cpp
GPS2HIGHTC_initialize.cpp
GPS2HIGHTC_terminate.cpp
increase_waypoint2.cpp
increase_waypoint2_initialize.cpp
increase_waypoint2_terminate.cpp
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
