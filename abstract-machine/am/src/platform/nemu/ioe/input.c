#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000
#define CONFIG_I8042_DATA_MMIO 0xa0000060

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t kbd_msg = inl(CONFIG_I8042_DATA_MMIO);
  kbd->keydown = (kbd_msg & KEYDOWN_MASK) ? true : false;
  kbd->keycode = kbd_msg & ~KEYDOWN_MASK;
}
