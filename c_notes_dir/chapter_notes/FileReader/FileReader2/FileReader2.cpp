#include <iostream>
#include <fstream>
#include <string>s


int main (){

  std:: string string1;
  std:: cout << "Hello, please enter the name of the file you would like to open: ";
  std:: cin >> string1;

  int a;
  
  std:: cout << "please enter a number indicating which of the following operations you would like to do to your file: \n";
  std:: cout << "for ios:in, enter 1 \n";
  std:: cout << "for ios:out, enter 2 \n";
  std:: cout << "for ios:app, enter 4 \n";
  std:: cout << "for a combination, please enter their sum: \n";

  std:: cin >> a;


  //this sets the way that the file will be treated. 
  bool input1 = false;
  bool output1 = false;
  bool truncate1 = false;
  
  if(a == 1){
    input1 = true;
  }
  else if(a == 2){
    output1 = true;
  }
  else if(a == 4){
    truncate1 = true;
  }
  else if (a == 3){
    input1 = true;
    output1 = true;
  }
  else if(a == 5){
    input1 = true;
    truncate1 = true;
  }
  else if(a == 6){
    output1 = true;
    truncate1 = true;
  }
  else if(a == 7){
    input1 = true;
    output1 = true;
    truncate1 = true;
  }
  else{
    std:: cout << "That is not a proper input! " << std:: endl;
    std:: cout << "all values will be set to append " << std:: endl;
    input1 = true;
    output1 = true;
    truncate1 = true;
  }

  //define the input and output files
  //open the file to be read
  //add the set parameters
  //ios::in - open with input operations, and is default on ifstream, --this operation allows reading from a file. 
  //ios::out - open with output operations, and is default on ofstream, -- this will delete all information on the file when used
  //f stream files are opened with default ios::in and ios::out operations
  //ios::ate - sets the initial position at the end of the file.
  //ios::app - all information is added at the end of the file
  //ios::trunc - if a file is open for output operations, and the file existed, the previous info from the file is deleted.

  std::fstream outfile; 
  
  if(input1){
    if(output1){
      if(truncate1){
	outfile.open(string1, std::ios::app | std::ios::in | std::ios::out);
	std:: cout << "all true \n";
      }
      else{outfile.open(string1, std::ios::in | std::ios::out);
	std:: cout << "input and output true \n";}
    }
    else if(truncate1){
      outfile.open(string1, std::ios::in | std::ios::app);
      std:: cout << "intput and truncate are both true! \n";
    }
    else{outfile.open(string1, std::ios::in);
      std:: cout << "only input true \n";
    }
  }
  else if(output1){
    if(truncate1){outfile.open(string1, std::ios::app| std::ios::out);
      std:: cout << "output and append are true!\n";}
       else{outfile.open(string1, std::ios::out);
	 std:: cout << "only output is true! \n";}
  }
  else if(truncate1){
    outfile.open(string1, std::ios::app);
    std:: cout << "only append is true! \n";
  }


  int input2 = 0;
  
    do{
      std:: cout << "Please input the text you would like to add to practice.txt: \n";
      std:: cin >> input2;
      if(input2 != 0){
	outfile << input2 << std:: endl;
      }
      else
	std:: cout << "thank you for your entry! \n";
    }while(input2 != 0);
 
  outfile.close();

  char yesno;
  std:: cout << "would you like to read all of the contents of the file you just editted? (y/n): \n";
  std:: cin >> yesno; 
  int item;
  char v[7];
  if(yesno == 'y'){
    outfile.open(string1, std::ios::in);
    std:: cout << "you have selected to read a file. \n";
    while(!outfile.eof()){
      outfile >> item;
      std:: cout << item << ", ";
      outfile >> v;
      std:: cout << v << " , ";
    }
    outfile.close();
  }
  else{
    std:: cout << "thank you for using the editor. \n";
  }
  
  return 0;

}
