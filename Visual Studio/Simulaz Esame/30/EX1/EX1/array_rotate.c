#include <stdlib.h>
extern int* rotate(const int* vec, size_t len, size_t r);

// 1 2 3 4

int* rotate(const int* vec, size_t len, size_t r) {
	if (vec == NULL)
		return NULL;
	size_t j = 0;
	int* ris = calloc(len, sizeof(int));
	//len--;
	for (size_t i = 0; i < len; ++i) {
		if (r + i > len)
			;//ris[i] = vec[r-len + i];
		else {
			ris[i] = vec[i];
		}
	}
	return ris;
}
