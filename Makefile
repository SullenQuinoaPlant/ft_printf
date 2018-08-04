.PHONY : def
def : targets all


############
#VARIABLES :

ifndef ROOT
 ROOT := .
endif

include $(ROOT)/make_vars.mk


#######
#CORE :

include $(ROOT)/core.mk


##########
#TARGETS :

include $(SRC_DIR)/Makefile


#######
#LIBS :

include $(LIB_DIR)/Makefile

########
#TESTS :
	
include $(UTEST_DIR)/Makefile

########
#DEBUG :

include $(DEBUG_DIR)/Makefile



################
#MISCELLANEOUS :


.PHONY : cp
cp :
	git commit -a -m i; git push;

.PHONY : grm
grm :
	git reset --hard && make


.PHONY : grmt
grmt : grm
	make ut
