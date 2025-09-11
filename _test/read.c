
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

// Utilzing fread and memchr, create a program which opens 
// ./input.txt and reads from it into a buffer in 4096 byte chunks.  
// From there, search the text for occurances of 'a' and print a count of them in the format:
// RESULT: [%d]\n

    FILE *fp = fopen("input-2.txt", "r");

    const int CHUNK_SIZE = 4096;

    char buf[CHUNK_SIZE];

    int c;
    ssize_t nread;
    char *p = buf;

    printf("test\n");
    while((nread = fread(buf, 1, CHUNK_SIZE, fp)) > 0)
    {
        printf("test\n");
        while (p = memchr(p, 'a', nread) && !((p - buf) >= CHUNK_SIZE)) {
            c++;
            p++;
        }
    }

    printf("RESULT FOUND >>[%d]<< \n", c);
    fclose(fp);
    return 0;
}