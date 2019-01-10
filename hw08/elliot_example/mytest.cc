#include "mytest.h"

int main(int argc, char** argv) {

  // Test the class and create test object
  // 
  MyTest test;

  // Test the debug method to print
  //
  printf("before calling set_debug, MyTest::debug_level_d is %d\n", MyTest::debug_level_d);
  test.set_debug(FULL);
  printf("after calling set_debug,  MyTest::debug_level_d is %d\n", MyTest::debug_level_d);
  
  // Exit gracefully
  //
  return 0;
}
