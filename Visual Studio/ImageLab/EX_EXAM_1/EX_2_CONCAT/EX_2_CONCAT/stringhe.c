#include <stdlib.h>

size_t lenght(const char* str) {
	size_t cont;
	if (str == NULL || str[0] == '\0')
		return 0;
	for (cont = 0; *(str + cont) != '\0'; cont += 1) {
	}
	return cont;
}

extern char* concatena(const char* prima, const char* seconda) {
	int l_prima = lenght(prima), l_seconda = lenght(seconda);
	int tot_lenght = l_prima + l_seconda;
	int i = 0, j = 0;
	char* str = calloc((tot_lenght + 1), (sizeof(char)));
	if (str) {
		for (; lenght(str) != tot_lenght; ++i) {
			if (lenght(str) >= lenght(prima)) {
				str[i] = seconda[j];
				++j;
			}
			else
				str[i] = prima[i];
		}
		return str;
	}
}
/*if (str) {
		do {
			if (i == 0) {
				for (; *(prima + j) != '\0'; j += 1) {
					if (l_prima == 0)
						break;
					*(str + j) = *(prima + j);
				}
			}
			if (l_seconda == 0)
				break;
			str[j] = seconda[i];
			++j;
			++i;
		} while (*(seconda + i) != '\0');
		return str;
	}*/