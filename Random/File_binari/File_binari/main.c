#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*  +++ ANNOTAZIONI +++

- NON E POSSIBILE RIDEFINIRE UNO STREAM PIU VOLTE E 
	DIFFERENTEMENTE IN UN UNICO FILE

- IL PUTC NON SERVE A NULLA, RISPETTO AL FPRINTF
	(MOLTO PROBABILMENTE STESSO PER FGETS E FSCANF

- IN CASO SI VOGLIA SCRIVERE UN ARRAY ATTRAVERSO UN
	FWRITE NON E NECESSARIO UN CICLO                     xx WATCH  OUT xx

- Quando una lettura ritorna un valore diverso dal numero di elementi che
	si volevano leggere bisogna controllare lo stato del file attraverso le
	funzioni feof() e ferror().

- USARE if( feof ( _f_stream ) ) OPPURE if ( feof (fstream) != 0 )

- DENY: WHILE(FEOF(f));

- E POSSIBILE RICHIAMARE LO STESSO FILE IN r, w SENZA USARE LETTURA E SCRITTURA
	SEMPLICEMENTE CAMBIANDO IL NOME DELLO STREAM E RICORDARSI
	DI CAMBIARE IL FORMAT

- RICORDARSI CHE IL FORMAT w SOVRASCRIVE IN MODO DISTRUTTIVO

- 

*/


int main(void) {
/*
	/*size_t i;
	int* _arr = calloc(n, sizeof(int));
	if (_arr) {
	for (i = 0; i < 5; i++)
		*(_arr + i) = i;*/

		/*FILE* bin = fopen("bin.txt", "w");
		for (i = 0; i < 5; i++)
			fprintf(bin,"\t%i\n",*(_arr + i) + 1);
		fprintf(bin, "\n\n\n");
		fclose(bin);*/

		/*FILE* bin = fopen("bin.txt", "w");
		for (i = 0; i < 5; i++)
			fprintf(bin, "\t%i\n", *(_arr + i) + 1);
		
		fprintf(bin, "ciao_ printf\n");
		char* s = "ciao_puntatore char printf\n";
		char* s_put = "ciao_puntatore char putc\n";
		fprintf(bin, "%s", s);
		fputs(s_put, bin);
		fclose(bin);*/
	// fwrite
	/*size_t n, ret = 0, i;
	FILE* bin = fopen("_binario.bin", "wb");
	if (bin == NULL)
		return -1;
	char* a = "ciao ciao ciao ciao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaociao ciao ciaoW";
	for (n = 0; a[n] != '\0'; n++);
	ret = fwrite(a, sizeof(char), n, bin);
	fprintf(bin, "\n %i", ret);
	if (ret != n)
		return -1;
	fclose(bin);
	return 0;*/

	// fread
	size_t n, ret = 0;
	FILE* bin = fopen("_binario.bin", "wb");
	if (bin == NULL)
		return -1;
	char* a = " Prima stampa dell fwrite che verrà letta e stampata dal buffer dell fread.";
	for (n = 0; a[n] != '\0'; n++);
	ret = fwrite(a, sizeof(char), n, bin);
	fprintf(bin, "\n Ritorno scritto fwrite: %i \n", ret);
	if (ret != n)
		return -1; // END FWRITE
	fclose(bin);

	// FREAD
	FILE* r_bin = fopen("_binario.bin", "rb");
	char* _buff = calloc(n, 1);
	if (_buff) {
		size_t reads = fread(_buff, sizeof(char), n, r_bin);
		if(reads != n)
			if (feof(r_bin) != 0 || ferror(r_bin))
				fclose(r_bin);
		fclose(r_bin);

	// FWRITE DI CIO APPENA LETTO PRECEDENTEMENTE
	FILE* bin = fopen("_binario.bin", "ab");  // N.B. MODALITA APPEND BINARY
	fprintf(bin, "\n\n Ritorno scritto fread: %i \n", reads);
	fprintf(bin, "\n Inizio fase stampa dal buffer...\n ");
	ret = fwrite(_buff, 1, n, bin);
	if (ret != n)
		return -1;
	fprintf(bin, "\n\n Ritorno scritto fwrite: %i \n", ret);
	fclose(bin);

		//fprintf(bin, "\n %i", reads);
		//fwrite(reads, sizeof(size_t), 1, bin);
	}
	fclose(bin);
	return 0;
	} 
/*
FILE* bin = fopen("bin.txt", "ab");
fwrite(_arr, sizeof(int), n, bin);
fclose(bin);


*/