cmake_minimum_required(VERSION 3.5)#最低CMake版本

project (hello_headers)# 工程名

set(SOURCES
    src/Hello.cpp
    src/main.cpp
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件。

add_executable(hello_headers ${SOURCES})#用所有的源文件生成一个可执行文件，因为这里定义了SOURCE变量，所以就不需要罗列cpp文件了
#等价于命令：     add_executable(hello_headers src/Hello.cpp src/main.cpp)

target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)#设置这个可执行文件hello_headers需要包含的库的路径

message("CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
message("CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})
message("CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR})
message("PROJECT_BINARY_DIR: " ${PROJECT_BINARY_DIR})
message("PROJECT_NAME: " ${PROJECT_NAME})
# CMAKE_SOURCE_DIR: ,{CMAKE_SOURCE_DIR}
# CMAKE_CURRENT_SOURCE_DIR: ,/home/yrc/文档/Project/ubuntuC-Project/hello-handers
# PROJECT_SOURCE_DIR: ,/home/yrc/文档/Project/ubuntuC-Project/hello-handers
# CMAKE_BINARY_DIR: ,/home/yrc/文档/Project/ubuntuC-Project/hello-handers/build
# CMAKE_CURRENT_BINARY_DIR: ./home/yrc/文档/Project/ubuntuC-Project/hello-handers/build
# PROJECT_BINARY_DIR: ,/home/yrc/文档/Project/ubuntuC-Project/hello-handers/build



#PROJECT_SOURCE_DIR指工程顶层目录
#PROJECT_Binary_DIR指编译目录
#PRIVATE指定了库的范围，下一节讲    

# make VERBOSE=1   查看用于调试目的的完整输出