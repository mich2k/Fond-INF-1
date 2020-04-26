#include "lettura.h"
#include <ctype.h>

/*
La funzione leggidouble() riceve in input il nome di un file come stringa C e
deve: aprire il file in lettura in modalità tradotta (testo), leggere i numeri in
variabili di tipo double allocando dinamicamente la memoria, impostare size al
numero di numeri trovati nel file, e ritornare un puntatore alla memoria
allocata. Se l’apertura fallisce o se non è possibile leggere nemmeno un numero,
ritornare NULL. Ricordarsi comunque di chiudere il file se l’apertura è andata a
buon fine.
*/



double* leggidouble(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "r");
	if (!f)
		return NULL;
	size_t n=0, ret;
	double* buff = NULL; // allocato e punta a nulla, ma definito
	double x;
	for (;;) {
		ret = fscanf(f, "%lf", &x);
		//ret = fread(&x, sizeof(double), 1, f);
		if (ret == 1) {
			buff = realloc(buff, (n + 1) * sizeof(double));
			*(buff + n) = x;
			++n;
		}
		else
		{
			if (n == 0) {
				fclose(f);
				return NULL;
			}
			else {
				if (feof(f) || ferror(f)) {
					*size = n;
					fclose(f);
					return buff;
				}
			}
		}
	}
}















/*
int look(FILE* f) {
	size_t x=0;
	for (;;) {
		//fseek(f, y , 0);
		fread(&x, 1, 1, f);
		if(isblank(x)!= 0)
			return x;
		x++;

	}
}

extern double* leggidouble(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) // Se il file non esiste -> NULL
		return NULL;
	double x;
	size_t ret, n = 0, y = 0;
	double* _buff = NULL;
	for (;;) {
		ret = fread(&x, sizeof(double), 1, f);
		if (ret != 1 || ferror(f) != 0 || feof(f) != 0) {
			if (n == 0) { // "non è possibile leggere nemmeno un numero -> NULL
				fclose(f);
				return NULL;
			}
			*size = n;
			fclose(f);
			return _buff;
		}
		_buff = realloc(_buff, (n + 1) * sizeof(double));
		_buff[n] = x;
		n++;
	}
}*/