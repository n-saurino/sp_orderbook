#include <iostream>
#include <vector>

using namespace std;

struct Order
{
    bool isbid;
    double price;
    int qty;
};


class OrderBook{
public:
    vector<Order> OrderBook::orders;

    OrderBook(){

    }

    vector<Order>::iterator splitBuysAndSells(){

        return nullptr;
    }

    void sortBook(){
        auto it = splitBuysAndSells();
        sort(orders.begin(), it);
        sort(it, orders.end());
    }

    ~OrderBook(){

    }

    void Add(Order order){
        
        auto other = findTrade(order);

        if(other == end(orders)){
            orders.push_back(order);
        }else{

            orders.erase(other);
        }

    }

    vector<Order>::iterator findTrade(const Order& order){
        auto ret = end(orders);

        size_t i = 0;
        while(i < orders.size()){
            if(order.isbid != orders[i].isbid){
                if(order.isbid && order.price > orders[i].price){
                    ret = orders.begin() + i;
                    return ret;
                }else if(!order.isbid && order.price < orders[i].price){
                    ret = orders.begin() + i;
                    return ret;
                }
            }
            ++i;
        }

        return ret;
    }

};