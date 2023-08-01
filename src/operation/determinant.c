#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_determinant(matrix_t *A, double *result) {
  if (result) *result = 0.0;
  if (!is_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;
  *result = s21_get_determinant(A);

  return 0;
}
