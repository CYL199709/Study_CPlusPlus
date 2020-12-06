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
    pd1 = new double[N];  //放于堆(heap)中
    pd2 = new (buffer) double[N]; //p2放在了buffer中，两者地址一样
    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    cout << "Memory address:\n"
         << " heap: " << pd1 << " static: " << (void *)buffer << endl;//类型不同，所以需要(void*)强制转换
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << "; " << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N];  // 不能delete,buffer指定的是静态内存
    for (i = 0; i < N; i++) {
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << "; " << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << "; " << endl;
    }
    delete[] pd1;
    delete[] pd3;
    return 0;
}