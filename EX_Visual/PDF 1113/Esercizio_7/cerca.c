#include <stdlib.h>

int cerca_primo(const char* s, char c) {
	for (size_t i = 0; *(s + i) != '\0'; i += 1) {
		if (s[i] == c) {
			return 1;
		}
	}
	return -1;
}