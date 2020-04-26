#include <stdio.h>
#include <stdlib.h>
#include "stat.h"

typedef unsigned int uint;

double media(double* x, uint n);
double varianza(double* x, double avg, uint n);

void array_fill(double* ptr, uint n) {
	if (ptr) { // assicura che calloc/malloc non torni 0/NULL
		for (uint i = 0; n > i; i += 1)
		{
			*(ptr + i) = i + (double)3; // malloc || calloc (alloc. din) richiedono di partire da 0, altrimenti si verificherà
							  // un heap buffer error con violazione di accesso di memoria
		}
	}
}


void main(void) {
	uint n = 5; // array size
	double* array = calloc(n, sizeof(double));
	array_fill(array, n);
	double aver = media(array, n);
	double _varianza = varianza(array, aver, n);
	free(array);
}