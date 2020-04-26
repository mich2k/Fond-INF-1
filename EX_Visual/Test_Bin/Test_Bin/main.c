#include <stdlib.h>
#include "stdio.h"
#include <string.h>

#pragma warning(disable:4996)

#define MAX 20

typedef unsigned int uint;

int main(void) {
	size_t ret;
	double* arr = (double*)malloc(MAX * sizeof(double));
	for (size_t cont = 0; cont < MAX; ++cont)
		*(arr + cont) = cont + 1;
	const char* x = "Domenico e scemo";
	FILE* f = fopen("test.bin", "wb");
	FILE* _f = fopen("test.txt", "w");
	if (f == NULL || _f == NULL)
		return NULL;
	for (int i = 0; i < MAX; i++)
		fprintf(_f, "%.2lf, ", *(arr + i));
	fprintf(_f, "\n\n\n");
	for (int i = 0; i < strlen(x); i++)
		fprintf(_f, "%c", *(x+i));
	 ret = fwrite(arr, sizeof(double), MAX, f);
	if (ret != MAX || ferror(f))
		return NULL;
	fprintf(f, "\n\n\n");
	 ret = fwrite(x,sizeof(char), strlen(x), f);
	if (ret != strlen(x) || ferror(f))
		return NULL;
	fclose(f);
	fclose(_f);
	free(arr);
	return EXIT_SUCCESS;
}