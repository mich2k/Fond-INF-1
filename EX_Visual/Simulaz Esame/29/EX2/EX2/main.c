#include "libri.h"
void main(void) {
	char tit[] = "Geometria";
	uint16_t anni[3] = { 2001,2002,0 };
	struct libro x = { tit, anni };
	/* ... */
	FILE* f = fopen("test.bin", "wb");
	libro_scrivi(&x, f);
	//fclose(in);
	//fclose(out);	//FILE* f = fopen(stdout, "wb");
	fclose(f);
}