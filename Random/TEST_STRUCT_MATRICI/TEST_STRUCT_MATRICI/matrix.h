#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	size_t rows;
	size_t cols;
	double* data;
} matrix;
extern matrix mfill(matrix*, int);
extern void mprint(matrix*);
#endif // MATRIX_H