#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  char *e;
  uint32_t value;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
  int i;
  for (i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP *new_wp()
{
  if (free_ == NULL) {
    assert(0);
  }
  int i;
  WP *temp = free_;
  WP *n_wp = NULL;
  for (i = 0; i < NR_WP; i++) {
    if (temp->next == NULL) {
      n_wp = temp;
      free_ = NULL;
      break;
    } else if (temp->next->next == NULL) {
      n_wp = temp->next;
      temp->next = NULL;
      break;
    }
    temp = temp->next;
  }
  if (head == NULL) {
    head = n_wp;
    head->NO = 0;
  } else {
    temp = head;
    for (i = 0; i < NR_WP; i++) {
      if (temp->next == NULL) {
        temp->next = n_wp;
        temp->next->NO = i;
        break;
      }
      temp = temp->next;
    }
  }
  return n_wp;
}

void free_wp(int index)
{
  int i;
  WP *temp = head;
  WP *f_wp = head;
  if (index == 0) { // find f_wp
    head = head->next;
    temp = head->next;
  } else {
    for (i = 0; i < index; i++) {
      temp = f_wp;
      f_wp = f_wp->next;
    }
    temp->next = f_wp->next;
    temp = temp->next;
  }
  f_wp->next = NULL;
  // NO - 1
  while (temp->next != NULL) {
    temp->NO = temp->NO - 1;
    temp = temp->next;
  }
  // free_
  if (free_ == NULL) {
    free_ = f_wp;
    free_->NO = 0;
  } else {
    temp = free_;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = f_wp;
    temp->next->NO = temp->NO + 1;
  }
}

void add_new_wp(char *args)
{
  WP *n_wp = new_wp();
  n_wp->e = args;
}

void print_watchpoint()
{
  WP *temp = head;
  if (temp == NULL) {
    printf("no checkpoint!\n");
  }
  int i;
  for (i = 0; i < NR_WP; i++) {
    printf("watchpoint NO.%d is %s -> %u\n", i, temp->e, temp->value);
    if (temp->next == NULL) {
      break;
    }
    temp = temp->next;
  }
}

void check_watchpoint()
{
  WP *temp = head;
  if (temp == NULL) {
    printf("no checkpoint!\n");
  }
  int i;
  bool *success = false;
  uint32_t c_value;
  for (i = 0; i < NR_WP; i++) {
    c_value = expr(temp->e, success);
    if (c_value != temp->value) {
      printf("watchpoint NO.%d change: %u -> %u\n", i, temp->value, c_value);
      temp->value = c_value;
      nemu_state.state = NEMU_STOP;
    }
    if (temp->next == NULL) {
      break;
    }
    temp = temp->next;
  }
}
