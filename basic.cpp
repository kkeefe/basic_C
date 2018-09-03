#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <map>
#include <set>
#include <utility> //includes pair


void print(const map<string,int> b){
  for(const auto c : b){
    cout << c.first << " appears " << c.second << " times .. " << endl;
  }
}

int main() {
  
  // //exercise 11.3.2

  //exercise 11.22
  //write the return types which returns and argument type for an intert to the below map:
  map<string, vector<int>> map_string_to_vec_int;
  string word;
  vector<int> vec_int;
  for(int i = 0; i!= vec_int.size(); i++){
    pair<map<string,vector<int>>::iterator,bool> ret_map = map_string_to_vec_int.insert(make_pair(word,vec_int[i]));
  }

  //exercise 11.20
  // //rewire the word-counting program to use inserter instead of subscripting
  // map<string, int> word_count2;
  // vector<string> string_vec;
  // string word;
  // //add all of the words to the string vector  
  // while(cin >> word and word != "exit"){
  //   string_vec.push_back(word);
  // }
  // //this forces an insert from everything in the string vector and makes a
  // //pair of c and 2 but does not increment the value for the key..
  // for(auto c : string_vec){
  //   //ret is used to increment the values of insert.. which has a very complicated type
  //   //ret = pair<map<string,int>::iterator,bool> type.. where bool is true if the insert function placed a new element..
  //   auto ret = word_count2.insert({c,1});
  //   if(!ret.second){
  //     ++((ret.first)->second);
  //   }
  // }
 
  // print(word_count2);
  //exercise 11.21
  // //observe prostatus below..
  // map<string,int> word_count_test;
  // string word;
  // while(cin >> word and word != "exit"){
  //   ++word_count_test.insert({word,0}).first->second;
  // }
  // print(word_count_test);

  
  
  // //exercise 11.3.1 ~~
  // //list initialize a map between a string and an integer
  // map<string, int> word_count = {
  //   {"this", 1},
  //   {"is", 1},
  //   {"my", 2},
  //   {"design",3},
  //   {"bro", 1}
  // };
  // //map iterator which increments the value of the second iterator each time it is called.
  // //also produces output in alphabetal order.. 11.15
  // map<string,int>::iterator map_itr = word_count.begin(); //exercise 11.18 has you write the type of this iterator out..
  // while(map_itr != word_count.end()){
  //   cout << map_itr->first << ": first element appears " << ++map_itr->second << " times..\n";
  //   map_itr++;
  // }

  // //reset the itr to the beginning again..
  // map_itr = word_count.begin();
  // //exercise 11.16 -> assign values to map elements
  // while(map_itr != word_count.end()){
  //   if(map_itr->first.size()%2){
  //     map_itr->second = 1;
  //   }else{
  //     map_itr->second = 2;
  //   }
  //   map_itr++;
  // }

  // //print the values of the word_count map;
  // print(word_count);

    
  
  return 0;
}
