#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* Write a simple C program that creates a char** array that holds the following three strings: “Mary”, “Joe”, and “Susan”. The arrays must be allocated to hold only the space required to store these strings. The program must allocate and deallocate memory. Draw a picture explaining how the char** ‘data structure’ is organized in memory. Be very specific and use the actual memory locations used in your program. Show that when the program is ready to exit, memory is properly cleaned up (there are no memory leaks). Show exactly where the three strings reside in memory. */

int main(int argc, char** argv) {

  // Declare char** array that holds three strings declared below
  //
  char** myarray = new char*[3];

  // Declare three strings containing the following: "Mary", "Joe", "Susan"
  //
  char mchararray[] = "Mary";
  char jchararray[] = "Joe";
  char schararray[] = "Susan";

  // Allocate space and store the length of the char strings in each argument
  // in each index of myarray plus a null character.
  //
  myarray[0] = new char[strlen(mchararray) + 1];
  myarray[1] = new char[strlen(jchararray) + 1];
  myarray[2] = new char[strlen(schararray) + 1];

  // Copy string into newly allocated memory
  //
  strcpy(myarray[0], mchararray);
  strcpy(myarray[1], jchararray);
  strcpy(myarray[2], schararray);
  
  // Test print the array indices
  //
  //  fprintf(stdout, "String at index 0 is: %s\n", myarray[0]);
  //  fprintf(stdout, "String at index 1 is: %s\n", myarray[0]);
  //  fprintf(stdout, "String at index 2 is: %s\n", myarray[2]);

  // Print the memory addresses of the original arrays
  //
  fprintf(stdout, "mchararray is at address: %d\n", &mchararray);
  fprintf(stdout, "jchararray is at address: %d\n", &jchararray);
  fprintf(stdout, "schararray is at address: %d\n\n", &schararray);

  // Print memory address of myarray indices
  //
  fprintf(stdout, "myarray is at address: %d\n", **&myarray);
  fprintf(stdout, "index 0 of myarray is at address: %d\n",  &myarray[0]);
  fprintf(stdout, "index 1 of myarray is at address: %d\n",  &myarray[1]);
  fprintf(stdout, "index 2 of myarray is at address: %d\n\n",  &myarray[2]);

  // Print size of memory at myarray indices to confirm proper allocation
  //
  fprintf(stdout, "Size of array[0] = %d\n", sizeof(myarray[0]));
  fprintf(stdout, "Size of array[1] = %d\n", sizeof(myarray[1]));
  fprintf(stdout, "Size of array[2] = %d\n", sizeof(myarray[2]));
  
  // Deallocate memory for myarray
  //
  delete [] myarray;

  // Exit gracefully
  //
  return (0);
}

