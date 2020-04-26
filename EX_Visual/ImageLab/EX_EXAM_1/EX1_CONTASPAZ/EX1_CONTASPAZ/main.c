#include <stdlib.h>

unsigned int conta_spazi(const char* s) {
	size_t cont = 0;
	for (size_t i = 0; *(s + i) != '\0'; i += 1) {
		//int x = s[i]; <- altern.
		if (s[i] == ' ') //if (x == 32) <--- alternativa
			++cont;
	}
	return cont;
}

void main(void) {
	conta_spazi("o k");
}