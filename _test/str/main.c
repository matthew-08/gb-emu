#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_nums (int n, int *nums) {
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }

}

int main (int argc, char *argv[]) {

    srand(time(NULL));

    int *buf = malloc(1024 * sizeof(*buf));

    if (!buf) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < 1024; i++) {
        buf[i] = rand();
    }

    print_nums(1024, buf);

}