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


####################
#compiling options :

#options are ARCH_A and 'add one to limbmyfloatingpoint'
ifndef ARCH
	ARCH := ARCH_A
endif

#options are MAC, GNU, MINE
ifndef BEHAVIOR
	BEHAVIOR := PRTF_BEHAVIOR_MAC
endif

ifeq ($(BEHAVIOR), PRTF_BEHAVIOR_MAC)
	ROUNDING_BEHAVIOR := PRTF_ROUNDING_BEHAVIOR_NEAR_EVEN
endif

ifeq ($(BEHAVIOR), PRTF_BEHAVIOR_GNU)
	ROUNDING_BEHAVIOR := PRTF_ROUNDING_BEHAVIOR_NEAR_EVEN
endif

ifeq ($(BEHAVIOR), PRTF_BEHAVIOR_MINE)
	ROUNDING_BEHAVIOR := PRTF_ROUNDING_BEHAVIOR_AWAY
endif


#################
#compiling tools:

#options are MAC, GNU
ifndef TOOLS
	TOOLS := MAC
endif

ifeq ($(TOOLS),MAC)
	TEST_CC := gcc-8.2.0
else
	TEST_CC := gcc
endif

CC := gcc
CC_DEFINES := $(ARCH) $(BEHAVIOR) $(ROUNDING_BEHAVIOR)
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror\
			-I $(INC_DIR) -I $(LIBS_I)\
			$(patsubst %,-D%,$(CC_DEFINES))
endif
CFLAGS_MORE = -g
CFLAGS += $(CFLAGS_MORE)
