#include <stdio.h>
#include <string.h>

int main(void) {
    const char *input = "  one  two   three ";
    const char *delims = " \t\n";
    const char *p = input;

    while (*p) {
        // Skip leading delimiters (spaces, tabs, newlines)
        p += strspn(p, delims);
        if (*p == '\0') break;

        // Find the length of this word
        size_t len = strcspn(p, delims);

        // Print the token
        printf("Token: %.*s\n", (int)len, p);

        // Advance to next possible token
        p += len;
    }
}