#include <stdlib.h>
int main(void) {
	char s1[] = "";
	char s2[] = "La prima e\' NULL";
	char* s;
	s = concatena(s1, s2);
	free(s);
}