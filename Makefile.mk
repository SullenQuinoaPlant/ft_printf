NAME = ft_printf
TARGETS =

OBJ = ./objects
SRC = ./sources

OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))

ifndef ROOT
	LIB_DIR = ./libs/objects
	LIB_H_DIR  = ./libs/includes
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_MORE =


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		-o $(NAME) $(OBJS)

$(OBJ)/%.o : $(SRC)/%.c | objdir
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		-o $@ -c $<

.PHONY : objdir
objdir :
	if [ ! -d $(OBJ) ]; then\
		mkdir $(OBJ);\
	fi

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
