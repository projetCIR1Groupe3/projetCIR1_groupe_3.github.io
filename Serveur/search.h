#ifndef _SEARCH_H_
#define _SEARCH_H_

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "createFilmotheque.h"

struct List* searchByDirector(struct Netflux* N, char* name);

struct Director* getBiggestDirector(struct Netflux* N);

struct List* searchByLenght(struct Netflux* N, unsigned int lenght);

#endif