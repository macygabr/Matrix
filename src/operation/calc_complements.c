#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!is_correct_matrix(A) || !is_correct_matrix(result))
    return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  matrix_t minor = {0};
  double determinant = 0;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      get_minor(A, &minor, i, j);
      s21_determinant(&minor, &determinant);
      result->matrix[i][j] = pow(-1, i + j) * determinant;
    }
  }

  if (A->rows == 1 && A->columns == 1) result->matrix[0][0] = A->matrix[0][0];
  s21_remove_matrix(&minor);
  return 0;
}