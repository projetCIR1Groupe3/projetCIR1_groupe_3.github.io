#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJET_END_REQUEST_H
#define PROJET_END_REQUEST_H

#include "search.h"

int checkIfFileExists(const char * filename);
void ListToTxt(struct List* l);
void requestExe(struct Netflux* n);
#endif //PROJET_END_REQUEST_H
