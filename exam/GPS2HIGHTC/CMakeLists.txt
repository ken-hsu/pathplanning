PROJECT(opencv_test)
cmake_minimum_required(VERSION 3.5)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${opencv_test_SOURCE_DIR}/bin)\

add_library(vwp
GPS2HIGHTC.cpp
GPS2HIGHTC_initialize.cpp
GPS2HIGHTC_terminate.cpp
rtGetInf.cpp
rtGetNaN.cpp
rt_nonfinite.cpp
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(opencv_test
 example3.cpp
 )
# link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(opencv_test 
${OpenCV_LIBS}
vwp
)
