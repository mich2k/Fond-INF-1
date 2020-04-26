#include "matrix.h"

typedef unsigned int uint;

 matrix mfill(matrix* mat, int n) {
	for (uint r = 0; r < mat->rows; ++r) {
		for (uint c = 0; c < mat->cols; ++c) {
			mat->data[r * mat->cols + c] = n;
		}
	}
}

 void mprint(matrix* m) {
	 for (uint r = 0; r < m->rows; ++r) {
		 for (uint c = 0; c < m->cols; ++c) {
			 fprintf(stdout, " %0.1f", m->data[r*m->cols+c]);
		 }
		 puts("");
	 }
 }
