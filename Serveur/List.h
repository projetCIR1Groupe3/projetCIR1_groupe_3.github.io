#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Cell {
    struct Movie* movie;
    struct Cell* next;
};

struct List {
    struct Cell* head;
    unsigned int size;
};

// Opérations de création

struct Cell* createCell(struct Movie* movie);
struct List* createEmptyList();

// Opérations d'accès

void addFirst(struct List* l, struct Movie* movie);

// Suppression

void deleteFirst(struct List* l);
void deleteList(struct List** l);

// Autres opérations

bool isListEmpty(struct List* l);


#endif //PROJET_END_LIST_H
