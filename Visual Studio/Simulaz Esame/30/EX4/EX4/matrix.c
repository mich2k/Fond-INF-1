/*
Creare i file matrix.h e matrix.c che consentano di utilizzare la seguente
struttura:

struct matrix {
    size_t rows, cols;
    double *data;
};

e la funzione:

extern struct matrix *mat_scale(const struct matrix *m, double x);

La struct consente di rappresentare matrici di dimensioni arbitraria, dove rows è
il numero di righe, cols è il numero di colonne e data è un puntatore a rows×cols
valori di tipo double memorizzati per righe.  Consideriamo ad esempio la matrice

    ( 1 2 3 )
A = (       )
    ( 4 5 6 )

questo corrisponderebbe ad una variabile struct matrix A, con A.rows = 2, A.cols =
3 e A.data che punta ad un area di memoria contenente i valori {1.0, 2.0, 3.0, 4.0,
5.0, 6.0 }.

La funzione accetta come parametri un puntatore ad una matrice m e un double x e
deve restituire un puntatore a una nuova matrice allocata dinamicamente che
contiene la matrice ottenuta moltiplicando gli elementi della matrice m per lo
scalare x.
Ad esempio:

    ( 1 2 3 )
M = ( 4 5 6 )
    ( 7 8 9 )

                        (  7 14 21 )
mat_scale(M,7.0) ≡ 7⋅M = ( 28 35 42 )
                        ( 49 56 63 )

Se il puntatore passato alla funzione è NULL la funzione ritorna NULL.
*/

#include "matrix.h"

struct matrix* mat_scale(const struct matrix* m, double x) {
    if (m == NULL)
        return NULL;
    struct matrix* r = malloc(sizeof(struct matrix));
    r->rows = m->rows;
    r->cols = m->cols;
    r->data = malloc(r->rows * r->cols * sizeof(double));
    for (size_t ro = 0; ro < m->rows; ++ro) {
        for (size_t c = 0; c < m->cols; ++c) {
            r->data[ro * m->cols + c] = (m->data[ro * m->cols + c])*x;
        }
    }
    return r;
 }
