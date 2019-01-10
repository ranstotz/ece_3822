#include "mytest.h"

int main(int argc, char** argv) {

  // Test the class and create test object
  // 
  MyTest test;

  // Test the debug method to print
  //
  test.set_debug(MyTest::FULL);
  
  // Exit gracefully
  //
  return 0;
}
