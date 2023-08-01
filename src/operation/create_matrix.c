#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!is_correct_sizes(rows, columns)) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
      }
    }
  }
  return 0;
}