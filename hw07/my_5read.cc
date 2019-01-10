#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

  // Open file as first argument, assign size of signed short, print number
  //  
  FILE* fp = fopen(argv[1], "r");
  
  int a;
  short int b;
  unsigned short int c;
  float d;
  double e;
  short int f[10];
  float g[10];
  double h[10];

  // Read the file that was written
  //
  fread(&a, sizeof(int), 1, fp);
  fread(&b, sizeof(short int), 1, fp);
  fread(&c, sizeof(unsigned short int), 1, fp);
  fread(&d, sizeof(float), 1, fp);
  fread(&e, sizeof(double), 1, fp);
  fread(f, sizeof(short int), 10, fp);
  fread(g, sizeof(float), 10, fp);
  fread(h, sizeof(double), 10, fp);
  
  // Print the contents of what was read
  //
  fprintf(stdout, "%d\n", a);
  fprintf(stdout, "%d\n", b);
  fprintf(stdout, "%d\n", c);
  fprintf(stdout, "%f\n", d);
  fprintf(stdout, "%lf\n", e);
 
  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%d\n", f[i]);
  }
  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%f\n", g[i]);
  }
  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%lf\n", h[i]);
  }

  // Close the file
  //
  fclose(fp);
  return 0;
}
