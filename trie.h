#ifndef _TRIE_H_
#define _TRIE_H_

#include "node.h"

typedef struct trie {
    struct node *root;
    int size;
    int longest_string;
} trie;

trie init_trie();

void release_trie(trie t);

void insert(trie* t,char* s);

void print_trie(trie* t, enum boolean b);

void get_string(struct node *n, char* s, int i);

void get_string_reversed(struct node *n, char* s, int i);

#endif