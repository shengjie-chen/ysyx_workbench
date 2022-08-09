#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...)
{
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
  panic("Not implemented");
}

int int2char(int d, char *out)
{
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

int sprintf(char *out, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
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
    }
    i++;
  }
  out[j] = '\0';
  va_end(ap);
  return j;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
  panic("Not implemented");
}

#endif
