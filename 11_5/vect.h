// vect.h
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
namespace VECTOR {
class Vector {
   public:
    enum Mode { RECT, POL };  //表示矢量的两种方式
   private:
    double x;
    double y;
    double mag;
    double ang;
    Mode mode;

    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

   public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const { return x; }
    double yval() const { return y; }
    double magval() const { return mag; }
    double angval() const { return ang; }
    void polar_mode();  // set mode to POL
    void rect_mode();   // set mode to RECT

    //运算符重载
    Vector operator+(const Vector& b) const;
    Vector operator-(const Vector& b) const;
    Vector operator-() const;
    Vector operator*(double n) const;

    //友元函数
    friend Vector operator*(double n, const Vector& a);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};
}  // namespace VECTOR

#endif
