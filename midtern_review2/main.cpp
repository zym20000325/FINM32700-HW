//
// Created by Yumeng Zhang on 5/4/23.
//

#include <iostream>
using std::cout, std::cin, std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "array_and_string.h"

#include "two_d_array.h"

#include "template.h"

#include "IteratorPattern.h"

#include "ObserverPattern.h"

//////////// Observer Pattern ////////////

class Observer {

public:
    virtual ~Observer(){};
    virtual void Update (int pos) = 0;

protected:
    Observer(){};
};

class Subject {

public:
    virtual ~Subject(){};
    virtual void Attach (Observer*);
    virtual void Detach (Observer*);
    virtual void Notify(){};

protected:
    Subject(){};
    vector<Observer*> _observers;

private:

};

void Subject::Attach (Observer* o) {
    _observers.push_back(o);
}

void Subject::Detach (Observer* o) {
    //_observers->(o);
}

class TradingStrategy: public Observer{
public:
    int position;
    TradingStrategy(): Observer(),position(0){}

    void Update(int pos){
        position = pos;
    };

    void get_position(){
        cout << position << endl;
    }
};

class PositionManager : public Subject{

public:
    int position;
    PositionManager(): Subject(),position(0) {};

    void set_state(int pos){
        position = pos;
    }

    void Notify() {
        for ( auto &it : _observers)
            (*it).Update(position);
    }
};

void use_observer_pattern(){

    TradingStrategy t1;
    TradingStrategy t2;
    PositionManager pm1;

    pm1.Attach(&t1);
    pm1.Attach(&t2);

    pm1.set_state(66);
    pm1.Notify();

    t1.get_position();
    t2.get_position();
}

//////////// Method Factory ////////////

class Order{
public:
    virtual void declare() = 0;
};

class FOKOrder: public Order{
public:
    void declare() override{
        cout << "It's FOK." << endl;
    }
};

class GTCOrder: public Order{
public:
    void declare() override{
        cout << "It's GTC." << endl;
    }
};

class Creator{
    virtual Order* FactoryMethod(string type) = 0;
};

class OrderCreator: public Creator{

public:

    Order* FactoryMethod(string type){
        if(type == "GTC"){
            return new GTCOrder();
        }
        else if(type == "FOK"){
            return new FOKOrder();
        }
    }
};

void use_method_factory(){

    OrderCreator oc;
    GTCOrder* o1 = static_cast<GTCOrder*>(oc.FactoryMethod("GTC"));
    o1->declare();

    FOKOrder* o2 = static_cast<FOKOrder*>(oc.FactoryMethod("FOK"));
    o2->declare();
}

//////////// Abstract Factory ////////////

class Composer{
public:
    virtual void compose() = 0;
};

class Parser{
public:
    virtual void parse() = 0;
};

class NasdaqComposer: public Composer{
public:
    void compose(){
        std::cout << "Composing Nasdaq message" << std::endl;
    }
};

class NasdaqParser: public Parser{
public:
    void parse(){
        cout << "Parsing Nasdaq message" << endl;
    }
};

class EBSComposer: public Composer{
public:
    void compose(){
        cout << "Composing EBS message" << endl;
    }
};

class EBSParser: public Parser{
public:
    void parse(){
        cout << "Parsing EBS message" << endl;
    }
};

class AbstractFactory{
public:
    virtual Composer* createComposer() = 0;
    virtual Parser* createParser() = 0;
};

class FactoryNasdaq: public AbstractFactory{
public:
    Composer* createComposer(){
        return new NasdaqComposer();
    }
    Parser* createParser(){
        return new NasdaqParser();
    }
};

class FactoryEBS: public AbstractFactory{
public:
    Composer* createComposer(){
        return new EBSComposer();
    }
    Parser* createParser(){
        return new EBSParser();
    }
};
//
//class Composer{
//
//};
//
//class Parser{
//
//};
//
//class NasdaqComposer: public Composer{
//
//};
//
//class NasdaqParser: public Parser{
//
//};
//
//class EBSComposer: public Composer{
//
//};
//
//class EBSParser: public Parser{
//
//};
//
//class AbstractFactory{
//public:
//    Composer* createComposer();
//    Parser* createParser();
//};
//
//class FactoryNasdaq: public AbstractFactory{
//public:
//    Composer* createComposer(){
//        new NasdaqComposer();
//    }
//    Parser* createParser(){
//        new NasdaqParser();
//    }
//};
//
//class FactoryEBS: public AbstractFactory{
//public:
//    Composer* createComposer(){
//        new EBSComposer();
//    }
//    Parser* createParser(){
//        new EBSParser();
//    }
//};

void use_abstract_factory(){

    AbstractFactory* nasdaqFactory = new FactoryNasdaq();
    AbstractFactory* ebsFactory = new FactoryEBS();

    Composer* composer;
    Parser* parser;

    composer = nasdaqFactory->createComposer();
    parser = nasdaqFactory->createParser();

    composer->compose();
    parser->parse();

    composer = ebsFactory->createComposer();
    parser = ebsFactory->createParser();

    composer->compose();
    parser->parse();

    delete composer;
    delete parser;
}


//////////// Singleton ////////////

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; // Only created once, on first use
        return instance;
    }

    void someFunction() {
        std::cout << "Hello from the singleton!" << std::endl;
    }

private:
    Singleton() {} // Private constructor to prevent instantiation
    Singleton(const Singleton&) = delete; // Delete copy constructor
    Singleton& operator=(const Singleton&) = delete; // Delete assignment operator
};

void use_singleton(){
    Singleton& singleton = Singleton::getInstance(); // Get the singleton instance
    singleton.someFunction(); // Call a function on the singleton
}

#define LOG(X,Y) {cout << "case " << X << ": " << Y << endl;}

int function1(int a){
    a++;
    return a;
}

int function2(int &a){
    a++;
    return a;
}

int function3(int *a){
    (*a)++;
    return *a;
}

void understand_pointer(){
    int a = 2;
    function1(a);
    cout << a << endl;
    function2(a);
    cout << a << endl;
    function2(a);
    cout << a << endl;
    function3(&a);
    cout << a << endl;

//    LOG(1, function1(a));
//    LOG(2, function2(a));
//    LOG(3, function2(a));
//    LOG(4, function3(&a));
}


int main() {

//    array_string();

//    use_2d_array();

//    use_template();

//    use_iterator_pattern();

//    use_observer_pattern();

//    use_method_factory();

//    use_abstract_factory();

//    use_singleton();

    understand_pointer();

    return 0;
}
