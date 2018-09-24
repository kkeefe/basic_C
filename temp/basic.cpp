#include <initializer_list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "basic.hh"

using namespace std;

int main(){

  cout << "Hello Classes! " << endl;

  Element X, Y;
  read(cin, X);
  cout << "\n input element: ";
  print(cout, X);
  cout << endl;
  cout << "default constructor: ";
  print(cout, Y);


  return 0;
}
