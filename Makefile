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
