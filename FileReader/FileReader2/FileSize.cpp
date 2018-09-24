#include <fstream>
#include <iostream>

int main(){

  std:: streampos end, begin;
  std:: string input;

  std:: cout << "enter the name of the file who's size you would like to determine: ";
  std:: cin >> input;

  //attempt to open a file based off of some input
  std:: ifstream file (input, std::ios::binary);

  //read the beginning of the file
  begin = file.tellg();

  //put the get position at the end of the file
  file.seekg(0, std::ios::end);

  //read the file at the new location
  end = file.tellg();

  //relay the information of the size of the file bytes.
  std:: cout << "the size of the file type you entered: " << input << " is " << (end - begin) << " byes \n";
  
   
  return 0; 
}
