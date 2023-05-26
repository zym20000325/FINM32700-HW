//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_QUIZ22_H
#define QUIZ_QUIZ22_H

#include <iostream>

using namespace std;

enum side_t {BUY, SELL};

class Order4{

public:
    Order4(int p, int q, int i, side_t s):price(p),quantity(q), id(i), side(s){
    }

    Order4(const Order4& o){
        cout << "copy constructor invoked" << endl;
        side=o.side;
        price=o.price;
        quantity=o.quantity;
        id=o.id;
    }

    Order4& operator=(const Order4& o){
        side=o.side;
        price=o.price;
        quantity=o.quantity;
        id=o.id;
        return *this;
    }


    int get_price() const{
        return price;
    }

    int get_quantity() const{
        return quantity;
    }

    int get_id() const{
        return id;
    }

    size_t get_side() const{
        if(side == side_t::BUY)
            return BUY;
        else
            return SELL;
    }

//    friend Order4 operator+(const Order4& a);

private:
    int price; //4 bytes
    int quantity; //4 bytes
    int id; //4 bytes
    side_t side; //4 bytes
};

int f1(Order4& a){
    return a.get_price();
}

Order4 operator+(const Order4& a, const Order4& b) {
    // Check if the orders are on the same side (BUY or SELL)
    if (a.get_side() != b.get_side()) {
        throw std::invalid_argument("Orders must be on the same side to be added");
    }

    int new_price = a.get_price();  // The new order's price will be the price of the first order
    int new_quantity = a.get_quantity() + b.get_quantity();  // Add the two quantities
    int new_id = std::max(a.get_id(), b.get_id()) + 1;  // The new order's id will be the larger of the two plus one
    side_t new_side = static_cast<side_t>(a.get_side());  // The new order's side will be the same as the first order's side

    Order4 new_order(new_price, new_quantity, new_id, new_side);
    return new_order;
}

//Order4 operator+(Order4 a, Order4 b) {
//    int newQuantity = a.get_quantity() + b.get_quantity();
//    return Order4(a.get_price(), newQuantity, a.get_id() + 1, a.get_side());
//}

//Order4 operator+(const Order4& a) {
//    Order4 newOrder(get_price(), get_quantity() + a.get_quantity(), get_id() +1, get_side() == "BUY" ? side_t::BUY : side_t::SELL);
//    Order4 newOrder(price, quantity + a.get_quantity(), id + 1, side);
//    return newOrder;
//}

void quiz_22(){
    Order4 a(3,10,1,side_t::BUY);
    Order4 b(a);
    Order4 c=b; // <===> Order c(b);
    c=b=a; // <=====> c.operator=(b.operator=(a));
    cout << a.get_quantity() << " " << a.get_price() << " " << a.get_side() << endl;
    cout << b.get_quantity() << " " << b.get_price() << " " << b.get_side() << endl;
    cout << c.get_quantity() << " " << c.get_price() << " " << c.get_side() << endl;

    Order4 d1(3,10,1,side_t::BUY);
    Order4 d2(2,15,1,side_t::BUY);
    Order4 d3 = d1+d2;

    cout << d3.get_quantity() << " " << d3.get_price() << " " << d3.get_side() << endl;
}

#endif //QUIZ_QUIZ22_H
