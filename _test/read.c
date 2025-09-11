
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <malloc.h>

enum ShapeKind { CIRCLE, RECTANGLE };

struct TaggedShape {
    enum ShapeKind kind;
    union {
        struct { 
            double radius; 
        } circle;
        struct {
            double w;
            double h;
        } rectange;
    };
};

double area(struct TaggedShape s) {
    return s.kind == CIRCLE
        ? 3.14 * s.circle.radius * s.circle.radius
        : s.rectange.w * s.rectange.h;
};
 
int main () {

    // Utilizing fread, open a file called ./input.text, and read from it in 4096 chunks, 
    // using fwrite to write the output into stdout.
    FILE *fp = fopen("./input.txt", "r");

    const int CHUNK_SIZE = 4096;
    char *buff = malloc(CHUNK_SIZE);

    size_t nread;

    while ((nread = fread(buff, 1, CHUNK_SIZE, fp)) > 0) {
        fwrite(buff, 1, nread, stdout);
    }

    return 0;

}