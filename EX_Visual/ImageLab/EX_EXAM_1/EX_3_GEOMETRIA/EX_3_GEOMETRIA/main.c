#include <stdlib.h>
#include "geometria.h"

void main(void) {
	struct punto p1 = { 3, 4 };
	struct punto p2 = { 7, 4 };
	struct punto p3 = { 3, 4 };
	colineari(p1,p2,p3);
}