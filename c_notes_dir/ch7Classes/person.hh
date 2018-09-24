#include <initializer_list>
#include <iostream>
#include <fstream>
#include <string>
#include "basic.hh"
#include "Sales_item.h"

using namespace std;

class Person{

public:
  //~~~constructors
  Person();
  Person(istream & is);
  Person(std::string & a) : address(a){};
  Person(std::string & a, std::string &b) : address(a), phone_number(b){};
  Person(std::string & a, std::string &b, std::string &c) : address(a), phone_number(b), name(c){};

  //~~~member functions
  string get_address(const Person);
  string get_number(const Person);
  string function(const Person);

private:
  
  //~~~memeber values
  string address;
  string phone_number;
  string name;

//~~~~ friendly functions
friend std::istream & read(Person&, std::istream &);
friend std::ostream & print(const Person&, std::ostream&);
};

