#include <stdlib.h>

extern int* prodotto(const int* v, size_t n);

int* prodotto(const int* v, size_t n) {
	if (v == NULL || n == 0 || n == 1)
		return NULL;
	int* vet = calloc(n, sizeof(int));
	for (size_t i = 0; i < n; ++i) {
		vet[i] = 1;
		for (size_t j = 0; j < n; ++j) {
			 if(i!=j)
				vet[i] *= v[j];
		}
	}
	return vet;
}