#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//typedef struct node {
//    char letter;
//    long unsigned int count;
//    struct node* children[NUM_LETTERS];
//} node;



//****** node functions ***********
node* init_node(char data){
    node *n = (node*) malloc(sizeof(node));
    if (n==NULL) {
        printf("Insufficient Memory, Exiting... \n");
        exit(1);
    }
    n->letter = data;
    n->count = 0;
    for (int i=0;i<26;i++) {
        n->children[i] = NULL;
    }
    return n;
}

void release_node(node* n){
    for (int i=0;i<26;i++) {
        if(n->children[i]) {release_node(n->children[i]);}
    }
    free(n);
}



void set_child(node *parent,char letter){
    int index = (int) letter - 97;
    if (!parent->children[index]){
        node *child=init_node(letter);
        child->letter=letter;
        parent->children[index] = child;
    }else parent->children[index]->count++;
}