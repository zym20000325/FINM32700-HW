//
// Created by Yumeng Zhang on 4/5/23.
//

#include "Map.h"
#include "List.h"

void Map(){

    // map and multimap key of type int to value of type string
    map<int, string> mapIntToStr1;
    multimap<int, string> mmapIntToStr1;

    // map and multimap constructed as a copy of another
    map<int, string> mapIntToStr2(mapIntToStr1);
    multimap<int, string> mmapIntToStr2(mmapIntToStr1);

    // map and multimap constructed given a part of another map or multimap
    map<int, string> mapIntToStr3(mapIntToStr1.cbegin(), mapIntToStr1.cend());
    multimap<int, string> mmapIntToStr3(mmapIntToStr1.cbegin(), mmapIntToStr1.cend());

    // map and multimap with a predicate that inverses sort order
    map<int, string, ReverseSort<int>> mapIntToStr4 (mapIntToStr1.cbegin(), mapIntToStr1.cend());
    multimap<int, string, ReverseSort<int>> mmapIntToStr4 (mapIntToStr1.cbegin(), mapIntToStr1.cend());

    mapIntToStr1.insert(make_pair(1, "one"));
    mapIntToStr1.insert(make_pair(3, "three"));
    mapIntToStr1.insert(make_pair(2, "two"));

    DisplayMap(mapIntToStr1);

    cout << endl;

    mapIntToStr4.insert(make_pair(8, "eight"));
    mapIntToStr4.insert(make_pair(10, "ten"));
    mapIntToStr4.insert(make_pair(5, "five"));
    mapIntToStr4.insert(make_pair(12, "twelve"));

    DisplayReverseMap(mapIntToStr4);

}

void OrderMap(){

    map<int, Order*> orders;
    orders[1] = new Order(10,4);
    orders[2] = new Order(20,5);
    orders[3] = new Order(30,6);
    orders.insert(make_pair(0, new Order(40,2)));

    for (auto &it: orders){
        cout << it.first <<" " << it.second->price << " " << it.second->quantity << endl;
    }

//    for (auto &it2: orders){
//        cout << it2.first << " " << *(it2.second) << endl;
//    }
}