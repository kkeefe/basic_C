//function defintions
// #include "Sales_item.h"--moved to another directory?
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <utility> //includes pair

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

void print_map_string_stringvec(map<string, vector<string>> a){
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
