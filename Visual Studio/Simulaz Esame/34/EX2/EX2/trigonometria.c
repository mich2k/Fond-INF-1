#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

extern double seno_iperbolico(double x);

double factorial(double n) {
    return ((n == 1 || n == 0) ? 1 : factorial(n - 1) * n);
}

double pot(double x, unsigned short exp) {
    if (exp == 1)
        return x;
    if (exp == 0)
        return 1;
    double val = x;
    for (; exp > 1; --exp)
        x *= val;
    return x;
}

double seno_iperbolico(double x) {
    double ris = 0, tmp = 0, nom, den;
    for (unsigned long long int n = 0;;++n) {
        if (n != 0)
            tmp = ris;
        den = factorial(2 * n + 1);
        nom = pot(x, 2 * n + 1);
        ris += (1 / den) * nom;
        if (tmp == ris)
            return ris;
    }
}


/*
Nel file trigonometria.c implementare in linguaggio C la funzione
corrispondente alla seguente dichiarazione:

extern double seno_iperbolico(double x);

La funzione deve calcolare il valore di sinh(x) utilizzando il seguente
sviluppo in serie di Taylor:

          inf
           __     1
sinh(x) = \   --------- x^(2n+1)
          /__  (2n+1)!
          n=0

Il ciclo (teoricamente infinito) deve continuare finché il risultato non cambia più.
Nel realizzare la funzione non è consentito l’uso di librerie esterne.
*/