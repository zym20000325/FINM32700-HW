//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_QUIZ23_H
#define QUIZ_QUIZ23_H

#include <iostream>
using std::cout, std::cin, std::endl;

#include <cstddef>

template <typename T>
size_t mySizeof(const T& type) {
    return (size_t)(char*)(&type + 1) - (size_t)(char*)(&type);
}

void quiz_23(){
    int i = 5;
    size_t size1 = sizeof(i);
    size_t size2 = (size_t)(char*)(&i + 1) - (size_t)(char*)(&i);

    cout << "Size of int: " << size1 << endl;
    cout << "Size of int (using mySizeof function): " << size2 << endl;
}

#endif //QUIZ_QUIZ23_H
