#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

int main(void) {
    char *buf = NULL;
    size_t n = 0;
    ssize_t nread = 0;

    if ((nread = getline(&buf, &n, stdin)) != -1)
    {
        printf("Read %zd characters: %s", nread, buf);
    }
    else
    {
        perror('getline');
    }



}