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

   while (right > 0)
   {

    long left = ((right - CHUNK_SIZE) < 0) ? 0 : (right - CHUNK_SIZE);
    size_t span = (right - left);


    fseek(fp, left, SEEK_SET);
    size_t got = fread(buffer, 1, span, fp);
    fwrite(buffer, 1, got, stdout);
    right = left;

   }



   
   return 0;
}