#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // 4 is the place where istringstream is located..

using namespace std; 
<<<<<<< HEAD


int main(int argc, char **argv)
{

  
  printf("this is my design.. \n");

  return 0;
=======
// word transformation map

int main(int argc, char** argv){

  // will this now give me error lines

  string word;
  while(word != "exit"){
    cout << " please enter a any string of characters you want to be processed: ";
    getline(cin, word);
    istringstream stream(word);
    cout << word << " -- this is what you entered .." << endl;;
    
    while(stream >> word){
      cout << " new word .. " << endl;
      cout << word << " this is what word is now currently pointing too " << endl;
    }
}
return 0;
>>>>>>> b964b0a726d7142c29f62afb9fefafdcd12c36cd
}
