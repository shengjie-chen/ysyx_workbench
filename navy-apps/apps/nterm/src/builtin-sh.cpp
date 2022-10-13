#include <SDL.h>
#include <nterm.h>
#include <stdarg.h>
#include <unistd.h>

char handle_key(SDL_Event *ev);
void clear_display(void);

static void sh_printf(const char *format, ...) {
  static char buf[256] = {};
  va_list ap;
  va_start(ap, format);
  int len = vsnprintf(buf, 256, format, ap);
  va_end(ap);
  term->write(buf, len);
}

static void sh_banner() {
  sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt() {
  sh_printf("sh> ");
}

static void sh_handle_cmd(const char *cmd) {
  // const char *exec_argv[3];
  // exec_argv[0] = cmd;
  // exec_argv[1] = NULL;
  // exec_argv[2] = NULL;
  // char *envp[1];
  // envp[0] = NULL;
  // execve(cmd, (char**)exec_argv, (char**)envp);
  clear_display();
  char pathname [256];
  strcpy(pathname, cmd);
  int l = strlen(pathname);
  pathname[l-1] = 0;
  execve(pathname, NULL, NULL);

}

void builtin_sh_run() {
  sh_banner();
  sh_prompt();

  while (1) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN) {
        const char *res = term->keypress(handle_key(&ev));
        if (res) {
          sh_handle_cmd(res);
          sh_prompt();
        }
      }
    }
    refresh_terminal();
  }
}
