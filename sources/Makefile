ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

.PHONY : targets
targets :

.PHONY : $(ROOT)/targets.mk
$(ROOT)/targets.mk :
	@echo "TARGETS := \\" > $@
	@ls $(SRC_DIR)/*.c \
	|sed 's@.*/\([a-z0-9][a-z0-9_]*\)\.c@	\1 \\@' \
	|sed '$$s@\(.*\) \\@\1@' >> $@
