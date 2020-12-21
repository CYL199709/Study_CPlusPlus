// usestock1.cpp -- the client program
//需要与 stock1.cpp 一同编译
#include <iostream>

#include "stock10.h"

int main() {
    using std::cout;
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);
    stock2.show();

    cout << "Assigning stock1 to stock2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();

    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0); //调用构造函数创建一个临时对象，再复制到stock1中，再丢弃它
    cout << "Revised stock1:\n";
    stock1.show();
    cout << "Done\n";
    return 0;

}