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

sim_vcd: verilog
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) --Mdir $(OBJ_DIR)  -o $(abspath $(BIN_VCD))
	$(BIN_VCD)
	gtkwave $(GEN_DIR)/$(TOPNAME).vcd

IMG=/home/jiexxpu/ysyx/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv64-npc.bin
# sdb itrace mtrace ftrace
ARGS=sdb_y elf=$(basename $(IMG)).elf diff=/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/riscv64-nemu-interpreter-so
DISASM_CXXSRC = /home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/disasm.cc
DISASM_CXXFLAGS = $(shell llvm-config --cxxflags) -fPIE
DISASM_LIBS = $(shell llvm-config --libs) -O2 -fsanitize=address -pie -ldl
sim_npc_vcd: verilog
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	mkdir -p $(OBJ_DIR)
	g++ -O2 -MMD -Wall -Werror -save-temps $(DISASM_CXXFLAGS) -c -o $(abspath $(OBJ_DIR)/disasm.o) $(DISASM_CXXSRC)
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) $(abspath $(OBJ_DIR)/disasm.o) -o $(abspath $(BIN_VCD)) $(addprefix -LDFLAGS ,$(DISASM_LIBS))  # $(addprefix -CFLAGS ,$(CXXFLAGS))
	$(BIN_VCD) $(IMG) $(ARGS)
	gtkwave $(GEN_DIR)/$(TOPNAME).vcd

sim_npc_vcd_without_regen:
	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
	mkdir -p $(OBJ_DIR)
	g++ -O2 -MMD -Wall -Werror -save-temps $(DISASM_CXXFLAGS) -c -o $(abspath $(OBJ_DIR)/disasm.o) $(DISASM_CXXSRC)
	verilator --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) $(abspath $(OBJ_DIR)/disasm.o) -o $(abspath $(BIN_VCD)) $(addprefix -LDFLAGS ,$(DISASM_LIBS))  # $(addprefix -CFLAGS ,$(CXXFLAGS))
	$(BIN_VCD) $(IMG) $(ARGS)
	gtkwave $(GEN_DIR)/$(TOPNAME).vcd

# sim_npc_vcd_without_regen_gdb:
# 	$(call git_commit, "sim $(TOPNAME) RTL") # DO NOT REMOVE THIS LINE!!!
# 	@echo "Write this Makefile by yourself."
# 	mkdir -p $(OBJ_DIR)
# 	g++ -O2 -MMD -Wall -Werror -save-temps $(DISASM_CXXFLAGS) -c -o $(abspath $(OBJ_DIR)/disasm.o) $(DISASM_CXXSRC)
# 	verilator --cc $(VSRCS) --trace --exe --build --gdb $(CSRCS_VCD) $(abspath $(OBJ_DIR)/disasm.o) -o $(abspath $(BIN_VCD)) $(addprefix -LDFLAGS ,$(DISASM_LIBS))  
# 	gdb $(abspath $(BIN_VCD)) --args $(IMG) $(ARGS)
# 	gtkwave $(GEN_DIR)/$(TOPNAME).vcd
#$(abspath $(OBJ_DIR)/disasm.o)
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
