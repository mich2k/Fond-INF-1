#include <stdlib.h>


void main(void) {
	size_t n = 4;
	//char* seq = calloc(n, sizeof(char));
	char* seq = malloc(2*sizeof(char));
	seq[0] = 'c';
	seq[1] = 'i';
	seq[2] = 'a';
	seq[3] = 'o';
	encrypt(seq, n);
	char a = 'a';
	char b = a ^ 0xaa;
	char c = b ^ 0xaa;
}