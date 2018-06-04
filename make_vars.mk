ifndef ROOT
	ROOT = .
endif

NAME = ft_printf

SRC_DIR	:= $(ROOT)/sources
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes

include $(SRC_DIR)/targets.mk

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -D $(ARCH)
endif
CFLAGS_MORE =

UTEST_DIR := $(ROOT)/unit-tests
