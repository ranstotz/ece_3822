#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSIZE 100

int main(int argc, char** argv) {

  if (argc < 2) {
    fprintf(stdout, "Please provide filename. \n");
  }
  
  // Create array of 100 signed short ints 
  // 
  signed short int x[100];
  for (int i = 0; i < 100; i++) {
    x[i] = i;
  }
  
  // Open file and write to it
  // 
  FILE* fp = fopen(argv[1], "w");
  if (fp == (FILE*)NULL) {
    fprintf(stdout, "Error opening file (%s)\n", argv[1]);
    return (-1);
  }

  long num_write = fwrite(x, sizeof(signed short int), NSIZE, fp);
  fprintf(stdout, "fwrite wrote %ld\na", num_write);

  fclose(fp);

  return 0;
}
