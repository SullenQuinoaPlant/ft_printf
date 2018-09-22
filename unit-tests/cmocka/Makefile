ifndef ROOT
 ROOT = ../..
 include $(ROOT)/make_vars.mk
endif

BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

ifndef CMAKE
 CMAKE = cmake
endif

.PHONY : cmocka
cmocka : $(BUILD_DIR) $(SOURCE_DIR) build install

.PHONY : build
build :
	cd $(BUILD_DIR) && $(CMAKE) ../$(SOURCE_DIR) && make;

.PHONY : install
install :
	cp $(SOURCE_DIR)/include/cmocka.h .
	cp $(BUILD_DIR)/src/libcmocka* .
	mv cmocka.h $(LIBS_I)
	mv libcmocka* $(LIBS_L)

$(BUILD_DIR) :
	if [ -d $(BUILD_DIR) ]; then :; else mkdir $(BUILD_DIR); fi

$(SOURCE_DIR) :
	if [ -d $(SOURCE_DIR) ]; then :; else git clone git://git.cryptomilk.org/projects/cmocka.git $(SOURCE_DIR); fi
	

clean :
	-rm libcmocka*
	-rm cmocka.h
