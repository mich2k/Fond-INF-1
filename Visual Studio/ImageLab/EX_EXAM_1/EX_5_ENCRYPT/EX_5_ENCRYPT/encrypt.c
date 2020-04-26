#include <stdlib.h>

extern void encrypt(char* s, unsigned int n) {
	for (;n>0; n-=1)
		s[n] ^= 0xaa;
}
