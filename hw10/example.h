// Make sure definitions are only made once
//
#ifndef EXAMPLE_H
#define EXAMPLE_H

// System include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

// Declare class definitions for HW 10

// Create function template to pass data type as a parameter so we can store
// different types of elements to matrices
//
template<typename T>
// Create a sparse matrix for all any row/column selection
//
class SparseMatrix {
public:
  // Constructor for the sparse matrix
  //
  SparseMatrix(int rows, int columns);

  // Copy constructor
  //
  SparseMatrix(const SparseMatrix<T> & m);

  // Operator overload (=)
  //
  SparseMatrix<T> & operator = (const SparseMatrix<T> & m);
  
  // Destructor
  //
  ~SparseMatrix(void);

  // Getters and Setters
  //
  int getRowCount(void) const;
  int getColumnCount(void) const;

  // Values
  //
  T get(int row, int col) const;
  SparseMatrix & set(T val, int row, int col);

  // Operators
  //
  SparseMatrix<T> add(const SparseMatrix<T> & m) const;
  SparseMatrix<T> operator + (const SparseMatrix<T> & m) const;

  // Resize
  //
  void resize(int row, int col);

  // Debug
  //
  void debug(int rrow, int ccol);
  
  /*
  // Operator overloading
  // Parentheses
  //
  SparseMatrix<T> parentheses(int row, int column) const;
 
  SparseMatrix<T> operator()(int row, int col) const;
  */
  // Protected
  //
protected:
  int m, n;

  vector<T> *vals;
  vector<int> *rows, *cols;

  // Additional methods
  //
  void construct(int m, int n);
  void destruct(void);
  void deepCopy(const SparseMatrix<T> & m);
  void validateCoordinates(int row, int col) const;
  void insert(int index, int row, int col, T val);
  void remove(int index, int row);

};

// End of Include file
//
#endif
