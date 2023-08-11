#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = 0;

  if (A == NULL || B == NULL || result == NULL) {
    return_code = 1;
  } else if (!(A->matrix != NULL && A->rows > 0 && A->columns > 0)) {
    return_code = 2;
  } else if (!(B->matrix != NULL && B->rows > 0 && B->columns > 0)) {
    return_code = 2;
  } else if (A->columns == B->rows) {
    return_code = s21_create_matrix(A->rows, B->columns, result);
    if (return_code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  } else {
    return_code = 2;
  }

  return return_code;
}
