#include "scrittura.h"
int scrivimaiuscolo(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (!f || f == NULL)
		return 0;
	char x;
	size_t ret;
	for (;;) {
		ret = fscanf(f, "%c", &x);
		if (ret == 1) {
			if (!(isupper(x)))
				x = toupper(x);
			fprintf(stdout, "%c", x);
		}
		else
		{
			fclose(f);
			return 1;
		}
	}
}


/*
Creare i file scrittura.h e scrittura.c che consentano di utilizzare la seguente funzione:

extern int scrivimaiuscolo(const char *filename);

La funzione riceve in input il nome di un file come stringa C e deve: aprire il file in
lettura in modalità tradotta (testo), se l’apertura fallisce ritornare 0, altrimenti
leggere tutti i caratteri dal file e scriverli su stdout convertendoli in maiuscolo se
sono lettere minuscole, infine ritornare 1. Ricordarsi di chiudere il file se l’apertura
è andata a buon fine.

*/