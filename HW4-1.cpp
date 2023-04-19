#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>

enum ORDERTYPE {IOC, GTD, GTC};
enum ACTION {CREATE, MODIFY, DELETE};

typedef unsigned int price_t;
typedef unsigned int quantity_t;
typedef unsigned int order_id_t;


const std::string convert_order_type(ORDERTYPE ot)
{
    switch(ot)
    {
        case ORDERTYPE::IOC:
            return "IOC";
        case ORDERTYPE::GTC:
            return "GTC";
        case ORDERTYPE::GTD:
            return "GTD";
        default:
            return "NONE";
    }
}

/* You may need to modify the copy constructor */
/* and adapt the constructor */
/* DO NOT ASSUME THAT venue will be copied automatically */
/* you need to use strcpy */

struct Order{
    long timestamp;
    bool is_bid;
    order_id_t id;
    price_t price;
    quantity_t quantity;
    char venue[20];
    ORDERTYPE type;

    Order(
            long timestamp_,
            bool is_bid_,
            order_id_t id_,
            price_t price_,
            quantity_t quantity_,
            const char * venue_,
            ORDERTYPE type_
        )
        :
            timestamp(timestamp_),
            is_bid(is_bid_),
            id(id_),
            price(price_),
            quantity(quantity_),
            type(type_)
        {
            strncpy(venue, venue_, 20);
        }
    
    // Copy constructor
    Order(const Order& other)
            : timestamp(other.timestamp), is_bid(other.is_bid), id(other.id), price(other.price), quantity(other.quantity), type(other.type) {
        strncpy(venue, other.venue, 20);
    }
};


/* DO NOT MODIFY THIS PART UNTIL THE NEXT COMMENT */
struct OrderAction{
    Order &order;
    ACTION action;
    OrderAction(Order& o, ACTION a):order(o),action(a){}
};



const std::string convert_side(const Order &o)
{
    return (o.is_bid)?"bid":"ask";
}


void display_error_IOC(const Order &o)
{
    std::cout << "order id=" << o.id << " is a IOC order - order skipped" << std::endl;
}

void display_error_order_id_exist(const Order &o)
{
    std::cout << "order id=" << o.id << " is a duplicate - order skipped" << std::endl;
}

void display_order_creation(const Order &o)
{
    std::cout << "order id=" << o.id << " created"
              << " price=" << o.price
              << " quantity=" << o.quantity
              << " side=" << convert_side(o)
              << " venue=" << o.venue
              << " type="  << convert_order_type(o.type)
              << " ts=" << o.timestamp
              <<  std::endl;
}

void display_error_exist_order_modification(const Order &o)
{
    std::cout << "order id=" << o.id << " not existing - modification rejected" << std::endl;
}

void display_error_amendment_price(const Order &o)
{
    std::cout << "order id=" << o.id << " cannot have price changed  - amendment rejected" << std::endl;
}

void display_error_amendment_quantity(const Order &o)
{
    std::cout << "order id=" << o.id << " amendment must have a lower quantity - amendment rejected" << std::endl;
}

void display_amended_order(const Order &o)
{
    std::cout << "order_id=" << o.id << " modified"
              << " price=" << o.price
              << " quantity=" << o.quantity
              << " side=" << convert_side(o)
              << " venue=" << o.venue
              << " type="  << convert_order_type(o.type)
              << " ts=" << o.timestamp
              <<  std::endl;
}

void display_error_order_not_existing_deletion(const Order &o)
{
    std::cout << "order id=" << o.id << " not existing - deletion rejected" << std::endl;
}

void display_deleted_order(const Order &o)
{
    std::cout << "order id=" << o.id << " deleted" << std::endl;
}

void display_best_bid(int max)
{
    std::cout << "best bid:" << max << std::endl;
}

void display_best_ask(int min)
{
    std::cout << "best ask:" << min << std::endl;
}



/* MODIFY THIS PART BY FOLLOWING THE COMMENTS */



class OrderBook{
private:
    std::unordered_map<order_id_t, Order *> bids;
    std::unordered_map<order_id_t, Order *> asks;
public:
    OrderBook(){};
    
   template <typename T1, typename T2>
   void DisplayUnorderedMap(std::unordered_map<T1, T2>& cont) {

       std::cout << "Display" << std::endl;

       for (auto element = cont.cbegin(); element != cont.cend(); ++ element)
           std::cout << element->first << " -> "<< element->second->price<< " " << element->second->quantity << std::endl;
       std::cout << std::endl;
   }

    void add_order(Order &o)
    {
        //IF an order has an order type IOC, you shouldn't process this order
        // You should report an error with the function display_error_IOC

        if(o.type == ORDERTYPE::IOC){
            display_error_IOC(o);
            return;
        }

        // You should certainly find in which map you would like to store the new order
        // Based on the field is_bid, you should be able to take the right map

        //Try to create a reference on the map you will use later

        // If an order already exists you should not process this order
        // Check if the order id already exists in the map.
        // The map primary key is the order id
        // If the order exists, you should us the function display_error_order_id_exist
        // If the order doesn't exist you can insert it in the right map

        if (o.is_bid == true){

            auto iter = bids.find(o.id);
            if (iter != bids.end()){
                display_error_order_id_exist(o);
            }
            else {
                bids[o.id] = new Order(o);
                display_order_creation(o);
            }
        }
        else {

            auto iter = asks.find(o.id);
            if (iter != asks.end()){
                display_error_order_id_exist(o);
            }
            else {
                asks[o.id] = new Order(o);
                display_order_creation(o);
            }
        }
    };
    
