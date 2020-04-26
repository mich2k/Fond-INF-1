#include "matrix.h"

struct matrix* mat_delete_row(const struct matrix* m, size_t i) {
	if (m == NULL || m->data == NULL) // E NECESSARIO PRIMA CONTROLLARE LA MATRICE
		return NULL;					// E SUCCESSIVAMENTE I PARAMETRI ALL INTERNO
	if (i < 0 || i >= m->rows || m->rows == 1 ) //ALTRIMENTI CRASHA ERR_NLLPTR
		return NULL;
	int flag = 0;
	struct matrix* n = malloc(sizeof(struct matrix));
	n->cols = m->cols;
	n->rows = m->rows - 1;
	n->data = malloc(n->cols * n->rows * sizeof(double));
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
				if(i != r){
					if( r < i )
						n->data[r * m->cols + c] = m->data[r * m->cols + c];
					else {
						n->data[(r-1) * m->cols + c] = m->data[(r) * m->cols + c];
					}
				}
			}
		}
	return n;
	}