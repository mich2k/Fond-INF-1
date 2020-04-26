#include "matrix.h"
struct matrix* scambia_diagonali(const struct matrix* m) {
	if (m == NULL || (m->cols+m->rows)%2!=0)
		return NULL;
	struct matrix* ris = malloc(sizeof(struct matrix));
	ris->cols = m->cols;
	ris->rows = m->rows;
	ris->data = calloc(ris->cols * ris->rows, sizeof(double));
	for (unsigned short r = 0; r < ris->rows; ++r) {
		for (unsigned short c = 0; c < ris->cols; ++c)
			ris->data[r * ris->cols + c] = m->data[r * m->cols + c];
	}
	for (unsigned short r = 0; r < ris->rows; ++r) {
		for (unsigned short c = 0; c < ris->cols; ++c) {
			if (r + c == (ris->cols-1)) {
				double tmp = ris->data[r * ris->cols + c];
				ris->data[r * ris->cols + c] = ris->data[r * ris->cols + r];
				ris->data[r * ris->cols + r] = tmp;
			}
		}
	}
	return ris;
}