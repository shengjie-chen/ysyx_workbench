#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main() {
  struct timeval last_time, curr_time;
  struct timeval *ct;
  struct timeval *lt;
  ct = &curr_time;
  lt = &last_time;
  // printf("%p\n",last_time);
  _gettimeofday(lt, NULL);
  int i = 0;
  while (1) {
    _gettimeofday(ct, NULL);
    long int t_interval = (ct->tv_sec - lt->tv_sec) * 1000 + (ct->tv_usec - lt->tv_usec);
    printf("%d\n",t_interval);
    if (t_interval > 500) {
      i++;
      printf("time pass more than 0.5s in %d time", i);
      last_time = curr_time;
    }
  }
  return 0;
}
