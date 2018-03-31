#######
#######
#CORE :

include make_vars.mk
include Makefile.mk



########
########
#OTHER :

#######
#LIBS :

include libs/Makefile

########
#TESTS :

.PHONY : libproject 
	
include unit-tests/Makefile



#########
#OUTPUT :

OUT = ft_printf
clean-ft_printf :
	if ! [ -d $(OUT) ]; then mkdir $(OUT); fi
	cp auteur $(OUT)/
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $(OUT)/libft
