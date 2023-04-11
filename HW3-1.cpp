#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}


/*
 * Complete the 'removeNodes' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST listHead
 *  2. INTEGER x
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
    
    if (listHead == nullptr){
        return nullptr;
    }
    
    // check head
    
    while (listHead->data > x) {
        
        SinglyLinkedListNode* p = listHead;
        listHead = listHead->next;
        delete p;

        if (listHead == nullptr) {
            return nullptr;
        }
    }
    
    // check rest
    
    SinglyLinkedListNode* current = listHead;
    
    while(current->next != nullptr){
        
        if (current->next->data > x){
            SinglyLinkedListNode* p = current->next;
            current->next = p->next;
            delete p;
        }
        else{
            current = current->next;
        }
    }
    
    return listHead;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* listHead = new SinglyLinkedList();

    string listHead_count_temp;
    getline(cin, listHead_count_temp);

    int listHead_count = stoi(ltrim(rtrim(listHead_count_temp)));

    for (int i = 0; i < listHead_count; i++) {
        string listHead_item_temp;
        getline(cin, listHead_item_temp);

        int listHead_item = stoi(ltrim(rtrim(listHead_item_temp)));

        listHead->insert_node(listHead_item);
    }

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    SinglyLinkedListNode* result = removeNodes(listHead->head, x);

    print_singly_linked_list(result, "\n", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
