#include <stdio.h>
#include <string.h>

int main(void) {
   // take in user input from stdin, print everything after the word skip

    const char *str = "skiphello world";
    const char *p = strstr(str, "skip");   // find "skip" inside str

    if (p) {
        p += 4; // move past "skip"
        printf("%s\n", p);  // print everything after
    } else {
        printf("No 'skip' found\n");
    }

    return 0;

}