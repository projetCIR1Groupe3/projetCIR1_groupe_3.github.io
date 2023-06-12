#include "list.h"
#include "movie.h"


// Opérations de création

struct Cell* createCell(struct Movie* movie){
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->movie = movie;                                               //ici
    cell->next = NULL;
    return cell;
}

struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    l->size = 0;
    l->head = NULL;
    return l;
}

// Opérations d'accès

void addFirst(struct List* l, struct Movie* movie){
    struct Cell* cell = createCell(movie);
    cell->next = l->head;
    l->head = cell;
    l->size++;
}


// Suppression

void deleteFirst(struct List* l) {
    if (isListEmpty(l)) {
        return;
    }
    struct Cell* temp = l->head;
    struct Cell* next = l->head->next;
    deleteMovie(&(temp->movie));
    free(temp);
    l->head = next;
    l->size--;
}


void deleteList(struct List** l){
    if(*l == NULL){
        return ;
    }
    struct Cell* iter = (*l)->head;
    while(!isListEmpty(*l)){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

// Autres opérations

bool isListEmpty(struct List* l){
    return l->size == 0;
}