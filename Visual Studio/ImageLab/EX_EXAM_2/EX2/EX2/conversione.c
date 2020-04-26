#include <stdlib.h>

typedef unsigned int uint;

size_t lenght(uint x) {
	size_t len = 0;
	for (; x > 0; x /= 10)
		++len;
	return len;
}

void spec(char* x, int n) {
	char* y=calloc(n+1, sizeof(char));
	if (y) {
		for (int i = 0; i < n; i++)
			y[i] = x[i];
		for (int i = 0; i < n; ++i)
			x[i] = y[n -2 - i]; // -1 considerando partenza da 0, -1 per evitare lo '\0'
		x[n-1] = '\0';
		free(y);
	}
	}

 char* converti(unsigned int n) {
	int i;
	char* digit = calloc(lenght(n)+1, sizeof(char));
	if (digit) {
		for (i = 0; n > 0; i++) {
			digit[i] = n % 10;
			n /= 10;
			if (!(n>0))
				digit[i + 1] = '\0';
		}
		spec(digit, 1+i);
 		for (int j = 0; digit[j] != '\0'; ++j) {
			digit[j] = '0' + digit[j];
			/* Other ways to convert */
			// digit[j]= itoa(z,...);
			// sprintf(digit[i], "%d", z);
		}
		return digit;
	}
	else
		return NULL;
}

 /*
 sprintf
Write formatted data to string (function )
atoi
Convert string to integer (function )
atol
Convert string to long integer (function )
*/