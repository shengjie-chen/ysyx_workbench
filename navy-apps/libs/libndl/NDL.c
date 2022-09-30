#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/stat.h>
// #include <sys/time.h>
// #include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval curr_time;
  gettimeofday(&curr_time, NULL);
  uint32_t ms = curr_time.tv_sec * 1000 + curr_time.tv_usec;
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

void NDL_OpenCanvas(int *w, int *h) {
  char pinfo[25];
  int fd = open("/proc/dispinfo", O_RDONLY);
  if (fd == -1) {
    printf("open file fail!\n");
    return 0;
  }
  read(fd, pinfo, 25);
  printf("%s\n", pinfo);
  int colon1, newline, colon2, null;
  if (!memcmp(pinfo, "WIDTH :", 7)) {
    printf("1\n");
    colon1 = 6;
  }
  printf("1\n");
  for (int i = colon1 + 1; i < 25; i++) {
    if (pinfo[i] == '\n') {
      newline = i;
      colon2 = newline + 7;
    }
    if (pinfo[i] == 0) {
      null = i;
      break;
    }
  }
  int width = 0;
  int height = 0;
  for (int i = newline - 1; i > colon1; i--) {
    int pow = 1;
    for (int j = 0; j < newline - 1 - i; j++) {
      pow = pow * 10;
    }
    width = width + (pinfo[i] - 48) * pow;
  }

  for (int i = null - 1; i > colon2; i--) {
    int pow = 1;
    for (int j = 0; j < null - 1 - i; j++) {
      pow = pow * 10;
    }
    height = height + (pinfo[i] - 48) * pow;
  }

  printf("screen width: %d, height: %d\n", width, height);
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

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
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
  return 0;
}

void NDL_Quit() {
}
