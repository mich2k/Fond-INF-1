#include <stdlib.h>
void main(void) {
	extern int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n);
	/*Lo stipendio da 0 a 15000 euro e' tassato al 23%
		Lo stipendio da 15000 a 28000 euro e' tassato al 27%
		Lo stipendio da 28000 a 55000 euro e' tassato al 38%
		Lo stipendio da 55000 a 75000 euro e' tassato al 41%
		Lo stipendio oltre 75000 euro e' tassato al 43%*/
		unsigned int scaglioni[5] = { 0,15000,28000,55000,75000 };
		unsigned int aliquote[5] = { 23,27,38,41,43 };
		irpef(25500, scaglioni, aliquote, 5);

}