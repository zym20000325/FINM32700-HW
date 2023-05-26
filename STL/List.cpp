//
// Created by Yumeng Zhang on 4/5/23.
//

#include "List.h"

void List(){

    // instantiate an empty list
    list <int> linkInts;

    // instantiate a list with 10 integers
    list<int> listWith10Integers(10);

    // instantiate a list with 10 integers, each value 99
    list<int> listWith10IntegerEach99 (10, 99);

    // create an exact copy of an existing list
    list<int> listCopyAnother(listWith10IntegerEach99);

    // a vector with 10 integers, each 2017
    vector<int> vecIntegers(10, 2017);

    // instantiate a list using values from another container
    list<int> listContainsCopyOfAnother(vecIntegers.cbegin(),vecIntegers.cend());

    DisplayContents(listWith10IntegerEach99);

    listWith10IntegerEach99.push_front(12);
    listWith10IntegerEach99.push_front(15);
    DisplayContents(listWith10IntegerEach99);

    listWith10IntegerEach99.reverse();
    DisplayContents(listWith10IntegerEach99);

    listWith10IntegerEach99.sort();
    DisplayContents(listWith10IntegerEach99);

    listWith10IntegerEach99.insert(listWith10IntegerEach99.begin(),3 ,4);
    DisplayContents(listWith10IntegerEach99);

    vector<int> v1;

    for(int k=0; k<10; ++k){
        v1.push_back(k);
    }

    for (vector<int>::iterator it = v1.begin(); it!=v1.end(); ++it){
        cout << *it << endl;
    }

    for (auto &it: v1){
        cout << it << endl;
    }
}