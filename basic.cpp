#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <map>
#include <set>
#include <utility> //includes pair

//find the number of times a set of strings appears in a given input stream

int main() {

  //exercise 11.2.3
  pair<string,int> process_string_words1(string a, int b){
    return make_pair(a,b);
  }
  pair<string,int> process_string_words2(string a, int b){
    pair<string, int> pair(a,b);
    return pair;
  }
  string words = "what";
  int numbers = 5;
  pair<string, int> pair_string_int;
  pair<string, int> pair_string_int2;
  vector<pair<string,int>> vec_pair_string_int;
  pair_string_int = process_string_words1(words,numbers);
  pair_string_int2 = process_string_words2(words,numbers);
  vec_pair_string_int.push_back(pair_string_int);

  // //exercise 11.2.2 - define a map that associates words with a list of line numbers on which the word might occur
  // //map notes : key and value in map declaration are only their types
  // //can't declare a map for list, but can declare a map for vector. - this means that vec iterators are always 1-1 and onto, but not lists..
  // string word;
  // list<int> line_number = {1,2,3,4,5};
  // list<int>::iterator line_itr;// = line_number.begin();
  // vector<int> vec_number = {1,2,3,4,5};
  // vector<int>::iterator vec_itr = vec_number.begin();
  // map<string,list<int>> word_map;

  // map<vector<int>::iterator, int> vec_map;
  // map<list<int>::iterator, int> list_map;

  // ++vec_map[vec_itr];
  // // list_map[line_itr];
  // ++vec_map[vec_itr];

  // for(const auto & w : vec_map){
  //   cout << w.second << endl;
  // }
  
  // //exercise 11.2 - define a map for family and children names -11.2.3 adds vector<string> to include vector<pair<string,string>>
  // //note that there is an run-time error if cin reads more that one word at a given time
  // //map<key, value>
  // map<string,vector<pair<string,string>>> Family_Names;
  // string l_name;
  // string c_name;
  // string c_bday;
  // //record the last names and children names of a family
  // cout << "type exit to leave.." << endl;  
  // cout << "enter the family name you wish to record: ";
  // while(cin >> l_name and l_name != "exit"){
  //   Family_Names[l_name]; //adds the name to the family name map
  //   cout << "\nenter the names of the chldren for family " << l_name << ": ";
  //   while(cin >> c_name and c_name != "exit"){
  //     cout << "Please enter " << c_name << "'s birthday: ";
  //     cin >> c_bday; 
  //     pair<string,string> child_birthday(c_name,c_bday);
  //     Family_Names[l_name].push_back(child_birthday);
  //     cout << "\nenter the names of the chldren for family " << l_name << ": ";      
  //   }
  //   cout << "enter the family name you wish to record: ";
  // }
  // //print all of the family names and their children
  // for(auto & c : Family_Names){ //print all of the last names
  //   cout << "Family Name: " << c.first << "\n ";
  //   cout << "Children Names: " << "\n";
  //   for(auto & d : c.second){ //print all of the children names for that last name - note that c is type string, vec and we need to go over c.second range
  //     cout << d.first << ",\t" << d.second << endl;
  //   }
  //   cout << endl;
  // }

  
  // //exercise 11.1 
  // //write your own version of the word counting program
  // ostream_iterator<string> out(cout, "\n");
  // istream_iterator<string> in(cin), eof;
  
  // map<string, size_t> word_count;
  // set<string> include = {"a","an","the"};
  
  // while(*in != "exit" and in != eof){
  //   string input = *in;
  //   string invariant_string;
  //   for(auto & c : input){
  //     if(!ispunct(c)){ //ignore all punctuation in a stirng
  // 	c = tolower(c); //convert all case to the same 
  // 	invariant_string+=c; //add the lowercase _ nonpunct to the string we wish to find in our set
  //     }
  //   }
  //   if(include.find(invariant_string) != include.end()){
  //     out = invariant_string;
  //     ++word_count[invariant_string];
  //   }
  //   in++;
  // }

  // for(const auto & map_value : word_count){
  //   out = map_value.first;
  //   out = " appeared this number of time(s): ";
  //   cout <<  map_value.second; //note that size_t does not like out operator
  // }

  return 0;
}
