#include <am.h>
#include <klib.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

int width;
int height;
void __am_gpu_init()
{
  // int i;
  // int w = io_read(AM_GPU_CONFIG).width;
  // int h = io_read(AM_GPU_CONFIG).height;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i++)
  //   fb[i] = i;
  // outl(SYNC_ADDR, 1);

  width = io_read(AM_GPU_CONFIG).width;
  height = io_read(AM_GPU_CONFIG).height;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T){
      .present = true, .has_accel = false, .width = inw(VGACTL_ADDR + 2), .height = inw(VGACTL_ADDR), .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  if (!ctl->sync) {
    int x, y, w, h;
    x = ctl->x;
    y = ctl->y;
    w = ctl->w;
    h = ctl->h;
    uint32_t *color_buf = ctl->pixels;
    int i, j;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        *(fb + (i + y) * width + j + x) = color_buf[i * w + j];
      }
    }
  } 
  // else {
  //   uint32_t *color_buf = ctl->pixels;
  //   for (i = 0; i < height; i++) {
  //     for (j = 0; j < width; j++) {
  //       *(fb + i * width + j) = color_buf[i * width + j];
  //     }
  //   }
  // }
    outl(SYNC_ADDR, 1);

}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{
  status->ready = true;
}
