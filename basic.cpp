#include "basic.hh"
#include "StrBlob.hh"

// reads a txt file
// stores first line of text file into 'items'
// reads the rest of the data line by line, associating each column with the column name
// 
class queryData
{
using std::vector<vector<double>> = Data;
private:
  std::shared_ptr<Data> data; // place to point to where the data is 
  std::shared_ptr<map<std::string , std::set<string>>> names; // what are the names associated with each data type
  std::shared_ptr<map<std::string , std::set<int>>> dataRows; // what rows is this data found on

public:
  queryData queryData(std::ifstream &);
};

class dataResult
{
private:
  std::shared_ptr<Data> data; // place to point to where the data is 
  std::string dataName;
  std::shared_ptr<map<std::string , std::set<string>>> names; // what are the names associated with each data type
  std::shared_ptr<map<std::string , std::set<int>>> dataRows; // what rows is this data found on
public:
  basic dataResult();
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////// textbook stuff: /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
using line_no = std::vector<std::string>::size_type; // type alias
class QueryResult;
class TextQuery
{
  public:
    TextQuery(std::ifstream&); // constructor
    QueryResult query(const std::string&) const;
  private:
    std::shared_ptr<std::vector<std::string>> file; //input file
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

// let's now define the QueryResult class:
class QueryResult
{
  friend std::ostream &print(std::ostream&, const QueryResult&);
  public:
    // much better to store ordering information in a set -> auto sorts -> easier to ignore duplicates.
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}
  private:
    std::string sought; // word you're looking for 
    std::shared_ptr<std::set<line_no>> lines; // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};

// lets define that constructor:
TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
  // define the line you're going to read
  string text;
  
  // get the line from istream
  while( getline(is , text)){
    
    // add the stream to the file
    file->push_back(text);
    
    // keep track of where you are
    int n = file->size() - 1;
    
    // define what word you're on
    istringstream line(text);
    string word;
    
    // do something for every word..
    while ( line >> word ){
      // lines is a shared_ptr here
      auto &lines = wm[word];
      // if lines is empty, do something with it
      if(!lines) lines.reset(new set<line_no>);
      // add number to this set if it's new, 
      // if it's already in there, set type doesn't do anything
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const string &sought) const
{
  // we'll return a pointer to this set if we don't find sought..
  static shared_ptr<set<line_no>> nodata(new set<line_no>);

  // use find to locate something in a map
  auto loc = wm.find(sought);
  // if we're at the end of the map we didn't find anything..
  if( loc == wm.end())
    return QueryResult(sought , nodata , file); // not found
  else
    return QueryResult(sought, loc->second , file); // found ;)
}

// finally define the print function:
ostream& print(ostream& os, const QueryResult& qr)
{
  os << qr.sought << " occurs " << qr.lines->size() << " time(s)\n";
  for(auto num : *qr.lines){
    os << "\tlines " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
  }
  return os;
}

void runQueries(ifstream &infile){
  TextQuery tq(infile);
  // not much different with a do-while, 
  // except that the loop is guaranteed to be executed..
  while(true){
    string looking_for;
    cout << "please enter a string you want to search for: ";
    cin >> looking_for;
    if (looking_for == "exit") break;
    auto result = tq.query(looking_for);
    print(cout , result);
  }
}
////////////////////////////////////////////////////////////////////////////////

// Chapter 12 notes.. Dynamic Memory
int main(int argc, char **argv)
{

  // // Exercise 12.26 - rewrite the program from the previous section using an allocator
  // // this is exercises 12.23-26 together..
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

  std::string filename("blah.txt");

  std::ifstream inputfile(filename);
  std::string s;
  char w[];
  char* word("ni hao");
  char* jword("konichiwa");
  while(inputfile >> w)
  {
    if(!inputfile.eof()) cout << w << endl;
  }

return 0;
}