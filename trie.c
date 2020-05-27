#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "trie.h"



//typedef struct trie {
//    struct node *root;
//    int size;
//} trie;


//root will have the char '$' as default
trie init_trie(){
    trie t;
    struct node *n = init_node('$');
    t.root = n;
    t.size = 0;
    t.longest_string=0;
    return t;
}

void release_trie(trie t) {
    release_node(t.root);
}


void insert(trie* t,char* s) {
    int i=0;
    t->size++;
    if (strlen(s)>t->longest_string) t->longest_string=strlen(s);
    struct node *temp = t->root;
    temp->count++;
    while (*(s+i)!='\0'){
        set_child(temp, *(s+i));
        temp = temp->children[((int)*(s+i))-97];
        i++;
    }
    if (temp->children[26]) {
        temp->children[26]->count++;
    }else{
        set_child(temp,'$');
    }
}

int contains(trie* t, char *s){
    node *temp = t->root;
    int i=0;
    while (*(s+i)!='\0'){
        if (temp->children[*(s+i)-97]) {
            temp = temp->children[*(s+i)-97];
            i++;
            continue;
        }else return 0;
    }
    if (temp->children[26]){
        return temp->children[26]->count;
    }else return 0;
}

void delete(trie* t, char* s){
    if (contains(t,s)<=0) {
        printf("the word: %s wasn't found in the trie", s);
        return;
    }
    node *temp = t->root;
    temp->count--;
    int i=0;
    while (*(s+i)!='\0'){
        temp = temp->children[*(s+i)-97];
        if (temp->count==1) {
            release_node(temp);
            return;
        }else temp->count--; 
        i++;
        continue;
    }
    temp = temp->children[26];
    if (temp->count==1) {
        release_node(temp);
    }else temp->count--;
}

void print_trie(trie* t, enum boolean b){
    node *temp = t->root;
    char *s = (char*)malloc(sizeof(char)*t->longest_string);
    if (s==NULL){
        printf("Insufficient Memory, Exiting... \n");
        exit(1);
    }
    int i=0;
    if (b==TRUE){
        for (int j=0;j<26;j++){
            if (temp->children[j]) get_string(temp->children[j], s, i);
        }
    }else {
        for (int j=25;j>-1;j--){
            if (temp->children[j]) get_string_reversed(temp->children[j], s, i);
        }
    }
    free(s);
}

void get_string(node *n, char* s, int i){
    if (n->letter=='$') {
        *(s+i) = '\0';
        printf("%s\t%ld\n", s, n->count);
        return;
    }
    *(s+i) = n->letter;
    if (n->children[26]) get_string(n->children[26], s, i+1);
    for (int j=0;j<26;j++){
        if (n->children[j]) get_string(n->children[j], s, i+1);
    }
}

void get_string_reversed(struct node *n, char* s, int i){
    if (n->letter=='$') {
        *(s+i) = '\0';
        printf("%s\t%ld\n", s, n->count);
        return;
    }
    *(s+i) = n->letter;
    if (n->children[26]) get_string_reversed(n->children[26], s, i+1);
    for (int j=25;j>-1;j--){
        if (n->children[j]) get_string_reversed(n->children[j], s, i+1);
    }
}