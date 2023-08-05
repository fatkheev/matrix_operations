#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    if (A == NULL || result == NULL) {
        return 1; // Ошибка, матрица или результат являются NULL
    }

    if (A->rows != A->columns) {
        return 2; // Ошибка, некорректная матрица (не квадратная)
    }

    int n = A->rows;
    matrix_t temp_matrix;
    if (s21_create_matrix(n, n, &temp_matrix) != 0) {
        return 1; // Ошибка создания матрицы
    }

    // Копирование матрицы A в temp_matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp_matrix.matrix[i][j] = A->matrix[i][j];
        }
    }

    // Вычисление определителя temp_matrix методом Гаусса
    *result = 1.0;
    for (int i = 0; i < n; i++) {
        if (temp_matrix.matrix[i][i] == 0) {
            int swap_row = -1;
            for (int k = i + 1; k < n; k++) {
                if (temp_matrix.matrix[k][i] != 0) {
                    swap_row = k;
                    break;
                }
            }
            if (swap_row == -1) {
                *result = 0.0;
                break;
            }
            for (int j = 0; j < n; j++) {
                double temp = temp_matrix.matrix[i][j];
                temp_matrix.matrix[i][j] = temp_matrix.matrix[swap_row][j];
                temp_matrix.matrix[swap_row][j] = temp;
            }
            *result *= -1.0; // изменение знака определителя при перестановке строк
        }
        for (int k = i + 1; k < n; k++) {
            double factor = temp_matrix.matrix[k][i] / temp_matrix.matrix[i][i];
            for (int j = i; j < n; j++) {
                temp_matrix.matrix[k][j] -= factor * temp_matrix.matrix[i][j];
            }
        }
        *result *= temp_matrix.matrix[i][i];
    }

    s21_remove_matrix(&temp_matrix);
    return 0;
}