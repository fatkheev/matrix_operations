#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    if (A == NULL || result == NULL) {
        return 1;
    }

    if (s21_create_matrix(A->rows, A->columns, result) != 0) {
        return 1;
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] * number;
        }
    }

    return 0;
}