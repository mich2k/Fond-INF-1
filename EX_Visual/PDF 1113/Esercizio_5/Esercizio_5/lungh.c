#include <stdlib.h>
#include <string.h>

extern size_t lungh(const char* str) {
	size_t j;
	for ( j = 0; *(str + j) != '\0'; ++j)
		++j;
	return j;
	//return strlen(str);
}