#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef _NETFLUX_H
#define _NETFLUX_H

#include "list.h"
#include "nodeTrie.h"

struct Netflux {
    struct NodeTrie* trie;
    struct List* lengthSort[400]; //tableau de list de film
    struct Director* biggest;
};

//Opération de création

struct Netflux* createNetflux();

//Opération de suppression

void deleteNetflux(struct Netflux** netflux);
void deleteLenghtSort(struct List** lenghtSort);



#endif //CFILES_NETFLUX_H
