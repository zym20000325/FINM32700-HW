//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION65_SINGLETON_H
#define QUIZ_SESSION65_SINGLETON_H

#include <iostream>

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

void session_65(){
    Singleton& singleton = Singleton::getInstance(); // Get the singleton instance
    singleton.someFunction(); // Call a function on the singleton
}


#endif //QUIZ_SESSION65_SINGLETON_H
