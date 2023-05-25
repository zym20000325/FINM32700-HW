#include <iostream>
#include <memory>
using namespace std;


class Order {
public:
    Order() { cout << "Order Constructor" << endl; }
    ~Order() { cout << "Order Destructor" << endl; }
    void getPrice() { cout << "This is public function of class" << endl; }
};






// A helper function which returns a shared pointer
shared_ptr<Order> CreateSmartPointer() {
    //Create a shared pointer
    cout << "Enter CreateSmartPointer" << endl;
    shared_ptr<Order> o = make_shared<Order>();
    cout << "Exit CreateSmartPointer" << endl;
    return o;
}

// A helper function which returns a unique pointer
unique_ptr<Order> CreateUniquePointer() {
    //Create a unique pointer
    cout << "Enter CreateUniquePointer" << endl;
    unique_ptr<Order> o = make_unique<Order>();
    cout << "Exit CreateUniquePointer" << endl;
    return o;
}


template <class T>
class MyOwnSmartPointer {
    
//You will implement your own smart pointer class

public:
    MyOwnSmartPointer(T* ptr) : pointer(ptr) {
    }
    
    ~MyOwnSmartPointer() {
        delete pointer;
    }

    T* operator->() const {
        return pointer;
    }

    T& operator*() const {
        return *pointer;
    }

private:
    T* pointer;

};
// Test to confirm that shared pointers do release memory without explicitely calling
// the delete
void  CheckReleaseMemory() {
    shared_ptr<Order> sp(new Order{});
    sp->getPrice();
    return;
}

// Test to confirm that shared pointers does use reference counts
void CheckReferenceCount() {
    cout << "Enter CheckReferenceCount" << endl;
    shared_ptr<Order> retSp = CreateSmartPointer();
    cout << "Exit CheckReferenceCount" << endl;
    return;
}
// Test to confirm that shared pointers does use reference counts and use it smartly
void CheckReferenceCountAssignment() {
    cout << "Enter CheckReferenceCountAssignment" << endl;
    CreateSmartPointer();
    cout << "Exit CheckReferenceCountAssignment" << endl;
    return;
}

// Test for using inbuilt Make_Shared to create a shared pointer
void TestSharedPtr_MakeShared() {
    shared_ptr<Order> sp = make_shared<Order>();
    return;
}





// Test to confirm that unique pointers do release memory without explicitely calling
// the delete
void  TestUniquePtr_ReleaseMemory() {
    unique_ptr<Order> up(new Order{});
    up->getPrice();
    return;
}

// Test to confirm that unique pointers doesn't transfer the ownership
void TestUniquePtr_NoOwnershipTrasfer() {
    unique_ptr<Order> up(new Order);
    // The line below will generate compiler error
    //unique_ptr<Sample> upTrans = up;
    return;
}

// Test to confirm that unique pointers ownership can be transferred using std::move
void TestUniquePtr_MoveOwnershipTrasfer() {
    unique_ptr<Order> up(new Order);
    unique_ptr<Order> upTrans = std::move(up);
    return;
}


// Test to confirm that unique pointers can be returned from a function without
// sharing the ownership
void TestUniquePtr_ReturnFunction() {
    cout << "Enter TestUniquePtr_ReturnFunction" << endl;
    unique_ptr<Order> retSp = CreateUniquePointer();
    cout << "Exit TestUniquePtr_ReturnFunction" << endl;
    return;
}
// Test to confirm that unique pointers does free up the memory if no one is willing to take
// the ownership
void TestUniquePtr_ReturnNoOwnership() {
    cout << "Enter TestUniquePtr_ReturnNoOwnership" << endl;
    CreateUniquePointer();
    cout << "Exit TestUniquePtr_ReturnNoOwnership" << endl;
    return;
}

// Test for using inbuilt Make_Unique to create a unique pointer
// Available only in C++14 onwards
void TestUniquePtr_MakeUnique() {
    unique_ptr<Order> sp = make_unique<Order>();
    return;
}


int main() {
    CheckReleaseMemory();
    cout << "------------------------------------------------" << endl;
    CheckReferenceCount();
    cout << "------------------------------------------------" << endl;
    CheckReferenceCountAssignment();
    cout << "------------------------------------------------" << endl;
    TestSharedPtr_MakeShared();

    TestUniquePtr_ReleaseMemory();
    cout << "------------------------------------------------" << endl;
    TestUniquePtr_MoveOwnershipTrasfer();
    cout << "------------------------------------------------" << endl;
    TestUniquePtr_ReturnFunction();
    cout << "------------------------------------------------" << endl;
    TestUniquePtr_ReturnNoOwnership();
    cout << "------------------------------------------------" << endl;
    TestUniquePtr_MakeUnique();

    MyOwnSmartPointer<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;

    MyOwnSmartPointer<Order> ptr2(new Order());
    cout << *ptr << endl;

    cout << "end of the code" << endl;

    return 0;
}