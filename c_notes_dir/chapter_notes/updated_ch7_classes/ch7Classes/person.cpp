#include "person.cc"

using namespace std;

int main(){

  Person joe = Person(cin);
  print(joe, cout);

  Person deafault;
  print(deafault, cout);

  cout << deafault.name << "\t" << deafault.address;


  
  return 0;
}
