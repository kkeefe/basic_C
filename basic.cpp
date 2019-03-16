#include "basic.hh" //includes algorithm, function, vector headers, etc..
#include <sstream>  // 4 is the place where istringstream is located..

using namespace std;

int main(int argc, char **argv)
{

  if(argc != 2){
    printf("please only enter the file name you wish to open as your second argument..\n");
    return 1;
  }
  
  ifstream input_file(argv[1]);

  string name[129];
  string word;
  for(int i = 0; i < 129; ++i){
    input_file >> word;
    name[i] = word;
    cout << word << " is the word read.." << endl;

  }

  vector<int> threshold_value;
  vector<int> scaler_counts[128];

  int value;
  
  do{
    for(int i = 0; i < 129; ++i){
      input_file >> value;
      if(i == 0){
	threshold_value.push_back(value);
      }else
	scaler_counts[i-1].push_back(value);
    }
  }while(!input_file.eof());

  for(int i = 0; i < 129; ++i){

    string file_name("_Channel_SiPM.txt");
    string count = std::to_string(i);

    file_name = count + file_name;

    ofstream output_file(file_name);

    if (threshold_value.size() == scaler_counts[i].size()){ //make sure they're the same size..

      auto c = threshold_value.begin();
      auto d = scaler_counts[i].begin();

      while(c != threshold_value.end()){
	output_file << *c << "\t" << *d << "\t" << i << endl;
	c++;
	d++;
      }
    }else {
      printf("iterators are not of the same length..\n");
      cout << "file found: " << file_name << endl;
    }
  }
  return 0;
}
