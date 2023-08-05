#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (A == NULL || B == NULL || result == NULL) {
        return 1;
    }
    
    if (A->rows != B->rows || A->columns != B->columns) {
        return 2;
    }

    if (s21_create_matrix(A->rows, A->columns, result) != 0) {
        return 1;
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }

    return 0;
}