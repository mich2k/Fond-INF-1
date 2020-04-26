#include <stdlib.h>
extern int* convolution3(const int* v, size_t lenv, const int k[3]);

void main(void) {
	const int v[] = {1,2,3,4,3,2,1};
	const int k[] = { -1,2,-1 };
	convolution3(v,7,k);
}