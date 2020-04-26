
// Esercizio 1, 2 && 3

#include <stdio.h>
#include <stdlib.h>

void potenza(double* x, size_t i) {
	for (size_t n=0; n < i; ++n) {
		*(x+i) *= *(x+i);
	}
}
	int main(void)
	{
		double a[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
		size_t i, n = 10;
		for (i = 0; i < n; ++i) {
			//double d = a[i];
			potenza(a, i);
			//a[i] = d;
		}
		return 0;
	}