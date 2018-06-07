include make_vars.mk

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

all : $(NAME).a

$(NAME).a : $(OBJS)
		-ar rcs $@ $(OBJS)
		mv $@ $(OUT_DIR_LIB)/
		cp $(SRC_DIR)/$(NAME).h $(OUT_DIR_H)/

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | objdir
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

.PHONY : objdir
objdir :
	if [ ! -d $(OBJ_DIR) ]; then\
		mkdir $(OBJ_DIR);\
	fi

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(OUT_DIR_LIB)/$(NAME).a
	-rm $(OUT_DIR_H)/$(NAME).h

re : fclean all

.PHONY : re fclean clean all
