# ./CMakeLists.txt
PROJECT(HELLO)
# 添加⼦⽬录
ADD_SUBDIRECTORY(src bin)
# 安装⼆进制⽂件和脚本
INSTALL(TARGETS hello DESTINATION /usr/local/bin)
INSTALL(PROGRAMS runhello.sh DESTINATION /usr/local/bin)