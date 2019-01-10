#include "mytest.h"

// Implementations of methods in MyTest

// Declare statics
//
const char* MyTest::NAME = "MyTest";

// Implement name() method
//
const char*MyTest::name() {
  return NAME;
}

// Declare debug_level
//
MyTest::DBGL MyTest::debug_level_d = MyTest::FULL;

// Implement set_debug method to set the debug_level_d
// FULL = 0, PARTIAL = 1, BRIEF = 2, NONE = 3
//
bool MyTest::set_debug(MyTest::DBGL x_a) {

  // Set debug_level_d to the argument provided
  //
  debug_level_d = x_a;

  
  // exit gracefully
  //
  return true;
}

/*
// Implement debug method to display all internal data within the class
//
bool MyTest::debug(MyTest::DBGL var_a) {

  // Reset debug_level_d according to the argument provided since scope was an
  // issue
  //
  debug_level_d = var_a;

  // Let user know if debug level incorrectly set
  //
  if (debug_level_d < 0 || debug_level_d > 3) {
    fprintf(stdout, "Please select a debug level:\n0=FULL, 1=PARTIAL, 2=BRIEF, 3=NONE\n");
    return false;
  }

  // Print the name of the class
  //
  fprintf(stdout, "The name of the class is %s.\n", NAME);

  // If statement to print data for each debug level
  //
  // Debug FULL
  //
  if (debug_level_d == 0) {
    fprintf(stdout, "This statement is printing since the FULL debug method was selected. \n\nThe public data includes a static const called 'NAME' that contains the string 'MyTest' and a static enum type later described with variable name 'debug_level_d'. \n\nAlso, there are two public enum's named: debug_level containing values 'FULL', 'PARTIAL', 'BRIEF', AND 'NONE'; and ALGORITHM that contains 3 values. \nPublic methods are: 'name' that returns the class name; 'set_debug' that sets the debug_level_d to a certain value; 'debug' that similarly sets the debug_level_d to a certain value and prints messages as such; 'compute' that takes an argument that is an enum called ALGORITHM and calls one of three private methods describe after this; 'compute_1', 'compute_2', and 'compute_3' that prints a message indicating it was called; and a private method reset that clears all internal data.\n");
  }

  // Debug PARTIAL
  //
  else if (debug_level_d == 1) {
    fprintf(stdout, "This statement is printing since the PARTIAL debug method was selected.  \n\nThe public data includes a static const called 'NAME' that contains the string 'MyTest' and a static enum type later described with variable name 'debug_level_d'. \n\nAlso, there are two public enum's named: debug_level containing values 'FULL', 'PARTIAL', 'BRIEF', AND 'NONE'; and ALGORITHM that contains 3 values. \nPublic methods: 'name', 'set_debug', 'debug', 'compute'. \nPrivate methods: 'compute_1, compute_2, compute_3, and 'reset'.\n");
  }

  // Debug BRIEF
  //
  else if (debug_level_d == 1) {
    fprintf(stdout, "This statement is printing since the BRIEF debug method selected. \n\nPublic methods: 'name', 'set_debug', 'debug', 'compute'. \nPrivate methods: 'compute_1, compute_2, compute_3, and 'reset'.\n");
  }

  // Exit gracefully
  //
  return true;
}
*/

// Declare enum type ALGORITHM with three choices
//
enum ALGORITHM {COMP_1 = 0, COMP_2, COMP_3};

// Declare variable to store argument parameter
//
static ALGORITHM algoChoice;

// Implement compute method to accept an argument and cast it to the Algorithm enum
// then, depending on the argument, call private methods
//
void MyTest::compute(int var) {
  // Cast parameter to ALGORITHM enum
  //
  ALGORITHM algoChoice = (ALGORITHM)var;

  // Implement enum according to algorithm choice (0, 1, 2)
  //
  if (algoChoice == 0) {
    compute_1();
  }   
  else if (algoChoice == 1) {
    compute_2();
  }
  else if (algoChoice == 2) {
    compute_3();
  }
  else {
    fprintf(stdout, "please enter 0, 1, or 2 for compute_1, compute_2, or compute_3");
  }
}

// Implement private method compute_1, does nothing but return a print statement
//
void MyTest::compute_1() {
  fprintf(stdout, "this is compute_1\n");
}

// Implement private method compute_2, does nothing but return a print statement
//
void MyTest::compute_2() {
  fprintf(stdout, "this is compute_2\n");
}

// Implement private method compute_3, does nothing but return a print statement
//
void MyTest::compute_3() {
  fprintf(stdout, "this is compute_3\n");
}

// Private method called resest that clears all internal data
//
bool MyTest::reset() {
  
  ALGORITHM algoChoice = (ALGORITHM)0;
  
  return true;
}

