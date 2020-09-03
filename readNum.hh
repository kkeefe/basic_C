#include <map>
#ifndef __READNUM_MAP_H_
#define __READNUM_MAP_H_

struct Pixel_Map {
  Pixel_Map() = default;
  Pixel_Map(const unsigned int ch, const unsigned int r, const unsigned int c)
      : ch(ch), row(r), col(c){};
  Pixel_Map(const Pixel_Map &pl) : ch(pl.ch), row(pl.row), col(pl.col){};
  ~Pixel_Map(){};
  // special identifiers
  unsigned int ch;
  unsigned int row;
  unsigned int col;
};

inline bool operator<(const Pixel_Map &lhs, const Pixel_Map &rhs) {
  return lhs.ch < rhs.ch or (lhs.ch == rhs.ch and lhs.row < rhs.row) or
         (lhs.ch == rhs.ch and lhs.row == rhs.row and lhs.col < rhs.col);
}

inline bool operator>(const Pixel_Map &lhs, const Pixel_Map &rhs) {
  return lhs.ch > rhs.ch or (lhs.ch == rhs.ch and lhs.row > rhs.row) or
         (lhs.ch == rhs.ch and lhs.row == rhs.row and lhs.col > rhs.col);
}

inline bool operator==(const Pixel_Map &lhs, const Pixel_Map &rhs) {
  return (lhs.ch == rhs.ch and lhs.row == rhs.row and lhs.col == rhs.col);
}

// all data taken from full_analyst_pixelData.txt file..
auto pix1 = Pixel_Map(2, 0, 3);
auto pix2 = Pixel_Map(4, 0, 3);
auto pix3 = Pixel_Map(6, 0, 3);
auto pix4 = Pixel_Map(0, 0, 3);
auto pix5 = Pixel_Map(0, 1, 2);
auto pix6 = Pixel_Map(0, 1, 3);
auto pix7 = Pixel_Map(2, 1, 3);
auto pix8 = Pixel_Map(4, 1, 3);
auto pix9 = Pixel_Map(3, 0, 3);
auto pix10 = Pixel_Map(5, 0, 3);
auto pix11 = Pixel_Map(7, 0, 3);
auto pix12 = Pixel_Map(0, 0, 2);
auto pix13 = Pixel_Map(7, 1, 3);
auto pix14 = Pixel_Map(1, 1, 3);
auto pix15 = Pixel_Map(3, 1, 3);
auto pix16 = Pixel_Map(5, 1, 3);
auto pix17 = Pixel_Map(1, 0, 3);
auto pix18 = Pixel_Map(5, 0, 2);
auto pix19 = Pixel_Map(3, 0, 2);
auto pix20 = Pixel_Map(2, 0, 2);
auto pix21 = Pixel_Map(4, 1, 2);
auto pix22 = Pixel_Map(2, 1, 2);
auto pix23 = Pixel_Map(5, 1, 2);
auto pix24 = Pixel_Map(7, 1, 2);
auto pix25 = Pixel_Map(6, 0, 2);
auto pix26 = Pixel_Map(1, 0, 2);
auto pix27 = Pixel_Map(4, 0, 2);
auto pix28 = Pixel_Map(7, 0, 2);
auto pix29 = Pixel_Map(3, 1, 2);
auto pix30 = Pixel_Map(1, 1, 2);
auto pix31 = Pixel_Map(6, 1, 2);
auto pix32 = Pixel_Map(6, 1, 3);
auto pix33 = Pixel_Map(6, 0, 0);
auto pix34 = Pixel_Map(2, 0, 1);
auto pix35 = Pixel_Map(4, 0, 1);
auto pix36 = Pixel_Map(3, 0, 1);
auto pix37 = Pixel_Map(5, 1, 1);
auto pix38 = Pixel_Map(3, 1, 1);
auto pix39 = Pixel_Map(1, 1, 1);
auto pix40 = Pixel_Map(6, 1, 1);
auto pix41 = Pixel_Map(1, 0, 1);
auto pix42 = Pixel_Map(6, 0, 1);
auto pix43 = Pixel_Map(5, 0, 1);
auto pix44 = Pixel_Map(0, 0, 1);
auto pix45 = Pixel_Map(4, 1, 1);
auto pix46 = Pixel_Map(2, 1, 1);
auto pix47 = Pixel_Map(0, 1, 1);
auto pix48 = Pixel_Map(1, 1, 0);
auto pix49 = Pixel_Map(5, 0, 0);
auto pix50 = Pixel_Map(3, 0, 0);
auto pix51 = Pixel_Map(1, 0, 0);
auto pix52 = Pixel_Map(7, 0, 0);
auto pix53 = Pixel_Map(7, 1, 1);
auto pix54 = Pixel_Map(7, 1, 0);
auto pix55 = Pixel_Map(5, 1, 0);
auto pix56 = Pixel_Map(3, 1, 0);
auto pix57 = Pixel_Map(4, 0, 0);
auto pix58 = Pixel_Map(2, 0, 0);
auto pix59 = Pixel_Map(0, 0, 0);
auto pix60 = Pixel_Map(7, 0, 1);
auto pix61 = Pixel_Map(0, 1, 0);
auto pix62 = Pixel_Map(6, 1, 0);
auto pix63 = Pixel_Map(4, 1, 0);
auto pix64 = Pixel_Map(2, 1, 0);

