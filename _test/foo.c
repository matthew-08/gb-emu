#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char *argv[]) {
    char *strings[] = {"test", "abc", "123"};

    printf("%s", *(strings + 1));
    

    return 0;
    
}
// *(*strs)

