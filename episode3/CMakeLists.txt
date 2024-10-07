cmake_minimum_required(VERSION 3.0)

project(HELLO)
set(SRC_LIST main.cc)

message("Global Source Directory: ${HELLO_SOURCE_DIR}")
message("Global Binary Directory: ${HELLO_BINARY_DIR}")

add_executable(HELLO ${SRC_LIST})