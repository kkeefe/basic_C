#include <sstream>  // 4 is the place where istringstream is located..
#include "basic.hh" //includes algorithm, function, vector headers, etc..

// chapter 7 cpp textbook notes, for some reason i skipped the chapter including classes..

using namespace std;

// keep in mind that a class has data_members private by default, in contrast with struct..
// basic overlay of what a class looks like:


class Sales_Data
{

friend std::istream &read_data(std::istream &, Sales_Data&);
friend std::ostream &print_data(std::ostream &, const Sales_Data&);

public:
  //~~~~~~CONSTRUCTORS~~~~~~
  Sales_Data() = default;
  Sales_Data(const std::string &s) : bookNo(s){};
  Sales_Data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p){};
  Sales_Data(std::istream &is) : Sales_Data() { read_data(is, *this) ; };

  //~~MEMBER FUNCTIONS - functions defined here are implicitly inline..
  std::string isbn() const { return bookNo; };
  Sales_Data &combine(const Sales_Data &);
  double avg_price() const;

  //~member values
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

private:
  //~~defined public functions - friends
};

inline double Sales_Data::avg_price() const
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

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

class Person
{
  //friend functions are externally declared / defined functions
  //they have access to private data memebers..
public:
  // default constructor can be used by setting the below arguement in the parentheses
  Person(istream &is = std::cin); // effective default
  // Person() = default;
  Person(const string nm) : name(nm){};
  Person(const string &nm, const string &addr) : name(nm), address(addr){};

  //note that the below are const member functions as const follows the function declaration..
  //const member functions modify this identify that the parameters of the person class they are called on won't change..
  string getName() const { return this->name; }
  string getAddress() const { return this->address; }
  void setName(string nme) { this->name = nme; }
  void setAddress(string addr) { this->address = addr; }

private:
  string name;
  string address;
};


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

class Screen
{
  typedef std::string::size_type pos;

public:
  //Constructors~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //default consructors generally not useful for classes which allocate
  //resources outside of the class structure..
  Screen() = default; //required when specifying additional constructors
  Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

  //member functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  char get() const
  {
    return contents[cursor];
  }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos r, pos col, char c);
  Screen &display(std::ostream &os)
  {
    do_display(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const
  {
    do_display(os);
    return *this;
  }

private:
  //mutable data memebers can always be changed, even by const memever functions
  mutable unsigned access_ctr = 0;
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  //private memeber functions
  void do_display(std::ostream &os) const { os << contents; }

  //do you have any friends??
  //friends MUST be decalred outside of the class scope..
  friend class Window_mgr;
};

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

class Window_mgr
{
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);
  ScreenIndex addScreen(const Screen &s);

private:
  //Window_mgr stores a vector of screens, and is default initialized with a single element
  //notice the single element uses Screen-class initializer..
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

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

//exercise 7.3.3 - forward declaration
struct Y;
struct X
{
  int value_y;
  Y *stuff;
};

struct Y
{
  X value_y;
};

//exercise 7.40 - create an abstraction of a class
class Element
{
public:
  //Constructors  
  Element(int num, double mass, string nm) : atomic_num(num), atomic_mass(mass), name(nm){};
  //make these bad bois some default constructors..
  Element(int num) : Element(num, 0.00, "blank"){};
  Element(double mass) : Element(0, mass, "blank"){};

  //member functions
  double getMass() { return atomic_mass; }
  int getNum() { return atomic_num; }
  string getName() { return name; }

private:
  //memebers!!
  int atomic_num;
  double atomic_mass;
  string name;
};

int main(int argc, char **argv)
{
  //7.1 defining abstract data types
  // some key words to know:
  // interface        - things available to the user to interact with a class
  // implementation   - data members / member functions of a class that include private and public memebers..
  // data abstraction - refers to a programming technique which relies on interface and implementation..
  // encapsulation    - enforces the separation of a class' interface and implementation

  // cout << "hey there! " << endl;
  // Sales_Data first;
  // cout << "enters how many units you sold: ";
  // cin >> first.units_sold;
  // cout << "\nyou sold: " << first.units_sold << " number of books.. \n";
  // for (int i = 0; i < first.units_sold; i++)
  // {
  //   cin >> first.revenue;
  // }
  // cout << "you have made: " << first.revenue << " monies!\n";

  //7.1.2
  //7.2 - include the above member function definitions..
  //7.3 - revise previous program steps..
  // Sales_Data second;
  // printf("enter the following:\n isbn: ");
  // cin >> second.bookNo;
  // printf("\nunits sold: ");
  // cin >> second.units_sold;
  // printf("\nrevenue: ");
  // cin >> second.revenue;
  // printf("avg value is: ");
  // cout << second.avg_price();
  // second = second.combine(second);
  // printf("\ndouble that revenue is:");
  // cout << second.revenue;

  // //7.5 - create your own person class..
  // Person you("name");
  // read_person(cin, you);
  // print_person(cout, you);

  // //use the empty string default constructor..
  // Person no_one;
  // print_person(cout, no_one);

  //constructors
  // Person me(cin); //create a person from standard input calling the read_person function
  // print_person(cout, me);

  //sect 7.2 -
  // public vs. private : public memembers are directly available to code outside of class.
  // whereas private members are only available to class member functions. (encapsulation)
  // struct vs. class - default data member are public vs. private..

  //7.3 additional class features -
  //since the functions move() and set() return *this, you can call both
  //functions on my screen simultaneously. The functions return Screen&

  // Screen myScreen;
  // myScreen.move(0, 4).set('#');

  // Screen yourScreen(5,30);
  // const Screen blank(5,3,'2');

  // printf("\nmyScreen:\n");
  // myScreen.display(cout);
  // printf("\nyourSreen:\n");
  // yourScreen.set('#').display(cout);
  // printf("\nblank:\n");
  // blank.display(cout);

  // //exercise 7.27
  // // if the functions are set to return nonRefs, myScreen is unaffected by the function calls..
  // Screen myScreen(5,5,'X');
  // myScreen.move(4,0).set('#').display(cout);
  // cout << "\n";
  // myScreen.display(cout);
  // cout << "\n";

  //section 7.4 - Class Scope, another way of saying a class is its -own- scope
  // scope heirarchy:
  // -> Member function definition  item
  // -> Class scope <class::item>
  // -> Global surrounding (prev) scope < ::item>
  // if you define your own types in a class, they should be placed first..
  // just don't reuse names for anything..

  //section 7.5 - Constructors revisted:
  //the difference is between Initialization, and Assignment
  //Things that must be initialized: const refs, classes without default()~
  //data memebers are initialzed in order of their member declarations.
  //initialization order should match member declaration order.
  //almost always you want to define a default constructor..

  //implicite conversion : 
  //constructors of classes which take a single arguement are converting constructors
  // item is default initialized.
  // inside of combine(), cin is implicitly converted to a temp Sales_Data object..
  Sales_Data item;
  item.combine(cin);
  print_data(cout, item);

  return 0;
}