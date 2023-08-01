#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!is_correct_matrix(A) || !is_correct_matrix(result))
    return INCORRECT_MATRIX;
  if (A->rows != result->columns || A->columns != result->rows)
    return CALCULATION_ERROR;

  for (int i = 0; i < result->rows; i++)
    for (int j = 0; j < result->columns; j++)
      result->matrix[i][j] = A->matrix[j][i];

  return 0;
}