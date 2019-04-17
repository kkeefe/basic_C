#include <iostream> //basic stuffs
#include <cstdlib>  //srand, rand
#include <time.h>   //*time*
#include <fstream> // allows reading of files and inputing numbers from other files

int main(){

  srand(time(NULL));
  int random = rand() % 10 + 1; //creates a random number between 1 and 10
  int first;
  std:: cout <<  "please input the first nunmber: ";
  std:: cin >> first;

  for (int i = 0; i < first; ++i) {
    std:: cout << i << " plus " << first << " is " << first + i << "\n";
    std:: cout << random << " is a random number! \n";
    // std:: cout << RAND_MAX  << " is the maximum random number! \n";
  }

  
   
  return -1;

}
