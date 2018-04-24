all :
	git status

############
#VARIABLES :

include make_vars.mk

#######
#CORE :

.PHONY : $(NAME) $(OBJ_DIR)/%.o clean fclean re
$(NAME) clean fclean re d:
	$(MAKE) -f Makefile.mk \
	LIBFT_IDIR=$(LIBS_I) LIBFT_LDIR=$(LIBS_L) \
	LIBFT_DIR=$(LIB_DIR) \
	$@
$(OBJ_DIR)%.o :
	$(MAKE) -f Makefile.mk \
	LIBFT_IDIR=$(LIBS_I) LIBFT_LDIR=$(LIBS_L) \
	LIBFT_DIR=$(LIB_DIR) \
	$@


#######
#LIBS :

include libs/Makefile

########
#TESTS :
	
include unit-tests/Makefile


#########
#OUTPUT :

OUT = $(subst $(NAME), out_$(NAME), $(NAME))
.PHONY : clean-ft_printf
clean-ft_printf :
	if ! [ -d $(OUT) ]; then mkdir $(OUT); fi
	cp auteur $(OUT)/
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $(OUT)/libft
	cp Makefile.mk $(OUT)/Makefile
	cp -r $(SRC_DIR)/ $(OUT)/


################
#MISCELLANEOUS :

.PHONY : c
c :
	git commit -a -m i

.PHONY : p
p :
	git push
