#include <iostream>

using namespace std;
void func2();
void func3();
// Shift + Alt + F : 代码格式化快捷
// 多行注释或取消注释：Alt+Shift+A
/*
 总结：
 1和2可以认为是指针初始化的两种方法
 */
int main()
{
    //1. 指针的危险（4.7.2）：注意：定义指针后必须赋初始化地址
    //如下写法不可
    /*
    long *fellow;
    *fellow = 2333; //fellow很可能指向不了2333真正应该存储的地方
    */

    //2. 使用new来分配内存（4.7.4）
    //   使用delete来释放内存（4.7.5）注意：new 与 delete 一般成对使用
    //通用格式为： typeName * pointer_name = new typeName

    //func2(); //程序清单4.17

    //3. 使用new来创建动态数组
    //通用格式为： typeName * pointer_name = new typeName [num_elements]

    //func3(); //C++中将数组名解释为地址

    /* short tell[10];
    cout << tell << endl;  //tell[0]的地址
    cout << tell + 1 << endl; //tell[1]的地址
    cout << &tell << endl; //整个数组的地址，数值上和tell[0]的地址一样
    cout << &tell + 1 << endl; */
    //tell[0]的地址+20（10*2 2是一个short类型占2个字节）

    const char *bird = "wren";
    cout << bird << endl; //wren
    return 0;
}

void func2()
{
    int *pt = new int; //给一个int型变量分配内存空间
    *pt = 1001;
    double *pd = new double;
    *pd = 10000001.0;
    int nights = 1001;
    cout << "nights value = " << nights << ";location " << &nights << endl;
    cout << "int value = " << *pt << ";location " << pt << endl;
    cout << "double calue = " << *pd << ";location " << pd << endl;
    cout << "size of nights:" << sizeof(nights) << endl;
    cout << "size of *pt:" << sizeof(*pt) << ";size of pt:" << sizeof(pt) << endl;
    cout << "size of *pd:" << sizeof(*pd) << ";size of pt:" << sizeof(pd) << endl;
    delete pt;
    delete pd;
}

void func3()
{
    double *p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1] is " << p3[1] << endl; //指针可以当数组名使用，指向第0个元素
    p3 = p3 + 1;                          //此时指向第0+1个元素
    cout << "Now p3[0] is " << p3[0] << endl;
    cout << "Now p3[1] is " << p3[1] << endl;
    p3 = p3 - 1; //回到第0个元素的地址，因为下一步是删除
    delete[] p3;
}