std::map<Pixel_Map, int> chRowCol_to_fastPix = {
    {pix1, 1},   {pix2, 2},   {pix3, 3},   {pix4, 4},   {pix5, 5},
    {pix6, 6},   {pix7, 7},   {pix8, 8},   {pix9, 9},   {pix10, 10},
    {pix11, 11}, {pix12, 12}, {pix13, 13}, {pix14, 14}, {pix15, 15},
    {pix16, 16}, {pix17, 17}, {pix18, 18}, {pix19, 19}, {pix20, 20},
    {pix21, 21}, {pix22, 22}, {pix23, 23}, {pix24, 24}, {pix25, 25},
    {pix26, 26}, {pix27, 27}, {pix28, 28}, {pix29, 29}, {pix30, 30},
    {pix31, 31}, {pix32, 32}, {pix33, 33}, {pix34, 34}, {pix35, 35},
    {pix36, 36}, {pix37, 37}, {pix38, 38}, {pix39, 39}, {pix40, 40},
    {pix41, 41}, {pix42, 42}, {pix43, 43}, {pix44, 44}, {pix45, 45},
    {pix46, 46}, {pix47, 47}, {pix48, 48}, {pix49, 49}, {pix50, 50},
    {pix51, 51}, {pix52, 52}, {pix53, 53}, {pix54, 54}, {pix55, 55},
    {pix56, 56}, {pix57, 57}, {pix58, 58}, {pix59, 59}, {pix60, 60},
    {pix61, 61}, {pix62, 62}, {pix63, 63}, {pix64, 64}};

std::map<Pixel_Map, int> chRowCol_to_slowPix = {
    {pix1, 2},   {pix2, 3},   {pix3, 4},   {pix4, 1},   {pix5, 21},
    {pix6, 5},   {pix7, 6},   {pix8, 7},   {pix9, 10},  {pix10, 11},
    {pix11, 12}, {pix12, 28}, {pix13, 16}, {pix14, 13}, {pix15, 14},
    {pix16, 15}, {pix17, 9},  {pix18, 18}, {pix19, 19}, {pix20, 27},
    {pix21, 23}, {pix22, 22}, {pix23, 31}, {pix24, 32}, {pix25, 25},
    {pix26, 20}, {pix27, 26}, {pix28, 17}, {pix29, 30}, {pix30, 29},
    {pix31, 24}, {pix32, 8},  {pix33, 57}, {pix34, 34}, {pix35, 35},
    {pix36, 42}, {pix37, 38}, {pix38, 39}, {pix39, 40}, {pix40, 45},
    {pix41, 41}, {pix42, 36}, {pix43, 43}, {pix44, 33}, {pix45, 46},
    {pix46, 47}, {pix47, 48}, {pix48, 56}, {pix49, 50}, {pix50, 51},
    {pix51, 52}, {pix52, 49}, {pix53, 37}, {pix54, 53}, {pix55, 54},
    {pix56, 55}, {pix57, 58}, {pix58, 59}, {pix59, 60}, {pix60, 44},
    {pix61, 64}, {pix62, 61}, {pix63, 62}, {pix64, 63}};

