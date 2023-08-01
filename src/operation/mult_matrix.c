#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return 0;
}
