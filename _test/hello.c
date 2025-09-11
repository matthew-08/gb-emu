#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // make an array of 3 strings
    char *strings[] = { "alpha", "bravo", "charlie" };

    // let lines point to that array
    char **lines = strings;

    printf("Base address (lines)    : %p\n", (void*)lines);
    printf("Address of lines + 1    : %p\n", (void*)(lines + 1));
    printf("Address of lines + 2    : %p\n", (void*)(lines + 2));
    printf("Size of char *          : %zu bytes\n", sizeof(char *));

    // also look inside one string
    printf("\nInside first string:\n");
    printf("Address of lines[0]     : %p\n", (void*)lines[0]);
    printf("Address of lines[0] + 1 : %p\n", (void*)(lines[0] + 1));
    printf("Size of char            : %zu byte\n", sizeof(char));

    return 0;
}
