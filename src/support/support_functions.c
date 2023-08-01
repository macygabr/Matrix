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

void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}

double s21_get_determinant(matrix_t *A) {
  double flag = 0.0;

  if (A->rows == 1) {
    flag = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_get_matrix(0, i, A, &tmp);
      if (i % 2) {
        flag -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        flag += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return flag;
}

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}