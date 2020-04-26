#include "ip.h"
#include <string.h>

uint32_t* leggi_indirizzi_ip(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "r");
	if (f == NULL ) {
		*size = 0;
		return NULL;
	}
	fseek(f, 0, SEEK_END);
	unsigned short x = ftell(f);
	if (x == 0) {
		*size = 0;
		return NULL;
	} 
	fseek(f, 0, 0);
	// massimo
	int val = 0;
	char ch = 0;
	size[0] = 0;
	uint32_t* dst = NULL;
	for (;;) {
		size_t j = 0;
		uint32_t num = 0;
		for (size_t i = 0; i < 4; ++i) {
			fscanf(f, "i", &val);
			if ((feof(f) || ferror(f) || val < 0 || val > 255) && i != 3) {
				fclose(f);
				*size = 0;
				free(dst);
				return NULL;
			}
			val <<= (j * 8);
			++j;
			num += val;
			fscanf(f, "%c", &ch);
			if ((feof(f) || ferror(f) || ch != '.') && i != 3) {
				fclose(f);
				*size = 0;
				free(dst);
				return NULL;
			}
			++size[0];
			dst = realloc(dst, sizeof(uint32_t) * size[0]);
			dst[(*size) - 1] = num;
			fscanf(f, "%c", &ch);
			if (feof(f)) break;
			else (fseek(f, -1, SEEK_CUR));
		}
		fclose(f);
		return dst;

	}
}





	/*uint32_t *ris = NULL;
	char* s = malloc(16);
	char *c=malloc(4);
	int orig = 0;
	char m;
	while (fscanf(f, "%[\n]") != 0, &m) {
		r = 0;
		for (;;) {
			if (fscanf(f, "%[^., \n]", c) != 0) {
				ris = realloc(ris, (r + 1)*sizeof(uint32_t));
				ris[r] = atoi(c);
				r++;
				if (r == 4) {
					for (int l = 0; l < 4; l++) {
						itoa(ris[l], s, 10);
						int val = 8 - strlen(s);
						ris[l] <<= 8;
					}
					break;
				}
			}
			else
				fseek(f, 1, SEEK_CUR);
		}
	}

	fclose(f);
	return ris;
	*/

/*
Creare i file ip.h e ip.c che consentano di utilizzare la seguente funzione:

extern uint32_t *leggi_indirizzi_ip(const char *filename, size_t *size);

La funzione riceve il nome di un file da aprire in modalità lettura tradotta (testo), e
un puntatore ad un size_t. Il file contiene una sequenza di righe contenenti indirizzi IP
in formato testo, ovvero quattro numeri interi da 0 a 255 separati da tre punti. Ad
esempio:

127.0.0.1↵
10.0.42.3↵
78.15.46.23↵

La funzione deve convertire il file in una sequenza allocata dinamicamente di numeri
interi a 32 bit in big endian. Ogni numero è formato dai 4 byte corrispondenti ai valori
degli indirizzi IP. Nel caso precedente, la funzione dovrebbe allocare 3 interi a 32 bit,
che contengano i valori 0x7F000001, 0x0A002A03, 0x4E0F2E17. La variabile puntata da size
deve essere impostata al numero di valori letti.

Se il file è vuoto o non esiste, se contiene numeri non compresi nell’intervallo
rappresentabile in un byte o se contiene linee incomplete, la funzione ritorna NULL e
imposta size a 0.
*/