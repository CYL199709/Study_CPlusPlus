// stonewt.cpp --Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"
Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_sth;
    pds_left = int(lbs) % Lbs_per_sth;
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_sth + lbs;
}
Stonewt::Stonewt() { stone = pounds = pds_left = 0; }
Stonewt::~Stonewt() {}
void Stonewt::show_stn() const {
    cout << stone << "stone, " << pds_left << " pounds\n";
}
void Stonewt::show_lbs() const { cout << pounds << " pounds\n"; }

Stonewt::operator int() const {
    return int(pounds+0.5);
}

Stonewt::operator double() const {
    return pounds;
}