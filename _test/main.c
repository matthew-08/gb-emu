#include <stdio.h>
#include <string.h>

int main()
{
    // create a buffer of 50 characters read one line of input from stdin

    char buf[50] = {0};

    if(!fgets(buf, sizeof(buf), stdin)) {
        perror("fgets");
        return 1;
    }

    printf("test: %zu", strlen(buf));
    printf("Result: %s\n", buf);

    
    return 0;
}