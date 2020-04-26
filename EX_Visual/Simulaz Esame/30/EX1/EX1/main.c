#include <stdlib.h>
extern int* rotate(const int* vec, size_t len, size_t r);

void main(void) {
	int arr[4] = { 1,2,3,4 };
	rotate(arr, 4, 6);
}