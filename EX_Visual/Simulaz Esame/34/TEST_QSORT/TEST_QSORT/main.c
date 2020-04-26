#include <stdlib.h>
#pragma warning (disable : 6011)


int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}


void main(void) {
    unsigned int* arr = NULL;
    unsigned int i = 0;
    for (;; i++) {
        arr = realloc(arr, sizeof(unsigned int) * (i + 1));
        arr[i] = rand();
        qsort(arr, i, sizeof(unsigned int), compare_ints);
    }
    return;
}