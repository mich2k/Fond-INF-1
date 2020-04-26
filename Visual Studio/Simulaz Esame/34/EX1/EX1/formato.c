#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

extern bool is_date(const char* s);


bool is_date(const char* s) {
	if (s == NULL) return false;
	unsigned short digits = 0, exc = 0, flag = 0;
	for (unsigned short i = 0; *(s + i) != '\0'; ++i) {
		if (isdigit(s[i])) {
			++digits;
		}
		else {
			if (s[i] != '/')
				return false;	
			else {
				if (digits != 2 && digits != 4)
					return false;
				exc++;
			}
		}
	}
	if (digits == 8 && exc == 2)
		return true;
	return false;
}

/*
Nel file formato.c definire la funzione corrispondente alla seguente
dichiarazione:

extern bool is_date(const char *s);

La funzione accetta una stringa zero terminata e deve verificare se rispetta il
formato di una data in cui il giorno e il mese sono rappresentati da due cifre,
l’anno da quattro cifre e sono separati dal carattere “/”. La funzione ritorna
1 se il formato è corretto, 0 se il puntatore è NULL, o se la stringa non
rispetta il formato indicato.
Ad esempio la stringa “10/07/2015” rispetta il formato, mentre “10-7-15” o
“10.07.2015” no.
*/