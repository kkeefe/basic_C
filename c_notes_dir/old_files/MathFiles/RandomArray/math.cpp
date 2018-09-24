#include <iostream> //basic stuffs
#include <cstdlib>  //srand, rand
#include <time.h>   //*time*
#include <fstream> // allows reading of files and inputing numbers from other files

using namespace std;

int main(){

  int first = 0;
  int second = 0;
  string input;
  int try1 = 1;

  std:: cout <<  "please type the math operation you desire: ";

  while(try1 < 4){

    std:: cin >> input;
    
    if(input == "addition"){
      do{
	std:: cout <<  "please input the first nunmber: ";
	std:: cin >> first;
	std:: cout <<  "please input the second nunmber: ";
	std:: cin >> second;
  
	for (int i = 0; i <= second; ++i) {
	  std:: cout << i << " plus " << first << " is " << first + i << "\n";
	  std:: cout << random << " is a random number! \n";
	  std:: cout << RAND_MAX  << " is the maximum random number! \n";
	}
      } while (first or second != 0);
      try1 = 4;      
    }
    else if(input == "subtraction"){
      do{
	std:: cout <<  "please input the first nunmber: ";
	std:: cin >> first;
	std:: cout <<  "please input the second nunmber: ";
	std:: cin >> second;
	for (int i = second; i >= 0; --i) {
	  std:: cout << i << " minus " << first << " is " << i - first << "\n";
	}
      } while (first or second != 0);
      try1 = 4;      
    }
    else if(input == "multiplication"){
      do{
    	std:: cout <<  "please input the first nunmber: ";
    	std:: cin >> first;
    	std:: cout <<  "please input the second nunmber: ";
    	std:: cin >> second;
    	for (int i = 0; i <  second; ++i) {
    	  std:: cout << i << " multiplied with " << first << " is " << i * first << "\n";
    	}
      } while (first or second != 0);
      try1 = 4;
    }
    else if(input == "division"){
      do{
    	double division1;
    	std:: cout <<  "please input the first nunmber: ";
    	std:: cin >> first;
    	std:: cout <<  "please input the second nunmber: ";
    	std:: cin >> second;
    	for (int i = 1; i < second; ++i) {
    	  division1 = (first / i);
    	  std:: cout << first << " divided by " << i << " is " << division1 << "\n";
    	}
      } while (first or second != 0);
      try1 = 4;
    }
    else    
    std:: cout << "that is not a correction choice..\n";
    std:: cout << "Please input one of the following: addition, subtraction, multiplication, or division ";    
    try1++;
    
  }
return 0;
 
}
