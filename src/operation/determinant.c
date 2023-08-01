#include "../s21_matrix.h"
#include "../support/support_functions.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!is_correct_matrix(A)) return INCORRECT_MATRIX;
  if (!is_square(A)) return CALCULATION_ERROR;

  *result = 1;
  matrix_t triangle = {0};
  s21_create_matrix(A->rows, A->columns, &triangle);

  for (int i = 0; i < triangle.rows; i++)
    for (int j = 0; j < triangle.columns; j++)
      triangle.matrix[i][j] = A->matrix[i][j];

  for (int i = 0; i < triangle.rows; i++) {
    int hook = i;
    for (int j = i + 1; j < triangle.rows; j++)
      if (triangle.matrix[j][i] > triangle.matrix[hook][i]) hook = j;
    if (hook != i) {
      *result *= -1;
      for (int j = i; j < triangle.rows; j++) {
        double temp = triangle.matrix[i][j];
        triangle.matrix[i][j] = triangle.matrix[hook][j];
        triangle.matrix[hook][j] = temp;
      }
    }
    if (!triangle.matrix[i][i]) {
      *result = 0;
      i = triangle.rows;
    } else
      *result *= triangle.matrix[i][i];
    for (int j = i + 1; j < triangle.rows; j++) {
      double ratio = triangle.matrix[j][i] / triangle.matrix[i][i];
      for (int k = i; k < triangle.rows; k++)
        triangle.matrix[j][k] -= ratio * triangle.matrix[i][k];
    }
  }
  s21_remove_matrix(&triangle);

  if (A->rows == 1 && A->columns == 1) *result = A->matrix[0][0];

  return 0;
}
