#include "basic.hh"
#include "StrBlob.hh"

typedef std::vector<std::string>::size_type size_type;
// section 13.1 Copy, Assign, Destroy
// 13.1.1 Copy Constructor
// e.g.
class foo
{
 public:
  foo();           // default constructor
  foo(const foo&); // copy constructor
};
// Chapter 13 exercises
// #1 - When is the copy constructor used?
// - pass an object as an argument to a parameter of nonreference type
// - Return an object from a function that has nonreference return type
// - Brace initilaize the elements in an array or the members of an aggregate class
//
// #2 - Why is the following illegal?
// foo::foo(foo rhs);
// copy constructor must pass its first arugment by reference..
//
// #3 - what about StrBlobs and StrBlobPtrs?
  // StrBlob sb1({"this","is","my","design"});
  // StrBlob sb2;

  // // copy 2 from 1
  // sb2 = sb1;

  // // make a new StrBlobPtr..
  // StrBlobPtr sbp1(sb2);
  // StrBlobPtr sbp2;

  // // copy 2 from 1
  // sbp2 = sbp1;
  // // keep going until a break in an exception..
  // while(true)
  // {
  //   // attempt to find the words and go to next item
  //   try
  //   {
  //   std::cout << sbp2.deref() << std::endl;
  //   sbp2.incr();
  //   }
  //   // look for when you're at the end.
  //   // this is the built in 'stop' condition..
  //   catch(const std::out_of_range& oor){
  //     std::cerr << "finished looking for the StrBlob! " << oor.what() << std::endl;
  //     break;
  //   }
  // }

// exercise 13.5 - make a copy constructor for the class sketch below.
// the constructor should dynamically allocate a new string and copy
// the object to which ps points..
class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {  }

    HasPtr(HasPtr& hp) : ps(new std::string(*hp.ps))  , i(0) {  } // copy constructor which makes a new element
    // new element is dynamically allocated and copies the values to which hp.ps points..

    HasPtr& operator=(const HasPtr& rhs);
    void print() const; // define some print function..
  private:
    std::string *ps;
    int i;
};

// look for a way to check the output..
 void HasPtr::print() const
{
  std::cout << *(this->ps) << std::endl;
}
  // HasPtr a("this is my Design"); // make an element with a string..
  // a.print();

  // HasPtr b(a); // copy into a new element b
  // b.print();   // check the output..

// correct version of the copy assignment operator..
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
  // make sure you get a new string memory slot
  auto newps = new std::string(*rhs.ps);

  // get rid of the old one
  delete ps;

  // copy assign the the new object
  ps = newps;
  i   = rhs.i;

  // get the new object
  return *this;
}

// Overloaded Assignment:
// - The Copy-Assignment operator
// - return types of references to left hand operand..
//
// Exercise 13.6 - what is a copy assignment operator?
// ex: object& object::operator= (object& rhs)
// the compiler will generator this operator if a class does not define it
// the compiler will return a lhs& to the object it is called on
// the copy assignment will member assign copies of each element from rhs to lhs

// Exercise 13.7 - what happens when we copy assignment StrBlobs and StrblobPtrs?
// this was done in chapter 12. They will member copy each element from rhs into lhs.
// the compiler automagically generator this operator for the class since we didn't define one.

// Exercise 13.8 - write the assignment operator for the HasPtr class.
// Make sure to copy the object to which ps points..

// Chapter 13 notes.. Copy Control
int main(int argc, char **argv)
{
  printf("hello worlds!\n");

  HasPtr a("this is my Design"); // make an element with a string..
  a.print();

  HasPtr b(a); // copy into a new element b
  b.print();   // check the output..

  // let's use that copy assignment operator! :D
  HasPtr c = b;
  c.print();

  return 0;
}
