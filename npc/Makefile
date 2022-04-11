BUILD_DIR = ./build
# design module
TOPNAME = Multiplexer
# name of object to generate the verilog of design
TOPMODULE_GEN = $(TOPNAME)Gen
GEN_DIR = $(BUILD_DIR)/circuit_exp/$(TOPNAME)
SRC_CODE_DIR = ./playground/src/circuit_exp/$(TOPNAME)

OBJ_DIR = $(GEN_DIR)/obj_dir
VERILOG_GEN = Verilog_Gen
VERILOG_OBJ_DIR = $(GEN_DIR)/$(VERILOG_GEN)
NXDC_FILES = $(SRC_CODE_DIR)/$(TOPNAME).nxdc
BIN = $(GEN_DIR)/$(TOPNAME)

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
					-O3 --x-assign fast --x-initial fast --noassert


verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(VERILOG_OBJ_DIR)
	mill -i __.test.runMain $(TOPMODULE_GEN) -td $(VERILOG_OBJ_DIR)

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/$(TOPNAME)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath $(VERILOG_OBJ_DIR)) -name  "*.v")
CSRCS = $(shell find $(abspath $(SRC_CODE_DIR)) -name  "Multiplexer_sim.cpp")#"*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS_BOARD = $(CSRCS) $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN):$(VSRCS) $(CSRCS_BOARD) $(NVBOARD_ARCHIVE)
		@rm -rf $(OBJ_DIR)
		$(VERILATOR) $(VERILATOR_CFLAGS) \
				--top-module $(TOPNAME) $^ \
				$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
				--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

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

.PHONY: test verilog help compile bsp reformat checkformat clean

sim_board:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	$^

sim_vcd:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS) --Mdir $(OBJ_DIR)  -o $(abspath $(BIN))
	$(BIN)
	gtkwave Top.vcd



include ../Makefile
