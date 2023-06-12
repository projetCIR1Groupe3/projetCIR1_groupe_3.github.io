#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

#include "request.h"



int checkIfFileExists(const char * filename)
{
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }

    return 0;
}

void ListToTxt(struct List* l){
    FILE *fichier = NULL;
    fichier = fopen("resultat.txt", "w");
    if (fichier != NULL){
        struct Cell* iter = l->head;
        while(iter != NULL){
            fprintf(fichier, "%s;%s;%s;%d\n", iter->movie->directorName, iter->movie->title, iter->movie->genre, iter->movie->length);
            iter = iter->next;
        }
        fclose(fichier);
    }

}


void requestExe(struct Netflux* n){
    int stop = 0;
    while(stop == 0) {
        if (checkIfFileExists("request.txt")) {
            FILE *file = fopen("request.txt", "r");


            char* token;
            int i = 0;
            char filtre[32];
            char recherche[32];
            char str[100];


            while(!feof(file)){
                fgets(str, 100, file);
                str[strcspn(str, "\r\n")] = '\0';
                token = strtok(str,";");
                strcpy(filtre,token); // première itération
                while(token != NULL) {
                    token = strtok(NULL, ";");
                    switch (i) { //on "slice" avec un compteur pour mettre au bon endroit
                        case 0:
                            strcpy(recherche, token);
                            break;
                        default:
                            token = NULL;
                            break;
                    }
                    i++;
                }
            }

            fclose(file);
            remove("request.txt");
            if(strcmp(filtre, "realisateur")){
                searchByDirector(n, recherche);
                ListToTxt(l);
            }
            else if(strcmp(filtre, "duree")){
                int lenght = atoi(recherche);
                searchByLenght(n,lenght);
                ListToTxt(l);
            }
            else if(strcmp(filtre, "DeleteAllMovies")){
                deleteNetflux(n);
            }
            else if(strcmp(filtre, "BiggestReal")){

            }
        }
    }
}
