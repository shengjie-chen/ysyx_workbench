#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,
  DEC_INT

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
    {"\\+", '+'},      // plus
    {"==", TK_EQ},     // equal

    {"[0-9]+", DEC_INT}, // decimal integer
    {"\\-", '-'},        // substract
    {"\\*", '*'},        // multiply
    {"/", '/'},          // divide
    {"\\(", '('},        // (
    {"\\)", ')'}         // )
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
        assert(nr_token < 32);
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

static uint32_t eval(int p, int q)
{
  if (p > q) {
    panic("Bad expression\n");
    return 0;
  } else if (p == q) {
    if (tokens[p].type == DEC_INT) {
      uint32_t val;
      sscanf(tokens[p].str, "%d", &val);
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
      case '-':
      case '+':
        op = i;
        op_type = tokens[i].type;
        i++;
        break;
      case '*':
      case '/':
        if (op_type != '+' && op_type != '-') {
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
    uint32_t val1 = eval(p, op - 1);
    uint32_t val2 = eval(op + 1, q);

    switch (op_type) {
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
  uint32_t value;
  value = eval(0, nr_token - 1);
  printf("EXP is %d\n", value);
  return value;
}

bool check_expr()
{
  FILE *fp = fopen("./tools/gen-expr/input", "r");
  char input[65536];
  bool *success = 0;
  uint32_t result;
  char e[65536];
  if (fp == NULL) {
    panic("read expr input file error\n");
  } else {
    int i;
    for (i = 0; i < 1000; i++) {
      printf("check %d line",i);
      if (fgets(input, 65536, fp) != NULL) {
        sscanf(input, "%u %s\n", &result, e);
        if (expr(e, success) != result) {
          return false;
        }
      }
    }
    return true;
  }
}