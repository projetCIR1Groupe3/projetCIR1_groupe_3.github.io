
#include "request.h"



int checkIfFileExists(const char * filename){       //fonction qui vérifie si le fichier existe (ici pour request.txt)
    FILE *file;
    if ((file = fopen(filename, "r"))){     //si la fonction réussi à ouvrir le fichier, il existe
        fclose(file);
        return 1;
    }

    return 0;
}

void ListToTxt(struct List* l){         //fonction qui écrit la liste dans un fichier texte
    FILE *fichier = NULL;
    fichier = fopen("resultat.txt", "w");
    if(l==NULL){
        fprintf(fichier, "NULL\n");         //si la liste est vide alors on écrit que rien ne correspond
        fclose(fichier);
    }
    else{                            //sinon on écrit les films qui correspondent
        if (fichier != NULL) {
            struct Cell *iter = l->head;
            while (iter != NULL) {
                fprintf(fichier, "%s;%s;%s;%d\n", iter->movie->directorName, iter->movie->title, iter->movie->genre, iter->movie->length);  //on écrit les infos du film dans le même format que dans la base de données
                iter = iter->next;
            }
            fclose(fichier);
        }
    }

}


void requestExe(struct Netflux* n){       //fonction qui recupère la requête et qui exécute la fonction correspondante
    double time_spent = 0.0;
    clock_t start = clock();        //on démarre le timer pour calculer le temps d'exécution

    int stop = 0;       //variable qui permet de faire une condition d'arrêt pour la boucle while et donc pour terminer le programme
    while(stop == 0) {
        if (checkIfFileExists("request.txt")) { //si le fichier existe alors on peut lire la requête
            FILE *file = fopen("request.txt", "w+");

            //Initialisation des variables
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
            remove("request.txt"); //supprime le request.txt pour éviter de lire la même requête plusieurs fois

            //On fait une série de "if" et de "else" pour savoir quelle fonction exécuter suivant le filtre

            if(strcmp(filtre, "realisateur")==0){
                struct List* l = searchByDirector(n, recherche);
                clock_t end = clock();      //on arrête le timer car il ne faut pas compter le temps d'écriture dans le fichier
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);     //on écrit le temps d'exécution dans le fichier
                fclose(fichier);
                ListToTxt(l);       //on écrit la liste dans le fichier

                FILE *ready = NULL;
                ready = fopen("ready.txt", "w");        //on écrit un fichier "ready.txt" pour dire que le fichier est prêt à être lu
                fclose(ready);

            }
            else if(strcmp(filtre, "duree")==0){        //on fait presque la même chose que précédemment
                int lenght = atoi(recherche);   //on convertit la recherche en int sachant que la recherche correspond à une durée
                struct List* l = searchByLenght(n,lenght);
                clock_t end = clock();      //comme précédemment on arrête le timer car il ne faut pas compter le temps d'écriture dans le fichier
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);   //on écrit le temps d'exécution dans le fichier
                fclose(fichier);
                ListToTxt(l);           //on écrit la liste dans le fichier

                FILE *ready = NULL;
                ready = fopen("ready.txt", "w");        //on écrit un fichier "ready.txt" pour dire que le fichier est prêt à être lu
                fclose(ready);

            }
            else if(strcmp(filtre, "DeleteAllMovies")==0){
                deleteNetflux(&n);          //on supprime la base de données
                clock_t end = clock();              //on arrête le timer car il ne faut pas compter le temps d'écriture dans le fichier
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%f\n", time_spent);       //on écrit le temps d'exécution dans le fichier
                fclose(fichier);

                FILE *ready = NULL;
                ready = fopen("ready.txt", "w");        //on écrit un fichier "ready.txt" pour dire que le fichier est prêt à être lu
                fclose(ready);
                stop = 1;           //on arrête la boucle while pour terminer le programme

            }
            else if(strcmp(filtre, "BiggestReal")==0){
                char *name = getBiggestDirector(n)->name;
                int nb = n->biggest->movieList->size;
                clock_t end = clock();
                time_spent += (double)(end - start) / CLOCKS_PER_SEC;
                FILE *fichier = NULL;
                fichier = fopen("resultat.txt", "w");
                fprintf(fichier, "%s;%d\n", name, nb);          //on écrit le nom du réalisateur et le nombre de films qu'il a réalisé
                fclose(fichier);
                FILE *fichier2 = NULL;
                fichier2 = fopen("resultat.txt", "w");
                fprintf(fichier2, "%f\n", time_spent);
                fclose(fichier2);

                FILE *ready = NULL;
                ready = fopen("ready.txt", "w");
                fclose(ready);

            }
        }
    }
}
