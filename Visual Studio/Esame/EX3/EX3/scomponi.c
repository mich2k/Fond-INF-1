#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

extern void stampa_scomposizione(unsigned int n);

void stampa_scomposizione(unsigned int n) {
	int _arr[5] = { 5,4,3,2,1 };
	sort(_arr, 1, 5);
	if (n == 0) {
		fprintf(stdout, "0");
		return;
	}
	else if (n == 1) {
		fprintf(stdout, "1");
		return;
	}
	int* arr = NULL, exp = NULL;
	size_t r = 0, i = 2;
	while (n != 1) {
		while (n % i == 0) {
			n /= i;
			arr = realloc(arr, sizeof(size_t) * (r + 1));
			arr[r] = i;
			fprintf(stdout, "%d ", i);
			++r;
		}
		i++;
	}
	sort(arr, exp, r);
}










/*
	while (n != 1) {
		while (n % i == 0) {
			n /= i;
			fprintf(stdout, "%d", i);
		}
		i++;
		}
*/