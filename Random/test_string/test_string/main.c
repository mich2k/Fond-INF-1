#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "bella ciao bella ciao";
    char* dest = calloc(110,1);

    printf("Before memmove dest = %s, src = %s\n", dest, src);
    memmove(dest, src, 10);
    printf("After memmove dest = %s, src = %s\n", dest, src);

    return(0);
}