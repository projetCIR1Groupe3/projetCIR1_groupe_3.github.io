#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "movie.h"


struct Movie* createMovie(unsigned int length, char* title, char* genre, char* directorName){

    struct Movie* m = malloc(sizeof(struct Movie));

    if(m == NULL) {
        printf("ERROR MALLOC");
        return m;
    }

    m->directorName = malloc((strlen(directorName)+1)*sizeof(char));
    if(m->directorName != NULL){
        strcpy(m->directorName,directorName);
    }
    m->genre = malloc((strlen(genre)+1)*sizeof(char));
    if(m->genre != NULL){
        strcpy(m->genre,genre);
    }

    m->title = malloc((strlen(title)+1)*sizeof(char));
    if(m->title != NULL){
        strcpy(m->title,title);
    }
    m->length = length;

    return m;

}

char* getTitle(struct Movie* m){
    return m->title;
}

char* getGenre(struct Movie* m){
    return m->genre;
}

unsigned int getLength(struct Movie* m){
    return m->length;
}

char* getDirectorName(struct Movie* m){
    return m->directorName;
}

void deleteMovie(struct Movie** m){

    free((*m)->directorName);
    free((*m)->genre);
    free((*m)->title);

    free(*m);
    (*m)=NULL;

}


