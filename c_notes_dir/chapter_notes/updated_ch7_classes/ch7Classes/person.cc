#include "person.hh"

Person::Person(istream& is)
{
  read(*this, cin);
}

Person::Person()
{
  this->name = "john";
}

string Person::get_address (const Person Joe)
{
  return Joe.address;
}

string Person::get_number (const Person Joe)
{
  return Joe.phone_number;
}

std::istream& read(Person& Joe, std::istream& is)
{
  cout << "please enter the name: " << endl;
  getline(is, Joe.name);
  cout << "please enter the address: " << endl;
  getline(is, Joe.address);
  cout << "please enter the phone number: " << endl;
  getline(is, Joe.phone_number);
  return is;
}

std::ostream & print(const Person & Joe, std::ostream & os)
{
  os << Joe.address << " is " << Joe.name << "'s address" << endl;
  os << Joe.phone_number << " is " << Joe.name << "'s phone number " << endl;
  return os;
}
