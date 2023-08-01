#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) return INCORRECT_MATRIX;
  if (!is_eq_size(A, B)) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
        res = FAILURE;
        j = A->columns;
        i = A->rows;
      }
    }
  }
  return res;
}