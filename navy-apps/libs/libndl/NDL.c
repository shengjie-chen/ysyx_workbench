#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/stat.h>
// #include <sys/time.h>
// #include <sys/types.h>
#include <assert.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

static uint32_t init_sec, init_usec;

uint32_t NDL_GetTicks() {
  struct timeval curr_time;
  gettimeofday(&curr_time, NULL);
  // printf("tv_sec: %ld,tv_usec: %ld\n",curr_time.tv_sec,curr_time.tv_usec);
  uint32_t ms = (curr_time.tv_sec - init_sec) * 1000 + (curr_time.tv_usec - init_usec) / 1000;
  // printf("NDL_GetTicks: %ld\n",ms);
  return ms;
}

int NDL_PollEvent(char *buf, int len) {
  int fd = open("/dev/events", O_RDONLY);
  if (fd == -1) {
    printf("open file fail!\n");
    return 0;
  }
  int bytes;
  bytes = read(fd, buf, len);
  if (bytes == -1) {
    printf("ReadFailed.\n");
    return 0;
  } else if (bytes == 0) {
    close(fd);
    return 0;
  } else {
    close(fd);
    return 1;
  }
}

int width;
int height;
void NDL_OpenCanvas(int *w, int *h) {

  // printf("canvas width: %d, height: %d\n", *w, *h);
  assert(*w <= width);
  assert(*h <= height);
  if (*w == 0 && *h == 0) {
    *w = width;
    *h = height;
  }

  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w;
    screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0)
        continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0)
        break;
    }
    close(fbctl);
  }
}

static int fb_fd;

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {

  // printf("w:%d\n", w);
  // printf("width:%d\n", width);

#ifdef __ISA_NATIVE__ // navy-native use standard
  if (w == width) {
    assert(x == 0);
    assert((h + y) <= height);
    lseek(fb_fd, (y * width) * 4, SEEK_SET);
    write(fb_fd, pixels, w * h * 4);
    // printf("draw complete line!\n");
  } else {
    for (int i = 0; i < h; i++) {
      lseek(fb_fd, (x + y * width + i * width) * 4, SEEK_SET);
      write(fb_fd, pixels + w * i, w * 4);
      // printf("%d: write offset %d\n", i, w * i);
    }
  }
#else // am-native nemu npc  quick mode not standard
  // printf("navy:\n");
  // printf("w:%d\n", w);
  // printf("h:%d\n", h);
  // printf("x:%d\n", x);
  // printf("y:%d\n", y);
  // unsigned long offset = (x+40 + (y+50) * width) * 4; // center the pal window
  unsigned long offset = (x + y * width) * 4;
  // printf("offset:%ld\n", offset);
  lseek(fb_fd, offset, SEEK_SET);
  unsigned long len = ((unsigned long)w << 16 | (unsigned long)h);
  // printf("len:%ld\n", len);
  write(fb_fd, pixels, len);

  // printf("use trick to draw fb\n");
  // printf("%d: write offset %d\n", i, w * i);
#endif
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }
  fb_fd = open("/dev/fb", O_WRONLY);
  if (fb_fd == -1) {
    printf("open file fail!\n");
    exit(1);
  }
  char pinfo[25];
  int fd = open("/proc/dispinfo", O_RDONLY);
  if (fd == -1) {
    printf("open file fail!\n");
    exit(1);
  }
  // printf("read pinfo!!\n");
  read(fd, pinfo, 25);
  // printf("%s\n", pinfo);
  int colon1 = 0, colon2 = 0;
  int num1_head = 0, num1_tail = 0, num2_head = 0, num2_tail = 0;
  if (memcmp(pinfo, "WIDTH", 5)) {
    exit(1);
  }
  for (int i = 5; i < 25; i++) {
    if (pinfo[i] == ':') {
      if (colon1 == 0) {
        colon1 = i;
      } else {
        colon2 = i;
      }
    }
    if (pinfo[i] >= 48 && pinfo[i] <= 57) {
      if (colon2 == 0) {
        if (num1_head == 0)
          num1_head = i;
        else
          num1_tail = i;
      } else {
        if (num2_head == 0)
          num2_head = i;
        else
          num2_tail = i;
      }
    }
  }
  // printf("num1_head = %d, num1_tail = %d, num2_head = %d, num2_tail = %d\n", num1_head, num1_tail, num2_head, num2_tail);
  width = 0;
  height = 0;
  for (int i = num1_tail; i >= num1_head; i--) {
    int pow = 1;
    for (int j = 0; j < num1_tail - i; j++) {
      pow = pow * 10;
    }
    width = width + (pinfo[i] - 48) * pow;
  }

  for (int i = num2_tail; i >= num2_head; i--) {
    int pow = 1;
    for (int j = 0; j < num2_tail - i; j++) {
      pow = pow * 10;
    }
    height = height + (pinfo[i] - 48) * pow;
  }

  struct timeval curr_time;
  gettimeofday(&curr_time, NULL);
  // printf("tv_sec: %ld,tv_usec: %ld\n",curr_time.tv_sec,curr_time.tv_usec);
  init_sec = curr_time.tv_sec;
  init_usec = curr_time.tv_usec;
  // printf("screen width: %d, height: %d\n", width, height);
  return 0;
}

void NDL_Quit() {
  close(fb_fd);
}
