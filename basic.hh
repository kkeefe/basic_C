//function defintions
// #include "Sales_item.h"--moved to another directory?
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <utility> //includes pair


using namespace std;


//define a struct class type
class Sales_Data {

public:
  //~~~~~~CONSTRUCTORS~~~~~~
  //define constructors for your data members
  Sales_Data() = default;
  Sales_Data(const std::string& s) : sales_isbn(s) {}
  Sales_Data(const std::string& s, const int i) : sales_isbn(s), sales_count(i){}
  Sales_Data(const std::string& s, const int i, double d) : sales_isbn(s), sales_count(i), sales_price(d){};
  Sales_Data(std::istream & is);

  //~~MEMBER FUNCTIONS
  //all functions defined here are implicitly inline functions
  string isbn() const;
  int sales() const;
  double price() const;
  Sales_Data& combine(const Sales_Data &rhs);
  void add_total(const Sales_Data & data1);
  void print_total();

private:
  //~member values
  unsigned units_sold = 0;
  double revenue = 0.0;
  string sales_isbn;
  unsigned sales_count;
  double sales_price;

//~~defined public functions
friend std::istream & read(std::istream & is, Sales_Data& data1);
friend std::ostream &  print(std::ostream & os, const Sales_Data& data1);
};

//old functions defined previously
void reset(int& a);
void swap_int(int& a, int& b);
void swap_var(int*a, int*b);
double square (double x);
int factorial (int x);
int abs_value(int a);
void Interact(int a);
int function_counter(int a);

//best practice is to declare and define all inline and constexpr functions inside header files only: they must all match exactly and definition must be known at compile time.
inline bool is_shorter (const string& a, const string& b){
  return  (a > b) ? true : false;
}


/*
  PRINT FUNCTIONS!!
*/


void print_map_string_stringvec(map<string, vector<string>> a){
  for(auto c : a){
    cout << "Family Name: " << c.first << ", has the following children:\n";
    int a(1);
    for(auto d : c.second){
      cout << a << ". " << d << endl;
      a++;
    }
  }
}

void print_map_string_vecPair_string_string(map<string, vector<pair<string,string>>> a){
  for(auto c : a){ //c has type pair string vec_pair
    cout << "Family Name: " << c.first << ", has the following children:\n";
    int a(1);
    for(auto d : c.second){ //d has type pair<string,string>
      cout << a << ". " << d.first << "\t";
      cout << d.first << "'s birthday is: " << d.second << endl;
      a++;
    }
  }
}

