#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t i = 0;
  while (*(s + i) != 0) {
    i++;
  }
  return i;
}

char *strcpy(char *dst, const char *src) {
  char *pstr = dst;

  if (sizeof(*dst) > 1) {
    int size = sizeof(*dst);
    int i;
    for (i = 0; i < size; i++) {
      if ((*pstr++ = *src++) == 0) {
        return dst;
      }
    }
    panic("the destination string dest must be large enough to receive the copy!");
  } else {
    while ((*pstr++ = *src++) != 0)
      ;
    return dst;
  }
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *pstr = dst;

  if (sizeof(*dst) > 1) {
    int size = sizeof(*dst);
    if (size < n) {
      panic("no place in dst");
    }
  }
  int i;
  for (i = 0; i < n; i++) {
    if ((*pstr++ = *src++) == 0) {
      break;
    }
  }
  while (i < n) {
    *pstr++ = 0;
    i++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  assert(dst != NULL && src != NULL);

  char *pstr = dst;
  while (*pstr++)
    ;
  --pstr;

  while ((*pstr++ = *src++) != 0)
    ;

  return dst;
}

int strcmp(const char *s1, const char *s2) {
  int i = 0;
  int r;
  while (1) {
    r = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
    if (r != 0 || *(unsigned char *)(s1 + i) == 0) {
      return (r);
    }
    i++;
  }
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int i = 0;
  int r;
  while (i < n) {
    r = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
    if (r != 0 || *(unsigned char *)(s1 + i) == 0 || i == n - 1) {
      return (r);
    }
    i++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  int i;
  char *pstr = s;
  for (i = 0; i < n; i++) {
    *(pstr + i) = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
  // int i = 0;
  // while (*(src + i) != '\0')
  //   i++;
  // for (; i != -1; i--)
  //   *(dst + i) = *(src + i);
}

void *memcpy(void *out, const void *in, size_t n) {
  char *data = out;
  for (int i = 0; i < n; i++) {
    *(data + i) = *(char *)(in + i);
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  int i = 0;
  int r;
  while (i < n) {
    r = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
    if (r != 0 || *(unsigned char *)(s1 + i) == 0 || i == n - 1) {
      return (r);
    }
    i++;
  }
  return 0;
}

#endif
