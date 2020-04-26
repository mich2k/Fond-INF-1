#ifndef TIROCINI_H
#define TIROCINI_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct tirocinio {
    char* nome;
    char* azienda1;
    char* azienda2;
    char* azienda3;
};
extern bool tirocinio_load(FILE* f, struct tirocinio* t);

#endif // TIROCINI_H