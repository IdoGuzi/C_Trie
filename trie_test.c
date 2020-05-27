#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

//function declurations
void insert_contains_test();

int main(int argc, char* argv[]) {
    insert_contains_test();
}

// this function test insert and contains at the same time.
// count fails for insert/contains indevidualy 
void insert_contains_test() {
    int insert_fails = 0;
    int contains_fails = 0;
    int delete_fails = 0;
    trie t = init_trie();
    trie* t_ptr = &t;
    char *str = "hello";
    insert(t_ptr,str);
    int expected = 1;
    int result = contains(t_ptr,str);
    if (result!=expected) {
        if (result==0) {
            printf("ERROR: insert failed");
            insert_fails++;
        }else {
            printf("ERROR: contains failed");
            contains_fails++;
        }
    }
    insert(t_ptr,str);
    expected = 2;
    result = contains(t_ptr,str);
    if (result!=expected) {
        if ((insert_fails==0 && result==1) || (insert_fails==1 && result==0)){
            printf("ERROR: insert failed");
            insert_fails++;
        }else{
            printf("ERROR: contains failed");
            contains_fails++;
        }
    }
    printf("%d\n",contains(t_ptr,str));
    delete(t_ptr,str);
    expected = 1;
    result = contains(t_ptr,str);
    if (result!=expected) {
        printf("ERROR: delete failed\n");
        delete_fails++;
    }
    print_trie(t_ptr,TRUE);
    delete(t_ptr,str);
    expected = 0;
    print_trie(t_ptr,TRUE);
    result = contains(t_ptr,str);
    if (result!=expected) {
        printf("ERROR: delete failed\n");
        delete_fails++;
    }

    str = "world";
    expected=0;
    result = contains(t_ptr,str);
    if (result!=expected) {
        if (result==0) {
            printf("ERROR: insert failed");
            insert_fails++;
        }else {
            printf("ERROR: contains failed");
            contains_fails++;
        }
    }
    printf("insert fails=%d\ncontains fails=%d\ndelete fails=%d\n", insert_fails,contains_fails,delete_fails);
    release_trie(t);
}