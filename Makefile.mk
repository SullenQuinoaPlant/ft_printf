include make_vars.mk

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

all : lib$(NAME).a

$(LIBNAME).a : $(OBJ_DIR)/$(NAME).o
	-ar rcs $@ $<
	mv $@ $(OUT_DIR_LIB)/
	cp $(SRC_DIR)/$(NAME).h $(OUT_DIR_H)/$(LIBNAME).h

$(OBJ_DIR)/$(NAME).o : $(OBJS)
	ld -r $^ -o $@

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
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all

.PHONY : re fclean clean all
