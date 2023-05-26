//
// Created by Yumeng Zhang on 5/4/23.
//

#ifndef QUIZ_SESSION52_H
#define QUIZ_SESSION52_H

#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
using namespace std;


int dot_product(vector<int> a, vector<int> b) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

int threaded_dot_product(vector<int> a, vector<int> b) {
    int sum1 = 0;
    int sum2 = 0;
    thread t1([&]() {
        for (int i = 0; i < a.size() / 2; i++) {
            sum1 += a[i] * b[i];
        }
    });
    thread t2([&]() {
        for (int i = a.size() / 2; i < a.size(); i++) {
            sum2 += a[i] * b[i];
        }
    });
    t1.join();
    t2.join();
    return sum1 + sum2;
}

void session_52(){

    vector<int> a;
    for (int i = 0; i < 100000000; i++) {
        a.push_back(1);
    }

    vector<int> b;
    for (int i = 0; i < 100000000; i++) {
        b.push_back(1);
    }

    auto start = chrono::high_resolution_clock::now();
    cout << "Threaded Dot product: " << threaded_dot_product(a, b) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    cout << "Dot product: " << dot_product(a, b) << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

#endif //QUIZ_SESSION52_H
