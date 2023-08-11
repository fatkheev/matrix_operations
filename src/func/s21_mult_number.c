#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = 0;

  if (A == NULL || result == NULL) {
    return_code = 1;
  } else if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    return_code = 1;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return return_code;
}