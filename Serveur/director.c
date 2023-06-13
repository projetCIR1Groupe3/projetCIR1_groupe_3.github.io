#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#include "director.h"


struct Director* createDirector(char* name){

    struct Director* d = malloc(sizeof(struct Director));           //on alloue la mémoire pour le directeur

    if(d == NULL){                //on vérifie que le malloc a bien fonctionné
        printf("ERROR MALLOC");
        return d;
    }

    d->name = malloc((strlen(name)+1)*sizeof(char));        //on alloue la mémoire pour le nom du directeur
    if(d->name != NULL){
        strcpy(d->name,name);                    //on copie le nom du directeur
    }

    d->movieList = createEmptyList();               //on crée une liste de films vide

    return d;

}

void deleteDirector(struct Director** d){           //on fait une fonction qui supprime un directeur
    if(*d == NULL){
        return ;
    }
    struct Director* d1 = *d;
    deleteList(&(d1->movieList));           //on supprime la liste de films du directeur
    free(d1->name);                         //on supprime le nom du directeur

    free(d1);                               //on supprime le directeur
    d1=NULL;
}

void addMovieDirector(struct Director* d, struct Movie* m){
    addFirst(d->movieList,m);           //on ajoute un film à la liste de films du directeur
}

