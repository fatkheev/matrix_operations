#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
        return 1;
    }

    if (A->rows != A->columns) {
        return 2;
    }

    int n = A->rows;

    double det;
    if (s21_determinant(A, &det) != 0 || det == 0.0) {
        return 2;
    }

    matrix_t complements;
    if (s21_create_matrix(n, n, &complements) != 0) {
        return 1;
    }

    if (s21_calc_complements(A, &complements) != 0) {
        s21_remove_matrix(&complements);
        return 1;
    }

    matrix_t transposed_complements;
    if (s21_create_matrix(n, n, &transposed_complements) != 0) {
        s21_remove_matrix(&complements);
        return 1;
    }

    if (s21_transpose(&complements, &transposed_complements) != 0) {
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transposed_complements);
        return 1;
    }

    if (s21_mult_number(&transposed_complements, 1.0 / det, result) != 0) {
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transposed_complements);
        return 1;
    }

    s21_remove_matrix(&complements);
    s21_remove_matrix(&transposed_complements);

    return 0;
}
