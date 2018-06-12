ifndef ROOT
	ROOT = .
endif

NAME = ftprintf
LIBNAME = libftprintf

SRC_DIR	:= $(ROOT)/sources
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(SRC_DIR)/targets.mk

CC := gcc
ifndef ARCH
	ARCH := ARCH_A
endif
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -D $(ARCH)
endif
CFLAGS += $(CFLAGS_MORE)

UTEST_DIR := $(ROOT)/unit-tests
DEBUG_DIR := $(ROOT)/debug
