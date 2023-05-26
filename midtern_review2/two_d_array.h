//
// Created by Yumeng Zhang on 5/3/23.
//

#ifndef MIDTERN_REVIEW2_TWO_D_ARRAY_H
#define MIDTERN_REVIEW2_TWO_D_ARRAY_H


#include <iostream>
using std::cout, std::cin, std::endl;

void allocate_matrix(double **a, int rows, int columns);

void display_matrix(double *a);

void display_matrix_3(double (*c)[3]);

void initialize_a(double *a, int rows, int columns);

void initialize_b(double *a, int rows, int columns);

void initialize_c(double *a, int rows, int columns);

void product_sum(double (*a)[3], double *b,  double *c);

void display_vector(double *c, int size);

int* makeZeroedArray(int n);

void reallocateArray(int*& A, int oldSize, int newSize);

void use_2d_array();


#endif //MIDTERN_REVIEW2_TWO_D_ARRAY_H
