#include "RVNoob.h"
#include "common.h"
#include "timer.c"
#include <SDL2/SDL.h>

extern NPCState npc_state;

#define TIMER_HZ 60

// --------------------------------> keyboard
#define KEYDOWN_MASK 0x8000

// Note that this is not the standard
#define _KEYS(f)                                                                                               \
  f(ESCAPE) f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12)                         \
      f(GRAVE) f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(0) f(MINUS) f(EQUALS) f(BACKSPACE)               \
          f(TAB) f(Q) f(W) f(E) f(R) f(T) f(Y) f(U) f(I) f(O) f(P) f(LEFTBRACKET) f(RIGHTBRACKET) f(BACKSLASH) \
              f(CAPSLOCK) f(A) f(S) f(D) f(F) f(G) f(H) f(J) f(K) f(L) f(SEMICOLON) f(APOSTROPHE) f(RETURN)    \
                  f(LSHIFT) f(Z) f(X) f(C) f(V) f(B) f(N) f(M) f(COMMA) f(PERIOD) f(SLASH) f(RSHIFT)           \
                      f(LCTRL) f(APPLICATION) f(LALT) f(SPACE) f(RALT) f(RCTRL)                                \
                          f(UP) f(DOWN) f(LEFT) f(RIGHT) f(INSERT) f(DELETE) f(HOME) f(END) f(PAGEUP) f(PAGEDOWN)

#define _KEY_NAME(k) _KEY_##k,

enum {
  _KEY_NONE = 0,
  MAP(_KEYS, _KEY_NAME)
};

#define SDL_KEYMAP(k) keymap[concat(SDL_SCANCODE_, k)] = concat(_KEY_, k);
static uint32_t keymap[256] = {};

static void init_keymap() {
  MAP(_KEYS, SDL_KEYMAP)
}

#define KEY_QUEUE_LEN 1024
static int key_queue[KEY_QUEUE_LEN] = {};
static int key_f = 0, key_r = 0;

static void key_enqueue(uint32_t am_scancode) {
  key_queue[key_r] = am_scancode;
  key_r = (key_r + 1) % KEY_QUEUE_LEN;
  // if (key_r != key_f)
    // key_r--;
  // panic("key queue overflow!");
}

static uint32_t key_dequeue() {
  uint32_t key = _KEY_NONE;
  // printf("key dequeue: key_f:%d, key_r:%d\n",key_f,key_r);
  if (key_f != key_r) {
    key = key_queue[key_f];
    key_f = (key_f + 1) % KEY_QUEUE_LEN;
  }
  return key;
}

void send_key(uint8_t scancode, bool is_keydown) {
  if (npc_state.state == NPC_RUNNING && keymap[scancode] != _KEY_NONE) {
    // printf("is_keydown:%d, key:%d\n", is_keydown, keymap[scancode]);
    uint32_t am_scancode = keymap[scancode] | (is_keydown ? KEYDOWN_MASK : 0);
    key_enqueue(am_scancode);
  }
}

uint32_t i8042_data_port_base;

void i8042_data_io_handler() {
  i8042_data_port_base = key_dequeue();
}

void init_i8042() {
  i8042_data_port_base = _KEY_NONE;
  init_keymap();
}

// --------------------------------> vga

#define SCREEN_W (MUXDEF(CONFIG_VGA_SIZE_800x600, 800, 400))
#define SCREEN_H (MUXDEF(CONFIG_VGA_SIZE_800x600, 600, 300))

static uint32_t screen_width = SCREEN_W;
static uint32_t screen_height = SCREEN_H;

uint32_t screen_size = screen_width * screen_height * sizeof(uint32_t);

void *vmem = NULL;
uint32_t vgactl_port_base, vgactl_port_base_syn;
// uint32_t vgactl_port_base[2];

#ifdef CONFIG_VGA_SHOW_SCREEN

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static void init_screen() {
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "%s-NPC", "riscv64");
  SDL_Init(SDL_INIT_VIDEO);
  // SDL_CreateWindowAndRenderer(
  //     SCREEN_W * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
  //     SCREEN_H * (MUXDEF(CONFIG_VGA_SIZE_400x300, 2, 1)),
  //     0, &window, &renderer);
    SDL_CreateWindowAndRenderer(
      SCREEN_W * 1,
      SCREEN_H * 1,
      0, &window, &renderer);
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
}

static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}

#endif

void vga_update_screen() {
  // TODO: call `update_screen()` when the sync register is non-zero,
  // then zero out the sync register
  int sync = vgactl_port_base_syn;
  if(sync != 0){
    update_screen();
    vgactl_port_base_syn = 0;
  }
}

void init_vga() {
  // vgactl_port_base = (uint32_t *)new_space(8);
  // vgactl_port_base[0] = (screen_width() << 16) | screen_height();
  vgactl_port_base = (screen_width << 16) | screen_height;
  vgactl_port_base_syn = 0;

  // add_mmio_map("vgactl", CONFIG_VGA_CTL_MMIO, vgactl_port_base, 8, NULL);

  vmem = malloc(screen_size);
  // #ifdef CONFIG_VGA_SHOW_SCREEN
  //   init_screen();
  //   memset(vmem, 0, screen_size);
  // #endif
  // IFDEF(CONFIG_VGA_SHOW_SCREEN, printf("1\n"));
  // vmem = new_space(screen_size());
  // add_mmio_map("vmem", CONFIG_FB_ADDR, vmem, screen_size(), NULL);
  IFDEF(CONFIG_VGA_SHOW_SCREEN, init_screen());
  IFDEF(CONFIG_VGA_SHOW_SCREEN, memset(vmem, 0, screen_size));
}

// --------------------------------> device

void device_update() {
  static uint64_t last = 0;
  uint64_t now = get_time();
  if (now - last < 1000000 / TIMER_HZ) {
    return;
  }
  last = now;

  vga_update_screen();

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      npc_state.state = NPC_QUIT;
      break;
    // If a key was pressed
    case SDL_KEYDOWN:
    case SDL_KEYUP: {
      uint8_t k = event.key.keysym.scancode;
      bool is_keydown = (event.key.type == SDL_KEYDOWN);
      send_key(k, is_keydown);
      break;
    }
    default:
      break;
    }
  }
}