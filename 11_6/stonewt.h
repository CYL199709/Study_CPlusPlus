//stonewt.h --definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt{
    private:
    enum{Lbs_per_sth = 14}; //pounds per stone
    int stone;
    double pds_left;
    double pounds;

    public:
    Stonewt(double lbs);
    Stonewt(int stn,double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    //转换函数
    operator int() const;
    operator double() const;
};
#endif
