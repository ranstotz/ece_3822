#include "example.h"
#include "example_00.cc"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  
  SparseMatrix<float> a(11, 11);
  SparseMatrix<float> b(11, 11);
  SparseMatrix<float> c(11, 11);
  
  a.set(27.0, 1, 1);
  a.set(27.0, 2, 2);
  a.set(27.0, 3, 3);

  b = a;

  c = a + b;

  c.debug(10,10);

  c.resize(10, 10);

  c.set(-1.0, 2, 2);
  
  fprintf(stdout, "val is %lf\n", val);
  
  c.set(-1.0, 10, 10);
  
  c.debug(10, 10);
  
  // Exit gracefully
  //
  return 0;
}
