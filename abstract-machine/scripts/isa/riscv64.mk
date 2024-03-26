CROSS_COMPILE := riscv64-linux-gnu-
COMMON_FLAGS  := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
# CROSS_COMPILE := riscv64-unknown-elf-
# COMMON_FLAGS  := -fno-pic -march=rv64im_zicsr -mcmodel=medany -mstrict-align -mabi=lp64
CFLAGS        += $(COMMON_FLAGS) -static
ASFLAGS       += $(COMMON_FLAGS) -O0
LDFLAGS       += -melf64lriscv
