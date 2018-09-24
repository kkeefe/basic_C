#include <iostream> //basic stuffs
#include <cstdlib>  //srand, rand
#include <time.h>   //*time*
#include <fstream> // allows reading of files and inputing numbers from other files


int mult (int a, int b){
  return a*b;
}


int main(){

  const int a = 3;
  const int b = 4;
  const int l = a+b;
  decltype(a+b) c = a+b;
  auto e = b;
  const int *const p = &a;
  c++;
  e++;

  std:: cout << l << " this is the value of l \n";
  std::cout << c << " this is the value of c \n";
  std::cout << e << " this is the value of e \n";
  std::cout << b << " this is the value of b \n";
  std::cout << a << " this is the value of a \n";
  
  return 0;

}
