#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main() {
  struct timeval *last_time;
  struct timeval *curr_time;
  printf("%p\n",last_time);
  _gettimeofday(last_time, NULL);
  int i = 0;
  while (1) {
    i++;
    _gettimeofday(curr_time, NULL);
    long int t_interval = (curr_time->tv_sec - last_time->tv_sec) * 1000 + (curr_time->tv_usec - last_time->tv_usec);
    if (t_interval > 500){
      printf("time pass more than 0.5s in %d time", i);
      *last_time = *curr_time;
      }
  }
  return 0;
}
