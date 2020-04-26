#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool cifre_duplicate(unsigned long long n) {
	uint32_t i = 0;
	unsigned long long _n = n;
	for (i = 0; _n > 0; _n /= 10) // calcolo digit
		++i;
	if (i == 1)
		return false;
	int* arr = malloc(i * sizeof(int));
	int* found = malloc(10*sizeof(int));
	for (int r = 0; r < 10; r++)
		found[r] = -1;
	for (uint32_t j = i; n > 0; n /= 10, j--) { // sort
		if ((j - 1) >= 0)
			arr[j - 1] = n % 10;
	}
	for (uint32_t j = 0; i > j; j++) {
		if (found[arr[j]] != false)
			found[arr[j]] = false;
		else {
			free(arr);
			free(found);
			return true;
		}
	}
	free(arr);
	free(found);
	return false;
}

void main(void) {
	bool x = cifre_duplicate(1234567890);
}