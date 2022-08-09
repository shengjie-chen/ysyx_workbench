#include "sdb.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <math.h>
#include <memory/paddr.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
int ascii2num(char *args);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args)
{
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args)
{
  nemu_state.state = NEMU_QUIT;
  printf("Exit NEMU\n");
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args)
{
  if (args == 0) {
    cpu_exec(1);
  } else {
    int n;
    sscanf(args, "%d", &n);
    cpu_exec(n);
  }
  return 0;
}

static int cmd_info(char *args)
{
  if (*args == 'r') {
    isa_reg_display();
  } else if (*args == 'w') {
    print_watchpoint();
  }
  return 0;
}

static int cmd_x(char *args)
{
  int args1;
  paddr_t args2;
  sscanf(args, "%d %x", &args1, &args2);
  int i, j;
  uint8_t *addr;
  for (i = 0; i < args1; i++) {
    printf("addr: %x : 0x ", args2 + i * 4);
    for (j = 3; j >= 0; j--) {
      addr = guest_to_host(args2 + 4 * i + j);
      printf("%02x ", *addr);
    }
    printf("\n");
  }
  return 0;
}

static int cmd_p(char *args)
{
  bool *success = 0;
  expr(args, success);
  return 0;
}

static int cmd_w(char *args)
{
  add_new_wp(args);
  return 0;
}

static int cmd_d(char *args)
{
  int index;
  sscanf(args, "%d", &index);
  free_wp(index);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display informations about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "Next step", cmd_si},
    {"info", "Print program state", cmd_info},
    {"x", "Scan Memory", cmd_x},
    {"p", "Calculate Expression", cmd_p},
    {"w", "Watchpoint", cmd_w},
    {"d", "Delete Watchpoint", cmd_d},

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode()
{
  is_batch_mode = true;
}

void sdb_mainloop()
{
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb()
{
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

int ascii2num(char *args)
{
  int len = strlen(args);
  int num = 0;
  int i;
  for (i = 0; i < len; i++) {
    num += (args[i] - 48) * pow(10, len - i - 1);
  }
  return num;
}