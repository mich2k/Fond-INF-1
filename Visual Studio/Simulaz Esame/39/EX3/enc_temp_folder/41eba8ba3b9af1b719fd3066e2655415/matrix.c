#include "matrix.h"

struct bmatrix* mat_boolean(const struct matrix* m, double rhs, enum comparisons cmp) {
	if (m == NULL)
		return NULL;
	struct bmatrix* ris = malloc(sizeof(struct bmatrix));
	ris->cols = m->cols;
	ris->rows = m->rows;
	ris->data = malloc(ris->cols * ris->rows* sizeof(_Bool));
	for (size_t r = 0; r < ris->rows ; ++r) {
		for (size_t c = 0; c < ris->cols; ++c) {
			_Bool* p = &(ris->data[r * ris->rows + c]);
			double* mat = &(m->data[r * m->rows + c]);
			switch (cmp) {
			case LT:
				if (*mat < rhs)
					*p = true;
				else *p = false;
				break;
			case LE:
				if (*mat <= rhs)
					*p = true;
				else *p = false;
				break;
			case EQ:
				if (*mat == rhs)
					*p = true;
				else *p = false;
				break;
			case NE:
				if (*mat != rhs)
					*p = true;
				else *p = false;
				break;
			case GE:
				if (*mat >= rhs)
					*p = true;
				else *p = false;
				break;
			case GT:
				if (*mat > rhs)
					*p = true;
				else *p = false;
				break;
			default:
				break;	
			}
		}
		// LT, LE, EQ, // less than, lower or equal, equal, not equal, greater or equal, greater than
		//	NE, GE, GT
	}
	return ris;
}