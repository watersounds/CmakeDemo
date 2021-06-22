cmake_minimum_required(VERSION 3.15)
project(nanodet_ncnn)

set(OpenCV_DIR /home/yrc/opencvlib/lib/cmake/opencv4)
set(ncnn_DIR /home/yrc/文档/ncnn/ncnn/build/install/lib/cmake/ncnn)

find_package(OpenCV REQUIRED)

find_package(ncnn REQUIRED)
if(NOT TARGET ncnn)
    message(WARNING "ncnn NOT FOUND!  Please set ncnn_DIR environment variable")
else()
    message("ncnn FOUND ")
endif()

set(SOURCES
    src/nanodet.cpp
    src/main.cpp
)
# directory of opencv ncnn headers
include_directories(${OpenCV_INCLUDE_DIRS}
                    ${ncnn_INCLUDE_DIRS})

# name of executable file and path of source file
add_executable(nanodet_ncnn ${SOURCES})

target_include_directories(nanodet_ncnn
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )


# directory of opencv ncnn library
link_directories(${OpenCV_LIBRARY_DIRS}
                 ${ncnn_LIBRARY_DIRS})

# opencv libraries
target_link_libraries(nanodet_ncnn ncnn ${OpenCV_LIBS})

