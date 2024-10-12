cmake_minimum_required(VERSION 3.15)

# 定义项目名称
project(CMAKE_TUTORIAL)

# 定义一个名为 PROJECT_DIR 的编译宏，方便在代码中使用项目的根目录
add_compile_definitions(PROJECT_DIR="${PROJECT_SOURCE_DIR}")

# 打印项目根目录，便于调试
message("${PROJECT_DIR}")

# 指定可执行文件的生成目标，将 main.cpp 编译为可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 开启编译命令导出（用于生成 compile_commands.json，便于编辑器自动补全）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置 CMake 前缀路径，CMake 将在这里查找依赖库
set(CMAKE_PREFIX_PATH "/")

# 添加子目录 modules，进行模块构建
add_subdirectory(modules)

# 链接 modules 库到主程序 CMAKE_TUTORIAL
target_link_libraries(CMAKE_TUTORIAL modules)