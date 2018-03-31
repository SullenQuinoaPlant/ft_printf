NAME = ft_printf
TARGETS =

ifndef ROOT
	ROOT = .
	include $(ROOT)/make_vars.mk
endif

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_MORE =


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		-o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | objdir
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
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
