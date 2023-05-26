//
// Created by Yumeng Zhang on 4/5/23.
//

#include "UnorderedMap.h"

void UnorderedMap(){

    unordered_map<int, string> umapIntToStr;
    umapIntToStr.insert(make_pair(1, "One"));
    umapIntToStr.insert(make_pair(45, "Forty Five"));
    umapIntToStr.insert(make_pair(1001, "Thousand One"));
    umapIntToStr.insert(make_pair(-2, "Minus Two"));
    umapIntToStr.insert(make_pair(-1000, "Minus One Thousand"));
    umapIntToStr.insert(make_pair(100, "One Hundred"));
    umapIntToStr.insert(make_pair(12, "Twelve"));
    umapIntToStr.insert(make_pair(-100, "Minus One Hundred"));

    DisplayUnorderedMap<int, string>(umapIntToStr);

    cout << "Inserting one more element" << endl;
    umapIntToStr.insert(make_pair(300, "Three Hundred"));
    DisplayUnorderedMap<int, string>(umapIntToStr);

    cout << "Enter key to find for: "; int Key = 0;
    cin >> Key;

    auto element = umapIntToStr.find(Key);

    if (element != umapIntToStr.end())
        cout << "Found! Key pairs with value " << element->second << endl;
    else
        cout << "Key has no corresponding pair value!" << endl;
}
