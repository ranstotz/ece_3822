#include <stdio.h>
#include <stdlib.h>

int myfunc(void);

int main(int argc, char** argv) {

  // char *arg1 = argv[1];
  // char *arg2 = argv[2];
  
  //float x = atof(arg2);
  int x = myfunc();
  fprintf(stdout, "this is %d", x);

  return (0);
}
