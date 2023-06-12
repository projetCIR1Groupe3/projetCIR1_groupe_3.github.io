#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJET_END_REQUEST_H
#define PROJET_END_REQUEST_H

int checkIfFileExists(const char * filename);
void ListToTxt(struct List* l);
void requestExe(struct netflux* n);
#endif //PROJET_END_REQUEST_H
