
NAME = ftprintf
LIBNAME = libftprintf

SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(ROT)
OUT_DIR_H := $(LIBS_I)

SRCS := $(patsubst %,$(SRC_DIR)/%.c,$(TARGETS))
OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

DEPENDENCIES =\
	libmyvaltobuffers\
	libmyutf8\
	libmystupidmath\
	libmyfloatingpoint\
	libft

FAT_STATIC_LIBRARY = 1


####################
#compiling options :

#options are ARCH_A and 'add another to limbmyfloatingpoint'
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



CC := gcc
CC_DEFINES := $(ARCH) $(BEHAVIOR) $(ROUNDING_BEHAVIOR)
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror\
			-I $(INC_DIR) -I $(LIBS_I)\
			$(patsubst %,-D%,$(CC_DEFINES))
endif
CFLAGS_MORE =
CFLAGS += $(CFLAGS_MORE)
