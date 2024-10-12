# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 查找 OpenCV库
find_package(OpenCV REQUIRED)

# 包含 OpenCV 的头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 输出 OpenCV 版本信息，便于调试
message("OpenCV version is ${OpenCV_VERSION}")

# 自动查找 cv 目录下的源文件并将其添加到变量 cv_src 中
aux_source_directory(cv cv_src)

# 创建共享库 modules，将 cv 目录中的源文件编译为共享库
add_library(modules SHARED ${cv_src})

# 链接 OpenCV库到 modules 共享库
target_link_libraries(modules
    ${OpenCV_LIBS}
)