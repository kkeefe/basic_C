#include "basic.hh"//includes algorithm, function, vector headers, etc..

using namespace std; 

int main(int argc, char** argv){

  //exercises in 11_3
  // exercise 11.24
  // what does the following program do? 
  map<int, int> m;
  m[0] = 1;
  cout << m[0] << " this is the value pointed to by m.. " << endl;
  
  // // exercise 11.25
  // // contract the following program with the previous one: //this below program just likes to seg fault
  // vector<int> v;
  // v[0] = 1;

  // // // new operations:
  // // c : is a map or unordered map
  // // k : is the key..
  //    c.find(k)  // returns an iterator to the first element with key k. off the end if not in container.
  //    c.count(k) // returns int number of elements with key equal to k

  //    // bounds:
  //    c.lower_bound(k) // returns and itr to the first element with key less than k
  //    c.upper_bound(k) // returns an itr to first element with key greater than k
  //    c.equal_range(k) // returns pair of itrs with elements of key k

  
  // // exercise 11.26
  // // what type can subscript a map? what is its return type? give an example, make the code, run and check..
  // // you can map any two types together that you wish.. keep in mind that a map function is purely a 1:1 isomorphic mathetmatical mapping you define between any two arbitrary types..
  // map<string, int> map_string_int;
  // map<char, int> map_char_int;
  // map<char*, int> map_charS_int;
  // char* k;
  
  // map_string_int["hi"] = 2;
  // map_char_int['k'] = 3;
  // map_charS_int[k] = 4;

  // cout << map_string_int["hi"] <<  " value pointed to by the string map.. " << endl;
  // cout << map_char_int['k'] <<  " value pointed to by the char map.. " << endl;
  // cout << map_charS_int[k] <<  " value pointed to by the char* map.. " << endl;

  // exercise 11.27
  // what kinds of problems would you use count to solve? (pg 438)
  // the count function is a call on a map type. you pass map_type.count(key_type), the return type is an int referring to the number of times that the key appears in the map..
  // map_type.count(key_type)
  // find function would be more useful when you want to have an iterator to the first element in a map with the associated key passed to the find function..

  // exercise 11.28
  // define and initialize a variable to hold the result of calling find on a map from string to vector<int>

  map<string, vector<int>> map_string_vecInt; // map to call the find function on..
  for(int i = 0; i < 5; ++i){
    map_string_vecInt["first"].push_back(i);
    map_string_vecInt["second"].push_back(i*2);
  }
  map<string, vector<int>>::iterator map_string_vecInt_point = map_string_vecInt.find("second"); // map to call the find function on..  
  // cout << map_string_vecInt_point->first << endl;
  // cout << map_string_vecInt_point->second[3] << endl;  

  // keep in mind that the value type that is referenced to by a map is the pair type.. a map is a set of pairs..
  
  // // exercise 11.29
  // // what do upper_bound, lower_bound, and equal_range return when you pass a key that is not in their container?
  // // if you pass a key to upper / lower bound functions that are not in the map, then you will get null pointers, which is bad news bears.. keep in mind that equal_Range also returns a pair of iterators..
  // map<string, vector<int>>::iterator map_string_vecInt_point1 = map_string_vecInt.lower_bound("first");
  // map<string, vector<int>>::iterator map_string_vecInt_point2 = map_string_vecInt.upper_bound("first");
  // // keep in mind that equal_range returns a pair of iterators..
  // auto map_string_vecInt_point3 = map_string_vecInt.equal_range("third");  
  // printf("pointer 1 \n");
  // print_map_iterator(map_string_vecInt_point);
  // printf("pointer 2 \n");
  // print_map_iterator(map_string_vecInt_point1);
  // printf("pointer 3 \n");
  // print_map_iterator(map_string_vecInt_point2);
  // printf("");
  // // print_map_iterator(map_string_vecInt_point3);  

  // exercise 11.30
  // explain the meaning of the operand pos.first->second used in the output expresion of the final program in this section (pg. 440)
  // pos is a pair iterator type.. pos.first returns the element, pos.first-> fetches the value of that element which is also a pair.. pos.first->second gets the second value of the pointed to pair..
  
  // exercise 11.31
  // write a program that defines a multimap of authors and their works. use find to find an element in the multimap and erase that element. be sure
  // your program works correclty if the elemnt you look for is not in the map.

  // exercise 11.32
  // using multimap the previous exercise, write a program to print the list of authors and their works alphabetically..
  // note that the below code does both exercises 11.31 and 11.32
  
  multimap<string, string> author_work = { {"Apple", "work_1"},
  					   {"Jeff", "work_2"},
  					   {"Zeus", "work_3"},
					   {"Jeff", "work_2a"},
					   {"Jeff", "work_2b"} };				   
  string search;
  printf("please input the author name you wish to search for: ");
  cin >> search;
  multimap<string, string>::iterator search_fnc = author_work.find(search);
  auto search_range = author_work.equal_range(search);
  //print the multimap..
  print_multiMap_stringString(author_work);
  //sort the multimap..
  //sort_multiMap_stringString(author_work); sorting is no good but the multimap takes care of this as is..
  
  if(search_fnc != author_work.end()){
    printf("\n we found it! \n");
    //author_work.erase(search_fnc); //this will erase only the first element returned by the search fnc
    author_work.erase(search_range.first, search_range.second); // this erases the entire range of the key pointed to by the search..
    print_multiMap_stringString(author_work);
  }else
    printf("\n we didn't find nothing, the author list is unchanged.. \n");
  
  
  return 0;
}
