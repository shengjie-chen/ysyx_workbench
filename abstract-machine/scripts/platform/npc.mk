AM_SRCS := platform/npc/trm.c \
           platform/npc/ioe/ioe.c \
           platform/npc/ioe/timer.c \
           platform/npc/ioe/input.c \
           platform/npc/ioe/gpu.c \
           platform/npc/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
             --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
NPCFLAGS += -l $(shell dirname $(IMAGE).elf)/npc-log.txt

CFLAGS += -DMAINARGS=\"$(mainargs)\"
CFLAGS += -I$(AM_HOME)/am/src/platform/npc/include
.PHONY: $(AM_HOME)/am/src/platform/npc/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_gtk IMG=$(IMAGE).bin PRJNAME=RVNoobSim

# $(MAKE) -C $(NPC_HOME) sim_npc_vcd IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_gtk IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_regen IMG=$(IMAGE).bin
# $(MAKE) -C $(NPC_HOME) sim_npc_vcd_without_regen_gtk IMG=$(IMAGE).bin SDB=sdb_n
	
# gdb: image
# 	$(MAKE) -C $(NEMU_HOME) ISA=$(ISA) gdb ARGS="$(NPCFLAGS)" IMG=$(IMAGE).bin
