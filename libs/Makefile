ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"

define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$@.a $(LIBS_L)
	cp $@/$@.h $(LIBS_I)
	rm -rf $@
	touch $(LIB_DIR)/$@
endef
	
libft :
	git clone \
		--single-branch \
		-b the_lib https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)


libmystupidmath :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_stupidmath.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)


libmyfloatingpoint :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_floatingpoint.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)


.PHONY : clean-*
clean-% :
	-rm $(LIB_DIR)/$*
	-rm $(LIBS_I)/$*.h
	-rm $(LIBS_L)/$*.a
