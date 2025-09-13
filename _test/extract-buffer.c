#include <stdio.h>
#include <sys/io.h>
#include <string.h>




int main() {

    char name[50];
    double height;
    int age;

    if ((scanf("%s %lf %d", name, &height, &age)) == 3) {
        printf("NAME: %s, height: %lf, age: %d", name, height, age);
    }
 
    return 0;

}