#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
extern void ex_print(char* i_mieiex) {
	for (size_t i = 0; *(i_mieiex + i) != '\0'; i += 1) {
		if (i == 0)
			printf(" ");
		printf("%c", *(i_mieiex + i));
		Sleep(1000);
		printf("\a");
	}
	printf("\n\n");
}