int get_pixel_fast(const int &ch, const int &row, const int &col) {
  Pixel_Map pix = Pixel_Map(ch, row, col);
  int pix_num = chRowCol_to_fastPix[pix];
  return pix_num;
}

int get_pixel_slow(const int &ch, const int &row, const int &col) {
  Pixel_Map pix = Pixel_Map(ch, row, col);
  int pix_num = chRowCol_to_slowPix[pix];
  return pix_num;
}

// tested for every pixel combintation (1-64 converting from sipm1 to sipm2
// which defines main barNumber)
int sipm1_conv_pixel_to_barNum(const int &pixNum) {
  int col = pixNum / 8;
  int row = pixNum % 8;
  if (row == 0) {
    return (9 - col) * 8;
  } else
    return (7 - col) * 8 + row;
}

// fast mapping things
std::map<int, int> fast_bitNum_to_asicRow = {
    {26, 0}, {28, 0}, {30, 0}, {24, 0}, {48, 1}, {56, 1}, {58, 1}, {60, 1},
    {27, 0}, {29, 0}, {31, 0}, {16, 0}, {63, 1}, {57, 1}, {59, 1}, {61, 1},
    {25, 0}, {21, 0}, {19, 0}, {18, 0}, {52, 1}, {50, 1}, {53, 1}, {55, 1},
    {22, 0}, {17, 0}, {20, 0}, {23, 0}, {51, 1}, {49, 1}, {54, 1}, {62, 1},
    {6, 0},  {10, 0}, {12, 0}, {11, 0}, {45, 1}, {43, 1}, {41, 1}, {46, 1},
    {9, 0},  {14, 0}, {13, 0}, {8, 0},  {44, 1}, {42, 1}, {40, 1}, {33, 1},
    {5, 0},  {3, 0},  {1, 0},  {7, 0},  {47, 1}, {39, 1}, {37, 1}, {35, 1},
    {4, 0},  {2, 0},  {0, 0},  {15, 0}, {32, 1}, {38, 1}, {36, 1}, {34, 1}};

std::map<int, int> fast_bitNum_to_asicCol = {
    {26, 3}, {28, 3}, {30, 3}, {24, 3}, {48, 2}, {56, 3}, {58, 3}, {60, 3},
    {27, 3}, {29, 3}, {31, 3}, {16, 2}, {63, 3}, {57, 3}, {59, 3}, {61, 3},
    {25, 3}, {21, 2}, {19, 2}, {18, 2}, {52, 2}, {50, 2}, {53, 2}, {55, 2},
    {22, 2}, {17, 2}, {20, 2}, {23, 2}, {51, 2}, {49, 2}, {54, 2}, {62, 3},
    {6, 0},  {10, 1}, {12, 1}, {11, 1}, {45, 1}, {43, 1}, {41, 1}, {46, 1},
    {9, 1},  {14, 1}, {13, 1}, {8, 1},  {44, 1}, {42, 1}, {40, 1}, {33, 0},
    {5, 0},  {3, 0},  {1, 0},  {7, 0},  {47, 1}, {39, 0}, {37, 0}, {35, 0},
    {4, 0},  {2, 0},  {0, 0},  {15, 1}, {32, 0}, {38, 0}, {36, 0}, {34, 0}};

