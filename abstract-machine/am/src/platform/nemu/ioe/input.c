#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000
#define CONFIG_I8042_DATA_MMIO 0xa0000060

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keydown = (inl(CONFIG_I8042_DATA_MMIO) & KEYDOWN_MASK) == KEYDOWN_MASK;
  kbd->keycode = inl(CONFIG_I8042_DATA_MMIO) & ~KEYDOWN_MASK;
}
