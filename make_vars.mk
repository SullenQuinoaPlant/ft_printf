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
UTEST_DIR := $(ROOT)/unit-tests
DEBUG_DIR := $(ROOT)/debug

include $(ROOT)/targets.mk
SRCS := $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
INCS := $(INC_DIR)/*.h
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

DEPENDENCIES =\
	libmyvaltobuffers\
	libmyutf8\
	libmystupidmath\
	libmyfloatingpoint\
	libft

ifndef TOOLS
	TOOLS := MAC
endif

ifndef ARCH
	ARCH := ARCH_A
endif

ifndef BEHAVIOR
	BEHAVIOR := MAC
endif

ifeq ($(TOOLS),MAC)
	TEST_CC := gcc-8.2.0
else
	TEST_CC := gcc
endif

CC := gcc

CC_DEFINES := $(BEHAVIOR) $(ARCH)
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror\
			-I $(INC_DIR) -I $(LIBS_I)\
			$(patsubst %,-D%,$(CC_DEFINES))
endif
CFLAGS_MORE = -g
CFLAGS += $(CFLAGS_MORE)
