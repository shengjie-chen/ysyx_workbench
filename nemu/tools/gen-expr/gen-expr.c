#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
    "#include <stdio.h>\n"
    "int main() { "
    "  unsigned result = %s; "
    "  printf(\"%%u\", result); "
    "  return 0; "
    "}";

static int buf_point = 0;

static int choose(int x)
{
  return rand() % x;
}

static void gen(char x)
{
  buf[buf_point] = x;
  buf_point++;
}

static void gen_rand_space()
{
  if (rand() % 6 == 0) {
    buf[buf_point] = ' ';
    buf_point++;
  }
}

static void gen_num()
{
  int width = rand() % 4;
  int i;
  char num = rand() % 9 + 49;
  gen(num);
  for (i = 1; i < width; i++) {
    num = rand() % 10 + 48;
    gen(num);
  }
  gen('u');
}

static void gen_rand_op()
{
  int i;
  char op;
  i = choose(4);
  switch (i) {
  case (0):
    op = '+';
    break;
  case (1):
    op = '-';
    break;
  case (2):
    op = '*';
    break;
  case (3):
    op = '/';
    break;
  default:
    op = '+';
  }
  gen(op);
}

static int gen_rand_expr_num = 0;
static int choose_num = 3;

static void gen_rand_expr()
{
  if (gen_rand_expr_num > 100) {
    choose_num = 2;
  }else{
    choose_num = 3;
  }
  switch (choose(choose_num)) {
  case 0:
    gen_rand_space();
    gen_num();
    gen_rand_space();
    break;
  case 1:
    gen_rand_space();
    gen('(');
    gen_rand_space();
    gen_rand_expr();
    gen_rand_space();
    gen(')');
    gen_rand_space();
    break;
  default:
    gen_rand_space();
    gen_rand_expr();
    gen_rand_space();
    gen_rand_op();
    gen_rand_space();
    gen_rand_expr();
    gen_rand_space();
    break;
  }
  buf[buf_point] = '\0';
  gen_rand_expr_num++;
}

int main(int argc, char *argv[])
{
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  FILE *wfp = fopen("./tools/gen-expr/input", "w");
  for (i = 0; i < loop; i++) {
    gen_rand_expr();
    buf_point = 0;
    gen_rand_expr_num = 0;
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0)
      continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
    fprintf(wfp, "%u %s\n", result, buf);
  }
  return 0;
}
