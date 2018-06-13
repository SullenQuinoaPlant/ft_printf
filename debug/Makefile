ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif

.PHONY : debug
debug : debug.o
	gdb $(DEBUG_DIR)/debug.o

debug.o :
	$(MAKE) -C $(ROOT) CFLAGS_MORE=-g def
	$(CC) -g \
		-I $(ROOT)/$(LIBS_I) \
		-L $(ROOT)/$(LIBS_L) \
		$(DEBUG_DIR)/debug.c \
		-lftprintf -lft \
		-o $(DEBUG_DIR)/$@
