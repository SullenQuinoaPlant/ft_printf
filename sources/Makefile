ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

targets :
	@echo "TARGETS := \\" > $(SRC_DIR)/targets.mk
	@ls $(SRC_DIR)/*.c \
	|sed 's@.*/\([a-z0-9][a-z0-9_]*\)\.c@	\1 \\@' \
	|sed '$$s@\(.*\) \\@\1@' >> $(SRC_DIR)/targets.mk
	$(eval include $(SRC_DIR)/targets.mk)
