/*Creare i file matrix.h e matrix.c che consentano di utilizzare la seguente struttura :

struct matrix {
    size_t rows, cols;
    double* data;
};

e la funzione :

extern struct matrix* mat_transpose(const struct matrix* mat);

La struct consente di rappresentare matrici di dimensioni arbitraria, dove rows è il numero
di righe, cols è il numero di colonne e data è un puntatore a rows×cols valori di tipo
double memorizzati per righe.Consideriamo ad esempio la matrice

(1 2 3)
A = ()
(4 5 6)

questo corrisponderebbe ad una variabile struct matrix A, con A.rows = 2, A.cols = 3 e
A.data che punta ad un area di memoria contenente i valori{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 }.

Si dice matrice trasposta di A la matrice A ^ T i cui elementi sono definiti come segue :

k    h
b = a
h    k

La matrice A ^ T si ottiene dunque semplicemente considerando come colonne le
righe di A e viceversa.La trasposta della matrice precedente è

T(1 4)
A = (2 5)
(3 6)

La funzione accetta come parametro un puntatore ad una matrice e deve
ritornarne la trasposta, allocata dinamicamente sull’heap.Il puntatore alla
matrice non sarà mai NULL.*/

#include "matrix.h"

struct matrix* mat_transpose(const struct matrix* m) {
    struct matrix* t = malloc(sizeof(struct matrix));
    t->rows = m->cols;
    t->cols = m->rows;
    t->data = calloc(t->rows * t->cols, sizeof(double));
    for (size_t r = 0; r < m->rows; ++r) {
        for (size_t c = 0; c < m->cols; ++c) {
            t->data[c * m->rows + r] = m->data[r * m->rows + c];
        }
    }
    return t;
}








/*
struct matrix* mat_constructor(struct matrix* m, int rows, int cols)
{
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * cols * sizeof(double));
    return m;
} 

struct matrix* mat_transpose(const struct matrix* mat) {
    struct matrix* trasp = mat_constructor(malloc(sizeof(mat)), mat->cols, mat->rows);
    size_t cols = mat->cols;
    size_t rows = mat->rows;
    for (int r = 0; r < rows -1; r++) {
        for (int c = 0; c < cols -1; c++) {
            int x = *(mat->data + (r + c));
        }
    }

}*/