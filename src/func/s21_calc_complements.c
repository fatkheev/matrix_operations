#include "../s21_matrix.h"

int s21_minor(matrix_t *A, int row, int col, double *result) {
  int return_code = 0;
  int should_continue = 1;

  if (A == NULL || result == NULL || A->rows != A->columns) {
    return_code = 1;
    should_continue = 0;
  }

  if (should_continue && A->rows == 1) {
    *result = 1.0;
    should_continue = 0;
  }

  matrix_t minor_matrix;
  if (should_continue &&
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix) != 0) {
    return_code = 1;
    should_continue = 0;
  }

  if (should_continue) {
    int m_i = 0;
    for (int i = 0; i < A->rows && should_continue; i++) {
      if (i == row) continue;

      int m_j = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j == col) continue;

        minor_matrix.matrix[m_i][m_j] = A->matrix[i][j];
        m_j++;
      }
      m_i++;
    }

    if (s21_determinant(&minor_matrix, result) != 0) {
      return_code = 1;
    }

    s21_remove_matrix(&minor_matrix);
  }

  return return_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code = 0;

  if (A == NULL || result == NULL) {
    return_code = 1;
  } else if (A->rows != A->columns) {
    return_code = 2;
  } else if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    return_code = 1;
  }

  if (return_code == 0) {
    int n = A->rows;
    int i = 0;
    int exit_flag = 0;
    while (i < n && exit_flag != 1) {
      int j = 0;
      while (j < n && exit_flag != 1) {
        double minor_val;
        if (s21_minor(A, i, j, &minor_val) != 0) {
          return_code = 1;
          exit_flag = 1;
        } else {
          result->matrix[i][j] = ((i + j) % 2 == 0) ? minor_val : -minor_val;
        }
        j++;
      }
      i++;
    }
  }

  return return_code;
}
