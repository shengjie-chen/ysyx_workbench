-include $(NEMU_HOME)/../Makefile
include $(NEMU_HOME)/scripts/build.mk

include $(NEMU_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NEMU")
$(BINARY): compile_git

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)

# Command to execute NEMU
IMG ?=
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)

run: run-env
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)

gdb: run-env
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY) --args $(NEMU_EXEC)

INIT_C_LINE=17252
INIT_H_LINE=1898
CURR_C_LINE=$(shell find $(NEMU_HOME) -name "*.c" | xargs grep '^.'|wc -l)
CURR_H_LINE=$(shell find $(NEMU_HOME) -name "*.h" | xargs grep '^.'|wc -l)
NEW_C_LINE=$(shell echo $(CURR_C_LINE)-$(INIT_C_LINE) | bc)
NEW_H_LINE=$(shell echo $(CURR_H_LINE)-$(INIT_H_LINE) | bc)
count: 
	@echo Total C file valid lines: $(CURR_C_LINE)
	@echo New C file valid lines: $(NEW_C_LINE)
	@echo Total H file valid lines: $(CURR_H_LINE)
	@echo New H file valid lines: $(NEW_H_LINE)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)
