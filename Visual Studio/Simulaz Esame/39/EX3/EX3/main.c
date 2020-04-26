#include "matrix.h"
void main(void) {
	double data[] = {
		1, 2 , 3, 0.5,
		4, 5,6,0.3,
		7,8,9,0.230
	};
	struct matrix m= { 3,4, &data };
	mat_boolean(&m, 4.5, LE);
}