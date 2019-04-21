#include <iostream> //basic stuffs

using std::string;
using std::cout;
using std::cin;

int max (int a, int b){
  if(a>=b){
    return a;
  }
  else return b;
}

int min (int a, int b){
  if(a>=b){
    return b;
  }
  else return a;
}

int main(){

  string s1 = "Hello, please input two numbers you would like to see the range between. ";
  int a, b;

  cout << s1;
  cin >> a;
  cin >> b; 

  int c =  max(a,b);
  int d = min(a,b);

  while( d <= c){
    cout << d << " the input is: " << std::endl;
    d++;    
  }
  
  
  return 0;

}
