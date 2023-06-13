#include "list.h"
#include "movie.h"


// Opérations de création

struct Cell* createCell(struct Movie* movie){
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->movie = movie;        // On copie l'adresse du film
    cell->next = NULL;          // On initialise le pointeur suivant à NULL
    return cell;
}

struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    l->size = 0;        // On initialise la taille à 0
    l->head = NULL;     // On initialise le head à NULL
    return l;
}

// Opérations d'accès

void addFirst(struct List* l, struct Movie* movie){
    struct Cell* cell = createCell(movie);
    cell->next = l->head;       // On fait pointer le nouveau cellule vers l'ancien head
    l->head = cell;             // On fait pointer le head vers la nouvelle cellule
    l->size++;                  // On incrémente la taille de la liste
}


// Suppression

void deleteFirst(struct List* l) {
    if (isListEmpty(l)) {       // Si la liste est vide, on ne fait rien
        return;
    }
    struct Cell* temp = l->head;
    struct Cell* next = l->head->next;
    deleteMovie(&(temp->movie));        // On supprime le film
    free(temp);                    // On supprime la cellule
    l->head = next;         // On fait pointer le head vers la nouvelle cellule
    l->size--;          // On décrémente la taille de la liste
}


void deleteList(struct List** l){
    while(!isListEmpty(*l)){        // Tant que la liste n'est pas vide, on supprime le premier élément
        deleteFirst(*l);
    }
    free(*l);       // On supprime la liste
    *l = NULL;
}

// Autres opérations

bool isListEmpty(struct List* l){           // On vérifie si la liste est vide
    return l->size == 0;
}
