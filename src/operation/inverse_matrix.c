#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (!is_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  double determinant = 0;
  if (s21_determinant(A, &determinant) == OK && determinant != 0) {
    matrix_t temp = {0};
    s21_create_matrix(A->rows, A->columns, &temp);
    s21_calc_complements(A, &temp);
    s21_transpose(&temp, result);
    code = s21_mult_number(result, 1 / determinant, result);
    s21_remove_matrix(&temp);
  } else
    code = CALCULATION_ERROR;

  return code;
}
