#include "klib.h"
int a[20];
int b[20] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 133, 432, 432, 55 , 66, 77, 88, 99, 100, 101};

int main() {
    for (int i = 0; i < 20; i++) {
        a[i] = i;
		// b[i] = i*2;
    }
	// for(int j = 0; j < 5; j++) {
	// 	printf("a[%d] = %d\n", j, a[j]);
	// }
	for(int j = 0; j < 5; j++) {
		printf("b[%d] = %d\n", j, b[j]);
	}
    
    return 0;
}