#include <iostream> //basic stuffs
#include <cstdlib>  //srand, rand
#include <time.h>   //*time*
#include <fstream> // allows reading of files and inputing numbers from other files

int main(){

  std::string fileName;
  std::ofstream outfile; 
  std::ifstream infile;
  double value;
  double sum = 0;
  int count = 0;
  double avg;

  std:: cout << "please input the name of the file you want to open including .txt extension: \n";
  std:: cin >> fileName;
  
  infile.open(fileName);

  //this is here to read all of the lines of the file.
  while( infile >> value )
    {
      infile >> value;
      count++;
      sum += value;      
    }

  avg = (sum / count);
  
  infile.close();
  
  std:: cout << "the file has completed its reading \n";
  std:: cout << count << " is the value of the count \n";
  std:: cout << sum << " is the value of the SUM \n";
  std:: cout << avg << " this is the value of the average \n";

  // std:: string string1; 
  // std:: cout << "please input the name of the file that you would like to open: ";
  // std:: cin >> string1;

  
  // //open the file to be read
  // outfile.open(string1, std::ios::app);

  // int input1 = 0;

  // do{
  //   std:: cout << "Please input the text you would like to add to practice.txt: \n";
  //   std:: cin >> input1;
  //   if(input1 != 0){
  //     outfile << input1 << std:: endl;
  //   }
  //   else
  //     std:: cout << "thank you for your entry! \n";
  // 	}while(input1 != 0);
 
  // outfile.close();
  
  return 0;
}
