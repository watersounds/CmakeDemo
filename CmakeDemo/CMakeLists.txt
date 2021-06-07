cmake_minimum_required(VERSION 3.0.0)  # Cmake 最低版本要求是3.0.0
# project(cmake_demo VERSION 0.1.0)

# include(CTest)
# enable_testing()

# add_executable(cmake_demo main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

project(demo)  # 工程信息，也就是工程名叫demo



# add_executable(cmake_demo main.cpp testFunc.cpp)  # 表示最终要生成的elf文件的名字叫main，使用的源文件是main.c

# =================================================================================
# 多个源文件时,使用aux_source_directory把当前目录下的源文件存列表存放到变量SRC_LIST里，
# 然后在add_executable里调用SRC_LIST（注意调用变量时的写法）。

# 把指定目录下所有的源文件存储在一个变量中
# aux_source_directory(. SRC_LIST)  # 第一个参数dir是指定目录，第二个参数var是用于存放源文件列表的变量。
# 弊端:它会把指定目录下的所有源文件都加进来，可能会加入一些我们不需要的文件，此时我们可以使用set命令去新建变量来存放需要的源文件
# set(SRC_LIST 
#         ./main.cpp
#         ./testFunc.cpp
#         ./testFunc1.cpp)

# add_executable(cmake_demo ${SRC_LIST}) 

# include_directories。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔。
# include_directories(testFunc testFunc1)


# ==============================================================================================
# add_subdirectory()，这个命令可以向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置，
add_subdirectory(src)





