//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION4_H
#define QUIZ_SESSION4_H

#include <iostream>
using std::cout, std::endl;
using std::ostream;

struct node{
    struct node *next;
    int number;
    node(int n):number(n),next(nullptr){}
};
#include <forward_list>
#include <vector>
#include <map>

class Order2{
    int price;
    int quantity;
public:
    Order2(int p, int q):price(p),quantity(q){}
    ~Order2(){
        cout << "destructor" << endl;
    }
    friend ostream& operator<<(ostream& os, const Order2& o);
};

ostream& operator<<(ostream& os, const Order2& o)
{
    os << "Order(" << o.price << "/" << o.quantity << ")" ;
    return os;
}

template <typename T>
class my_ptr{
    T *ptr;
    int count;
public:
    my_ptr(T * p):ptr(p),count(1){}
    my_ptr(const T & p){
        count=p.count+1;
        ptr = p.ptr;
    }

    T *get(){return ptr;}
    ~my_ptr(){
        count--;
        if (count==0)
            delete ptr;
    }
};

class handle_order{
    Order2* create_order(){
        return new Order2(4,5);
    }
};

class A{
//    std::shared_ptr<B> * ptr;
};

class B{
    std::shared_ptr<A>* ptr;
};


void session_4(){
    std::shared_ptr<Order2> p1(new Order2(4,5)); //ref counter = 1
    {
        std::weak_ptr<Order2> p2(p1); //ref counter = 1
    }
    std::cout << "end of my code" << std::endl;
}


#endif //QUIZ_SESSION4_H
