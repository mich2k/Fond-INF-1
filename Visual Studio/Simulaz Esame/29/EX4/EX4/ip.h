#ifndef IP_H
#define IP_H
#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
extern uint32_t* leggi_indirizzi_ip(const char* filename, size_t* size);
#endif //IP_H