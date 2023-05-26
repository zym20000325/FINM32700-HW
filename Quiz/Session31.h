//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION31_H
#define QUIZ_SESSION31_H

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Order{
protected:
    int price;
    int quantity;
public:
    virtual string get_name(){
        return "Order";
    }
    int get_price(){return price;}
    int get_quantity(){return quantity;}

    Order(int price_, int quantity_):price(price_),quantity(quantity_){
        cout << "constructor for Order" << endl;
    }
    ~Order(){
        cout << "destructor for Order" << endl;
    }
};

class FOKOrder : public Order {
public:
    FOKOrder(int price_, int quantity_) : \
    Order(price_, quantity_) {
        cout << "constructor for FOK" << endl;
    };
};

class GTCOrder : public Order {
    int exp_date;
public:
    string get_name(){
        return "GTCOrder";
    }
    GTCOrder(int price_, int quantity_, int exp_date_):\
    Order(price_,quantity_),exp_date(exp_date_) {
        cout << "constructor for GTC" << endl;
    }
    ~GTCOrder(){
        cout << "destructor for GTC" << endl;
    }
    void modify_price(int p){
        price=p;
    }
};


void session_31(){
    vector<Order*> potential_positions;
    potential_positions.push_back(new FOKOrder(2,3));
    potential_positions.push_back(new GTCOrder(1,5,3));
    potential_positions.push_back(new GTCOrder(2,4,4));
    potential_positions.push_back(new FOKOrder(1,5));

    //iterate the vector potential_positions
    // if the type is GTCOrder
    // add notional position to the result
    int notional_exposure = 0;

    for (Order* order: potential_positions) {
        GTCOrder* gtc_order = dynamic_cast<GTCOrder*>(order);
        if (gtc_order != nullptr) {
            notional_exposure += gtc_order->get_price() * gtc_order->get_quantity();
        }
    }
    cout  << notional_exposure << endl;
}

#endif //QUIZ_SESSION31_H
