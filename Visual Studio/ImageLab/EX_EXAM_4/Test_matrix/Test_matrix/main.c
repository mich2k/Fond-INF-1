#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

void main(void) {
	system("color f0");
	// matrice di zeri
	int** matrix; // vettore verticale
	int cols = 6, rows = 5;
	matrix = (int**)malloc(rows* sizeof(int*));
	puts("");
	for (int cont = 0; cont < rows; ++cont)
		matrix[cont] = (int*)calloc(cols, sizeof(int));
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			fprintf(stdout, " %i", matrix[r][c]);
		puts("");
	}
	// INIZIO FREE
	for (int cont = 0; cont < rows; ++cont)
		free(matrix[cont]);
	free(matrix);
	}
	
	
	/*
	int i, rows, cols, **mat;
	mat = malloc(rows*sizeof(int*));
	for(i=0;i<rows;i++) mat[i] = malloc(cols*sizeof(int));	
	*/