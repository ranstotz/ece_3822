#include "f_00.h"   // include header file

// Function prototypes
//
//float add_sin(float num1, float num2);
//float add_sqrt(float num1, float num2);

// Main function
//
int main(int argc, char** argv) {

  // Accept arguments
  //
  char *arg1 = argv[1];
  char *arg2 = argv[2];
  
  // Cast arguments to floats
  //
  float fltArg1 = atof(arg1);
  float fltArg2 = atof(arg2);

  // Call functions and store to variables
  //
  float fltAddSin = add_sin(fltArg1, fltArg2);
  float fltAddSqrt = add_sqrt(fltArg1, fltArg2);

  // Print functions and "hello world"
  //
  fprintf(stdout, "hello world\n");
  fprintf(stdout, "%f\n", fltAddSin);
  fprintf(stdout, "%f\n", fltAddSqrt);

  // End
  //
  return 0;
}

  
