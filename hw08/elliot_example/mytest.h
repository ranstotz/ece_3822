// Make sure definitions are only made once
//
#ifndef MYTEST_H
#define MYTEST_H

// System include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declare debug_level choices. You could put this in some other
// header file, and include that header file in all class header files
// that you want to use this.
//
enum DBGL {FULL = 777, PARTIAL, BRIEF, NONE, SUSHI};

// Declare class definitions
//
class MyTest {

  // Public data
  //
 public:

  // Declare a debug_level variable
  //
  static DBGL debug_level_d;

  // Declare public method set_debug that sets debug level to a specific value
  //
  bool set_debug(DBGL debug_level_a);

};

// End of Include file
//
#endif

  


