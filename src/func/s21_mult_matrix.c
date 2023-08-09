#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Если любая из матриц равна NULL, возвращаем ошибку
    if (A == NULL || B == NULL || result == NULL) {
        return 1;
    }

    // Проверка на корректность размеров матрицы A
    if (!(A->matrix != NULL && A->rows > 0 && A->columns > 0)) {
        return 2;
    }

    // Проверка на корректность размеров матрицы B
    if (!(B->matrix != NULL && B->rows > 0 && B->columns > 0)) {
        return 2;
    }

    // Проверка, подходят ли матрицы для умножения
    if (A->columns == B->rows) {
        int err = s21_create_matrix(A->rows, B->columns, result);
        if (err == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    for (int k = 0; k < B->rows; k++) {
                        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                    }
                }
            }
        }
        return err;
    } else {
        return 2;  // Размеры матриц не совпадают для умножения
    }
}
