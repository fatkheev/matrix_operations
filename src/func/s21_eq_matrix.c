#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 1;

  if (A->rows != B->rows || A->columns != B->columns) {
    result = 0;
  } else {
    int i = 0;
    int j;
    while (result == 1 && i < A->rows) {
      j = 0;
      while (result == 1 && j < A->columns) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
          result = 0;
        }
        j++;
      }
      i++;
    }
  }

  return result;
}