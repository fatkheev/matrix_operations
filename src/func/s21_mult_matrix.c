#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = 0;

  if (A == NULL || B == NULL || result == NULL || A->columns != B->rows) {
    return_code = (A == NULL || B == NULL || result == NULL) ? 1 : 2;
  } else if (s21_create_matrix(A->rows, B->columns, result) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    return_code = 1;
  }

  return return_code;
}