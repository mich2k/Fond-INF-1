#include <stdlib.h>

extern int* clamped(const int* v, size_t n, int min, int max);

int* clamped(const int* v, size_t n, int min, int max) {
	if (min > max || v == NULL || n == 0)
		return NULL;
	int* ris = calloc(n, sizeof(int));
	for (size_t i = 0; i < n; ++i) {
		if (v[i] > max)
			ris[i] = max;
		else {
			if (v[i] < min)
				ris[i] = min;
			else ris[i] = v[i];
		}
	}
	return ris;
}