cmake_minimum_required(VERSION 3.5)
# set(OpenCV_DIR "/opt/ros/kinetic/include/opencv-3.3.1-dev/")
find_package(OpenCV REQUIRED)
# add_executable(
#     wp_gen
#     generate.cpp
# )
include_directories(
    ${OpenCV_INCLUDE_DIR}
)
add_executable(opencv_test
    opencv_test.cpp
)
target_link_libraries(opencv_test
    ${OpenCV_LIBRARIES}
)