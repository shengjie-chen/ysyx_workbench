CLEAN_ALL = $(dir $(shell find . -mindepth 2 -name Makefile))
$(info ###clean $(CLEAN_ALL))
clean-all: $(CLEAN_ALL)
$(CLEAN_ALL):
	-@$(MAKE) -s -C $@ clean

.PHONY: clean-all $(CLEAN_ALL)