#include "basic.hh"
#include "StrBlob.hh"

// Chapter 12 notes.. Dynamic Memory
int main(int argc, char **argv)
{

  // // Exercise 12.26 - rewrite the program from the previous section using an allocator
  // // this is exercises 12.23-26 together..

  // const char* rawCharP("rawBurnt");
  // const char* rawCharP2("rawChar");

  // const int totalSize = (sizeof(rawCharP) + sizeof(rawCharP2));
  // unique_ptr<char[]>dynamicRaw(new char[totalSize]);

  // // copy the first elements into the array
  // for(int i = 0; i < sizeof(rawCharP); ++i){
  //   dynamicRaw[i] = rawCharP[i];
  // }

  // // copy the second elements into the array.
  // // make sure to start the second word at 0!
  // for(int i = sizeof(rawCharP); i < totalSize; ++i){
  //   int j = i - sizeof(rawCharP);
  //   dynamicRaw[i] = rawCharP2[j];
  // }

  // std::string str1("rawBurnt");
  // std::string str2("rawChar");
  // std::string strT = str1 + str2;
  // std::cout << strT << ", combined string\n";

  // // 12.24 do this but some standard input
  // char* userInput(new char[10]);
  // while( userInput[0] != 'e'){
    // char test[10] , smol[5];
    // std::cin >> userInput;
    // std::cout << "you've entered: " << userInput << std::endl;
    // std::cout << "please enter test, followed by smol:\n";
    // std::cin >> test >> smol;
    // std::cout << "you've entered: " << test << "\t" << smol << std::endl;
    // std::cout << "ni hao" << endl;
  // }

  // 12.3 using a text query program

  // for exercises 12.19- 12.22
  StrBlob b1;
  StrBlob b2 = {"a", "an", "the"};
  b1 = b2;
  b2.push_back("about");

  // 12.20 write a program to read a file line by line, then put each line into a StrBlob type
  // use a StrBlobPtr to then print each element in that StrBlob..
  ifstream infile("strBlob.txt");
  StrBlob blobFile;
  int lineCount(0);
  // get the stuff from the infile..
  while(!infile.eof()){
    std::string line;

    // get the element from the file
    getline(infile , line);

    // put that element in the blob..
    blobFile.push_back(line);

    // keep track of the line count we're on
    lineCount += 1;
  }

  // the StrBlobPtr is initialized from the StrBlob: it needs that wptr data
  StrBlobPtr sbp(blobFile);

  // just keep going..
  while(true)
  {
    // get the element you want to spit out
    cout << sbp.deref() << endl;

    // go to the next element
    sbp = sbp.incr();

    //  think of any stopping condition you want.
    if (lineCount == 1) break;
    else lineCount -= 1;
  }

  return 0;
}
