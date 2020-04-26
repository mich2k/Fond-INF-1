//#include "stat.h"

typedef unsigned int uint;

double _pow(double x, uint y) {
	double pot = x;
	for (uint i = 1; i < y; i += 1)
		pot *= x;
	return pot;
}

double media(double* x, uint n) {
	if (n == 0)
		return 0;
	double tot = 0;
	for (uint i = 0; i < n; i += 1)
		tot += *(x + i);
	return tot / n;
}

double varianza(double* x, double avg, uint n)
{
	if (n < 2)
		return 0;
	double sum = 0;
	for (uint i = 0; i < n; i += 1) {
		double num = *(x + i);
		double valore = num - avg;
		sum += _pow(valore, 2);
	}
	return (sum/(double)(n-1)); //evitare espressioni articolate nei return statement, o essere rigorosi con le priorità (parentesi etc..)
}
