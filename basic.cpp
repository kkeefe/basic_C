#include "basic.hh"//includes algorithm, function, vector headers, etc..

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

int main(){


  //exercise section 11.2.1

  //exercise 11.5
  //explaine the differeneces between map and set, when would you use each?
  /* 
     map - has a pair type return, with a key_type and value_type.
     set - has only a key value type
   */

  //exercise 11.6
  //explain the difference between a set and list, when would you use each?
  /*
    sets contain no elements that are equal to each other
    list is an ordered collection of elements -users can access elemenets by indexing
    set - elements are always unordered
   */
  
  // //exercise 11.7
  // //define a map for which the key is the family's last name and the value is a vector of strings.
  // //write code to add new families and to add new chidlren to an existing family
  // string last_name, first_name;
  // map<string, vector<string>> Family_Names;
  // cout << "Please enter the family name you wish to check for:\t";
  // while(cin >> last_name and last_name != "exit"){
  //   //use this to create a last name key..
  //   cout << "please enter a child's first name..\t";
  //   while(cin >> first_name and first_name != "exit"){
  //     Family_Names[last_name].push_back(first_name);
  //     cout << "please enter a child's first name.. (type exit to leave..)\n";
  //   }
  //   cout << "Please enter the family name you wish to check for (type exit to leave):\t";
  // }
  // print_map_string_stringvec(Family_Names);
  
  
  //exercise 11.8
  //write a program that stores the excluded words in a vector instead of in a set,
  //what are the advantages to useing a set??
  string words;
  vector<string> excluded_words;
  set<string> last_name_set= {
    {"Keefe"},
    {"Proctor"}
  };
  cout << "please input some excluded words.." << endl;
  while(cin >> words and words != "exit"){
    last_name_set.insert(words);
    excluded_words.push_back(words);
    cout << "please input some excluded words..(type exit to leave)" << endl;
  }
  
  //exercise 11.9
  //define a map that associates words with a list of line numbers on which the word might occur

  //exercise 11.10
  //could we define a map from vector<int>::ioterator in int?
  //what about list<int>::iterator to int> in each case, if not, why not?

  //exercise 11.11
  //redefine bookstore without using decltype

  //exercise 11.12
  //write a program to read a sequence of strings and ints, storing each into a pair. store the pairs in a vector.

  //exercise 11.13
  //there are at lest 3 ways to create a pair. create a pair in 3 different ways. which is the best?

  //exercise 11.14
  //extend the map of children to their fmaily name that you wrote by having the vector store a pair that hold's a child's name and birthday..

  //exercise 11.15
  //what are the mapped_type, key_type, and value_type of a map from int to vector<int>?

  //exercise 11.16
  //using a map iterator write an expression that assigns a value to an element.

  //exercise 11.17
  //explain which of the following calls are legal on page 431..

  //exercise 11.18
  //write the type of map_it from the loop on page 430 without using decltype..

  //exercise 11.19
  //define a variable that you initialie by calling begin() no the multiset name bookstore from page 425.
  //write the variable's type without using auto of decltype.

  //exercise 11.20
  //write the word counting program on page 421 to use insert instead of subscripting.
  //which is the easier / better program to write and why?

  //exercise 11.21
  //assuming word_count is a mpa from string to size_t, and word is a string explain the following loop:
  /*
    while (cin >> word)
    ++word_count.insert({word,0}.first->second;
   */
  
  //exercise 11.22
  //given a map<string, vector<int>> write the types used as an argument and as a return value for the version of insert that inserts one element.

  //exercise 11.23
  //rewrite the map that stored vectors of children's names with a key that is the family last name for the exercises on page 424, to use a multimap

  

  
  return 0;
}
