#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#define M_PI acos(-1.0)
/*
double volume_cono(double r, double h) {
	if ( r < 0 || h <0 )
		return 0;
	double volume = (M_PI * r * r * h) / 3;
	return volume;
}

int ciao(void) {
	printf("\n Errico coglione");
	return 1;
}

void main(void) {
	system("color f0");
	double x = volume_cono(3,2);
	int somma = ciao();
	ciao();
	ciao();
	_kbhit();
}*/
/*
void main(void) {

	/*printf("\n %d ", sizeof(char));
	_getch();
	_getch();

	int r[20] = { 0 };
	int a[10]; // allocazione AUTOMATICA
	//   a[1]  == *(a+1)
	int* b = malloc(10 * sizeof(int)); // allocazione DINAMICA

	free(b);
	int s;

	for (int i = 0; i < 10; i += 1) {
		a[i] = i;
		s = a[i] * 2; // s=a[9]*2;
	}
	b[0] = 2;
int* _arr = calloc(10, sizeof(int));
}*/



void main(void) {
	int x;
	x = 5;
	printf("\n %d", x);
	printf("\n %d", &x);
}







// INCLUDE GUARD
#ifndef SOMMA_H // #if !defined SOMMA_H
#define SOMMA_H
extern int somma_s(int, int);
#endif // SOMMA_H