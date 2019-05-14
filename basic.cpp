#include "basic.hh"
#include "StrBlob.hh"


// Chapter 12 notes.. Dynamic Memory
int main(int argc, char **argv)
{


  // Dynamic memory is managed through two operators: new and delete
  // new frees new object memory to associate with a pointer,
  // delete, obviously destroys the said pointer and frees memory..

  // three kinds of smart pointers: (all located in memory header)
  // shared_ptr -> multiple pointers to refer to the same object
  // unique_ptr -> "owns" object to which it points
  // weak_ptr   -> weak reference to an object managed by a shared_ptr

  // // 12.1.1 - shared_ptr
  // // these bad bois are templates, like vector< >

  // shared_ptr<string> p1; // this guy can point to a string
  // shared_ptr<list<int>> p2; // can point to a list of ints

  // //lets check to see if p1 is empty
  // if (p1 && p1->empty()) *p1 = "hi"; // will not currently at to p1..

  // shared_ptr<int> p3 = make_shared<int>(42);
  // cout << *p3;

  // exercise 1/2 -create SrBlob class and test size of addition..
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }

  //  cout << "size of shared_ptr is: " << b1.size();

  // exercise 3 - do the push_back and pop_back functions need const?
  // exercise 4 - dat	a could be null pointer, but if it is pointer to 0, value is destroyed.
  // exercise 5 - constructor for initializer_list is not explicit, what are the pros / cons?
  // -> Pros : can be used for implicit conversion types
  // -> Cons : these pointers are fuckin confusing.. 

  // smart pointers are explicit..
  // smart pointers with new:
  // error : shared_ptr<int> shared_int = new int(1024);
  // shared_ptr<int> shared_int(new int(1024));
  // cout << "\nthe value of shared int is: " << *shared_int << endl;

  // write a function which returns a dynamically allocated vector of ints..
  // pass that vector to another function that reads std::in to give values to
  // the elements 
  // remember to delete the vector at the appropriate time..
  // vector<int> vec1 = {1, 2, 3};
  // auto shared_vec1 = make_shared_vector(vec1);
  // print_shared_vector(cout, shared_vec1);

  // use no throw when you don't want to fail if there is in fact no new memory..
  // int a(7);
  // int *p3 = new (nothrow) int(a);
  
  // if you delete the pointer, it must be a dynamic pointer..
  // it is also okay to delete nullptrs..

  // cout << *p3 << ", value of *p3\n";
  // cout << a << ", value of a\n";
  // delete p3;
  // cout << a << ", value of a\n";
  // cout << *p3 << ", value of *p3\n";

  // exercise 12.8 if you use a function to create dynamic memory objects, delete them
  // inside of the same scope. they are not freed by leaving the scope of the function..

  // // Exercise: 12.9
  // // explains what happens in the following code"
  // int *q = new int(42) , *r = new int(100);
  // r = q; // the memory is not freed from the original r value!
  // // note that deleteing -either- p or r frees the memory..
  
  // auto q2 = make_shared<int>(42) , r2 = make_shared<int>(100);
  // cout << r2.use_count() << endl; // 1 ptr
  // r2 = q2;
  // cout << r2.use_count() << endl; // 2 ptr..

  // Exercise 12.10
  // explain if the following calls are legal:
  // the below function creates a new shared_ptr, passes it to process
  // the count inside of process is 2, and returns to 1 after scope.
  // shared_ptr<int> p(new int(2048));
  // process_1(shared_ptr<int>(p));
  // cout << *p << " value again? " << p.use_count() << endl;

  // // Exercise 12.11
  // // what happens if instead?
  // shared_ptr<int> w(new int(4098));
  // process_1(shared_ptr<int>(w.get())); // bad malloc error!
  // // this occurs since we initialized a shared_ptr from get..
  // // get returns a built-in pointer and is destroyed in function call..
  // // Exercise 12.12
  // // use the following p & sp declarations. find what is legal / not
  // auto pa = new int();
  // auto sp = make_shared<int>();
  // process_1(sp); // good to go
  // process_1(make_shared<int>()); // good to go
  // // process_1(new int()); // no dice, like pa..
  // // process_1(pa); // no good, pa not a shared_ptr..

  // // Exercise 12.13
  // // what happens with the following code:
  // auto sp = make_shared<int>();
  // auto p4  = sp.get();
  // delete p4; // like 12.11 this deletes the make_shared pointer, sp..
  
  // Exercise 12.14
  // write your own version of a function which manages a
  // connection with a shared_ptr

  // Exercise 12.15
  // rewrite the above exercise to use a lamba
  // callable instead of a function..
  Data d1;
  d1.value = 1;
  manage_analysis(d1);
  manage_analysis2(d1);    

return 0;
}
