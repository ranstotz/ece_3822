#include "mytest.h"

// Implementations of methods in MyTest
//

// Define debug_level. Because static member variables are not part of
// the individual class objects (they are treated similarly to global
// variables, and get initialized when the program starts), you must
// explicitly define the static member outside of the class, in the
// global scope.
//
DBGL MyTest::debug_level_d = SUSHI;

// Implement set_debug method to set the debug_level_d
//
bool MyTest::set_debug(DBGL debug_level_a) {

  // Set debug_level_d to the argument provided
  //
  debug_level_d = debug_level_a;
  
  // exit gracefully
  //
  return true;
}
