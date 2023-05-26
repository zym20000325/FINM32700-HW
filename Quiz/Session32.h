//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION32_H
#define QUIZ_SESSION32_H

#include <iostream>
using std::cout, std::endl;

template <typename T>
T add(T n1, T n2){
    return n1+n2;
}

template <typename T>
class my_vector {
    T *tab;
    unsigned int size;
    unsigned int index;

public:
    my_vector(int s):size(s), index(0){
        tab = new T[s];
    }

    void push_back(T s){
        tab[index++]=s;
        if (index>size-1)
        {
            size = size * 2;
            int *newtab = new T[size];
            for (int k=0;k<index;k++)
            {
                newtab[k]=tab[k];
            }
            delete[] tab;
            tab=newtab;
        }
    }

    void display_content(){
        for (int k=0; k<index; k++) {
            cout << tab[k] << " ";
        }
        cout << endl;

    }
};


void session_32(){

    my_vector<int> list_int(3);

    list_int.push_back(2);
    list_int.push_back(3);
    list_int.push_back(4);
    list_int.push_back(5);
    list_int.push_back(6);

    list_int.display_content();
}

#endif //QUIZ_SESSION32_H
