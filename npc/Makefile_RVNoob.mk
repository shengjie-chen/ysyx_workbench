BUILD_DIR = ./build
# design module AluFourBit LFSRegister Multiplexer PriorEncoder KeyBoard VgaOutput CharacterInput
TOPNAME = RegisterFile
SRC_DIR = ./playground/src
# name of object to generate the verilog of design
TOPMODULE_GEN = $(TOPNAME)Gen

SRC_CODE_DIR = $(shell find $(abspath $(SRC_DIR)) -maxdepth 2 -name "RVNoob")
GEN_DIR = $(subst $(abspath $(SRC_DIR)),$(BUILD_DIR),$(SRC_CODE_DIR))# $(subst FROM, TO, TEXT)，即将字符串TEXT中的子串FROM变为TO

PACKAGE = RVNoob

verilog:
	$(call git_commit, "generate $(TOPNAME) verilog")
	echo $(SRC_CODE_DIR)
	echo $(GEN_DIR)
	mkdir -p $(GEN_DIR)
	mill -i __.test.runMain $(PACKAGE).$(TOPMODULE_GEN) -td $(GEN_DIR)

test:
	mill -i __.test

help:
	mill -i __.test.runMain Elaborate --help

compile:
	mill -i __.compile

bsp:
	mill -i mill.bsp.BSP/install

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

clean:
	-rm -rf $(BUILD_DIR)

clean_object:
	rm $(BIN_BOARD)

.PHONY: test verilog help compile bsp reformat checkformat clean clean_object




include ../Makefile
