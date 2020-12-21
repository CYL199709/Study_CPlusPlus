// stock00.cpp -- Stock类的补充
// version 00
#include "stock00.h"

#include <iostream>

void Stock::acquire(const std::string& co, long n, double pr) {
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
    std::cout << "Company: " << company << " Shares: " << shares
              << " Shares Price: $" << share_val << " Total Worth: $"
              << total_val << '\n';
}