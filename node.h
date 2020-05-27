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

/**
 * create new node
 * @return pointer to the new node
 */
node* init_node(char data);

/**
 * release the node allocated memory
 * this will release the node childs for safety
 */
void release_node(node* n);

/**
 * will create a new node for the letter
 * and will set the new node to be the parend's child
 */
void set_child(node *parent,char letter);



#endif