//
// Created by Yumeng Zhang on 4/14/23.
//

#include "LinkedList.h"

void linked_list(){

    node* head = new node(5);
    head->next = new node(6);
    head->next->next = new node(7);

    node* current = head;

    while(current!= nullptr){
        cout << current->number << endl;
        current = current->next;
    }
}
