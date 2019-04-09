#include "basic.hh" //includes algorithm, function, vector headers, etc..
#include <sstream>  // 4 is the place where istringstream is located..

// chapter 7 cpp textbook notes, for some reason i skipped the chapter including classes..

using namespace std;

// keep in mind that a class has data_members private by default, in contrast with struct..
// basic overlay of what a class looks like:
class Sales_Data
{
public:
  //~~~~~~CONSTRUCTORS~~~~~~
  Sales_Data() = default;
  Sales_Data(const std::string &s) : bookNo(s) { };
  Sales_Data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) { };
   
  //~~MEMBER FUNCTIONS - functions defined here are implicitly inline..
  std::string isbn() const { return bookNo; };
  Sales_Data& combine(const Sales_Data&);
  double avg_price() const;

  //~member values 
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

private:
//~~defined public functions - friends
};


double Sales_Data::avg_price() const 
{
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

Sales_Data& Sales_Data::combine(const Sales_Data & rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

class Person 
{
//friend functions are externally declared / defined functions 
//they have access to private data memebers..
public:
  Person() = default;
  Person(const string &nm) : name(nm) { };
  Person(const string &nm, const string &addr) : name(nm), address(addr) { };
  Person(istream &is);

  //note that the below are const member functions as const follows the function declaration..
  //const member functions modify this identify that the parameters of the person class they are called on won't change..
  string getName() const { return this->name; }
  string getAddress() const { return this->address; }
  void setName(string nme) {this->name = nme;}
  void setAddress(string addr) {this->address = addr;}

private:
  string name;
  string address;
};

  // use this badboy to fill information about a person..
  istream& read_person(istream &is, Person &p)
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

  ostream& print_person(ostream &os, Person &p)
  {
    os << "address is: " << p.getAddress() << endl;
    os << "name is: " << p.getName() << endl;

    return os;
  }

class Screen 
{
  public: 
    typedef std::string::size_type pos;
    //Constructors
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') { }

    //member functions
    char get() const 
      { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
  
  private:
    //mutable data memebers can always be changed, even by const memever functions
    mutable unsigned access_ctr = 0;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

class Window_mgr 
{
  private:
    //Window_mgr stores a vector of screens, and is default initialized with a single element
    //notice the single element uses Screen-class initializer..
    std::vector<Screen> screens { Screen(24, 80, ' ') } ;
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

    //7.5 - create your own person class..
    Person you("name");
    read_person(cin, you);
    print_person(cout, you);

    //constructors
    Person me(cin); //create a person from standard input calling the read_person function
    print_person(cout, me);

    //sect 7.2 -
    // public vs. private : public memembers are directly available to code outside of class.
    // whereas private members are only available to class member functions. (encapsulation)
    // struct vs. class - default data member are public vs. private..


    return 0;
  }
