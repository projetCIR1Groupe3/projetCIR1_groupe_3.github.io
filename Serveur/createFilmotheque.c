#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "createFilmotheque.h"

struct Netflux* createFilmotheque(char* fileName){
    struct Netflux* N = createNetflux(); // on crée le support
    FILE* file = fopen(fileName,"r");
    char str[100];
    struct Movie* m;
    struct Director* d;

    while(!feof(file)){
        //traitement d'une ligne
        fgets(str, 100, file);
        str[strcspn(str, "\r\n")] = '\0';
        m = recupMovie(str);
        d = findDirector(N->trie,m->directorName);

        // ajout dans le nodeTrie
        if(d == NULL){
            d = createDirector(m->directorName);
            insertDirector(N->trie,d);
        }
        addMovieDirector(d,m);

        // ajout dans la lengthSort
        addFirst(N->lengthSort[m->length],m);

        // comparaison real actuel / plus gros real
        compareBiggestProd(N,d);
    }
    fclose(file);

    return N;
}

struct Movie* recupMovie(char* str){
    // declaration
    char* token;
    int i = 0;
    char name[96];
    char genre[32];
    char directorName[32];
    unsigned int length;

    //separation de la ligne

    token = strtok(str,";");
    strcpy(directorName,token); // première itération
    while(token != NULL) {
        token = strtok(NULL, ";");
        switch (i) { //on "slice" avec un compteur pour mettre au bon endroit
            case 0:
                strcpy(name,token);
                break;
            case 1:
                length = atoi(token);
                break;
            case 2:
                strcpy(genre,token);
                break;
            default:
                token = NULL;
                break;
        }
        i++;
    }
    //on return la structure du film finie
    struct Movie* m = createMovie(length,name,genre, toLowerCase(directorName)/*on passe le nom en min pour eviter les erreurs dans le trie*/);  
    return m;
}

char* toLowerCase(char* word){
    unsigned int n = strlen(word);

    for(int i = 0;i < n;i++){
        if(word[i] != '-' && word[i] != '\'' && word[i] < 'a'){
            word[i] = word[i] + 32; // décalage dans la table ascii entre min et maj
        }
    }
    return word;
}

void compareBiggestProd(struct Netflux* N, struct Director* d){
    if(N->biggest == NULL){   // premiere iteration, biggest init à NULL
        N->biggest = d;
    }
    else{
        //on test la taille des listes donc le nombre de film
        if(N->biggest->movieList->size < d->movieList->size){
            N->biggest = d;
        }
    }
}
