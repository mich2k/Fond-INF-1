#include "leggi_linee.h"

char** leggi_linee(const char* filename) {
	if (filename == NULL)
		return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	fseek(f, 0, SEEK_END);
	unsigned int len = ftell(f);
	fseek(f, 0, 0);
	if (len == 0) {
		char* p = NULL;
		char** ris = &p;
		return ris;
	}
	char** ris = malloc(sizeof(char*)*1000);
	char c;
	size_t j = 0, i = 0, flag = 1;
	for (i = 0;flag!=0; ++i) {
		j = 0;
		for (;;) {
			if (j == 0) {
				ris[i] = NULL;
				fseek(f, -1, SEEK_CUR);
			}
				ris[i] = realloc(ris[i], sizeof(char) * (j + 1));
				c = fgetc(f);
				if (iscntrl(c) || j ==255) break;
				if (isprint(c))
					ris[i][j] = c;
				j++;
			}
			ris[i] = realloc(ris[i], sizeof(char) * (j + 1));
			ris[i][j] = '\0';
			if (fscanf(f, "%c", &c) == EOF || feof(f) || ferror(f))
				flag = 0;
		}
	        ris[i] = realloc(ris[i], sizeof(char) * (j + 1)+ sizeof(NULL));
			ris[i][0] = NULL;
			fclose(f);
			return ris;
		
	}


/*

Creare i file leggi_linee.h e leggi_linee.c che consentano di utilizzare la
seguente funzione:

extern char **leggi_linee(const char *filename);

La funzione accetta in input una stringa C che contiene il nome di un file da
aprire in modalità lettura tradotta. La funzione deve ritornare un vettore di
stringhe C contenente tutte le linee del file.
Il doppio puntatore ritornato dalla funzione dovrà puntare alla prima stringa
(la prima linea del file). Per indicare il termine del vettore ritornato dalla
funzione non si usa un'altra variabile per memorizzare la dimensione ma,
similmente a come viene fatto per le stringhe C, dopo il suo ultimo elemento
viene allocato spazio anche per un puntatore NULL.

Consideriamo il seguente file di esempio:

Prima riga↵
Seconda riga↵
Terza riga↵

In questo caso la funzione dovrebbe ritornare un doppio puntatore a char che
punterà al primo di quattro puntatori singoli a char i quali a loro volta
punteranno ai primi caratteri di tre stringhe C, rispettivamente “Prima riga”,
“Seconda riga” e “Terza riga”, mentre il quarto sarà un puntatore NULL.
Le righe lette NON dovranno contenere il carattere “a capo” alla fine e si può
assumere che le linee siano lunghe al massimo 255 caratteri, carattere “a capo”
compreso. Se alla funzione viene passato un puntatore NULL o se non è possibile
aprire il file la funzione dovrà ritornare NULL. Se invece il file esiste ma non
contiene alcun carattere, la funzione ritornerà un puntatore ad un puntatore NULL.
*/