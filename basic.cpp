#include "basic.hh"
#include "StrBlob.hh"

// class queryData
// {
// using std::vector<vector<double>> = Data;
// private:
//   std::shared_ptr<Data> data; // place to point to where the data is 
//   std::shared_ptr<map<std::string , std::set<string>>> names; // what are the names associated with each data type
//   std::shared_ptr<map<std::string , std::set<int>>> dataRows; // what rows is this data found on

// public:
//   queryData queryData(std::ifstream &);
// };

// class dataResult
// {
// private:
//   std::shared_ptr<Data> data; // place to point to where the data is 
//   std::string dataName;
//   std::shared_ptr<map<std::string , std::set<string>>> names; // what are the names associated with each data type
//   std::shared_ptr<map<std::string , std::set<int>>> dataRows; // what rows is this data found on
// public:
//   basic dataResult();
// };

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


  int val = 5;
  // protip - do not assign uniq_ptr to val and then destroy it..
  unique_ptr<int> uniq_int2(new int (42));
  val = 6;
  cout << *uniq_int2 << ", value\n";
  cout << "still here! :) \n";
  cout << *uniq_int2 << ", value\n";

  // exercise 12.16 how does gcc respond to copy assignments of uniq_ptr?
  // below produces a malloc "pointer being freed was not allocated" error
  // unique_ptr<int> uniq_int(&val);
  //
  // exercise 12.17:
  // which of the following are illegal?

  int ix = 1024 , *pi = &ix , *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;
  // IntP p0(ix); // error no good type. ix is an int
  // IntP p1(pi); // malloc error on release
  // IntP p3(&ix); // malloc error on release.
  // IntP p5(p2.get()); // malloc error on release..
  IntP p4(new int(2048));
  IntP p2(pi2);


  double money(3.50);
  money = 5;

  // exercise 12.18:
  // why doesn't shared_ptr have a release memeber?
  // shared pointer can have many pointers to the same memory location..
  // it doesn't make sense to be able to 'free' all memebers at the same time,
  // this could equally be accomplished with deleting the location in memory, making
  // every one of the shared pointers a nullptr..

  // weak_ptr - does not control life time of memory
  // how to get access to a weak_ptr
  auto p = make_shared<int>(42);
  weak_ptr<int> wp(p);
  cout << wp.lock() << ", weak ptr .. \n";
  cout << *(wp.lock()) << ", weak value .. \n";
  wp.reset(); // make the ptr null
  wp.expired(); // check to see if w.use_count() is zero
  // weak_ptrs are useful for checking to see if shared_ptrs still exist
  // for the dynamic memory.


  // smart pointers , dynamic arrays , allocators
  // almost always better to use library containers.. but..

  // no initialization stuff with your array
  int *intArr_ptr = new int[7];
  cout << intArr_ptr << ", intArry ptr location.. \n";
  cout << *intArr_ptr << ", intArry value .. \n";
  // the method to kill this ptr..
  delete []intArr_ptr;

  // can list initialize your new dynamically created array!
  int *intArr_ptr2 = new int[7]{1,2,3,4,5,6,7};
  cout << intArr_ptr2 << ", intArry ptr location.. \n";
  cout << *(intArr_ptr2) << ", intArry value .. \n"; // default to zero
  intArr_ptr2 += 2; // point to a new position in the array
  cout << *(intArr_ptr2) << ", intArry value .. \n";

  // // unique_ptr<T>
  // // manage arrays allocated by new
  // unique_ptr<int[]>uniq1_ptr(new int[10]);
  // cout << uniq1_ptr << ", uniq1 ptr location.. \n";
  // // currently unitiialized! random output!!
  // cout << uniq1_ptr[1] << ", uniq1 value.. \n";
  // uniq1_ptr[1] = 10; // can assign values to it!
  // cout << uniq1_ptr[1] << ", uniq1 value.. \n";
  // uniq1_ptr.reset();

  // shared_ptrs must supply their own deleter to manage
  // dynamic arrays..
  shared_ptr<int> shr_p(new int[10] , [](int*p) { delete [] p; });
  cout << *shr_p << ", shr_p value.. \n";
  shr_p.reset();

  // the allocator class:
  allocator<double> alloc_data;

  // dblData now points to one past the allocated memory, n
  // this creates 5 places for doubles, and dblData points to the first element
  auto const dblData = alloc_data.allocate(5);

  // create another pointer at the same location, but this can change
  auto constructData = dblData;

  // make the element 5 in the new slot
  alloc_data.construct(constructData++ , 5);

  // make the element 7 in the second slot
  alloc_data.construct(constructData++ , 7);

  // this will be called twice to destroy the two elements we created
  while (constructData != dblData){
    alloc_data.destroy(--constructData);
  }
  // once memory is destroyed, two options:
  // 1) reuse and reassign data
  // 2) return memory back to system with: alloc_data.deallocate(pointer , n_items);
  alloc_data.deallocate(dblData , 1);

  // Exercise 12.26 - rewrite the program from the previous section using an allocator
  // this is exercises 12.23-26 together..

  const char* rawCharP("rawBurnt");
  const char* rawCharP2("rawChar");

  const int totalSize = (sizeof(rawCharP) + sizeof(rawCharP2));
  unique_ptr<char[]>dynamicRaw(new char[totalSize]);

  // copy the first elements into the array
  for(int i = 0; i < sizeof(rawCharP); ++i){
    dynamicRaw[i] = rawCharP[i];
  }

  // copy the second elements into the array.
  // make sure to start the second word at 0!
  for(int i = sizeof(rawCharP); i < totalSize; ++i){
    int j = i - sizeof(rawCharP);
    dynamicRaw[i] = rawCharP2[j];
  }

  std::string str1("rawBurnt");
  std::string str2("rawChar");
  std::string strT = str1 + str2;
  std::cout << strT << ", combined string\n";

  // // 12.24 do this but some standard input
  // char* userInput(new char[10]);
  // while( userInput[0] != 'e'){
  //   char test[10] , smol[5];
  //   std::cin >> userInput;
  //   std::cout << "you've entered: " << userInput << std::endl;
  //   std::cout << "please enter test, followed by smol:\n";
  //   std::cin >> test >> smol;
  //   std::cout << "you've entered: " << test << "\t" << smol << std::endl;
  //   std::cout << "ni hao" << endl;
  // }

  // // 12.3 using a text query program
  // while(true){
  //   string s;
  //   std::cout << "please enter a word: " << endl;
  //   if(!(cin >> s) or s == "q") break;
  //   std::cout << "you entered a word.." << endl;
  // }

  // using a text query program -> data looking program
  // want two classes -> place to read and store data file
  // second one       -> place to get results from the first class 

  // better implementation in the main code.
  ifstream readFile("blah.txt");
  runQueries(readFile);

  return 0;
}
