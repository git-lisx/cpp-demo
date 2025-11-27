# cpp-demo

C++项目demo

- cmake-demo：纯CMakeLists.txt项目
- my_crow_server：纯CMakeLists.txt项目 + 第三方依赖
- my_vcpkg_crow_server：CMakeLists.txt + vcpkg包管理项目

## my_crow_server

纯CMakeLists.txt项目

### 编译

```shell
# 项目结构
my_crow_server/
├── CMakeLists.txt
├── build/
├── src/
│   └── server.cpp

# 构建步骤
mkdir build
cd build
cmake ..  # 读取 CMakeLists.txt，下载依赖，生成 Makefile
make      # 编译 + 链接，生成可执行程序
./server  # 执行
```

## my_vcpkg_crow_server

CMakeLists.txt + vcpkg包管理项目

### 安装vcpkg

> 微软维护的包管理工具

链接：https://github.com/microsoft/vcpkg

```shell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh

# 配置环境变量
vim ~/.bashrc
export VCPKG_ROOT=/home/utenet/lisx/vcpkg
export PATH=$VCPKG_ROOT:$PATH
source ~/.bashrc

```

### 编译

```shell
# 项目结构
my_vcpkg_crow_server/
├── CMakeLists.txt
├── vcpkg.json
├── src/
│   └── server.cpp


# 安装依赖
cd ./cpp-demo/my_vcpkg_crow_server
vcpkg install     # 安装依赖vcpkg.json

mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
make
./server


```
