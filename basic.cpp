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
  ~foo(); // total annaihilation
};

class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {  }

    HasPtr(HasPtr& hp) : ps(new std::string(*hp.ps))  , i(0) {  } // copy constructor which makes a new element
    // new element is dynamically allocated and copies the values to which hp.ps points..

    HasPtr& operator=(const HasPtr& rhs);
    // note that this synthesized destructor will not delete the built-in pointer.
    // which was created with new
    ~HasPtr() { }; // make dat destructor - Ex13.11
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

// // #13
// // given the basic code below: add a copy-assignment operator and a destructor
// struct X
// {
//   X() {std::cout << "X()" << std::endl;}
//   X(const X&) {std::cout << "X(const&X)" << std::endl;}
// };
//
// note the rest of this stuff in the org file for chapter notes..


// Chapter 13 notes.. Copy Control
int main(int argc, char *argv[])
{
  //   HasPtr a("this is my Design"); // make an element with a string..
  // a.print();

  // HasPtr b(a); // copy into a new element b
  // b.print();   // check the output..

  // // let's use that copy assignment operator! :D
  // HasPtr c = b;
  // c.print();

  // std::string filename("blah.txt");

  // std::ifstream inputfile(filename);
  // std::string s;
  // char w[];
  // char* word("ni hao");
  // char* jword("konichiwa");
  // while(inputfile >> w){
  //   if(!inputfile.eof()) cout << w << endl;
  // }

  return 0;

}
