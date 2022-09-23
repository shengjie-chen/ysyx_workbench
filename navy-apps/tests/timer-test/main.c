#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "NDL.h"
// #include "/home/jiexxpu/ysyx/ysyx-workbench/navy-apps/libs/libndl/include/NDL.h"

// extern int _gettimeofday(struct timeval *tv, struct timezone *tz);

// int main() {
//   struct timeval last_time, curr_time;
//   struct timeval *ct;
//   struct timeval *lt;
//   ct = &curr_time;
//   lt = &last_time;
//   // printf("%p\n",last_time);
//   gettimeofday(lt, NULL);
//   int i = 0;

//   while (1) {
//     gettimeofday(ct, NULL);
//     long int t_interval = (ct->tv_sec - lt->tv_sec) * 1000 + (ct->tv_usec - lt->tv_usec);

//     if (t_interval > 500) {
//       i++;
//       printf("time pass more than 0.5s in %d time\n", i);
//       last_time = curr_time;
//     }
//   }
//   return 0;
// }

int main() {
  uint32_t ct;
  uint32_t lt;
  lt = NDL_GetTicks();
  int i = 0;
  while (1) {
    ct = NDL_GetTicks();
    long int t_interval = ct - lt;

    if (t_interval > 500) {
      i++;
      printf("time pass more than 0.5s in %d time\n", i);
      lt = ct;
    }
  }
  return 0;
}
