#include <am.h>
#include <nemu.h>
#include <klib.h>


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
  if (ctl->sync) {
    int x1, x2, y1, y2;
    x1 = ctl->x;
    y1 = ctl->y;
    x2 = x1 + ctl->w;
    y2 = y1 + ctl->h;
    int i, j;
    uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        if ((j == x1) || (j == x2) || (i == y1) || (i == y2)) {
          *(fb + i * width + j) = 0x00ff0000;
          // printf("i = %d, j = %d\n", i, j);
          printf("x1 = %d, y1 = %d\n", x1, y1);
          printf("x2 = %d, y2 = %d\n", x2, y2);
        }
        // else {
        //   *(fb + i * width + j) = 0x00000000;
        // }
      }
    }
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{
  status->ready = true;
}
