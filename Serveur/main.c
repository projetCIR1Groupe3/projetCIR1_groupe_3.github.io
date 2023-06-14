#include "request.h"

int main(int argc, char** argv) {
    struct Netflux* n = createFilmotheque(argv[1]);     //on crée une filmothèque n avec argv[1] le nom du fichier de la base de données
    printf("program ready lancement request\n");

    requestExe(n);                            //on exécute les requêtes
    

    return 0;
}