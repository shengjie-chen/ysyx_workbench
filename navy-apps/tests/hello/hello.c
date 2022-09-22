#include <stdio.h>
#include <unistd.h>

int main() {
  write(1, "Hello World!\n", 13);
  int i = 2;
  volatile int j = 0;
  while (1) {
    j++;
    if (j == 10000) {
      write(1, "Hello World!\n", 13);

      // printf("%d", i);
      // printf("\n");
      printf("Hello World from Navy-apps for the %dth time!\n", i++);
      j = 0;
      break;
    }
  }
  return 0;
}
