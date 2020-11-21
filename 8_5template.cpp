#include <iostream>
using namespace std;
//函数模板示例
//函数模板并不能缩短可执行程序，本例最后仍由2个独立的函数定义。
//注意：结尾没有;
template <typename T>  //此处 typename 也可为class(旧版)
void Swap(T&, T&);
int main() {
    int i = 10;
    int j = 20;
    cout << "before:"
         << "i=" << i << ",j=" << j << endl;
    Swap(i, j);
    cout << "after :"
         << "i=" << i << ",j=" << j << endl;

    double x = 1.2;
    double y = 2.3;
    cout << "before:"
         << "x=" << x << ",y=" << y << endl;
    Swap(x, y);
    cout << "after :"
         << "x=" << x << ",y=" << y << endl;
    return 0;
}

template <typename T>
void Swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}