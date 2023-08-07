#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result)
{
  int return_code = 0;

  if (rows < 1 || columns < 1 || result == NULL) {
    return_code = 1;
  }
  else {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)malloc(rows * sizeof(double *));

    if (!result->matrix) {
      return_code = 2;
    }
    else {
      for (int i = 0; i < rows && return_code == 0; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));

        if (!result->matrix[i]) {
          return_code = 2;
        }
        else {
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = 0.0;
          }
        }
      }
    }
  }
  
  return return_code;
}