    void modify_order(struct Order o){
        
        // You should certainly find in which map you would like to retrieve the order you will modify
        // Based on the field is_bid, you should be able to take the right map

        // If order id in map duplicate order, you should not process the order and you should use the function
        // display_error_exist_order_modification

        // if the modification coming from the order in the parameter of the function has a different price
        // you shouldn't process the amendment and you should display an error display_error_amendment_price

        // if the quantity of the order in the parameter of this function is not lower than the original quantity
        // you shouldn't process the order and you should display an error display_error_amendment_quantity

        // if an error is successfully amended, you should display the characteristics of this order with
        // the function display_amended_order

        if (o.is_bid == true){

            auto iter = bids.find(o.id);
            if (iter == bids.end()){
                display_error_exist_order_modification(o);
            }
            else {

                if (iter->second->price != o.price){
                    display_error_amendment_price(o);
                }
                else if (iter->second->quantity < o.quantity){
                    display_error_amendment_quantity(o);
                }
                else{
                    iter->second->quantity = o.quantity;
                    display_amended_order(o);
                }
            }
        }
        else{
            auto iter = asks.find(o.id);
            if (iter == asks.end()){
                display_error_exist_order_modification(o);
            }
            else {

                if (iter->second->price != o.price){
                    display_error_amendment_price(o);
                }
                else if (iter->second->quantity < o.quantity){
                    display_error_amendment_quantity(o);
                }
                else{
                    iter->second->quantity = o.quantity;
                    display_amended_order(o);
                }
            }
        }
    }
    
    void delete_order(struct Order o){
        
        // You should certainly find in which map you would like to retrieve the order you will delete
        // Based on the field is_bid, you should be able to take the right map


        // You should check if the order exist
        // If the order doesn't exist, you should display the error using the function
        // display_error_order_not_existing_deletion

        // If the order is successfully deleted, you must display the message using the function
        // display_deleted_order

        if (o.is_bid == true){

            auto iter = bids.find(o.id);
            if (iter == bids.end()){
                display_error_order_not_existing_deletion(o);
            }
            else {
                bids.erase(o.id);
                display_deleted_order(o);
            }
        }
        else {

            auto iter = asks.find(o.id);
            if (iter == asks.end()){
                display_error_order_not_existing_deletion(o);
            }
            else {
                asks.erase(o.id);
                display_deleted_order(o);
            }
        }
    }
    
    void process_order(OrderAction o)
    {
        // This function is called for any received orders.
        // You should call the function add_order, delete_order, modify_order depending
        // on the ACTION::CREATE, ACTION::DELETE, ACTION::MODIFY
        
        if (o.action == ACTION::CREATE){
            add_order(o.order);
        }
        else if (o.action == ACTION::MODIFY){
            modify_order(o.order);
        }
        else if (o.action == ACTION::DELETE){
            delete_order(o.order);
        }
    };
    
    void get_best_bid(){
        
        // You need to display the best bid
        // by calling the function display_best_bid
        // first check if there are bids in the map, if no bids, please display the message "no bids"
        
        if (bids.empty()){
            std::cout << "no bids" << std::endl;
        }
        else{
            int highest_price = 0;
            for(auto& entry : bids) {
                Order* order = entry.second;
                if(highest_price == 0 || order->price > highest_price) {
                    highest_price = order->price;
                }
            }
            display_best_bid(highest_price);
        }
    };

    void get_best_ask(){
        
        // You need to display the best ask
        // by calling the function display_best_ask
        // first check if there are asks in the map, if no asks, please display the message "no asks"
        
        if (asks.empty()){
            std::cout << "no asks" << std::endl;
        }
        else{
            int lowest_price = 1000000;
            for(auto& entry : asks) {
                Order* order = entry.second;
                if(lowest_price == 0 || order->price < lowest_price) {
                    lowest_price = order->price;
                }
            }
            display_best_ask(lowest_price);
        }
    };

    /* DO NOT MODIFIY */
    void get_bid_levels(){
        // This function will display the different price and the total volume associated to this price
        std::map<int,int> bid_volume_level;
        for (auto &it: bids)
        {
            auto it2=bid_volume_level.find(it.second->price);
            if(it2!=bid_volume_level.end())
            {
                bid_volume_level[it.second->price]+=it.second->quantity;
            }
            else {
                bid_volume_level[it.second->price]=it.second->quantity;
            }
        }
        std::cout << "bid" << "   volume" << std::endl;
        for (auto &it: bid_volume_level)
        {
            std::cout << it.first <<"   " << it.second << std::endl;
        }
    }

