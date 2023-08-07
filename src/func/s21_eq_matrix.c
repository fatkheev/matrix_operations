#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 1;

  if (A == NULL || B == NULL) {
    result = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    result = 0;
  } else {
    for (int i = 0; i < A->rows && result == 1; i++) {
      for (int j = 0; j < A->columns && result == 1; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
          result = 0;
        }
      }
    }
  }

  return result;
}