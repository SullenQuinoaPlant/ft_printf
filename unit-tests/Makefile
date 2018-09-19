ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(UTEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
#BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_UTEST = -fno-builtin -g
CFLAGS_UTEST += $(CFLAGS_MORE)

TEST_DEPENDENCIES = libgetnextline libcmocka_shared



.PHONY : tests_all
tests_all : build_test_dependencies clean-tests build_tests run_tests

############
#BUILD TESTS

.PHONY : build_test_dependencies
build_test_dependencies : $(TEST_DEPENDENCIES)

.PHONY : libcmocka_shared
libcmocka_shared :
		$(MAKE) -C $(UTEST_DIR)/cmocka/;\

.PHONY : build_tests
build_tests : set_utest_flags def $(TEST_OBJS)

.PHONY : set_utest_flags
set_utest_flags :
	$(eval CFLAGS += $(CFLAGS_UTEST))

%.test.o\
$(UTEST_DIR)/%.test.o\
:\
$(UTEST_DIR)/%.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -I $(SRC_DIR)\
		-D main=testee_main\
		-include $(SRC_DIR)/$*.c\
		$<\
		-L $(LIBS_L)\
		-lcmocka_shared\
		-lmystupidmath -lmyfloatingpoint -lft\
		-o $@\
		-Wl,-rpath=$$(readlink -e $(LIBS_L))

%.test.o\
$(UTEST_DIR)/%.test.o\
:\
$(UTEST_DIR)/%.test.c $(UTEST_DIR)/printf_diff.c $(LIBS_L)/libftprintf.a
	$(CC) $(CFLAGS_UTEST)\
		-I $(SRC_DIR)\
		-I $(LIBS_I)\
		$<\
		-L $(LIBS_L)\
		-lcmocka_shared\
		-lftprintf\
		$(patsubst lib%,-l%,$(TEST_DEPENDENCIES))\
		$(patsubst lib%,-l%,$(DEPENDENCIES))\
		-o $@\
		-Wl,-rpath=$$(readlink -e $(LIBS_L))



############
#RUN TESTS :

.PHONY : unit-tests ut
unit-tests ut : list_tests build_tests run_tests

.PHONY : run_tests
run_tests : cmocka $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(UTEST_DIR)" \
	&& touch $@

.PHONY : cmocka
cmocka : 
	@if $(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
	 	$(UTEST_DIR)/cmocka/check_install.c\
		 -lcmocka_shared -o test.o\
		-Wl,-rpath=$$(readlink -e $(LIBS_L))\
		&& ./test.o .;\
	then\
		echo "cmocka installed";\
	else\
		echo "insall cmocka";\
	fi
	-@rm ./test.o


###############
#MISCELLANEOUS:
.PHONY : clean-tests
clean-tests :
	-rm $(UTEST_DIR)/*.o
	-rm $(UTEST_DIR)/*.stamp

.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
