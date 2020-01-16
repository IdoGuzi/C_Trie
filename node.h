#ifndef _NODE_H_
#define _NODE_H_

#define NUM_LETTERS ((int)27)

extern enum boolean{FALSE=0,TRUE=1} boolean;

//extern struct node node;
typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;

node* init_node(char data);

void release_node(node* n);

void set_child(node *parent,char letter);



#endif