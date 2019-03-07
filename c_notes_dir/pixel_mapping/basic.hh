#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <utility> //includes pair

using namespace std;

void print_map(const map<int, int> m);
void print_map(const map<int, pair<int, int>> mp);
int convert_to_Channel(const int channel, const pair<int, int> row_column);
