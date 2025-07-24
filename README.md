# cpp-demo

C++项目demo

- my_crow_server：纯CMakeLists.txt项目
- my_vcpkg_crow_server：CMakeLists.txt + vcpkg包管理项目

## vcpkg

链接：https://github.com/microsoft/vcpkg
安装

```shell
# 安装
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh

# 配置环境变量
vim ~/.bashrc
export VCPKG_ROOT=/home/utenet/lisx/vcpkg
export PATH=$VCPKG_ROOT:$PATH
source ~/.bashrc

```

## 编译自己的项目

```shell
my_vcpkg_crow_server/
├── CMakeLists.txt
├── vcpkg.json
├── src/
│   └── server.cpp


# 安装依赖
cd /home/utenet/lisx/my_vcpkg_crow_server
vcpkg install     # 安装依赖vcpkg.json

mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
make
./server


```