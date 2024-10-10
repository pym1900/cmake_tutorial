cmake_minimum_required(VERSION 3.10)
project(UseHello)
add_executable(main main.cc)

cmake_minimum_required(VERSION 3.10)
project(UseHello)

# 添加头文件搜索路径
include_directories(/usr/local/include/hello)

find_library(HELLO_LIBRARY NAMES hello PATHS${CMAKE_LIBRARY_PATH})

if(HELLO_LIBRARY)
    target_link_libraries(main ${HELLO_LIBRARY})
endif()