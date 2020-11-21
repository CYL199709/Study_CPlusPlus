//使用一个 static 局部变量
#include <iostream>
using namespace std;
const int ArSize = 10;
void strcount(const char* str);

int main() {
    char input[ArSize];
    char next;

    cout << "Enter a line:" << endl;
    cin.get(input, ArSize);
    while (cin) {       //读取空行时 cin 为false
        cin.get(next);  //读取行输入后的字符
        while (next != '\n') cin.get(next);
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char* str) {
    static int total = 0; //只初始化时为0，后面每次调用时都将保持上次的值
    int count = 0;
    cout << "\"" << str << "\" contains ";
    while (*str++) {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}