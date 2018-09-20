ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)

define BUILD_LIB
	$(MAKE) -C $(LIB_DIR)/$@/ 
	cp $(LIB_DIR)/$@/$@.a $(LIBS_L)
	cp $(LIB_DIR)/$@/includes/$@.h $(LIBS_I)
endef
	
libft :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)


libmystupidmath :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_stupidmath.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)


libmyfloatingpoint :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_floatingpoint.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)

libmyvaltobuffers :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_valuestobuffers.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)

libmyutf8 :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_utf8.git \
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)

libgetnextline :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/get_next_line.git\
		--depth 1 \
		$(LIB_DIR)/$@/
	$(BUILD_LIB)

.PHONY : clean-lib*
clean-lib% :
	-rm -rf $(LIB_DIR)/lib$*
	-rm $(LIBS_I)/lib$*.h
	-rm $(LIBS_L)/lib$*.a

CLEAN_ALL_LIBS = $(patsubst %,clean-%,$(DEPENDENCIES))
.PHONY : clean_libs
clean_libs : $(CLEAN_ALL_LIBS)

.PHONY : libs_re
libs_re : clean_libs build_dependencies
