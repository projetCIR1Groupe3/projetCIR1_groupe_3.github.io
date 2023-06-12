#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "Netflux.h"
#include "List.h"
#include "nodeTrie.h"

//Opération de création

struct Netflux* createNetflux(){
    struct Netflux* netflux = malloc(sizeof(struct Netflux));
    netflux->$ = createEmptyNodeTrie();
    for(int i=0; i<400; i++){
        netflux->lengthSort[i] = createEmptyList();
    }
    netflux->biggest = NULL;
    return netflux;
}

//Opération de suppression

void deleteNetflux(struct Netflux** netflux){
    deleteNodeTrie(&((*netflux)->$));
    for(int i=0; i<400; i++){
        deleteList(&((*netflux)->lengthSort[i]));
    }
    free(*netflux);
    *netflux = NULL;
}