    /* DO NOT MODIFIY */
    void get_ask_levels(){
        // Same as the previous one
        std::map<int,int> ask_volume_level;
        for (auto &it: asks)
        {
            auto it2=ask_volume_level.find(it.second->price);
            if(it2!=ask_volume_level.end())
            {
                ask_volume_level[it.second->price]+=it.second->quantity;
            }
            else {
                ask_volume_level[it.second->price]=it.second->quantity;
            }
        }
        std::cout << "ask" << "   volume" << std::endl;
        for (auto &it: ask_volume_level)
        {
            std::cout << it.first <<"   " << it.second << std::endl;
        }
    }

    void clear_book(){
        
        // you need to clear the book completely
        // it means you need to remove all the bids
        // all the orders
        
        // at the end of this function you will display the number of bids and the asks
        // you remove
        
        int number_of_bids_deleted = bids.size();
        int number_of_asks_deleted = asks.size();

        bids.clear();
        asks.clear();

        std::cout << "Number of bids deleted:" << number_of_bids_deleted << std::endl;
        std::cout << "Number of asks deleted:" << number_of_asks_deleted << std::endl;
    }
};

void case0(OrderBook &ob1)
{
    long ts=0;
    {
        Order e(ts++, true, 1, 10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    {
        Order e(ts++, true, 1, 10, 50000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::MODIFY);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    {
        Order e(ts++, true, 1, 10, 60000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::MODIFY);
        ob1.process_order(oa);
    }
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    {
        Order e(ts++, true, 1, 9, 30000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::MODIFY);
        ob1.process_order(oa);
    }
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    {
        Order e(ts++, false, 2, 5, 30000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    {
        Order e(ts++, false, 3, 4, 20000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_ask_levels();
    ob1.get_bid_levels();



    ob1.clear_book();
}

void case1(OrderBook &ob1)
{
    long ts=0;
    id_t id=0;
    for(int i=0;i<100;i++){
        Order e(ts++, true, id++, id%10+10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<100;i++){
        Order e (ts++, false, 100+id++, id%10+20, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();
    ob1.clear_book();
}


void case2(OrderBook &ob1)
{
    long ts=0;
    id_t id=0;
    for(int i=0;i<100;i++){
        Order e(ts++, true, id++, id%10+10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<100;i++){
        Order e (ts++, false, 100+id++, id%10+20, 100000, "DONALD", (i%10)?ORDERTYPE::GTC:ORDERTYPE::IOC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();

    ob1.clear_book();
}


void case3(OrderBook &ob1)
{
    long ts=0;
    id_t id=0;
    for(int i=0;i<100;i++){
        Order e(ts++, true, id++, id%10+10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<100;i++){
        Order e (ts++, false, 100+id++, id%10+20, 100000, "DONALD", (i%10)?ORDERTYPE::GTC:ORDERTYPE::IOC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<10;i++){
        Order e (ts++, false, id++, id%10+20, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::DELETE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();

    ob1.clear_book();
}


void case4(OrderBook &ob1)
{
    long ts=0;
    id_t id=0;
    for(int i=0;i<100;i++){
        Order e(ts++, true, id++, id%10+10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<100;i++){
        Order e (ts++, false, 100+id++, id%10+20, 100000, "DONALD", (i%10)?ORDERTYPE::GTC:ORDERTYPE::IOC);
        OrderAction oa(e,ACTION::CREATE);
        ob1.process_order(oa);
    }
    for(int i=0;i<100;i++){
        Order e (ts++, false, id++, id%10+20, 50000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e,ACTION::MODIFY);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();

    ob1.clear_book();
}

void training0(OrderBook &ob1) {
    long ts = 0;
    {
        Order e(ts++, true, 1, 10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e, ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();
}

void training1(OrderBook &ob1) {
    long ts = 0;
    {
        Order e(ts++, false, 1, 10, 100000, "DONALD", ORDERTYPE::GTC);
        OrderAction oa(e, ACTION::CREATE);
        ob1.process_order(oa);
    }
    ob1.get_best_ask();
    ob1.get_best_bid();
    ob1.get_ask_levels();
    ob1.get_bid_levels();
}

void order0() {
    Order *a1 =new Order(12, true, 1, 10, 100000, "DONALD", ORDERTYPE::GTC);
    display_order_creation(*a1);
    Order *a2= new Order(*a1);
    delete(a1);
    display_order_creation(*a2);
}


int main() {
    OrderBook ob1;
    long ts=0;

    std::string line;
    std::getline(std::cin, line);
    if(line=="0")
    {
        case0(ob1);
    }
    else if(line=="1")
    {
        case1(ob1);
    }
    else if(line=="2")
    {
        case2(ob1);
    }
    else if(line=="3")
    {
        case3(ob1);
    }
    else if(line=="4")
    {
        case4(ob1);
    }
    else if(line=="training0")
    {
        training0(ob1);
    }
    else if(line=="training1")
    {
        training1(ob1);
    }
    else if(line=="order0")
    {
        order0();
    }

    return 0;
}