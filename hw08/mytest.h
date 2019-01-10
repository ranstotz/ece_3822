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

// Declare class definitions for Problem 2 of HW 08
//
class MyTest {
  // Public data
  //
 public:
  
  // Define the class name
  // 
  static const char* NAME;

  // Define method that returns class name
  //
  const char* name();

  // Define debug_level choices
  //
  enum DBGL {FULL = 0, PARTIAL, BRIEF, NONE};

  // Define a debug_level variable
  //
  static DBGL debug_level_d;

  // Define public method set_debug that sets debug level to a specific value
  //
  bool set_debug(DBGL x_a);

  // Define a public method debug that displays all internal data within the class
  //
  bool debug(DBGL var_a);

  // Define a public method compute that takes an argument that is an enum
  // called ALGORITHM and calls private methods called compute_1, compute_2,
  // compute_3 depending on the value passed to compute
  // First define enum
  //
  enum ALGORITHM {COMP_1 = 0, COMP_2, COMP_3};

  // Define variable to store the algorithm choice
  //
  static ALGORITHM algoChoice;
  
  // Define the method
  //
  void compute(int var); 
  
  // Define private methods
  //
private:

  // Define compute_1, adds two numbers
  //
  void compute_1();

  // Define compute_2, subtracts two numbers
  //
  void compute_2();

  // Define compute_3, multiplies two numbers
  //
  void compute_3();
  
  // Private method called resest that clears all internal data
  //
  bool reset();

};

// End of Include file
//
#endif

  


