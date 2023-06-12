#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "netflux.h"
#include "List.h"
#include "nodeTrie.h"


//Opération de création

struct Netflux* createNetflux(){
    struct Netflux* netflux = malloc(sizeof(struct Netflux));
    netflux->trie = createEmptyNodeTrie();
    for(int i=0; i<400; i++){
        netflux->lengthSort[i] = createEmptyList();
    }
    netflux->biggest = NULL;

    return netflux;
}

//Opération de suppression

void deleteNetflux(struct Netflux** netflux){
    deleteNodeTrie(&((*netflux)->trie));
    deleteLenghtSort((*netflux)->lengthSort);
    free(*netflux);
    *netflux = NULL;
}

void deleteLenghtSort(struct List** lenghtSort){
    struct List* iterList;
    struct Cell* temp;
    struct Cell* next;
    for(int i = 0;i < 400;i++){
        iterList = lenghtSort[i];
        for(int j = 0;j <iterList->size;j++){
            temp = iterList->head;
            next = iterList->head->next;
            free(temp);
            iterList->head = next;
        }
        free(iterList);
    }
}
