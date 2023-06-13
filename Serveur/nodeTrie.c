#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include "nodeTrie.h"


struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* trie = malloc(sizeof(struct NodeTrie));
    if(trie != NULL){
        trie->director = NULL;
        //pointeur à director qui fait office de "isWord"
        for(int i = 0;i < 28; i++){
            trie->next[i] = NULL; //on init tout le tableau à NULL
        }
    }
    return trie;
}

void insertDirector(struct NodeTrie* trie, struct Director* director){
    unsigned int n = strlen(director->name);

    struct NodeTrie* iter = trie;
    //on rejoint le dernier char du nom, pour chaque char, si il n'existe pas on le crée
    for(int i = 0;i < n;i++){
        if(director->name[i] == '-'){
            if(iter->next[26] == NULL){
                iter->next[26] = createEmptyNodeTrie();
                iter = iter->next[26];
            }
            else{
                iter = iter->next[26];
            }
        }
        else{
            if(director->name[i] == '\''){
                if(iter->next[27] == NULL){
                    iter->next[27] = createEmptyNodeTrie();
                    iter = iter->next[27];
                }
                else{
                    iter = iter->next[27];
                }
            }
            else{
                if(iter->next[(int)director->name[i]-'a'] == NULL){
                    iter->next[(int)director->name[i]-'a'] = createEmptyNodeTrie();
                    iter = iter->next[(int)director->name[i]-'a'];
                }
                else{
                    iter = iter->next[(int)director->name[i]-'a'];
                }
            }

        }

    }
    //une fois au dernier char, on met le pointeur à la cellule director
    iter->director = director;
}

struct Director* findDirector(struct NodeTrie* trie, char* name){
    struct NodeTrie* iter = trie;
    int n = strlen(name);
    //on parcour jusqu'a arrivé au dernier char du nom
    for(int i = 0;i < n;i++){
        if(name[i] == '-'){
            if(iter->next[26] == NULL){
                //si on rencontre un char qui n'est pas defini, alors le real n'existe pas donc on return NULL
                return NULL;
            }
            iter = iter->next[26];
        }
        else{
            if(name[i] == '\''){
                if(iter->next[27] == NULL){
                    return NULL;
                }
                iter = iter->next[27];
            }
            else{
                if(iter->next[name[i]-'a'] == NULL){
                    return NULL;
                }
                iter = iter->next[name[i]-'a'];
            }
        }
    }
    //on return la structure trouvé à la fin
    return iter->director;
}

void deleteNodeTrie(struct NodeTrie** trie){
    for(int i = 0;i < 28;i++){
        //on lance la fonction pour les 28 cases du tableau
        if((*trie)->next[i]!= NULL){
            deleteNodeTrie(&((*trie)->next[i]));
        }
    }
    //on libère la mémoire de la structure du réalisateur
    deleteDirector(&((*trie)->director));
    //puis on supprime le noeud
    free(*trie);
    *trie = NULL;
}