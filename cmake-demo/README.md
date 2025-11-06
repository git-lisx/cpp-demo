# cmake-demo

一个最小的 C++ + CMake 演示项目

## 编译&运行

推荐使用自带的 `build.sh`（若存在且可执行）：

```bash
./build.sh
```

或手动使用 CMake：

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

构建成功后，可执行文件位于 `build/` 目录下（通常名为 `demo`）。

进入构建目录并运行二进制：

```bash
cd build
./demo
```


或不使用cmake编译：

```bash
g++ -std=c++14 src/main.cpp src/demo/person.cpp -Iinclude -o demo
./demo

```
解释：

-Iinclude 告诉编译器去 include/ 目录找头文件。



