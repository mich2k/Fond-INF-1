#include "matrix.h"
void main(void) {
	double data[10] = { 1,2,3,4,5,6,7,8,9 };
	struct matrix m = { 3,3,data};
	struct matrix* n;
	n = mat_delete_row(NULL, 3);
}