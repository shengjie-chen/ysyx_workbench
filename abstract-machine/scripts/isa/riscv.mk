# CROSS_COMPILE := riscv64-linux-gnu-
# COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
# CROSS_COMPILE := riscv64-unknown-elf-
# COMMON_CFLAGS  := -fno-pic -march=rv64im_zicsr -mcmodel=medany -mstrict-align -mabi=lp64

CROSS_COMPILE := riscv64-unknown-linux-gnu-
COMMON_CFLAGS  := -fno-pic -march=rv64im_zicsr_zifencei -mabi=lp64 -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
