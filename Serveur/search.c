#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "search.h"

struct List* searchByDirector(struct Netflux* N, char* name){
    unsigned int n = strlen(name);
    struct NodeTrie* iter = N->trie;
    name = toLowerCase(name);
    for(int i = 0;i < n;i++){
        if(name[i] == '-'){ //cas pour char spéciaux
            iter = iter->next[26];
        }
        else{
            if(name[i] == '\''){
                iter = iter->next[27];
            }
            else{
                iter = iter->next[(int)(name[i]-'a')]; // décalage ascii pour index dans le trie
            }
        }
        if(iter == NULL){
            return NULL; //le réal cherché n'existe pas, donc on return rien
        }
    }
    return iter->director->movieList;
}

struct Director* getBiggestDirector(struct Netflux* N){
    return N->biggest;
}

struct List* searchByLenght(struct Netflux* N, unsigned int lenght){
    return N->lengthSort[lenght];
}

