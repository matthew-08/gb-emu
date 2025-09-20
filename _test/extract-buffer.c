#include <stdio.h>
#include <sys/io.h>
#include <string.h>
#include <stdlib.h>


int main() {

    char *  p = malloc(10);
    p[10] = '\0';   // ❌ should be p[9]
}