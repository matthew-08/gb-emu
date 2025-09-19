#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 4096

int main(void) {

    FILE *f = fopen("./input.txt", "r");
    char buf[CHUNK_SIZE];

    size_t nread;
    while ((nread = fread(buf, 1, CHUNK_SIZE, f)) > 0) {
        fwrite(f, 1, nread, stdout);
    }

    return 0;

}
