#ifndef SCREENS
#define SCREENS

class Screens
{

  friend std::istream & read(std::istream&, Screens & s);
  friend std::ostream & print(std::ostream&, const Screens & s);

public:
  typedef std::string::size_type pos;
  Screens() = default;
  Screens(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {};
  Screens(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {};
  
  Screens & move(pos , pos );
  char get(pos, pos ) const;
  Screens & set (char );
  Screens & set( pos, pos, char);
  Screens & display(std::ostream & os)
  { do_display(os) ; return *this; } 
  const Screens & display(std::ostream & os) const
  { do_display(os) ; return *this; }
  
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  std::string contents;


private:

  void do_display(std::ostream& os) const { os << contents; } 
  
  
};
 
#endif
