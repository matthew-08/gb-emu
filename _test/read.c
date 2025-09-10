
#include <stdio.h>

int main () {
    freopen("operations.txt", "r+", stdin);

    freopen("result.txt", "w", stdout);

    int a;
    int b;
    scanf("%d %d", &a, &b);

    printf("%d", a+b);
}