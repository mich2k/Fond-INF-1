#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


extern int* leggiinteri2(const char* filename, size_t* size){
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		//fclose(f); NON FARE
		return NULL;
	}
	int* _buff = NULL; // calloc(n, sizeof(int)); // int* buff = NULL; EQUIVALE A DIRE PTR A 0/NULL
	int* temp = calloc(1, sizeof(int)); // equivalente a scrivere int temp; e fread(&temp, ... );
	size_t ret, n = 0;
		for(;;) {
			ret = fread(temp, sizeof(int), 1, f);
			if (feof(f) != 0 || ferror(f) != 0 || ret != 1)
			{
				if (n == 0) {
					fclose(f);
					free(temp);
					return NULL;
				}
				else {
					fclose(f);
					*size = n;
					free(temp);
					return _buff;
				}
			}
			else {
				_buff = realloc(_buff, (n + 1) * sizeof(int));
				*(_buff + n) = temp[0];
			}
			++n;
	}
}






/*
if (_buff) {
	// Metodo Relloc
	fseek(f, 0, 0);
	for (;;) {
		ret = fread(&x, sizeof(int), 8, f);
		if (ret != n) {
			if (n == 1) {
				fclose(f);
				return NULL;
			}
			else
				break;
		}
			else
			{
				++n;
				_buff = realloc(_buff, (n+1) * sizeof(int));
				fseek(f, sizeof(int), (n) * sizeof(int));
			}
	}
	fclose(f);
	*size = n; // imposto size al numero di interi trovati
	return _buff;
}
return NULL;*/