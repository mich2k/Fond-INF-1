
/*
Creare i file string_split.h e string_split.c che consentano di utilizzare la seguente
funzione:

extern void string_split(const char *str, size_t index, char **s1, char **s2);

La funzione prende come parametri una stringa C, un size_t e due puntatori a puntatore a
char. La funzione deve dividere la stringa in due in corrispondenza dell’indice passato
nella variabile index e modificare i puntatori puntati da s1 e s2 in modo che puntino a
due nuove stringhe allocate dinamicamente contenenti le due parti della stringa.

Consideriamo ad esempio la stringa “alfabetizzazione” da spezzare all’indice 6. In questo
caso si otterranno due stringhe: la prima contenente le prime 6 lettere (“alfabe”) e la
seconda contenente le restanti 10 (“tizzazione”).

Se la stringa è NULL o se l’indice è maggiore del numero di caratteri della stringa, la
funzione imposta i puntatori puntati da s1 e s2 a NULL.
*/

#include "string_split.h"

void string_split(const char* str, size_t index, char** s1, char** s2) {
	if (str == NULL ) {
		s1 = NULL;
		s2 = NULL; 
		return;
	}
	if (index > strlen(str)) {
		s1[0] = NULL;
		s2[0] = NULL;
		return;
	}
	char* new_s1 = calloc((index + 1) , sizeof(char)+100);
	char* new_s2 = calloc((strlen(str) - index + 1) , sizeof(char)+100);
	size_t cont = 0, i, j;
	for ( i = 0; i < index; ++i)
		new_s1[i] = str[i];
	new_s1[i] = '\0';
	for ( j = index; j < strlen(str); ++j) {
		new_s2[cont] = str[j];
		++cont;
	}
	new_s2[cont] = '\0';
	s1[0] = new_s1;
	s2[0] = new_s2;
}