#include <stdio.h>
#include <stdlib.h>
//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) // IMPORTANTE

int main(void) {
	FILE* f = fopen("file.txt", "w");
	if (f == NULL)
		return -1;
	char* s = "Jew what do you mean";
	fprintf(f, "%s", s);
	fclose(f);
	FILE* fbin = fopen("file_bin.bin", "wb");
	if (fbin == NULL)
		return -1;
	int num[] = {
		1001,
		2110,
		3221
	};
	size_t ret = fwrite(num, sizeof(int), 3, fbin);
	// puntatore a dove leggere i dati
	// dimensione un dato
	// quanti dati sono
	// stream file 
	if (ret != 3)
		return -2;
	fclose(fbin);
	return EXIT_SUCCESS;
}