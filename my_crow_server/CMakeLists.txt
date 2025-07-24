# 设置 CMake 最低版本要求，3.14 及以上支持 FetchContent 模块
cmake_minimum_required(VERSION 3.14)

# 定义项目名称
project(MyCrowServer)

# 设置 C++ 标准为 17，Crow 和 json 都要求 C++17 以上
set(CMAKE_CXX_STANDARD 17)

# 引入 FetchContent 模块，用于自动下载第三方依赖
include(FetchContent)

# -------------------------------
# 自动下载 Crow 库（包含 Standalone Asio）
# -------------------------------
FetchContent_Declare(
  crow                                     # 依赖名称
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git   # Crow 官方仓库地址
  GIT_TAG v1.0+3                           # 选择指定版本（推荐用 Release 版）
)
FetchContent_MakeAvailable(crow)           # 拉取并准备 Crow 库

# -------------------------------
# 自动下载 nlohmann/json 库
# -------------------------------
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3                          # 稳定版（你也可以改为最新版本）
)
FetchContent_MakeAvailable(nlohmann_json)

# -------------------------------
# 添加你的可执行程序 server，源码位于 src/server.cpp
# -------------------------------
add_executable(server src/server.cpp)

# -------------------------------
# 链接 Crow 和 nlohmann/json 库
# -------------------------------
target_link_libraries(server
  PRIVATE                                   # 只对 server 目标有效
    Crow::Crow                              # Crow 官方 CMake 导出的目标
    nlohmann_json::nlohmann_json            # nlohmann/json 官方导出的目标
)

# -------------------------------
# 可选：显示 FetchContent 下载信息（调试用）
# -------------------------------
message(STATUS "Crow 已集成，Asio 已包含")
message(STATUS "nlohmann_json 已集成")

