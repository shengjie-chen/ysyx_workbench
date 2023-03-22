

VSRCS = top.v
CSRCS_VCD = sim.cpp
OBJ_DIR = obj_dir
BIN_VCD = $(OBJ_DIR)/Vtop
run:
	verilator   --cc $(VSRCS) --trace --exe --build $(CSRCS_VCD) \
	--Mdir $(OBJ_DIR)  -o $(abspath $(BIN_VCD)) \
	--threads 2 \
	# -CFLAGS -DVL_THREADED -LDFLAGS -DVL_THREADED 
	$(BIN_VCD) 

clean:
	rm -rf $(OBJ_DIR)
	rm Top.vcd