// mytime0.h -- 运算符重载前的 Time 类
#ifndef MYTIME0_H_
#define MYTIME0_H_
#include <iostream>
class Time {
   private:
    int hours;
    int minutes;

   public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(double n) const;
    friend Time operator*(double m, const Time& t) {
        return t * m;
    }  //内联 友元函数
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
#endif