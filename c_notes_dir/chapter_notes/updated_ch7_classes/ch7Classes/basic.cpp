#include <initializer_list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "basic.hh"
#include "Sales_item.h"
#include "Sales_Data.cpp"
#include "screens.cc"

using namespace std;

int main(){

  Screens myScreen(5,5, 'x');
  myScreen.move(4,0).set('H').display(cout);
  cout << endl << endl;
  myScreen.display(cout);
  cout << endl;
  
  return 0;
}
