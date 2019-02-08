#include "basic.hh"//includes algorithm, function, vector headers, etc..

using namespace std; 

int main(){

  //exercises in 11_3

  cout << "this is my design.." << endl;
  system("pause");

  string word; 
  cout << "please enter some word .. " << endl;
  cin >> word;

  // //exercise 11.24
  // //what does the following program do?
  // map<int, int> m;
  // m[0] = 1;

  // // exercise 11.25
  // // contract the following program with the previous one:
  // vector<int> v;
  // v[0] = 1;

  //new operations:
  // c : is a map or unordered map
  // k : is the key..
  /* 
     c.find(k)  -- returns an iterator to the first element with key k. off the end if not in container.
     c.count(k) -- returns int number of elements with key equal to k

     bounds:
     c.lower_bound(k) -- returns and itr to the first element with key less than k
     c.upper_bound(k) -- returns an itr to first element with key greater than k
     c.equal_range(k) -- returns pair of itrs with elements of key k

   */
  
  // exercise 11.26
  // what type can subscript a map? what is its return type? give an example, make the code, run and check..

  // exercise 11.27
  // what kinds of problems would you use count to solve? (pg 4.38)

  // exercise 11.28
  // define and initialize a variable to hold the result of calling find on a map from string to vector<int>

  // exercise 11.29
  // what do upper_bound, lower_bound, and equal_range return when you pass a key that is not in their container?

  // exercise 11.30
  // explain the meaning of the operand pos.first->second used in the output expresion of the final program in this section (pg. 440)

  // exercise 11.31
  // write a program that defines a multimap of authors and their works. use find to find an element in the miultimap and erase that element. be sure
  // your program works correclty if the elemnt you lok for is not in the map.

  // exercise 11.32
  // using mutlimap fro the previous exercise, write a program to print the list of authors and their works alphabetically..
  
  
  
  printf("hi");
  
  return 0;
}
