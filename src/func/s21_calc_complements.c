#include "../s21_matrix.h"

int s21_minor(matrix_t *A, int row, int col, double *result) {
    if (A == NULL || result == NULL || A->rows != A->columns) {
        return 1;
    }

    int n = A->rows;
    if (n == 1) {
        *result = 1.0;
        return 0;
    }

    matrix_t minor_matrix;
    if (s21_create_matrix(n - 1, n - 1, &minor_matrix) != 0) {
        return 1;
    }

    for (int i = 0, m_i = 0; i < n; i++) {
        if (i == row) continue;
        for (int j = 0, m_j = 0; j < n; j++) {
            if (j == col) continue;
            minor_matrix.matrix[m_i][m_j] = A->matrix[i][j];
            m_j++;
        }
        m_i++;
    }

    int status = s21_determinant(&minor_matrix, result);
    s21_remove_matrix(&minor_matrix);
    return status;
}


int s21_calc_complements(matrix_t *A, matrix_t *result) {
    if (A == NULL || result == NULL) {
        return 1;
    }

    if (A->rows != A->columns) {
        return 2;
    }

    int n = A->rows;
    if (s21_create_matrix(n, n, result) != 0) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double minor_val;
            if (s21_minor(A, i, j, &minor_val) != 0) {
                return 1;
            }
            result->matrix[i][j] = (i + j) % 2 == 0 ? minor_val : -minor_val;
        }
    }
    return 0;
}