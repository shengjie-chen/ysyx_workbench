CLEAN_ALL = $(dir $(shell find . -mindepth 2 -name Makefile))
clean-all: $(CLEAN_ALL)
$(CLEAN_ALL):
	-@$(MAKE) -s -C $@ clean