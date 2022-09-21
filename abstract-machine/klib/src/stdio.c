#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int int2char(int d, char *out);
int uint2char(uint32_t d, char *out);
int hex2char(uint32_t d, char *out);

#define MAX_LEN_PRINT 10240
int printf(const char *fmt, ...) {
  char out[MAX_LEN_PRINT];
  va_list ap;
  va_start(ap, fmt);
  int j = vsprintf(out, fmt, ap);
  if (j > MAX_LEN_PRINT) {
    printf("printf char array out of bounds, change macro!\n");
  }
  va_end(ap);
  if (j >= 0) {
    for (int i = 0; i < j; i++) {
      putch(out[i]);
    }
  }
  return j;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int i = 0; // fmt
  int j = 0; // out
  while (fmt[i] != '\0') {
    if (fmt[i] != '%') {
      out[j] = fmt[i];
      i++;
      j++;
      continue;
    }
    i++;
    int count;
    switch (fmt[i]) {
    case 'c': // 得到一个字符
    {
      char cc;
      cc = (char)va_arg(ap, int);
      out[j] = cc;
      j++;
      break;
    }
    case 'd': // 得到一个整数
    {
      int dd;
      dd = (int)va_arg(ap, int);
      count = int2char(dd, &out[j]);
      j += count;
      break;
    }
    case 'x': // 得到一个0x数
    {
      int xx;
      xx = (uint32_t)va_arg(ap, uint32_t);
      count = hex2char(xx, &out[j]);
      j += count;
      break;
    }
    case 's': // 得到一个字符串
    {
      char *ss;
      count = 0;
      ss = va_arg(ap, char *);
      if (ss == NULL) {
        return -1;
      }
      while ((out[j++] = *ss++) != 0)
        ;
      j--;
      break;
    }
    case 'p': // 得到一个address
    {
      int pp;
      pp = (uint32_t)va_arg(ap, uint32_t);
      count = uint2char(pp, &out[j]);
      j += count;
      break;
    }
    }
    i++;
  }
  out[j] = '\0';
  return j;
}

int int2char(int d, char *out) {
  int count = 0;
  int n = d;
  char m[10];
  if (d < 0) {
    *out++ = '-';
    n = -d;
  }
  while (n != 0) {
    m[count] = n % 10 + 48;
    n /= 10;
    ++count;
  }
  int i;
  for (i = 0; i < count; i++) {
    *(out + i) = m[count - i - 1];
  }
  if (d < 0) {
    return count + 1;
  } else {
    return count;
  }
}

int uint2char(uint32_t d, char *out) {
  int count = 0;
  uint32_t n = d;
  char m[10];
  while (n != 0) {
    m[count] = n % 10 + 48;
    n /= 10;
    ++count;
  }
  int i;
  for (i = 0; i < count; i++) {
    *(out + i) = m[count - i - 1];
  }
  return count;
}

int hex2char(uint32_t d, char *out) {
  int count = 0;
  uint32_t n = d;
  char m[10];
  while (n != 0) {
    int x = n % 16;
    if (x < 10) {
      m[count] = x + 48;

    } else {
      m[count] = n % 16 + 55;
    }
    n /= 16;
    ++count;
  }
  int i;
  for (i = 0; i < count; i++) {
    *(out + i) = m[count - i - 1];
  }
  return count;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int j = vsprintf(out, fmt, ap);
  va_end(ap);
  return j;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
