AM_SRCS := platform/ysyxsoc/trm.c \
           platform/ysyxsoc/ioe/ioe.c \
           platform/ysyxsoc/ioe/timer.c \
           platform/ysyxsoc/ioe/input.c \
           platform/ysyxsoc/ioe/gpu.c \
           platform/ysyxsoc/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/soc-linker.ld \
             --defsym=_mrom_start=0x20000000 --defsym=_entry_offset=0x0
            #  --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/ysyxsoc-log.txt

CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(AM_HOME)/am/src/platform/ysyxsoc/include
.PHONY: $(AM_HOME)/am/src/platform/ysyxsoc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_gtk IMG=$(IMAGE).bin PRJNAME=ysyxSoCFull

# $(MAKE) -C $(NPC_HOME) sim_npc_vcd IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_gtk IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_regen IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_regen_gtk IMG=$(IMAGE).bin SDB=sdb_n
	
# gdb: image
# 	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
