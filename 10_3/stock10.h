// stock10.h -- Stock 类 接口 加上了构造函数和析构函数
// version 00
#ifndef STOCK10_H_
#define STOCK10_H_

#include <string>
class Stock {  // 类 声明
   private:
    std::string company;  // 公司名称
    long shares;          // 所持股票数量
    double share_val;     // 每股价格
    double total_val;     // 股票总值
    void set_tot() { total_val = shares * share_val; }

   public:
    //两个构造函数
    Stock();  //默认构造函数
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    //析构函数
    ~Stock();
    void buy(long num, double price);   // 增持
    void sell(long num, double price);  //卖出股票
    void update(double price);          //更新股票价格
    void show();                        //显示关于所持股票的信息
    const Stock &topval(const Stock &s) const;
};  //注意：此处要有分号

#endif