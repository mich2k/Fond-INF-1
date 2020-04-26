
/*
Creare un file lungh.c. Nel file, si realizzi in linguaggio C la funzione corrispondente alla seguente
dichiarazione:
extern size_t lungh (const char *str);
La funzione riceve un puntatore a un vettore di char zero terminato (stringa C) e restituisce il
numero di caratteri contenuti (senza il terminatore). Un esempio di chiamata è il seguente:
int main (void) {
char s[] = "Ecco la stringa di prova";
size_t len;
len = lungh(s);
return 0;
}
In questo caso len varrà 24.
Inserite la funzione main() in un file main.c, ovvero non nello stesso file che contiene la definizione
di lung(). Non create un file lung.h.

*/

#include <stdlib.h>

int main(void) {
	char s[] = "Ecco la stringa di prova";
	size_t len;
	len = lungh(s);
	return 0;
}