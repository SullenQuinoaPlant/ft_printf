NAME = ft_printf
TARGETS =

OBJ_DIR = ./objects
SRC_DIR = ./sources

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC = gcc
ifndef
	CFLAGS = -Wall -Wextra -Werror
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS)\
		-o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | objdir
	$(CC) $(CFLAGS)\
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
