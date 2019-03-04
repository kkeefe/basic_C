#include "basic.hh"//includes algorithm, function, vector headers, etc..
#include <sstream> // 4 is the place where istringstream is located..

using namespace std; 

map<string, string> buildMap(ifstream &reference_file)
{
  map<string, string> transformation;
  string key;
  string value;
  while (reference_file >> key && getline(reference_file, value))
    if (value.size() > 1)
    {
      transformation[key] = value.substr(1);
    }
    else
    {
      throw runtime_error("no rule for " + key);
    }
  return transformation;
}

const string &transform(const string &s, const map<string, string> &m)
{
  auto map_it = m.find(s);
  if (map_it != m.cend())
    return map_it->second;
  else
    return s;
}

void word_transformation(ifstream &input_file, ifstream &reference_file)
{
  auto transformation = buildMap(input_file);
  string text;
  while (getline(reference_file, text))
  {
    istringstream stream(text);
    string word;
    bool firstword = true;
    while (stream >> word)
    {
      if (firstword)
        firstword = false;
      else
        cout << " ";

      cout << transform(word, transformation);
    }
    cout << endl;
  }
}

int main(int argc, char **argv)
{

  ifstream input_file;
  input_file.open("input_transformation.txt");

  ifstream reference_file;
  reference_file.open("word_transformation_file.txt");

  word_transformation(reference_file, input_file);

  input_file.close();
  reference_file.close();

  return 0;
}
