#include <iostream>
#include <fstream>
#include <numeric>//this is the for accumulate algorithm
#include <vector>
#include <algorithm> //includes swap and unique algorithms, notice they're not called directly onto the vector
#include <functional>
#include <list>

using namespace std;
using namespace std::placeholders;

//write a function to count the words of size 6 or less
int is_less_than_function(vector<int> int_vec, int compare){
  int a(0);
  for(auto c : int_vec){if(c < compare)a++;};
    
  return a;
  
}

bool compare_function(int int_vec_part, int compare){
  return int_vec_part < compare;
}

void print_vector(const vector<int> a){
  for(auto c : a){cout << c << "\t";}
  cout << endl;
  }


void print_list(const list<int> a){
  for(auto c : a){cout << c << "\t" << "....";}
  cout << endl;
  }
