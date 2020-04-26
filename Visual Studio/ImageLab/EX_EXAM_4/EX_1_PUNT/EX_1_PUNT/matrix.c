#include "matrix.h"

void mprint(int **m, int rows, int cols) {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			fprintf(stdout, " %i", m[r][c]);
		}
		puts("");
	}
}

int** matrice_trasp(int **m, int rows, int cols) {
	int** t = (int**)calloc(rows, sizeof(int*));
	for (int i = 0; i < rows; ++i)
		t[i] = (int*)calloc(cols, sizeof(int));
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			t[c][r] = m[r][c];
	}
	return t;
}