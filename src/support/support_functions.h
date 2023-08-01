#ifndef PRINT_MATRIX
#define PRINT_MATRIX

#include "../s21_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define EPS 1e-7

int is_null(const void *ptr);
int is_correct_matrix(const matrix_t *A);
int is_correct_sizes(int rows, int columns);
int is_square(const matrix_t *matrix) ;
int get_minor(matrix_t *A, matrix_t *result, int row, int colum);
int is_eq_size(const matrix_t *A, const matrix_t *B);
#endif