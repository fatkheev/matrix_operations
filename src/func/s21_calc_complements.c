#include "../s21_matrix.h"

int s21_minor(matrix_t *A, int row, int col, double *result) {
  int return_code = 0;

  if (A == NULL || result == NULL || A->rows != A->columns) return 1;
  if (A->rows == 1) {
    *result = 1.0;
    return 0;
  }

  matrix_t minor_matrix;
  if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix) != 0)
    return 1;

  int m_i = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;

    int m_j = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;

      minor_matrix.matrix[m_i][m_j] = A->matrix[i][j];
      m_j++;
    }
    m_i++;
  }

  return_code = s21_determinant(&minor_matrix, result);
  s21_remove_matrix(&minor_matrix);

  return return_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code = 0;

  // Первый уровень проверок
  if (A == NULL || result == NULL) {
    return_code = 1;
  } else if (A->rows != A->columns) {
    return_code = 2;
  } else if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    return_code = 1;
  }

  // Если все первоначальные проверки пройдены успешно
  if (return_code == 0) {
    int n = A->rows;
    int i = 0;
    int exit_flag = 0;  // Флаг для пропуска итераций
    while (i < n && exit_flag != 1) {
      int j = 0;
      while (j < n && exit_flag != 1) {
        double minor_val;
        if (s21_minor(A, i, j, &minor_val) != 0) {
          return_code = 1;
          exit_flag = 1;  // Пропускаем все последующие итерации
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
