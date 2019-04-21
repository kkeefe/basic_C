#include "salesData.hh"
#include <iostream>

using namespace std;

//define constructors for your data members
// Sales_Data::Sales_Data(std::istream & is){
//   read(is, *this);
// }
  
//member functions must be declared in the sales_data struct, but may not be defined here;
//all functions defined here are implicitly inline functions
string Sales_Data::isbn() const{return sales_isbn;}
int Sales_Data::sales() const{return sales_count;}
double Sales_Data::price() const{return sales_price;}
Sales_Data& Sales_Data::combine(const Sales_Data &rhs){
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
};

void Sales_Data::add_total(const Sales_Data & data1){
  units_sold += data1.sales_count;
  double price;
  price = data1.sales_count * data1.sales_price;
  revenue += price;
}

void Sales_Data::print_total(){
  cout << units_sold << " units sold " << endl;
  cout << revenue << " total revenue " << endl;
}

//define a read function to take values from a stream, be sure to not have constant member type for data1
std::istream & read(std::istream & is, Sales_Data& data1){
  cout << "enter sales count " << endl;
  is >> data1.sales_count;
  cout << "enter sales isbn " << endl;
  is >> data1.sales_isbn;
  cout << "enter sales price " << endl;
  is >> data1.sales_price;
  return is;
}

//define a print function to put values of data1 onto a stream
std::ostream &  print(std::ostream & os, const Sales_Data& data1){
  os << data1.sales_count << " is sales count of data " << endl;
  os << data1.sales_isbn << " is sales isbn of data " << endl;
  os << data1.sales_price << " is sales price of data " << endl;
  return os;
};

