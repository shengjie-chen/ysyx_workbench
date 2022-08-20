BUILD_DIR = ./build
# design module AluFourBit LFSRegister Multiplexer PriorEncoder KeyBoard VgaOutput CharacterInput
TOPNAME = RVNoob
SRC_DIR = ./playground/src
# name of object to generate the verilog of design
TOPMODULE_GEN = $(TOPNAME)Gen

SRC_CODE_DIR = $(shell find $(abspath $(SRC_DIR)) -maxdepth 2 -type d -name "$(TOPNAME)")
GEN_DIR = $(subst $(abspath $(SRC_DIR)),$(BUILD_DIR),$(SRC_CODE_DIR))# $(subst FROM, TO, TEXT)，即将字符串TEXT中的子串FROM变为TO

PACKAGE = $(subst /,.,$(subst $(abspath $(SRC_DIR))/,,$(SRC_CODE_DIR)))

OBJ_DIR = $(GEN_DIR)/obj_dir
VERILOG_GEN = Verilog_Gen
VERILOG_OBJ_DIR = $(GEN_DIR)/$(VERILOG_GEN)
NXDC_FILES = $(SRC_CODE_DIR)/$(TOPNAME).nxdc
BIN_BOARD = $(GEN_DIR)/$(TOPNAME)
BIN_VCD = $(GEN_DIR)/$(TOPNAME)

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
					-O3 --x-assign fast --x-initial fast --noassert

# constraint file
SRC_AUTO_BIND = $(abspath ./nvboard_constr/auto_bind.cpp)# The file is initialized manually
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
SSRCS = $(shell find $(abspath $(SRC_CODE_DIR)) -name  "*.scala")
SSRCS += $(shell find $(abspath $(SRC_CODE_DIR)) -name  "*.v")
VSRCS = $(shell find $(abspath $(VERILOG_OBJ_DIR)) -name  "*.v")
VSRCS += $(shell find $(abspath $(SRC_CODE_DIR)) -name  "*.v")# add blackbox verilog file
CSRCS_BOARD = $(shell find $(abspath $(SRC_CODE_DIR)) -name  "$(TOPNAME).cpp")#"Multiplexer_sim.cpp")#"*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS_BOARD += $(SRC_AUTO_BIND)
CSRCS_VCD = $(shell find $(abspath $(SRC_CODE_DIR)) -name  "$(TOPNAME)_sim.cpp")

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN_BOARD):$(VSRCS) $(CSRCS_BOARD) $(NVBOARD_ARCHIVE)
		@rm -rf $(OBJ_DIR)
		echo $(VSRCS)
		$(VERILATOR) $(VERILATOR_CFLAGS) \
				--top-module $(TOPNAME) $^ \
				$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
				--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN_BOARD))


verilog:
	$(call git_commit, "generate $(TOPNAME) verilog")
	echo $(SRC_CODE_DIR)
	echo $(GEN_DIR)
	mkdir -p $(VERILOG_OBJ_DIR)
	mill -i __.test.runMain $(PACKAGE).$(TOPMODULE_GEN) -td $(VERILOG_OBJ_DIR)

# before run, make verilog
sim_board:$(BIN_BOARD)
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	$^

IMG=/home/jiexxpu/ysyx/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv64-npc.bin
# sdb itrace mtrace ftrace
FUN=sdb
sim_vcd: verilog
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	# g++ -O2 -MMD -Wall -Werror -save-temps -I/home/jiexxpu/ysyx/ysyx-workbench/nemu/include -I/home/jiexxpu/ysyx/ysyx-workbench/nemu/src/engine/interpreter -I/home/jiexxpu/ysyx/ysyx-workbench/nemu/src/isa/riscv64/include -O2  -Og -ggdb3 -fsanitize=address -DITRACE_COND=true -D__GUEST_ISA__=riscv64 -I/usr/lib/llvm-12/include -std=c++14   -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fPIE -c -o /home/jiexxpu/ysyx/ysyx-workbench/nemu/build/obj-riscv64-nemu-interpreter/src/utils/disasm.o src/utils/disasm.cc
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) --Mdir $(OBJ_DIR)  -o $(abspath $(BIN_VCD))
	$(BIN_VCD) $(IMG) $(FUN)
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
