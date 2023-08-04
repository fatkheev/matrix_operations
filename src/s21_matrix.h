#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define NOTCORRECT 1
#define ERROR_CALC 2
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц (create_matrix):
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц (remove_matrix):
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц (eq_matrix):
int s21_eq_matrix(matrix_t *A, matrix_t *B);