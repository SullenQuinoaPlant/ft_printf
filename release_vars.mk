
NAME = ftprintf
LIBNAME = libftprintf

ROOT = .
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)
LIBS_I := $(ROOT)/includes
OUT_DIR_LIB := $(ROOT)
OUT_DIR_H := $(INC_DIR)

SRCS := $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

DEPENDENCIES =\
	libmyvaltobuffers\
	libmyutf8\
	libmystupidmath\
	libmyfloatingpoint\
	libft

CC := gcc
ARCH := ARCH_A
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -D $(ARCH)
endif
CFLAGS += $(CFLAGS_MORE)
