#include <iostream>

using namespace std;

//X has a pointer to Y
class Element
{
  friend std::ostream & print(std::ostream &, const Element &);
  friend std::istream & read(std::istream &,  Element &);

public:
  Element() : atomic_number(1), atomic_mass(1.0079), shell('s'), name("hydrogen"){};
  Element(int a, double b, char c, string d) : atomic_number(a), atomic_mass(b), shell(c), name(d){};
  Element(int a) : Element(a, 0.00, '0', "undefined"){};
  Element(int a, double b) : Element(a, 0.00, b, "undef"){};
  Element(double b, char c) : Element(1, b, c, "undefined"){};
  Element(double b, string d) : Element(2, b, '0', d){};
  Element(char c, string d) : Element(3, 0.00, c, d){};
				
private:
  int atomic_number = 0;
  double atomic_mass = 0;
  char shell;
  string name;
  
};

std::ostream & print(std::ostream & os, const Element & y)
{
  os << y.atomic_number << " is atomic nunmber " << endl;
  os << y.atomic_mass << " is atomic mass " << endl;  
  os << y.name << " is the name of the element " << endl;
  os << y.shell << " is the shell of the element " << endl;  
  return os;
}

std::istream & read(std::istream & is, Element & y)
{
  cout << "atomic number: ";
  is >> y.atomic_number;
  cout << "Element name: "; 
  is >> y.name;
  cout << "atomic mass: ";
  is >> y.atomic_mass;
  cout << "shell: ";
  is >> y.shell;  
  
  return is;
}
