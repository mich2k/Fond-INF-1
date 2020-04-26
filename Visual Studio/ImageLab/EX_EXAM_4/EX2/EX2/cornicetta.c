#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void stampa_cornicetta(const char*);

void stampa_cornicetta(const char* s) {
	size_t val = strlen(s) + 4, i = 1, x = 1, cont = 0;
	for (; x <= 3; ++x) {
		i = 1;
		for (; i <= val; ++i) {
				switch (x) {
				case 1:
					if (i == 1)
						fprintf(stdout, "/");
					else {
						if (i == val)
							fprintf(stdout, "\\");
						else
							fprintf(stdout, "-");
					}
					break;
				case 2:
					if ( i == 1 )
						fprintf(stdout, "|");
					else {
						if (i == val)
							fprintf(stdout, "|");
						else {
							if (i == 2 || i == (val - 1))
								fprintf(stdout, " ");
							else {
								fprintf(stdout, "%c", *(s + cont));
								++cont;
							}
						}
					}
					break;
				case 3:
					if (i == 1)
						fprintf(stdout, "\\");
					else {
						if (i == val)
							fprintf(stdout, "/");
						else
							fprintf(stdout, "-");
					}
					break;
				default:
					exit(-1);
				}
			}
		fprintf(stdout, "\n");
		}
}