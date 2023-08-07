#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int return_code = 0;
    
    if (A == NULL || B == NULL || result == NULL) {
        return_code = 1;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        return_code = 2;
    } else if (s21_create_matrix(A->rows, A->columns, result) != 0) {
        return_code = 1;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }

    return return_code;
}