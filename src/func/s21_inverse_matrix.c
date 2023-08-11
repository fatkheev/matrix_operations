#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 1;

  if (A != NULL && A->matrix != NULL && A->rows >= 1 && A->columns >= 1) {
    res = 2;
    double det = 0.0;
    s21_determinant(A, &det);
    if (fabs(det - 0) > 1e-7) {
      matrix_t temp;
      res = s21_calc_complements(A, &temp);
      if (res == 0) {
        matrix_t trans;
        res = s21_transpose(&temp, &trans);
        if (res == 0) {
          s21_mult_number(&trans, 1 / det, result);
        }
        s21_remove_matrix(&trans);
      }
      s21_remove_matrix(&temp);
    }
  }

  return res;
}