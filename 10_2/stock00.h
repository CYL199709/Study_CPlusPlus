// stock00.h -- Stock 类 接口
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>
class Stock {  // 类 声明
   private:
    std::string company;  // 公司名称
    long shares;          // 所持股票数量
    double share_val;     // 每股价格
    double total_val;     // 股票总值
    void set_tot() { total_val = shares * share_val; }

   public:
    void acquire(const std::string& co, long n, double pr);  //获得股票
    void buy(long num, double price);                        // 增持
    void sell(long num, double price);                       //卖出股票
    void update(double price);  //更新股票价格
    void show();                //显示关于所持股票的信息
};  //注意：此处要有分号

#endif