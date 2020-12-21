// stock10.cpp -- Stock类的补充 增加了构造函数和析构函数
// version 10
#include "stock10.h"

#include <iostream>

Stock::Stock() {  //默认的构造函数
    std::cout << "Default Constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr) {
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negtive; " << company
                  << "shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

//析构函数
Stock::~Stock() { std::cout << "Bye, " << company << "!\n"; }

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased can't be negtive. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold can't be negtive. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    std::cout << "Company: " << company << " Shares: " << shares
              << " Shares Price: $" << share_val;
    // set format to #.###
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock& Stock::topval(const Stock& s) const {  //最后一个const是限定this为const,即不能使用this来修改const的值
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}