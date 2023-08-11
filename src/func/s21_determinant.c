#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || result == NULL) {
    return 1;
  }

  if (A->rows != A->columns) {
    return 2;
  }

  int n = A->rows;

  if (n == 1) {
    *result = A->matrix[0][0];
    return 0;
  }

  *result = 0.0;
  for (int j = 0; j < n; j++) {
    double minor_val;
    int ret = s21_minor(A, 0, j, &minor_val);
    if (ret != 0) {
      return ret;
    }

    *result += A->matrix[0][j] * ((0 + j) % 2 == 0 ? minor_val : -minor_val);
  }

  return 0;
}
