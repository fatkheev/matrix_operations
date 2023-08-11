#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_code = 0;
  double local_result = 0.0;

  if (A == NULL || result == NULL) {
    return_code = 1;
  } else if (A->rows != A->columns) {
    return_code = 2;
  } else if (A->rows == 1) {
    local_result = A->matrix[0][0];
  } else {
    for (int j = 0; j < A->rows && return_code == 0; j++) {
      double minor_val;
      if (s21_minor(A, 0, j, &minor_val) != 0) {
        return_code = 1;
      } else {
        local_result +=
            A->matrix[0][j] * ((j % 2 == 0) ? minor_val : -minor_val);
      }
    }
  }

  if (return_code == 0) {
    *result = local_result;
  }

  return return_code;
}
