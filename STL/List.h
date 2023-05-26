//
// Created by Yumeng Zhang on 4/5/23.
//

#ifndef STL_LIST_H
#define STL_LIST_H

#include <list>
#include <vector>
#include <iostream>
#include <forward_list>

using std::cout, std::endl;
using std::vector;
using std::list;

template <typename T>
void DisplayContents (const T& container){

    for (auto element = container.cbegin();element != container.cend(); ++element){
        cout << *element << ' ';
    }
    cout << endl;
}

void List();

#endif //STL_LIST_H
