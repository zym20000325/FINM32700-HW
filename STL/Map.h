//
// Created by Yumeng Zhang on 4/5/23.
//

#ifndef STL_MAP_H
#define STL_MAP_H

#include <map>
#include <string>
#include <iostream>

using std::cout, std::endl;
using std::string;
using std::map, std::multimap;
using std::make_pair;
using std::ostream;

template<typename keyType>
struct ReverseSort {
    bool operator()(const keyType& key1, const keyType& key2) const{
        return (key1 < key2);
    }
};

template<typename KeyType, typename ValueType>
void DisplayMap(const map<KeyType, ValueType>& m) {
    for (const auto& p : m) {
        cout << p.first << ": " << p.second << endl;
    }
}

template<typename KeyType, typename ValueType, typename Compare>
void DisplayReverseMap(const map<KeyType, ValueType, Compare>& m) {
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

class Order{

public:

    int price;
    int quantity;

    Order(int p, int q): price(p), quantity(q){}
};

//ostream& operator<<(ostream& os_, const Order& o_){
//    os_ << "Order (" << o_.price << "/" << o_.quantity << ")";
//    return os_;
//}

void Map();

void OrderMap();


#endif //STL_MAP_H
