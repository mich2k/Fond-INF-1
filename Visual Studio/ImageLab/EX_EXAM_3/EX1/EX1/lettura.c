#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

extern int* leggiinteri(const char* filename, size_t* size) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		//fclose(f); NON FARE
		return NULL;
	}
	else
	{
		size_t ret;
		unsigned int n = 0;
		ret = fread(&n, sizeof(int), 1, f); // CONTROLLARE ANCHE CON N
		if (ret != 1) {
			if (feof(f) != 0 || ferror(f)) {
				fclose(f);
				return NULL;
			}
		}
		int* _buff = calloc(n, sizeof(int));
		if (_buff) {
			fseek(f, (long)sizeof(int), 0); // sposto il cursore di 4 byte
			ret = fread(_buff, sizeof(int), n, f);
			if (ret != n) {
				if (feof(f) != 0 || ferror(f)) {
					fclose(f);
					return NULL;
				}
			}
			*size = n; // necessario altrimenti imagelab "Sbagliato"
			fclose(f);
			return _buff;
		}
	}
}