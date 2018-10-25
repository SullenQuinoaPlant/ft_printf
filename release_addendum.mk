
#################
#RELEASE ADDENDUM

$(patsubst %,$(LIBS_L)/%.a,$(DEPENDENCIES)):
	$(MAKE) -C $(LIB_DIR)/$(*F)
	cp $(LIB_DIR)/$(*F)/$(*F).a $(OBJ_DIR)
