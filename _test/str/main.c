#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void print_binary(int num) {
    int whole = num / 2;
    int r = num % 2;

    if (whole != 0) {
        print_binary(whole);
    }

    printf("%d", r);
}

int main () {
    print_binary(22);

}