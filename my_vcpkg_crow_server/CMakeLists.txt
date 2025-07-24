# 指定所需 CMake 最低版本
cmake_minimum_required(VERSION 3.15)

# 项目名称
project(MyCrowServer)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
# 是否必须使用当前设置的C++版本
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 如果未指定 vcpkg 工具链，报错提示用户
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "请在 cmake 命令里指定 vcpkg 工具链文件，例如：cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake")
endif()

# 查找 nlohmann_json 包（CMake Config 模式），必须找到
find_package(nlohmann_json CONFIG REQUIRED)

# 添加可执行文件：server，源文件为 src/server.cpp
add_executable(server src/server.cpp)

# 链接 nlohmann_json 和 pthread
target_link_libraries(server PRIVATE nlohmann_json::nlohmann_json pthread)
