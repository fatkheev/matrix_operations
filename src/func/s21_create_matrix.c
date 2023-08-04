#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result)
{
  if (rows < 1 || columns < 1) {
    return 1;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (!result->matrix) {
    return 2;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
    if (!result->matrix[i]) {
      return 2;
    }

    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }

  return 0;
}