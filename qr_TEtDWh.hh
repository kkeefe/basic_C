#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
//function defintions
// #include "Sales_item.h"--moved to another directory?

#include <algorithm>
#include <functional>
#include <map>
#include <unordered_map>
#include <set>
#include <utility> //includes pair
#include <memory>

//note that sales class data constructor is in basicCh11_3_MultiMap.txt

using namespace std;

/*
   Word transformation functions!!
 */
const string &transform(const string &s, const map<string, string> &m);

map<string, string> buildMap(ifstream &reference_file);

void word_transformation(ifstream &input_file, ifstream &reference_file);

/*
   END transformation functions!!
 */

//best practice is to declare and define all inline and constexpr functions inside header files only: they must all match exactly and definition must be known at compile time.
inline bool is_shorter (const string& a, const string& b){
  return  (a > b) ? true : false;
}

/*
  PRINT FUNCTIONS!!
*/

void print_map_string_stringvec(map<string, vector< string > > a){
  for(auto c : a){
    cout << "Family Name: " << c.first << ", has the following children:\n";
    int a(1);
    for(auto d : c.second){
      cout << a << ". " << d << endl;
      a++;
    }
  }
}

void print_map_string_vecPair_string_string(map<string, vector<pair<string,string>>> a){

  for(auto c : a){ //c has type pair string vec_pair
    cout << "Family Name: " << c.first << ", has the following children:\n";
    int a(1);
    for(auto d : c.second){ //d has type pair<string,string>
      cout << a << ". " << d.first << "\t";
      cout << d.first << "'s birthday is: " << d.second << endl;
      a++;
    }
  }
}

void print_map_iterator(map<string, vector<int>>::iterator map){
  cout << map->first << " is the first element.. " << endl;
  cout << map->second[1] << " is the second element of the vector space.. " << endl;
}

void print_multiMap_stringString(multimap<string, string> map){
  multimap<string, string>::iterator start = map.begin();
  while(start != map.end()){
    cout << start->first << " is the author name .. ";
    cout << start->second << " is the work .. " << endl;
    start++;
  }
}

// function for ch12 ex 6
shared_ptr<vector<int>> make_shared_vector(vector<int> vec_int){
  shared_ptr<vector<int>> shared_vec_int(new vector<int> (vec_int));
  return shared_vec_int;
}

// now make a function to print the values which we read..

ostream& print_shared_vector(ostream& os, shared_ptr<vector<int>> shared_vec_int){
  
  for(auto c : *shared_vec_int){
    os  << c << "\n";
  }
  return os;
}

// additional smart pointer practice:

void process_1(shared_ptr<int> ptr){
  cout << *ptr << " is the value pt shared_ptr " << ptr.use_count() << "\n";
}

// part of exercises 12.14 / 12.15
struct Data
{
  Data() = default;
  int value;
  int value2;
};

struct Analysis
{
  Analysis() = default;
  int value;
};

Analysis analyze(Data *d){
  Analysis a;
  a.value = 2*d->value;
  return a;
}

void stopAnalyze(Analysis){
  printf("analysis complete.\n");
}

void endAnalysis(Analysis* a){
  stopAnalyze(*a);
}

void manage_analysis(Data &c){
  cout << "running analysis.." << endl;
  Analysis d = analyze(&c);
  shared_ptr<Analysis>p(&d , endAnalysis);
}

// ex 12.15 wants to use endAnalysis as a lambda fnc instead..
void manage_analysis2(Data &c){
  cout << "running analysis2..\n";
  Analysis d = analyze(&c);
  shared_ptr<Analysis>p(&d, [](Analysis *a){stopAnalyze(*a);});
}
