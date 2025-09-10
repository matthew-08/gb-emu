#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <sys/stat.h>

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

int main()
{
    FILE *f = fopen("./input.txt", "r");
    long fs = get_file_size("./input.txt");

    printf("RESULT: [%ld]\n", fs);

    int c = 0;
    
    char buf[4096];
    size_t nread;
    
    char *p = buf;
    while((nread = fread(buf, 1, 4096, f)) > 0)
    {
        while (p = memchr(p, 'a', nread))
        {
            c++;
            p++;
        }
    }


    printf("RESULT: [%d]\n", c);
    fclose(f);
    
    return 0;
}