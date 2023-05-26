//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION1_H
#define QUIZ_SESSION1_H

#include <iostream>

void session_1(){
    int a[2][2];
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("%p ",&a[i][j]);
        }

    }

    int* ptrr = &a[0][0];
    printf("\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("%p ",ptrr+(i*2)+j);
        }
    }
}

#endif //QUIZ_SESSION1_H
