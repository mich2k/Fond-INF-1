#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

short int main(void) {
	// test, scrittura tra binaria e non

	FILE* f = fopen("tradotta.txt", "w");
	FILE* fb = fopen("binaria.bin", "wb");
	int a = 1,  b = 3;
	fprintf(f, "La somma tra %i e %i sara\'\n\t:%i\n", a, b, a+b);
	fprintf(fb, "La somma tra %i e %i sara\'\n\t:%i\n", a, b, a+b);
	//fwrite(a + b, 4, 1, fb);
	fclose(f);
	fclose(fb);
	/*
	APRENDO CON UN EDITOR HEX
	E VISIBILE DI COME L A CAPO NELLA MODALITA TRADOTTA SIA
	0D 0A ( 13 10 ) \r\n
	MENTRE NELLA BINARIA SOLO
	0A (10) \n
	*/
	return 0;
}