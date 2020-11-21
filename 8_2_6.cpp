#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
void file_it(ostream &, double, const double[], int);
const int LIMIT = 5;

int main() {
    ofstream fout;
    const char *fn = "ep-data.txt";
    //cout << fn << endl; //ep-data.txt
    //cout << *fn << endl; //e
    fout.open(fn);
    if(!fout.is_open()){
        cout<<"Can't open "<<fn<<".  Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout<<"Enter the focal length of your "
          "telescope ojective in mm: ";
    cin>>objective;
    double eps[LIMIT];
    cout<<"Enter the focal lengths, in mm, of "<<LIMIT
        << " eyepieces:\n";
    for(int i=0;i<LIMIT;i++){
        cout<<"Eyepiece #"<<i+1<<":";
        cin>>eps[i];
    }
    file_it(fout,objective,eps,LIMIT);
    file_it(cout,objective,eps,LIMIT);
    cout<<"Done\n";
    return 0;
}

void file_it(ostream &os, double fo, const double fe[], int n) {
    ios_base::fmtflags initial;
    //setf用于设置各种格式化状态。
    //ios_base::fixed 使用定点表示法
    initial = os.setf(ios_base::fixed); 
    os.precision(0); //表示显示多少位小数
    os << "Focal length of objective: " << fo << "mm\n";
    //ios_base::showpoint 显示小数点模式
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);//设定下一次输出使用的字段宽度
    os << "f.l. eyepiece";
    os.width(24);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }
    os.setf(initial);
}