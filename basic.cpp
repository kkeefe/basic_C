#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // 4 is the place where istringstream is located..

using namespace std; 

void print_map(const map<int,int> m){
  printf("pixel_num\tcable_num\n");
  for(auto &c : m){
    std::cout << c.first << "\t\t" << c.second << "\n";
  }
}

void print_map(const map<int,pair<int,int>> mp){
  printf("pixel_num\tJ_num\t\tpin_num\n");
  for(auto &c : mp){
    std::cout << c.first << "\t\t" << c.second.first << "\t\t" << c.second.second << "\n";
  }
}

//must supply pin Num and Row Column information
int convert_to_Channel(const int channel, const pair<int,int> row_column){
  int asicCh = channel;
  int row   = row_column.first;
  int col   = row_column.second;
  
  int chNum = (row*8) + (col*32) + (asicCh) + 1;

  return chNum;
}

int main(int argc, char **argv)
{
  //note file structure:
  //pixel#    cable#
  ifstream read_file("pixel_cable.txt");

  //note file structure:
  //cable#   j#    pin(2,4,6,8,10,12,14,16)#
  ifstream read_file2("pixel_asic.txt");



  //note that pin numbers must be mapped as following:
  map<int, int> conv_pin_to_channel = { {2,7},
					      {4,6},
					      {6,5},
					      {8,4},
					      {10,3},
					      {12,2},
					      {14,1},
					      {16,0}
  };

  //what remains is to have a correct mapping between j_num and asic channel
  map<int, pair<int,int>> conv_jNum_to_asicRowCol = { {1, {0,3}},//bottom stack (j, (row, col))
							    {2, {0,2}},
							    {3, {0,1}},
							    {4, {0,0}},
							    {5, {1,3}},//top stack (j, (row, col))
							    {6, {1,2}},
							    {7, {1,1}},
							    {8, {1,0}},
  };
  
  int pixel_num, cable_num;
  map<int,int> cable_to_pixel;
  while(read_file >> pixel_num >> cable_num){
    cable_to_pixel[pixel_num] = cable_num;
  }
  // print_map(cable_to_pixel);
  
  int j_num, pin_num;
  map<int,pair<int,int>> pixel_to_JandAsic;
  while(read_file2 >> pixel_num >> j_num >> pin_num){
    pixel_to_JandAsic[pixel_num] = make_pair(j_num, pin_num);
  }
  // print_map(pixel_to_JandAsic);

  ofstream outfile1("pixel_cable_channel.txt");
  for(auto c : pixel_to_JandAsic){
    pair<int,int> row_column = conv_jNum_to_asicRowCol[c.second.first];
    int Asic_channel = conv_pin_to_channel[c.second.second];
    outfile1 << "pixel number: " << c.first << "\t cable number is: " << cable_to_pixel[c.first] << "\t channel number is: " << convert_to_Channel(Asic_channel, row_column) << endl;
  }
  outfile1.close();
  

  return 0;
}
