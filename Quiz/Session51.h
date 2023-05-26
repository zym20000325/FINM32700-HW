//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION51_H
#define QUIZ_SESSION51_H

#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

int bank_account_balance = 0;
mutex flag;

void transaction(int cash){
    for (int i = 0; i < 1000000; i++) {
        flag.lock();
        bank_account_balance+=cash;
        flag.unlock();
    }
}

void session_51(){

    thread seb([]{transaction(1);});
    thread nic([]{transaction(-1);});
    seb.join();
    nic.join();
    std::cout << "Balance: " << bank_account_balance << endl;
}


#endif //QUIZ_SESSION51_H
