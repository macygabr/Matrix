#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!is_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  int flag = 2;
  double det = 0.0;
  s21_determinant(A, &det);
  if (det) {
    matrix_t tmp_calc = {0};
    flag = s21_calc_complements(A, &tmp_calc);
    if (flag == 0) {
      matrix_t tmp_trans = {0};
      flag = s21_transpose(&tmp_calc, &tmp_trans);
      if (flag == 0) {
        s21_mult_number(&tmp_trans, 1 / det, result);
      }
      s21_remove_matrix(&tmp_trans);
    }
    s21_remove_matrix(&tmp_calc);
  }

  if (A->rows == 1) {
    flag = s21_create_matrix(A->rows, A->rows, result);
    if (flag == 0) result->matrix[0][0] = 1.0 / A->matrix[0][0];
  }
  return flag;
}