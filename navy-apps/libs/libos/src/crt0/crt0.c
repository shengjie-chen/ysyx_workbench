#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

extern void _exit(int status);

int main(int argc, char *argv[], char *envp[]);
extern char **environ;
void call_main(uintptr_t *args) {
  char *empty[] =  {NULL };
  environ = empty;
  _exit(main(0, empty, empty));
  assert(0);
}
