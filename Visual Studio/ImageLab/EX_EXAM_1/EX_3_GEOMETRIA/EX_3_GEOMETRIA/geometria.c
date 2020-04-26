#include <stdlib.h>
#include "geometria.h"

int colineari(struct punto p1, struct punto p2, struct punto p3) {
	if (((p3.x - p2.x) * (p1.y - p2.y)) == ((p3.y - p2.y) * (p1.x - p2.x)))
		return 1;
		return 0;
}

// (x_3-x_2)(y_1-y_2) = (y_3-y_2)(x_1-x_2)
