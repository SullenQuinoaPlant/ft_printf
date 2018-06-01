include make_vars.mk

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

all : $(NAME).a

$(NAME).a : $(OBJS)
		-ar rcs $@ $(OBJS)
		mv $@ $(LIBS_L)/
		cp $(SRC_DIR)/$(NAME).h $(LIBS_I)/

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
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
