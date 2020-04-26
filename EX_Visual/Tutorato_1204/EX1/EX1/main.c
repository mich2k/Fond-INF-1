/*
Creare un file “main.c”. Nel file, si completi la seguente funzione utilizzando comandi del linguaggio
C:
uint32_t divisore_minimo (uint32_t x) {
...
}
La funzione restituisce il più piccolo divisore del numero x tra i numeri naturali maggiori di 1.
Qualora x sia minore di 2, la funzione restituisce 0.
*/

#include <stdint.h>
#include <stdlib.h>
typedef uint32_t u32;

uint32_t divisore_minimo(uint32_t x) {
	if (x < 2)
		return 0;
	size_t i;
	for (i = 2; i < x; ++i) {
		if (x % i == 0)
			return i;
	}
}

void main(void) {
	divisore_minimo(7);
}
