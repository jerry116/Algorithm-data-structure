#wildcard把 指定目录下的所有后缀是c的文件全部展开。
SRCS =  $(wildcard *.c ../test/*.c)
SRCS += $(wildcard *.c ../sort/*.c)
SRCS += $(wildcard *.c ../list/*.c)
SRCS += $(wildcard *.c ../tree/*.c)
SRCS += $(wildcard *.c ../graph/*.c)

#OBJS将$(SRCS)下的.c文件转化为.o文件
OBJS = $(SRCS:.c = .o)

CC = gcc

#头文件查找路径
INCLUDES = -I../include \
           -I. \

#链接库查找地址
LIBS = 

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
