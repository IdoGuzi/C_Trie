#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

int main(int argc, char* argv[]) {
    trie t = init_trie();
    int i=0;
    int len = 5;
    char *s = (char*)malloc(sizeof(char)*len);
    if (s==NULL){
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }
    char c = '*';
    while ((c=getc(stdin))!=EOF){
        if (i>=len){
            len=len*2;
            s = (char*) realloc(s,sizeof(char)*len);
            if (s==NULL){
                printf("Insufficient Memory, Exiting... \n");
                return 0;
            }
        }
        if (c==' ' || c=='\t' || c=='\n' || c=='\0'){
            *(s+i)='\0';
            insert(&t,s);
            i=0;
            continue;
        }
        if (64<(int)c && (int)c<91) c = (char)(32+(int)c);
        if ((int)c<97 || 122<(int)c) continue;
        *(s+i)=c;
        i++;

    }
    char *word = "it";
    printf("the word \"it\" can be found in the trie %d times\n", contains(&t,word));
    free(s);
    release_trie(t);
    return 0;
}