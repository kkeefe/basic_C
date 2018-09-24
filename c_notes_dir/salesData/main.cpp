#include <initializer_list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "salesData.cc"



using namespace std;

int main(){


  //use the delegated constructor
  Sales_Data data1 = Sales_Data(cin);
  
  print(cout, data1);
  
  // //create Sales_Data types
  // Sales_Data data1, data2, data5;

  // string name;
  // cout << "please enter a name" << endl;
  // cin >> name;

  // int count;
  // cout << "please enter a sales count" << endl;
  // cin >> count;

  // double salePrice;
  // cout << "please enter a sales price" << endl;
  // cin >> salePrice;

  // data1 = Sales_Data(name, count);
  // print(cout, data1);
  
  // data2 = Sales_Data(name);
  // print(cout, data2);

  // data5 = Sales_Data(name, count, salePrice);
  // print(cout, data5);


  // Sales_Data data3;
  // char a;
  // while(cin >> a and a != 'n'){
  //   if(a == 'y'){
  //   read(cin, data3);
  //   print(cout, data3);

  //   // Sales_Data::add_total(data3);
  //   // Sales_Data::print_total();
  //   }else{
  //     cout << "please enter a valid input, type 'n' to exit " << endl;
  //   }
  // }
  

  // //ask for the first isbn to check against  
  // cout << "please enter the first isbn you would like to check: " << endl;
  // cin >> data1.sales_isbn;

  // cout << "you are checking against: " << data1.isbn() << endl;
  
  // //compare against a second isbn to record the sales for this isbn
  // cout << "please enter the isbn of the sale: ";
  // while(cin >> data2.sales_isbn and data2.sales_isbn != "exit"){

  //   //if the data types match; add the values together.
  //   if(data2.sales_isbn == data1.sales_isbn){
  //     cout << "please enter the price of the book: ";
  //     cin >> data2.sales_price;
  //     cout << "\nplease enter the count of the books you sold: ";
  //     cin >> data2.sales_count;
  //     data2.sales_price *= data2.sales_count;
  //     data1.sales_price += data2.sales_price;
  //     cout << "the current total sales of this isbn: " << data2.sales_isbn << " is " << data1.sales_price << "\n";
  //   }
  //   //if the data types do not match, ask if you would like to change to a different type of file
  //   else{
  //     cout << data2.sales_isbn << " does not match " << data1.sales_isbn
  // 	   << " would you like to add to this new selection? (y/n) \n";
  //     char y;
  //     cin >> y;
  //     if(y == 'y'){
  // 	data1.sales_isbn = data2.sales_isbn;
  // 	cout << "you are now checking against: " << data1.sales_isbn << endl;
  //     }else if(y == 'n'){
  // 	cout << "you will continue to check against: " << data1.sales_isbn << endl;
  //     }
  //   }
  //   //continue to ask for the isbn of the item sold
  //   cout << "please enter the sales isbn of the item you sold: \t (type exit to leave the program) \n";
    
  // }
							       
  

  
  return 0;
}
