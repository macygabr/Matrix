#include "support_functions.h"

#include "math.h"

int is_null(const void *ptr) { return ptr ? 0 : 1; }
int is_correct_sizes(int rows, int columns) { return rows > 0 && columns > 0; }

int is_square(const matrix_t *matrix) {
  return matrix->rows == matrix->columns;
}

int is_correct_matrix(const matrix_t *A) {
  return !is_null(A) && !is_null(A->matrix) &&
         is_correct_sizes(A->rows, A->columns);
}
int is_eq_size(const matrix_t *A, const matrix_t *B) {
  return !is_null(A) && !is_null(B) && A->rows == B->rows &&
         A->columns == B->columns;
}

int get_minor(matrix_t *A, matrix_t *result, int row, int colum) {
  for (int i = 0, m = 0, n = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (i != row && j != colum) {
        result->matrix[m][n] = A->matrix[i][j];
        if (n == result->columns - 1) {
          m++;
          n = 0;
        } else
          n++;
      }

  return 0;
}
