// //function defintions
// // #include "Sales_item.h"--moved to another directory?
// #include <list>
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>

// #include <algorithm>
// #include <functional>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <utility> //includes pair
// #include <memory>

// //note that sales class data constructor is in basicCh11_3_MultiMap.txt

// using namespace std;

// /*
//    Word transformation functions!!
//  */
// const string &transform(const string &s, const map<string, string> &m);

// map<string, string> buildMap(ifstream &reference_file);

// void word_transformation(ifstream &input_file, ifstream &reference_file);

// /*
//    END transformation functions!!
//  */

// //best practice is to declare and define all inline and constexpr functions inside header files only: they must all match exactly and definition must be known at compile time.
// inline bool is_shorter (const string& a, const string& b){
//   return  (a > b) ? true : false;
// }

// /*
//   PRINT FUNCTIONS!!
// */

// void print_map_string_stringvec(map<string, vector< string > > a){
//   for(auto c : a){
//     cout << "Family Name: " << c.first << ", has the following children:\n";
//     int a(1);
//     for(auto d : c.second){
//       cout << a << ". " << d << endl;
//       a++;
//     }
//   }
// }

// void print_map_string_vecPair_string_string(map<string, vector<pair<string,string>>> a){

//   for(auto c : a){ //c has type pair string vec_pair
//     cout << "Family Name: " << c.first << ", has the following children:\n";
//     int a(1);
//     for(auto d : c.second){ //d has type pair<string,string>
//       cout << a << ". " << d.first << "\t";
//       cout << d.first << "'s birthday is: " << d.second << endl;
//       a++;
//     }
//   }
// }

// void print_map_iterator(map<string, vector<int>>::iterator map){
//   cout << map->first << " is the first element.. " << endl;
//   cout << map->second[1] << " is the second element of the vector space.. " << endl;
// }

// void print_multiMap_stringString(multimap<string, string> map){
//   multimap<string, string>::iterator start = map.begin();
//   while(start != map.end()){
//     cout << start->first << " is the author name .. ";
//     cout << start->second << " is the work .. " << endl;
//     start++;
//   }
// }

// // function for ch12 ex 6
// shared_ptr<vector<int>> make_shared_vector(vector<int> vec_int){
//   shared_ptr<vector<int>> shared_vec_int(new vector<int> (vec_int));
//   return shared_vec_int;
// }

// // now make a function to print the values which we read..

// ostream& print_shared_vector(ostream& os, shared_ptr<vector<int>> shared_vec_int){

//   for(auto c : *shared_vec_int){
//     os  << c << "\n";
//   }
//   return os;
// }

// // additional smart pointer practice:

// void process_1(shared_ptr<int> ptr){
//   cout << *ptr << " is the value pt shared_ptr " << ptr.use_count() << "\n";
// }

// // part of exercises 12.14 / 12.15
// struct Data
// {
//   Data() = default;
//   int value;
//   int value2;
// };

// struct Analysis
// {
//   Analysis() = default;
//   int value;
// };

// Analysis analyze(Data *d){
//   Analysis a;
//   a.value = 2*d->value;
//   return a;
// }

// void stopAnalyze(Analysis){
//   printf("analysis complete.\n");
// }

// void endAnalysis(Analysis* a){
//   stopAnalyze(*a);
// }

// void manage_analysis(Data &c){
//   cout << "running analysis.." << endl;
//   Analysis d = analyze(&c);
//   shared_ptr<Analysis>p(&d , endAnalysis);
// }

// // ex 12.15 wants to use endAnalysis as a lambda fnc instead..
// void manage_analysis2(Data &c){
//   cout << "running analysis2..\n";
//   Analysis d = analyze(&c);
//   shared_ptr<Analysis>p(&d, [](Analysis *a){stopAnalyze(*a);});
// }
// #include "basic.hh"
#include "StrBlob.hh"

// reads a txt file
// stores first line of text file into 'items'
// reads the rest of the data line by line, associating each column with the column name
//

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
