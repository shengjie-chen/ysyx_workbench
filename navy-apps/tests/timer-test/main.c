#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

// extern int _gettimeofday(struct timeval *tv, struct timezone *tz);

int main() {
  struct timeval last_time, curr_time;
  struct timeval *ct;
  struct timeval *lt;
  ct = &curr_time;
  lt = &last_time;
  // printf("%p\n",last_time);
  gettimeofday(lt, NULL);
  int i = 0;
  int j = 0;
  while (1) {
    j++;

    gettimeofday(ct, NULL);
    long int t_interval = (ct->tv_sec - lt->tv_sec) * 1000 + (ct->tv_usec - lt->tv_usec);
    // printf("%ld\n",t_interval);
    if (j == 500) {
      printf("%ld\n", t_interval);
      printf("%lds %ldms\n", ct->tv_sec, ct->tv_usec);
    }
    if (t_interval > 500) {
      i++;
      printf("time pass more than 0.5s in %d time", i);
      last_time = curr_time;
    }
  }
  return 0;
}
