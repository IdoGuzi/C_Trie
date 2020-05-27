#ifndef _TRIE_H_
#define _TRIE_H_

#include "node.h"

typedef struct trie {
    struct node *root;
    int size;
    int longest_string;
} trie;

/**
 * initialize a trie
 * @return a new trie
 */
trie init_trie();

/**
 * release the memory allocted for the trie
 */
void release_trie(trie t);

/**
 * inserts the word s to trie t
 */
void insert(trie* t,char* s);

/**
 * @return the number of time the word s was inserted
 */
int contains(trie* t, char *s);

/**
 * will delete the word s from the trie once
 */
void delete(trie* t, char* s);

void print_trie(trie* t, enum boolean b);

void get_string(struct node *n, char* s, int i);

void get_string_reversed(struct node *n, char* s, int i);

#endif