#ifndef _CREATEFILMOTHEQUE_H_
#define _CREATEFILMOTHEQUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "netflux.h"

struct Netflux* createFilmotheque();

struct Movie* recupMovie(char* str);

char* toLowerCase(char* word);

void compareBiggestProd(struct Netflux* N, struct Director* d);



#endif
