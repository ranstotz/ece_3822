#include <iostream>
#include "example.h"

// Define constant
//
#define NSIZE 256

int main(int argc, char** argv) {

  // Declare an array that holds the three strings that will be read from
  // argv[1]
  //
  char** myarray = new char*[3];

  // Open the file from argv[1] in read mode
  //
  FILE *fp;
  fp = fopen(argv[1], "r");

  // Create a buffer char array to store the strings in the text file
  //
  char buffer[NSIZE];

  // Temp counter to note lines read
  //
  int lineIndex = 0;

  while (EOF != fscanf(fp, "%255[^\n]\n", buffer)) {

    // Store contents of buffer to myarray
    // First allocate memory to store the string pluss a null char
    //
    myarray[lineIndex] = new char[strlen(buffer) + 1];

    // Copy the buffer string into the newly allocated memory
    //
    strcpy(myarray[lineIndex], buffer);

    // Test print statements
    //
    //    fprintf(stdout, "%d: %s. strlen: %d\n", lineIndex, buffer, strlen(buffer));
    fprintf(stdout, "contents of myarray at index %d is: %s\n", lineIndex, myarray[lineIndex]);
    lineIndex ++;
  }

  // Close the file
  //
  fclose(fp);

  // Declare object (mylist) from class List
  //
  List mylist;

  // Append nodes to the linked list and print them as a demonstration
  //
  mylist.Append(myarray[0]);
  mylist.Print();
  mylist.Append(myarray[1]);
  mylist.Print();
  mylist.Append(myarray[2]);
  mylist.Print();

  // Then delete all the nodes from the list and print as a demonstration
  //
  mylist.Delete(myarray[2]);
  mylist.Print();
  mylist.Delete(myarray[1]);
  mylist.Print();
  mylist.Delete(myarray[0]);
  mylist.Print();

  // Deallocate memory
  //
  delete [] myarray;
  
  // Exit gracefully
  //
  return (0);
}
