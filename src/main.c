#include "s21_matrix.h"

int main() {
  matrix_t my_matrix;

  int result = s21_create_matrix(5, 5, &my_matrix);
  if (result != 0) {
    printf("Ошибка создания матрицы. Код ошибки: %d\n", result);
    return result;
  }

  printf("Матрица успешно создана.\n");
  printf("Строк: %d\n", my_matrix.rows);
  printf("Столбцов: %d\n", my_matrix.columns);

  for (int i = 0; i < my_matrix.rows; i++) {
    for (int j = 0; j < my_matrix.columns; j++) {
      printf("%.2f ", my_matrix.matrix[i][j]);
    }
    printf("\n");
  }

  // Не забудьте освободить память
  for (int i = 0; i < my_matrix.rows; i++) {
    free(my_matrix.matrix[i]);
  }
  free(my_matrix.matrix);

  return 0;
}