# 指定所需的最小 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称为 demo_project
project(demo_project)

# 设置 C++ 标准为 C++14
set(CMAKE_CXX_STANDARD 14)

# 完全静态链接（不推荐）
#set(CMAKE_EXE_LINKER_FLAGS "-static")

# 包含头文件目录
# include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(include)

# file(GLOB DEMO_SOURCES "src/demo/*.cpp")
# 定义可执行文件目标
# demo: 生成的可执行文件名
# 源文件列表
add_executable(demo_main
    src/main.cpp
    # ${DEMO_SOURCES}
    src/demo/person.cpp
)

# 添加指针演示的可执行文件
add_executable(pointer_demo
    src/demo/pointer_demo.cpp)

# 添加 class_interface_demo 的可执行文件
add_executable(class_interface_demo
        src/class_interface_demo.cpp
        src/car.cpp)


# 添加这一行来打印 PROJECT_SOURCE_DIR 的值
#message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
#message(STATUS "CATKIN_DEVEL_PREFIX = ${CATKIN_DEVEL_PREFIX}")

# 打印所有CMake变量（这会产生大量输出）
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
 message(STATUS "CMake内置的变量 ${_variableName}=${${_variableName}}")
endforeach()
