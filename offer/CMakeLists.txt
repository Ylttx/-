cmake_minimum_required(VERSION 3.20)

set(project_name offer)
project(${project_name} VERSION 1.0 DESCRIPTION "I want offer" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF) # 编译详细信息： make VERBOSE=1

add_compile_options(-W -Wall -g)
add_link_options(-rdynamic -g -fno-omit-frame-pointer)

# option(ENABLE_UNIT_TESTS "Enable unit tests" ON)

# 添加包含路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include)

link_directories(/usr/local/lib)

# 添加源代码路径 
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/test TEST_LIST)

# 生成可执行文件
add_executable(${project_name} main.cpp ${SRC_LIST})
add_executable(ut.${project_name} ${TEST_LIST} ${SRC_LIST})
target_link_libraries(ut.${project_name} PRIVATE pthread gtest)