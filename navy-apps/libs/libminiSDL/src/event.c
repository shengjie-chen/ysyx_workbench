#include <NDL.h>
#include <SDL.h>

#define keyname(k) #k,

static const char *keyname[] = {
    "NONE",
    _KEYS(keyname)};

int SDL_PushEvent(SDL_Event *ev) {
  return 0;
}

int SDL_PollEvent(SDL_Event *ev) {
  return 0;
}

#define strdef(k) #k,

const char *key_str[] = {"NONE", _KEYS(strdef)};

static int SDL_ConvertEvent(char *key) {
  // printf("key:%s\n", key);
  // printf("key size:%d\n", sizeof(key_str) );
  // printf("key num:%d\n", sizeof(key_str) / sizeof(key_str[0]));
  for (int i = 0; i < sizeof(key_str) / sizeof(key_str[0]); i++) {
    if (strcmp(key, key_str[i]) == 0) {
      return i;
    }
  }
  return 0;
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[64];
  if (NDL_PollEvent(buf, sizeof(buf))) {
    buf[strlen(buf) - 1] = 0;
    printf("receive event: %s\n", buf);
    // printf("%c\n", buf[1]);
    event->type = (buf[1] == 'd') ? SDL_KEYDOWN : SDL_KEYUP;
    printf("SDL_EventType: %d\n", event->type);
    event->key.keysym.sym = SDL_ConvertEvent(&buf[3]);
    printf("SDL_Keys: %d\n", event->key.keysym.sym);
  }
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys) {
  return NULL;
}
