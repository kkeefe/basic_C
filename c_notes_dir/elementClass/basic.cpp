#include <initializer_list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "basic.hh"

using namespace std;

int main(){

  cout << "Hello Classes! " << endl;
  cout << "change" << endl;
  Element X, Y;
  cout << "please input the atomic number and name" << endl;
  read(cin, X);
  cout << "\n input element: ";
  print(cout, X);
  cout << endl;
  cout << "default constructor: ";
  print(cout, Y);

  Element X1(1.2, "double, string");
  print(cout, X1);

  Element X2(2.2, 'c');
  print(cout, X2);

  Element X3('c', "char, string");
  print(cout, X3);


  



  return 0;
}
