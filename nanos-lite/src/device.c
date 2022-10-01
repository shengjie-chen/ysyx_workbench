#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
#define MULTIPROGRAM_YIELD() yield()
#else
#define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
    [AM_KEY_NONE] = "NONE",
    AM_KEYS(NAME)};

size_t serial_write(const void *buf, size_t offset, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    putch(*((char *)buf + i));
  }
  return i;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  memset(buf, 0, len);
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
  if (ev.keycode == AM_KEY_NONE) {
    return 0;
  }
  char event_str[17];
  strcat(event_str, ev.keydown ? "kd " : "ku ");
  strcat(event_str, keyname[ev.keycode]);
  strcat(event_str, "\n");
  int e_len = strlen(event_str);
  if (len < e_len) {
    e_len = len;
  }
  memcpy(buf, event_str, e_len);

  return e_len;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  int dis_w = io_read(AM_GPU_CONFIG).width;
  int dis_h = io_read(AM_GPU_CONFIG).height;
  char pinfo[25] = {0};
  char info[5] = {0};
  strcat(pinfo, "WIDTH :");
  int2char(dis_w, info);
  strcat(pinfo, info);
  memset(info, 0, 5);
  strcat(pinfo, "\nHEIGHT:");
  int2char(dis_h, info);
  strcat(pinfo, info);
  memcpy(buf, pinfo, 25);
  return 0;
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  int screen_w = io_read(AM_GPU_CONFIG).width;
  // int screen_h = io_read(AM_GPU_CONFIG).height;
  int flx = offset % screen_w; // first line x
  int fly = offset / screen_w; // first line y

  uint32_t *pxl = (uint32_t *)buf;
  int cross_line = (len + flx) / screen_w;
  int llx = (len + flx - 1) % screen_w; // last line x
  int lly = cross_line + fly;           // last line y
  if (cross_line == 0) {
    io_write(AM_GPU_FBDRAW, flx, fly, pxl, len, 1, true);
  } else {
    io_write(AM_GPU_FBDRAW, flx, fly, pxl, (screen_w - flx), 1, false);
    if (cross_line != 1) {
      io_write(AM_GPU_FBDRAW, 0, fly + 1, pxl + (screen_w - flx), screen_w, cross_line - 1, false);
    }
    io_write(AM_GPU_FBDRAW, 0, lly, pxl + (len - llx - 1), llx + 1, 1, true);
  }
  return len;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
