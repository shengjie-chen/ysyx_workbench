#include <BMP.h>
#include <NDL.h>
#include <assert.h>
#include <fixedptc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  fixedpt A = fixedpt_rconst(1.2);
  fixedpt B = fixedpt_fromint(10);
  fixedpt C = 0;
  if (B > fixedpt_rconst(7.9)) {
    C = fixedpt_div(fixedpt_mul(A + FIXEDPT_ONE, B), fixedpt_rconst(2.3));
  }

  float a = 1.2;
  float b = 10;
  int c = 0;
  if (b > 7.9) {
    c = (a + 1) * b / 2.3;
  }

  if (c != fixedpt_toint(C)) {
    printf("fixedpt function error!\n");
  }

  // srand((unsigned int)time(NULL));

  //   for(int i=0;i < 100;i++){
  // int u_float = rand() % 1000 ;
  // int u_int = rand() % 1000;
  // int u_sign = rand() % 2;
  // int spec_floor;
  // int spec_ceil;

  //   }
  // printf("fixedpt floor function pass!\n");
  printf("1.2 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(1.2))));
  printf("1.2 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(1.2))));
  printf("-1.2 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(-1.2))));
  printf("-1.2 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(-1.2))));
  printf("4 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(4))));
  printf("4 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(4))));
  printf("-4 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(-4))));
  printf("-4 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(-4))));
  printf("49.665 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(49.665))));
  printf("49.665 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(49.665))));
  printf("-49.665 floor result is %d\n", fixedpt_toint(fixedpt_floor(fixedpt_rconst(-49.665))));
  printf("-49.665 ceil result is %d\n", fixedpt_toint(fixedpt_ceil(fixedpt_rconst(-49.665))));
  printf("----\n");
  printf("-1.2 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(-1.2))));
  printf("4 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(4))));
  printf("-4 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(-4))));
  printf("49.665 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(49.665))));
  printf("-49.665 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(-49.665))));
  printf("1.2 abs result is %d\n", fixedpt_toint(fixedpt_abs(fixedpt_rconst(1.2))));

  return 0;
}
