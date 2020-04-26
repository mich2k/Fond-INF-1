#ifndef LIBRI_H
#define LIBRI_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#pragma warning(disable : 4996)

#include <string.h>
#include <stdbool.h>
struct libro {
    char* titolo;
    uint16_t* anni_ristampe;
};

extern bool libro_scrivi(const struct libro* p, FILE* f);

#endif // LIBRI_H