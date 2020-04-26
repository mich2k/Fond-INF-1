/*
Creare i file stringhe.h e stringhe.c che consentano di utilizzare la seguente funzione:

extern char *title(const char *str);

La funzione riceve in input un puntatore a una stringa C str e in uscita deve produrre
una nuova stringa C allocata dinamicamente che contenga la stringa str con l’iniziale di
ogni parola in maiuscolo. Con “parola” si intende qualsiasi sequenza che non contenga
whitespace (spazi, tabulazioni o a capo).
La funzione deve gestire correttamente qualsiasi carattere ASCII nelle parole e se il
puntatore è NULL, deve ritornare NULL.
*/

#include "stringhe.h"

char* title(const char* str) {
	if (str == NULL)
		return NULL;
	char* r = calloc(sizeof(char), strlen(str)+1); // terminatore ?
	r[0] = toupper(str[0]);
	for (size_t i = 1; i < strlen(str); ++i) {
		if (str[i] != ' ' && str[i] != '\0' && isblank(str[i - 1]) != 0)
			r[i] = toupper( str[i] );
		else 
			r[i] =str[i];
	}
	return r;
}