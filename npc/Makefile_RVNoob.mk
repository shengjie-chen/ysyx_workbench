BUILD_DIR = ./build
# design module AluFourBit LFSRegister Multiplexer PriorEncoder KeyBoard VgaOutput CharacterInput
TOPNAME = RVNoob
SRC_DIR = ./playground/src
# name of object to generate the verilog of design
TOPMODULE_GEN = $(TOPNAME)Gen

SRC_CODE_DIR = $(shell find $(abspath $(SRC_DIR)) -maxdepth 2 -name "RVNoob")
GEN_DIR = $(subst $(abspath $(SRC_DIR)),$(BUILD_DIR),$(SRC_CODE_DIR))# $(subst FROM, TO, TEXT)，即将字符串TEXT中的子串FROM变为TO

PACKAGE = RVNoob

OBJ_DIR = $(GEN_DIR)/obj_dir
VERILOG_GEN = Verilog_Gen
VERILOG_OBJ_DIR = $(GEN_DIR)/$(VERILOG_GEN)
VERILOG_OBJ_DIR = $(GEN_DIR)/$(TOPNAME)

verilog:
	$(call git_commit, "generate $(TOPNAME) verilog")
	echo $(SRC_CODE_DIR)
	echo $(GEN_DIR)
	mkdir -p $(GEN_DIR)
	mill -i __.test.runMain $(PACKAGE).$(TOPMODULE_GEN) -td $(VERILOG_OBJ_DIR)

sim_vcd:
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) --Mdir $(OBJ_DIR)  -o $(abspath $(BIN_VCD))
	$(BIN_VCD)
	gtkwave $(GEN_DIR)/$(TOPNAME).vcd

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
