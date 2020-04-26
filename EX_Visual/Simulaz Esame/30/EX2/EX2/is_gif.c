/*
Creare i file is_gif.h e is_gif.c che consentano di utilizzare la seguente
funzione:

extern bool is_gif(const char *filename);

La funzione accetta in input una stringa C che contiene il nome di un file e
verifica se il file contiene un immagine in formato GIF, verificando che i primi
6 byte contengano i caratteri GIF89a oppure GIF87a. Se il file non esiste, se non
è possibile leggere 6 byte o se i 6 byte letti non corrispondono ad una delle due
possibilità, la funzione ritorna false, altrimenti true.

Suggerimento: utilizzate HxD per aprire gli esempi forniti e verificare quali
file sono effettivamente GIF.
*/

#include "is_gif.h"

bool is_gif(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL)
		return NULL;
	size_t ret;
	 char* x = "GIF89a";
	char* y = "GIF87a";
	char* z = malloc(60);
	ret = fread(z, 6, 1, f);
	if (ret!= 1 || (strncmp(x, z, 6)!= 0 && strncmp(y,z,6)!=0)){
		fclose(f);
		free(z);
		return false;
	}
	fclose(f);
	free(z);
	return true;
}