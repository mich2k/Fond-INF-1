#include <stdlib.h>

/*unsigned int conta_spazi(const char* s) {
	size_t cont = 0;
	for (size_t i = 0; *(s + i) != '\0'; i += 1) { 
		int x = s[i];
		if(x == 32)  //if (s[i] == ' ') <--- better way
			++cont;
	}
	return cont;
}*/

void main(void)
{
	char stringa[20] = { "c i a o !" };
	conta_spazi(stringa);
}