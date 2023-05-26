//
// Created by Yumeng Zhang on 4/5/23.
//

#include "Vector.h"

void DisplayVector(const vector<int>& inVec) {

    for (auto element = inVec.cbegin(); element != inVec.cend(); ++ element)
        cout << *element << ' ';
    cout << endl;
}

void Vector() {

    // vector of integers
    vector<int> i;

    // Instantiate a vector with 10 elements (it can still grow)
    vector<int> tenElements (10);

    // Instantiate a vector with 10 elements, each initialized to 90
    vector<int> tenElemInit (10, 90);

    // Initialize vector to the contents of another
    vector<int> copyVector (tenElemInit);

    // Vector initialized to 5 elements from another using iterators
    vector<int> partialCopy (tenElements.cbegin(), tenElements.cbegin() + 5);

    // Instantiate a vector with 4 elements, each initialized to 90
    vector <int> integers (4, 90);

    cout << "The initial contents of the vector: ";
    DisplayVector(integers);

    // Insert 25 at the beginning
    integers.insert (integers.begin (), 25);

    // Insert 2 numbers of value 45 at the end
    integers.insert (integers.end (), 2, 45);

    cout << "Vector after inserting elements at beginning and end: ";
    DisplayVector(integers);

    // Another vector containing 2 elements of value 30
    vector <int> another (2, 30);

    // Insert two elements from another container in position [1]
    integers.insert (integers.begin () + 1, another.begin (), another.end ());
    cout << "Vector after inserting contents from another vector in the middle: ";
    DisplayVector(integers);
}
