//
// Created by Yumeng Zhang on 5/4/23.
//

#include "IteratorPattern.h"

void use_iterator_pattern(){

    int tab[20];

    for(int k=0;k<20;k++){
        tab[k]=k;
    }

    ArrayIterator<int> it(tab);

    for(int k=0;k<21;k++){
        cout << it.CurrentItem() << endl;
        it.Next();
    }
}
