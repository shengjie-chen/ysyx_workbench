#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char *nptr) {
  int x = 0;
  while (*nptr == ' ') {
    nptr++;
  }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
static char *addr_alloc;
static int first = 0;
// #endif
void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
  // #if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if (first == 0) {
    addr_alloc = (void *)ROUNDUP(heap.start, 8);
    first = 1;
    // printf("heap.start:%x\nheap.end:%x\n",heap.start,heap.end);
  }
  size = (size_t)ROUNDUP(size, 8);
  if (size > ((uintptr_t)heap.end - (uintptr_t)addr_alloc)) {
    return NULL;
  }
  char *old = addr_alloc;
  addr_alloc += size;
  printf("%ld\n", size);
  // if (!((uintptr_t)heap.start <= (uintptr_t)addr_alloc && (uintptr_t)addr_alloc <= (uintptr_t)heap.end)) {
  //   return NULL;
  // }

  printf("addr_alloc:%x\n", addr_alloc);
  static int p_first = 0;
  for (uint64_t *p = (uint64_t *)old; p != (uint64_t *)addr_alloc; p++) {
    if (p > (uint64_t *)addr_alloc && p_first == 0) {
      printf("p:%x\n", p);
      p_first++;
    }
    *p = 0;
  }
  return old;
  // #endif
  return NULL;
}
#endif

void free(void *ptr) {
}

#endif
