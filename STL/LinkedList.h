//
// Created by Yumeng Zhang on 4/14/23.
//

#ifndef STL_LINKEDLIST_H
#define STL_LINKEDLIST_H

#include <iostream>
using std::cout, std::endl;

struct node{

    int number;
    struct node* next;

    node(int n): number(n), next(nullptr) {}
};

void linked_list();


#endif //STL_LINKEDLIST_H
