#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <vector>

using namespace std;

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

    //note: implicit constructors: 
    //any single parameter constructor without they keyword: explicit, can be
    //made to be used as an implicit constructor. (see the call to combine().. )
    //to prevent implict conversion, use explicit in the constructor declaration..
    //use explicit constructors when you must for direct initialization of that class.

    //~~MEMBER FUNCTIONS - functions defined here are implicitly inline..
    std::string isbn() const { return bookNo; };

    Sales_Data &combine(const Sales_Data &);
    // Sales_Data &combine(Sales_Data);
    // Sales_Data &combine(Sales_Data&);
    // Sales_Data &combine(const Sales_Data&) const;

    double avg_price() const;

    //~member values
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

  private:
    //~~defined public functions - friends
};

class Person
{
    //friend functions are externally declared / defined functions
    //they have access to private data memebers..
  public:
    // default constructor can be used by setting the below arguement in the parentheses
    explicit Person(istream &is = std::cin); // effective default
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
    // mutable unsigned access_ctr = 0;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    //private memeber functions
    void do_display(std::ostream &os) const { os << contents; }

    //do you have any friends??
    //friends MUST be decalred outside of the class scope..
    friend class Window_mgr;
};

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

//example of a literal class..
class Debug 
{
  public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }
    
    constexpr bool any () { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }

  private:
    bool hw;
    bool io;
    bool other;
};

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


//examples for the use of static data members.
class Account
{
  public:
    static double interest_rate() { return current_rate;}
    static void rate(double);
    const int get_int_period() { return period; }

  private:
    static constexpr int vec = 0;
    vector<double> vec_dbl[vec];
    static double current_rate;
    static constexpr int period = 30;
    // double daily_tbl[period]; //not really used in the examples..
};