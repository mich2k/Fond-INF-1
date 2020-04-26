/*
L’Imposta sui Redditi delle Persone Fisiche (IRPEF) viene calcolata come
percentuale dello stipendio (lordo), suddivisa a scaglioni:
•	la parte da 0 fino a 15000 euro è tassata al 23%,
•	la parte oltre i 15000 e fino a 28000 è tassata al 27%,
•	la parte oltre i 28000 e fino a 55000 è tassata al 38%,
•	la parte oltre i 55000 e fino a 75000 è tassata al 41%,
•	la parte oltre i 75000 è tassata al 43%.

Se lo stipendio è di 25000 euro, i primi 15000 sono tassati al 23%, la parte da
15001 a 25000 è tassata al 27%. In totale si calcola 15000*23/100 +
(25000-15000)*27/100 = 6150.

Se lo stipendio è di 35000 euro, i primi 15000 sono tassati al 23%, la parte da
15001 a 28000 è tassata al 27%, la parte da 28001 a 35000 è tassata al 38%. In
totale si calcola 15000*23/100 + (28000-15000)*27/100 + (35000-28000)*38/100 =
9620.

Nel file tasse.c implementare la definizione della seguente funzione:

extern unsigned int irpef(	unsigned int stipendio, unsigned int *scaglioni,
unsigned int *aliquote, size_t n);

Nel vettore scaglioni sono presenti le n soglie a partire da 0, nel vettore
aliquota sono presenti le n percentuali. Nel caso illustrato (quello delle tasse
italiane ad oggi) scaglioni punta a { 0, 15000, 28000, 55000, 75000 }, aliquote
punta a { 23, 27, 38, 41, 43 }. La funzione deve calcolare le tasse secondo il
procedimento illustrato per qualsiasi valore di stipendio e per qualsiasi coppia
di vettori scaglioni e aliquote.
*/

#include <stdlib.h>

int percent(int valore, int modulo) {
	return (valore * modulo) / 100;
}

extern unsigned int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n) {
	int tasse_tot = 0, valore;
	//int* tasse = calloc(n, sizeof(int));
	for (size_t i = 0; i < n; i += 1) {
		if (stipendio < scaglioni[1] || stipendio > scaglioni[n]) {
			tasse_tot += percent(stipendio, aliquote[i]);
			return tasse_tot;
		}
		else {
			if (i == 0)
				valore = scaglioni[1];
			else
				valore = scaglioni[i] - scaglioni[i - 1];
			tasse_tot += percent(valore, aliquote[i]);
		}

	}
}


/*
#include <stdlib.h>

int percent(int valore, int modulo) {
	return valore * modulo / 100;
}

extern unsigned int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n) {
	int tasse_tot = 0;
	int* tasse = calloc(n, sizeof(int));
	for (int i = 0; i < n; i += 1) {
		if (i == 0)
			tasse[i] = percent((scaglioni[i]), aliquote[i]);
		else
			tasse[i] = percent((scaglioni[i] - scaglioni[i - 1]), aliquote[i]);
		tasse_tot += tasse[i]
	}
	return tasse_tot;
}
*/