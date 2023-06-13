#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "netflux.h"
#include "list.h"
#include "nodeTrie.h"


//Opération de création

struct Netflux* createNetflux(){
    struct Netflux* netflux = malloc(sizeof(struct Netflux));
    netflux->trie = createEmptyNodeTrie();
    for(int i=0; i<400; i++){ //on crée des lits pour chaque enplacement du tableau
        netflux->lengthSort[i] = createEmptyList();
    }
    netflux->biggest = NULL; //init à null 

    return netflux;
}

//Opération de suppression

void deleteNetflux(struct Netflux** netflux){
    //on delete le trie puis le tableau avant de supprimer l'ensemble
    deleteNodeTrie(&((*netflux)->trie)); 
    deleteLenghtSort((*netflux)->lengthSort);
    free(*netflux);
    *netflux = NULL;
}

void deleteLenghtSort(struct List** lenghtSort){
    //c'est un delete list, mais on ne supprime pas le film car il a déjà été supprimer dans le deleteNodetrie
    struct List* iterList;
    struct Cell* temp;
    struct Cell* next;
    for(int i = 0;i < 400;i++){ //on le fait pour chaque 400 case du tableau 
        //on supprime simplement les "support" de la liste chainées
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
