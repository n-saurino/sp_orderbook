#include <iostream>
#include "orderbook.h"

using namespace std;

int main(int, char**){
    OrderBook book;

    Order first_order = {0, 13.0, 10};
    Order second_order = {0, 12.0, 15};
    Order third_order = {1, 13.0, 20};
    Order final_order = {1, 10.0, 10};
    book.Add(first_order);
    book.Add(second_order);
    book.Add(third_order);
    book.Add(final_order);
    book.Print();


}
