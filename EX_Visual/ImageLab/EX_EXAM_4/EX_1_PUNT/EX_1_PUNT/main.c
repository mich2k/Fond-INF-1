#include "matrix.h"

void main(void) {
	int rows = 6,
		cols = 6;

	// ALLOCO m
	int** m;
	m = (int**)malloc(rows * sizeof(int*));
	for (int cont = 0; cont < rows; ++cont)
		m[cont] = (int*)malloc(cols * sizeof(int));

	// INPUT GENERICO
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			m[r][c] = r;
		}
	}


	int** t = matrice_trasp(m, rows, cols);

	//PRINT
	mprint(m, rows, cols);
	puts("");
	mprint(t, rows, cols);

	//FREE
	for (int cont = 0; cont < rows; ++cont) {
		free(m[cont]);
		free(t[cont]);
	}
	free(t);
	free(m);
}