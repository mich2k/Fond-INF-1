#include "matrix.h"

// matrice di tutti uno, usando malloc

//ALLOCAZIONE DINAMICA MATRICE ATTRAVERSO LE STRUCT

void main(void) {
	/*
		Questo corrisponde alla definizione -> matrix* m; 
		+ l inizializzazione
		m=malloc(sizeof(matrix));, allocando dinamicamente quindi due size_t per un totale di 8 byte
		ed un puntatore a data di 4 byte. free(m); libererà questi 12 byte e free(m->data); libererà 
		gli altri cols*rows*8byte dati
	*/
	matrix* m = malloc(sizeof(matrix)); // ALLOCO DINAMICAMENTE LA STRUCT
	m->cols = 3;
	m->rows = 3;
	m->data = malloc(m->cols * m->rows * sizeof(double)); // ALLOCO SPAZIO DATI
	// ... utilizzo matrice ->
	mfill(m, 2);
	mprint(m);
	free(m->data); // DEALLOCO I DATI
	free(m); // LIBERO LA STRUCT
}