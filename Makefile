all :
	git status

############
#VARIABLES :

include make_vars.mk

#######
#CORE :

.PHONY :
.PHONY : $(NAME) $(OBJ_DIR)/%.o clean fclean re
$(NAME) $(OBJ_DIR)/%.o clean fclean re :
	git status
	$(MAKE) -f Makefile.mk $(MAKECMDGOALS)


#######
#LIBS :

include libs/Makefile

########
#TESTS :
	
include unit-tests/Makefile


#########
#OUTPUT :

OUT = NAME
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
