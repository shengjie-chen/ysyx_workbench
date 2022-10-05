#include <NDL.h>
#include <SDL.h>

#define keyname(k) #k,

static const char *keyname[] = {
    "NONE",
    _KEYS(keyname)};

static int SDL_ConvertEvent(char *key) {
  // printf("key:%s\n", key);
  // printf("key size:%d\n", sizeof(keyname) );
  // printf("key num:%d\n", sizeof(keyname) / sizeof(keyname[0]));
  for (int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
    if (strcmp(key, keyname[i]) == 0) {
      return i;
    }
  }
  return 0;
}

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  char buf[64];
  if (NDL_PollEvent(buf, sizeof(buf))) {
    buf[strlen(buf) - 1] = 0;
    printf("receive event: %s\n", buf);
    // printf("%c\n", buf[1]);
    ev->type = (buf[1] == 'd') ? SDL_KEYDOWN : SDL_KEYUP;
    printf("SDL_EventType: %d\n", ev->type);
    ev->key.keysym.sym = SDL_ConvertEvent(&buf[3]);
    printf("SDL_Keys: %d\n", ev->key.keysym.sym);
    return 1;
  }
  return 0;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[64];
  while (1) {
    if (NDL_PollEvent(buf, sizeof(buf))) {
      buf[strlen(buf) - 1] = 0;
      printf("receive event: %s\n", buf);
      // printf("%c\n", buf[1]);
      event->type = (buf[1] == 'd') ? SDL_KEYDOWN : SDL_KEYUP;
      printf("SDL_EventType: %d\n", event->type);
      event->key.keysym.sym = SDL_ConvertEvent(&buf[3]);
      printf("SDL_Keys: %d\n", event->key.keysym.sym);
      return 1;
    }
  }
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys) {
  return NULL;
}
