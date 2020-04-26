#include <stdlib.h>

extern int* convolution3(const int* v, size_t lenv, const int k[3]);

int* convolution3(const int* v, size_t lenv, const int k[3]) {
	if (v == NULL)
		return NULL;
	if (k == NULL)
		return NULL;
	int temp = 0;
	int* c = calloc(lenv, sizeof(int));
	for (size_t n = 0; n < lenv; ++n) {
		for (size_t m = 0; m <= 2; ++m) {
			if ((n+1-m) < 0 || (n+1-m) >= lenv)
				c[n] += 0;
			else
			c[n] += v[n + 1 - m] * k[m];
		}
	}
	return c;
}