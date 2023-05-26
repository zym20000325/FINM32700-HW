//
// Created by Yumeng Zhang on 5/3/23.
//

#include "two_d_array.h"

void allocate_matrix(double **a, int rows, int columns){
    // You need to do the dynamic allocation on the heap

    *a = new double[rows*columns];
}

void display_matrix(double *a){

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i*3+j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void display_matrix_3(double (*c)[3]){

    for (int i=0; i<3;i++) {
        for (int k = 0; k < 3; k++){
            cout << c[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initialize_a(double *a, int rows, int columns){
    //You need to initialize a
    /* We want a to look like the following
    *      1  2  3
    * a =  1  1  1
    *      1  1  1
    */

    display_matrix(a);

//    double (*twod_array)[3] = (double (*)[3]) a;    // C-style
    double (*twod_array)[3] = reinterpret_cast<double (*)[3]>(a);

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){

            if (i==0){
                twod_array[i][j] = j+1;
            }
            else{
                twod_array[i][j] = 1;
            }
        }
    }

    display_matrix_3(twod_array);
}

void initialize_b(double *a, int rows, int columns){
    //You need to initialize b
    /* We want b to look like the following
    * b =  1  1  1
    */

    for (int i = 0; i < columns; ++i){
        a[i] = 1;
    }
}

void initialize_c(double *a, int rows, int columns){
    //You need to initialize c
    /* We want c to look like the following
    * c =  0 0 0
    */

    for (int i = 0; i < columns; ++i){
        a[i] = 0;
    }
}


void product_sum(double (*a)[3], double *b,  double *c){
    /* We want a vector s.t.
    * c = b * a + b
    */

    for (int i = 0; i < 3; i++) {
        c[i] = b[i];

        for (int j = 0; j < 3; j++) {
//            cout << i << " " << j << endl;
//            cout << a[j][i] << endl;
            c[i] += b[j] * a[j][i];
        }
    }
}

void display_vector(double *c, int size){

    for (int i=0; i<size;i++) {
        cout << c[i] << " ";
    }
}

// makeZeroedArray(n) returns an array with
// n items, all set to 0.

int* makeZeroedArray(int n){

    int* A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = 0;
    }
    return A;
}

void reallocateArray(int*& A, int oldSize, int newSize){

//    The *& in the function parameter is a reference to a pointer,
//    which allows the function to modify the original pointer passed to it.

    int* Anew = new int[newSize];
    int n = std::min(oldSize, newSize);

    for(int i = 0; i < n; i++){
        Anew[i] = A[i];
    }
    delete [] A;

    A = Anew;
}

void use_2d_array(){
    double* matA = nullptr;
    allocate_matrix(&matA,3,3);
    display_matrix(matA);
    initialize_a(matA, 3, 3);
    display_matrix(matA);

    double* vecB = nullptr;
    allocate_matrix(&vecB,3,3);
    initialize_b(vecB, 1, 3);

    double* vecC = nullptr;
    allocate_matrix(&vecC,3,3);
    initialize_b(vecC, 1, 3);

    product_sum((double(*)[3])matA, vecB, vecC);
    display_vector(vecC, 3);


    int* array = new int[5];

    int** a2d = new int* [5];
    for (int i = 0; i<5; ++i){
        a2d[i] = new int[5];
    }

    a2d[0][0] = 1;

    delete[] a2d;

    int* A = new int[5];
    reallocateArray(A, 5, 10);

    int* A2 = makeZeroedArray(5);
    reallocateArray(A2, 5, 10);

    //    double* grid = new double[5*10];

    //    int*** a3d = new int** [5];
    //    for (int i = 0; i<5; ++i){
    //        a3d[i] = new int* [5];
    //        for (int j = 0; j<5; ++j){
    //            int** ptr = a3d[i];
    //            ptr[j] = new int[5];
    //        }
    //    }
    //    a3d[0][0][0] = 1;
    //    delete[] a3d;
}

