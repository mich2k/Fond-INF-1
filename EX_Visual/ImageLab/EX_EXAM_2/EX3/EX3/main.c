#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

size_t conta_parole(const char* s) {
	size_t cont = 0;
	for (int i = 0; *(s + i) != 0; i += 1) {
		if (isalnum(s[i]) != 0)
			++cont;
	}
	return cont;
}

void main(void) {
	char* a = "a b c";
	size_t num = conta_parole(a);
}
