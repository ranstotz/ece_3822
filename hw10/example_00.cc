#include "example.h"
#include <vector>
#include <iostream>

using namespace std;

// Implementations of methods
// SparseMatrix construction
//
template<typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns)
{
  this->construct(rows, columns);
}

// Copy constructor implementation
//
template<typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T> & matrix)
{
  this->deepCopy(matrix);
}

// Operator overload (=) implementation
//
template<typename T>
SparseMatrix<T> & SparseMatrix<T>::operator = (const SparseMatrix<T> & matrix)
{
  if (&matrix != this) {
    this->destruct();
    this->deepCopy(matrix);
  }

  return *this;
}

// Deep copy implementation, this allocates space for new vectors, first row, then column
//
template<typename T>
void SparseMatrix<T>::deepCopy(const SparseMatrix<T> & matrix)
{
  this->m = matrix.m;
  this->n = matrix.n;
  this->rows = new vector<int>(*(matrix.rows));

  if (matrix.vals != NULL) {
    this->cols = new vector<int>(*(matrix.cols));
    this->vals = new vector<T>(*(matrix.vals));
  }
}

// Destructor implementation
//
template<typename T>
SparseMatrix<T>::~SparseMatrix(void)
{
  this->destruct();
}

// Constructor implementation, give message to user if rows || cols less than 1.
// Allocate space for rows
//
template<typename T>
void SparseMatrix<T>::construct(int rows, int columns)
{
  if (rows < 1 || columns < 1) {
    fprintf(stdout, "Please ensure rows and columns are greater than 1.\n");
  }

  this->m = rows;
  this->n = columns;

  this->vals = NULL;
  this->cols = NULL;
  this->rows = new vector<int>(rows + 1, 1);
}

// Implement destructor, deletes vals, cols, and rows to prevent memory leaks
//
template<typename T>
void SparseMatrix<T>::destruct(void)
{
  if (this->vals != NULL) {
    delete this->vals;
    delete this->cols;
  }

  delete this->rows;
}

// Implement getters and setters
//
template<typename T>
int SparseMatrix<T>::getRowCount(void) const
{
  return this->m;
}


template<typename T>
int SparseMatrix<T>::getColumnCount(void) const
{
  return this->n;
}

// Return values
// Get
//
template<typename T>
T SparseMatrix<T>::get(int row, int col) const
{
  this->validateCoordinates(row, col);

  int currCol;

  for (int pos = (*(this->rows))[row - 1] - 1; pos < (*(this->rows))[row] - 1; ++pos) {
    currCol = (*(this->cols))[pos];

    if (currCol == col) {
      return (*(this->vals))[pos];

    } else if (currCol > col) {
      break;
    }
  }

  return T();
}

// Set
//
template<typename T>
SparseMatrix<T> & SparseMatrix<T>::set(T val, int row, int col)
{
  this->validateCoordinates(row, col);

  int pos = (*(this->rows))[row - 1] - 1;
  int currCol = 0;

  for (; pos < (*(this->rows))[row] - 1; pos++) {
    currCol = (*(this->cols))[pos];

    if (currCol >= col) {
      break;
    }
  }

  if (currCol != col) {
    if (!(val == T())) {
      this->insert(pos, row, col, val);
    }

  } else if (val == T()) {
    this->remove(pos, row);

  } else {
    (*(this->vals))[pos] = val;
  }

  return *this;
}

// Addition operator implementation
//
template<typename T>
SparseMatrix<T> SparseMatrix<T>::add(const SparseMatrix<T> & m) const
{
  // Provide error message if matrix dimensions don't match
  //
  if (this->m != m.m || this->n != m.n) {
    fprintf(stdout, "Cannot add: matrices dimensions don't match.");
  }

  SparseMatrix<T> result(this->m, this->n);

  // Loop over matrix and add values
  //
   for (int i = 1; i <= this->m; i++) {
    for (int j = 1; j <= this->n; j++) {
      result.set(this->get(i, j) + m.get(i, j), i, j);
    }
  }

  return result;
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator + (const SparseMatrix<T> & m) const
{
  return this->add(m);
}

// Resize
//
template<typename T>
void SparseMatrix<T>::resize(int rrow, int ccol)
{
  // Destruct existing matrix, then construct new with new size
  //
  SparseMatrix<T>::destruct();
  SparseMatrix<T>::construct(rrow, ccol);

  // Loop over size of new matrix and populate matrix with 0's
  //
  for (int i = 0; i < rrow; i++) {
    for (int j = 0; j < ccol; j++) {
        SparseMatrix<T>::set(0, i, j);
    }
  }
}

// Debug
//
template<typename T>
void SparseMatrix<T>::debug(int rrow, int ccol)
{
  float temp = 0.0;
  for (int i = 0; i < rrow; i++) {
    for (int j = 0; j < ccol; j++) {
      temp = get(i, j);

      if (temp > 0) {
	fprintf(stdout, "%lf\n", temp);
      }
    }
  }
}
// Operator overloaders

// Parentheses
//
/*
template<typename T>
SparseMatrix<T> SparseMatrix<T>::parentheses(int row, int column) const
{
  return (float)set(*this, row, column);
}
template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator () (int row, int column) const
{
  return this->parentheses(row, column);
}

*/
// Additional methods
//
template<typename T>
void SparseMatrix<T>::validateCoordinates(int row, int col) const
{
  if (row < 1 || col < 1 || row > this->m || col > this->n) {
    fprintf(stdout, "Coordinates out of range\n");
  }
}


template<typename T>
void SparseMatrix<T>::insert(int index, int row, int col, T val)
{
  if (this->vals == NULL) {
    this->vals = new vector<T>(1, val);
    this->cols = new vector<int>(1, col);

  } else {
    this->vals->insert(this->vals->begin() + index, val);
    this->cols->insert(this->cols->begin() + index, col);
  }

  for (int i = row; i <= this->m; i++) {
    (*(this->rows))[i] += 1;
  }
}


template<typename T>
void SparseMatrix<T>::remove(int index, int row)
{
  this->vals->erase(this->vals->begin() + index);
  this->cols->erase(this->cols->begin() + index);

  for (int i = row; i <= this->m; i++) {
    (*(this->rows))[i] -= 1;
  }
}
