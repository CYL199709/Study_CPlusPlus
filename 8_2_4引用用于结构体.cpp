//程序清单8.6
#include <iostream>
#include <string>
using namespace std;

struct free_throws {
    string name;
    int made;
    int attemps;
    float percent;
};

void display(const free_throws&);
void set_pc(free_throws&);
free_throws& accumulate(free_throws&, const free_throws&);

int main() {
    // 初始化
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;

    set_pc(one);  // 100.0*13/14 = 92.8571
    display(one);

    accumulate(team, one);
    display(team);

    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    dup = accumulate(team, five);
    cout << "displaying team" << endl;
    display(team);
    cout << "displaying dup" << endl;
    display(dup);
    set_pc(four);

    // 此处可行，因为函数的返回值是一个引用
    //等效于
    /*
    accumulate(dup, five); //该行相当于无用
    dup = four;
    */
    accumulate(dup, five) = four;
    cout << "displaying dup after ill-advised assignments:\n";
    display(dup);
    return 0;
}

// 打印输出结构体函数
// 使用 const 引用传递参数，因为不能修改
// 与值传递相比，使用引用可以节省时间和内存
void display(const free_throws& ft) {
    cout << "Name:" << ft.name << endl;
    cout << "  Made: " << ft.made << '\t';
    cout << "  attemps: " << ft.attemps << '\t';
    cout << "  percent: " << ft.percent << '\n';
}

// 计算percent
// 这里传递的函数参数是引用类型，回到主函数时，对应值也会随之改变
// 与传递指针变量的效果是一样的
void set_pc(free_throws& ft) {
    if (ft.attemps != 0) {
        ft.percent = 100.0f * float(ft.made) / float(ft.attemps);
    } else {
        ft.percent = 0;
    }
}
// 第一个修改后，main函数中传的变量也会随之修改
// 第二个不会被修改
free_throws& accumulate(free_throws& target, const free_throws& source) {
    target.attemps += source.attemps;
    target.made += source.made;
    set_pc(target);
    return target;  //注意target变量的生命周期，如果是其他在函数内部存在的变量，则不能返回。
                    //见plus P284.
}

/*
问题：函数返回引用与传统返回机制的不同之处？
答：传统返回机制将return后面的表达式的值复制到一个临时位置，调用函数时将使用这个值。
但在返回值为引用时，直接用上该值，少去了将值复制到临时位置这一过程，效率更高。

*/