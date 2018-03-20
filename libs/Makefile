ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif

BUILD_DIR = oaeuhtns

nop :
	@:


libft : $(LIBS_I)/libft.h $(LIBS_L)/libft.a
	-rm -rf $(BUILD_DIR)
	git clone --single-branch -b the_lib https://github.com/SullenQuinoaPlant/Libft.git $(BUILD_DIR)/
	$(MAKE) -C $(BUILD_DIR)/
	cp $(BUILD_DIR)/libft.a $(LIBS_L)
	cp $(BUILD_DIR)/libft.h $(LIBS_I)
	rm -rf $(BUILD_DIR)
	touch libft

$(LIBS_I)/libft.h :
	@:

$(LIBS_L)/libft.a :
	@:

.PHONY : clean-libft
clean-libft :
	-rm libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
