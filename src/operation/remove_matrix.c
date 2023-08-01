#include "../s21_matrix.h"
#include "../support/support_functions.h"

void s21_remove_matrix(matrix_t *const A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
  }
  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}
