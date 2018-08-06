ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif

all : $(OUT_DIR_LIB)/$(LIBNAME).a


OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJ_DIR)/$(NAME).o
	-ar rcs $@ $<
	cp $(SRC_DIR)/$(NAME).h $(OUT_DIR_H)/$(LIBNAME).h

$(OBJ_DIR)/$(NAME).o : $(OBJS)
	ld -r $^ -o $@

#compilation :
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

#specifc file dependencies:
$(SRC_DIR)/parse_format_string.c \
$(SRC_DIR)/my_lstappend.c \
:\
$(SRC_DIR)/my_lstappend.h
	touch $@

$(SRC_DIR)/my_utf8.c : $(SRC_DIR)/my_utf8.h
	touch $@



#miscellaneous:
.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
