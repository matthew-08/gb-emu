#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *reverse(char *s) {
    size_t len = strlen(s);

    size_t i, j;

    char tmp;
    for (i = 0, j = (len ? len - 1 : 0); i < j; i++, j--) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }

}

int main () {

    char *contents = read_stdin();

    if (contents) {
        printf("%s", read_stdin());
        free(contents);
    }

}
// *(*strs)

