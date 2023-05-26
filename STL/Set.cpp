//
// Created by Yumeng Zhang on 4/5/23.
//

#include "Set.h"
#include "List.h"

void Set(){

    set <int> setInts{ 202, 151, -999, -1 };
    setInts.insert(-1); // duplicate
    cout << "Contents of the set: " << endl;
    DisplayContents(setInts);

    multiset <int> msetInts;
    msetInts.insert(setInts.begin(), setInts.end());
    msetInts.insert(-1); // duplicate
    cout << "Contents of the multiset: " << endl;
    DisplayContents(msetInts);

    cout << "Number of instances of '-1' in the multiset are: '";
    cout << msetInts.count(-1) << "'" << endl;

    auto element_to_find = setInts.find(-1);
    cout << *element_to_find << endl;

    setInts.erase(-1);
    cout << "Contents of the set after removal -1: " << endl;
    DisplayContents(setInts);
}
