#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


int main(int argc, char* argv[]) {
    trie t = init_trie();
    int i=0;
    int len = 5;
    char *s = (char*)malloc(sizeof(char)*len);
    char c;
    while (scanf("%c", &c)!=EOF){
        if (64<(int)c && (int)c<91) c = (char)(32+(int)c);
        if ((int)c<97 || 122<(int)c) continue;
        if (i>=len){
            len=len*2;
            s = (char*) realloc(s,sizeof(char)*len);
        }
        if (c==' ' || c=='\t' || c=='\n' || c=='\0'){
            *(s+i)='\0';
            insert(t,s);
            i=0;
        }else{
            *(s+i)=c;
            i++;
        }

    }
    print_trie(t,TRUE);

    free(s);
    release_trie(t);
    return 0;
}