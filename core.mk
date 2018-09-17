ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif


.PHONY : all
all : library header

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

.PHONY : library
library : $(OUT_DIR_LIB)/$(LIBNAME).a


##############
#compilation :
$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJ_DIR)/$(NAME).o
	-ar rcs $@ $<
	cp $(SRC_DIR)/$(NAME).h $(OUT_DIR_H)/$(LIBNAME).h

$(OBJ_DIR)/$(NAME).o : $(OBJS)
	ld -r $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

$(OUT_DIR_H)/$(LIBNAME).h :
	cp $(INC_DIR)/$(NAME).h $@


###############
#miscellaneous:
.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
