#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init()
{
  int i;
  int w = io_read(AM_GPU_CONFIG).width;
  int h = io_read(AM_GPU_CONFIG).height;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i++)
    fb[i] = i;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T){
      .present = true, .has_accel = false, .width = inw(VGACTL_ADDR + 2), .height = inw(VGACTL_ADDR), .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  if (ctl->sync) {
    int width = io_read(AM_GPU_CONFIG).width;
    int height = io_read(AM_GPU_CONFIG).height;
    int x1, x2, y1, y2;
    x1 = ctl->x;
    y1 = ctl->y;
    x2 = x1 + ctl->w;
    y2 = y1 + ctl->h;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if ((j == x1) || (j == x2) || (i == y1) || (i == y2)) {
          *(fb + i * width + j) = 0x00ff0000;
        } else {
          *(fb + i * width + j) = 0x00000000;
        }
      }
    }
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{
  status->ready = true;
}
