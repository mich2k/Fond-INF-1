#include <stdlib.h>
#include "complessi.h"

void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2) {

	 comp1->re =  (comp1->re * comp2->re - comp1->im * comp2->im);
	 comp1->im = (comp1->re * comp2->re + comp2->re * comp1->im);
}
