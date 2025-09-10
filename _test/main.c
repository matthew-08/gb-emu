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
   // jump to end of file
   // read 4000 bytes
   // start at end of array, find newline.
   // from start of newline to next newline, copy every char into a buffer.
   // store the resulting string in an array
   // at the end, print each string to stdout.


   FILE *fp = fopen("./input.txt", "r");
   fseek(fp, 0, SEEK_END);
   long size = ftell(fp);
   
   long chunk_size = 4000;
   long offset = 0;


   long pos = size;
   printf("%ld", ftell(fp));

   char buffer[4000] = {0};


   int right = size;
   int left = 0;
   while (right > left)
   {
    // right = size
    // left = size - chunk_size OR size - size
    int left = (chunk_size > size) ? 0 : size - chunk_size; 
    size = (right - left);

    fseek(fp, left, SEEK_SET);
    fread(buffer, 1, size, fp);
    fwrite(buffer, 1, size, stdout);

    right = left;

   }


   
   return 0;
}