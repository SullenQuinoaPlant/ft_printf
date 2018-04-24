NAME = ft_printf
TARGETS =

OBJ_DIR = ./objects
SRC_DIR = ./sources
LIBFT_IDIR = ./libft
LIBFT_LDIR = ./libft
LIBFT_DIR = ./libft

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CC = gcc
ifndef
	CFLAGS = -Wall -Wextra -Werror
endif

all : $(NAME).a

$(NAME).a : $(OBJS)
		-ar rcs $@ $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | objdir
	$(CC) $(CFLAGS)\
		-I $(LIBFT_IDIR)\
		-o $@ -c $<

.PHONY : objdir
objdir :
	if [ ! -d $(OBJ_DIR) ]; then\
		mkdir $(OBJ_DIR);\
	fi

d : libft
.PHONY : libft
libft :
	$(MAKE) -C $(LIBFT_DIR) $@.a

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
