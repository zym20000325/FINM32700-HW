//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION62_OBSERVERPATTERN_H
#define QUIZ_SESSION62_OBSERVERPATTERN_H

#include <iostream>
#include <vector>
using namespace std;

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
    void get_position()
    {
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


void session_62(){

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

#endif //QUIZ_SESSION62_OBSERVERPATTERN_H
