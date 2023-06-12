#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include "nodeTrie.h"


struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* trie = malloc(sizeof(struct NodeTrie));
    if(trie != NULL){
        trie->director = NULL;
        for(int i = 0;i < 28; i++){
            trie->next[i] = NULL;
        }
    }
    return trie;
}

void insertDirector(struct NodeTrie* trie, struct Director* director){
    unsigned int n = strlen(director->name);

    struct NodeTrie* iter = trie;
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
    iter->director = director;
}



void deleteDirectorTrie(struct NodeTrie* trie, struct Director* director){
    unsigned int n = strlen(director->name);
    struct NodeTrie* iter = trie;
    for(int i = 0;i < n;i++){
        if(director->name[i] == '-'){
            iter = iter->next[26];
        }

        else{
            if(director->name[i] == '\''){
                iter = iter->next[27];
            }
            else{
                iter = iter->next[director->name[i]-'a'];
            }

        }
    }
    iter->director = NULL;
}

struct Director* findDirector(struct NodeTrie* trie, char* name){
    struct NodeTrie* iter = trie;
    int n = strlen(name);
    for(int i = 0;i < n;i++){
        if(name[i] == '-'){
            if(trie->next[26] == NULL){
                return NULL;
            }
            trie = trie->next[26];
        }
        else{
            if(name[i] == '\''){
                if(trie->next[27] == NULL){
                    return NULL;
                }
                trie = trie->next[27];
            }
            else{
                if(trie->next[name[i]-'a'] == NULL){
                    return NULL;
                }
                trie = trie->next[name[i]-'a'];
            }
        }
    }
    return trie->director;
}

void deleteNodeTrie(struct NodeTrie** trie){
    for(int i = 0;i < 28;i++){
        if((*trie)->next[i]!= NULL){
            deleteNodeTrie(&((*trie)->next[i]));
        }
    }
    deleteDirector(&((*trie)->director));
    free(*trie);
    *trie = NULL;
}