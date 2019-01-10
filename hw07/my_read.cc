#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSIZE 100

int main(int argc, char** argv) {

  // Open file as first argument, assign size of signed short, print number 
  FILE* fp = fopen(argv[1], "r");
  long bsize = sizeof(signed short int);
  signed short int buffer[NSIZE];
  long num_read = fread(buffer, sizeof(signed short int), NSIZE, fp);
  fprintf(stdout, "num_read = %ld\n", num_read);

  for (int i=0; i < NSIZE; i++) {

    fprintf(stdout, "%d", buffer[i]);
  }
    
  fclose(fp);
  return 0;
}
