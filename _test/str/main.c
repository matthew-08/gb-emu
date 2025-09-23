#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void test (int n, int (*nums)[n]) {
    
    for (int i = 0; i < n; i++) {
        printf("%d", *nums[i]);
    }
}

int main (int argc, char *argv[]) {

    srand(time(NULL));

    int max = 100;
    int min = 50;
    printf("%d", min + rand() % (max - min + 1));

}