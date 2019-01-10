#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

int main(int argc, char** argv) {

  if (argc < 2) {
    fprintf(stdout, "Please provide filename. \n");
  }

  // Create an array of 10,000 samples of the sum of three sin waves with the following info:
  // 500 Hz, 1000 Hz, 2000 Hz; amplitude = 5000; phase = 0
  //
  int sampleSize = 10000;
  int amplitude = 5000;
  int freqOne = 500;
  int freqTwo = 1000;
  int freqThree = 2000;
  signed short int sig[sampleSize];
  
  // Loop over 10,000 samples and add the sign waves for the continuous function. Store results to array.
  // 
  for (long n = 0; n < sampleSize; n++) {
    sig[n] = amplitude*(sin(2*PI*freqOne*n/sampleSize)+(sin(2*PI*freqTwo*n/sampleSize))+(sin(2*PI*freqThree*n/sampleSize)));
  }
			
  // Open file and write to it
  // 
  FILE* fp = fopen(argv[1], "w");
  if (fp == (FILE*)NULL) {
    fprintf(stdout, "Error opening file (%s)\n", argv[1]);
    return (-1);
  }

  long num_write = fwrite(sig, sizeof(signed short int), sampleSize, fp);
  fprintf(stdout, "fwrite wrote %ld\na", num_write);

  fclose(fp);

  return 0;
}
