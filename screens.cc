#include "screens.hh"

//~~~~ Member functions
Screens& Screens::move(pos row, pos col)
{
  pos x = row*width;
  cursor = x + col;
  return *this;
}

char Screens::get(pos row, pos col) const
{
  pos x = row*width;
  return contents[x+col];
}

Screens& Screens::set(pos row, pos col, char c)
{
  contents[row*width + col] = c;
  return *this;
}

Screens& Screens::set(char c)
{
  contents[cursor] = c;
  return *this;
}

//~~~~ friendly functions
std::istream & read(std::istream & is, Screens & screen)
{
  cout << "please input the cursor length" << endl;
  is >> screen.cursor;
  cout << "please input the height " << endl;
  is >> screen.height;
  cout << "please input the cursor width" << endl;
  is >> screen.width;
  
  return is;
}
std::ostream & print(std::ostream & os, const Screens & screen)
{
  os << screen.cursor << " cursor \n";
  os << screen.height << " height \n";
  os << screen.width << " width \n";

  return os;
}
