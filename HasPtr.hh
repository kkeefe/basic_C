#ifndef __HASPTR_H_
#define __HASPTR_H_

// pointer like version of HasPtr..
class HasPtr
{
  public:
    // let's get some constructors:
    HasPtr(const std::string &s = std::string()) : ptr(new std::string(s)), i(0), user_cnt(new int(1)) {  }

    // copy constructor, copy all elements directly into lhs
    HasPtr(const HasPtr& a) : ptr(a.ptr) , i(a.i) , user_cnt(a.user_cnt)
    { ++*user_cnt; } // don't forget to increment the user count..

    // copy assignment constructor
    HasPtr& operator=(const HasPtr&);

    // destructor
    ~HasPtr();
  private:
    // the private string ptr member
    std::string *ptr;

    // element
    int i;

    // keep count of how many users are pointing to this string here
    int *user_cnt;

};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
  // keep a hold of the new rhs user_cnt
  ++(*rhs.user_cnt);

  // delete the pointers if you need to
  if(*--user_cnt == 0){
    delete ptr;
    delete user_cnt;
  }

  // finally make the copy assignments..
  ptr = rhs.ptr;
  i = rhs.i;
  user_cnt = rhs.user_cnt;

  // the assignment operator needs to return the HasPtr
  return *this;
}

// destructor: delete the pointer elements if there are no longer any users.
HasPtr::~HasPtr()
{
  if(--*user_cnt == 0){
    delete user_cnt;
    delete ptr;
  }
}


#endif // __HASPTR_H_
