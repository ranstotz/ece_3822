#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the array size as 10,000 samples according to problem
//
#define NSIZE 10000

int main(int argc, char** argv) {

  // Open file as first argument, assign size of signed short, print number
  //  
  FILE* fp = fopen(argv[1], "r");
  
  // Create a buffer to handle all of the sine wave additions
  //
  signed short int buffer[NSIZE];
  
  // Store the read signed short ints into a variable to be printed
  // 
  long num_read = fread(buffer, sizeof(signed short int), NSIZE, fp);

  // Print the number of signed short ints read
  // 
  fprintf(stdout, "num_read = %ld\n", num_read);

  // Loop through buffer that stores the read text
  // 
  for (int i=0; i < NSIZE; i++) {

    fprintf(stdout, "%d\n", buffer[i]);
  }

  // Close file
  //     
  fclose(fp);
  return 0;
}
