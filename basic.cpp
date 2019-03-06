#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // 4 is the place where istringstream is located..



using namespace std; 


int main(int argc, char **argv)
{

  ifstream read_file;
  read_file.open("pixel_cable.txt");

  ifstream read_file2;
  read_file2.open("
  
  int num;
  while(read_file >> num){
    cout << num << endl;
  }
  
  //pixel centric approach
  map<int, int> map_pixel_2cable;

  // shared_ptr<string> p1;
  // shared_ptr<list<int>> p2;

  // if(p1 and p1->empty()){
  //   *p1 = "hi"; 
  // }

  // printf("ni hao\n");


  return 0;
}
