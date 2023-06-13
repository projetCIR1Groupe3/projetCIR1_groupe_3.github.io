
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
    double time_spent = 0.0;
    clock_t start = clock();

    int stop = 0;
    while(stop == 0) {
        if (checkIfFileExists("request.txt")) {
            FILE *file = fopen("request.txt", "w+");


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
            if(strcmp(filtre, "realisateur")==0){
                struct List* l = searchByDirector(n, recherche);
                clock_t end = clock();
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);
                fclose(fichier);
                ListToTxt(l);

            }
            else if(strcmp(filtre, "duree")==0){
                int lenght = atoi(recherche);
                struct List* l = searchByLenght(n,lenght);
                clock_t end = clock();
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);
                fclose(fichier);
                ListToTxt(l);
            }
            else if(strcmp(filtre, "DeleteAllMovies")==0){
                deleteNetflux(n);
                clock_t end = clock();
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);
                fclose(fichier);
            }
            else if(strcmp(filtre, "BiggestReal")==0){
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%s;%d\n", getBiggestDirector(n), n->biggest->movieList->size);
                fclose(fichier);
                clock_t end = clock();
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier2 = NULL;
                fichier2 = fopen("resultat.txt", "w");
                fprintf(fichier2, "%f\n", time_spent);
                fclose(fichier2);
            }
        }
    }
}
