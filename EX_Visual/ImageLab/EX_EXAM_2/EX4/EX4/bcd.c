#include <stdlib.h>

typedef unsigned short ush;

ush digit_to_bin(ush n){
	ush ris = 0, i=1;
	for (; n != 0; i*=10) {
		ris += (n % 2)*i;
		n /= 2;
	}
	return ris;
}

ush len(int n) {
	ush count=0;
	for (; n > 0; n /= 10)
		count++;
	return count;
}

extern unsigned short bin2bcd(unsigned short val) {
	//passare le cifre al contrario
	ush tot = 0, i = 1;
	for (; val > 0; val /= 10) {
		ush temp = digit_to_bin(val % 10);
	}
	return tot;
 }
