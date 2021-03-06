
.PHONY : all
all : library header

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h

.PHONY : library
library : $(OUT_DIR_LIB)/$(LIBNAME).a


##############
#compilation :

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	-ar -rcs $@ $^

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
