
/*
Nel file crescenti.c implementare la definizione della funzione:

extern bool crescente(unsigned int x);

La funzione prende come input il valore x e ritorna true se il numero è crescente, false
altrimenti.

Un numero viene detto “crescente”, se ogni cifra della sua rappresentazione in base 10 è
seguita dalla cifra che ha valore successivo o è l’ultima del numero.

Ad esempio:
123 → 1 è seguito da 2 (ok), 2 è seguito da 3 (ok), 3 è l’ultima cifra (ok) → è crescente
5 → 5 è l’ultima cifra (ok) → è crescente
124 → 1 è seguito da 2 (ok), 2 è seguito da 4 (errore) → non è crescente
*/
#include <stdlib.h>
#include <stdbool.h>

extern bool crescente(unsigned int x);

bool crescente(unsigned int x) {
	unsigned int* digits = malloc(1);
	unsigned int val, y=x;
	int i;
	for (i = 0; y % 10 != 0; i++) {
		digits = realloc(digits, (i + 1)*sizeof(unsigned int));
		if (digits == NULL)
			exit(-2);
		y /= 10;
	}
	i--;
	if (i == 0)
		return true;
	int r = i;
	for (; i >= 0; i--) {
		val = x % 10;
		digits[i] = val;
		x /= 10;
		if (i != r && digits[i + 1] < digits[i]) {
				free(digits);
				return false;
		}

	}
	free(digits);
	return true;
}
