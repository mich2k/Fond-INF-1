#include <stdio.h>
#include <stdlib.h>
#include "calcola_seno.h"
#define _USE_MATH_DEFINES
#include <math.h> // Utilizzata solo per la costante pi

double degtorad(double x) {
	return (x * M_PI / 180.0);
}

void main(void) {
	//int *n_esecuz = 0;
	double x = 30.0; // input in gradi
	double ris = calcola_seno(degtorad(x));
	//double ris = calcola_seno(degtorad(x), *n_esecuz); 
	//printf("\n Sono state eseguite %d esecuzioni.", *n_esecuz);
}