#include <fstream>
#include <iostream>
using namespace std;

void file_write();
void file_read();
int main()
{
    //向文件中写入数据
    // file_write();

    //从文件中读入数据
    file_read();

    return 0;
}

void file_read()
{
    ifstream inFile; //声明一个文件读取对象
    inFile.open("nums.txt");
    if (!inFile.is_open()) { //无法打开文件
        cout << "open file failed!" << endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0;
    int count = 0;
    inFile >> value;
    
    while (inFile.good()) { //有输入
        count++;
        sum += value;
        inFile >> value;
    }
    if (inFile.eof()) {
        cout << "End of file reached!\n";
    } else if (inFile.fail()) {
        cout << "input terminated by data mismatch!\n";
    } else {
        cout << "input terminated for unknown reason!\n";
    }
    if (count == 0) {
        cout << "No data.\n";
    } else {
        cout << "count: " << count << endl;
        cout << "sum: " << sum << endl;
        cout << "average: " << sum / count << endl;
    }
}

void file_write()
{
    char name[50];
    int year;
    double a_price, d_price;
    ofstream outFile; //声明一个文件输出对象
    outFile.open("info.txt"); //将对象和文件相关联

    cout << "Enter the name: ";
    cin.getline(name, 50);
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter thr price: ";
    cin >> a_price;
    d_price = 0.9 * a_price;

    //从屏幕上输出
    cout << fixed; //表示用一般方式输出浮点数，而不是科学计数法
    cout.precision(2); //设置精确度为2，并返回上一次的设置。
    cout.setf(ios_base::showpoint); //显示浮点数小数点后面的零。

    cout << "name:" << name << endl;
    cout << "year:" << year << endl;
    cout << "a_price:" << a_price << endl;
    cout << "d_price:" << d_price << endl;

    //输出到文件
    outFile << fixed; //表示用一般方式输出浮点数，而不是科学计数法
    outFile.precision(2); //设置精确度为2，并返回上一次的设置。
    outFile.setf(ios_base::showpoint); //显示浮点数小数点后面的零。

    outFile << "name:" << name << endl;
    outFile << "year:" << year << endl;
    outFile << "a_price:" << a_price << endl;
    outFile << "d_price:" << d_price << endl;

    outFile.close();
}