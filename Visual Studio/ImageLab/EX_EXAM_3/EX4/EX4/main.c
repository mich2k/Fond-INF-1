/*
Creare i file scrittura.h e scrittura.c che consentano di utilizzare la seguente funzione:

extern int scrivimaiuscolo(const char *filename);

La funzione riceve in input il nome di un file come stringa C e deve: aprire il file in
lettura in modalità tradotta (testo), se l’apertura fallisce ritornare 0, altrimenti
leggere tutti i caratteri dal file e scriverli su stdout convertendoli in maiuscolo se
sono lettere minuscole, infine ritornare 1. Ricordarsi di chiudere il file se l’apertura
è andata a buon fine.

*/

#include "scrittura.h"
#pragma warning(disable:4996)

void main(void) {

	scrivimaiuscolo("C:\\Users\\Michele\\Desktop\\Fond. INF 1\\Visual Studio\\ImageLab\\EX_EXAM_3\\EX4\\file03.txt");
}