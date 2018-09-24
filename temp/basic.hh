#include <iostream>

using namespace std;

//X has a pointer to Y
class Element
{
  friend std::ostream & print(std::ostream &, const Element &);
  friend std::istream & read(std::istream &,  Element &);

public:
  Element() : atomic_number(1), atomic_mass(1.0079), shell('s'), name("hydrogen"){};
  Element(unsigned a, double b, char c, string d) : atomic_number(a), atomic_mass(b), shell(c), name(d){};


  
private:
  unsigned atomic_number = 0;
  double atomic_mass = 0;
  char shell;
  string name;
  
};

std::ostream & print(std::ostream & os, const Element & y)
{
  os << y.atomic_number << " is atomic nunmber " << endl;
  os << y.name << " is the name of the element " << endl;
  return os;
}

std::istream & read(std::istream & is, Element & y)
{
  is >> y.atomic_number;
  is >> y.name;
  return is;
}
