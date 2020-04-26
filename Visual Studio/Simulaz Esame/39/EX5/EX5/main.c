#include "tirocini.h"

void main(void) {
    struct tirocinio x;
    FILE* f = fopen("C:\\Users\\Michele\\Desktop\\Fond. INF 1\\Visual Studio\\Simulaz Esame\\39\\EX5\\Debug\\input2.txt", "r");
    while (tirocinio_load(f, &x) != false);
}