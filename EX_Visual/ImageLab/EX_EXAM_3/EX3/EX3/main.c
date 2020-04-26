
/*
La funzione leggidouble() riceve in input il nome di un file come stringa C e
deve: aprire il file in lettura in modalità tradotta (testo), leggere i numeri in
variabili di tipo double allocando dinamicamente la memoria, impostare size al
numero di numeri trovati nel file, e ritornare un puntatore alla memoria
allocata. Se l’apertura fallisce o se non è possibile leggere nemmeno un numero,
ritornare NULL. Ricordarsi comunque di chiudere il file se l’apertura è andata a
buon fine.
*/

#include "lettura.h"

void main(void) {
	size_t size;
	leggidouble("C:\\Users\\Michele\\Desktop\\Fond. INF 1\\Visual Studio\\ImageLab\\EX_EXAM_3\\EX3\\datas\\dati1.txt", &size);
}
