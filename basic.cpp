#include "basic.hh" //includes algorithm, function, vector headers, etc..
#include "classes.hh"

// chapter 7 cpp textbook notes, for some reason i skipped the chapter including classes..

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
  // constructors of classes which take a single arguement are converting constructors
  // item is default initialized.
  // inside of combine(), cin is implicitly converted to a temp Sales_Data object..
  // Sales_Data item;
  // item.combine(cin); //example of implicitly converting cin to Sales_Data..
  // print_data(cout, item);

  //exercises 7.5.4:
  //7.47 - when to use explicit: when you want to prevent the use of a constructor as a 
  // user defined conversion function.

  // //7.48 what happens if the constructors for sales data are implicit or explicit 
  // string null_isbn("9-999-99999-9");
  // Sales_Data item1(null_isbn);
  // Sales_Data item2("9-999-99999-9");
  // print_data(cout, item1);
  // print_data(cout, item2);
  // //everything works whether they're explicit or not in both 11 / 17 standards

  //7.49: using different combine() function types.
  // Sales_Data i("9-999-99-9", 2, 14.99);
  // string s("ni hao");
  // i.combine(s); //implict conversion using the string constructor!
  /* 
  Sales_Data &combine(Sales_Data); //works, there is a Sales_Data(string) constructor..
  Sales_Data &combine(Sales_Data&); //Sales_Data& can't be initialized by a string..
  Sales_Data &combine(const Sales_Data &) const; //this doesn't work because you can't 
  modify the value you're trying to pass, so combine is not a good const member function..
  below, s is some string value, and is attempted to be implicitly converted to a  viable
  Sales_Data type which can be passed to combine()..
  */

 //7.50 - vector uses explicit, but string does not, why?
  /*
  the use of implicit conversions is desirable for strings: "text"
  but this same behavior would not be desirable to vectors, since single
  argument constructors would be confusing to initialize vectors, but a 
  string constructor is always a single argument, making it more clear.
  */

  //7.5.5 Aggregate Classes -
  /*
  -> All Data members public
  -> no constructors
  -> no in-class initializers
  -> no base classes or virtual functions

  all members are public, and they must be initalized in declaration in the 
  same order as they're defined in the class.
  */

  //7.5.6 - Literal Classes
  /*
  -> all members have literal type
  -> must have atleast one const expr constructor
  -> if a data member has an in-class initializer, initializer must be constexpr
    -> see debug class
  -> class must use default definition for its destructor
  */

 //7.6 static data members
 /*
  -> static members are "global" to the class and don't belong to any class object..
  functions and data memebers can be static..
  -> const static member functions should be defined outside of the class..
  -> Static members may have incomplete type, and may even refer to class type itself..
 */
  
  Account yours;
  double val(10);
  yours.rate(val);

  Account mine;
  cout << mine.interest_rate() << endl;;
  cout << mine.get_int_period();

  return 0;
}