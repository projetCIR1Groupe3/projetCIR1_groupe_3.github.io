#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef CFILES_NETFLUX_H
#define CFILES_NETFLUX_H

struct Netflux {
    struct NodeTrie* $;
    struct List* lengthSort[400]; //tableau de list de film
    struct director* biggest;
};

//Opération de création

struct Netflux* createNetflux();

//Opération de suppression

void deleteNetflux(struct Netflux** netflux);



#endif //CFILES_NETFLUX_H
