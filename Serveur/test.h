//
// Created by shin on 08/06/23.
//

#ifndef PROJET_END_TEST_H
#define PROJET_END_TEST_H

struct Movie {
    int lengh;
    char* title;
    char* genre;
    char* directorName;
};

struct Director{
    int movieAmount;
    char* Name;
    struct Movie** movieList;
};

struct NodeTrie {
    char letter;
    struct NodeTrie* next[27]; // 27 car alphabet + '-'
    struct Director* director; // NULL si pas un producer
};

struct Netflux {
    struct NodeTrie* $[27];
    struct producer* biggest;
    struct HashTable* lenghSort;
};

struct HashTable {
    int buckets; // besoin de 400 buckets max
    int items;
    struct List** table;
};

#endif //PROJET_END_TEST_H
