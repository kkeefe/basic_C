#include <iostream>
#include <fstream>

using std::cout;

int main(){

  std::ifstream infile;

  infile.open("outfile.txt");

  int a;
  while(infile >> a){
    if(a == 1){
      cout << "acrylic" << "\t";
    }else{
      cout << "air" << "\t";
    }
  }

  
  infile.close();
  
  return 0;
}
