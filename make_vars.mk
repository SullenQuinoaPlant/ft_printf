ifndef ROOT
	ROOT = .
endif

NAME = ft_printf

SRC_DIR	:= $(ROOT)/sources
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes

UTEST_DIR := $(ROOT)/unit-tests

CC := gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_MORE =
