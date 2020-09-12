#include <iostream>
#include <stdexcept>
#include <string>
#include "matrix_helper.h"
// no other includes are allowed

using std::cout, std::endl;
using std::invalid_argument;
using std::to_string;
using std::size_t;
using std::ostream;

/*
dynamically allocates a new rows x cols matrix
initialize all elements to 0
*/
Matrix create_matrix(size_t rows, size_t cols) {
  // TODO
  int** A = new int*[rows];
  for (size_t i = 0; i < rows; i++) {
    A[i] = new int[cols]{0};
  }
  return A;
}

// overload to create square matrices
// initialize all elements to 0
Matrix create_matrix(size_t n) {
  // TODO
  int** B = new int*[n];
  for (size_t i = 0; i < n; i++) {
    B[i] = new int[n]{0};
  }
  return B;
}

/*
given matrices A, B
horizontally concatenate B onto A
updates and returns A, frees B
e.g.
A = [1 2 ; 3 4]
  1 2
  3 4

B = [5 6 7 ; 8 9 10]
  5  6  7
  8  9 10
  
horzcat(A, B)
  1  2  5  6  7
  3  4  8  9 10

A
  1  2  5  6  7
  3  4  8  9 10
  
B
  []
*/
Matrix& horzcat(Matrix& A, 
                size_t& rows_A, 
                size_t& cols_A, 
                Matrix& B,
                size_t& rows_B, 
                size_t& cols_B) {
  // TODO
  if (rows_A != rows_B) {
    throw invalid_argument("");
    return A;
  }
  Matrix C = create_matrix(rows_A, cols_A+cols_B);
  for (size_t i = 0; i < rows_A; i++) {
    for (size_t j = 0; j < cols_A+cols_B; j++) {
      if (j < cols_A) {
        C[i][j] = A[i][j];
      }
      else {
        C[i][j] = B[i][j-cols_A];
      }
      
    }
  }
  A = C;
  cols_A = cols_A + cols_B;
  rows_B = 0;
  cols_B = 0;
  for (size_t i = 0; i < rows_A; i++) {
    B[i] = nullptr;
  }
  B = nullptr;
  return A;
}

int main() {
  // A = [1 2 ; 3 4]
  Matrix A = create_matrix(2);
  size_t rows_A = 2;
  size_t cols_A = 2;
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;
  print_matrix(A, rows_A, cols_A);
  
  // B = [5 6 7 ; 8 9 10]
  Matrix B = create_matrix(2,3);
  size_t rows_B = 2;
  size_t cols_B = 3;
  B[0][0] = 5;
  B[0][1] = 6;
  B[0][2] = 7;
  B[1][0] = 8;
  B[1][1] = 9;
  B[1][2] = 10;
  print_matrix(B, rows_B, cols_B);

  // horzcat(A, B)
  print_matrix(horzcat(A, rows_A, cols_A, B, rows_B, cols_B), rows_A, cols_A);

  // A
  print_matrix(A, rows_A, cols_A);
  
  // B
  print_matrix(B, rows_B, cols_B);
  
  // do you hear a leak?
  for (size_t i = 0; i < rows_A; i++) {
    delete[] A[i];
    delete[] B[i];
  }
  delete[] A;
  delete[] B;
  return 0;
}
