#wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是c的文件全部展开。
SRCS =  $(wildcard *.c ../lib/*.c)
SRCS += $(wildcard *.c ../source/*.c)

#OBJS将$(SRCS)下的.c文件转化为.o文件
OBJS = $(SRCS:.c = .o)

CC = gcc

#头文件查找路径
INCLUDES = -I../include \
           -I. \

#链接库查找地址
LIBS = -L../lib

#
CCFLAGS = -g -Wall -O0

OUTPUT = lemon.out

all:$(OUTPUT)

$(OUTPUT) : $(OBJS)
	    $(CC) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.c
	    $(CC) -c $< $(CCFLAGS)

clean:
	    rm -rf *.out *.o

.PHONY:clean
