/*#include <stdlib.h>
#include <stdio.h>

float somma (coords);

typedef struct _coordinate {
	float x;
	float y;
} coords;

float somma(coords punto) {
	return punto.x + punto.y;
}

void main(void) {
	coords primo = { .x = 10.0, .y = 15 };
	printf("%f",somma(primo));
}*/










#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#define _max 20

typedef struct _humancreed {
	char gender[20];
	size_t color;
	char _sex[20];
}creed;

enum _color {
	white,
	black
};

void main(void) {
	struct _humancreed man;
	printf("\n Enter your Gender, White/Black, Gender: ");
	scanf_s("%s%u%s", &(man.gender), &(man.color), &(man._sex));
	printf("So you are a");
	if (man.color == white)
		printf(" white ");
	else
		printf(" black ");
	printf("%s, %s !", man.gender, man._sex);

}