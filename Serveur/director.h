#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "movie.h"
#include "list.h"

struct Director{
    char* name;
    struct List* movieList; // list des films du real, nombre de films : movieList->size
};

//PROJETC_DIRECTOR_H

struct Director* createDirector(char* name);

void deleteDirector(struct Director** d);

void addMovieDirector(struct Director* d, struct Movie* m);



#endif
