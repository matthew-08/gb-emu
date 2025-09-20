#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char *argv[]) {

    freopen("./o-input.txt", "r", stdin);
    freopen("./o-output.txt", "w", stdout);

    int a,b;
    scanf("%d %d", &a, &b);

    printf("%d", a + b);
}
// *(*strs)

