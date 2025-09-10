
#include <stdio.h>

int main() {

    const int CHUNK_SIZE = 4096;
    int test = 1024;
    printf("%d", (test - CHUNK_SIZE));
}