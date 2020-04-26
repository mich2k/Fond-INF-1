#include "string_split.h"
void main(void) {
	char **s1 = malloc(8);
	char **s2 = malloc(8);
	string_split("Alfabetizzazione", 60, s1, s2);
	free(s1[0]);
	free(s2[0]);
	free(s1);
	free(s2);
	return;
}