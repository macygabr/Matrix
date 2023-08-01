#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) return INCORRECT_MATRIX;
  if (!is_eq_size(A, B)) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return 0;
}