#include <iostream>
using namespace std;

void func1();
void func2();
void fun3(int&, int&);
// 引用：指向相同的值和内存单元。改变其中一个的值，另一个的值也会随之而改变
// 当函数的参数传递的是引用时，会将变量的改变传回来。(fun3)
int main() {
    // func1();
    // func2(); //引用+指针
    int a = 1;
    int b = 2;
    fun3(a, b);
    cout << "a=" << a << " b=" << b << endl; //2 1
    return 0;
}

void func1() {
    int rats = 101;
    //此处不是取地址，而是引用
    //将变量类型声明为 int&
    int& rodents =
        rats;  // 必须在声明引用时将其初始化。这与指针不同，指针可以先声明，再赋值。
    cout << "rats=" << rats << endl;        // 101
    cout << "rodents=" << rodents << endl;  // 101

    rodents++;
    cout << "rats=" << rats << endl;        // 102
    cout << "rodents=" << rodents << endl;  // 102

    rats++;
    cout << "rats=" << rats << endl;        // 103
    cout << "rodents=" << rodents << endl;  // 103
}

void func2() {
    int rats = 101;
    int* pt = &rats;     // pt是rat的地址
    int& rodents = *pt;  // rodents和 *pt（=rats） 相引用
    cout << "rats=" << rats << " rodents=" << rodents << " *pt=" << *pt
         << endl;  // 101 101 101
    int bunnies = 50;
    pt = &bunnies;
    cout << "rats=" << rats << " rodents=" << rodents << " *pt=" << *pt
         << endl;  // 101 101 50
}

void fun3(int& c, int& d) {
    int temp = c;
    c = d;
    d = temp;
}