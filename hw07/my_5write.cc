#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

  if (argc < 2) {
    fprintf(stdout, "Please provide filename. \n");
  }
  
  // Declare data 
  // 
  int a = 27;
  short int b = 32767;
  unsigned short int c = 32769;
  float d = -27.2727272727272727272727272727272727272727272727;
  double e = -27.2727272727272727272727272727272727272727272727;
  short int f[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  float g[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  double h[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  // Open file and write to it
  // 
  FILE* fp = fopen(argv[1], "w");
  if (fp == (FILE*)NULL) {
    fprintf(stdout, "Error opening file (%s)\n", argv[1]);
    return (-1);
  }

  fwrite(&a, sizeof(int), 1, fp);
  fwrite(&b, sizeof(short int), 1, fp);
  fwrite(&c, sizeof(unsigned short int), 1, fp);
  fwrite(&d, sizeof(float),1, fp);
  fwrite(&e, sizeof(double), 1, fp);
  fwrite(f, sizeof(short int), 10, fp);
  fwrite(g, sizeof(float), 10, fp);
  fwrite(h, sizeof(double), 10, fp);
  
  fclose(fp);

  return 0;
}
