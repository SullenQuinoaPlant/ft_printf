def : targets all

############
#VARIABLES :

#include make_vars.mk #included in core.

#######
#CORE :

include Makefile.mk


##########
#TARGETS :

include sources/Makefile


#######
#LIBS :

include libs/Makefile

########
#TESTS :
	
include unit-tests/Makefile

########
#DEBUG :

include debug/Makefile


#########
#OUTPUT :

OUT = out_$(NAME)

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

.PHONY : cp
cp :
	git commit -a -m i; git push;
