#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (!is_eq_size(A, B)) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((A->matrix[i][j] - B->matrix[i][j]) >= EPS ||
          (B->matrix[i][j] - A->matrix[i][j]) >= EPS) {
        res = FAILURE;
        j = A->columns;
        i = A->rows;
      }
    }
  }
  return res;
}