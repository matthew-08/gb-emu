#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 4096

char *read_stdin(void) {

    size_t cap = 1024;
    size_t len = 0;

    char *buf = malloc(1024);

    if(!buf) return 0;

    char ch;
    while ((ch = getchar()) != EOF) {
        if (len + 1 > cap) {
           cap *= 2;
           char *tmp = realloc(buf, cap);
           if(!tmp) {
            free(buf);
            return NULL;
           }
           buf = tmp; 
        }
        buf[len++] = ch;
    }

    buf[len] = '\0';

    return buf;
}


int main () {

    char *strs[] = {"hello", "test", "amazing"};
    
    for (int i = 0; i < (sizeof(strs) / sizeof(*strs)); i++) {
        printf("INDEX: %d\nPointer: %p\nString: %s\n", i, strs[i], strs[i]);
    }
}

