TARGETS := \
	convert_a \
	convert_a_stuffers1 \
	convert_a_stuffers2 \
	convert_apostrophe_flag_auxilliaries \
	convert_b \
	convert_b_outputters \
	convert_b_stuffers \
	convert_big_k \
	convert_big_k_stuffers \
	convert_c \
	convert_d \
	convert_d_stuffers \
	convert_e \
	convert_e_outputters \
	convert_e_stuffers1 \
	convert_e_stuffers2 \
	convert_f \
	convert_f_stuffers1 \
	convert_f_stuffers2 \
	convert_fp_to_decimal1 \
	convert_fp_to_decimal2 \
	convert_g \
	convert_g_estuffers1 \
	convert_g_estuffers2 \
	convert_g_fstuffers1 \
	convert_g_fstuffers2 \
	convert_i \
	convert_k \
	convert_n \
	convert_nospecifier \
	convert_o \
	convert_o_stuffers \
	convert_p \
	convert_p_stuffers \
	convert_pct \
	convert_r \
	convert_s \
	convert_s_hashcharstr \
	convert_s_wcharstr \
	convert_sign \
	convert_syllable_auxilliaries \
	convert_u \
	convert_u_stuffers \
	convert_x \
	convert_x_stuffers \
	etypes_get_etype \
	etypes_sizeof_etype \
	ft_printf \
	get_va_args \
	get_va_args__vaarger_functions1 \
	get_va_args__vaarger_functions2 \
	get_va_args__vaarger_functions3 \
	get_va_args__vaarger_functions4 \
	get_va_args__vaarger_functions5 \
	get_va_args__vaarger_functions6 \
	get_vaarged_floatingpoint \
	global_output_state_auxilliaries \
	global_parse_state_auxilliaries \
	output_chunks \
	output_control \
	output_control_filedescriptor \
	output_fp \
	output_generic \
	output_nan_inf \
	output_nil_null \
	output_padding \
	output_percent_chunk \
	output_simple_chunks \
	output_string \
	output_syllables \
	outputter_auxilliaries \
	pad_syllables \
	parse_auxilliaries \
	parse_format_string \
	parse_format_string_percent \
	parse_format_string_percent_char \
	parse_format_string_percent_control \
	parse_format_string_percent_control_filedes \
	parse_format_string_percent_conversion \
	parse_format_string_percent_conversion_fillers1 \
	parse_format_string_percent_conversion_fillers2 \
	parse_format_string_text \
	parse_literal_integer \
	parse_percent_star_arg \
	parse_state_store_integer \
	tscc_to_tsso \
	tstuffer_auxilliaries

NAME = ftprintf
LIBNAME = libftprintf

ROOT := .
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

.PHONY : all
all : library header

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

.PHONY : library
library : $(OUT_DIR_LIB)/$(LIBNAME).a


##############
#compilation :
ifdef FAT_STATIC_LIBRARY
$(OUT_DIR_LIB)/$(LIBNAME).a :\
$(patsubst %,$(LIBS_L)/%.a,$(DEPENDENCIES)) $(OBJS)\
else
$(OUT_DIR_LIB)/$(LIBNAME).a :\
$(OBJS)
endif
	-libtool -static -o $@ -s $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-o $@ -c $<

$(OUT_DIR_H)/$(LIBNAME).h :
	cp $(INC_DIR)/$(NAME).h $@


###############
#miscellaneous:
.PHONY : re fclean clean all
clean :
	-rm $(OBJS)

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all

.PHONY : $(DEPENDENCIES)
$(DEPENDENCIES) :
	$(MAKE) -C $(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/$@.a $(OBJ_DIR)
