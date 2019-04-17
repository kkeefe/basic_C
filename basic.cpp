#include "basic.hh"
#include "StrBlob.hh"

// Chapter 12 notes.. Dynamic Memory
int main(int argc, char **argv)
{


  printf("ni hao\n");
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

  cout << "size of shared_ptr is: " << b1.size();

  // exercise 3 - do the push_back and pop_back functions need const?
  // exercise 4 - data could be null pointer, but if it is pointer to 0, value is destroyed.
  // exercise 5 - constructor for initializer_list is not explicit, what are the pros / cons?
  // -> Pros : can be used for implicit conversion types
  // -> Cons : 



  return 0;
}