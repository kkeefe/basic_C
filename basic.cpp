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

