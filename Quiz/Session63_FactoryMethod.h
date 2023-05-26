//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION63_FACTORYMETHOD_H
#define QUIZ_SESSION63_FACTORYMETHOD_H

#include <iostream>
using std::cout, std::cin, std::endl;

#include <string>
using std::string;

class Order3{
public:
    virtual void declare() = 0;
};

class FOKOrder3: public Order3{
public:
    void declare() override{
        cout << "It's FOK." << endl;
    }
};

class GTCOrder3: public Order3{
public:
    void declare() override{
        cout << "It's GTC." << endl;
    }
};

class Creator{
    virtual Order3* FactoryMethod(string type) = 0;
};

class OrderCreator: public Creator{

public:

    Order3* FactoryMethod(string type){
        if(type == "GTC"){
            return new GTCOrder3();
        }
        else if(type == "FOK"){
            return new FOKOrder3();
        }
    }
};

void session_63(){

    OrderCreator oc;
    GTCOrder3* o1 = static_cast<GTCOrder3*>(oc.FactoryMethod("GTC"));
    o1->declare();

    FOKOrder3* o2 = static_cast<FOKOrder3*>(oc.FactoryMethod("FOK"));
    o2->declare();
}

#endif //QUIZ_SESSION63_FACTORYMETHOD_H
