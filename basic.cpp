#include <string>
#include <stdio.h>

using namespace std;
// testing subclass things
class animal
{
  private:
    int size;
    int age;

  public:
    animal() = default;
    animal(const int& a, const int& s) : age(a), size(s) {};
    virtual ~animal() = default;
    int get_size() {return size;};
    int get_age() {return age;};

  protected:
    std::string name;

};

class dog : public animal
{
  public:
    dog() : animal() {};
    dog(const int& a, const int& s) : animal(a,s) {};
    dog(const int& a, const int& s, const string& o) : animal(a,s), owner(o){};
    std::string owner;

  private:

  protected:

};

template <typename T>
bool compare(const T& t1, const T& t2)
{
  if(t1 > t2) return true;
  else return false;
}

int main(int argc, char *argv[])
{

  return 0;
}
