// matrix_vertcat.cpp
#include <iostream>
#include <stdexcept>
#include "./matrix.h"

using std::cout, std::endl;
using std::invalid_argument;
using std::size_t;

// vertically concatenate B to A (A on top of B)
// throws an invalid_argument exception on mismatched dimensions
// side effects:
//   A is reallocated to be bigger
Matrix& vertcat(Matrix& A, Matrix const& B) {
  // TODO(student) : vertcat
  if (A.cols != B.cols) {
    throw invalid_argument(" dimension mismatch: ");
    return A;
  }
  int** C = new int*[A.rows+B.rows];
  for (size_t i = 0; i < A.rows+B.rows; i++) {
    C[i] = new int[A.cols]{0};
  }
  for (size_t i = 0; i < A.cols; i++) {
    for (size_t j = 0; j < A.rows+B.rows; j++) {
      if (j < A.rows) {
        C[j][i] = A.data[j][i];
      } else {
        C[j][i] = B.data[j-A.rows][i];
      }
    }
  }
  A.data = C;
  A.rows = A.rows + B.rows;
  return A;
}

Matrix::~Matrix() {
  // TODO(student): destructor
  for (size_t i = 0 ; i < rows; i++) {
    delete[] data[i];
  }
  delete[] data;
} 