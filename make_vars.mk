NAME = ftprintf
LIBNAME = libftprintf

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(ROOT)/targets.mk
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

DEPENDENCIES =\
	libft\
	libmystupidmath\
	libmyfloatingpoint\
	libmyvaltobuffers\
	libmyutf8

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
CFLAGS_MORE = -g
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -D $(ARCH)
endif
CFLAGS += $(CFLAGS_MORE)

UTEST_DIR := $(ROOT)/unit-tests
DEBUG_DIR := $(ROOT)/debug
