```
# 定义编译器
CC = g++

# 编译选项
CFLAGS = -Wall -g

# 可执行文件名称
TARGET = main

# 源文件
SRCS = main.cc

# 目标文件 (将 .cc 文件编译为 .o 文件)
OBJS = $(SRCS:.cc=.o)

# 链接的库 (例如 math 库)
LIBS = -lm  # 数学库使用 -lm，如果有其他库，添加它们

# 库路径 (如果库在自定义路径)
LIBDIR = /path/to/custom/library

# 默认目标
all: $(TARGET)

# 生成可执行文件并链接外部库
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# 编译源文件为目标文件
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

# 清理命令
clean:
	rm -f $(OBJS) $(TARGET)
```