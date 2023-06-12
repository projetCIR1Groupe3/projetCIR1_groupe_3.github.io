#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#include "director.h"


struct Director* createDirector(char* name){

    struct Director* d = malloc(sizeof(struct Director));

    if(d == NULL){
        printf("ERROR MALLOC");
        return d;
    }

    d->name = malloc((strlen(name)+1)*sizeof(char));
    if(d->name != NULL){
        strcpy(d->name,name);
    }

    d->movieList = createEmptyList();

    return d;

}

void deleteDirector(struct Director** d){
    if(*d == NULL){
        return ;
    }
    struct Director* d1 = *d;
    deleteList(&(d1->movieList));
    free(d1->name);

    free(d1);
    d1=NULL;
}

void addMovieDirector(struct Director* d, struct Movie* m){
    addFirst(d->movieList,m);
}

