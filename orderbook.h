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
    vector<Order> orders;

    OrderBook(){

    }

    void Print(){
        for(auto order : orders){
            if(order.isbid){
                cout << "Buy";
            }else{
                cout << "Sell";
            }
            cout << " " << order.qty << "@" << order.price << endl;
        }
    }

    vector<Order>::iterator splitBuysAndSells() {
        vector<Order> buys;
        vector<Order> sells;

        // Split orders into buys and sells
        for (const auto& order : orders) {
            if (order.isbid) {
                buys.push_back(order);
            } else {
                sells.push_back(order);
            }
        }

        // Copy buys and sells back into the original vector
        auto it = orders.begin();
        it = copy(buys.begin(), buys.end(), it);
        copy(sells.begin(), sells.end(), it);

        // Return an iterator to the beginning of sells
        return orders.begin() + buys.size();
    }

    void sortBook() {
        auto it = splitBuysAndSells();

        // Sort buys from highest to lowest
        sort(orders.begin(), it, [](const Order& lhs, const Order& rhs) {
            return lhs.price > rhs.price;
        });

        // Sort sells from lowest to highest
        sort(it, orders.end(), [](const Order& lhs, const Order& rhs) {
            return lhs.price < rhs.price;
        });
    }

    ~OrderBook(){

    }

    void Add(Order order){
        
        auto other = findTrade(order);

        if(other == end(orders)){
            orders.push_back(order);
            sortBook();
        }else{
            // cout << other->isbid << " " << other->qty << "@" << other->price << endl;
            if(order.qty == other->qty){
                orders.erase(other);
            }else if(order.qty < other->qty){
                other->qty -= order.qty;
            }else if(order.qty > other->qty){
                order.qty -= other->qty;
                orders.erase(other);
                Add(order);
            }
        }

    }

    vector<Order>::iterator findTrade(const Order& order){
        auto ret = end(orders);

        size_t i = 0;
        while(i < orders.size()){
            if(order.isbid != orders[i].isbid){
                if(order.isbid && order.price >= orders[i].price){
                    ret = orders.begin() + i;
                    return ret;
                }else if(!order.isbid && order.price <= orders[i].price){
                    ret = orders.begin() + i;
                    return ret;
                }
            }
            ++i;
        }
        return ret;
    }

};