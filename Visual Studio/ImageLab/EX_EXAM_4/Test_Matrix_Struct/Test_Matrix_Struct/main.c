#include <stdlib.h>
#include <stdio.h>

// 2 way: struct + (typedef)

typedef struct {
	size_t rows;
	size_t cols;
	int* data;
} matrix;

 matrix* trasp(matrix *m) {
	 matrix* tra = malloc(sizeof(matrix));
	tra->data = calloc(m->cols * m->rows, sizeof(int)); // ACHTUNG
	tra->cols = m->cols;
	tra->rows = m->rows;
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			tra->data[c*tra->cols+r] = m->data[r * m->cols + c];
			//printf(" %i", >data[r * m->cols + c]);
			//m->data[r] = 1;
			//printf(" %i", m->data[r]);
		}
		puts("");
	}
	return tra;
}

void main(void) {
	size_t rows = 4, cols = 3;
	int* data = calloc(rows * cols, sizeof(int));
	if (data) {
		for (unsigned int i = 0; i < rows * cols; ++i)
			data[i] = i + 1;
		 matrix matrice = { rows, cols, data };
		 matrix* t = trasp(&matrice);
		for (size_t r = 0; r < t->rows; ++r) {
			for (size_t c = 0; c < t->cols; ++c) {
				printf("%i ", t->data[r * 3 + c]);
			}
			puts("");
		}
		free(data);
		free(t);
	}
	else
		exit(10);
}