//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef MIDTERN_REVIEW2_ITERATORPATTERN_H
#define MIDTERN_REVIEW2_ITERATORPATTERN_H

#include <iostream>
using std::cout, std::cin, std::endl;

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
ArrayIterator<Item>::ArrayIterator (const Item* aArray): _size(20), _array(aArray), _current(0) {
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
    if (IsDone()){
        cout << "end iterator" << std::endl;
        return -1;
    }
    return _array[_current];
}

void use_iterator_pattern();


#endif //MIDTERN_REVIEW2_ITERATORPATTERN_H
