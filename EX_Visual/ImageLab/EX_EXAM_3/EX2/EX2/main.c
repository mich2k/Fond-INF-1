/*
Creare i file lettura.h e lettura.c che consentano di utilizzare la seguente
funzione:

extern int *leggiinteri2(const char *filename, size_t *size);

È stato definito un formato binario (veramente banale) di dati per memorizzare
numeri interi a 32 bit, che consiste nel memorizzare i numeri interi a 32 bit in
little endian tutti in sequenza. Ad esempio un file contenente i valori 7, 8 e 9
verrebbe codificato con i seguenti byte (rappresentati in esadecimale nel seguito):

07 00 00 00 08 00 00 00 09 00 00 00

La funzione leggininteri2() riceve in input il nome di un file come stringa C e
deve: aprire il file in lettura in modalità non tradotta (binaria), leggere gli
interi allocando dinamicamente la memoria, impostare size al numero di interi
trovati nel file, e ritornare un puntatore alla memoria allocata. Se l’apertura
fallisce o se non è possibile leggere nemmeno un intero, ritornare NULL.
Ricordarsi comunque di chiudere il file se l’apertura è andata a buon fine.*/


#include <stdlib.h>
#include <stdio.h>
#include "lettura.h"
#pragma warning(disable:4996)


void main(void) {
	size_t size;
	int* ptr = leggiinteri2("C:\\dati2.bin", &size);
}


/*
	printf("\n Sono presenti %i numeri: \n\n\n\n ", size);
	for (size_t i = 0; i < size; ++i) {
		if (i == size - 1)
			printf(" %i ", *(ptr + i));
		else
			printf(" %i, ", *(ptr + i));
	}
	printf("\n\n\n\n");

*/