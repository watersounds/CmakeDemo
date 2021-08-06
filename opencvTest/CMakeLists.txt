# project name
PROJECT(opencv_test)
# requirement of cmake version
cmake_minimum_required(VERSION 3.5)

# set the directory of executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${opencv_test_SOURCE_DIR}/bin)

set(OpenCV_DIR /home/yrc/opencvlib/lib/cmake/opencv4/)

# find required opencv
find_package(OpenCV REQUIRED)
# directory of opencv headers
include_directories(${OpenCV_INCLUDE_DIRS})
# name of executable file and path of source file
add_executable(opencv_test src/opencv_test.cpp)
add_executable(test_Homography src/test_Homography.cpp)
# directory of opencv library
# link_directories(${OpenCV_LIBRARY_DIRS})
# opencv libraries
target_link_libraries(opencv_test ${OpenCV_LIBS})
target_link_libraries(test_Homography ${OpenCV_LIBS})
