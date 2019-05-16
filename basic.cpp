#include "basic.hh"
#include "StrBlob.hh"


// Chapter 12 notes.. Dynamic Memory
int main(int argc, char **argv)
{

  // Exercise 12.12
  // use the following p & sp declarations. find what is legal / not
  // auto pa = new int();
  // auto sp = make_shared<int>();
  // process_1(sp); // good to go
  // process_1(make_shared<int>()); // good to go
  // process_1(new int()); // no dice, like pa..
  // process_1(pa); // no good, pa not a shared_ptr..

  // Exercise 12.13
  // what happens with the following code:
  // auto sp = make_shared<int>();
  // auto p4  = sp.get();
  // delete p4; // like 12.11 this deletes the make_shared pointer, sp..
  
  // Exercise 12.14
  // write your own version of a function which manages a
  // connection with a shared_ptr

  // Exercise 12.15
  // rewrite the above exercise to use a lamba
  // callable instead of a function..
  // Data d1;
  // d1.value = 1;
  // manage_analysis(d1);
  // manage_analysis2(d1);

  // begin section 5 stuff:
  // uniqute_prts
  // must use direct form of initialization
  // find this beginning on page 470

  int val = 5;
  // protip - do not assign uniq_ptr to val and then destroy it..
  unique_ptr<int> uniq_int2(new int (42));
  val = 6;
  cout << *uniq_int2 << ", value\n";
  cout << "still here! :) \n";
  cout << *uniq_int2 << ", value\n";

  // exercise 12.16 how does gcc respond to copy assignments of uniq_ptr?
  // below produces a malloc "pointer being freed was not allocated" error
  // unique_ptr<int> uniq_int(&val);
  //
  // exercise 12.17:
  // which of the following are illegal?

  int ix = 1024 , *pi = &ix , *pi2 = new int(2048);
  typedef unique_ptr<int> IntP;
  // IntP p0(ix); // error no good type. ix is an int
  // IntP p1(pi); // malloc error on release
  // IntP p3(&ix); // malloc error on release.
  // IntP p5(p2.get()); // malloc error on release..
  IntP p4(new int(2048));
  IntP p2(pi2);

  // exercise 12.18:
  // why doesn't shared_ptr have a release memeber?
  // shared pointer can have many pointers to the same memory location..
  // it doesn't make sense to be able to 'free' all memebers at the same time,
  // this could equally be accomplished with deleting the location in memory, making
  // every one of the shared pointers a nullptr..


return 0;
}
