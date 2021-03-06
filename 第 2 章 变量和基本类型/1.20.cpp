#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data data;
  double price = 0;
  while (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue
              << " " << price << std::endl;
  }
  return 0;
}
