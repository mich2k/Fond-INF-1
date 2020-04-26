#include "stringhe.h"
void elimina_consecutivi(char* str) {
	if (str == NULL)
		return;
	char* s = malloc(1);
	s[0] = str[0];
	int j = 1;
	for (size_t i = 1; i < strlen(str); ++i) {
		if (str[i - 1] != str[i]) {
			s = realloc(s, j + 1);
			s[j] = str[i];
			j++;
		}
	}
	memset(str, 0, strlen(str));
	memcpy(str, s, j);
	//strncpy(str, s, j);
	free(s);
}