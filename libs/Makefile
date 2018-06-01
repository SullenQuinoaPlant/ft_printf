ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif

BUILD_DIR = winterwindswouldwindwistfullywhencewantonwhorshipperswailed

build_dir :
	if [ -d $(BUILD_DIR) ];then exit 1; fi


libft.% : $(LIBS_I)/libft.h $(LIBS_L)/libft.a | build_dir
	git clone --single-branch -b the_lib https://github.com/SullenQuinoaPlant/Libft.git $(BUILD_DIR)/
	$(MAKE) -C $(BUILD_DIR)/ $@
	cp $(BUILD_DIR)/libft.a $(LIBS_L)
	cp $(BUILD_DIR)/libft.h $(LIBS_I)
	rm -rf $(BUILD_DIR)
	touch $(LIB_DIR)/libft

$(LIBS_I)/libft.h :
	@:

$(LIBS_L)/libft.a :
	@:

.PHONY : clean-libft
clean-libft :
	-rm libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
