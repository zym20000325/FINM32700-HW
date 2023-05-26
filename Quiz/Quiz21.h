//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_QUIZ21_H
#define QUIZ_QUIZ21_H

#include <iostream>
using std::cout, std::cin, std::endl;

void modify_a(int *a){
    *a = 2;
}

typedef int* int_ptr;
void allocate_matrix_heap(int **ptr_a){
    *ptr_a = new int[10*10];
}

void display_matrix(int(*c)[10]){

    for (int i=0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void quiz_21(){

    int *a;
    allocate_matrix_heap(&a);
    int (*twod_array)[10] = (int (*)[10]) a;

    for(int i = 0; i<10; i++)
        for(int j = 0; j<10; j++){
            twod_array[i][j]=i+j;
        }

    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cout << twod_array[i][j] << " ";
        }
        cout << endl;
    }

    display_matrix(twod_array);
}

#endif //QUIZ_QUIZ21_H
