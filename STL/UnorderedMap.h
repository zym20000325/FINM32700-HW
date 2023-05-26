//
// Created by Yumeng Zhang on 4/5/23.
//

#ifndef STL_UNORDEREDMAP_H
#define STL_UNORDEREDMAP_H

#include<unordered_map>
#include <string>
#include <iostream>

using std::cin, std::cout, std::endl;
using std::string;
using std::unordered_map, std::unordered_multimap;
using std::make_pair;

template <typename T1, typename T2>
void DisplayUnorderedMap(unordered_map<T1, T2>& cont) {

    cout << "Unordered Map contains: " << endl;
    for (auto element = cont.cbegin(); element != cont.cend(); ++ element)
        cout << element->first << " -> "<< element->second<< endl;

    cout << endl;

    cout << "Number of pairs, size(): " << cont.size() << endl;
    cout << "Bucket count = " << cont.bucket_count() << endl;
    cout << "Current load factor: " << cont.load_factor() << endl;
    cout << "Max load factor = " << cont.max_load_factor() << endl;

    cout << endl;
}

void UnorderedMap();

#endif //STL_UNORDEREDMAP_H
