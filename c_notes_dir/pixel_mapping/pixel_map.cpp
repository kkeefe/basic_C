#include "pixel_map.hh" //includes algorithm, function, vector headers, etc..

using namespace std;

//note that channel to register mapping simply increases channel count by 12..

void print_map(const map<int, int> m)
{
  printf("pixel_num\tcable_num\n");
  for (auto &c : m)
  {
    std::cout << c.first << "\t\t" << c.second << "\n";
  }
}

void print_map(const map<int, pair<int, int>> mp)
{
  printf("pixel_num\tJ_num\t\tpin_num\n");
  for (auto &c : mp)
  {
    std::cout << c.first << "\t\t" << c.second.first << "\t\t" << c.second.second << "\n";
  }
}


//choice to use map types since pixel_num is easy to know in lab, and data type is automatically ordered by this key..
//note that pin numbers must be mapped as following:
map<int, int> conv_pin_to_channel = {{2, 7},
                                     {4, 6},
                                     {6, 5},
                                     {8, 4},
                                     {10, 3},
                                     {12, 2},
                                     {14, 1},
                                     {16, 0}};

//what remains is to have a correct mapping between j_num and asic channel
map<int, pair<int, int>> conv_jNum_to_asicRowCol = {
    {1, {0, 3}}, //bottom stack (j, (row, col))
    {2, {0, 2}},
    {3, {0, 1}},
    {4, {0, 0}},
    {5, {1, 3}}, //top stack (j, (row, col))
    {6, {1, 2}},
    {7, {1, 1}},
    {8, {1, 0}},
};



//Must supply pin Num and Row Column information
int convert_to_Channel(const int channel, const pair<int, int> row_column)
{
  int asicCh = channel;
  int row = row_column.first;
  int col = row_column.second;

  int chNum = (row * 8) + (col * 32) + (asicCh) + 1;

  return chNum;
}

//Must supply pin Num and Row Column information
int convert_to_Register(const int channel, const pair<int, int> row_column)
{
  int asicCh = channel;
  int row = row_column.first;
  int col = row_column.second;

  int Reg = (row * 8) + (col * 32) + (asicCh) + 13;

  return Reg;
}

int main(int argc, char **argv)
{
  //note file structure:
  //pixel#    cable#
  ifstream read_file("pixel_cable.txt");

  //note file structure:
  //pixel#   j#    pin(2,4,6,8,10,12,14,16)#
  ifstream read_file2("pixel_asic.txt");

  int pixel_num, cable_num;
  map<int, int> cable_to_pixel;
  while (read_file >> pixel_num >> cable_num)
  {
    cable_to_pixel[pixel_num] = cable_num; //create an ordered map between pixel numbers and cable numbers
  }
  // print_map(cable_to_pixel); //uncomment print map to standard output to check values..

  int j_num, pin_num;
  map<int, pair<int, int>> pixel_to_JandAsic;
  while (read_file2 >> pixel_num >> j_num >> pin_num)
  {
    pixel_to_JandAsic[pixel_num] = make_pair(j_num, pin_num); //create an ordered map between pixel number and (j_num / pin_num) pair
  }

  print_map(pixel_to_JandAsic); //uncomment print map to print standard output to check values..

  // ofstream outfile1("pixel_cable_channel.txt");
  // for (auto c : pixel_to_JandAsic) // c has type map<int, pair<int, int>> and uses the pixel as its key::type, which is the same key for the cable number..
  // {
  //   pair<int, int> row_column = conv_jNum_to_asicRowCol[c.second.first];
  //   int Asic_channel = conv_pin_to_channel[c.second.second];
  //   outfile1 << "pixel number: " << c.first
  //            << "\t cable number is: " << cable_to_pixel[c.first]
  //            << "\t channel number is: " << convert_to_Channel(Asic_channel, row_column)
  //            << endl;
  // }
  // outfile1.close();

  // ofstream outfile1("pixel_channel_reg.txt");
  // for (auto c : pixel_to_JandAsic) // c has type map<int, pair<int, int>> and uses the pixel as its key::type, which is the same key for the cable number..
  // {
  //   pair<int, int> row_column = conv_jNum_to_asicRowCol[c.second.first];
  //   int Asic_channel = conv_pin_to_channel[c.second.second];
  //   outfile1 <<  c.first << "\t" << convert_to_Channel(Asic_channel, row_column) << "\t" <<  convert_to_Register(Asic_channel, row_column) <<endl;
  // }
  // outfile1.close();

  // use this file to print the map you want..
  ifstream infile2("pixel_channel_reg.txt");
  ofstream print_map("pixel_reg_map.cpp");
  ofstream print_map2("register_to_channel_map.cpp");
  ofstream print_set("register_set.cpp");

  print_map << " int conv_RegN_to_pixN(int regN){" << endl;
  print_map2 << " int conv_RegN_to_chN(int regN){" << endl;
  print_set << " set<int> register_set = \n {";
  int pixN, chN, regN;
  while (infile2 >> pixN >> chN >> regN)
  {
    print_map << "{" << regN << ", " << pixN << "}," << endl;
    print_map2 << "{" << regN << ", " << chN << "}," << endl;
    print_set << regN << ", ";
  }

  print_map << "};";
  print_map2 << "};";
  print_set << "};";

  infile2.close();
  print_map.close();
  print_map2.close();
  print_set.close();

  // want to create a set of values from which to read reg_I_want and so to prevent useless register checks..

  return 0;
}
