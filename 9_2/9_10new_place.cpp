// 使用 定位(placement) new 运算符
#include <iostream>
#include <new>  // 定位(placement) new 运算符包含的头文件
using namespace std;
const int BUF = 512;
const int N = 5;
char buffer[BUF];
int main() {
    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];
    pd2 = new (buffer) double[N];
}