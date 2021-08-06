cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(OpenCV_DIR /home/yrc/opencvlib/lib/cmake/opencv4/)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCES src/calibration.cpp)
add_executable(calibration ${SOURCES})  # single carema 
add_executable(imagelist_creator src/imagelist_creator.cpp)
add_executable(stereo_calib src/stereo_calib.cpp)  # 得到 intrinsics.yml和 extrinsics.yml 文件
add_executable(stereo_match src/stereo_match.cpp)
add_executable(camera_calibration camera_calibration/camera_calibration.cpp)
add_executable(correction camera_calibration/correction.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# link_directories(${OpenCV_LIBRARY_DIRS})
target_link_libraries(calibration ${OpenCV_LIBS})
target_link_libraries(imagelist_creator ${OpenCV_LIBS})
target_link_libraries(stereo_calib ${OpenCV_LIBS})
target_link_libraries(stereo_match ${OpenCV_LIBS})
target_link_libraries(camera_calibration ${OpenCV_LIBS}) 
target_link_libraries(correction ${OpenCV_LIBS}) 

