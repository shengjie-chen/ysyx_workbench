#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256,
  DEC_NUM,
  HEX_NUM,
  REG_NAME,
  LOG_EQ,
  LOG_NEQ,
  LOG_AND,
  DEREF // dereference

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE}, // spaces
    {"u", TK_NOTYPE},  // unsigned suffix

    {"[0-9]+", DEC_NUM}, // decimal number
    {"\\+", '+'},        // plus 43
    {"\\-", '-'},        // substract 45
    {"\\*", '*'},        // multiply 42
    {"\\/", '/'},        // divide 47
    {"\\(", '('},        // (
    {"\\)", ')'},        // )

    {"0x[0-9]+", HEX_NUM},   // hexadecimal number
    {"\\$[0-9]+", REG_NAME}, // reg name
    {"==", LOG_EQ},          // == logic equal
    {"!=", LOG_NEQ},         // != logic not equal
    {"&&", LOG_AND},         // && logic and

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[1024] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        assert(nr_token < 1024);
        switch (rules[i].token_type) {
        case TK_NOTYPE:
          break;
        default:
          tokens[nr_token].type = rules[i].token_type;
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          nr_token++;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

int find_right_brackets(int p, int q)
{
  int i;
  for (i = p + 1; i <= q;) {
    if (tokens[i].type == ')') {
      return i;
    } else if (tokens[i].type == '(') {
      i = find_right_brackets(i, q);
      i++;
    } else {
      i++;
    }
  }
  panic("can't find ')'\n");
}

static bool check_parentheses(int p, int q)
{
  if (tokens[p].type == '(') {
    if (q == find_right_brackets(p, q)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

static uint32_t eval_deref(uint32_t val){
  uint8_t* addr;
  addr = guest_to_host(val);
  return *addr;
}

static uint32_t eval(int p, int q)
{
  if (p > q) {
    panic("Bad expression\n");
    return 0;
  } else if (p == q) {
    if (tokens[p].type == DEC_NUM) {
      uint32_t val;
      sscanf(tokens[p].str, "%d", &val);
      return val;
    } else if (tokens[p].type == HEX_NUM) {
      uint32_t val;
      sscanf(tokens[p].str, "%x", &val);
      return val;
    } else if (tokens[p].type == REG_NAME) {
      uint32_t val;
      bool *success = 0;
      val = isa_reg_str2val(tokens[p].str, success);
      return val;
    } else {
      panic("Sigle expression is not a number\n");
      return 0;
    }
  } else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q - 1);
  } else {
    int i;
    int op = 0;
    int op_type = 0;
    for (i = p; i <= q;) {
      switch (tokens[i].type) {
      case '(':
        i = find_right_brackets(i, q);
        break;
      case LOG_AND:
        op = i;
        op_type = tokens[i].type;
        i++;
        break;
      case LOG_NEQ:
      case LOG_EQ:
        if (op_type != LOG_AND) {
          op = i;
          op_type = tokens[i].type;
        }
        i++;
        break;
      case '-':
      case '+':
        if (op_type < 256) {
          op = i;
          op_type = tokens[i].type;
        }
        i++;
        break;
      case '*':
      case '/':
        if (op_type != '+' && op_type != '-' && op_type < 256) {
          op = i;
          op_type = tokens[i].type;
        }
        i++;
        break;
      case DEREF:
        if (op_type == 0) {
          op = i;
          op_type = tokens[i].type;
        }
        i++;
        break;
      default:
        op_type = op_type;
        op = op;
        i++;
      }
    }

    uint32_t val1;
    uint32_t val2 = eval(op + 1, q);
    if(op_type != DEREF){
    val1 = eval(p, op - 1);
    }
    switch (op_type) {
    case LOG_AND:
      return val1 && val2;
      break;
    case LOG_EQ:
      return val1 == val2;
      break;
    case LOG_NEQ:
      return val1 != val2;
      break;
    case '+':
      return val1 + val2;
      break;
    case '-':
      return val1 - val2;
      break;
    case '*':
      return val1 * val2;
      break;
    case '/':
      return val1 / val2;
      break;
    case DEREF:
      return eval_deref(val2);
      break;
    default:
      assert(0);
    }

    return 0;
  }
}

uint32_t expr(char *e, bool *success)
{
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  // TODO();
  int i;
  bool is_deref;
  for (i = 0; i < nr_token; i++) {
    is_deref = i == 0 ||
               tokens[i - 1].type == '(' ||
               tokens[i - 1].type == '+' ||
               tokens[i - 1].type == '-' ||
               tokens[i - 1].type == '*' ||
               tokens[i - 1].type == '/' ||
               tokens[i - 1].type == LOG_EQ ||
               tokens[i - 1].type == LOG_NEQ ||
               tokens[i - 1].type == LOG_AND ||
               tokens[i - 1].type == DEREF;
    if (tokens[i].type == '*' && is_deref) {
      tokens[i].type = DEREF;
    }
  }

  uint32_t value;
  value = eval(0, nr_token - 1);
  printf("EXP is %d\n", value);
  for (i = 0; i < nr_token; i++) {
    memset(tokens[i].str, 0, sizeof(tokens[i].str));
    tokens[i].type = 0;
  }
  return value;
}

bool check_expr() // check function expr() when initial
{
  FILE *fp = fopen("./tools/gen-expr/input", "r");
  char input[65536];
  bool *success = 0;
  uint32_t spec;
  uint32_t impl;
  char e[65536];
  if (fp == NULL) {
    panic("read expr input file error\n");
  } else {
    int i;
    for (i = 0; i < 10000; i++) {
      // printf("check %d line\n",i);
      if (fgets(input, 65536, fp) != NULL) {
        memset(e, 0, sizeof(e));
        sscanf(input, "%u %[^\n]", &spec, e);
        impl = expr(e, success);
        if (impl != spec) {
          printf("%d line is wrong, spec value is %u, compute value is %u\n", i, spec, impl);
          return false;
        } else {
          printf("%d line is right\n", i);
        }
      } else {
        break;
      }
    }
    return true;
  }
}