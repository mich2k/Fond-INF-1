#include <stdlib.h>
#include <stdio.h> // Libreria necessaria per i file
#include <stdbool.h>

extern bool scrivi_intero(const char* filename, int i) {
	FILE* _file = fopen(filename, "wb");
	if (_file == NULL || !_file)
		return false; // Controllo che l'apertura sia riuscita
	fprintf(_file, "%i", i);
	fclose(_file); // chiudo file
	return true;
}



/*

"r" Apre il file in lettura in modalità tradotta (testo). Il file deve
esistere.

"w" Apre il file in scrittura in modalità tradotta (testo). Se il file non
esiste, viene creato un file vuoto con il nome specificato,
altrimenti esso viene sovrascritto da quello nuovo vuoto.

"a" Apre il file in append in modalità tradotta (testo), cioè in
scrittura posizionandosi alla fine del file. Se il file non esiste
allora viene creato.

"rb" Apre il file in lettura in modalità non tradotta (binaria).

"wb" Apre il file in scrittura in modalità non tradotta (binaria).

"ab" Apre il file in append in modalità non tradotta (binaria).

*/

/*
MODALITA R/W:

"r+"/"r+b" Apre il file per lettura/scrittura. Il file deve esistere.

"w+"/"w+b" Apre il file per lettura/scrittura. Se il file non esiste, viene creato un file vuoto
con il nome specificato, altrimenti esso viene sovrascritto da quello nuovo
vuoto.

"a+"/"a+b" Apre il file per lettura/scrittura posizionandosi alla fine del file. Se il file non
esiste allora viene creato.

*/