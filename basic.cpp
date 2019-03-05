#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // 4 is the place where istringstream is located..

using namespace std; 


int main(int argc, char **argv)
{
  shared_ptr<string> p1;
  shared_ptr<list<int>> p2;

  if(p1 and p1->empty()){
    *p1 = "hi"; 
  }

  printf("ni hao\n");


  return 0;
}