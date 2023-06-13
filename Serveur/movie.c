#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "movie.h"


struct Movie* createMovie(unsigned int length, char* title, char* genre, char* directorName){

    struct Movie* m = malloc(sizeof(struct Movie));

    if(m == NULL) {             //on verifie que le malloc a bien fonctionné
        printf("ERROR MALLOC");
        return m;
    }

    m->directorName = malloc((strlen(directorName)+1)*sizeof(char));
    if(m->directorName != NULL){
        strcpy(m->directorName,directorName);       //on copie le nom du realisateur dans la structure
    }
    m->genre = malloc((strlen(genre)+1)*sizeof(char));
    if(m->genre != NULL){
        strcpy(m->genre,genre);     //on copie le genre dans la structure
    }

    m->title = malloc((strlen(title)+1)*sizeof(char));
    if(m->title != NULL){
        strcpy(m->title,title);         //on copie le titre dans la structure
    }
    m->length = length;             //on copie la duree dans la structure

    return m;

}

char* getTitle(struct Movie* m){        //on recupere le titre du film
    return m->title;
}

char* getGenre(struct Movie* m){        //on recupere le genre du film
    return m->genre;
}

unsigned int getLength(struct Movie* m){        //on recupere la duree du film
    return m->length;
}

char* getDirectorName(struct Movie* m){     //on recupere le nom du realisateur du film
    return m->directorName;
}

void deleteMovie(struct Movie** m){         //on supprime le film
    //on supprime les éléments un par un
    free((*m)->directorName);
    free((*m)->genre);
    free((*m)->title);

    free(*m);
    (*m)=NULL;

}


