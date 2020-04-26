#include "libri.h"

bool libro_scrivi(const struct libro* p, FILE* f) {
	if (f == NULL) return false;
	size_t ret, i;
	ret = fwrite(p->titolo, sizeof(strlen(p->titolo)), 1, f);
	if (ret != 1 || feof(f) != 0 || ferror(f) != 0)
		return false;
	for (i = 1; p->anni_ristampe[i] != 0; i++);
	ret = fwrite(p->anni_ristampe, sizeof(uint16_t), i+1, f);
	if (ret != i+1 || feof(f) != 0 || ferror(f) != 0)
		return false;
	return true;
}


/*
La funzione riceve un puntatore ad un elemento di tipo struct libro e deve scriverne i
dati sul file già aperto in modalità scrittura non tradotta (binaria) passato come
parametro. Il titolo viene scritto come sequenza di byte terminata con un ulteriore byte
uguale a 0 come le stringhe C, il campo anni_ristampe punta al primo di una sequenza di
interi senza segno a 16 bit terminata con uno di questi che vale 0. Deve essere scritta
su file in little endian (esattamente come in memoria nei processori Intel). La funzione
ritorna true se tutto va bene, o false se la scrittura fallisce.
Il seguente libro:

struct libro +
			 | titolo --> "Geometria"
		 |
		 | anni_ristampe --> { 2001, 2002, 0 }

Verrebbe scritto su file come:

Offset(h) 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
00000000  47 65 6F 6D 65 74 72 69 61 00 D1 07 D2 07 00 00  Geometria.Ñ.Ò...
*/
