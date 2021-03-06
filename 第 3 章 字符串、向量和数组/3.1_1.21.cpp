#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data data1, data2;
  double price = 0;
  cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;
  cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  if (data1.bookNo == data2.bookNo) {
    unsigned int totalNum = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;
    double ave = totalRevenue / totalNum;
    cout << data1.bookNo << " " << totalNum << " "
         << data1.revenue + data2.revenue << " " << ave << endl;
  }
  return 0;
}
