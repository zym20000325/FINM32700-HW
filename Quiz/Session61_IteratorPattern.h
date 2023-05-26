//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION61_ITERATORPATTERN_H
#define QUIZ_SESSION61_ITERATORPATTERN_H

#include <iostream>

using namespace std;

template <class Item>
class Iterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Item CurrentItem() const = 0;
protected:
    Iterator(){};
};

template <class Item>
class ArrayIterator: public Iterator<Item> {
public:
    ArrayIterator (const Item* aArray);
    void First();
    void Next();
    bool IsDone() const;
    Item CurrentItem() const;

private:
    const long _size;
    const Item* _array;
    long _current;
};

template <class Item>
ArrayIterator<Item>::ArrayIterator (
        const Item* aArray
) : _size(20), _array(aArray), _current(0) {
}


template <class Item>
void ArrayIterator<Item>::First() {
    _current = 0;
}


template <class Item>
void ArrayIterator<Item>::Next() {
    _current++;
}

template <class Item>
bool ArrayIterator<Item>::IsDone() const {
    return _current >= _size;
}


template <class Item>
Item ArrayIterator<Item>::CurrentItem() const {
    if (IsDone())
        std::cout << "end iterator" << std::endl;
    return _array[_current];
}


void session_61(){

    int tab[20];
    for(int k=0;k<20;k++)
        tab[k]=k;

    ArrayIterator<int> it(tab);
    for(int k=0;k<21;k++){
        cout << it.CurrentItem() << endl;
        it.Next();
    }
}

#endif //QUIZ_SESSION61_ITERATORPATTERN_H
