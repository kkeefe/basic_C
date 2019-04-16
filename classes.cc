#include <iostream>
#include <string>
#include "classes.hh"


Sales_Data &Sales_Data::combine(const Sales_Data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream &read_data(std::istream &is, Sales_Data &sales)
{
  string book;
  printf("input bookNo: ");
  is >> book;
  sales.bookNo = book;

  unsigned solds_units;
  printf("input number of units sold: " );
  is >> solds_units;
  sales.units_sold = solds_units;

  double money_made;
  printf("input money made: ");
  is  >> money_made;
  sales.revenue = money_made;

  return is;
}

std::ostream &print_data(std::ostream &os, const Sales_Data &sales)
{
  os << "revenue: " << sales.revenue << endl;
  os << "bookNo: " << sales.bookNo << endl;
  os << "units_sold: " << sales.units_sold << endl;

  return os;
}

inline double Sales_Data::avg_price() const
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

// use this badboy to fill information about a person..
istream &read_person(istream &is, Person &p)
{
  string name, addr;
  printf("who are you?..\t");
  is >> name;
  p.setName(name);
  printf("where do you live?.. ");
  is >> addr;
  p.setAddress(addr);

  return is;
}

Person::Person(istream &is)
{
  read_person(is, *this);
}

ostream &print_person(ostream &os, Person &p)
{
  os << "address is: " << p.getAddress() << endl;
  os << "name is: " << p.getName() << endl;

  return os;
}

//note memeber function definitions are compiled after all class declarations have been seen.
inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char c)
{
  contents[r * width + col] = c;
  return *this;
}

inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const
{
  pos row = r * width;
  return contents[row + c];
}

void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = string(s.height * s.width, ' ');
}

//ScreenIndex is a type defined in Window_mgr and therefore it's return type must call the scope
//operator to use that same type.. class -> own scope..
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
  screens.push_back(s);
  return screens.size() - 1;
}

// constexpr int Account::period;
// constexpr int Account::vec;
double Account::current_rate;

void Account::rate(double a)
{
  current_rate = a;
}
