#ifndef _NODETRIE_H_
#define _NODETRIE_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct NodeTrie{
    struct NodeTrie* next[27];
    struct Director* director;
};

struct NodeTrie* createEmptyNodeTrie();

void insertDirector(struct NodeTrie* trie, struct Director* director);

void deleteDirector(struct NodeTrie* trie, struct Director* director);

struct Director* findDirector(struct NodeTrie* trie, char* name);

void deleteNodeTrie(struct NodeTrie** trie);

void displayDict(struct NodeTrie* trie, char* actualWord, int index); // main : int index = 0 / char actualWord[50]

#endif