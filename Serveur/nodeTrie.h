#ifndef _NODETRIE_H_
#define _NODETRIE_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include "director.h"

struct NodeTrie{
    struct NodeTrie* next[28];
    struct Director* director;
};

struct NodeTrie* createEmptyNodeTrie();

void insertDirector(struct NodeTrie* trie, struct Director* director);

struct Director* findDirector(struct NodeTrie* trie, char* name);

void deleteNodeTrie(struct NodeTrie** trie);

#endif