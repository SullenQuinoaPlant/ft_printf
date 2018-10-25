
$(LIBS_L)/$(DEPENDENCIES).a :
	$(MAKE) -C $(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/$@.a $(OBJ_DIR)
