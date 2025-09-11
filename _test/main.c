#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

void extract_buffer (argc, argv) {

    char buf[500];

    fread(buf, 1, 500, stdin);
    int i = 500;

    char **lines = NULL;

    size_t count = 0;
    size_t capacity = 0;


    char *str = malloc(500);
    for (i; i > 0; i++) {
        if (buf[i] == '\n' && i < 500) {
            if (count == capacity) {
                capacity = (capacity == 0) ? 4 : capacity * 2;
                if (!capacity) {
                    lines = malloc(sizeof(char *) * capacity);
                }
                else {
                    lines = realloc(lines, sizeof(char *) * capacity);
                }
            }
            lines[count++] = buf[i];
        }
    }
}



int main()
{
   // jump to end of file
   // read 4000 bytes
   // start at end of array, find newline.
   // from start of newline to next newline, copy every char into a buffer.
   // store the resulting string in an array
   // at the end, print each string to stdout.


   FILE *fp = fopen("./out.txt", "rb"); 
   if (!fp) { perror("fopen"); return 1; }

   fseek(fp, 0, SEEK_END);
   long size = ftell(fp);
   
   const long CHUNK_SIZE = 4096;
   
   unsigned char *buffer = malloc(CHUNK_SIZE);
   if (!buffer) { perror("malloc"); fclose(fp); return 1;};




   long right = size;



   char *line_buffer = NULL;
   size_t line_buffer_size = 0;
   while (right > 0)
   {

    long left = ((right - CHUNK_SIZE) < 0) ? 0 : (right - CHUNK_SIZE);
    size_t span = (right - left);


    fseek(fp, left, SEEK_SET);
    size_t got = fread(buffer, 1, span, fp);
    fwrite(buffer, 1, got, stdout);
    // go into buffer, start at got, while the byte is not equal to '\n', traverse backwards,
    // adding to a new buffer
    // when encouneter new '\n'
    // take the buffer, append it to an array of pointers,
    
    line_buffer_size += got;
    if (!line_buffer) {
        line_buffer = malloc(line_buffer_size);
    }
    else {
        line_buffer = realloc(line_buffer, line_buffer_size);
    }

    size_t i = got;
    int newline_processing = 0;
    while (i > 0) {
        line_buffer[i] = buffer[i];
    }
    
    right = left;

    // first, find newline 
   }



   
   return 0;
}