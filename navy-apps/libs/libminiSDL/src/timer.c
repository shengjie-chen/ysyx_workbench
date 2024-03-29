#include <NDL.h>
#include <sdl-timer.h>
#include <stdio.h>

SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param) {
  printf("SDL_AddTimer wait to achieve\n");
  return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id) {
  printf("SDL_RemoveTimer wait to achieve\n");
  return 1;
}

uint32_t SDL_GetTicks() {
  return NDL_GetTicks();
}

void SDL_Delay(uint32_t ms) {
  uint32_t cur, tar;
  cur = SDL_GetTicks();
  tar = cur + ms;
  while (cur < tar) {
    cur = SDL_GetTicks();
  }
}