std::map<int, int> fast_bitNum_to_asicCh = {
    {26, 2}, {28, 4}, {30, 6}, {24, 0}, {48, 0}, {56, 0}, {58, 2}, {60, 4},
    {27, 3}, {29, 5}, {31, 7}, {16, 0}, {63, 7}, {57, 1}, {59, 3}, {61, 5},
    {25, 1}, {21, 5}, {19, 3}, {18, 2}, {52, 4}, {50, 2}, {53, 5}, {55, 7},
    {22, 6}, {17, 1}, {20, 4}, {23, 7}, {51, 3}, {49, 1}, {54, 6}, {62, 6},
    {6, 6},  {10, 2}, {12, 4}, {11, 3}, {45, 5}, {43, 3}, {41, 1}, {46, 6},
    {9, 1},  {14, 6}, {13, 5}, {8, 0},  {44, 4}, {42, 2}, {40, 0}, {33, 1},
    {5, 5},  {3, 3},  {1, 1},  {7, 7},  {47, 7}, {39, 7}, {37, 5}, {35, 3},
    {4, 4},  {2, 2},  {0, 0},  {15, 7}, {32, 0}, {38, 6}, {36, 4}, {34, 2}};

#endif // __READNUM_MAP_H_

// full text file info
// fast_pixel_num	slow_pixel_num	chNum	row	col	readNum	bitNum
// 1	2	2	0	3	3	26
// 2	3	4	0	3	5	28
// 3	4	6	0	3	7	30
// 4	1	0	0	3	1	24
// 5	21	0	1	2	41	48
// 6	5	0	1	3	33	56
// 7	6	2	1	3	35	58
// 8	7	4	1	3	37	60
// 9	10	3	0	3	4	27
// 10	11	5	0	3	6	29
// 11	12	7	0	3	8	31
// 12	28	0	0	2	9	16 -- readnum is 9
// 13	16	7	1	3	40	63
// 14	13	1	1	3	34	57
// 15	14	3	1	3	36	59
// 16	15	5	1	3	38	61
// 17	9	1	0	3	2	25
// 18	18	5	0	2	14	21
// 19	19	3	0	2	12	19
// 20	27	2	0	2	11	18
// 21	23	4	1	2	45	52
// 22	22	2	1	2	43	50
// 23	31	5	1	2	46	53
// 24	32	7	1	2	48	55
// 25	25	6	0	2	15	22
// 26	20	1	0	2	10	17
// 27	26	4	0	2	13	20
// 28	17	7	0	2	16	23
// 29	30	3	1	2	44	51
// 30	29	1	1	2	42	49
// 31	24	6	1	2	47	54
// 32	8	6	1	3	39	62
// 33	57	6	0	0	31	6
// 34	34	2	0	1	19	10
// 35	35	4	0	1	21	12
// 36	42	3	0	1	20	11
// 37	38	5	1	1	54	45
// 38	39	3	1	1	52	43
// 39	40	1	1	1	50	41
// 40	45	6	1	1	55	46
// 41	41	1	0	1	18	9
// 42	36	6	0	1	23	14
// 43	43	5	0	1	22	13
// 44	33	0	0	1	17	8
// 45	46	4	1	1	53	44
// 46	47	2	1	1	51	42
// 47	48	0	1	1	49	40
// 48	56	1	1	0	58	33
// 49	50	5	0	0	30	5
// 50	51	3	0	0	28	3
// 51	52	1	0	0	26	1
// 52	49	7	0	0	32	7
// 53	37	7	1	1	56	47
// 54	53	7	1	0	64	39
// 55	54	5	1	0	62	37
// 56	55	3	1	0	60	35
// 57	58	4	0	0	29	4
// 58	59	2	0	0	27	2
// 59	60	0	0	0	25	0
// 60	44	7	0	1	24	15
// 61	64	0	1	0	57	32
// 62	61	6	1	0	63	38
// 63	62	4	1	0	61	36
// 64	63	2	1	0	59	34
