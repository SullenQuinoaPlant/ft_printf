ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif


libft :
	git clone \
		--single-branch \
		-b the_lib https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$(BUILD_DIR)/
	$(MAKE) -C $(BUILD_DIR)/ $@
	cp $(BUILD_DIR)/libft.a $(LIBS_L)
	cp $(BUILD_DIR)/libft.h $(LIBS_I)
	rm -rf $(BUILD_DIR)
	touch $(LIB_DIR)/libft


.PHONY : clean-libft
clean-libft :
	-rm libft
	-rm $(LIBS_I)/libft.h
	-rm $(LIBS_L)/libft.a
