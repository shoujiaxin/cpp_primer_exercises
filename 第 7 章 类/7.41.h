#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

 public:
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(n * p) {
    std::cout << "Sales_data(const std::string&, unsigned, double)"
              << std::endl;
  }
  Sales_data() : Sales_data("", 0, 0.0f) {
    std::cout << "Sales_data()" << std::endl;
  }
  Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {
    std::cout << "Sales_data(const std::string&)" << std::endl;
  }
  Sales_data(std::istream &is);
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

 private:
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
  double avg_price() const;
};

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = data.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

#endif
