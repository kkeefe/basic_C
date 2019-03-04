#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // this is the place where istringstream is located..

using namespace std; 

// word transformation map

int main(int argc, char** argv){
  
 // why is c++ giving me so much shit?
 string word;

  while(word != "exit"){
    cout << " please enter a any string of characters you want to be processed: ";
    getline(cin, word);
    istringstream stream(word);
    cout << word << " -- this is what you entered .." << endl;

    while(stream >> word){
      cout << " new word .. " << endl;
      cout << word << " this is what word is now currently pointing too " << endl;
    }
  }

  int a(4);
  while(a < 5){
    cout << "a is still less than 5.. ";
    cin >> a;  
  }

  cout << "a is no longer less than 5.. " << endl;

return 0;
}
