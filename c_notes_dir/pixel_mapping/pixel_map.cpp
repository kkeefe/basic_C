#include "pixel_map.hh" //includes algorithm, function, vector headers, etc..

using namespace std;

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

map<int, int> conv_spot_to_order = {
{0,9},
{1,8},
{2,11},
{3,10},
{4,13},
{5,12},
{6,15},
{7,14},
// top half pixels
{8,1},
{9,0},
{10,3},
{11,2},
{12,5},
{13,4},
{14,7},
{15,6},
};

int convert_bitNum_to_readOrder(const int bitNum){
  int spot_order  = bitNum / 4;
  spot_order = conv_spot_to_order[spot_order];
  spot_order = spot_order*4;

  int nible_order = bitNum % 4;
  nible_order = 3 - nible_order;

  // start the reading at 1
  int read_order = spot_order + nible_order + 1;

  return read_order;

}

// useful for old soft/firmware
// Must supply pin Num and Row Column information
int convert_to_Channel(const int asicChNum, const pair<int, int> row_column)
{
  int asicCh = asicChNum;
  int row = row_column.first;
  int col = row_column.second;
  int chNum = (row * 8) + (col * 32) + (asicCh) + 1;

  return chNum;
}

//  Must supply pin Num and Row Column information
int convert_to_bitNum(const int asicChNum, const pair<int, int> row_column)
{
  int asicCh = asicChNum;
  int row = row_column.first;
  int col = row_column.second;
  int bitNum = (row * 32) + (col * 8) + (asicCh);

  return bitNum;
}

//Must supply pin Num and Row Column information
int convert_to_Register(const int asicChNum, const pair<int, int> row_column)
{
  int asicCh = asicChNum;
  int row = row_column.first;
  int col = row_column.second;
  int Reg = (row * 8) + (col * 32) + (asicCh) + 13;

  return Reg;
}

void create_Json(int pixel , int jNum , int regNum , int row , int col , int cableNum , int asicChNum , int readNum , int bitNum , ofstream& outputFilename){

// create the beginning brace
  outputFilename << "\t{\n";

// create the stuff inbetween
  outputFilename << "\t\t\"pixelNum\"" << ":" << pixel << ",\n";
  outputFilename << "\t\t\"jNum\""  << ":" << jNum << ",\n";
  outputFilename << "\t\t\"regNum\""   << ":" << regNum << ",\n";
  outputFilename << "\t\t\"row\""      << ":" << row << ",\n";
  outputFilename << "\t\t\"column\""   << ":" << col << ",\n";
  outputFilename << "\t\t\"cableNum\""  << ":" << cableNum << ",\n";
  outputFilename << "\t\t\"asicChNum\""  << ":" << asicChNum << ",\n";
  outputFilename << "\t\t\"readNum\""   << ":" << readNum << ",\n";
  outputFilename << "\t\t\"bitNum\""   << ":" << bitNum << "\n";

  // end the item in the ist..
  if ( pixel != 64 ) outputFilename << "\t},\n";
  else outputFilename << "\t}\n";

}

void create_Txt(int pixel , int jNum , int regNum , int row , int col , int cableNum , int asicChNum , int readNum , int bitNum , ofstream& outputFilename){
// create the stuff inbetween
  outputFilename << pixel << "\t" << jNum << "\t" << regNum << "\t" << row << "\t" << col << "\t" << cableNum << "\t" << asicChNum << "\t" << readNum << "\t" << bitNum << "\n";
}

int main(int argc, char **argv)
{
  //pixel#    cable#
  ifstream read_file("pixel_cable.txt");

  //pixel#   j#    pin(2,4,6,8,10,12,14,16)#
  ifstream read_file2("pixel_asic.txt");

  // pixel# channel# register#
  ifstream read_file3("pixel_channel_reg.txt");

  int pixel_num, cable_num;
  map<int, int> cable_to_pixel;
  while (read_file >> pixel_num >> cable_num)
  {
    cable_to_pixel[pixel_num] = cable_num; //create an ordered map between pixel numbers and cable numbers
  }

  int j_num, pin_num;
  map<int, pair<int, int>> pixel_to_JandAsic;
  while (read_file2 >> pixel_num >> j_num >> pin_num)
  {
    pixel_to_JandAsic[pixel_num] = make_pair(j_num, pin_num); //create an ordered map between pixel number and (j_num / pin_num) pair
  }

  ofstream outfile("pixelData.json");
  ofstream outfile2("pixelData.txt");
  outfile << "{\n\t\"allPixelMappings\":[\n";
  outfile2 << "pixelNum\tjNum\tregNum\trow\tcol\tcableNum\tchNum\treadNum\tbitNum\n";
  for(int i = 1; i <= 64; ++i){
    int cableNum = cable_to_pixel[i];

    pair<int, int> jNum_chNum = pixel_to_JandAsic[i];
    int jNum = jNum_chNum.first;
    int chNum = conv_pin_to_channel[jNum_chNum.second];

    pair<int , int> rowCol = conv_jNum_to_asicRowCol[jNum];
    int row = rowCol.first;
    int col = rowCol.second;

    int regNum = convert_to_Register(chNum, rowCol);
    int bitNum = convert_to_bitNum(chNum, rowCol);

    int readNum = convert_bitNum_to_readOrder(bitNum);

    create_Json(i , jNum , regNum , row , col , cableNum ,  chNum , readNum , bitNum , outfile);
    create_Txt(i , jNum , regNum , row , col , cableNum ,  chNum , readNum , bitNum , outfile2);
  }
  outfile << "\t]\n}";
  // close the files you're looking at
  read_file3.close();
  outfile.close();
  outfile2.close();

  return 0;
}
